#pragma once

#include <string>
#include <unordered_map>
#include <vector>
#include <queue>
#include <cstdint>

extern int INF;

namespace graph_library {
    class Graph {
    private:
        struct Edge {
            std::string to;
            int weight;
        };
        std::unordered_map<std::string, std::vector<Edge>> adj;

    public:
        virtual void add_edge(const std::string& from, const std::string& to, int weight);
        virtual std::vector<std::string> find_shortest_path(const std::string& start, const std::string& end);
    };
}