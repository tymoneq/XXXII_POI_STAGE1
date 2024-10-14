#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

constexpr int N = 1e6 + 10;
ll Cost_from_begining[N];
ll Cost_change_to_9_from_end[N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll res = 0;
    string number;
    cin >> number;

    bool edge_case = 0;
    for (int i = 0; i < N; i++)
        Cost_change_to_9_from_end[i] = -10;
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
        Cost_from_begining[0] = 1;
        for (int i = 1; i < number.size(); i++)
        {
            Cost_from_begining[i] = Cost_from_begining[i - 1];
            if (number[i] != '0')
                Cost_from_begining[i]++;
        }

        Cost_change_to_9_from_end[number.size() - 1] = 9 - (number[number.size() - 1] - '0');
        int j = 10;
        for (int i = number.size() - 2; i >= 0; i--)
        {
            Cost_change_to_9_from_end[i] = Cost_change_to_9_from_end[i + 1];
            Cost_change_to_9_from_end[i] += (9 - (number[i] - '0')) * j;
            j *= 10;
            if (Cost_change_to_9_from_end[i] > 1e10)
                break;
        }
        bool moved = 0;

        int cnt = 0;

        for (int i = number.size() - 1; i > 0; i--)
        {
            if (number[i] == '9')
                continue;
            if (number[i] == '0')
            {
                number[i] = '9';
                cnt++;
                continue;
            }

            if (!moved && Cost_change_to_9_from_end[i] >= 0 && Cost_change_to_9_from_end[i] < (Cost_from_begining[i] + 9 - (number[i] - '0')))
                res += Cost_change_to_9_from_end[i], cnt = 0;
            else
            {
                if (!moved)
                {
                    moved = 1;
                    res += Cost_from_begining[i];
                    if (number[i] != '0')
                        res += 9 - (number[i] - '0');
                }
                else if (number[i] != '0' && moved)
                    res += 9 - (number[i] - '0');
            }

            number[i] = '9';
        }

        bool onlyNine = 1;

        res += 9 - (number[0] - '0');
        if (!moved)
        {
            for (int i = 0; i < number.size(); i++)
                if (number[i] != '9' || cnt != 0)
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