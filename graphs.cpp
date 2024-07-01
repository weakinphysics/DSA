#include <bits/stdc++.h>

using namespace std;

class Graph{
    class Disjoint_set{

    };
    int vertexCount;
    vector <vector<int>> edges;
    vector <vector<int>> adj;
    vector <vector<int>> mat;
    vector <vector<int>> incidence;

    Graph(){
        // empty constructor 
    }

    Graph(int n, vector <vector<int>> &edges){
        // this feeds the edges and the vertices
    }
    Graph(Graph &x){
        // copy constructor
    }

    vector <int> singleSourceShortestPaths(int source){
        vector <int> distances;
        return distances;
    }

    vector <vector<int>> stronglyConnectedComponents(){
        // implements Kosaraju
        vector <vector<int>> sccs;
        return sccs;
    }

    vector <vector<int>> MST(){
        // implements Prim's algorithm
        vector <vector<int>> edges;
        return edges;
    }

    vector <vector<int>> allPairsShortestPaths(){
        // implements Floyd-Warshall
        vector <vector<int>> distances;
        return distances;
    }

    vector <int> articulationPoints(){
        // implements articulation points;
        vector <int> choke;
        return choke;
    }

    vector <vector<int>> cutSet(){
        vector <vector<int>> selection;
        return selection;
    }

    bool checkBipartite(){
        return false;
    }

    int coloring(){
        return 0;
    }
};



int main(){
    cout<<"Hello"<<endl;
    return 0;
}