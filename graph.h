#pragma once

#include <stdexcept>
#include <iostream>

// 1)TVertex - some info which store in Vertex
// 2)TEdge - some info which store in edge
// 3)TVertex, TEdge - lightweight
template <typename TVertex,typename TEdge>
void f(TVertex vertex){
    std::cout<<vertex;
}
template <typename TVertex,typename TEdge,typename TFuncional = void >
class Graph {

public:
    struct Edge {
        TVertex dstVertex;//where should go
        TEdge edge;//some info which store in edge

        Edge(const TVertex &dstVertex, const TEdge edge) : dstVertex(dstVertex), edge(edge) {}
    };

private:
    struct EdgeNode {//node of list
        Edge edge;
        EdgeNode *next;

        EdgeNode(const Edge &edge) : edge(edge), next(nullptr) {}

        EdgeNode(Edge edge, EdgeNode *next) : edge(edge), next(next) {}

    };

    struct Vertex {
        TVertex vertex;//info which store in vertex
        EdgeNode *edges;//list

        Vertex() : edges(nullptr) {}

        Vertex(const TVertex &vertex) : vertex(vertex), edges(nullptr) {}

    };

    Vertex *_graph;
    std::size_t _count;
public:
    Graph():_graph(nullptr),_count(0){}

    std::size_t FindVertexIndex(TVertex vertex) const {
        for (std::size_t i = 0; i < _count; ++i)if (_graph[i].vertex == vertex)return i;
        return _count;
    }

    std::size_t FindVertexIndexOrThrow(TVertex vertex) const {
        auto index = FindVertexIndex(vertex);
        if (index == _count)throw std::invalid_argument("Vertex not found!");
        return index;
    }

private:
    //we can store more than one edge between two vertex
    /*static EdgeNode *getEdges(Graph graph) {
        return graph->edges;
    }*/

public:
    void AddEdge(TVertex srcVertex, TVertex dstVertex, TEdge edge) {
        const auto srcIndex = FindVertexIndexOrThrow(srcVertex);
        const auto dstIndex = FindVertexIndexOrThrow(dstVertex);
        Edge e(dstVertex, edge);
        _graph[srcIndex].edges = new EdgeNode(e, _graph[srcIndex].edges);//head insert
    }

    [[nodiscard]]std::size_t GetVertexCount() const {
        return _count;
    }

    [[nodiscard]]TVertex GetVertex(std::size_t index) const {
        return _graph[index].vertex;
    }

    std::size_t getEdgeCount(TVertex vertex) const {
        std::size_t size = 0;
        auto index = FindVertexIndexOrThrow(vertex);
        auto tmp = _graph[index].edges;
        while (tmp) {
            ++size;
            tmp = tmp->next;
        }
        return size;
    }

    Edge GetEdge(TVertex srcVertex, std::size_t index) const {//?
        std::size_t count = 0;
        auto node = _graph[FindVertexIndexOrThrow(srcVertex)].edges;
        for (size_t i = 0; i < index; ++i)
            node = node->next;
        return node->edge;
    }


    void AddVertex(TVertex vertex) {
        const auto index = FindVertexIndex(vertex);
        if (index != _count)
            throw std::invalid_argument("Vertex already exists!");
        auto graph = new Vertex[_count + 1];
        for (std::size_t i = 0; i < _count; ++i)graph[i] = _graph[i];
        graph[index] = vertex;
        delete[] _graph;
        ++_count;
        _graph = graph;
    }
};
template<typename TVertex, typename TEdge, typename TFunctional>
void dfs(const Graph<TVertex,TEdge>& graph, TVertex begin,bool* used,std::size_t * stack,std::size_t &stackSize,TFunctional f) {
        auto beginIndex = graph.FindVertexIndexOrThrow(begin);
        used[beginIndex] = true;
        f(graph.GetVertex(beginIndex));
        const TVertex vertex=graph.GetVertex(beginIndex);
        //auto tmp= getEdges(graph[beginIndex]);
        for(std::size_t j=0;j<graph.getEdgeCount(vertex);++j){
            beginIndex=graph.FindVertexIndexOrThrow(graph.GetEdge(vertex,j).dstVertex);
            if(!used[beginIndex]) {
                stack[stackSize++] = beginIndex;
                used[beginIndex] = true;
            }
        }
        while(stackSize > 0) {
            auto vertexIndex = stack[--stackSize];
            dfs(graph, graph.GetVertex(vertexIndex), used, stack,stackSize ,f);
        }
    }
