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
    Q_PROPERTY(int timeElapsed READ timeElapsed NOTIFY isTimeElapsedChange)
    Q_PROPERTY(bool isSemaphoreOn WRITE setIsSemaphoreOn READ isSemaphoreOn NOTIFY isSemaphoreOnChange)
public:
    explicit SemaphoreManager(QObject* parent = nullptr);

    enum SemaphoreStates {
        RED_STATE = 0,
        RED_ORANGE_STATE,
        GREEN_STATE,
        ORANGE_STATE,
        OFF_STATE,
        OFF_ORANGE_STATE
    };
    Q_ENUM(SemaphoreStates);

    QTimer* m_timerSemaphore = nullptr;

    void setState(int const& state);
    int state() const;

    int timeElapsed() const;

    void setIsSemaphoreOn(bool const isSemaphoreOn);
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
