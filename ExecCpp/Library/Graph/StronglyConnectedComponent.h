#pragma once

#include <vector>
#include <iostream>
using namespace std;

bool used[10100];
vector<vector<long long>> graph(10100), rgraph(10100);
vector<int> firstRes;
vector<int> comId(10100);


void dfs(int from) {
    used[from] = true;
    for (const auto& to : graph[from]) {
        if (!used[to]) {
            dfs(to);
        }
    }

    cout << "terminated node in dfs: " << from << endl;
    firstRes.emplace_back(from);
};

void rdfs(int from, int componentId) {
    used[from] = true;
    comId[from] = componentId;
    //cout << "node in rdfs: " << from << endl;
    for (const auto& to : rgraph[from]) {
        if (!used[to]) {
            rdfs(to, componentId);
        }
    }
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int v, e;
    cin >> v >> e;

    memset(used, false, sizeof(used));

    for (int i = 0; i < e; i++)
    {
        int s, t;
        cin >> s >> t;
        graph[s].emplace_back(t);
        rgraph[t].emplace_back(s);
    }

    // Q. graphの全探索はどこからスタートする？(rootはわかるのであれば、rootからが良さそうだが。。)
    // A. とりあえずノード0番から見ていく模様
    for (int i = 0; i < v; i++)
    {
        if (!used[i]) {
            dfs(i);
        }
    }

    std::reverse(firstRes.begin(), firstRes.end());

    memset(used, false, sizeof(used));

    int k = 0;
    for (const auto& e : firstRes) {
        if (!used[e]) {
            rdfs(e, k);
        }
        k++;
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        int u, v;
        cin >> u >> v;
        if (comId[u] == comId[v]) {
            cout << 1 << endl;
        }
        else {
            cout << 0 << endl;
        }
    }
    return 0;
}
