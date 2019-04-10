// Implementation file for class 'ObjectOutput'.

#include "objectoutput.h"

// Constructors.
ObjectOutput::ObjectOutput() : m_FileName("output.txt")
{
}

ObjectOutput::ObjectOutput(QString fileName) : m_FileName(fileName)
{
}

// Function to return a QObject's contents as a string.
QString ObjectOutput::objectToString(const QObject* obj)
{
    QString objectStr;

    // Get object's metaObject.
    static const QMetaObject* metaObj = obj->metaObject();

    // Loop through object's properties.
    for (int i = metaObj->propertyOffset(); i < metaObj->propertyCount(); i++)
    {
        // For each property, get the name and value.
        QMetaProperty metaProp = metaObj->property(i);
        QString propName = QString(metaProp.name());
        QVariant propValue = metaProp.read(obj);

        // Build the string to return.
        objectStr.append(propName + ":  ");

        if (metaProp.isEnumType())
        {
            // For enum types, get the key associated with the int value.
            QMetaEnum metaEnum = metaProp.enumerator();
            QString enumKey = QString(metaEnum.valueToKey(propValue.toInt()));
            objectStr.append(enumKey + "\n");
            continue;
        }

        if (propValue.type() == QVariant::Date)
            objectStr.append(propValue.toDate().toString("yyyy-MM-dd") + "\n");

        else
            objectStr.append(propValue.toString() + "\n");
    }
    return objectStr;
}

// Function which writes a provided QObject to a text file.
bool ObjectOutput::saveToFile(const QObject* obj)
{
    QFile file(m_FileName);
    if (file.open(QIODevice::WriteOnly | QIODevice::Append))
    {
        // Get a string of the object.
        QString str = objectToString(obj);

        // Write string to file.
        QTextStream out(&file);
        out << str + "\n";
        file.close();

        return true;
    }
    return false;
}
