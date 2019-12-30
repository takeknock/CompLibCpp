#pragma once
#include <iostream>
#include <vector>
#include <algorithm>


typedef long long ll;
constexpr ll INF = 1e17;


using namespace std;

void solve() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (auto& e : a) {
        cin >> e;
    }
    vector<ll> dp(n, INF);
    for (int i = 0; i < n; i++)
    {
        *lower_bound(dp.begin(), dp.begin() + n, a[i]) = a[i];
    }

    if (dp[0] != 1) {
        cout << -1 << endl;
        return ;
    }

    //ll remain = dp.end() - lower_bound(dp.begin(), dp.begin() + n, INF);
    //ll lengthOfLongestIncresingSequence = upper_bound(dp.begin(), dp.begin() + n, INF) - dp.begin();
}