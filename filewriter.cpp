#include <QFile>
#include <QTextStream>
#include "filewriter.h"

FileWriter::FileWriter(QString fn): fileName(fn)
{
}

void FileWriter::write(QString s) const
{
    QFile file(fileName);
    file.open(QIODevice::Append);
    QTextStream toFile(&file);
    toFile << s;
    file.close();
}
