#include <iostream>
#include <algorithm>
#include <list>
using namespace std;

int main()
{
    list<string> ss;
    string s;
    cout << "Enter List String : ";
    while (cin >> s && s != "end")
    {
        ss.push_back(s);
    }
    int q;
    cin >> q;
    auto it = ss.begin();
    while (q--)
    {
        string cmd;
        cin >> cmd;

        if (cmd.find("visit") != string::npos)
        {
            string z; cin >> z;
            auto findString = find(ss.begin(), ss.end(), z);
            if (findString != ss.end())
            {
                it = findString;
                cout << *it << endl;
            }
            else
            {
                cout << "Not Available"<< endl;
            }
        }
        else if (cmd == "prev")
        {
            if (it == ss.begin())
            {
                cout << "Not Available" << endl;
            }
            else
            {
                it = prev(it);
                cout << *it << endl;
            }
        }
        else if (cmd == "next")
        {
            auto last = prev(ss.end());
            if (it == last)
            {
                cout << "Not Available" << endl;
            }
            else{
                it++;
                cout << *it << endl;
            } 
            
        }
    }
}