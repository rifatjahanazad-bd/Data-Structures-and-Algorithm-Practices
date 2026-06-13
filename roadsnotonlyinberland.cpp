#include <iostream>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

vector<int> parent;
vector<int> group_size;
int find_lead(int node)
{
    if (parent[node] == -1)
        return node;
    int leader = find_lead(parent[node]);
    parent[node] = leader;
    return leader;
}

void dsu_union(int node1, int node2)
{
    if (group_size[node1] >= group_size[node2])
    {
        parent[node2] = node1;
        group_size[node1] += group_size[node2];
    }
    else
    {
        parent[node1] = node2;
        group_size[node2] += group_size[node1];
    }
}

int main()
{
    int n;
    cin >> n;
    vector<pair<int, int>> roadBreak;
    vector<pair<int, int>> roadConnect;

    parent.resize(n + 1, -1);
    group_size.resize(n + 1, 1);

    for (int i = 1; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        int leader1 = find_lead(a);
        int leader2 = find_lead(b);

        if (leader1 == leader2) // eita vanga lagbe extra road
        {
            roadBreak.push_back({a, b});
        }
        else // rasta nai jora deya lagbe
        {
            dsu_union(leader1, leader2);
        }
    }
    for (int i = 2; i <= n; i++)
    {
        int leader1 = find_lead(1);
        int leader2 = find_lead(i);

        if (leader1 != leader2)
        {
            roadConnect.push_back({leader1, leader2});
            dsu_union(leader1, leader2);
        }
    }
    cout << roadBreak.size() << endl;
    for (int i = 0; i < roadBreak.size(); i++)
    {
        cout << roadBreak[i].first << " " << roadBreak[i].second << " " << roadConnect[i].first << " " << roadConnect[i].second << endl;
    }
}