#include <iostream>
#include <vector>
#include <queue>
#include <numeric>

using namespace std;

int row, col;
char grid[1005][1005];
bool visited[1005][1005];
pair<int, int> parent[1005][1005];
vector<pair<int, int>> mv = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

bool valid(int r, int c)
{
    if (r < 0 || r >= row || c < 0 || c >= col)
        return false;
    return true;
}

void bfs(int src_row, int src_col)
{
    int nr, nc; // new row, new col
    queue<pair<int, int>> q;

    q.push({src_row, src_col});
    visited[src_row][src_col] = true;
    while (!q.empty())
    {
        pair<int, int> curr = q.front(); // front or current element of the queue
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            nr = curr.first + mv[i].first; // new row
            nc = curr.second + mv[i].second; // new col

            if (valid(nr, nc) && !visited[nr][nc] && grid[nr][nc] != '#')
            {
                visited[nr][nc] = true;
                parent[nr][nc] = {curr.first,curr.second};
                q.push({nr, nc});
            }
        }
    }
}

int main()
{
    int src_row, src_col, tar_row, tar_col;
    cin >> row >> col;
    memset(visited, false, sizeof(visited));
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> grid[i][j];
            if (grid[i][j] == 'R')
            {
                src_row = i;
                src_col = j;
            }
            if (grid[i][j] == 'D')
            {
                tar_row = i;
                tar_col = j;
            }
            //reset parent value
            parent[i][j] ={-1,-1};
        }
    }
    
    bfs(src_row, src_col);
    // cout << "NEW GRID IS " << endl;
    // target source er parent track korte korte backtrack
    int cur_row, cur_col;
    cur_row = tar_row;
    cur_col = tar_col;
    //jody current ta src na hoy taile current element update hya parent of current hya jabe
    while ((cur_row != src_row || cur_col != src_col) && parent[cur_row][cur_col].first != -1)
    {
        //oi path niye kaj
        if (cur_row != tar_row || cur_col != tar_col) grid[cur_row][cur_col] = 'X';
        // cout << "Cur col is : " << cur_row << cur_col << "-" << grid[cur_row][cur_col] << " >> ";
        //update current row and col
        int pr = parent[cur_row][cur_col].first;
        int pc = parent[cur_row][cur_col].second;
        cur_row = pr;
        cur_col = pc;
        // cout << "NEW ROW COL IS " << cur_row << cur_col << endl;
    }
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << grid[i][j];
        }
        cout << endl;
    }
    
}