#include "Sudoku.h"
#include <QtWidgets/QApplication>

int main(int argc, char* argv[])
{
    srand(static_cast<unsigned>(time(nullptr)));
    QApplication a(argc, argv);
    Sudoku w;
    w.show();
    return a.exec();
}
