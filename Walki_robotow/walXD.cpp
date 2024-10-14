#include <bits/stdc++.h>

using namespace std;

struct robot
{
    int s, z, i;
};

inline bool sortoFirst(robot &lhs, robot &rhs) { return lhs.s > rhs.s; }
inline bool sortoSecond(robot &lhs, robot &rhs) { return lhs.z > rhs.z; }
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<robot> Robot(n);

    for (int i = 0; i < n; i++)
    {
        cin >> Robot[i].s >> Robot[i].z;

        Robot[i].i = i;
    }

    int strongest = 0;
    sort(Robot.begin(), Robot.end(), sortoFirst);

    strongest = Robot[0].i;
    sort(Robot.begin(), Robot.end(), sortoSecond);

    if (strongest == Robot[0].i)
        cout << "NIE\n";
    else
        cout << "TAK\n";

    return 0;
}