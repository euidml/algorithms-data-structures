#include <iostream>
#include "Graph.h"
using namespace std;

int main(){
    // bool mat1[2][2] = { {0,1},
    //                     {1,0}
    //                     };

    const int lenConst = 4;
    bool temp1[lenConst][lenConst] = { 
                        {0,1,0,1},
                        {1,0,1,0},
                        {0,1,0,1},
                        {1,0,1,0}
                        };
    bool temp2 [lenConst][lenConst] = { 
                        {0,1,0,1},
                        {1,0,1,0},
                        {0,0,0,1},
                        {0,0,0,0}
                        };
    bool temp3 [lenConst][lenConst] = {
                        {0,1,0,0},
                        {1,0,1,0},
                        {1,0,0,0},
                        {0,0,0,0}
                        };

    cout << "\n***temp1***\n" << endl;
    Graph graphTemp1(temp1, lenConst);
    graphTemp1.ShowVertices();
    cout << "\nNumber of Vertices: " << graphTemp1.VertexCount() << endl;
    graphTemp1.ShowAdjacencyList();
    cout << "\nNumber of Edges: " << graphTemp1.EdgeCount() << endl;
    graphTemp1.ShowEdgeList();
    cout << "\nIs this graph directed?: " << boolalpha << graphTemp1.IsDirected() << endl; 
    
    cout << "\nShowing neighbours of a vertex for all vertices:" << endl;
    for(int i = 0; i < lenConst; i++)
        graphTemp1.ShowNeighbors(i);
    cout << "Testing 5 which is out of bound: "; graphTemp1.ShowNeighbors(5); 
    cout << "\nShowing number of degrees of a vertex for all vertices:" << endl;
    for(int i = 0; i < lenConst; i++)
        cout << "Number of degrees of vertex " << i << ": " << graphTemp1.Degree(i);
    cout << "Testing 5 which is out of bound: " <<  graphTemp1.Degree(5) << endl; 
    cout << "\nShowing length of paths between two vertices for all vertices:" << endl;
    for(int i = 0; i < lenConst; i++)
        for(int j = 0; j < lenConst; j++)
            cout << "Length of path between vertex " << i <<" and " << j << ": " << graphTemp1.Path(i,j) << endl;
    cout << "\nShowing if there is an edge between two vertices for all vertices:" << endl;
    for(int i = 0; i < lenConst; i++)
        for(int j = 0; j < lenConst; j++)
            cout << "Is there edge between vertex " << i <<" and " << j << "?: " << graphTemp1.HasEdge(i,j) << endl;
    cout << "\nShowing if this graph has any cycle in it : " << boolalpha << graphTemp1.HasCycle() << endl;
    cout << "\nShowing all possible cycles: " << endl;
    graphTemp1.ShowCycles();

    cout << "\n***temp2***\n" << endl;
    Graph graphTemp2(temp2, lenConst);
    graphTemp2.ShowVertices();
    cout << "\nNumber of Vertices: " << graphTemp2.VertexCount() << endl;
    graphTemp2.ShowAdjacencyList();
    cout << "\nNumber of Edges: " << graphTemp2.EdgeCount() << endl;
    graphTemp2.ShowEdgeList();
    cout << "\nIs this graph directed?: " << boolalpha << graphTemp2.IsDirected() << endl; 
    
    cout << "\nShowing neighbours of a vertex for all vertices:" << endl;
    for(int i = 0; i < lenConst; i++)
        graphTemp2.ShowNeighbors(i);
    cout << "\nShowing number of degrees of a vertex for all vertices:" << endl;
    for(int i = 0; i < lenConst; i++)
        cout << "Number of degrees of vertex " << i << ": " << graphTemp2.Degree(i);
    cout << "\nShowing length of paths between two vertices for all vertices:" << endl;
    for(int i = 0; i < lenConst; i++)
        for(int j = 0; j < lenConst; j++)
            cout << "Length of path between vertex " << i <<" and " << j << ": " << graphTemp2.Path(i,j) << endl;
    cout << "\nShowing if there is an edge between two vertices for all vertices:" << endl;
    for(int i = 0; i < lenConst; i++)
        for(int j = 0; j < lenConst; j++)
            cout << "Is there edge between vertex " << i <<" and " << j << "?: " << graphTemp2.HasEdge(i,j) << endl;
    cout << "\nShowing if this graph has any cycle in it : " << boolalpha << graphTemp2.HasCycle() << endl;
    cout << "\nShowing all possible cycles: " << endl;
    graphTemp2.ShowCycles();

    cout << "\n***temp3***\n" << endl;
    Graph graphTemp3(temp3, lenConst);
    graphTemp3.ShowVertices();
    cout << "\nNumber of Vertices: " << graphTemp3.VertexCount() << endl;
    graphTemp3.ShowAdjacencyList();
    cout << "\nNumber of Edges: " << graphTemp3.EdgeCount() << endl;
    graphTemp3.ShowEdgeList();
    cout << "\nIs this graph directed?: " << boolalpha << graphTemp3.IsDirected() << endl; 
    
    cout << "\nShowing neighbours of a vertex for all vertices:" << endl;
    for(int i = 0; i < lenConst; i++)
        graphTemp3.ShowNeighbors(i);
    cout << "\nShowing number of degrees of a vertex for all vertices:" << endl;
    for(int i = 0; i < lenConst; i++)
        cout << "Number of degrees of vertex " << i << ": " << graphTemp3.Degree(i);
    cout << "\nShowing length of paths between two vertices for all vertices:" << endl;
    for(int i = 0; i < lenConst; i++)
        for(int j = 0; j < lenConst; j++)
            cout << "Length of path between vertex " << i <<" and " << j << ": " << graphTemp3.Path(i,j) << endl;
    cout << "\nShowing if there is an edge between two vertices for all vertices:" << endl;
    for(int i = 0; i < lenConst; i++)
        for(int j = 0; j < lenConst; j++)
            cout << "Is there edge between vertex " << i <<" and " << j << "?: " << graphTemp3.HasEdge(i,j) << endl;
    cout << "\nShowing if this graph has any cycle in it : " << boolalpha << graphTemp3.HasCycle() << endl;
    cout << "\nShowing all possible cycles: " << endl;
    graphTemp3.ShowCycles();
    
    
    return 0;
}
