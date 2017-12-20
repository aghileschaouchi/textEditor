#include "texteditor.h"
#include "ui_texteditor.h"

TextEditor::TextEditor(QWidget *parent) :
    QWidget(parent)
{
    setFixedSize(1200, 800);

    button = new QPushButton("Open file", this);
    button -> move (600, 10);

    editor = new QTextEdit(this);
    editor->setFixedSize(800, 600);
    editor->move(10, 100);
}

