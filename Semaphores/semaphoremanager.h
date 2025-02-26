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

class SemaphoreManager : public QObject
{
    Q_OBJECT

    Q_PROPERTY(int state WRITE setState READ state NOTIFY stateChanged)
    Q_PROPERTY(int timeElapsed READ timeElapsed NOTIFY isTimeElapsedChanged)
    Q_PROPERTY(bool isSemaphoreOn WRITE setIsSemaphoreOn READ isSemaphoreOn NOTIFY isSemaphoreOnChanged)
    Q_PROPERTY(bool syncedOnState WRITE setSyncedOnState READ syncedOnState NOTIFY syncedOnStateChanged)
    Q_PROPERTY(bool syncedOffState WRITE setSyncedOffState READ syncedOffState NOTIFY syncedOffStateChanged)
public:
    explicit SemaphoreManager(QObject* parent = nullptr);

    enum SemaphoreState {
        RED_STATE = 0,
        RED_ORANGE_STATE,
        GREEN_STATE,
        ORANGE_STATE,
        OFF_OFF_STATE,
        ORANGE_OFF_STATE
    };
    Q_ENUM(SemaphoreState);

    QTimer* m_timerSemaphore = nullptr;

    void setState(const int & state);
    int state() const;

    int timeElapsed() const;

    void setIsSemaphoreOn(const bool isSemaphoreOn);
    bool isSemaphoreOn() const;

    void setSyncedOnState(const bool syncedOnState);
    bool syncedOnState() const;

    void setSyncedOffState(const bool syncedOffState);
    bool syncedOffState() const;

signals:
    void stateChanged(int state);
    void isTimeElapsedChanged();
    void isSemaphoreOnChanged(bool isSemaphoreOn);
    void syncedOnStateChanged(bool syncedOnState);
    void syncedOffStateChanged(bool syncedOffState);

private:
    int m_state;
    int m_timeElapsed;
    bool m_isSemaphoreOn;
    bool m_syncedOnState;
    bool m_syncedOffState;

private slots:
    void onTimerTrigger();
    void onIsSemaphoreOnChanged(bool isSemaphoreOn);
};

#endif // SEMAPHOREMANAGER_H
