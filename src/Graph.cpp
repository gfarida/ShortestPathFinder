#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <fstream>

#include "../include/Graph.h"

void Graph::parseDataFromFile(const std::string &filename) {
    std::ifstream fin(filename);

    if (!fin.is_open()) {
        throw std::runtime_error("Unable to open file : " + filename);
    }

    fin >> numVertices;
    fin >> numEdges;

    adj.assign(numVertices, {});

    int u, v;
    for (int i = 0; i < numEdges; ++i) {
        fin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    fin >> startVertex;

    fin.close();
}

std::vector<int> Graph::bfs() const {
    std::vector<int> distance(numVertices, -1);
    std::vector<bool> visited(numVertices, false);
    std::queue<int> q;

    visited[startVertex] = true;
    distance[startVertex] = 0;
    q.push(startVertex);

    while (!q.empty()) {
        int s = q.front();
        q.pop();

        for (auto u: adj[s]) {
            if (!visited[u]) {
                visited[u] = true;
                distance[u] = distance[s] + 1;
                q.push(u);
            }
        }
    }

    return distance;
}   