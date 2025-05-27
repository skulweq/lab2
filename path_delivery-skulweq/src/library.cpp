#include "graph.hpp"
#include <limits>

namespace template_library {

    void Graph::add_edge(const std::string &from, const std::string &to, uint16_t weight) {
        adj[from].push_back(Edge{to, weight});
    }

    std::vector<std::string> Graph::find_shortest_path([[maybe_unused]] const std::string &start,
                                                       [[maybe_unused]] const std::string &end) {
        using Pair = std::pair<int, std::string>;
        std::priority_queue<Pair, std::vector<Pair>, std::greater<>> pq;
        std::unordered_map<std::string, int> dist;
        std::unordered_map<std::string, std::string> prev;
        std::vector<std::string> path;

        /*
         * Shortest Path Realization
         */

        return path;
    }
}