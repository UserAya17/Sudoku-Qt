#include <thread>
#include "Sudoku.h"
#include <chrono>
#include <thread>
#include <time.h>
#include <iostream>

#include <QCoreApplication>
#include <QThread>

#include <cstdlib>  // Pour utiliser la fonction rand()
#include <ctime>    // Pour initialiser le générateur de nombres aléatoires


int NumSolutionFound = 0;
const int EMPTY = 0;
#define N 9
// No. Of missing digits
int mat[N][N];
int grid[N][N] = {
   {0, 0, 0, 0, 0, 0, 0, 0, 0},
   {0, 0, 0, 0, 0, 0, 0, 0, 0},
   {0, 0, 0, 0, 0, 0, 0, 0, 0},
   {0, 0, 0, 0, 0, 0, 0, 0, 0},
   {0, 0, 0, 0, 0, 0, 0, 0, 0},
   {0, 0, 0, 0, 0, 0, 0, 0, 0},
   {0, 0, 0, 0, 0, 0, 0, 0, 0},
   {0, 0, 0, 0, 0, 0, 0, 0, 0},
   {0, 0, 0, 0, 0, 0, 0, 0, 0}
};

int previousgrid[N][N] = {
   {0, 0, 0, 0, 0, 0, 0, 0, 0},
   {0, 0, 0, 0, 0, 0, 0, 0, 0},
   {0, 0, 0, 0, 0, 0, 0, 0, 0},
   {0, 0, 0, 0, 0, 0, 0, 0, 0},
   {0, 0, 0, 0, 0, 0, 0, 0, 0},
   {0, 0, 0, 0, 0, 0, 0, 0, 0},
   {0, 0, 0, 0, 0, 0, 0, 0, 0},
   {0, 0, 0, 0, 0, 0, 0, 0, 0},
   {0, 0, 0, 0, 0, 0, 0, 0, 0}
};
// number of columns/rows.

double SRNd = sqrt(N);
int SRN = (int)SRNd;

// square root of N
int K = 20;
std::vector<Move> moves;  // Vecteur de structures Move
    // Fonction pour empiler un mouvement dans l'historique
    void Sudoku::pushMove(int x, int y, int value) {
        Move move(x, y, value);
        moves.push_back(move);
        qDebug() << "***********************add move: " << x<<y<<value;
    }

    // Fonction pour dépiler un mouvement de l'historique
  // Fonction pour dépiler un mouvement de l'historique
    void Sudoku::popMove()
    {
        qDebug() << "Before popMove - Number of moves: " << moves.size();

        if (!moves.empty()) {
            Move& lastMove = moves.back();
            qDebug() << "Retourne par modifier: (" << lastMove.x << ", " << lastMove.y << ") Value: " << lastMove.v;

            if (lastMove.x >= 0 && lastMove.x < 9 && lastMove.y >= 0 && lastMove.y < 9) {
               // QTableWidgetItem* item = new QTableWidgetItem(lastMove.v != 0 ? QString::number(lastMove.v) : "");


               // ui->Table->setItem(lastMove.x, lastMove.y, item);

                //ui->Table->setItem(lastMove.x, lastMove.y, new QTableWidgetItem);
                QString str = " ";
                    if(lastMove.v!=0) 
                    str = QString::number(lastMove.v);
                    ui->Table->item(lastMove.x, lastMove.y)->setText(str);


                moves.pop_back();
            }
            else {
                qDebug() << "Invalid indices for the table.";
            }

            // DisplayGrid();
        }
        else {
            qDebug() << "History is empty. Cannot pop.";
        }

        qDebug() << "After popMove - Number of moves: " << moves.size();
    }




    // Fonction pour afficher l'historique (à titre indicatif)
    void displayHistory() {
        for (const Move& move : moves) {
            qDebug() << "Move: (" << move.x << ", " << move.y << ") Value: " << move.v;
        }
    }

    void clearHistory() {
        moves.clear();
        std::cout << "History cleared." << std::endl;
    }

    int x11=0, y11=0, v11=-1;

    void Sudoku::onCurrentItemChanged(QTableWidgetItem* current, QTableWidgetItem* previous)
    {
        Q_UNUSED(previous);

        if (current) {
            int row = current->row();
            int col = current->column();
            int value = current->text().toInt();

            // Handle the current cell's information
           // qDebug() << "Cell at (" << row << ", " << col << ") selected with value: " << value;
            x11 = row; y11 = col; v11 = value;
           
           
        }
    }

    void Sudoku::onCellChanged(int row, int col)
    {
        // Retrieve the modified value when the cell is changed
        QTableWidgetItem* item = ui->Table->item(row, col);
        if (item) {
            int modifiedValue = item->text().toInt();
            if (v11 != modifiedValue && v11!=-1)
            {
                pushMove(x11, y11, v11);
                // Handle the modified value
               // qDebug() << "Cell at (" << row << ", " << col << ") changed to: " << modifiedValue;
                qDebug() << "push (" << x11 << ", " << y11 << ") puch to " << v11 << "\n";
            }
        }
    }





Sudoku::Sudoku(QWidget* parent)
    : QMainWindow(parent),
    ui(new Ui::SudokuClass)
{
    ui->setupUi(this);
    // Initialiser la matrice avec une configuration de Sudoku valide
    initializeGrid();
    // Connect currentItemChanged signal
    connect(ui->Table, &QTableWidget::currentItemChanged, this, &Sudoku::onCurrentItemChanged);

    // Connect cellChanged signal
    connect(ui->Table, &QTableWidget::cellChanged, this, &Sudoku::onCellChanged);
    // Mettre à jour l'interface graphique
    DisplayGrid();
}

Sudoku::~Sudoku()
{
    delete ui;
}

void Sudoku::on_Clear_clicked()
{
    /*for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            ui->Table->setItem(i, j, new QTableWidgetItem);
            grid[i][j] = EMPTY;
        }
    }*/
    // Initialiser la matrice avec une configuration de Sudoku valide
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            //grid[i][j] = initialSudokuConfig[i][j];
            grid[i][j] = mat[i][j];
            previousgrid[i][j] = grid[i][j];
        }
    }
    clearHistory();

    // Mettre à jour l'interface graphique
    DisplayGrid();
}


void Sudoku::on_CntrlzButton_clicked()
{
    /*for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            ui->Table->setItem(i, j, new QTableWidgetItem);
            grid[i][j] = EMPTY;
        }
    }*/
    // Initialiser la matrice avec une configuration de Sudoku valide

   popMove();

    // Mettre à jour l'interface graphique
   // DisplayGrid();
}


void Sudoku::on_RandomV_clicked()
{
    /*for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            ui->Table->setItem(i, j, new QTableWidgetItem);
            grid[i][j] = EMPTY;
        }
    }*/
    // Initialiser la matrice avec une configuration de Sudoku valide

    if (ui->radioButton->isChecked())
    {
        K = 20;
    }
    else if (ui->radioButton_2->isChecked())
    {
        K = 40;
    }
    else if (ui->radioButton_3->isChecked())
    {
        K = 60;
    }
    //clearHistory();
    initializeGrid();

    // Mettre à jour l'interface graphique
    DisplayGrid();
}


void Sudoku::on_SolveSlow_clicked()
{
    ui->ErrorLabel->setText(" ");
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            grid[i][j] = EMPTY;
        }
    }

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            QTableWidgetItem* cell = ui->Table->item(i, j);
            if (cell) {
                if (cell->text().toInt() > 0)
                {
                    if (cell->text().toInt() >= 10)
                    {
                        ui->ErrorLabel->setText("Cellule supérieure à 9");
                        return;
                    }
                    if (isValidPlace(i, j, cell->text().toInt()) == false)
                    {
                        ui->ErrorLabel->setText("Sudoku incorrect");
                        return;
                    }
                }
                grid[i][j] = cell->text().toInt();
            }
            previousgrid[i][j] = grid[i][j];
           
        }
    }

    GreyCells();
    connect(this, &Sudoku::on_Stopped, &SolveThread, &Solve::Stop);
    connect(&SolveThread, &Solve::NewItem, this, &Sudoku::DisplaySingleItem);


    QtConcurrent::run(&Solve::start, &this->SolveThread, grid, ui->horizontalSlider->value());
   
    DisplayGrid();
}





void Sudoku::on_Stop_Recussion_clicked()
{
    emit on_Stopped();
}


void Sudoku::on_Solve_clicked()
{
    ui->ErrorLabel->setText(" ");
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            grid[i][j] = EMPTY;
        }
    }

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            QTableWidgetItem* cell = ui->Table->item(i, j);
            if (cell) {
                if (cell->text().toInt() > 0)
                {
                    if (cell->text().toInt() >= 10)
                    {
                        ui->ErrorLabel->setText("Cellule supérieure à 9");
                        return;
                    }
                    if (isValidPlace(i, j, cell->text().toInt()) == false)
                    {
                        ui->ErrorLabel->setText("Sudoku incorrect");
                        return;
                    }
                }
                grid[i][j] = cell->text().toInt();
                //pushMove(i, j, grid[i][j]);
                qDebug() << "hihihihihihihhiadd add move: " << i << j << grid[i][j];
            }
            previousgrid[i][j] = grid[i][j];
           
        }
    }
    GreyCells();
    qDebug() << "Solving";
    bool test = solveSudoku();
    qDebug() << "Solved";

    NumSolutionFound = 0;
    bool test1 = solveSudokuNumber();


    DisplayGrid();

}

void Sudoku::on_Undo_Solve_clicked() {

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            grid[i][j] = previousgrid[i][j];
            ui->Table->setItem(i, j, new QTableWidgetItem);
            if (grid[i][j] > 0) {
                QString str = QString::number(grid[i][j]);
                ui->Table->item(i, j)->setText(str);
                ui->Table->item(i, j)->setBackground(Qt::white);
            }
        }
    }
    displayHistory();
}



void Sudoku::DisplayGrid()
{
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            ui->Table->setItem(i, j, new QTableWidgetItem);
            if (grid[i][j] > 0) {
                QString str = QString::number(grid[i][j]);
                ui->Table->item(i, j)->setText(str);
                if (previousgrid[i][j] > 0)
                {
                    ui->Table->item(i, j)->setBackground(Qt::gray);
                }
            }
        }
    }
    update();
}

void Sudoku::GreyCells()
{
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            ui->Table->setItem(i, j, new QTableWidgetItem);
            if (grid[i][j] > 0) {
                QString str = QString::number(grid[i][j]);
                ui->Table->item(i, j)->setText(str);
                ui->Table->item(i, j)->setBackground(Qt::gray);
            }
        }
    }
    update();
}

void Sudoku::DisplaySingleItem(int i, int j, int n)
{
    ui->Table->setItem(i, j, new QTableWidgetItem);
    QString str = QString::number(n);
    ui->Table->item(i, j)->setText(str);
}


bool Sudoku::isPresentInCol(int col, int num) { //check whether num is present in col or not
    for (int row = 0; row < N; row++)
        if (grid[row][col] == num)
            return true;
    return false;
}
bool Sudoku::isPresentInRow(int row, int num) { //check whether num is present in row or not
    for (int col = 0; col < N; col++)
        if (grid[row][col] == num)
            return true;
    return false;
}
bool Sudoku::isPresentInBox(int boxStartRow, int boxStartCol, int num) {
    //check whether num is present in 3x3 box or not
    for (int row = 0; row < 3; row++)
        for (int col = 0; col < 3; col++)
            if (grid[row + boxStartRow][col + boxStartCol] == num)
                return true;
    return false;
}
bool Sudoku::findEmptyPlace(int& row, int& col) { //get empty location and update row and column
    for (row = 0; row < N; row++)
        for (col = 0; col < N; col++)
            if (grid[row][col] == 0) //marked with 0 is empty
                return true;
    return false;
}
bool Sudoku::isValidPlace(int row, int col, int num) {
    //when item not found in col, row and current 3x3 box
    return !isPresentInRow(row, num) && !isPresentInCol(col, num) && !isPresentInBox(row - row % 3,
        col - col % 3, num);
}
bool Sudoku::solveSudoku() {
    int row, col;
    if (!findEmptyPlace(row, col))
        return true; //when all places are filled
    for (int num = 1; num <= 9; num++) { //valid numbers are 1 - 9
        if (isValidPlace(row, col, num)) { //check validation, if yes, put the number in the grid
            grid[row][col] = num;
            if (solveSudoku()) //recursively go for other rooms in the grid
                return true;
            grid[row][col] = 0; //turn to unassigned space when conditions are not satisfied
        }
    }
    return false;
}

bool Sudoku::solveSudokuNumber() {
    int row, col;
    if (!findEmptyPlace(row, col))
        NumSolutionFound++;
    qDebug() << "Number solutions found is " << NumSolutionFound;
    return false; //when all places are filled
    for (int num = 1; num <= 9; num++) { //valid numbers are 1 - 9
        if (isValidPlace(row, col, num)) { //check validation, if yes, put the number in the grid
            grid[row][col] = num;
            if (solveSudoku()) //recursively go for other rooms in the grid
                return true;
            grid[row][col] = 0; //turn to unassigned space when conditions are not satisfied
        }
    }
    return false;
}


void Sudoku::resetToInitial()
{
    // Remettre la grille à sa configuration initiale
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            grid[i][j] = previousgrid[i][j];
            ui->Table->setItem(i, j, new QTableWidgetItem);
            if (grid[i][j] > 0) {
                QString str = QString::number(grid[i][j]);
                ui->Table->item(i, j)->setText(str);
                ui->Table->item(i, j)->setBackground(Qt::white);
            }
        }
    }
}





//-------------gerer sudoku
/* C++ program for Sudoku generator */




    // Random generator
    int randomGenerator(int num)
    {
        return (int)floor(
            (float)(rand() / double(RAND_MAX) * num + 1));
    }

    // Returns false if given 3 x 3 block contains num.
    bool unUsedInBox(int rowStart, int colStart, int num)
    {
        for (int i = 0; i < SRN; i++) {
            for (int j = 0; j < SRN; j++) {
                if (mat[rowStart + i][colStart + j]
                    == num) {
                    return false;
                }
            }
        }
        return true;
    }
    // Fill a 3 x 3 matrix.
    void fillBox(int row, int col)
    {
        int num;
        for (int i = 0; i < SRN; i++) {
            for (int j = 0; j < SRN; j++) {
                do {
                    num = randomGenerator(N);
                } while (!unUsedInBox(row, col, num));
                mat[row + i][col + j] = num;
            }
        }
    }

    // Fill the diagonal SRN number of SRN x SRN matrices
    void fillDiagonal()
    {
        for (int i = 0; i < N; i = i + SRN)
        {

            // for diagonal box, start coordinates->i==j
            fillBox(i, i);
        }
    }


    // check in the row for existence
    bool unUsedInRow(int i, int num)
    {
        for (int j = 0; j < N; j++) {
            if (mat[i][j] == num) {
                return false;
            }
        }
        return true;
    }

    // check in the row for existence
    bool unUsedInCol(int j, int num)
    {
        for (int i = 0; i < N; i++) {
            if (mat[i][j] == num) {
                return false;
            }
        }
        return true;
    }
    // Check if safe to put in cell
    bool CheckIfSafe(int i, int j, int num)
    {
        return (
            unUsedInRow(i, num) && unUsedInCol(j, num)
            && unUsedInBox(i - i % SRN, j - j % SRN, num));
    }

    // A recursive function to fill remaining
    // matrix
    bool fillRemaining(int i, int j)
    {
        // System.out.println(i+" "+j);
        if (j >= N && i < N - 1) {
            i = i + 1;
            j = 0;
        }
        if (i >= N && j >= N) {
            return true;
        }
        if (i < SRN) {
            if (j < SRN) {
                j = SRN;
            }
        }
        else if (i < N - SRN) {
            if (j == (int)(i / SRN) * SRN) {
                j = j + SRN;
            }
        }
        else {
            if (j == N - SRN) {
                i = i + 1;
                j = 0;
                if (i >= N) {
                    return true;
                }
            }
        }
        for (int num = 1; num <= N; num++) {
            if (CheckIfSafe(i, j, num)) {
                mat[i][j] = num;
                if (fillRemaining(i, j + 1)) {
                    return true;
                }
                mat[i][j] = 0;
            }
        }
        return false;
    }
    // Remove the K no. of digits to
    // complete game
    void removeKDigits()
    {
        int count = K;
        while (count != 0) {
            int cellId = randomGenerator(N * N) - 1;
            // System.out.println(cellId);
            // extract coordinates i and j
            int i = (cellId / N);
            int j = cellId % N;
            if (j != 0) {
                j = j - 1;
            }
            // System.out.println(i+" "+j);
            if (mat[i][j] != 0) {
                count--;
                mat[i][j] = 0;
            }
        }
    }


    // Sudoku Generator
    void fillValues()
    {

        // Fill the diagonal of SRN x SRN matrices
        fillDiagonal();

        // Fill remaining blocks
        fillRemaining(0, SRN);

        // Remove Randomly K digits to make game
        removeKDigits();
    }

    // Ajoutez cette fonction membre à la classe Sudoku pour initialiser la grille avec une configuration de Sudoku valide
    void Sudoku::initializeGrid()
    {
        // Modifiez cette fonction pour initialiser la matrice avec une configuration de Sudoku valide
        // Par exemple, vous pouvez remplacer cette boucle par une configuration de Sudoku prédéfinie.
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                //grid[i][j] = initialSudokuConfig[i][j];
                mat[i][j]=0;
               
            }
        }

        fillValues();

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                //grid[i][j] = initialSudokuConfig[i][j];
                grid[i][j] = mat[i][j];
                previousgrid[i][j] = grid[i][j];
            }
        }
    }