/**************************************************************************
 * 
 * Успешная попытка: 84672891
 * 
 * -- ПРИНЦИП РАБОТЫ --
 * 
 * Вормирование префиксного дерева из слов и обход входного текста T
 * динамикой
 * 
 * -- ДОКАЗАТЕЛЬСТВО КОРРЕКТНОСТИ --
 * 
 * Шаги динамического программирования:
 * 
 * 1. Массив dp размера |T|+1 (T - входной текст) хранит флаг, означающий,
 * что текст из i символов можно набрать из входных слов. 
 * 2. Базовый случай - dp[0] = true, остальные dp[i] = false.
 * 3. Реккурентная формула: 
 *  dp[j] = true, если текущий символ префиксного дерева - терминальный.
 * 4. Порядок обхода: для всех символов текста, dp[i] для которых = true,
 * перебираем по j символы суффикса и проверяем на возможность набрать 
 * dp[j] из слов. 
 * 5. Ответ - элемент dp[|T|]
 * 
 * -- ВРЕМЕННАЯ СЛОЖНОСТЬ --
 * 
 * Поиск по дереву - O(|L|) = O(|L|), где L - искомое слово.
 * Построение дерева - O(n), где n - к-во слов
 * Обход динамики - O(|T||L|), где T - входной текст, а |L| - длина самого 
 * длинного слова в префиксном дереве.
 * Итого: O(n + |L||T|), где L - самое длинное слово, T - входной текст, а
 * n - количество слов.
 *
 * -- ПРОСТРАНСТВЕННАЯ СЛОЖНОСТЬ --
 * 
 * Динамика - O(|T|)
 * Дерево - O(|L|n), где n - количество входных слов
 * Итого: O(|T||L|n), где L - слово, T - входной текст, а n - количество 
 * входных слов
 * 
 *************************************************************************/

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
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



class Trie
{
public:

    class Node
    {
    public:

        bool terminal = false;
        std::map<char, Node*> children;
    };

    void addWord(std::string w)
    {
        Node* cur = this->_root;
        for (auto s : w)
        {
            auto next = cur->children.find(s);
            if (next != cur->children.end())
            {
                cur = (*next).second;
            }
            else
            {
                Node* newChild = new Node();
                cur->children[s] = newChild;
                cur = newChild;
            }
        }
        cur->terminal = true;
    }

    bool isSplitted(std::string input)
    {
        int size = input.size() + 1;
        std::vector<bool> dp(size, false);

        dp[0] = true;

        for (int i = 0; i < input.size(); i++)
        {
            if (dp[i])
            {
                auto cur = this->_root;
                for (int j = i; j < size; j++)
                {
                    if (cur->terminal) dp[j] = true;

                    auto next = cur->children.find(input[j]);
                    if (next == cur->children.end()) break;
                    cur = cur->children[input[j]];
                }
            }
        }

        return dp[size - 1];
    }

private:

    Node* _root = new Node;
};


int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::string T;
    in >> T;

    int n;
    in >> n;

    Trie trie;
    while (n--)
    {
        std::string input;
        in >> input;
        trie.addWord(input);
    }

    if (trie.isSplitted(T)) out << "YES";
    else out << "NO";

    return 0;
}