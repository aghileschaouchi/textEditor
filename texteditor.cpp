#include "texteditor.h"
#include "ui_texteditor.h"

TextEditor::TextEditor(QWidget *parent) :
    QWidget(parent)
{
    setFixedSize(1200, 800);

    button = new QPushButton("Open file", this);
    button -> move (600, 10);
    connect(button, SIGNAL(clicked()), this, SLOT(load_file()));

    editor = new QTextEdit(this);
    editor->setFixedSize(800, 600);
    editor->move(10, 100);
}

void TextEditor::load_file()
{
    QString file_name = QFileDialog::getOpenFileName(this,
            tr("Open file"));
    if (file_name.isEmpty())
        return;
    else
    {
        editor->clear();

        QFile file(file_name);
        QString line;

        if (!file.open(QIODevice::ReadOnly))
        {
            QMessageBox::information(this,
                                     tr("Impossible d'ouvrir le ficher"),
                                     file.errorString());
            return;
        }
        qDebug() << file_name;

        QTextStream stream(&file);

        while(!stream.atEnd())
        {
            QString line = stream.readLine();

            if (line.size() > 20)
            {
                const char ins = '\n';
                const int dec = 20;

                for(int i = dec; i <= line.size(); i += dec+1)
                {
                    line.insert(i, ins);
                    qDebug() << line;
                }
            qDebug() << line;

            }

            editor->append(line);
        }
        file.close();
    }
}



