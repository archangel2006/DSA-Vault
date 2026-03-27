#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        vector<vector<pair<int,int>>> graph(n);

        for (auto& f : flights){
            int u = f[0];
            int v = f[1];
            int w = f[2];

            graph[u].push_back({v,w});
        }

        // dist[node][edges] = min cost to reach node using 'edges' edges
        vector<vector<int>> distance(n, vector<int>(k+2, INT_MAX));

        // {cost, node, stops}
        priority_queue<vector<int>, vector<vector<int>>, greater <vector<int>>>pq;

        pq.push({0,src,0});
        distance[src][0] = 0; 

        while (!pq.empty()){

            auto curr = pq.top();
            pq.pop();

            int cost = curr[0];
            int node = curr[1];
            int stops = curr[2];

            // if destination reached
            if (node == dst) return cost;

            // if already made k stops, skip this path
            if (stops > k) continue;

            for (auto &neighbor : graph[node]){

                int next = neighbor.first;
                int price = neighbor.second;

                int new_cost = cost + price;

                // Relax if better for this edge count
                if (new_cost < distance[next][stops]){

                    distance[next][stops + 1] = new_cost;

                    pq.push({new_cost, next, stops+1});
                }
            }
        }

        return -1;
    }
};