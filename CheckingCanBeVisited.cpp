#include <iostream>
#include <vector>
#include <queue>
using namespace std;
bool visited[1005];
int level[1001]; 
void bfs(int src, vector<vector<int>> &adj_list)
{
    queue<int> q;
    q.push(src);
    visited[src] = true;
    level[src] = 0;
    while (!q.empty())
    {
        int par = q.front();
        // cout << par << " ";
        q.pop();
        for (int i : adj_list[par])
        {
            if (!visited[i])
            {
                q.push(i);
                visited[i] = true;
                level[i] = level[par]+1;
            }
        }
    }
}

int main()
{
    int n, e;
    cout << "Enter Nodes and Edges Count: " << endl;`
    cin >> n >> e;
    vector<vector<int>> adj_list(n);
    bool visitedArray[adj_list.size()];
    memset(level, -1, sizeof(level));
    // adjacency list
    for (int i = 0; i < e; i++)
    {
        cout << "Enter Connections : " << endl;
        int nodeA, nodeB;
        cin >> nodeA >> nodeB;
        adj_list[nodeA].push_back(nodeB);
        adj_list[nodeB].push_back(nodeA);
    }
    cout << "Enter From which one to where to go : " << endl;
    int scrnode, targetnode;
    cin >> scrnode >> targetnode;
    bfs(scrnode, adj_list);
    cout << level[targetnode] << endl;
}