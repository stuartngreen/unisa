// Semester 2: Assignment 1 Question 4
// Program which reads file contents and counts matched words using regular expressions,
// based on command line options and arguments provided.

#include <QCoreApplication>
#include <QDebug>
#include <QCommandLineOption>
#include <QCommandLineParser>
#include <QTextStream>
#include "fileprocessor.h"
#include "wordcounter.h"

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);
    QCoreApplication::setApplicationName("Word Counter");

    // Setup the command line parser and arguments and options available.
    QCommandLineParser parser;
    QCommandLineOption optionA("a","Count the number of words longer than 4 characters that start with a capital letter.");
    QCommandLineOption optionB("b","Count the number of words that are hyphenated.");
    QCommandLineOption optionC("c","Count the number of words that start and end on the same character.");
    QCommandLineOption optionD("d","Count the number of words that do not start with a vowel.");
    parser.addOption(optionA);
    parser.addOption(optionB);
    parser.addOption(optionC);
    parser.addOption(optionD);
    parser.addPositionalArgument("filename.ext", "Filename(s) to process (can be more than one).");
    parser.process(app);

    // Get the provided arguments.
    const QStringList args = parser.positionalArguments();

    if (args.size() == 0)
        parser.showHelp(0);
    else
    {
        QTextStream out(stdout);

        for (int i = 0; i < args.size(); i++)
        {
            // Get the filename.
            QString fileName = args.at(i);

            // Get the file contents.
            FileProcessor processor;
            QString fileDump = processor.readFile(fileName);

            // Quit if there is some problem reading the file.
            if (fileDump == "")
                return 0;

            // Convert file contents into words list.
            QString cleanStr = processor.stripPunctuation(fileDump);
            QStringList wordsList = processor.toStringList(cleanStr);

            // Initialise a word counter with the words lists.
            WordCounter wc(&wordsList);

            // Output the results based on the command line options.
            out << "*** " + fileName + " ***" << endl;
            if (parser.isSet(optionA))
            {
                out << "Number of words longer than 4 characters that start with a capital letter: ";
                out << wc.countStartWithCap() << endl;
            }
            if (parser.isSet(optionB))
            {
                out << "Number of words that are hyphenated: ";
                out << wc.countHyphenated() << endl;
            }
            if (parser.isSet(optionC))
            {
                out << "Number of words that start and end on the same character: ";
                out << wc.countSameStartEnd() << endl;
            }
            if (parser.isSet(optionD))
            {
                out << "Number of words that do not start with a vowel: ";
                out << wc.countNoVowelStart() << endl;
            }
            out << "\n";
        }
    }

    return 0;
}
