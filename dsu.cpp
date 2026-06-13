#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int n, e;

int par[100001];
int groupsize[100001];
int Countcyle;

int find(int a)
{
    if (par[a] == -1)
        return a;
    int leader = find(par[a]);
    par[a] = leader;
    return leader;
}

void dsu_union(int a, int b)
{
    int node1 = a;
    int node2 = b;

    if (groupsize[node1] >= groupsize [node2])
    {
        par[node2] = node1;
        groupsize[node1] = groupsize[node1] + groupsize[node2];
    }
    else
    {
        par[node1] = node2;
        groupsize[node2] = groupsize[node1] + groupsize[node2];
    }
    
}

int main()
{
    cin >> n >> e;

    for (int i = 0; i <= n; i++) par[i] = -1;
    for (int i = 0; i <= n; i++) groupsize[i] = 1;
    Countcyle = 0;

    set <pair<int,int>> s;

    while (e--)
    {
        int a, b;
        cin >> a >> b;
        s.insert({a,b});
    }

    for (auto x : s)
    {
        int a = x.first;
        int b = x.second;
        
        int leader1 = find(a);
        int leader2 = find(b);

        if (leader1 == leader2)
        {
            Countcyle++;
        }
        else
        dsu_union (leader1,leader2);
    }
    cout << Countcyle << endl;
}