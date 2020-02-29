#pragma once
#include<vector>;
#include <queue>;
using namespace std;

vector<ll> dijkstra(const vector<vector<pair<ll, ll>>>& graph, int start) {
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    vector<ll> dist(graph.size(), INF);
    dist[start] = 0l;
    pq.push(pair<ll, ll>(dist[start], start));
    while (!pq.empty()) {
        auto p = pq.top();
        pq.pop();
        int d = p.first;
        int from = p.second;
        if (dist[from] < d) continue;
        for (auto next : graph[from]) {
            int to = next.first;
            int cost = next.second;
            if (dist[from] + cost < dist[to]) {
                dist[to] = dist[from] + cost;
                pq.push(pair<ll, ll>(dist[to], to));
            }
        }
    }
    return dist;
}