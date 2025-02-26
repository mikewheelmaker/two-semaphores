#include "semaphoremanager.h"

SemaphoreManager::SemaphoreManager(QObject *parent) : QObject(parent)
{
    m_timerSemaphore = new QTimer(this);
    connect(m_timerSemaphore, &QTimer::timeout, this, &SemaphoreManager::onTimerTrigger);
    connect(this, &SemaphoreManager::isSemaphoreOnChanged, this, &SemaphoreManager::onIsSemaphoreOnChanged);
    m_timerSemaphore->start(TIME_OUT);
    m_state = OFF_OFF_STATE;
    m_timeElapsed = 0;
    m_isSemaphoreOn = false;
    m_syncedOnState = false;
    m_syncedOffState = true;
}

void SemaphoreManager::setState(const int & state)
{
    if(m_state != state)
    {
        m_state = state;
        emit stateChanged(m_state);
    }
}

int SemaphoreManager::state() const
{
    return this->m_state;
}

int SemaphoreManager::timeElapsed() const
{
    return this->m_timeElapsed;
}

void SemaphoreManager::setIsSemaphoreOn(const bool isSemaphoreOn)
{
    if(m_isSemaphoreOn != isSemaphoreOn)
    {
        m_isSemaphoreOn = isSemaphoreOn;
        emit isSemaphoreOnChanged(m_isSemaphoreOn);
    }
}

bool SemaphoreManager::isSemaphoreOn() const
{
    return this->m_isSemaphoreOn;
}

void SemaphoreManager::setSyncedOnState(const bool syncedOnState)
{
    if(m_syncedOnState != syncedOnState)
    {
        m_syncedOnState = syncedOnState;
        emit syncedOnStateChanged(m_syncedOnState);
    }
}

bool SemaphoreManager::syncedOnState() const
{
    return this->m_syncedOnState;
}

void SemaphoreManager::setSyncedOffState(const bool syncedOffState)
{
    if(m_syncedOffState != syncedOffState)
    {
        m_syncedOffState = syncedOffState;
        emit syncedOffStateChanged(m_syncedOffState);
    }
}

bool SemaphoreManager::syncedOffState() const
{
    return this->m_syncedOffState;
}

void SemaphoreManager::onTimerTrigger()
{
    m_timeElapsed += 1;
    if(m_state == RED_STATE && m_timeElapsed == RED_TIME && m_isSemaphoreOn == true)
    {
        setState(RED_ORANGE_STATE);
        m_timeElapsed = 0;
        qDebug() << "RED_STATE OFF; RED_ORANGE_STATE ON";
    }
    else if(m_state == RED_ORANGE_STATE && m_timeElapsed == RED_ORANGE_TIME && m_isSemaphoreOn == true)
    {
        setState(GREEN_STATE);
        m_timeElapsed = 0;
        qDebug() << "RED_ORANGE_STATE OFF; GREEN_STATE ON";
    }
    else if(m_state == GREEN_STATE && m_timeElapsed == GREEN_TIME && m_isSemaphoreOn == true)
    {
        setState(ORANGE_STATE);
        m_timeElapsed = 0;
        qDebug() << "GREEN_STATE OFF; ORANGE_STATE ON";
    }
    else if(m_state == ORANGE_STATE && m_timeElapsed == ORANGE_TIME && m_isSemaphoreOn == true)
    {
        setState(RED_STATE);
        m_timeElapsed = 0;
        qDebug() << "ORANGE_STATE OFF; RED_STATE ON";
    }
    else if(m_state == ORANGE_STATE && m_isSemaphoreOn == false)
    {
        setState(OFF_OFF_STATE);
        m_timeElapsed = 0;
        qDebug() << "ORANGE_STATE OFF; OFF_OFF_STATE ON";
    }
    else if(m_state == OFF_OFF_STATE && m_isSemaphoreOn == false)
    {
        setState(ORANGE_OFF_STATE);
        m_timeElapsed = 0;
        qDebug() << "OFF_OFF_STATE OFF; ORANGE_OFF_STATE ON";
    }
    else if(m_state == ORANGE_OFF_STATE && m_isSemaphoreOn == false)
    {
        setState(OFF_OFF_STATE);
        m_timeElapsed = 0;
        qDebug() << "ORANGE_OFF_STATE OFF; OFF_OFF_STATE ON";
    }
    emit isTimeElapsedChanged();
}

void SemaphoreManager::onIsSemaphoreOnChanged(bool isSemaphoreOn)
{
    if(isSemaphoreOn == true)
        m_state = RED_STATE;
    else
        m_state = OFF_OFF_STATE;
}
