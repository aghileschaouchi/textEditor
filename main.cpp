#include "texteditor.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TextEditor tEditor;
    tEditor.show();

    return a.exec();
}
