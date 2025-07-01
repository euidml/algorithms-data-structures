#include "./Graph.h"
#include <iostream>

using namespace std;

int main(){
    Graph g("distances3.txt");

    g.ShowLocationInfo();

    // tested to find no route exist between two existing cities and it worked.
    g.Search();

    return 0;
}