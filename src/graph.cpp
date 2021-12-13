#include <set>
#include <limits>
#include "graph.hpp"

//Helper recursive function used to find cyclic in Graph.
bool Graph::is_cyclic_util(int n, bool* visited, bool *rec_stack) {
	//If current node is not visited.
  	if (visited[n] == false) {
		//Current node is visited.
		visited[n] = true;
		//Mark as recursion node for current node.
		rec_stack[n] = true;
		//Loop for all nodes that are adjoint with the current node.
		for (Pair adj : adj_list[n]) {
			if (!visited[adj.first] && is_cyclic_util(adj.first, visited, rec_stack))
				return true;
			else if (rec_stack[adj.first])
				return true;
		}
  	}
	rec_stack[n] = false;
	return false;
}
//Function to find the cyclic in directional graphs.
bool Graph::is_cyclic(int n) {
	//Visited nodes are initialized.
	bool *visited = new bool[n]; ///smart pointer
	//Recursion nodes are initialized.
	bool *rec_stack = new bool[n];
	for (int i = 0; i < n; i++) {
		visited[i] = false;
		rec_stack[i] = false;
	}
	//Cyclic is detected by calling the is_cyclic_util function for each node.
	for (int i = 0; i < n; i++)
		if (is_cyclic_util(i, visited, rec_stack))
			return true;

	return false;
}
//Dijkstra's algorithm to find the shortest path between nodes in a graph.
void Graph::dijkstra_shortest_path(int source_node, int node_count) {
	//Infinity value is defined. (Here int max is used.)
	const int inf = std::numeric_limits<int>::max();
	//Distance value of all nodes is defined as inf.
	std::vector<int> dist(node_count, inf);
	std::set<Pair> set_length_node;
	
	//The distance value of the source node is initialize as 0.
	dist[source_node] = 0;
	//Source itself is added to set.
	set_length_node.insert(Pair(0, source_node));

	while (!set_length_node.empty()) {
		//Since the first element of Set is the minimum distance node, it is set as the vertex and extracted.
		Pair top = *set_length_node.begin();
		set_length_node.erase(set_length_node.begin());
		/* 	Current source node is initialized. 
			Because by default, the value defined in vector should not be shorter than other distances. 
			Therefore 0 or any other value is not initialized.	*/
		int current_source_node = top.second;

		//Adjoint nodes in the initialized node's adjoint list are browsed.
		for (const auto &it : adj_list[current_source_node]) {
			//Adjoint node of current_source_node.
			int adj_node = it.first;
			//Weight between current_source_node and adjoint node.
			int length_to_adjnode = it.second;
			//If there is a shorter path from the current source node to the adjoint node, it added to the set.
			if (dist[adj_node] > length_to_adjnode + dist[current_source_node]) {
				dist[adj_node] = length_to_adjnode + dist[current_source_node];
				set_length_node.insert(Pair(dist[adj_node], adj_node));
			}
		}
	}
	//All shortest paths are printed.
	for (int i = 0; i < node_count; i++)
		std::cout << "Source Node(" << source_node << ") -> Destination Node(" << i << ") : " << dist[i] << "\n";
}
//Prints the Graph's adjoint list.
void Graph::print_graph(int n) {
	for (int i = 0; i < n; i++) {
		for (Pair &v : adj_list[i]) {
			std::cout << "(" << i << ", " << v.first << ", " << v.second << ") ";
		}
		std::cout << "\n";
	}
}