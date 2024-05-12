//322516840
//reutgerber@gmail.com

#include "doctest.h"
#include "Algorithms.hpp"
#include "Graph.hpp"
#include <iostream>

using namespace std;



TEST_CASE("Test isConnected")
{
    cout << "test 1" << endl;
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isConnected(g) == true);

    cout << "test 2" << endl;
    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph2);
    CHECK(ariel::Algorithms::isConnected(g) == false);
}

TEST_CASE("Test shortestPath")
{
    cout << "test 3" << endl;
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 2) == "0->1->2");

    cout << "test 4" << endl;
    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph2);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 4) == "-1");
}
TEST_CASE("Test isContainsCycle")
{
    cout << "test 5" << endl;
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isContainsCycle(g) == false);

    cout << "test 6" << endl;
    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph2);
    CHECK(ariel::Algorithms::isContainsCycle(g) == true);
}
TEST_CASE("Test isBipartite")
{
    cout << "test 7" << endl;
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isBipartite(g) == "The graph is bipartite: A={0, 2}, B={1}");

    cout << "test 8" << endl;
    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph2);
    CHECK(ariel::Algorithms::isBipartite(g) == "0");

    cout << "test 9" << endl;
    vector<vector<int>> graph3 = {
        {0, 1, 2, 0, 0},
        {1, 0, 3, 0, 0},
        {2, 3, 0, 4, 0},
        {0, 0, 4, 0, 5},
        {0, 0, 0, 5, 0}};
    g.loadGraph(graph3);
    //CHECK(ariel::Algorithms::isBipartite(g) == "The graph is bipartite: A={0, 2, 4}, B={1, 3}");
    CHECK(ariel::Algorithms::isBipartite(g) =="0");
}
TEST_CASE("Test invalid graph")
{
    cout << "test 10" << endl;
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 2, 0},
        {1, 0, 3, 0},
        {2, 3, 0, 4},
        {0, 0, 4, 0},
        {0, 0, 0, 5} };
    CHECK_THROWS(g.loadGraph(graph));
}

TEST_CASE("Test isNegativeCycle")
    {
    cout << "test 11" << endl;
        ariel::Graph g;
        vector<vector<int>> graph = {
        {0,1,3,-3,0},
        {1,0,2,0,0},
        {3,2,0,-2,0},
        {-3,0,-2,0,6},
        {0,0,0,6,0}
        };
        g.loadGraph(graph);
        CHECK(ariel::Algorithms::isNegativeCycle(g) == true);
}
TEST_CASE("Test shortestPath with negative")
{
    cout << "test 12" << endl;
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0,1,3,-3,0},
        {1,0,2,0,0},
        {3,2,0,-2,0},
        {-3,0,-2,0,6},
        {0,0,0,6,0}
    };
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 4) == "error");
}
TEST_CASE("Test isContainsCycle with negative")
{
    cout << "test 13" << endl;
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0,1,3,-3,0},
        {1,0,2,0,0},
        {3,2,0,-2,0},
        {-3,0,-2,0,6},
        {0,0,0,6,0}
    };
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isContainsCycle(g) == true);
}

TEST_CASE("Test isBipartite longer graph")
{
    cout << "test 14" << endl;
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0,1,3,-3,0},
        {1,0,2,0,0},
        {3,2,0,-2,0},
        {-3,0,-2,0,6},
        {0,0,0,6,0}
    };
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isBipartite(g) == "0");
}


TEST_CASE("Test isConnected for directed graph") {
    cout << "Test 15 case 1: Directed graph with a single strongly connected component" << endl;
    ariel::Graph g1;
    vector<vector<int>> graph1 = {
        {0, 1, 1},
        {0, 0, 1},
        {1, 0, 0} };
    g1.loadGraph(graph1);
    CHECK(ariel::Algorithms::isConnected(g1) == true);

    cout << "Test 15 case 2: Directed graph with multiple strongly connected components" << endl;
    ariel::Graph g2;
    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {0, 0, 1, 0, 0},
        {1, 0, 0, 1, 0},
        {0, 0, 0, 0, 1},
        {0, 0, 0, 0, 0} };
    g2.loadGraph(graph2);
    CHECK(ariel::Algorithms::isConnected(g2) == false);
}

TEST_CASE("Test shortestPath for directed graph")
{
    cout << "test 16 case a: there is shortest path" << endl;
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 2},
        {0, 0, -4},
        {0, 0, 0} };
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 2) == "0->1->2");

    cout << "test 16 case b: there is no shortest path" << endl;
    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {0, 0, 1, 0, 0},
        {1, 0, 0, 1, 0},
        {0, 0, 0, 0, 1},
        {0, 0, 0, 0, 0} };
    g.loadGraph(graph2);
    CHECK(ariel::Algorithms::shortestPath(g, 4, 2) == "-1");

    cout << "test 16 case c: there is negative cycle" << endl;
    vector<vector<int>> graph3 = {
        {0, -1, 1, 0, 0},
        {0, 0, -1, 0, 0},
        {-1, 0, 0, 1, 0},
        {0, 0, 0, 0, 1},
        {0, 0, 0, 0, 0} };
    g.loadGraph(graph3);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 4) == "error");
}
TEST_CASE("Test isContainsCycle for directed graph")
{
    cout << "test 17 : contain cycle" << endl;
    ariel::Graph g;
    vector<vector<int>> graph4 = {
        {0, 1, 1, 0, 0},
        {0, 0, 1, 0, 0},
        {1, 0, 0, 1, 0},
        {0, 0, 0, 0, 1},
        {0, 0, 0, 0, 0} };
    g.loadGraph(graph4);
    CHECK(ariel::Algorithms::isContainsCycle(g) == true);


    cout << "test 18 : no cycle" << endl;
    vector<vector<int>> graph6 = {
        {0, -1, 1, 0, 0},
        {0, 0, -1, 0, 0},
        {0, 0, 0, 1, 0},
        {0, 0, 0, 0, 1},
        {0, 0, 0, 0, 0} };
    g.loadGraph(graph6);
    CHECK(ariel::Algorithms::isContainsCycle(g) == false);
}

TEST_CASE("Test isNegativeCycle for directed graph")
{
    ariel::Graph g;
    cout << "test 19 : contain negative cycle" << endl;
    vector<vector<int>> graph5 = {
        {0, -1, 1, 0, 0},
        {0, 0, -1, 0, 0},
        {-1, 0, 0, 1, 0},
        {0, 0, 0, 0, 1},
        {0, 0, 0, 0, 0} };
    g.loadGraph(graph5);
    CHECK(ariel::Algorithms::isNegativeCycle(g) == true);

    cout << "test 20 : no negative cycle" << endl;
    vector<vector<int>> graph7 = {
        {0, 1, 1, 0, 0},
        {0, 0, 1, 0, 0},
        {1, 0, 0, 1, 0},
        {0, 0, 0, 0, 1},
        {0, 0, 0, 0, 0} };
    g.loadGraph(graph7);
    CHECK(ariel::Algorithms::isNegativeCycle(g) == false);
}