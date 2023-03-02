/**************************************************************************
 *
 * Успешная попытка: 79877153
 *
 * -- ПРИНЦИП РАБОТЫ --
 *
 *
 * -- ДОКАЗАТЕЛЬСТВО КОРРЕКТНОСТИ --
 *
 *
 * -- ВРЕМЕННАЯ СЛОЖНОСТЬ --
 *
 *
 * -- ПРОСТРАНСТВЕННАЯ СЛОЖНОСТЬ --
 *
 *
 *************************************************************************/

#define MY_IDE

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

std::ifstream fin("in.txt");
std::ofstream fout("out.txt");

class Graph
{
private:

    int _vertices = 0;
    int _edges = 0;
    std::vector<std::vector<int>> _matrix;
    std::vector<int> _colors;

public:

    Graph(const int & vertices, const int & edges)
    {
        this->_vertices = vertices;
        this->_edges = edges;
        for(int i = 0; i < this->_vertices; i++) 
        {
            std::vector<int> raw;
            for(int j = 0; j < this->_vertices; j++) raw.push_back(0);
            this->_matrix.push_back(raw);
            this->_colors.push_back(0);
        }
    }

    ~Graph() { _matrix.clear(); }

    void DFS(int start)
    {

    }

    friend std::istream& operator >> (std::istream& inStream, Graph& graph) 
    { 
        int edges = graph._edges;
        while (edges--)
        {
            int v1, v2;
            inStream >> v1 >> v2;
            graph._matrix[v1 - 1][v2 - 1] = 1;
            graph._matrix[v2 - 1][v1 - 1] = 1;
        }
        return inStream; 
    }

    friend std::ostream& operator << (std::ostream& outStream, Graph& graph) 
    { 
        for(auto raw : graph._matrix)
        {
            for(auto elem : raw) outStream << elem << " ";
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
    out << graph;
    
    int start;
    in >> start;
    start--;


    //for (int i = 0; i < n; i++)
    //{
    //    for (int j = 0; j < n; j++) out << mas[i][j] << " ";
    //    out << std::endl;
    //}
        
    //out << std::endl;

    // while (1)
    // {
    //     //for (int i = 0; i < n; i++) out << color[i] << " ";
    //     //out << std::endl;

    //     if (color[s]) break;

    //     out << s + 1 << " ";
    //     color[s] = 1;

    //     for (int i = 0; i < n; i++)
    //     {
    //         if (mas[s][i] && !color[i])
    //         {
    //             s = i;
    //             break;
    //         }
    //     }
    // }

    return 0;
}
