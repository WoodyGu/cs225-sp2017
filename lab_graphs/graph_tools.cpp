/**
 * @file graph_tools.cpp
 * This is where you will implement several functions that operate on graphs.
 * Be sure to thoroughly read the comments above each function, as they give
 *  hints and instructions on how to solve the problems.
 */
#include <math.h>
#include "graph_tools.h"

struct DisjointSets{
  void addelements(int num){
    for(int i = 0;i<num;i++){
      v.push_back(-1);
    }
  }
  int find(int elem){
    if(v[elem]<0){
      return elem;
    }
    else{
      v[elem] = find(v[elem]);
      return find(v[elem]);
    }
  }
  void setunion(int a, int b){
    int root1 = find(a);
    int root2 = find(b);
    int newSize = v[root1]+v[root2];
    if(abs(v[root1])>=abs(v[root2])){
      v[root2] = root1;
      v[root1] = newSize;
    }
    else{
      v[root1] = root2;
      v[root2] = newSize;
    }
  }
  std::vector<int> v;
};
/**
 * Finds the minimum edge weight in the Graph graph.
 * THIS FUNCTION IS GRADED.
 *
 * @param graph - the graph to search
 * @return the minimum weighted edge
 *
 * @todo Label the minimum edge as "MIN". It will appear blue when
 *  graph.savePNG() is called in minweight_test.
 *
 * @note You must do a traversal.
 * @note You may use the STL stack and queue.
 * @note You may assume the graph is connected.
 *
 * @hint Initially label vertices and edges as unvisited.
 */
int GraphTools::findMinWeight(Graph& graph)
{
    /* Your code here! */
    Vertex start = graph.getStartingVertex();
    queue<Vertex> q;
    //set all the vertex to be "UNEXPLORED", or they will just be empty string
    vector<Vertex> allVertex= graph.getVertices();
    Vertex minStart;
    Vertex minEnd;
    for(size_t i = 0;i<allVertex.size();i++){
      graph.setVertexLabel(allVertex[i],"UNEXPLORED");
    }
    graph.setVertexLabel(start,"VISITED");
    q.push(start);
    int minWeight = 10000;
    //carry out a BFS
    while(!q.empty()){
      Vertex curr = q.front();
      q.pop();
      vector<Vertex> neighbour = graph.getAdjacent(curr);
      for(size_t i = 0;i<neighbour.size();i++){
        Vertex temp = neighbour[i];
        if(graph.getEdgeWeight(curr,temp) < minWeight){
          minWeight = graph.getEdgeWeight(curr,temp);
          minStart = curr;
          minEnd = temp;
        }
        if(graph.getVertexLabel(temp) == "UNEXPLORED"){
          graph.setEdgeLabel(curr,temp,"DISCOVERY");
          graph.setVertexLabel(temp,"VISITED");
          q.push(temp);
        }
        if(graph.getEdgeLabel(curr,temp) == ""){
          graph.setEdgeLabel(curr,temp,"CROSS");
        }
      }
    }
    graph.setEdgeLabel(minStart,minEnd,"MIN");
    return minWeight;
}

/**
 * Returns the shortest distance (in edges) between the Vertices
 *  start and end.
 * THIS FUNCTION IS GRADED.
 *
 * @param graph - the graph to search
 * @param start - the vertex to start the search from
 * @param end - the vertex to find a path to
 * @return the minimum number of edges between start and end
 *
 * @todo Label each edge "MINPATH" if it is part of the minimum path
 *
 * @note Remember this is the shortest path in terms of edges,
 *  not edge weights.
 * @note Again, you may use the STL stack and queue.
 * @note You may also use the STL's unordered_map, but it is possible
 *  to solve this problem without it.
 *
 * @hint In order to draw (and correctly count) the edges between two
 *  vertices, you'll have to remember each vertex's parent somehow.
 */
int GraphTools::findShortestPath(Graph& graph, Vertex start, Vertex end)
{
    /* Your code here! */
    //may use a map to store the vertex's parent
    //first traverse the whole graph and fill parent nodes just like
    queue<Vertex> q;
    vector<Vertex> allVertex= graph.getVertices();
    unordered_map<Vertex, Vertex> dictPrevious;//key is current vertex, value is predecessor
    for(size_t i = 0;i<allVertex.size();i++){
      graph.setVertexLabel(allVertex[i],"UNEXPLORED");
    }
    graph.setVertexLabel(start,"VISITED");
    q.push(start);
    while(!q.empty()){
      Vertex curr = q.front();
      q.pop();
      vector<Vertex> neighbour = graph.getAdjacent(curr);
      //set up the distance dict and previous dict throguh BFS
      for(size_t i = 0;i<neighbour.size();i++){
        Vertex temp = neighbour[i];
        if(graph.getVertexLabel(temp) == "UNEXPLORED"){
          dictPrevious.insert({temp,curr});
          graph.setEdgeLabel(curr,temp,"DISCOVERY");
          graph.setVertexLabel(temp,"VISITED");
          q.push(temp);
        }
        if(graph.getEdgeLabel(curr,temp) == ""){
          graph.setEdgeLabel(curr,temp,"CROSS");
        }
      }
    }
    int shortestPath = 0;
    Vertex curr = end;
    while (curr!=start) {
      Vertex currPrev = dictPrevious[curr];
      graph.setEdgeLabel(curr,currPrev,"MINPATH");
      curr = currPrev;
      shortestPath++;
    }
    return shortestPath;
}

/**
 * Finds a minimal spanning tree on a graph.
 * THIS FUNCTION IS GRADED.
 *
 * @param graph - the graph to find the MST of
 *
 * @todo Label the edges of a minimal spanning tree as "MST"
 *  in the graph. They will appear blue when graph.savePNG() is called.
 *
 * @note Use your disjoint sets class from MP 7.1 to help you with
 *  Kruskal's algorithm. Copy the files into the libdsets folder.
 * @note You may call std::sort instead of creating a priority queue.
 */
void GraphTools::findMST(Graph& graph)
{
    /* Your code here! */
    vector<Edge> allEdges = graph.getEdges();//need a vector to store all the Edges
    std::sort(allEdges.begin(),allEdges.end());//create a priorityqueue
    DisjointSets graphSets;//create a DisjointSets
    vector<Vertex> allVertex = graph.getVertices();//get a vector of all vertices
    graphSets.addelements(allVertex.size());//put all vertices into the disjoint set
    for(size_t i = 0;i<allEdges.size();i++){//go thorugh the edge vector
      Edge curr = allEdges[i];//extract an edge from the vector
      Vertex u = curr.source;//find its starting and ending point
      Vertex v = curr.dest;
      if(graphSets.find(u)!=graphSets.find(v)){//if they are not in the same set
        graph.setEdgeLabel(u,v,"MST");//label MST and put the vertex in to union
        graphSets.setunion(u,v);
      }
    }
}
