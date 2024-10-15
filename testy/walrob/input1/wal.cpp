#include <bits/stdc++.h>

using namespace std;
constexpr int N = 1010;
struct robot
{
    int s, z;
    vector<int> Pokona, Pokonany;
};

int D[N][N];
bool Vis[N][N];

inline bool sortoFirst(robot &lhs, robot &rhs) { return lhs.s > rhs.s; }

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    if (n == 0)
    {
        cout << "TAK\n";
        return 0;
    }

    vector<robot> Robot(n);

    for (int i = 0; i < n; i++)
    {
        cin >> Robot[i].s >> Robot[i].z;
    }

    sort(Robot.begin(), Robot.end(), sortoFirst);
    if (Robot[0].s == Robot[0].z)
    {
        cout << "NIE\n";
        return 0;
    }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                continue;
            if (Robot[i].s > Robot[j].s || Robot[i].z > Robot[j].z)
                Robot[i].Pokona.push_back(j);
            if (Robot[i].s < Robot[j].s || Robot[i].z < Robot[j].z)
                Robot[i].Pokonany.push_back(j);
        }

    if (n % 2 == 1)
    {
        set<int> ILE_POKONA;
        for (robot w : Robot)
            ILE_POKONA.insert(w.Pokona.size());

        if (ILE_POKONA.size() == 1)
        {
            cout << "NIE\n";
            return 0;
        }
    }

    for (int i = 0; i < n; i++)
    {
        queue<int> q;
        q.push(i);
        Vis[i][i] = 1;

        while (!q.empty())
        {
            int v = q.front();
            q.pop();
            for (int w : Robot[v].Pokona)
                if (!Vis[i][w])
                {
                    Vis[i][w] = 1;
                    D[i][w] = 1;
                }
        }
    }

    bool T = 1;

    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            for (int k = j + 1; k < n; k++)
                if (D[i][j] == 1 && D[i][k] == 1 && D[j][i] == 1 && D[j][k] == 1 && D[k][i] == 1 && D[k][j] == 1 && Robot[i].Pokonany.size() == 2 && Robot[j].Pokonany.size() == 2 && Robot[k].Pokonany.size() == 2)
                {
                    T = 0;
                    break;
                }

    cout << (T ? "TAK" : "NIE") << "\n";
    return 0;
}