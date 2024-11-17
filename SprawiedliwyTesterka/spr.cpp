#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <cmath>
#define ll long long
using namespace std;

vector<int> solve(ll n, const vector<ll>& a, const vector<ll>& b) {
    vector<tuple<ll, ll, ll>> items;
    for (ll i = 0; i < n; i++) {
        items.emplace_back(a[i], b[i], i);
    }
    
    sort(items.begin(), items.end(), [](const auto& x, const auto& y) {
        return llabs(get<0>(x) - get<1>(x)) > llabs(get<0>(y) - get<1>(y));
    });

    ll sum_a = 0, sum_b = 0;
    vector<int> result(n, 0);
    int count_a = 0, count_b = 0;

    for (const auto& item : items) {
        ll a_val = get<0>(item);
        ll b_val = get<1>(item);
        ll i = get<2>(item);

        if (a_val == b_val) {
            if (count_a < n / 2) {
                sum_a += a_val;
                result[i] = 1;
                count_a++;
            } else {
                sum_b += b_val;
                result[i] = 0;
                count_b++;
            }
        } else {
            if ((sum_a + a_val <= sum_b + b_val && count_a < n / 2) || count_b >= n / 2) {
                sum_a += a_val;
                result[i] = 1;
                count_a++;
            } else {
                sum_b += b_val;
                result[i] = 0;
                count_b++;
            }
        }
    }

    return result;
}

int main() {
    ll n;
    cin >> n;
    vector<ll> a(n), b(n);

    for (ll i = 0; i < n; ++i) cin >> a[i];
    for (ll i = 0; i < n; ++i) cin >> b[i];

    vector<int> result = solve(n, a, b);

    if (!result.empty()) {
        for (int r : result) cout << r << " ";
        cout << endl;
    }

    return 0;
}