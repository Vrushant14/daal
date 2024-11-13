#include <bits/stdc++.h>
using namespace std;

vector<vector<vector<int>>> allBoards;

bool isSafe(vector<vector<int>> &board, int row, int col)
{
    int n = board.size();
    int i, j;
    // horizontal
    for (i = 0; i < col; i++)
        if (board[row][i])
            return false;
    // vertical
    for (i = 0; i < row; i++)
    {
        if (board[i][col])
            return false;
    }

    // upper left
    for (i = row, j = col; i >= 0 &&
                           j >= 0;
         i--, j--)
        if (board[i][j])
            return false;
    // lower left
    for (i = row, j = col; j >= 0 &&
                           i < n;
         i++, j--)
        if (board[i][j])
            return false;

    // upper right
    for (i = row, j = col; i >= 0 && j < n; i--, j++)
    {
        if (board[i][j])
        {
            return false;
        }
    }

    // lower right
    for (i = row, j = col; i < n && j < n; i++, j++)
    {
        if (board[i][j])
        {
            return false;
        }
    }
    return true;
}

void saveboard(vector<vector<int>> b)
{
    allBoards.push_back(b);
}

void nqueens(vector<vector<int>> &board, int col)
{
    int n = board.size();
    if (col >= n)
    {
        saveboard(board);
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (isSafe(board, i, col))
        {
            board[i][col] = 1;
            nqueens(board, col + 1);
            board[i][col] = 0;
        }
    }
}
int main()
{
    int n;
    cout << "Enter number of queens:";
    cin >> n;
    vector<vector<int>> board(n, vector<int>(n, 0));
    nqueens(board, 0);
    if (allBoards.size() == 0)
    {
        cout << "No solution exists" << endl;
        return 0;
    }
    for (int k = 0; k < allBoards.size(); k++)
    {
        cout<<"Board no "<<k+1<<endl;
        for (int i = 0; i < n; i++)
        {
            for(int j=0;j<n;j++){
                cout << allBoards[k][i][j] << " ";
            }
            cout << endl;
        }
        cout<<endl;
    }

    return 0;
}