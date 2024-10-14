#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll res = 0;
    string number;
    cin >> number;

    if (number[0] == '1' && number.size() == 1)
    {
        cout << "0\n";
        return 0;
    }

    if (number[number.size() - 1] != '0' && number[number.size() - 1] != '9')
    {
        res += 9 - (number[number.size() - 1] - '0');
        number[number.size() - 1] = '9';
    }

    bool T = 1;
    while (T)
    {
        bool sequnce = 1;
        if (number[0] == '0')
        {
            number.erase(number.begin());
            continue;
        }
        else if (number.size() == 1)
        {
            res += 10 - (number[0] - '0') + 1;
            T = 0;
            break;
        }

        else if (number[0] == '1')
        {
            for (int i = 1; i < number.size(); i++)
                if (number[i] != '0')
                {
                    sequnce = 0;
                    break;
                }

            if (sequnce)
            {
                ++res;
                cout << res << "\n";
                return 0;
            }
        }
        else if (number[0] == '9')
        {
            for (int i = 1; i < number.size(); i++)
                if (number[i] != '9')
                {
                    sequnce = 0;
                    break;
                }

            if (sequnce)
            {
                res += 2;
                cout << res << "\n";
                return 0;
            }
        }

        res += 9 - (number[0] - '0');
        number.erase(number.begin());
        number.append("9");
        res += 1;
    }

    cout << res << "\n";

    return 0;
}