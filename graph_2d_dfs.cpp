#include <iostream>
#include <vector>
#include <queue>
#include <cstring> // Needed for memset

using namespace std;

int n, e;
bool visitedArray[100][100]; 

vector<pair<int, int>> mv = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

bool valid(int row, int col)
{
    if (row < 0 || row >= n || col < 0 || col >= e)
        return false;
    return true;
}

void dfs(int sr, int sc, vector<vector<int>> &adj_list)
{
    cout << adj_list[sr][sc] << " ";
    visitedArray[sr][sc] = true;
    
    for (int i = 0; i < 4; i++)
    {
        int nextr = sr + mv[i].first;
        int nextc = sc + mv[i].second;
        
        if (valid(nextr, nextc) && !visitedArray[nextr][nextc])
            dfs(nextr, nextc, adj_list);
    }
}

void bfs(int sr, int sc, vector<vector<int>> &adj_list)
{
    queue<pair<int, int>> q;
    q.push({sr, sc});
    visitedArray[sr][sc] = true;

    while (!q.empty())
    {
        int parent_row = q.front().first;
        int parent_col = q.front().second;
        q.pop();
        
        cout << adj_list[parent_row][parent_col] << " "; // Print to see BFS order

        for (int i = 0; i < 4; i++)
        {
            int nextr = parent_row + mv[i].first;
            int nextc = parent_col + mv[i].second;
            
            if (valid(nextr, nextc) && !visitedArray[nextr][nextc])
            {
                q.push({nextr, nextc});
                visitedArray[nextr][nextc] = true;
            }
        }
    }
}

int main()
{
    cout << "Enter row and column Count: ";
    cin >> n >> e;

    vector<vector<int>> adj_list(n, vector<int>(e));

    // Initialize visited array to false
    memset(visitedArray, false, sizeof(visitedArray));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < e; j++)
        {
            cout << "Enter data for [" << i << "][" << j << "]: ";
            cin >> adj_list[i][j];
        }
    }
    
    // Testing the traversals starting from top-left (0,0)
    cout << "\nDFS Traversal starting from (0,0): \n";
    dfs(0, 0, adj_list);
    
    // Reset visited array before running BFS
    memset(visitedArray, false, sizeof(visitedArray));
    
    cout << "\n\nBFS Traversal starting from (0,0): \n";
    bfs(0, 0, adj_list);
    
    return 0;
}