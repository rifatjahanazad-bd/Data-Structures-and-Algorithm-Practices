// #include <iostream>
// #include<vector>
// #include <queue>
// #include <string.h>
// using namespace std;
// vector <pair<int,int>> adjlist[100];
// int dist[100];

// void djkstras(int src)
// {
//     // queue <pair<int,int>> pq;
//     priority_queue <pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
//     dist[src] = 0;
//     pq.push({dist[src],src});
//     while (!pq.empty())
//     {
//         //take another parent pare and keep front
//         pair <int,int> par = pq.top();
//         int node = par.second;
//         int dis = par.first;
//         pq.pop();
//         // if (dis > dist[node]) continue;
//         for (auto child : adjlist[node])
//         {
//             int childnode = child.second;
//             int childdis = child.first;
//             if (dis+childdis < dist[childnode])
//             {
//                 dist[childnode] = dis+childdis;
//                 pq.push({dist[childnode],childnode});
//             }
//         }
//     }
// }

// int main ()
// {
//     int node , edge;
//     cout << "Enter node and edge count: ";
//     cin >> node >> edge;

//     while (edge--)
//     {
//         int a, b, w;
//         cin >> a >> b >> w;
//         adjlist[a].push_back({w,b});
//         // adjlist[b].push_back({w,a});
//     }
//     // memset(dist,INT_MAX,sizeof(dist));
//     for (int i = 0; i < 100; i++) dist[i] = INT_MAX;
//     djkstras(0);
//     for (int i = 0; i < node; i++)
//     {
//         cout << "0 -> " << i << " = " << dist[i] << endl;
//     }

// }

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define ll long long int

vector<vector<pair<ll, ll>>> edges_list;
vector<ll> parentof;
vector<ll> cost;
void dijkstra(int src)
{
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> q;
    q.push({cost[src], src});

    while (!q.empty())
    {
        pair<ll, ll> parent = q.top();

        // int par = parent.second;    // 10
        // int parent.first = parent.first; // 2
        q.pop();

        if (parent.first > cost[parent.second])
            continue;

        for (auto child : edges_list[parent.second])
        {
            // int child_nodeB = child.first;
            // int costOfB = child.second;

            if (parent.first + child.second < cost[child.first])
            {
                cost[child.first] = parent.first + child.second;
                q.push({cost[child.first], child.first});
                parentof[child.first] = parent.second;
            }
        }
    }
}

void printpath(int src)
{
    vector<ll> path;
    int cur = src;
    while (cur != -1)
    {
        path.push_back(cur);
        cur = parentof[cur];
    }
    reverse(path.begin(), path.end());
    for (int x : path)
        cout << x << " ";
}

int main()
{
    int n, e;
    cin >> n >> e;

    // 1 to n
    edges_list.resize(n + 1);
    while (e--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        edges_list[a].push_back({b, c});
        edges_list[b].push_back({a, c});
    }

    cost.resize(n + 1, LLONG_MAX);
    parentof.resize(n + 1, -1);

    cost[1] = 0; // cost of src to src
    dijkstra(1);

    if (parentof[n] != -1)
    {
        vector<ll> path;
        ll cur = n;
        while (cur != -1)
        {
            path.push_back(cur);
            cur = parentof[cur];
        }
        reverse(path.begin(), path.end());
        for (auto x : path)
            cout << x << " ";
    }
    else
        cout << -1 << endl;
}