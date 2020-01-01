#pragma once

#include <iostream>
#include <vector>
#include <stack>

typedef long long ll;
using namespace std;


void solve(){
    char goal = 'g';
    char start = 's';
    char wall = '#';

    ll h, w;
    cin >> h >> w;
    vector<vector<char>> field(h, vector<char>(w));

    ll sc, sr, gc, gr = -1;

    for (ll i = 0; i < h; i++)
    {
        for (ll j = 0; j < w; j++)
        {
            cin >> field[i][j];
            if (field[i][j] == start) {
                sc = j;
                sr = i;
            }
            if (field[i][j] == goal) {
                gc = j;
                gr = i;
            }
        }
    }

    vector<vector<ll>> seen(h, vector<ll>(w, 0));


    vector<ll> dx = { -1ll, 0ll, 1ll, 0ll };
    vector<ll> dy = { 0ll, -1ll, 0ll, 1ll };

    stack<std::pair<ll, ll>> history;

    history.push(std::make_pair(sr, sc));
    while (!history.empty()) {
        pair<ll, ll> current = history.top();
        history.pop();

        seen[current.first][current.second] = 1;

        for (int i = 0; i < 4; i++)
        {
            ll ny = current.first + dy[i];
            ll nx = current.second + dx[i];
            if (ny >= 0 && ny < h && nx >= 0 && nx < w) {
                if (!seen[ny][nx] && field[ny][nx] != wall) {
                    history.push(make_pair(ny, nx));
                }
            }
        }
    }

    if (seen[gr][gc]) {
        cout << "Yes" << "\n";
    }
    else {
        cout << "No" << "\n";
    }

    //for (const auto& row : field) {
    //    for (const auto& c : row) {
    //        cout << c;
    //    }
    //    cout << "\n";
    //}
}