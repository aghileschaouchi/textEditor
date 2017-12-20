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
        editor -> setText(stream.readAll());

        file.close();
    }
}



