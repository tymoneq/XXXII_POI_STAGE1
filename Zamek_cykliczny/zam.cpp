#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

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
    if (s[0] == '1')
    {
        bool XD = 1;
        for (int i = 1; i < s.size(); i++)
            if (s[i] != '0')
            {
                XD = 0;
                break;
            }
        if (XD)
        {
            cout << "1\n";
            return 0;
        }
    }
    if (s.size() == 1)
    {
        cout << 10 - (s[0] - '0') + 1 << "\n";
        return 0;
    }
    ll res = numeric_limits<ll>::max();

    int mnToCheck = min((int)s.size(), 9);

    for (int k = 0; k < mnToCheck; k++)
    {
        ll cost_of_update_last_k_elements = 0;
        ll j = 1;
        for (int i = 0; i < k; i++)
        {
            cost_of_update_last_k_elements += (9 - (s[s.size() - i - 1] - '0')) * j;
            j *= 10;
        }

        bool moved = 0;
        for (int i = s.size() - k - 1; i >= 0; i--)
        {
            if (s[i] == '0')
            {
                moved = 1;
                continue;
            }
            if (s[i] == '9' && moved)
            {
                cost_of_update_last_k_elements++;
                continue;
            }
            if (s[i] == '9' && !moved)
                continue;

            moved = 1;
            cost_of_update_last_k_elements += 1 + (9 - (s[i] - '0'));
        }

        res = min(res, cost_of_update_last_k_elements);
    }
    res += 2;
    cout << res << "\n";
    return 0;
}