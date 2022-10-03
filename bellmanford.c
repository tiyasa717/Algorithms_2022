#include<bits/stdc++.h>
using namespace std;
#define N 1000001

vector<array<int,3>> adj;

int dist[N];

void Bellmanford(int V , int E , int S) {

    for(int i =0 ; i < V ; i++) {
        dist[i] = INT_MAX;
    }

    dist[S] = 0;

    for (int i = 0; i < V - 1; i++) {

        for (int j = 0; j < E; j++) {
            if (dist[adj[j][0]] != INT_MAX && dist[adj[j][0]] + adj[j][2] < dist[adj[j][1]])
                dist[adj[j][1]] = dist[adj[j][0]] + adj[j][2];
        }
    }

    for (int i = 0; i < E; i++) {
        int x = adj[i][0];
        int y = adj[i][1];
        int w = adj[i][2];
        if (dist[x] != INT_MAX && dist[x] + w < dist[y]){
            cout << "Graph contains negative weight cycle\n";
            break;
        }
    }
}

int main() {

    int n , m;
    cout << "Enter No of vertices: ";
    cin >> n ;
    cout << "Enter No of Edges: ";
    cin >> m;

    cout << "Enter Edges(u , v , w) : \n";

    for(int i =0 ;i < m ; i++) {
        int x , y , w;
        cin >> x >> y >> w;
        adj.push_back({x , y , w});
    }

    cout << "Enter Source: ";
    int s;
    cin >> s;

    Bellmanford(n , m , s);


    cout << "Vertex Distance from the Source 0 is\n";
    cout << "Vertex        Distance\n";
    cout <<"----------------------\n";
    for(int i = 0 ; i < n ; i++) {
        cout << i <<"           "<< dist[i] << "\n";
    }

} 
