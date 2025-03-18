#include <string>

class Graph {
  private:
    int numVertices;
    int numEdges;
    int startVertex;
    std::vector<std::vector<int>> adj;

  public:
    Graph(): numVertices(0), numEdges(0) {}

    void parseDataFromFile(const std::string &filename);

    std::vector<int> bfs() const;

    ~Graph() {};
};