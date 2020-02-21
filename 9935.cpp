#include <iostream>
#include <vector>

using namespace std;
vector<char> stk;
vector<char> check;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int cnt = 1;
    string str;
    cin >> str;

    string word;
    cin >> word;
    int corr = 0;
    for (int i = 0; i < str.length(); i++)
    {
        stk.push_back(str[i]);
    }
    while (!stk.empty())
    {
        corr = 0;
        check.push_back(stk.back());
        /*
        cout << "-----------" << endl;
        cout << *(check.end() - 1) << ":";
        cout << stk.back();
        cout << endl;
        */
        if (check.back() == word[0])
        {
            if (check.size() >= word.size())
            {
                vector<char>::iterator iter = check.end() - 1;
                for (int i = 0; i < word.size(); i++)
                {
                    if (*iter != word[i])
                    {
                        corr = 0;
                        break;
                    }
                    else
                    {
                        iter--;
                    }
                    corr = 1;
                }
                if (corr == 1)
                {
                    for (int i = 0; i < word.size(); i++)
                        check.pop_back();
                }
            }
        }
        stk.pop_back();
    }
    if (check.empty())
    {
        cout << "FRULA";
    }
    else
    {
        while (!check.empty())
        {
            cout << check.back();
            check.pop_back();
        }
    }
}