#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

class Edge{
public:
    // assume u and v are two vertices 
    // vertices are zero-indexed
    int u;
    int v;

    Edge(){
        u = -1; // invalid vertex index
        v = -1; // invalid vertex index
    }

    Edge(int _u, int _v){
        u = _u;
        v = _v;
    }
};

class Graph{
private:
    vector<int> vertices;
    vector<vector<int> > adjacencyList;
    vector<Edge> edgeList;
    const static int NUMBEROFVERTICES = 4;
    

public:
    Graph(){
    }

    // not a good way to receive params.
    Graph(bool adjacencyMatrix[NUMBEROFVERTICES][NUMBEROFVERTICES], int n){
        // adjacencyMatrix has dimension n x n with zeroes along the main diagonal
        // assume row 0 is for vertex 0, row 1 is for vertex 1 and so on
        // vertex i contains i as its data
        // TASKS: add methods to do the following:
        // build vertices, adjacencyList, edgeList using adjacencyMatrix.
        BuildVertices(n);
        BuildAdjacencyList(adjacencyMatrix, n);
        BuildEdgeList();
    }
    
    void BuildVertices(int numberOfVertices){
        for(int i = 0; i < numberOfVertices; i++){
            vertices.push_back(i);
        }
    }

    void ShowVertices(){
        // display all vertices
        cout << "vertices: ";
        for(int i = 0; i < vertices.size() - 1; i++)
            cout << vertices[i] << ", ";
        cout << vertices[vertices.size() - 1]; 
        cout << endl;
    }

    void BuildAdjacencyList(bool adjacencyMatrix[NUMBEROFVERTICES][NUMBEROFVERTICES], int n){
        adjacencyList.resize(n);
        for(int vertex = 0; vertex < n; vertex++)
            for(int adjacent = 0; adjacent < n; adjacent++)
                if(adjacencyMatrix[vertex][adjacent] != 0){
                    adjacencyList[vertex].push_back(adjacent);
                }
    }
    void ShowAdjacencyList(){
        // display adjacency list
        for(int vertex = 0; vertex < adjacencyList.size(); vertex++){
            cout << "Adjaceny of vertex " << vertex << ": ";
            if(adjacencyList[vertex].size() != 0){
                for(int adjacent = 0; adjacent < adjacencyList[vertex].size() - 1; adjacent++)
                    cout << adjacencyList[vertex][adjacent] << ", ";
                cout << adjacencyList[vertex][adjacencyList[vertex].size() - 1];
            }
            cout << endl;
        }
    }

    void BuildEdgeList(){
        for(int vertex = 0; vertex < adjacencyList.size(); vertex++)
            for(int adjacent = 0; adjacent < adjacencyList[vertex].size(); adjacent++)
                edgeList.push_back(Edge(vertex, adjacencyList[vertex][adjacent]));
        
    }

    void ShowEdgeList(){
        // display edge list
        if(edgeList.size() == 0)
            return;
        cout << "Edges: ";
        for(int i = 0; i < edgeList.size(); i++){
            cout << "(" <<  edgeList[i].u << "," << edgeList[i].v <<") ";
        }
        cout << endl;
    }

    int VertexCount(){
        // returns the number of vertices in the graph
        return vertices.size();
    }

    int EdgeCount(){
        // returns the number of edges in the graph
        return edgeList.size();
    }

    void ShowNeighbors(int v){
        // display neighbors of vertex v
        if(v >= 0 && v < vertices.size()){
            cout << "Neighbours of Vertex " << v << ": ";
            if( adjacencyList[v].size() != 0){
                for(int i = 0; i < adjacencyList[v].size() - 1; i++)
                    cout << adjacencyList[v][i] << ", ";
                cout << adjacencyList[v][adjacencyList[v].size() - 1];
            }
            cout << endl;
        }else{
            cout << "Vertex " << v << " doesn't exist on the graph." << endl;
        }
    }

    int Degree(int v){
        // return the degree of vertex v
        return (v >= 0 && v < vertices.size()) ? adjacencyList[v].size() : 0;
    }

    bool IsDirected(){
        // returns true if the graph is directed; false otherwise
        // brute-force; needs to be updated
        for(int i = 0; i < edgeList.size(); i++){
            bool pairFound = false;
            for(int j = 0; j < edgeList.size(); j++)
                if(edgeList[i].u == edgeList[j].v && edgeList[i].v == edgeList[j].u)
                    pairFound = true;
            if(!pairFound)
                return true;
        }
        return false;
                
    }

    void ShowDegrees(){
        // display degrees of all vertices
        cout << "Degrees of all vertices: " << endl;
        for(int i = 0; i < vertices.size(); i++)
            cout << "Vertex " << i << "'s degrees: " << adjacencyList[i].size();
    }

    bool HasEdge(int v1, int v2){
        // returns true if there is an edge between vertices v1 n v2; false otherwise
        if(v1 >= 0 && v1 < vertices.size() && v2 >= 0 && v2 < vertices.size()){
            for(int i = 0; i < edgeList.size(); i++)
                if((edgeList[i].u == v1 && edgeList[i].v == v2) || (edgeList[i].u == v2 && edgeList[i].v == v1))
                    return true;
        }
        return false;
    }

    int Path(int v1, int v2){
        // returns the length of the path (number of edges) if there is a path from vertex v1 to vertex v2; otherwise returns 0
        if(!(v1 >= 0 && v1 < vertices.size()) || !(v2 >= 0 && v2 < vertices.size()) || v1 == v2)
            return 0;
        vector<bool> vistiedList;
        vistiedList.resize(vertices.size());
        vector<int> stack(1, v1);
        // start at v1;
        vistiedList[v1] = true;
        int currentV = v1;
        while(true){
            int degree = adjacencyList[currentV].size() - 1;
            bool nextVertexFound = false;
            while(degree >= 0 && !nextVertexFound){
                if(!vistiedList[adjacencyList[currentV][degree]]){
                    currentV = adjacencyList[currentV][degree];
                    vistiedList[currentV] = true;
                    stack.push_back(currentV);
                    nextVertexFound = true;
                }
                degree--;
            }
            if(currentV == v2)
                //returning number of edges
                return stack.size() - 1;
            else if(!nextVertexFound){
                // no path found
                if(stack.size() == 1)
                    return 0;
                stack.pop_back();
                currentV = stack.back();
            }
        }
        // // no path found
        // return 0;
    }

    bool HasCycle(){
        // return true if graph has a cycle (starting from a node we follow edges to return back to the same vertex); false otherwise
        //BFS
        int start = 0;
        while(start < vertices.size()){
            vector<bool> visited;
            queue<int> visiting;
            visited.resize(vertices.size());
            visiting.push(start);
            visited[start] = true;
            while(!visiting.empty()){
                int current = visiting.front();
                visiting.pop();
                int i = 0;
                while(i < adjacencyList[current].size()){
                    if(visited[adjacencyList[current][i]])
                        return true;
                    else{
                        visiting.push(adjacencyList[current][i]);
                        visited[adjacencyList[current][i]] = true;
                        i++;
                    }
                }
            }
            start++;
        }
        return false;
    }

    void ShowCycles(){
        // displays all cycles (if any)
        // each cycle should begin and end with the same vertex
        //DFS
        int start = 0;
        while(start < vertices.size()){
            vector<bool> visitedList;
            visitedList.resize(vertices.size());
            vector<int> stack(1, start);
            int currentV = start;
            visitedList[start] = true;
            while(true){
                currentV = stack.back();
                int degree = adjacencyList[currentV].size() - 1;
                bool hasNeighboursToTraverse = false;
                while(degree >= 0 && !hasNeighboursToTraverse){
                    if(adjacencyList[currentV][degree] == start){
                        currentV = start;
                        cout << "cycle starting from " << start << ": ";
                        for (int i = 0; i < stack.size(); i++)
                            cout << stack[i] << " -> ";
                        cout << start << endl;
                        break;
                    }else if(!visitedList[adjacencyList[currentV][degree]]){
                        hasNeighboursToTraverse = true;
                        currentV = adjacencyList[currentV][degree];
                        stack.push_back(currentV);
                        visitedList[currentV] = true;
                    }
                    degree--;
                }
                if(!hasNeighboursToTraverse){
                    // finally traversed all vertices, but not able to find a cycle
                    if(currentV == start)
                        break;
                    stack.pop_back();
                    currentV = stack.back();
                }
            }
            start++;   
        } 
    }
    

};



#endif