#include "book.h"

Book::Book() : title("UNKNOWN"), authors("UNKNOWN"), isbn("UNKNOWN"), publicationDate(QDate::currentDate())
{

}

Book::Book(QString t, QStringList a, QString i, QDate p)

{
    setTitle(t);
    setAuthors(a);
    setIsbn(i);
    setPublicationDate(p);
}

void Book::setTitle(QString t)
{
    title = t;
}

void Book::setAuthors (QStringList a)
{
    authors = a;
}

void Book::setIsbn (QString i)
{
    isbn = i;
}
void Book::setPublicationDate (QDate p)
{
    publicationDate = p;
}

QString Book::getTitle() const
{
    return title;
}

QStringList Book::getAuthors() const
{
     return authors;
}

QString Book::getIsbn() const
{
    return isbn;
}

QDate Book::getPublicationDate() const
{
    return publicationDate;
}

