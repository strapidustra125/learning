/**************************************************************************
 * 
 * Успешная попытка: 84467373
 * 
 * -- ПРИНЦИП РАБОТЫ --
 * 
 * Упрощенный вариант реализации частного случая задачи о рюкзаке
 * 
 * -- ДОКАЗАТЕЛЬСТВО КОРРЕКТНОСТИ --
 * 
 * Необходимо набрать половину суммы входных чисел из этих числе.
 * 
 * Шаги динамического программирования:
 * 
 * 1. Массив dp, число элементов которого равно половине суммы, хранит в 
 * себе флаг достижимости числа, равного индексу текущего элемента.
 * 2. Базовый случай - dp[0] = true, т.е. набрать 0 из 0 чисел.
 * 3. Реккурентная формула: 
 *  if (dp[j - data[i]]) dp[j] = true;
 * 4. Порядок обхода: 2 вложенных цикла. Т.е. для каждого числа 
 * перебираются элементы от получуссы до него самого.
 * 5. Ответ - элемент dp[sum]
 * 
 * -- ВРЕМЕННАЯ СЛОЖНОСТЬ --
 * 
 * O(mn), где n - количество элементов, а m - их полусумма.
 *
 * -- ПРОСТРАНСТВЕННАЯ СЛОЖНОСТЬ --
 * 
 * O(m+n), где n - количество элементов, а m - их полусумма.
 *
 *************************************************************************/


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

#ifdef LINUX
    std::ifstream fin("../in.txt");
    std::ofstream fout("../out.txt");
#else
    std::ifstream fin("in.txt");
    std::ofstream fout("out.txt");
#endif


int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int N;
    in >> N;

    int sum = 0;
    std::vector<int> data;
    for (int i = 0; i < N; i++)
    {
        int s;
        in >> s;
        sum += s;
        data.push_back(s);
    }

    if (sum % 2 != 0)
    {
        out << "False";
        return 0;
    }

    sum /= 2;

    std::vector<bool> dp;
    dp.push_back(true);
    for (int i = 1; i <= sum; i++) dp.push_back(false);

    for (int i = 0; i < data.size(); i++)
        for (int j = sum; j >= data[i]; j--)
            if (dp[j - data[i]]) dp[j] = true;
    
    if (dp[sum]) out << "True";
    else out << "False";

    return 0;
}