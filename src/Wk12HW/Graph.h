#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <fstream>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <climits>

#include <sstream>

using namespace std;

class Vertex
{
public:
    string name; // name of current location
    map<string, int> neighbors; // Neighboring locations and their distances

    Vertex()
    {
        name = "n/a";
    }

    Vertex(string &_name){
        if(name.length() != 0)
            name = _name;
        else
            Vertex();
    }
    void AddNeighbor(string n, int d)
    {
        // add a neighbor (with name n and distance d) to neighbors
        if(n.length() != 0 && d >= 0)
            neighbors[name] = d;
    }
};

class Graph
{
private:
    map<string, Vertex> locations; // all cities and their neighbors (i.e. adjacencies) in the graph    

public:
    Graph()
    {
    }

    Graph(string file = "distances.txt"){
        if(file == ""){
            return;
        }

        // Read road network data from a file
        ifstream inputFile(file);
        if (!inputFile) {
            cout << "Error: Unable to open input file." << endl;
            return;
        }

        // Parse the input file
        string sourceLocation, destLocation;
        int distance;
        while (inputFile >> sourceLocation >> destLocation >> distance) {
            locations[sourceLocation].name = sourceLocation;
            locations[destLocation].name = destLocation;
            locations[sourceLocation].neighbors[destLocation] = distance;
        }
        inputFile.close();
    }

    void ShowLocationInfo(){
        cout << "Locations:" << endl;
        for (const auto& pair : locations) {
            cout << pair.first << ": ";
            for (const auto& neighbor : pair.second.neighbors) {
                cout << neighbor.first << "(" << neighbor.second << "), ";
            }
            cout << endl;
        }        
    }

    void Dijkstra(string source, string dest){
        // check if source and dest exists
        if(locations.find(source) == locations.end() || locations.find(dest) == locations.end()){
            cout << "\ncity(s) is(are) not exist" << endl;
            return;
        }
        // check if they are same
        if(source == dest){
            cout << "\nsame cites" <<endl;
            return;
        }
        //data members here
        map<string, int> dist;
        map<string, string> prev;
        auto comp = [&dist](string left, string right){
            return dist[left] > dist[right];
        };
        priority_queue<string, vector<string>, decltype(comp)> q(comp);
        //set up    
        for(auto& pair:locations){
            dist[pair.first] = INT_MAX;
            prev[pair.first] = "";
        }
        q.push(source);
        dist[source] = 0;
        // searching - BFS by priority queue
        while(!q.empty()){
            auto current = q.top();
            q.pop();
            int temp = 0;
            for(const auto& neighbor : locations[current].neighbors){
                int temp = dist[current] + neighbor.second;
                if(temp < dist[neighbor.first]){
                    dist[neighbor.first] = temp;
                    prev[neighbor.first] = current;
                    q.push(neighbor.first);
                }
            }
        }
        // showing result
        if(dist[dest] != INT_MAX){
            string current = dest;
            int total = dist[dest];
            stack<string> s;
            while(current != source){
                s.push(current);
                current = prev[current];
            }
            cout << "\nShortest Route from " << source << " to " << dest << ":" << endl;
            cout << "Distance: " << total << " kilometers" << endl;
            cout << source;
            while(!s.empty()){
                cout << " -> "<< s.top();
                s.pop();
            }
            cout << endl;
        }else{
            cout << "\nNo route exists for the given locations." << endl;
        }
    }

    void Search(){
        string source, dest, temp;
        cout << "\nEnter the source location: ";
        cin >> source;
        cout << "Enter the destination location(s): ";
        cin >> dest;
        
        stringstream ss(dest);
        while(getline(ss, temp, ',')){
            Dijkstra(source, temp);
        }
    }

};

#endif