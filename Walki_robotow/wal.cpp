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
    set<int> A;
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
            A.insert(i);
    }
    if (A.size() % 2 == 1)
        for (int i = 0; i < n; i++)
        {
            if (A.find(i) != A.end())
                continue;

            for (int w : A)
                if (Roboty[i].szybkosc > Roboty[w].szybkosc || Roboty[i].zwinnosc > Roboty[w].zwinnosc)
                {
                    A.erase(w);
                    break;
                }
            if (A.size() % 2 ==0)
                break;
        }
    if (A.size() % 2 == 1)
        cout << "NIE\n";
    else
        cout << "TAK\n";
    return 0;
}