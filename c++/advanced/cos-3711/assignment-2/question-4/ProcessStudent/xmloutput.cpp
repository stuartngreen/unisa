// Implementation file for class 'XmlOutput'.

#include "xmloutput.h"

// Constructor.
XmlOutput::XmlOutput()
{
}

// Function to write the XML to a file.
bool XmlOutput::outputXml(QString filename)
{
    // Get the XML.
    QString xml = buildXml();

    // Write the XML to a file.
    QFile file(filename);
    if (!xml.isEmpty() && file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        qDebug() << "Outputting XML..." << endl;
        QTextStream out(&file);
        out << xml;
        file.close();

        return true;
    }
    return false;
}

// Function to build the required XML structure from the list.
QString XmlOutput::buildXml()
{
    // Get the instance of the StudentList.
    QList<Student*> studentListData = StudentList::instance()->getStudentList();

    if (studentListData.size() > 0)
    {
        // Build the XML hierarchy.
        QDomDocument document;

        // Append the <StudentList> tag.
        QDomElement studentList = document.createElement("StudentList");
        document.appendChild(studentList);

        // Loop to append <student> tags.
        foreach(Student* studentData, studentListData)
        {
            QDomElement student = document.createElement("student");
            studentList.appendChild(student);

            // Append the <number> tag.
            QDomElement number = document.createElement("number");
            student.appendChild(number);
            QDomText numberData = document.createTextNode(studentData->getNumber());
            number.appendChild(numberData);

            // Append the <modules> tag.
            QDomElement modules = document.createElement("modules");
            student.appendChild(modules);

            // Loop to append <module> tags.
            foreach(QString key, studentData->getModules().keys())
            {
                QDomElement module = document.createElement("module");
                modules.appendChild(module);

                // Append the <code> tag.
                QDomElement code = document.createElement("code");
                module.appendChild(code);
                QDomText codeData = document.createTextNode(key);
                code.appendChild(codeData);

                // Append the <mark> tag.
                QDomElement mark = document.createElement("mark");
                module.appendChild(mark);
                QDomText markData = document.createTextNode(QString::number(studentData->getModules().value(key)));
                mark.appendChild(markData);
            }
        }

        // Return the XML as a QString.
        return document.toString();
    }

    return QString("");
}
