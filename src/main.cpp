#include "graph.hpp"
#include <iostream>

int main()
{
    std::vector<Edge> edges = { {0, 1, 3}, {1, 2, 1}, {0, 3, 7}, {0, 4, 8}, {4, 3, 3}, {1, 3, 4}, {3, 2, 2} };
    int n = 5;
    Graph* g_ptr = new Graph(edges, n);

    g_ptr->print_graph(n);
    int selected_node = 0;
    g_ptr->dijkstra_shortest_path(selected_node, n);

    if (g_ptr->is_cyclic(n))
      	std::cout << "Graph contains cycle\n";
    else
      	std::cout << "Graph doesn't contain cycle\n";

    return 0;
}