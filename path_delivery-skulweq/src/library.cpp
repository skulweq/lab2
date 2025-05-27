#include "graph.hpp"
#include <limits>

int INF = std::numeric_limits<int>::max();

namespace graph_library {
    void Graph::add_edge(const std::string& u, const std::string& v, int w) {
        adj[u].push_back(Edge{ v, w });
        adj[v].push_back(Edge{ u, w });
    }
    std::vector<std::string> Graph::find_shortest_path(const std::string& start, const std::string& end) {
        using Pair = std::pair<int, std::string>;
        std::priority_queue <Pair, std::vector<Pair>, std::greater<>> pq;
        std::unordered_map <std::string, int> dist;
        std::unordered_map <std::string, std::string> prev;
        std::vector <std::string> path;

        for (auto& node : adj) {
            dist[node.first] = INF;
        }
        dist[start] = 0;
        pq.push({ 0, start });
        while (!pq.empty()) {
            auto& current = pq.top();
            pq.pop();
            int d = current.first;
            std::string s = current.second;
            if (d > dist[s]) {
                continue;
            }
            for (const Edge& edge : adj[s]) {
                std::string v = edge.to;
                int weight = edge.weight;
                if (dist[v] > dist[s] + weight) {
                    dist[v] = dist[s] + weight;
                    prev[v] = s;
                    pq.push({ dist[v], v });
                }
            }
        }
        if (dist[end] == INF) {
            return path;
        }
        for (std::string at = end; at != start; at = prev[at]) {
            path.push_back(at);
        }
        path.push_back(start);
        std::reverse(path.begin(), path.end());
        return path;
    }
}