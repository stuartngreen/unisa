// Implementation file for class 'MessageList'.
#include "messagelist.h"

// Default constructor.
MessageList::MessageList()
{
}

// Destructor.
MessageList::~MessageList()
{
}

// Function which appends a message to the list.
void MessageList::addMessage(QString message)
{
    m_Messages.append(message);
}

// Function which appends a list of messages to the list.
void MessageList::addMessages(QList<QString>* messages)
{
    for (int i = 0; i < messages->size(); i++)
        m_Messages.append(messages->at(i));
}
// Function which returns a random message from the list.
QString MessageList::getMessage()
{
    qsrand(QTime::currentTime().msec());
    int i = rand() % m_Messages.size();
    return m_Messages.at(i);
}
