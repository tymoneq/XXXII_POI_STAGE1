#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

constexpr int N = 1e6 + 10;
ll CostFromFront[N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s;

    cin >> s;

    if (s.size() == 1 && s[0] == '1')
    {
        cout << "0\n";
        return 0;
    }
    ll res = 0;

    CostFromFront[0] = 9 - (s[0] - '0') + 1;

    for (int i = 1; i < s.size(); i++)
    {
        CostFromFront[i] = CostFromFront[i - 1];
        if (s[i] != '0')
            CostFromFront[i] += 1 + 9 - (s[i] - '0');
    }
    ll j = 1, cost = 0;
    int mxIndx = -1;
    if (s.size() > 10)
        for (int i = s.size() - 1; i >= 0; i--)
        {

            if (cost + (9 - (s[i] - '0')) * j < CostFromFront[i])
            {
                mxIndx = i;
                cost += (9 - (s[i] - '0')) * j;
                j *= 10;
            }
            else
                break;

            if (j > 10e9)
                break;
        }

    res = cost;
    bool moved = 0;
    if (mxIndx == -1)
    {
        bool XD = ((s.size() > 1 && s[0] == '1') ? 1 : 0);
        for (int i = 1; i < s.size(); i++)
            if (s[i] != '0')
            {
                XD = 0;
                break;
            }

        if (!XD)
        {
            mxIndx = s.size() - 1;
            res += (s[s.size() - 1] == '0' ? 0 : 9 - (s[s.size() - 1] - '0'));
        }
        if (s[s.size() - 1] == '0')
            moved = 1;
    }
    for (int i = mxIndx - 1; i >= 0; i--)
    {
        if (s[i] == '0')
        {
            moved = 1;
            continue;
        }
        if (!moved && s[i] == '9')
            continue;

        res += 1 + 9 - (s[i] - '0');
        moved = 1;
    }
    if (mxIndx != -1)
        res += 2;
    else
        res = 1;

    cout << res << "\n";

    return 0;
}