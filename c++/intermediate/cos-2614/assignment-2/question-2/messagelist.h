// Interface file for class 'MessageList' which represents a list of messages. There is a:
//  - default constructor;
//  - destructor;
//  - addMessage(QString) function which appends a message to the list;
//  - addMessages(QList<QString>*) function which appends a list of messages to the list;
//  - getMessage() function which returns a random message from the list.

#ifndef MESSAGELIST_H
#define MESSAGELIST_H
#include <QStringList>
#include <QTime>

class MessageList
{
public:
    MessageList();
    ~MessageList();
    void addMessage(QString message);
    void addMessages(QList<QString>* messages);
    QString getMessage();
private:
    QStringList m_Messages;
};

#endif // MESSAGELIST_H
