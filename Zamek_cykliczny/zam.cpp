#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

constexpr int N = 1e6 + 10;
ll CostFromFront[N], CostFromEnd[N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s;

    // ifstream file("zam3.in");
    // file >> s;

    cin >> s;

    ll res = 0;
    // edge cases
    if (s[0] == '1')
    {
        if (s.size() == 1)
        {
            cout << "0\n";
            return 0;
        }
        bool edgeCase = 1;
        for (int i = 1; i < s.size(); i++)
            if (s[i] != '0')
            {
                edgeCase = 0;
                break;
            }

        if (edgeCase)
        {

            cout << "1\n";
            return 0;
        }
    }
    else if (s.size() == 1)
    {
        res = 10 - (s[0] - '0');
        res += 1;

        cout << res << "\n";
        return 0;
    }

    CostFromFront[0] = 9 - (s[s.size() - 1] - '0') + 1 + (9 - (s[0] - '0'));

    for (int i = 1; i < s.size(); i++)
    {
        CostFromFront[i] = CostFromFront[i - 1];
        if (i == s.size() - 1)
            break;
        if (s[i] != '0')
            CostFromFront[i] += 9 - (s[i] - '0') + 1;
    }

    for (int i = 0; i < s.size(); i++)
        CostFromEnd[i] = -1;

    ll j = 1;
    for (int i = s.size() - 1; i >= 0; i--)
    {
        CostFromEnd[i] = CostFromEnd[i + 1] + ((ll)(9 - (s[i] - '0')) * j);
        j *= 10;
        if (j > 1e8)
            break;
    }
    int indx = -1, INDX = -1, mxIndex = -1;
    for (int i = 0; i < s.size() - 1; i++)
    {
        if (CostFromEnd[i] == 0)
        {
            INDX = i;
            INDX--;
            break;
        }
        if (CostFromEnd[i] <= (CostFromFront[i] - (mxIndex != -1 ? CostFromFront[mxIndex] : 0)) && CostFromEnd[i] > 0)
        {
            indx = i;
            break;
        }
        if (s[i] != '0' && s[i] != '9')
            mxIndex = max(mxIndex, i);
    }

    if (INDX != -1 && mxIndex != -1)
        res = CostFromFront[mxIndex];

    else if (indx == -1 && mxIndex != -1)
    {
        int x = s.size() - 2;
        res = CostFromFront[min(x, mxIndex)];
        if (s[s.size() - 1] == '0')
            res -= 9;
    }
    else if (indx == -1 && INDX == -1 && mxIndex == -1)
    {

        bool onlyNines = 1;
        for (int i = 0; i < s.size(); i++)
            if (s[i] != '9')
            {
                onlyNines = 0;
                break;
            }

        if (onlyNines)
        {
            cout << "2\n";
            return 0;
        }
        vector<int> ZeroCount(s.size());
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '0')
                ZeroCount[i]++;
            if (i > 0)
                ZeroCount[i] += ZeroCount[i - 1];
        }

        for (int i = 0; i < s.size(); i++)
            if (s[i] == '9')
                mxIndex = i;

        res = mxIndex - ZeroCount[mxIndex] + 1;
    }
    else
    {
        if (mxIndex != -1)
            res = CostFromEnd[indx] + CostFromFront[mxIndex] - (9 - (s[s.size() - 1] - '0'));
        else
            res = CostFromEnd[indx];
    }

    res += 2;
    cout << res << "\n";
    return 0;
}
