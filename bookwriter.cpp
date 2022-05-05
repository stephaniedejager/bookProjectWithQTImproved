#include "bookwriter.h"

#include <QMetaProperty>
#include <QFile>
#include <QTextStream>

QString BookWriter::filename = "book_database.txt";

BookWriter::BookWriter()
{
}

void BookWriter::write(Book *b)
{
    QString alldata;
    const QMetaObject *meta = b->metaObject();
    int totalProperties = meta->propertyCount();
    for (int i=1; i<totalProperties; i++)
    {
        QMetaProperty prop = meta->property(i);
        alldata.append(getPropertyEntry(prop,b));
        alldata.append("#");
    }
    alldata.append("\n");

    QFile file(filename);
    file.open(QIODevice::Append);
    QTextStream toFile(&file);
    toFile << alldata;
    file.close();
}

QString BookWriter::getPropertyEntry(QMetaProperty prop, Book *book)
{
    if(prop.type() == QVariant::StringList)
    {
       return prop.read(book).toStringList().join(", ");
    }
    else
    {
       return prop.read(book).toString();
    }
}

