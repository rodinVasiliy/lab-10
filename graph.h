#include "Graph.h"
#include "Locality.h"
#include <iostream>

int main() {
    /* Graph<char, double> graph;
     graph.AddVertex('0');
     graph.AddVertex('1');
     graph.AddVertex('2');
     graph.AddVertex('3');
     graph.AddVertex('4');
     graph.AddVertex('5');
     graph.AddVertex('6');
     graph.AddVertex('7');
     graph.AddVertex('8');
     graph.AddEdge('0', '1', 5);
     graph.AddEdge('0', '2', 55);
     graph.AddEdge('2', '3', 30);
     graph.AddEdge('2', '4', 4);
     graph.AddEdge('2', '7', 3);
     graph.AddEdge('7', '6', 41);
     graph.AddEdge('7', '8', 55);
     graph.AddEdge('3', '4', 2);
     graph.AddEdge('4', '5', 13);
     auto vertexCount = graph.GetVertexCount();
     auto used = new bool[vertexCount];
     for (std::size_t i = 0; i < vertexCount; ++i) {
         used[i] = false;
     }
     auto stack = new std::size_t[vertexCount];
     std::size_t stackSize = 0;
     dfs(graph, '3', used, stack, stackSize, [](auto vertex) {
         std::cout << vertex << ' ';
     });
     std::cout << std::endl;
     DepthFirstSearch(graph, '0', [](auto vertex) {
         std::cout << vertex << ' ';
     });
     std::cout << std::endl;
     BreadthFirstSearch(graph, '0', [](auto vertex) {
         std::cout << vertex << ' ';
     });
     std::cout << std::endl;
     char *path = new char[vertexCount];
     std::size_t *distance = new size_t[vertexCount];
     //auto r = Dijkstra(graph, '0', '8', path, distance);
     auto r = BellmanFord(graph, '2', '8', path, distance);
     std::cout << r << std::endl;
     std::cout << path << std::endl;
     std::cout << *distance << std::endl;
     delete[] used;
     delete[] stack;
     delete[] distance;*/
    Graph<Locality, double> graph;
    Locality vertex1("samara", 1000);
    Locality vertex2("tolyatty", 1000);
    Locality vertex3("sisran", 1000);
    Locality vertex4("saratov", 1000);
    Locality vertex5("moscov", 1000);
    Locality vertex6("piter", 1000);
    Locality vertex7("London", 1000);
    Locality vertex8("LA", 1000);
    Locality vertex9("San Paulo", 1000);
    /*Locality vertex10("Milan", 1000);
    Locality vertex11("Madrid", 1000);
    Locality vertex12("Barcelona", 1000);*/
    graph.AddVertex(vertex1);
    graph.AddVertex(vertex2);
    graph.AddVertex(vertex3);
    graph.AddVertex(vertex4);
    graph.AddVertex(vertex5);
    graph.AddVertex(vertex6);
    graph.AddVertex(vertex7);
    graph.AddVertex(vertex8);
    graph.AddVertex(vertex9);
    graph.AddEdge(vertex1, vertex2, 5);
    graph.AddEdge(vertex1, vertex3, 55);
    graph.AddEdge(vertex3, vertex4, 30);
    graph.AddEdge(vertex3, vertex5, 4);
    graph.AddEdge(vertex4, vertex5, 3);
    graph.AddEdge(vertex5, vertex6, 41);
    graph.AddEdge(vertex8, vertex7, 55);
    graph.AddEdge(vertex8, vertex9, 2);
    graph.AddEdge(vertex3, vertex8, 13);
    auto vertexCount = graph.GetVertexCount();
    auto used = new bool[vertexCount];
    for (std::size_t i = 0; i < vertexCount; ++i) {
        used[i] = false;
    }
    auto stack = new std::size_t[vertexCount];
    std::size_t stackSize = 0;
    std::cout << "DFS" << std::endl;
    dfs(graph, vertex1, used, stack, stackSize, [](auto vertex) {
        std::cout << vertex << ' ';
    });
    std::cout << std::endl;
    std::cout << "DepthFirstSearch" << std::endl;
    DepthFirstSearch(graph, vertex1, [](auto vertex) {
        std::cout << vertex << ' ';
    });
    std::cout << std::endl;
    std::cout << "BreadthFirstSearch" << std::endl;
    BreadthFirstSearch(graph, vertex1, [](auto vertex) {
        std::cout << vertex << ' ';
    });
    std::cout << std::endl;
    Locality *path = new Locality[vertexCount];
    std::size_t *distance = new size_t[vertexCount];
    auto r = Dijkstra(graph, vertex1, vertex2, path, distance);
   // auto v = BellmanFord(graph, vertex1, vertex2, path, distance);
    std::cout << r << std::endl;
    for(std::size_t i=0;i<(*distance);++i){
        std::cout << *path << std::endl;
        path=path+sizeof(Locality);
    }
    std::cout << *distance << std::endl;
    delete[] used;
    delete[] stack;
    delete[] distance;
}
