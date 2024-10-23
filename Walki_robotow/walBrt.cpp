#include <bits/stdc++.h>

using namespace std;

struct wal
{
    int szybkosc, zwinnosc;
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<wal> Roboty(n);
    vector<int> A, B;
    for (int i = 0; i < n; i++)
        cin >> Roboty[i].szybkosc >> Roboty[i].zwinnosc;

    for (int i = 0; i < n; i++)
    {
        int tmp = 0;
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                continue;

            if (Roboty[i].zwinnosc > Roboty[j].zwinnosc || Roboty[i].szybkosc > Roboty[j].szybkosc)
                ++tmp;
        }
        if (tmp == n - 1)
            A.push_back(i);
        else
            B.push_back(i);
    }
    bool T = 0;
    if (A.size() % 2 == 1)
        for (int b : B)
        {
            for (int w : A)
                if (Roboty[b].szybkosc > Roboty[w].szybkosc || Roboty[b].zwinnosc > Roboty[w].zwinnosc)
                {
                    T = 1;
                    break;
                }
            if (T)
                break;
        }
    if (A.size() % 2 == 1 && !T)
        cout << "NIE\n";
    else
        cout << "TAK\n";
    return 0;
}