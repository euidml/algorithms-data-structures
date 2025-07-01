
#include <iostream>
#include <vector>
#include "Graph.h"
using namespace std;
// class Vertex{
//     public:
//         int element;
//         bool isCell;
//         vector<Vertex *> adjacencyList;

//     Vertex(){
//         element = -1;
//         isCell = false;
//         adjacencyList = vector<Vertex *>();
//     }

//     Vertex(int _element, bool _isCell){
//         element = _element;
//         isCell = _isCell;
//         adjacencyList = vector<Vertex *>();
//     }
// };
// class Edge{
// public:
//     // assume u and v are two vertices 
//     // vertices are zero-indexed
//     Vertex* u;
//     Vertex* v;

//     Edge(){
//         u = new Vertex(); // invalid vertex index
//         v = new Vertex(); // invalid vertex index
//     }

//     Edge(Vertex* _u, Vertex* _v){
//         u = _u;
//         v = _v;
//     }
// };



int main(){
    /**
     * @brief Given a maze (n x n 2D array of unsigned ints) where paths 
     * are marked with non-zero numbers and walls are 
     * marked with zeroes; output true/1 if there exists 
     * a path from the top-left corner (row 0, column 0) to the 
     * bottom-right corner (row n-1, column n-1) of the maze; if no path 
     * exists then output false/0.
     * 
     * In the maze shown above (4 x 4) there are 2 such paths.
     * 
     * If the top-left corner cell contains a zero in any maze then there 
     * can be no paths in that maze.     * 
     * 
     * Formulate the problem as a graph (vertices, edges).
     * Use graph algorithms (bfs, dfs) to solve the problem.
     * 
     * Thoroughly test your code - generate random mazes to validate your 
     * code. Try other values for n. You may limit your tests to unsigned 
     * int type square 2d arrays.
     * 
     * Feel free to use any Graph related code provided on D2L. 
     */

    /**
     * 
     * Modify the array here
     * 
     */
    
    // unsigned int maze[4][4] = {
    //             {1,1,1,1},
    //             {0,1,0,1},
    //             {0,1,0,0},
    //             {0,1,0,1}
    //             };

    // possible case 5 * 5
    // unsigned int maze[5][5] = {
    //             {1,1,1,1,1},
    //             {0,0,0,0,1},
    //             {1,1,1,1,1},
    //             {1,0,0,0,0},
    //             {1,1,1,1,1}
    //             };

    // fail case - 5 * 5
    // unsigned int maze[5][5] = {
    //             {1,1,1,1,1},
    //             {0,1,0,1,1},
    //             {0,1,0,0,0},
    //             {0,1,1,1,0},
    //             {0,1,0,0,1}
    //             };

    // false because there's no path(no corner exists)
    // unsigned int maze[1][1] = {{1}};

    //formulated by chat gpt
    unsigned int maze[10][10] = {
            {1, 0, 1, 1, 1, 1, 1, 1, 1, 1},
            {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
            {1, 1, 1, 1, 1, 1, 0, 1, 1, 1},
            {1, 1, 0, 0, 0, 1, 0, 1, 0, 1},
            {1, 1, 0, 1, 1, 1, 1, 1, 0, 1},
            {1, 1, 0, 1, 0, 0, 0, 1, 0, 1},
            {1, 1, 1, 1, 0, 1, 1, 1, 0, 1},
            {1, 0, 0, 0, 0, 1, 0, 0, 0, 1},
            {1, 0, 1, 1, 1, 1, 0, 1, 0, 1},
            {1, 1, 1, 0, 0, 1, 1, 1, 0, 1}
    };

    // transform the static array maze into dynamic array
    const int numOfRows = sizeof(maze) / sizeof(maze[0]);
    const int numOfColumns = sizeof(maze[0]) / sizeof(maze[0][0]);
    cout << numOfRows << endl;
    unsigned int** temp = new unsigned int *[numOfRows];
    for(int i = 0; i < numOfRows; i++){
        temp[i] = new unsigned int[numOfColumns];
        for(int j = 0; j < numOfColumns; j++)
            temp[i][j] = maze[i][j];
    }

    cout << "I'm here" << endl;

    Graph path(temp, numOfRows, numOfColumns);
    

    cout << "\nShowing Cells only: " << endl;
    path.ShowVertices();
    // showing AdjancyList
    cout << "\nShowing adjancents for all vetices" << endl;
    path.ShowAdjacencyList();

    // showing edges
    cout << "\nShowing all edges:" << endl;
    path.ShowEdgeList();

    // Showing map manipulated from vetices list:
    cout << "\nShowing map: " << endl;
    path.ShowMap();
    cout <<"Is there path from (0,0) to ("<< numOfColumns - 1 << "," << numOfRows - 1 <<")?: " << boolalpha << path.checkPath() << endl;
    // delete temp - dynamic array
    for(int i = 0; i < numOfRows; i++)
        if(temp[i])
            delete temp[i];
    delete temp;

    return 0;

    
}