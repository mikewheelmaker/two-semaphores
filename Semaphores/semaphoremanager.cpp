#include "semaphoremanager.h"

SemaphoreManager::SemaphoreManager(QObject *parent) : QObject(parent)
{
    m_timerSemaphore = new QTimer(this);
    connect(m_timerSemaphore, &QTimer::timeout, this, &SemaphoreManager::onTimerTrigger);
    connect(this, &SemaphoreManager::isSemaphoreOnChange, this, &SemaphoreManager::onIsSemaphoreOnChange);
    m_timerSemaphore->start(TIME_OUT);
    m_state = 4;
    m_timeElapsed = 0;
    m_isSemaphoreOn = false;
}

void SemaphoreManager::setState(int const& state)
{
    if(m_state == state)
    {
        return;
    }
    m_state = state;
    emit stateChanged(m_state);
}

int SemaphoreManager::state() const
{
    return this->m_state;
}

int SemaphoreManager::timeElapsed() const
{
    return this->m_timeElapsed;
}

void SemaphoreManager::setIsSemaphoreOn(bool const isSemaphoreOn)
{
    if(m_isSemaphoreOn == isSemaphoreOn)
    {
        return;
    }
    m_isSemaphoreOn = isSemaphoreOn;
    emit isSemaphoreOnChange(m_isSemaphoreOn);
}

bool SemaphoreManager::isSemaphoreOn() const
{
    return this->m_isSemaphoreOn;
}

void SemaphoreManager::onTimerTrigger()
{
    m_timeElapsed += 1;
    if(m_state == RED_STATE && m_timeElapsed == RED_TIME && m_isSemaphoreOn == true)
    {
        setState(RED_ORANGE_STATE);
        m_timeElapsed = 0;
        qDebug() << "Case 0 ON";
    }
    else if(m_state == RED_ORANGE_STATE && m_timeElapsed == RED_ORANGE_TIME && m_isSemaphoreOn == true)
    {
        setState(GREEN_STATE);
        m_timeElapsed = 0;
        qDebug() << "Case 1 ON";
    }
    else if(m_state == GREEN_STATE && m_timeElapsed == GREEN_TIME && m_isSemaphoreOn == true)
    {
        setState(ORANGE_STATE);
        m_timeElapsed = 0;
        qDebug() << "Case 2 ON";
    }
    else if(m_state == ORANGE_STATE && m_timeElapsed == ORANGE_TIME && m_isSemaphoreOn == true)
    {
        setState(RED_STATE);
        m_timeElapsed = 0;
        qDebug() << "Case 3 ON";
    }
    else if(m_state == OFF_ORANGE_STATE && m_isSemaphoreOn == false)
    {
        setState(OFF_STATE);
        m_timeElapsed = 0;
        qDebug() << "Case 3 OFF";
    }
    else if(m_state == OFF_STATE && m_isSemaphoreOn == false)
    {
        setState(OFF_ORANGE_STATE);
        m_timeElapsed = 0;
        qDebug() << "Case 4 OFF";
    }
    emit isTimeElapsedChange();
}

void SemaphoreManager::onIsSemaphoreOnChange(bool isSemaphoreOnChange)
{
    if(isSemaphoreOnChange == true)
        m_state = 0;
    else
        m_state = 4;
}
