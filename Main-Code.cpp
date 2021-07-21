#include<bits/stdc++.h>
using namespace std;
int matrix[9][9];
class sudoku
{
public:
    sudoku();
    char introd();
    void initializeSudokuGrid(char x);
    void printSudokuGrid();
    bool solveSudoku();
    bool findEmptyGridSlot(int& row, int& col);
    bool canPlaceNum(int row, int col, int num);
    bool numAlreadyInRow(int row, int num);
    bool numAlreadyInCol(int col, int num);
    bool numAlreadyInBox(int smallGridRow, int smallGridCol, int num);
    int grid[9][9];
    void input();
    int matrix[9][9];
    bool compare();
};

sudoku::sudoku()
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            grid[i][j] = 0;
        }
    }
    //cout << "\n all the grid locations are initialise to zero";
    
}

char sudoku::introd() {
    int coins = 100;
    cout << "Hello and Welcome to Sudoku King !!" << endl;
    cout << "The rules of the game are simple:" << endl;
    cout << " 1. Every square has to contain a single number." << endl;
    cout << " 2. Only the numbers from 1 through to 9 can be used." << endl;
    cout << " 3. Each (3*3) box can only contain each number from 1 to 9 once." << endl;
    cout << " 4. Each vertical column can only contain each number from 1 to 9 once." << endl;
    cout << " 5. Each horizontal row can only contain each number from 1 to 9 once" << endl;
    //cout << "Here's a 100 bucks. Let's see what you can do with this amount !! All the best !" << endl;
    char c;
    cout << "Choose your level - 'e' for Easy, 'm' for Medium and 'h' for hard !!" << endl;
    cin >> c;
    return c;
}

void sudoku::initializeSudokuGrid(char x)
{
    if (x == 'e') {
        grid[0][0] = 1;
        grid[0][2] = 3;
        grid[0][3] = 9;
        grid[0][5] = 5;
        grid[0][7] = 4;
        grid[0][8] = 2;
        grid[1][0] = 5;
        grid[1][1] = 9;
        grid[1][3] = 7;
        grid[1][4] = 2;
        grid[1][5] = 1;
        grid[1][6] = 3;
        grid[1][8] = 8;
        grid[2][0] = 7;
        grid[2][2] = 2;
        grid[2][3] = 4;
        grid[2][5] = 8;
        grid[2][7] = 9;
        grid[2][8] = 5;
        grid[3][0] = 3;
        grid[3][2] = 9;
        grid[3][4] = 5;
        grid[3][5] = 6;
        grid[3][7] = 1;
        grid[3][8] = 7;
        grid[4][0] = 2;
        grid[4][1] = 5;
        grid[4][3] = 3;
        grid[4][5] = 7;
        grid[4][7] = 8;
        grid[4][8] = 4;
        grid[5][0] = 8;
        grid[5][1] = 1;
        grid[5][3] = 2;
        grid[5][4] = 4;
        grid[5][6] = 5;
        grid[5][8] = 6;
        grid[6][1] = 7;
        grid[6][3] = 6;
        grid[6][5] = 2;
        grid[6][6] = 8;
        grid[6][8] = 3;
        grid[7][0] = 6;
        grid[7][2] = 5;
        grid[7][3] = 1;
        grid[7][4] = 8;
        grid[7][7] = 7;
        grid[8][0] = 9;
        grid[8][1] = 3;
        grid[8][3] = 5;
        grid[8][5] = 4;
        grid[8][8] = 1;
    }
    else if (x == 'm') {
        grid[0][0] = 1;
        grid[0][2] = 9;
        grid[0][4] = 6;
        grid[0][6] = 7;
        grid[0][8] = 8;
        grid[1][1] = 8;
        grid[1][3] = 2;
        grid[1][5] = 3;
        grid[1][7] = 9;
        grid[2][0] = 6;
        grid[2][2] = 2;
        grid[2][4] = 7;
        grid[2][6] = 4;
        grid[2][8] = 3;
        grid[3][1] = 1;
        grid[3][3] = 7;
        grid[3][5] = 2;
        grid[3][7] = 8;
        grid[4][0] = 2;
        grid[4][2] = 5;
        grid[4][4] = 8;
        grid[4][6] = 9;
        grid[4][8] = 4;
        grid[5][1] = 9;
        grid[5][3] = 3;
        grid[5][5] = 5;
        grid[5][7] = 7;
        grid[6][0] = 5;
        grid[6][2] = 8;
        grid[6][4] = 3;
        grid[6][6] = 1;
        grid[6][8] = 2;
        grid[7][1] = 6;
        grid[7][3] = 4;
        grid[7][5] = 8;
        grid[7][7] = 5;
        grid[8][0] = 9;
        grid[8][2] = 3;
        grid[8][4] = 5;
        grid[8][6] = 8;
        grid[8][8] = 7;
    }
    else if (x == 'h') {
        grid[0][0] = 6;
        grid[0][3] = 2;
        grid[0][5] = 1;
        grid[0][8] = 4;
        grid[1][1] = 5;
        grid[1][3] = 4;
        grid[1][6] = 7;
        grid[1][8] = 9;
        grid[2][0] = 9;
        grid[2][3] = 5;
        grid[2][5] = 6;
        grid[2][7] = 1;
        grid[3][2] = 2;
        grid[3][4] = 6;
        grid[3][6] = 9;
        grid[3][8] = 7;
        grid[4][1] = 9;
        grid[4][2] = 6;
        grid[4][5] = 4;
        grid[4][7] = 5;
        grid[5][0] = 5;
        grid[5][1] = 7;
        grid[5][3] = 1;
        grid[5][4] = 8;
        grid[5][6] = 3;
        grid[6][0] = 1;
        grid[6][2] = 3;
        grid[6][4] = 4;
        grid[6][6] = 8;
        grid[6][7] = 7;
        grid[7][1] = 2;
        grid[7][5] = 7;
        grid[7][7] = 3;
        grid[7][8] = 1;
        grid[8][0] = 7;
        grid[8][2] = 5;
        grid[8][6] = 4;
        grid[8][8] = 2;
    }
}

void sudoku::printSudokuGrid()
{
    cout << "\n";
    string fin[9][9];
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if(grid[i][j]==0)
                fin[i][j]="_";
            else    
                fin[i][j]=to_string(grid[i][j]);
        }
    }
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cout<<fin[i][j]<<"  ";
        }
        cout<<endl;
    }
}

bool sudoku::solveSudoku()
{
    int row, col;
    if (findEmptyGridSlot(row, col))
    {
        for (int num = 1; num <= 9; num++)
        {
            if (canPlaceNum(row, col, num))
            {
                grid[row][col] = num;
                if (solveSudoku()) //recursive call
                    return true;
                grid[row][col] = 0;
            }
        }
        return false; //backtrack
    }
    else
        return true; //there are no empty slots
}

bool sudoku::numAlreadyInRow(int row, int num)
{
    for (int i = 0; i < 9; i++)
    {
        if (num != 0 && grid[row][i] == num)
            return true;
    }
    return false;
}

bool sudoku::numAlreadyInCol(int col, int num)
{
    for (int i = 0; i < 9; i++)
    {
        if (num != 0 && grid[i][col] == num)
            return true;
    }
    return false;
}

bool sudoku::canPlaceNum(int row, int col, int num)
{
    if (!numAlreadyInRow(row, num))
    {
        if (!numAlreadyInCol(col, num))
        {
            int smallGridRow = row - row % 3;
            int smallGridCol = col - col % 3;
            if (!numAlreadyInBox(smallGridRow, smallGridCol, num))
            {
                return true;
            }
        }
    }
    return false;
}

bool sudoku::numAlreadyInBox(int smallGridRow, int smallGridCol, int num)
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (grid[i + smallGridRow][j + smallGridCol] == num)
                return true;
        }
    }
    return false;
}

bool sudoku::findEmptyGridSlot(int& row, int& col)
{
    for (row = 0; row < 9; row++)
    {
        for (col = 0; col < 9; col++)
        {
            if (grid[row][col] == 0)
                return true;
        }
    }
    return false;
}

void sudoku::input(){
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            cin>>matrix[i][j];
        }
    }
}

bool sudoku::compare()
{
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            if(matrix[i][j] == grid[i][j])
            {
                return true;
            }
            else 
            {
                return false;
            }
        }
    }
}

int main()
{
   
    char var = 'y';
    while (var == 'y') {
        sudoku s;
        char u = s.introd();
        s.initializeSudokuGrid(u);
        s.printSudokuGrid();
        if (u == 'e') {
            s.input();
        }
        else if (u == 'm') {
            s.input();
        }
        else if (u == 'h') {
            s.input();
        }
        
        cout << "\nWell time's up\n";
        if (s.solveSudoku())
        {cout<< "Answer Grid: \n";
            s.printSudokuGrid();
            if(s.compare())
            {
                cout<<"What you did was correct !!!";
            }
            else
            {
                cout<<"What you did was Wrong _";
            }
        }
        else
            cout << "\nNo solution exists :( try something different.\n";
        cout<<"\nTake a copy if you didn't succeeded and try again later with better practice.\n";
        cout << "Wanna play more?(y/n)" << endl;
        cin >> var;
    }
    return 0;
}