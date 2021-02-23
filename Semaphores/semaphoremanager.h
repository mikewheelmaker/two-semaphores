#ifndef SEMAPHOREMANAGER_H
#define SEMAPHOREMANAGER_H

#include <QObject>
#include <QTimer>
#include <QDebug>

#define TIME_OUT 1000
#define RED_TIME 10
#define RED_ORANGE_TIME 3
#define GREEN_TIME 10
#define ORANGE_TIME 3

#define RED_STATE 0
#define RED_ORANGE_STATE 1
#define GREEN_STATE 2
#define ORANGE_STATE 3
#define OFF_STATE 4
#define OFF_ORANGE_STATE 5

class SemaphoreManager : public QObject
{
    Q_OBJECT

    Q_PROPERTY(int state WRITE setState READ state NOTIFY stateChanged)
    Q_PROPERTY(int state READ state)
    Q_PROPERTY(int timeElapsed READ timeElapsed NOTIFY isTimeElapsedChange)
    Q_PROPERTY(bool isSemaphoreOn WRITE setIsSemaphoreOn READ isSemaphoreOn NOTIFY isSemaphoreOnChange)
public:
    explicit SemaphoreManager(QObject *parent = nullptr);

    /*enum SemaphoreStates {
        RED_STATE,
        RED_ORANGE_STATE,
        GREEN_STATE,
        ORANGE_STATE,
        OFF_STATE
    };
    Q_ENUM(SemaphoreStates);*/

    QTimer* m_timerSemaphore = nullptr;

    void setState(const int &state);
    int state() const;

    int timeElapsed() const;

    void setIsSemaphoreOn(const bool isSemaphoreOn);
    bool isSemaphoreOn() const;

signals:
    void stateChanged(int state);
    void isTimeElapsedChange();
    void isSemaphoreOnChange(bool isSemaphoreOn);

private:
    int m_state;
    int m_timeElapsed;
    bool m_isSemaphoreOn;

private slots:
    void onTimerTrigger();
    void onIsSemaphoreOnChange(bool isSemaphoreOnChange);
};

#endif // SEMAPHOREMANAGER_H
