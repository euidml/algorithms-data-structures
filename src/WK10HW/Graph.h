#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <map>
using namespace std;
class Vertex{
    public:
        int element;
        bool isCell;
        vector<Vertex *> adjacencyList;

    Vertex(){
        element = -1;
        isCell = false;
        adjacencyList = vector<Vertex *>();
    }

    Vertex(int _element, bool _isCell){
        element = _element;
        isCell = _isCell;
        adjacencyList = vector<Vertex *>();
    }
};


class Edge{
public:
    // assume u and v are two vertices 
    // vertices are zero-indexed
    Vertex* u;
    Vertex* v;

    Edge(){
        u = new Vertex(); // invalid vertex index
        v = new Vertex(); // invalid vertex index
    }

    Edge(Vertex* _u, Vertex* _v){
        u = _u;
        v = _v;
    }
};

class Graph{
private:
    vector<Vertex *> vertices = vector<Vertex*>();
    vector<Edge *> edgeList = vector<Edge *>();
    int numOfRows;
    int numOfColumns;
    

public:
    Graph(){
        Graph(nullptr, 0, 0);
    }

    // not a good way to receive params.
    Graph(unsigned int** maze, int _numOfRows, int _numOfColumns){
        if (maze && maze[0] && maze[0][0]) {
            // numOfRows = sizeof(maze) / sizeof(maze[0]);
            // numOfColumns = sizeof(maze[0]) / sizeof(maze[0][0]);
            numOfColumns = _numOfColumns;
            numOfRows = _numOfRows;
            BuildVertices(maze);
            BuildAdjacencyList(maze);
            BuildEdgeList();
        }
    }
    
    // DONE
    void BuildVertices(unsigned int** maze){
        if(!maze)
            return;
        vertices.resize(numOfRows * numOfColumns);
        for(int i = 0; i < numOfRows; i++)
            for(int j = 0; j < numOfColumns; j++)
                // it is to figure out whether or not it is a cell (if not, it's a wall)
                vertices[numOfColumns * i + j] = new Vertex(numOfColumns * i + j, maze[i][j]);
    
    }

    //Done
    void BuildAdjacencyList(unsigned int** maze){
        if(!maze)
            return;
        for(int idx = 0; idx < vertices.size(); idx++){
            // if it is a wall, pass it.
            if(!vertices[idx] && !vertices[idx] -> isCell)
                continue;
            // formulate i and j
            int i = idx / numOfColumns, j =  idx % numOfColumns;
            cout << i <<" " << j <<endl;
            //checking if there is any path to Up, Right, Down, Left
            // Up
            if((i - 1) >= 0 && vertices[(i - 1) * numOfColumns + j] -> isCell)
                vertices[idx] -> adjacencyList.push_back(vertices[(i - 1) * numOfColumns + j]);
            // Right
            if((j + 1) < numOfColumns && vertices[i * numOfColumns + j + 1] -> isCell)
                vertices[idx] -> adjacencyList.push_back(vertices[i * numOfColumns + j + 1]);
            // Down
            if((i + 1) < numOfRows && vertices[(i + 1) * numOfColumns + j] -> isCell)
                vertices[idx] -> adjacencyList.push_back(vertices[(i + 1) * numOfColumns + j]);
            // Left
            if((j - 1) >= 0 && vertices[i * numOfColumns + j - 1] -> isCell)
                vertices[idx] -> adjacencyList.push_back(vertices[i * numOfColumns + j - 1]);
        }
        
    }
   

    void BuildEdgeList(){
       for(int i = 0; i < vertices.size(); i++)
        if(vertices[i] && vertices[i] -> isCell)
            for(int j = 0; j < vertices[i] -> adjacencyList.size(); j++)
                edgeList.push_back(new Edge(vertices[i], vertices[i] -> adjacencyList[j]));
    }

        
    void ShowMap(){
        // cout << "Showing map: " << endl;
        for(int i = 0; i < numOfRows; i++){
            for(int j = 0; j < numOfColumns; j++){
                cout << vertices[i * numOfColumns + j] -> isCell << " ";
            }
            cout << endl;
        }
    }

    void ShowVertices(){
        // display all cells by location
        // cout << "Showing Cells only: " << endl;
        for (int i = 0; i < vertices.size(); i++)
            if(vertices[i] -> element)
                cout << i  << " ";
        cout << endl;
    }

     void ShowAdjacencyList(){
        // display adjacency list
        // cout << "Showing adjancents for all vetices" << endl;
        for(int i = 0; i < vertices.size(); i++){
            if(vertices[i] -> isCell){
                cout << "Vertex " << i << "'s adjacents: ";
                for(int j = 0; j < vertices[i] -> adjacencyList.size(); j++)
                    cout << vertices[i] -> adjacencyList[j] -> element << " ";
            }else{
                cout << "Vertex i " << i << " is a wall";
            }
            cout << endl;
        }
    }

    void ShowEdgeList(){
        // display edge list
        for (int i = 0; i < edgeList.size(); i++)
            cout << "(" << edgeList[i] -> u -> element << "," << edgeList[i] -> v -> element << ") ";
        cout << endl;
    }

    // checks if there's a path from (0,0) to (col - 1, row - 1)
    bool checkPath(){
        if(vertices[0] && vertices[0] -> isCell && vertices[numOfRows * numOfColumns - 1] && vertices[numOfRows * numOfColumns - 1] -> isCell){
            // map<int, bool>* m = new map<int,bool>();
            vector<bool>* visited = new vector<bool>();
            queue<Vertex*>* q = new queue<Vertex*>();
            visited -> resize(numOfRows * numOfColumns);
            visited -> at(0) = true;
            q -> push(vertices[0]);
            bool found = false;
            findExit(vertices[0], visited, q, found);
            // delete m;
            delete visited, q;
            return found;
        }
        else if(!vertices[0] || !vertices[0] -> isCell)
            cout << "(0,0) is not a cell" << endl;
        else
            cout << "("<< numOfColumns - 1 << "," << numOfRows - 1 <<") is not a cell" << endl; 
    }

    // Helper function of checkPath using BFS
    void findExit(Vertex* current, vector<bool>* visited, queue<Vertex*>* q, bool &found){
        if(!current)
            return;
        for(Vertex* v : current -> adjacencyList){
            if(v == vertices[numOfRows * numOfColumns - 1]){
                found = true;
                return;
            }
            if(!visited -> at(v -> element)){
                visited -> at(current -> element) = true;
                q -> push(v);
            }
        }
        if(!q->empty()){
            q -> pop();
            findExit(q->front(), visited, q, found);
        }
    }
};



#endif