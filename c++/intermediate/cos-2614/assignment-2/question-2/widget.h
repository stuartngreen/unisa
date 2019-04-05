// Interface file for class 'Widget' which inherits from 'QWidget' and represents the GUI elements
// and their interactions. There is a:
//  - constructor which builds the GUI and connects SIGNALS to SLOTS;
//  - destructor;
//  - init(MessageList*) function which initialises the private member list with content;
//  - start() function which validates input and starts a timer to call update();
//  - stop() function which stops the timer;
//  - update() function which displays a returned message.

#ifndef WIDGET_H
#define WIDGET_H
#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QLineEdit>
#include <QTimer>
#include <QValidator>
#include <QLabel>
#include <QMessageBox>
#include <QDebug>
#include "messagelist.h"

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget* parent = 0);
    ~Widget();

public slots:
    void init(MessageList* messageList);
    void start();
    void stop();
    void update();

private:
    MessageList* m_MessageList;
    QPushButton* m_StartButton;
    QPushButton* m_StopButton;
    QLineEdit* m_TimeInput;
    QTimer* m_Timer;
    QLabel* m_MessageOutput;
};


#endif // WIDGET_H
