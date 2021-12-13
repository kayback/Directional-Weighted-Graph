#include <iostream>
#include <vector>
#ifndef GRAPH_HPP
#define GRAPH_HPP

//A pair type is defined to specify the adjoint list.
typedef std::pair<int, int> Pair;

//A data structure is defined that holds graph edge information.
struct Edge {
    int src, dest, weight;
};

class Graph {
	bool is_cyclic_util(int n, bool* visited, bool *rs);

public:
    //An adjoint vector of type pair is created to specify the adjoint list.
  	std::vector<std::vector<Pair>> adj_list;

	Graph(std::vector<Edge> const &edges, int n) {

        //The adj_list is sized by the number of nodes in the graph.
    	adj_list.resize(n);
        //Edge information is added for the directed graph.
		for (auto &edge : edges) {
			int src = edge.src;
			int dest = edge.dest;
			int weight = edge.weight;

			adj_list[src].push_back(std::make_pair(dest, weight));
		}
	}
    bool is_cyclic(int n);
	void dijkstra_shortest_path(int source_node, int node_count);
	void print_graph(int n);
};
#endif //GRAPH_HPP