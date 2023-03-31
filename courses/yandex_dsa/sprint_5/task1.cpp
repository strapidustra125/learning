/**************************************************************************
 *
 * Успешная попытка: 83352796
 *
 * -- ПРИНЦИП РАБОТЫ --
 *
 *  Класс Member для описания участников: поддерживает операции вывода в
 * поток и операцию "больше".
 *
 *  Шаблонный класс Heap реализует кучу. Шаблон использовался для отладки
 * на int'ах. Объект хранит в себе массив и перетряхивает его с помощью
 * _siftUp при добавлении элемента через push и с помощью _siftDown при
 * удалении элемента через pop.
 *
 * -- ДОКАЗАТЕЛЬСТВО КОРРЕКТНОСТИ --
 *
 *  Задача - вывести массив, отсортированный кучей. Достигаеся это путем
 * изъятия элемента с верха кучи: он всегда будет максимумом среди текущих
 * элементов кучи.
 *
 * -- ВРЕМЕННАЯ СЛОЖНОСТЬ --
 *
 *  Сложность _siftDown и _siftUp не превышает высоты кучи -  O(logn).
 * Соответственно вставка - это O(n * log(n)), изъятие - тоже
 * => O(2 * n * log(n)) = O(n*log(n)), где n - количество участников.
 *
 * -- ПРОСТРАНСТВЕННАЯ СЛОЖНОСТЬ --
 *
 *  Хранится массив за O(n), где n - количество участников.
 *
 *************************************************************************/

#include <iostream> 
#include <fstream> 
#include <string> 
#include <sstream> 
#include <vector> 
#include <limits>

#ifdef MY_IDE 
#define out fout 
#define in fin 
#else 
#define out std::cout 
#define in std::cin 
#endif 

std::ifstream fin("in.txt");
std::ofstream fout("out.txt");

class Member
{

private:

    std::string _name = "";
    int _tasks = std::numeric_limits<int>::min();
    int _fine = std::numeric_limits<int>::min();

public:

    Member() {}

    ~Member() {}

    bool operator > (const Member& member)
    {
        if (this->_tasks != member._tasks) return this->_tasks > member._tasks;
        if (this->_fine != member._fine) return this->_fine < member._fine;
        return this->_name.compare(member._name) < 0;
    }

    friend std::ostream& operator << (std::ostream& outStream, const Member& member)
    {
        outStream << member._name;
        return outStream;
    }

    friend std::istream& operator >> (std::istream& inStream, Member& member)
    {
        std::string line;
        std::getline(in, line);

        std::stringstream ss(line);
        ss >> member._name >> member._tasks >> member._fine;

        return inStream;
    }
};

template <typename T>
class Heap
{
public:

    const int start = 0;

private:

    std::vector<T> _mas;

public:

    Heap() {}
    ~Heap() {}

    int size();

    void print();

    void push(const T& member);
    T pop();

private:

    int _parent(const int& i);
    int _left(const int& i);
    int _right(const int& i);

    void _siftUp(int index);
    void _siftDown(int index);
};


template <typename T>
int Heap<T>::size()
{
    return this->_mas.size();
}


template <typename T>
void Heap<T>::print()
{
    out << "-------" << std::endl;
    for (int i = this->start; i < this->size(); i++)
    {
        out << i << " " << _mas[i] << std::endl;
    }
    out << "-------" << std::endl;
}


template <typename T>
void Heap<T>::push(const T& member)
{
    this->_mas.push_back(member);
    this->_siftUp(this->size() - 1);
}


template <typename T>
T Heap<T>::pop()
{
    T result = this->_mas[this->start];

    std::swap(this->_mas[this->start], this->_mas[this->size() - 1]);
    this->_mas.pop_back();

    if(this->size()) this->_siftDown(this->start);

    return result;
}


template <typename T>
int Heap<T>::_parent(const int& i)
{
    if (!i) return -1;
    return i / 2 - (1 - i % 2);
}


template <typename T>
int Heap<T>::_left(const int& i)
{
    int child = i * 2 + 1;
    if (child >= this->size()) return -1;
    else return child;
}


template <typename T>
int Heap<T>::_right(const int& i)
{
    int child = i * 2 + 2;
    if (child >= this->size()) return -1;
    else return child;
}


template <typename T>
void Heap<T>::_siftUp(int index)
{
    while (1)
    {
        int p = this->_parent(index);

        if (!(p != -1 && this->_mas[index] > this->_mas[p])) break;

        std::swap(this->_mas[p], this->_mas[index]);
        index = p;
    }
}


template <typename T>
void Heap<T>::_siftDown(int index)
{
    while (1)
    {
        int l = this->_left(index);
        int r = this->_right(index);

        T min_member;

        T l_val = (l == -1 ? min_member : this->_mas[l]);
        T r_val = (r == -1 ? min_member : this->_mas[r]);
        T index_val = this->_mas[index];

        int max_index;

        max_index = (l_val > index_val ? l : index);
        max_index = (r_val > this->_mas[max_index] ? r : max_index);

        if (!(this->_mas[max_index] > this->_mas[index])) break;
        
        std::swap(this->_mas[max_index], this->_mas[index]);
        index = max_index;
    }
}


int readMembersNumber()
{
    std::string line;
    std::getline(in, line);
    return std::stoi(line);
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    Heap<Member> heap;

    int n = readMembersNumber();

    while (n--)
    {
        Member member;
        in >> member;
        heap.push(member);
    }

    while (heap.size()) out << heap.pop() << std::endl;

    return 0;
}