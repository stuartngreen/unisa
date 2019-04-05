// Semester 1: Assignment 2 Question 2
// Program to accept a time interval for displaying messages in a GUI.

#include <QApplication>
#include <QList>
#include "widget.h"
#include "messagelist.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QList<QString> messages;
    messages << "The best and most beautiful things in the world cannot be seen or even touched - they must be felt with the heart. -- Helen Keller"
             << "The best preparation for tomorrow is doing your best today. -- H. Jackson Brown, Jr."
             << "We must let go of the life we have planned, so as to accept the one that is waiting for us. -- Joseph Campbell"
             << "Today's weather is a warm 26C. Remember to apply sunscreen if you are outside!"
             << "It is during our darkest moments that we must focus to see the light. -- Aristotle"
             << "Believe you can and you're halfway there. -- Theodore Roosevelt"
             << "Don't forget your dentist appointment on Friday at 14:30!"
             << "Someone is sitting in the shade today because someone planted a tree a long time ago. -- Warren Buffett"
             << "Let us make our future now, and let us make our dreams tomorrow's reality. -- Malala Yousafzai"
             << "I hated every minute of training, but I said, 'Don't quit. Suffer now and live the rest of your life as a champion.' -- Muhammad Ali"
             << "Don't forget your meeting with Dave from Nedbank on Thursday at 13:30!"
             << "I can't change the direction of the wind, but I can adjust my sails to always reach my destination. -- Jimmy Dean"
             << "Let your life lightly dance on the edges of Time like dew on the tip of a leaf. -- Rabindranath Tagore"
             << "Shoot for the moon and if you miss you will still be among the stars. -- Les Brown"
             << "Even if I knew that tomorrow the world would go to pieces, I would still plant my apple tree. -- Martin Luther"
             << "The limits of the possible can only be defined by going beyond them into the impossible. -- Arthur C. Clarke"
             << "Nurture your minds with great thoughts. To believe in the heroic makes heroes. -- Benjamin Disraeli"
             << "Look within. Within is the fountain of good, and it will ever bubble up, if thou wilt ever dig. -- Marcus Aurelius"
             << "Do your little bit of good where you are; it's those little bits of good put together that overwhelm the world. -- Desmond Tutu"
             << "I believe every human has a finite number of heartbeats. I don't intend to waste any of mine. -- Neil Armstrong"
             << "Countless as the sands of the sea are human passions. -- Nikolai Gogol"
             << "A compliment is something like a kiss through a veil. -- Victor Hugo"
             << "Be not entangled in this world of days and nights; Thou hast another time and space as well. -- Muhammad Iqbal"
             << "Hope is but the dream of those who wake. -- Matthew Prior"
             << "We relish news of our heroes, forgetting that we are extraordinary to somebody too. -- Helen Hayes";

    MessageList messageList;
    messageList.addMessages(&messages);

    Widget widget;
    widget.init(&messageList); // Send the messages list to the widget object.
    widget.show();

    return a.exec();
}
