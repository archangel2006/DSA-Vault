#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        
        vector<vector<pair<int,int>>> graph(V);
        
        for (auto arr : edges){
            int u = arr[0];
            int v = arr[1];
            int w = arr[2];
            
            graph[u].push_back({v,w});
            graph[v].push_back({u,w});
        }
        
        vector<int> distance(V, INT_MAX);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
       
        distance[src] = 0;
        pq.push({0, src});
        
        while(!pq.empty()){
            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            for (auto neighbor : graph[node]){
                
                int edge_weight = neighbor.second;
                int adj_node = neighbor.first;
                
                int new_distance = dis + edge_weight;
                
                if (new_distance < distance[adj_node]){
                    
                    distance[adj_node] = new_distance;
                    pq.push({new_distance, adj_node});
                    
                }
            }
        }
        
        return distance;
        
    }
};



class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        
        vector<vector<pair<int,int>>> graph(V);
        
        for (auto arr : edges){
            int u = arr[0];
            int v = arr[1];
            int w = arr[2];
            
            graph[u].push_back({v,w});
            graph[v].push_back({u,w});
        }
        
        vector<int> distance(V, INT_MAX);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
       
        distance[src] = 0;
        pq.push({0, src});
        
        while(!pq.empty()){
            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            // Skip if we already found a shorter path
            if (dis > distance[node]) continue;  // skip outdated pair
            
            for (auto neighbor : graph[node]){
                
                int edge_weight = neighbor.second;
                int adj_node = neighbor.first;
                
                int new_distance = dis + edge_weight;
                
                if (new_distance < distance[adj_node]){
                    
                    distance[adj_node] = new_distance;
                    pq.push({new_distance, adj_node});
                    
                }
            }
        }
        
        return distance;
        
    }
};