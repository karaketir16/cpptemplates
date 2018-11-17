#ifndef GRAPH_HPP_
#define GRAPH_HPP_
#include <vector>
#include <queue>
using namespace std;
class Edge
{
    public:
    int nodeNumber1;
    int nodeNumber2;
    int edgeWeight=1;
};
class Node
{
    public:
    bool visited = false;
    vector<pair<int, int>> adj;// edgeWeight, nodeNumber
    
};
template<class T>
class Graph
{
    public:
        bool directed;
        vector<T> nodes;
        Graph(int n, vector<Edge> edges, bool directed=0);
        queue<int> bfs_queue(int startNodeNumber=1);
};
template<class T>
Graph<T>::Graph(int n, vector<Edge> edges, bool directed)
{
    this->directed=directed;
    nodes = vector<T> (n+1);
    for(auto edge: edges)
    {
        nodes[edge.nodeNumber1].adj.
        push_back(make_pair(edge.edgeWeight, edge.nodeNumber2));
        if(!directed)
            nodes[edge.nodeNumber2].adj.
            push_back(make_pair(edge.edgeWeight, edge.nodeNumber1));
    }
}
template<class T> 
queue<int> Graph<T>::bfs_queue(int startNodeNumber)
{
    //is_root_of_tree
    vector<T> temp_nodes=this->nodes;
    queue<int> q;
    queue<int> temp_q;
    temp_q.push(startNodeNumber);
    temp_nodes[startNodeNumber].visited=true;
    while(!temp_q.empty())
    {
        q.push(temp_q.front());
        for(auto nextNode:temp_nodes[temp_q.front()].adj)
        {
            if(temp_nodes[nextNode.second].visited) continue;
            temp_q.push(nextNode.second);
            temp_nodes[nextNode.second].visited=true;
        }
        temp_q.pop();
    }
    return q;
}
#endif // GRAPH_HPP_