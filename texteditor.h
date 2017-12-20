#ifndef TEXTEDITOR_H
#define TEXTEDITOR_H

#include <QWidget>
#include <QtWidgets>
#include <QDebug>

namespace Ui {
class TextEditor;
}

class TextEditor : public QWidget
{
    Q_OBJECT

public:
    explicit TextEditor(QWidget *parent = 0);

private:
    QTextEdit *editor;
    QPushButton *button;
public slots:
    void load_file();

};

#endif // TEXTEDITOR_H
