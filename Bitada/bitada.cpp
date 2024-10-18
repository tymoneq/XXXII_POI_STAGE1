#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#warning change MAXN = 3010
constexpr int MAXN = 10;

vector<int> Bitada[MAXN], Bajtocja[MAXN];
ll dp[MAXN][3];
bool isOff[MAXN];
int Sajz[MAXN], Parent[MAXN];
int k, N, M;
ll res = 0;

inline void combinationsCalclation(int &vBitada, int &vBajtocja)
{
    vector<int> PossibleVertexes;
    for (int w : Bajtocja[vBajtocja])
        if (!isOff[w])
            PossibleVertexes.push_back(w);

    if (Bitada[vBitada].size() == 1)
        for (int w : PossibleVertexes)
            res += dp[w][0] % k;

    else if (Bitada[vBitada].size() == 2)
        for (int w : PossibleVertexes)
            for (int v : PossibleVertexes)
            {
                if (w == v)
                    continue;
                res += (dp[w][0] * dp[v][1]) % k;
            }

    else if (Bitada[vBitada].size() == 3)
        for (int w : PossibleVertexes)
            for (int v : PossibleVertexes)
                for (int d : PossibleVertexes)
                {
                    if (w == v || d == v || w == d)
                        continue;
                    res += (((dp[w][0] * dp[v][1]) % k) * dp[d][2]) % k;
                }

    res %= k;
}

inline void
calc(int vBajtocja, int vBitada, int state, int parentBajtocja, int parentBitada)
{
    dp[vBajtocja][state] = 0;
    // liczenie kombinacji na liściach
    if (Bitada[vBitada].size() == 1)
    {
        dp[vBajtocja][state] += 1;
        return;
    }

    vector<int> PossibleVertexes;
    for (int w : Bajtocja[vBajtocja])
        if (w != parentBajtocja && !isOff[w])
            PossibleVertexes.push_back(w);

    if (PossibleVertexes.size() + 1 < Bitada[vBitada].size())
        return;

    // dfs

    for (int w : PossibleVertexes)
    {
        int STATE = 0;
        for (int j = 0; j < Bitada[vBitada].size(); j++)
            if (Bitada[vBitada][j] != parentBitada)
            {
                calc(w, Bitada[vBitada][j], STATE, vBajtocja, vBitada);
                STATE++;
            }
    }

    // calculating Score

    if (Bitada[vBitada].size() == 2)
        for (int w : PossibleVertexes)
            dp[vBajtocja][state] += dp[w][0] % k;

    else if (Bitada[vBitada].size() == 3)
        for (int w : PossibleVertexes)
            for (int v : PossibleVertexes)
            {
                if (w == v)
                    continue;
                dp[vBajtocja][state] += (dp[w][0] * dp[v][1]) % k;
            }

    dp[vBajtocja][state] %= k;
}
inline void dfs(int v, int p)
{
    Sajz[v] = 1;
    Parent[v] = p;
    for (int w : Bajtocja[v])
        if (w != isOff[w] && w != p)
        {
            dfs(w, v);
            Sajz[v] += Sajz[w];
        }
}
inline int find_Centroid(int v, int tree_sajz)
{
    for (int w : Bajtocja[v])
    {
        if (isOff[w])
            continue;
        if (w == Parent[v] && tree_sajz - Sajz[v] > ((tree_sajz + 1 / 2)))
            return find_Centroid(Parent[v], tree_sajz);
        else if (w != Parent[v] && Sajz[w] > ((tree_sajz + 1) / 2))
            return find_Centroid(w, tree_sajz);
    }
    return v;
}

inline void centroid_decomposition(int v, int tree_sajz)
{
    if (tree_sajz == 1 && N == 1)
    {
        res++;
        return;
    }
    else if (tree_sajz == 1)
        return;
    dfs(v, 0);
    int centr = find_Centroid(v, tree_sajz);

    for (int n = 1; n <= N; n++)
    {
        if (Bajtocja[centr].size() < Bitada[n].size())
            continue;
        for (int i = 0; i < Bajtocja[centr].size(); i++)
            for (int j = 0; j < Bitada[n].size(); j++)
                calc(Bajtocja[centr][i], Bitada[n][j], j, centr, n);

        combinationsCalclation(n, centr);
    }

    isOff[v] = 1;
    for (int w : Bajtocja[centr])
        if (!isOff[w])
        {
            int new_size = (Sajz[w] < Sajz[centr] ? Sajz[w] : tree_sajz - Sajz[centr]);
            centroid_decomposition(w, new_size);
        }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int a, b;

    cin >> N >> M >> k;

    for (int i = 1; i < N; i++)
    {
        cin >> a >> b;
        Bitada[a].push_back(b);
        Bitada[b].push_back(a);
    }

    for (int i = 1; i < M; i++)
    {
        cin >> a >> b;
        Bajtocja[a].push_back(b);
        Bajtocja[b].push_back(a);
    }

    centroid_decomposition(1, M);

    res %= k;
    cout << res << "\n";
    return 0;
}