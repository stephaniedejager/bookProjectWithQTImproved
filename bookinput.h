#ifndef BOOKINPUT_H
#define BOOKINPUT_H

#include <QMainWindow>
#include "bookwriter.h"

namespace Ui {
class BookInput;
}

class BookInput : public QMainWindow
{
    Q_OBJECT

public:
    explicit BookInput(QWidget *parent = 0);
    ~BookInput();

private slots:
    void on_pushButtonSave_clicked();

private:
    Ui::BookInput *ui;
    void readFromGui();
    void createAndSaveBook(QString title, QStringList authors, QString isbn, QDate publicationDate);
    void clear();
    BookWriter *bookWriter;
};

#endif // BOOKINPUT_H
