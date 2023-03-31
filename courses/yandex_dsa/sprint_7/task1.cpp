/**************************************************************************
 * 
 * Успешная попытка: 84517992
 * 
 * -- ПРИНЦИП РАБОТЫ --
 * 
 * Реализация алгоритма Алгоритм Вагнера-Фишера
 * 
 * -- ДОКАЗАТЕЛЬСТВО КОРРЕКТНОСТИ --
 * 
 * Шаги динамического программирования:
 * 
 * 1. Массив cur размера max+1 хранит значение метрики между двумя 
 * словами. Где max - длина наибольшего слова.
 * 2. Базовый случай - dp[cur][i] = i, где i - итератор по длинному слову.
 * 3. Реккурентная формула: 
 *  dp[cur][j] = minimum(
 *                   dp[cur][j - 1] + 1, 
 *                   dp[prev][j] + 1, 
 *                   dp[prev][j - 1] + (int)(w1[i - 1] != w2[j - 1])
 *           );
 * 4. Порядок обхода: 2 вложенных цикла. Т.е. для каждой буквы из 1 слова
 * перебираются все буквы второго.
 * 5. Ответ - элемент dp[cur][max]
 * 
 * -- ВРЕМЕННАЯ СЛОЖНОСТЬ --
 * 
 * O(mn), где n, m - длины слов.
 *
 * -- ПРОСТРАНСТВЕННАЯ СЛОЖНОСТЬ --
 * 
 * O(2max), где max - длина наибольшего слова.
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

int minimum(const int & a, const int& b, const int& c)
{
    int min2 = std::min(a, b);
    return std::min(min2, c);
}


int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::string w1, w2;
    in >> w1 >> w2;

    int min = w1.size();
    int max = w2.size();

    if(min > max)
    {
        std::swap(min, max);
        std::swap(w1, w2);
    }

    int ** dp = new int* [2];
    for(int i = 0; i < 2; i++) dp[i] = new int [max + 1];

    int cur = 1;
    int prev = 0;

    for(int i = 0; i < max + 1; i++) dp[cur][i] = i;

    for(int i = 1; i < min + 1; i++)
    {
        cur = 1 - cur;
        prev = 1 - prev;
        dp[cur][0] = i;

        for(int j = 1; j < max + 1; j++) 
        {
            dp[cur][j] = minimum(
                    dp[cur][j - 1] + 1, 
                    dp[prev][j] + 1, 
                    dp[prev][j - 1] + (int)(w1[i - 1] != w2[j - 1])
            );
        }
    }

    out << dp[cur][max];
    return 0;
}