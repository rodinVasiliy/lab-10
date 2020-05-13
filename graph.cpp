#include "Graph.h"
#include <iostream>

int main(){
    Graph<char,double> graph;
    graph.AddVertex('0');
    graph.AddVertex('1');
    graph.AddVertex('2');
    graph.AddVertex('3');
    graph.AddVertex('4');
    graph.AddVertex('5');
    graph.AddVertex('6');
    graph.AddVertex('7');
    graph.AddVertex('8');
    graph.AddEdge('0','1',0);
    graph.AddEdge('0','2',0);
    graph.AddEdge('2' ,'3' ,0);
    graph.AddEdge('2' ,'4' ,0);
    graph.AddEdge( '2','7' ,0);
    graph.AddEdge('7' ,'6' ,0);
    graph.AddEdge( '7','8',0);
    graph.AddEdge( '3','4' ,0);
    graph.AddEdge( '4', '5',0);
    auto vertexCount = graph.GetVertexCount();
    auto used = new bool[vertexCount];
    for(std::size_t i=0;i<vertexCount;++i){
        used[i]=false;
    }
    auto stack = new std::size_t[vertexCount];
    std::size_t stackSize=0;
    dfs(graph,'3',used,stack,stackSize,[](auto vertex) {
       std::cout << vertex << ' ';
    });
    std::cout << std::endl;
    DepthFirstSearch(graph,'0',[](auto vertex) {
        std::cout << vertex << ' ';
    });
    std::cout << std::endl;
    BreadthFirstSearch(graph,'0',[](auto vertex) {
        std::cout << vertex << ' ';
    });
    std::cout << std::endl;
    delete[] used;
    delete[] stack;
}
