/**************************************************************************
 *
 * Успешная попытка: 83352796
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


#include <iostream>
#include <limits>
#include <stack>
#include <fstream>
#include <sstream>
#include <vector>
#include <queue>



#ifdef MY_IDE
#define out fout
#define in fin
#else
#define out std::cout
#define in std::cin
#endif

std::ifstream fin("in.txt");
std::ofstream fout("out.txt");





class Neighbour
{

public:

    int index = 0;
    int weight = std::numeric_limits<int>::min();

    struct Compare
    {
    public:
        bool operator()(Neighbour & neighbour1, Neighbour & neighbour2)
        {
            return neighbour2.weight > neighbour1.weight;
        }
    };

    static Neighbour make(const int& index, const int& weight)
    {
        Neighbour result;

        result.index = index;
        result.weight = weight;

        return result;
    }
};








class Vertex
{

public:

    int index = 0;
    std::priority_queue<Neighbour, std::vector<Neighbour>, Neighbour::Compare> neighbours;

    Vertex() {}
    ~Vertex() {}

    Vertex(const int& index)
    {
        this->index = index;
    }

    void addNeighbour(const int& neighbour, const int& neighbourWeight)
    {
        this->neighbours.push(Neighbour::make(neighbour, neighbourWeight));
    }

    friend std::ostream& operator << (std::ostream& outStream, const Vertex& vertex)
    {
        Vertex temp = vertex;
        outStream << temp.index << std::endl;
        if (temp.neighbours.size())
        {
            while (temp.neighbours.size())
            {
                auto n = temp.neighbours.top();
                temp.neighbours.pop();
                outStream << "(" << temp.index << " -> " << n.index << " : " << n.weight << ") ";
            }
            outStream << std::endl;
        }

        return outStream;
    }
};



class Graph
{

private:

    const int _start = 1;
    int _end = 0;

    Vertex * _V;
    bool * _colors;

public:

    Graph() = delete;
    ~Graph() {}

    Graph(const int& n)
    {
        this->_end = n + 1;

        this->_V = new Vertex[this->_end];
        this->_colors = new bool[this->_end];

        for (int i = this->_start; i < this->_end; i++) this->_V[i].index = i;

        _resetColors();
    }

    void print()
    {
        for (int i = this->_start; i < this->_end; i++) out << this->_V[i];
        out << "--------" << std::endl;
    }

    void addVertex()
    {
        int v1, v2, w;
        in >> v1 >> v2 >> w;

        this->_V[v1].addNeighbour(v2, w);
        this->_V[v2].addNeighbour(v1, w);
    }

    int MST()
    {
        int resultMST = std::numeric_limits<int>::min();

        for (int i = this->_start; i < this->_end; i++)
        {
            this->_resetColors();
            resultMST = std::max(resultMST, this->_MST(i));
        }

        return resultMST;
    }

private:

    void _resetColors()
    {
        for (int i = this->_start; i < this->_end; i++)
        {
            this->_colors[i] = true;
        }
    }

    int _MST(int index)
    {
        int sumWeight = 0;

        while (1)
        {
            bool noNeighbour = true;

            //std::cout << index << std::endl;
            this->_colors[index] = false;

            auto neighbours = this->_V[index].neighbours;

            while (neighbours.size())
            {
                auto neighbour = neighbours.top();
                neighbours.pop();

                if (this->_colors[neighbour.index])
                {
                    index = neighbour.index;
                    sumWeight += neighbour.weight;
                    noNeighbour = false;
                    break;
                }
            }

            if (noNeighbour) break;
        }

        return sumWeight;
    }
};



int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, m;

    in >> n >> m;

    Graph graph(n);

    while (m-- > 0)
    {
        graph.addVertex();

        //graph.print();
    }

    int MST = graph.MST();

    out << (MST ? std::to_string(MST) : "Oops! I did it again") << std::endl;

    return 0;
}