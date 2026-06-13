#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void bfs(int sourceNode, vector<vector<int>> &adj_list, bool visitedArray[])
{
    queue<int> q;
    memset(visitedArray, false, sizeof(visitedArray));
    q.push(sourceNode);
    visitedArray[sourceNode] = true;
    vector<int> bfs_order;
    while (!q.empty())
    {
        int par = q.front();
        q.pop();
        bfs_order.push_back(par);
        visitedArray[par] = true;
        for (int i : adj_list[par])
        {
            if (visitedArray[i] == false)
            {
                q.push(i);
                visitedArray[i] = true;
            }
        }
    }
    // print traversal
    for (int n : bfs_order)
        cout << n << " ";
    cout << endl;
}

int main()
{
    int n, e;
    cin >> n >> e;
    // vector<vector<int>> adj_mat (n,vector<int>(n,0));
    vector<vector<int>> adj_list(n);
    bool visitedArray[adj_list.size()];
    // // matrix
    // for (int i = 0; i < e; i++)
    // {
    //     int nodeA, nodeB;
    //     cin >> nodeA >> nodeB;
    //     adj_mat[nodeA][nodeB] = 1;
    //     adj_mat[nodeB][nodeA] = 1;
    // }
    // diagonal
    // for (int i = 0; i < adj_mat.size(); i++)
    // {
    //     for (int j = 0; j < adj_mat[i].size(); j++)
    //     {
    //         if (i==j)
    //             adj_mat[i][j] = 1;
    //     }

    // }
    // adjacency list
    for (int i = 0; i < e; i++)
    {
        int nodeA, nodeB;
        cin >> nodeA >> nodeB;
        adj_list[nodeA].push_back(nodeB);
        adj_list[nodeB].push_back(nodeA);
    }
    // traverse bfs
    bfs(0, adj_list,visitedArray);

    // print
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j : adj_list[i])
    //     {
    //         cout << j << " ";
    //     }
    //     cout << endl;
    // }
}