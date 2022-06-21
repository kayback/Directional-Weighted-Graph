#include <gtest/gtest.h>
#include "../../src/graph.hpp"


class graph_test : public ::testing::Test{
protected:
    
    std::vector<Edge> edges = { {0, 1, 3}, {1, 2, 1}, {0, 3, 7}, {0, 4, 8}, {4, 3, 3}, {1, 3, 4}, {3, 2, 2} };
    int n = 5;
    Graph* g_ptr = new Graph(edges, n);
    void SetUp() override {}

    void TearDown() override {}

};
namespace graph_positive {

  TEST_F(graph_test, graph_test_print_graph) {
    ASSERT_NO_THROW(g_ptr->print_graph(n););
    EXPECT_EQ(g_ptr->adj_list.size(), n);
  }
  TEST_F(graph_test, graph_test_dijkstra_shortest_path) {
    printf("şükrü");
    int selected_node = 0;
    ASSERT_NO_THROW(g_ptr->dijkstra_shortest_path(selected_node, n););
    EXPECT_EQ(g_ptr->adj_list.size(), n);
  }
  TEST_F(graph_test, graph_test_is_not_cyclic) {
    ASSERT_NO_THROW(EXPECT_FALSE(g_ptr->is_cyclic(n)));
    EXPECT_EQ(g_ptr->adj_list.size(), n);
  }

}
class graph_test_other_graphs : public ::testing::Test{
protected:
    
    std::vector<Edge> edges = { {0, 1, 3}, {1, 3, 1}, {3, 0, 7}, {0, 4, 8}, {4, 3, 3}, {1, 3, 4}, {3, 2, 2}, {2, 5, 2}, {5, 6, 2}};
    int n = 7;
    Graph* g_ptr = new Graph(edges, n);
    void SetUp() override {}

    void TearDown() override {}

};
namespace graph_test_2 {
  TEST_F(graph_test_other_graphs, graph_test_print_graph_other) {
    ASSERT_NO_THROW(g_ptr->print_graph(n));
    EXPECT_EQ(g_ptr->adj_list.size(), n);
  }
  TEST_F(graph_test_other_graphs, graph_test_dijkstra_shortest_path_other) {
    int selected_node = 0;
    ASSERT_NO_THROW(g_ptr->dijkstra_shortest_path(selected_node, n););
    EXPECT_EQ(g_ptr->adj_list.size(), n);
  }

  TEST_F(graph_test_other_graphs, graph_test_is_cyclic_other) {
    ASSERT_NO_THROW(EXPECT_TRUE(g_ptr->is_cyclic(n)));
    EXPECT_EQ(g_ptr->adj_list.size(), n);
  }
}