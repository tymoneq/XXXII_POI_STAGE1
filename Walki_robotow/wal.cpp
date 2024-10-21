#include <bits/stdc++.h>

using namespace std;

struct wal
{
    int szybkosc, zwinnosc, ile_pokona = 0;
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<wal> Roboty(n);
    for (int i = 0; i < n; i++)
        cin >> Roboty[i].szybkosc >> Roboty[i].zwinnosc;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                continue;

            if (Roboty[i].szybkosc > Roboty[j].szybkosc || Roboty[i].zwinnosc > Roboty[j].zwinnosc)
                ++Roboty[i].ile_pokona;
        }

    int cnt = 0;
    for (int i = 0; i < n; i++)
        if (Roboty[i].ile_pokona == n - 1)
            cnt++;

    if (cnt % 2 == 0)
        cout << "TAK\n";
    else
        cout << "NIE\n";
    return 0;
}