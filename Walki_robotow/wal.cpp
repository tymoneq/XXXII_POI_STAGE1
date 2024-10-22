#include <bits/stdc++.h>

using namespace std;
constexpr int N = 1010;
bool Pokonany[N];

struct wal
{
    int szybkosc, zwinnosc;
};

inline bool sorto(wal &lhs, wal &rhs) { return (lhs.szybkosc + lhs.zwinnosc) < (rhs.szybkosc + rhs.zwinnosc); }

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

    sort(Roboty.begin(), Roboty.end(), sorto);

    for (int i = 0; i < n; i++)
    {
        if (Pokonany[i])
            continue;
        for (int j = 0; j < i; j++)
        {
            if (Pokonany[j])
                continue;
            if ((Roboty[j].szybkosc < Roboty[i].szybkosc) && (Roboty[j].zwinnosc < Roboty[i].zwinnosc))
                Pokonany[j] = 1;
            else if ((Roboty[j].szybkosc < Roboty[i].szybkosc && Roboty[j].zwinnosc > Roboty[i].zwinnosc) || (Roboty[j].szybkosc > Roboty[i].szybkosc && Roboty[j].zwinnosc < Roboty[i].zwinnosc))
            {
                Pokonany[j] = 1;
                Pokonany[i] = 1;
                break;
            }
        }
    }
    bool T = 1;
    for (int i = 0; i < n; i++)
        if (!Pokonany[i])
        {
            T = 0;
            break;
        }

    cout << (T ? "TAK" : "NIE") << "\n";
    return 0;
}