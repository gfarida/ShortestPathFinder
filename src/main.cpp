#include <iostream>
#include <vector>

#include "../include/Graph.h"

int main(int argc, char **argv) {
    try {
        if (argc != 2) {
            throw std::invalid_argument("Usage: ./minPathLen path_to_graph_file");
            return 1;
        }
    
        Graph g;
        g.parseDataFromFile(argv[1]);
    
        std::vector<int> distance = g.bfs();
    
        for (size_t i = 0; i < distance.size(); ++i) {
            std::cout << distance[i] << std::endl;
        }
    } catch (const std::exception &e) {
        std::cerr << "Error! " << e.what() << std::endl;
        return 1;
    }

    return 0;
}