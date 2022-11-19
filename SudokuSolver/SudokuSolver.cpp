#include <iostream>
#include <vector>
#include <set>
using namespace std;
class Solution {
public:
    vector<vector<char>> sudokuRecurse(vector<vector<char>> board, vector<vector<set<int>>> matrixSet, int blanks)
    {
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] == '.') // If empty
                {
                    if (matrixSet[i][j].size() < 9)
                    {
                        pair<set<int>::iterator, bool> ret;
                        for (int k = 1; k < 10; k++)
                        {
                            ret = matrixSet[i][j].insert(k); // Add the value and if it fails then you know it can't be that number.
                            if (ret.second) // If duplicate is not found
                            {   
                                board[i][j] = k + 48;
                                vector<vector<set<int>>> tempSet = matrixSet;
                                for (int rowAndColumn = 0; rowAndColumn < 9; rowAndColumn++) // Inserts the rest of the row and columns
                                {
                                    if(board[rowAndColumn][j] == '.')
                                        tempSet[rowAndColumn][j].insert(k);
                                    if(board[i][rowAndColumn] == '.')
                                        tempSet[i][rowAndColumn].insert(k);
                                    if (tempSet[rowAndColumn][j].size() == 9 && board[rowAndColumn][j] == '.') // MIGHT BE WRONG CHECK LATER
                                        goto next;
                                    if (tempSet[i][rowAndColumn].size() == 9 && board[i][rowAndColumn] == '.')
                                        goto next;
                                }
                                if (i < 3 && j < 3)
                                    for (int l = 0; l < 3; l++)
                                        for (int m = 0; m < 3; m++)
                                        {
                                            tempSet[l][m].insert(k);
                                            if (tempSet[l][m].size() == 9 && board[l][m] == '.')
                                                goto next;
                                        }
                                else if (i < 3 && j > 2 && j < 6)
                                    for (int l = 0; l < 3; l++)
                                        for (int m = 3; m < 6; m++)
                                        {
                                            tempSet[l][m].insert(k);
                                            if (tempSet[l][m].size() == 9 && board[l][m] == '.')
                                                goto next;
                                        }
                                else if (i < 3 && j > 5 && j < 9)
                                    for (int l = 0; l < 3; l++)
                                        for (int m = 6; m < 9; m++)
                                        {
                                            tempSet[l][m].insert(k);
                                            if (tempSet[l][m].size() == 9 && board[l][m] == '.')
                                                goto next;
                                        }
                                else if (i > 2 && i < 6 && j < 3)
                                    for (int l = 3; l < 6; l++)
                                        for (int m = 0; m < 3; m++)
                                        {
                                            tempSet[l][m].insert(k);
                                            if (tempSet[l][m].size() == 9 && board[l][m] == '.')
                                                goto next;
                                        }
                                else if (i > 2 && i < 6 && j > 2 && j < 6)
                                    for (int l = 3; l < 6; l++)
                                        for (int m = 3; m < 6; m++)
                                        {
                                            tempSet[l][m].insert(k);
                                            if (tempSet[l][m].size() == 9 && board[l][m] == '.')
                                                goto next;
                                        }
                                else if (i > 2 && i < 6 && j > 5 && j < 9)
                                    for (int l = 3; l < 6; l++)
                                        for (int m = 6; m < 9; m++)
                                        {
                                            tempSet[l][m].insert(k);
                                            if (tempSet[l][m].size() == 9 && board[l][m] == '.')
                                                goto next;
                                        }
                                else if (i > 5 && i < 9 && j < 3)
                                    for (int l = 6; l < 9; l++)
                                        for (int m = 0; m < 3; m++)
                                        {
                                            tempSet[l][m].insert(k);
                                            if (tempSet[l][m].size() == 9 && board[l][m] == '.')
                                                goto next;
                                        }
                                else if (i > 5 && i < 9 && j > 2 && j < 6)
                                    for (int l = 6; l < 9; l++)
                                        for (int m = 3; m < 6; m++)
                                        {
                                            tempSet[l][m].insert(k);
                                            if (tempSet[l][m].size() == 9 && board[l][m] == '.')
                                                goto next;
                                        }
                                else if (i > 5 && i < 9 && j > 5 && j < 9)
                                    for (int l = 6; l < 9; l++)
                                        for (int m = 6; m < 9; m++)
                                        {
                                            tempSet[l][m].insert(k);
                                            if (tempSet[l][m].size() == 9 && board[l][m] == '.')
                                                goto next;
                                        }
                                vector<vector<char>> tempBoard;
                                tempBoard = sudokuRecurse(board, tempSet, blanks - 1);
                                if (tempBoard[0][0] != 'a')
                                    return tempBoard;
                            }
                        next:
                            continue;
                        }
                        board[0][0] = 'a';
                        return board;
                    }
                    else // Wrong Path
                    {
                        board[0][0] = 'a';
                        return board;
                    }
                }
            }
        }
        return board; // reaches this if its the end of the board.
    }


    void solveSudoku(vector<vector<char>>& board) {
        vector<vector<int>> xSet;
        vector<vector<int>> ySet;
        vector<vector<int>> xySet;
        int k = 0;
        int xyInc = 0;
        int blanks = 0;
        for (int j = 0; j < 9; j++)
        {
            vector<int> xAxis;
            vector<int> yAxis;
            vector<int> xyAxis;
            if (j == 3 || j == 6)
            {
                k = j;
                xyInc = 0;
            }
            for (int i = 0; i < 9; i++)
            {
                if (board[j][i] != '.')
                    xAxis.push_back(board[j][i] - 48);
                if (board[i][j] != '.')
                    yAxis.push_back(board[i][j] - 48);
                if (i < 3 && board[0 + k][i + xyInc] != '.')
                    xyAxis.push_back(board[0 + k][i + xyInc] - 48);
                else if (i > 2 && i < 6 && board[1 + k][i % 3 + xyInc] != '.')
                    xyAxis.push_back(board[1 + k][i % 3 + xyInc] - 48);
                else if (i > 5 && board[2 + k][i % 3 + xyInc] != '.')
                    xyAxis.push_back(board[2 + k][i % 3 + xyInc] - 48);
                else
                    ++blanks;
            }
            xyInc += 3;
            xSet.push_back(xAxis);
            ySet.push_back(yAxis);
            xySet.push_back(xyAxis);
        }
        // Push it to set
        vector<vector<set<int>>> matrixSet;
        vector<set<int>> aLayer;
        set<int> aSet;
        for (int i = 0; i < 9; i++)
        {
            for (k = 0; k < xSet[i].size(); k++) // we can save it?
                aSet.insert(xSet[i][k]);
            for (int j = 0; j < 9; j++)
            {
                set<int> bSet;
                for (int l = 0; l < ySet[j].size(); l++)
                    bSet.insert(ySet[j][l]);
                bSet.insert(aSet.begin(), aSet.end());
                aLayer.push_back(bSet);
            }
            matrixSet.push_back(aLayer);
            aSet.clear();
            aLayer.clear();
        }
        for (int i = 0; i < xySet.size(); i++)
        {
            for (int j = 0; j < xySet[i].size(); j++)
            {
                if (i == 0)
                    for (int k = 0; k < 3; k++)
                        for (int l = 0; l < 3; l++)
                            matrixSet[k][l].insert(xySet[i][j]);
                if (i == 1)
                    for (int k = 0; k < 3; k++)
                        for (int l = 3; l < 6; l++)
                            matrixSet[k][l].insert(xySet[i][j]);
                if (i == 2)
                    for (int k = 0; k < 3; k++)
                        for (int l = 6; l < 9; l++)
                            matrixSet[k][l].insert(xySet[i][j]);
                if (i == 3)
                    for (int k = 3; k < 6; k++)
                        for (int l = 0; l < 3; l++)
                            matrixSet[k][l].insert(xySet[i][j]);
                if (i == 4)
                    for (int k = 3; k < 6; k++)
                        for (int l = 3; l < 6; l++)
                            matrixSet[k][l].insert(xySet[i][j]);
                if (i == 5)
                    for (int k = 3; k < 6; k++)
                        for (int l = 6; l < 9; l++)
                            matrixSet[k][l].insert(xySet[i][j]);
                if (i == 6)
                    for (int k = 6; k < 9; k++)
                        for (int l = 0; l < 3; l++)
                            matrixSet[k][l].insert(xySet[i][j]);
                if (i == 7)
                    for (int k = 6; k < 9; k++)
                        for (int l = 3; l < 6; l++)
                            matrixSet[k][l].insert(xySet[i][j]);
                if (i == 8)
                    for (int k = 6; k < 9; k++)
                        for (int l = 6; l < 9; l++)
                            matrixSet[k][l].insert(xySet[i][j]);
            }
        }

        board = sudokuRecurse(board, matrixSet, blanks);
    }
};

//TIME CAN BE SAVED BY NOT INSERTING WHEN NUMBER IS KNOWN FOR BOTH FUNCTIONS
int main()
{
    vector<vector<char>> problem
    {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    };

    vector<vector<char>> problem2
    {
        {'.','.','9','7','4','8','.','.','.'},
        {'7','.','.','.','.','.','.','.','.'},
        {'.','2','.','1','.','9','.','.','.'},
        {'.','.','7','.','.','.','2','4','.'},
        {'.','6','4','.','1','.','5','9','.'},
        {'.','9','8','.','.','.','3','.','.'},
        {'.','.','.','8','.','3','.','2','.'},
        {'.','.','.','.','.','.','.','.','6'},
        {'.','.','.','2','7','5','9','.','.'}
    };

    Solution sudokuSolver;
    sudokuSolver.solveSudoku(problem);
    for (auto x : problem)
    {
        cout << '{';
        for (auto y : x)
        {
            cout << y << ' ';
        }
        cout << '}' << endl;
    }
    cout << endl;
    sudokuSolver.solveSudoku(problem2);
    for (auto x : problem2)
    {
        cout << '{';
        for (auto y : x)
        {
            cout << y << ' ';
        }
        cout << '}' << endl;
    }
    return 0;
}