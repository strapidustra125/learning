/**************************************************************************
 *
 * Успешная попытка: 80121897
 *
 * -- ПРИНЦИП РАБОТЫ --
 *
 * 1. Формируется мапа, которая хранит в себе слово, документ, в котором
 *  оно встречается и количество вхождений.
 * 2. Читается множество слов запроса в set, чтобы не было повторений.
 * 3. Проход по всем словам из запроса: формирование мапы 
 *  <докумнт><релевантность>.
 * 4. Запись мапы в вектор, сортировка вектора и вывод первых 5 (или 
 *  меньше) элементов.
 * 
 * -- ДОКАЗАТЕЛЬСТВО КОРРЕКТНОСТИ --
 * 
 * Мапа учтет в себе все слова и их количество, остается только перебрать
 * слова из запроса. Проверка на пустоту помогает избежать лишних затрат 
 * памяти.
 * 
 * -- ВРЕМЕННАЯ СЛОЖНОСТЬ --
 * 
 * 1. Чтение документов - O(n), где n - к-во документов
 * 2. Чтение запросов - O(m), где m - к-во запросов
 * 3. Обработка запросов в худшем случае (если все документы состоят из 
 * попарно различных слов) - O(k*n) - 2 вложенных цикла, k - количество 
 * попарно различных слов, n - к-во документов. 
 * Насколько я понял - длина строки максимум 1000
 * 26*26 = 676 двухбуквенных слов.
 * 26 однобуквенных слов.
 * 26(1б слов) + 26(пробелов) = 52
 * Остается 1000 - 52 = 948 позиций для 2б слов: 948 / 3 = 316 слов.
 * Т.е. обработка запросов в худшем случае выполняется за 
 * O((316 + 52)n) = O(368n) = O(n).
 * 4. Сортировка вектора так же не зависит от n и m.
 * 
 * Для чтения каждого запроса есть 1 обработка за O(n) и 1 сортировка за 
 * O(n)
 * => Общая временная сложность - O(n + m * (n + n)) = O(n + n * m)
 *
 * -- ПРОСТРАНСТВЕННАЯ СЛОЖНОСТЬ --
 *
 * Мапа по словам - O(500*n) = O(n), где n - к-во документов
 * Мапа релевантности - O(n), где n - к-во документов
 * Больше 1 запроса не хранится. Т.е. максимум 100 символов - O(1).
 * Вектор - O(n)
 * Итого: O(n + n + n) = O(n)
 *
 *************************************************************************/

#include <vector>
#include <string>
#include <array>
#include <unordered_set>
#include <cassert>
#include <algorithm>
#include <unordered_map>

#include <iostream>
#include <fstream>
#include <sstream>


#ifdef MY_IDE
#define out fout
#define in fin
#else
#define out std::cout
#define in std::cin
#endif

std::ifstream fin("../in.txt");
std::ofstream fout("../out.txt");

struct Relevance
{
    int documentID;
    int documentRelevance;
};


std::unordered_map<std::string, std::unordered_map<int, int>> documents;

int getNumber()
{
    std::string line;
    std::getline(in, line);
    return std::stoi(line);
}

void getDocument()
{
    static int documentID = 1;
    std::string line;
    std::getline(in, line);

    int counter = 0;
    int index;
    while ((index = line.find(" ")) != std::string::npos)
    {
        documents[line.substr(0, index)][documentID]++;
        line = line.substr(index + 1, line.size());
    }
    documents[line][documentID]++;

    documentID++;
}

std::unordered_set<std::string> getRequest()
{
    std::unordered_set<std::string> request;

    std::string line;
    std::getline(in, line);

    std::stringstream ss;
    ss << line;
    while(ss >> line) request.insert(line);

    return request;
}

void processRequest(const std::unordered_set<std::string> & requestWords, 
                    const int & documentsNumber)
{
    std::unordered_map<int, int> request;
    for (const auto & requestWord : requestWords)
    {
        if(documents.count(requestWord) == 0) continue;
        for(const auto & [key, value] : documents[requestWord]) 
            request[key] += value;
    }

    std::vector<Relevance> requestVector;
    for (auto word : request)
    {
        Relevance r;
        r.documentID = word.first;
        r.documentRelevance = word.second;
        requestVector.push_back(r);
    }

    request.clear();

    auto resultIter = (requestVector.size() < 5 ? requestVector.end() : requestVector.begin() + 5);

    std::partial_sort
    (
        requestVector.begin(),
        resultIter,
        requestVector.end(),
        [](Relevance a, Relevance b)
        {
            if (a.documentRelevance != b.documentRelevance) 
                return a.documentRelevance > b.documentRelevance;
            else return a.documentID < b.documentID;
        }
    );

    for (auto i = requestVector.begin(); i < resultIter; i++) out << (*i).documentID << " ";
    out << std::endl;

    requestVector.clear();
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int documentsNumber = getNumber();
    int counter = documentsNumber;
    while (counter--) getDocument();

    int requestNumber = getNumber();
    while (requestNumber--) processRequest(getRequest(), documentsNumber);

    return 0;
}