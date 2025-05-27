#include <iostream>
#include "graph.hpp"

int main() {
    graph_library::Graph graph;
    graph.add_edge("Moscow", "Kazan", 840);
    graph.add_edge("Moscow", "Tambov", 485);
    graph.add_edge("Moscow", "Sochi", 1640);
    graph.add_edge("Tambov", "Kazan", 796);
    graph.add_edge("Tambov", "Sochi", 1310);

    auto path = graph.find_shortest_path("Moscow", "Kazan");
    for (size_t i = 0; i < path.size(); ++i) {
        std::cout << path[i] << std::endl;
    }
    return 0;
}