
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

#ifdef MY_IDE
#define out fout
#define in fin
#else
#define out std::cout
#define in std::cin
#endif

std::ifstream fin("../in.txt");
std::ofstream fout("../out.txt");

class Graph
{
private:

    int _vertices = 0;
    int _edges = 0;
    std::vector<std::vector<int>> _matrix;
    std::vector<int> _colors;

    std::vector<std::vector<int>> _list;

public:

    Graph(const int& vertices, const int& edges)
    {
        this->_vertices = vertices;
        this->_edges = edges;
        for (int i = 0; i < this->_vertices; i++)
        {
            std::vector<int> raw;
            //for (int j = 0; j < this->_vertices; j++) raw.push_back(0);
            //this->_matrix.push_back(raw);
            this->_list.push_back(raw);
            this->_colors.push_back(0);
        }
    }

    ~Graph() {}

    void DFS(int start)
    {
        //std::cout << "DFS\n";
        this->_colors[start] = 1;
        out << start + 1 << " ";
        //std::cout << "start = " << start << "\n";

        //for (auto c : this->_colors) std::cout << c << " ";
        //std::cout << std::endl;

        for (auto elem : this->_list[start])
        {
            //int elem = this->_list[start][i];
            //std::cout << "_matrix[" << start << "][" << i << "] = " << elem << "\n";
            if (!this->_colors[elem])
                DFS(elem);

        }
    }

    friend std::istream& operator >> (std::istream& inStream, Graph& graph)
    {
        int edges = graph._edges;
        while (edges--)
        {
            int v1, v2;
            inStream >> v1 >> v2;
            graph._list[v1 - 1].push_back(v2 - 1);
            graph._list[v2 - 1].push_back(v1 - 1);
        }

        for (auto it = graph._list.begin(); it < graph._list.end(); it++)
            std::sort((*it).begin(), (*it).end());

        return inStream;
    }

    friend std::ostream& operator << (std::ostream& outStream, Graph& graph)
    {
        int count = 0;
        for (auto raw : graph._list)
        {
            outStream << count++ << " : ";
            for (auto elem : raw) outStream << elem << " ";
            outStream << std::endl;
        }
        return outStream;
    }
};



int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, m;
    in >> n >> m;

    Graph graph(n, m);
    in >> graph;
    //std::cout << graph;

    int start;
    in >> start;
    start--;

    graph.DFS(start);

    return 0;
}
