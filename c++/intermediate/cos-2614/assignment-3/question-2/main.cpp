// Program to test TextbookMap and Textbook classes.
#include "textbook.h"
#include "textbookmap.h"
#include <QDebug>
#include <QTextStream>
#include <QStringList>

int main()
{
    QTextStream cout(stdout);


    // Adding some textbooks to the map.
    TextbookMap textbooks;
    textbooks.add(new Textbook("Programming Principles and Practice Using C++", "Stroustrup", "0321992784", 2014));
    textbooks.add(new Textbook("The C++ Programming Language", "Stroustrup", "0201700735", 1997));
    textbooks.add(new Textbook("XML in a Nutshell", "Harold", "0596002920", 2002));
    textbooks.add(new Textbook("UML Distilled", "Fowler", "0321193687", 2004));
    textbooks.add(new Textbook("Design Patterns", "Gamma", "0201633612", 1995));


    // Outputting map contents.
    cout << ">>> Contents of TextbookMap:\n" << endl;
    cout << textbooks.toString() << endl;


    // Outputting books for author "stroustrup".
    cout << ">>> Books written by \"Stroustrup\":\n" << endl;
    QStringList books = textbooks.textbookInfo("stroustrup");
    for (int i = 0; i < books.size(); i++)
        cout << books[i] << endl << endl;


    // Deleting some books.
    cout << "\n>>> Deleting books with ISBN 0201700735, ISBN 0321193687 and ISBN 0596002920:\n" << endl;

    if (textbooks.foundTextbook("0201700735"))
    {
        cout << "Textbook found. Deleting..." << endl;
        textbooks.deleteTextbook("0201700735");
    }
    else
        cout << "Textbook not found." << endl;

    if (textbooks.foundTextbook("0321193687"))
    {
        cout << "Textbook found. Deleting..." << endl;
        textbooks.deleteTextbook("0321193687");
    }
    else
        cout << "Textbook not found." << endl;

    if (textbooks.foundTextbook("0596002920"))
    {
        cout << "Textbook found. Deleting..." << endl;
        textbooks.deleteTextbook("0596002920");
    }
    else
        cout << "Textbook not found." << endl;


    // Outputting map contents after deletion.
    cout << "\n\n>>> Contents of TextbookMap after deletions:\n" << endl;
    cout << textbooks.toString() << endl;


    return 0;
}
