#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

constexpr int N = 1e6 + 10;
ll Cost[N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll res = 0;
    string number;
    cin >> number;

    bool edge_case = 0;
    if (number[0] == '1')
    {
        edge_case = 1;
        if (number.size() == 1)
        {
            cout << "0\n";
            return 0;
        }
        for (int i = 1; i < number.size(); i++)
            if (number[i] != '0')
            {
                edge_case = 0;
                break;
            }
    }
    if (edge_case)
    {
        cout << "1\n";
        return 0;
    }

    if (number.size() > 1)
    {
        res = 2;

        Cost[0] = 1;
        for (int i = 1; i < number.size(); i++)
        {
            Cost[i] = Cost[i - 1];
            if (number[i] != '0')
                Cost[i]++;
        }

        bool moved = 0;

        for (int i = number.size() - 1; i > 0; i--)
        {
            if (number[i] == '0')
            {
                if (!moved)
                {
                    res += Cost[i];
                    moved = 1;
                }
                continue;
            }

            if (number[i] == '9')
                continue;

            res += 9 - (number[i] - '0');
            if (i != number.size() - 1 && !moved)
            {
                res += Cost[i];
                moved = 1;
            }
        }

        bool onlyNine = 1;

        res += 9 - (number[0] - '0');
        if (!moved)
        {
            for (int i = 0; i < number.size(); i++)
                if (number[i] != '9')
                {
                    onlyNine = 0;
                    break;
                }

            if (!onlyNine)
                res++;
        }
    }
    else
    {
        res = 10 - (number[0] - '0');
        res++;
    }
    cout << res << '\n';
    return 0;
}