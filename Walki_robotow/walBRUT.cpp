#include <bits/stdc++.h>
using namespace std;

bool T = 0;
vector<pair<int, int>> Robot;
void calc(int fighter, set<int> A)
{
    if (A.size() == 1)
        return;
    A.erase(fighter);
    for (int w : A)
    {
        if (Robot[fighter].first > Robot[w].first && Robot[fighter].second > Robot[w].second)
        {
            if (A.size() == 1)
                return;
            set<int> B = A;
            B.erase(w);
            calc(fighter, B);
        }
        else if (Robot[fighter].first < Robot[w].first && Robot[fighter].second < Robot[w].second)
            calc(w, A);
        else
        {
            if (A.size() == 1)
                break;

            set<int> B = A;
            B.erase(w);
            calc(*(B.begin()), B);
        }
    }
    if (A.empty())
        T = 1;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    Robot.resize(n);
    for (int i = 0; i < n; i++)
        cin >> Robot[i].first >> Robot[i].second;

    set<int> numbers;

    for (int i = 0; i < n; i++)
        numbers.insert(i);

    for (int i = 0; i < n; i++)
        calc(i, numbers);

    cout << (T ? "TAK" : "NIE") << "\n";

    return 0;
}