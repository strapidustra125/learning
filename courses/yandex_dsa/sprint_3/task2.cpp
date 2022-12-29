/**************************************************************************
 *
 * Успешная попытка: 79898994
 *
 * -- ПРИНЦИП РАБОТЫ --
 *
 *  Сортировка: 
 * Выбор опорного элемента - случайно. Смещение указателей к центру до тех
 * пор, пока левый указатель меньше опорного элемента, а правый больше. 
 * Как только оба условия нарушатся - смена позиций значений. Так до тех 
 * пор, пока указатели не встретятся. Пото рекурсивный вызов сортировки для
 * левой части (не включая опорный) и правой части (включая опорный). Выход
 * из рекурсии: в полуинтервале [left; right) 1 или 0 элементов.
 *  Сравнение:
 * Для сравнения использовал перегрузку операторов '<' и '>' для класса 
 * Member. Это удобно, потому что отлаживался я на мессиве целых чисел, а
 * когда с ним все получилось - через шаблон подставил класс с 
 * перегруженными операциями.  
 *
 * -- ДОКАЗАТЕЛЬСТВО КОРРЕКТНОСТИ --
 *
 *  3 важных кейса: опорный элемент - максимальный в массиве, минимальный и
 * какой-то средний.
 * В первых двух случаях один из указателей, благодаря строгому 
 * неравенству, будет всегда стоять на опорном элементе, пока второй 
 * указатель его [первый] не догонит. Тогда от массива отбросится опорный 
 * элемент. В третьем случае указатели сойдутся где-то не на краю и массив
 * разделится на 2 подмассива.
 *
 * -- ВРЕМЕННАЯ СЛОЖНОСТЬ --
 *
 * Фактически, алгоритм похож на бинарный поиск, поэтому деление на 
 * подмассивы дает сложность O(log n). А пробегание по массиву на каждой 
 * итерации перед разделением - O(n) - перебор всех n элементов. 
 * Итого: O(n log n), где n - размер массива. 
 * В худшем случае: O(n * n * log n), если опорным элементом каждый раз 
 * будет крайний элемент массива, и сортировка пройдет за O(n*n).
 *
 * -- ПРОСТРАНСТВЕННАЯ СЛОЖНОСТЬ --
 *
 * O(n), потому что не создаются дополнительные массивы, а меняется 
 * существующий. Для локальных переменных, хранящихся в стеке - O(log n).
 * Итого: O(n + log n).
 *
 *************************************************************************/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#ifdef MY_IDE
#define out fout
#define in fin
#else
#define out std::cout
#define in std::cin
#endif

std::ifstream fin("../in.txt");
std::ofstream fout("../out.txt");

class Member
{
private:

    std::string _name = "";
    int _tasks = 0;
    int _fine = 0;

public:

    Member(std::string sourceString)
    {
        int ind;
        if (sourceString.find(" ") != std::string::npos)
        {
            ind = sourceString.find(" ");
            this->_name = sourceString.substr(0, ind);
            sourceString = sourceString.substr(ind + 1);

            if (sourceString.find(" ") != std::string::npos)
            {
                ind = sourceString.find(" ");
                this->_tasks = std::stoi(sourceString.substr(0, ind));
                this->_fine = std::stoi(sourceString.substr(ind + 1));
            }
        }
    }

    ~Member() {}

    void print()
    {
        out << this->_name << std::endl;
    }

    bool operator < (const Member& member)
    {
        if (this->_tasks != member._tasks) return this->_tasks < member._tasks;
        if (this->_fine != member._fine) return this->_fine > member._fine;
        return this->_name.compare(member._name) > 0;
    }

    bool operator > (const Member& member)
    {
        if (this->_tasks != member._tasks) return this->_tasks > member._tasks;
        if (this->_fine != member._fine) return this->_fine < member._fine;
        return this->_name.compare(member._name) < 0;
    }
};

template <typename T>
void quickSort(const int & left, const int & right, std::vector<T> & list)
{
    if (right - left == 1 || right - left == 0) return;

    T pivot = list[rand() % (right - left) + left];
    int _left = left;
    int _right = right;

    while (_left != _right - 1)
    {
        while(list[_left] > pivot) _left++;
        while(list[_right - 1] < pivot) _right--;

        if (!(list[_left] > pivot) && !(list[_right - 1] < pivot))
        {
            std::swap(list[_left], list[_right - 1]);
        }
    }
    
    quickSort(left, _left, list);
    quickSort(_right - 1, right, list);
}

template <typename T>
void sort(std::vector<T> & list)
{
    quickSort(0, list.size(), list);
}

int readMembersNumber()
{
    std::string line;
    std::getline(in, line);
    return std::stoi(line);
}

std::string readMember()
{
    std::string line;
    std::getline(in, line);
    return line;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    srand(time(NULL));

    std::vector<Member> memberList;

    int membersNumber = readMembersNumber();

    while (membersNumber--)
    {
        Member member(readMember());
        memberList.push_back(member);
    }

    sort(memberList);

    for (auto member : memberList) member.print();

    return 0;
}
