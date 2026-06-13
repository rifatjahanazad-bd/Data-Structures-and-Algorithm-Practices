#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector <int> items_weight, items_value;
vector<vector<int>> dp;

int countMaxValue(int item, int bagWeight)
{

    if (bagWeight < 0 || item < 0) return 0;

    if (dp[item][bagWeight] != -1) return dp[item][bagWeight];

    if (bagWeight >= items_weight[item])
    {
        int op1 = countMaxValue(item-1,bagWeight-items_weight[item]) + items_value[item];     //item ta rakhbo
        int op2 = countMaxValue(item-1,bagWeight); //item ta rakhbo na
        dp[item][bagWeight] = max (op1,op2);
        return dp[item][bagWeight];
    }
    else
    {
        dp[item][bagWeight] = countMaxValue(item-1,bagWeight);
        return dp[item][bagWeight]; // bag er weight kom item er weight beshi
    }
}
int main()
{
    int t;
    cin >> t;
    
    while (t--)
    {
        int items, bagWeight;
        cin >> items >> bagWeight;

        items_value.resize(items+1);
        items_weight.resize(items+1);
        dp.resize(items+1,vector<int>(10000,-1));
        
        for (int i = 0; i < items; i++)
            cin >> items_weight[i];
        for (int i = 0; i < items; i++)
            cin >> items_value[i];

        cout << countMaxValue(items-1,bagWeight) << endl;
    }
}