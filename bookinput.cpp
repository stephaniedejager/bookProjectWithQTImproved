#include "bookinput.h"
#include "ui_bookinput.h"
#include "book.h"
#include "bookwriter.h"
#include <QMetaProperty>
#include <QMessageBox>

BookInput::BookInput(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::BookInput)
{
    ui->setupUi(this);
    ui->dateEditPublicationDate->setDate(QDate::currentDate());
}

BookInput::~BookInput()
{
    delete ui;
}

void BookInput::on_pushButtonSave_clicked()
{
    readFromGui();
}

void BookInput::readFromGui()
{
    QString title = ui->lineEditTitle->text();
    QString authorsString = ui->lineEditAuthors->text();
    QString isbn = ui->lineEditIsbn->text();
    QDate publicationDate = ui->dateEditPublicationDate->date();

    if(!title.isEmpty() && !authorsString.isEmpty() && !isbn.isEmpty() && !publicationDate.isNull())
    {
        QStringList authors = authorsString.split(",");
        createAndSaveBook(title, authors, isbn, publicationDate);
        clear();
    }
    else
    {
        QMessageBox::warning(0, "Book Information Invalid", "Please enter all the necessary information");
    }
}

void BookInput::createAndSaveBook(QString title, QStringList authors, QString isbn, QDate publicationDate)
{
    Book *b = new Book();

    b->setProperty("title", title);
    b->setProperty("authors", authors);
    b->setProperty("isbn", isbn);
    b->setProperty("publicationDate", publicationDate);

    bookWriter->write(b);

    QMessageBox::information(0,"Book Information", "Book saved");
}

void BookInput::clear()
{
    ui->lineEditTitle->clear();
    ui->lineEditAuthors->clear();
    ui->lineEditIsbn->clear();
    ui->dateEditPublicationDate->setDate(QDate::currentDate());
}
