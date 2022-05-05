#ifndef BOOKWRITER_H
#define BOOKWRITER_H

#include "book.h"
#include <QString>
#include <QMetaProperty>

class BookWriter
{
public:
    BookWriter();
    void write(Book *b);
    QString getPropertyEntry(QMetaProperty prop, Book *b);
    static QString filename;
};

#endif // BOOKWRITER_H
