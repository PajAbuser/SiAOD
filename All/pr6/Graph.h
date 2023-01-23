#ifndef PR5_GRAPH_H
#define PR5_GRAPH_H

#include <bits/stdc++.h>

using namespace std;

struct Graph {

    struct Vertex {
        int val;
        Vertex(int val): val(val) {}
        Vertex() {}
    };

    struct Edge {
        Vertex* from;
        Vertex* to;
        int weight;
        Edge(Vertex* from, Vertex* to, int weight): from(from), to(to), weight(weight) {}
        Edge() {}
    };

    const int INF = 1000;

    vector<Vertex*> vertices;

    vector<Edge*> edges;

    vector<vector<int>> incMatrix { {0} };

    int find(Vertex* vertex) {
        for(int i = 0; i < vertices.size(); i++) {
            if(vertices[i] == vertex) return i;
        }
        return -1;
    }

    void addVertex(Vertex* vertex) {
        vertices.push_back(vertex);
    }

    void addEdge(Edge* edge) {
        edges.push_back(edge);
    }


    void print(){
        for(int i = 0; i < vertices.size(); i++) {
            incMatrix.emplace_back();
            for(int j = 0; j < vertices.size(); j++) {
                incMatrix[i].push_back(0);
            }
        }
        cout << "     ";
        for(int i = 0; i < vertices.size(); i++) cout << setw(4) << i << " ";
        cout << endl;
        cout << "     ";
        for(int i = 0; i < vertices.size(); i++) cout << setw(4) << "   - ";
        cout << endl;
        for(int j = 0; j < vertices.size(); j++) {
            cout << j << ": | ";
            for(int i = 0; i < vertices.size(); i++) {
                if(i == j) incMatrix[j][i] = INF;
                for(int k = 0; k < edges.size(); k++) {
                    if(edges[k]->from == vertices[j] && edges[k]->to == vertices[i]) {
                        incMatrix[j][i] = edges[k]->weight;
                    }
                    else if(edges[k]->from == vertices[i] && edges[k]->to == vertices[j]) {
                        incMatrix[j][i] = edges[k]->weight;
                    }
                }
                cout << fixed << setw(4) << incMatrix[j][i] << " ";
            }
            cout << endl << endl;
        }
    }

    void Prims() {
        int n = vertices.size();
        vector<bool> used(n);
        vector<int> min_e(n, INF), sel_e(n, -1);
        min_e[0] = 0;
        for (int i = 0; i < n; ++i) {
            int v = -1;
            for (int j = 0; j < n; ++j)
                if (!used[j] && (v == -1 || min_e[j] < min_e[v]))
                    v = j;
            if (min_e[v] == INF) {
                cout << "No MST!";
                exit(0);
            }

            used[v] = true;
            if (sel_e[v] != -1)
                cout << v << " " << sel_e[v] << endl;

            for (int to = 0; to < n; ++to)
                if (incMatrix[v][to] < min_e[to]) {
                    min_e[to] = incMatrix[v][to];
                    sel_e[to] = v;
                }
        }
    }

    int minKey(vector<int> key, vector<bool> mstSet){
        int min = INF, min_index;
        for (int v = 0; v < vertices.size(); v++)
            if (mstSet[v] == false && key[v] < min)
                min = key[v], min_index = v;
        return min_index;
    }

    void printMST(vector<int> parent, int n, vector<vector<int>> graph){
        cout << "Edge \tWeight \n";
        for (int i = 1; i < vertices.size(); i++)
            cout << parent[i] << " - " << i << " \t" << graph[i][parent[i]] << " \n";
    }

    void PrimMST(){
        vector<int> parent(vertices.size());
        vector<int> key(vertices.size());
        vector<bool> mstSet(vertices.size());
        for (int i = 0; i < vertices.size(); i++)
            key[i] = INF, mstSet[i] = false;
        key[0] = 0;
        parent[0] = -1;
        for (int count = 0; count < vertices.size() - 1; count++) {
            int u = minKey(key, mstSet);
            mstSet[u] = true;
            for (int v = 0; v < vertices.size(); v++)
                if (incMatrix[u][v] && mstSet[v] == false && incMatrix[u][v] < key[v])
                    parent[v] = u, key[v] = incMatrix[u][v];
        }
        printMST(parent, vertices.size(), incMatrix);
    }

    void generate(int n){
        for(int i = 0; i < n; i++) {
            addVertex(new Vertex(i));
        }
        int m = rand() % n;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < m; j++) {
                if(i != j) {
                    addEdge(new Edge(vertices[i], vertices[j], rand() % 100));
                }
            }
        }
    }

};

#endif
