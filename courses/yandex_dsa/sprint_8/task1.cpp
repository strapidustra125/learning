/**************************************************************************
 * 
 * Успешная попытка: 84674548
 * 
 * -- ПРИНЦИП РАБОТЫ --
 * 
 * Рекурсивная распаковка строки
 * Перебор всех слов до тех пор, пока не будет расхождения в символах или 
 * одно из слов не закончится
 * 
 * -- ДОКАЗАТЕЛЬСТВО КОРРЕКТНОСТИ --
 * 
 * Посимвольный параллельный перебор слов гарантирует последовательное 
 * сравнение префиксов строк 
 * 
 * -- ВРЕМЕННАЯ СЛОЖНОСТЬ --
 * 
 * Худший случай перебора - одинаковые слова максимальной длины.
 * По уловию - длина максимум 10^5 = |L| - константа
 * Сложность перебора n слов по |L| символов = O(n|L|) в общем случае.
 * Если счптать, что n - бесконечно больше, то константу можно отбросить.
 * Т.е. O(n), где n - количество слов
 * 
 * Распаковка - рекурсивный обход n строк по |L| символов = O(n|L|)
 * 
 * Итого: 2 * O(n|L|) или O(n) в случае бесконечно большого n.
 *
 * -- ПРОСТРАНСТВЕННАЯ СЛОЖНОСТЬ --
 * 
 * Храним одну строку, которая |L| в худшем случае, и префикс равный строке
 * в худшем случае.
 * Итого: O(2*|L|) = O(|L|)
 * 
 *************************************************************************/


 #include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <stack>
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


int unpack(int pos, std::string& s, std::string& res) 
{
    res = "";
    if (s[pos] == '[') return pos + 1;
    if (s[pos] == ']') return pos + 1;
    
    while (pos < s.size() && s[pos] != ']') 
    {
        if ('a' <= s[pos] && s[pos] <= 'z') 
        {
            while (pos < s.size() && 'a' <= s[pos] && s[pos] <= 'z') 
            {
                res += s[pos];
                pos++;
            }
        }
        else 
        {
            std::string sub = "";
            int new_pos = unpack(pos + 2, s, sub);
            int n = s[pos] - '0';

            for (int i = 0; i < n; i++ ) res += sub;
            
            pos = new_pos + 1;
        }
    }

    return pos;
}


std::string prefix(std::string a, std::string b)
{
	int len = 0; 
	while (true) 
	{
		if (len == b.size() || len == a.size()) return a.substr(0, len);
        if (b[len] != a[len]) return a.substr(0, len);
		len++;
	}
	return a.substr(0, len);
}


int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    in >> n;

    std::string input;
    in >> input;
    n--;


    std::string unpackedString;
    unpack(0, input, unpackedString);

    std::string curPrefix = unpackedString;

    while (n--)
    {
        in >> input;

        unpack(0, input, unpackedString);
        curPrefix = prefix(curPrefix, unpackedString);
    }

    out << curPrefix;

    return 0;
}