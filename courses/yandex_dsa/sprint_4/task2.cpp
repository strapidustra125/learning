/************************************************************************** 
 * 
 * Успешная попытка: 80090028 
 * 
 * -- ПРИНЦИП РАБОТЫ -- 
 * 
 *  Хэш-таблица - это массив указателей на список указателей на ноду  
 * [key, value]. 
 *  Коллизии разрешаются методом цепочек через связный список. 
 * Читается строка с запросом и парсится соответствующим методом класса  
 * HashTable. 
 * 
 * -- ДОКАЗАТЕЛЬСТВО КОРРЕКТНОСТИ -- 
 * 
 *  Список помогает разрешать колизии. 
 *  Массив обеспечивает быстрый доступ к каждому элементу по индексу. 
 *  Хэш-функция берет число по модуль размера таблицы. 
 * 
 * -- ВРЕМЕННАЯ СЛОЖНОСТЬ -- 
 * 
 *  Все операции происходят за O(1), т.к. работают с массивом по индексу. 
 * Итого: O(n), где n - количество запросов. 
 * 
 * -- ПРОСТРАНСТВЕННАЯ СЛОЖНОСТЬ -- 
 * 
 *  O(10000) - размер массива 
 *  Как бы не распределились элементы таблицы: хоть 10к в одну ячейку, хоть  
 * в 10к ячеек по одному - памяти будет O(n), где n - количество запросов.
 * 
 *************************************************************************/ 
 
#include <iostream> 
#include <fstream> 
#include <string> 
#include <optional> 
#include <list> 
#include <vector> 
 
#ifdef MY_IDE 
#define out fout 
#define in fin 
#else 
#define out std::cout 
#define in std::cin 
#endif 
 
std::ifstream fin("in.txt"); 
std::ofstream fout("out.txt"); 
 
const int CAPACITY = 100000; 
 
class HashTable 
{ 
private: 
 
    struct TableElem 
    { 
        int key = 0; 
        int value = 0; 
    }; 
 
    std::list<TableElem> ** _table = new std::list<TableElem>*[CAPACITY]; 
 
public: 
 
    HashTable() 
    { 
        for (int i = 0; i < CAPACITY; i++) this->_table[i] = nullptr; 
    } 
 
    ~HashTable() {} 
 
    std::optional<int> get(const int& key) 
    { 
        int index = this->_hash(key); 
        if (this->_table[index] == nullptr) return std::nullopt; 
        if (!this->_table[index]->size()) return std::nullopt; 
 
        for (auto i = this->_table[index]->begin();  
             i != this->_table[index]->end(); i++) 
        { 
            if ((*i).key == key) return (*i).value; 
        } 
        return std::nullopt; 
    } 
 
    void put(const int& key, const int& value) 
    { 
        int index = this->_hash(key); 
 
        if (this->_table[index] != nullptr) 
        { 
            if (this->_table[index]->size()) 
            { 
                for (auto i = this->_table[index]->begin();  
                     i != this->_table[index]->end(); i++) 
                { 
                    if ((*i).key == key) 
                    { 
                        (*i).value = value; 
                        return; 
                    } 
                } 
            } 
        } 
 
        if (this->_table[index] == nullptr)  
            this->_table[index] = new std::list<TableElem>(); 
 
        TableElem elem; 
        elem.key = key; 
        elem.value = value; 
        this->_table[index]->push_back(elem); 
    } 
 
    std::optional<int> remove(const int& key) 
    { 
        int index = this->_hash(key); 
        if (this->_table[index] == nullptr) return std::nullopt; 
        if (!this->_table[index]->size()) return std::nullopt; 
        for (auto i = this->_table[index]->begin();  
             i != this->_table[index]->end(); i++) 
        { 
            if ((*i).key == key) 
            { 
                int removedElem = (*i).value; 
                this->_table[index]->erase(i); 
                return removedElem; 
            } 
        } 
        return std::nullopt; 
    } 
 
    void processCommand(std::string command) 
    { 
        std::string commandName = command.substr(0, command.find(" ")); 
        command = command.substr(command.find(" ") + 1, command.size()); 
 
        if (commandName == "delete") 
        { 
            int key = std::stoi(command); 
 
            std::optional<int> value = this->remove(key); 
 
            if (value == std::nullopt) out << "None" << std::endl; 
            else out << *value << std::endl; 
 
            return; 
        } 
        if (commandName == "put") 
        { 
            int key = std::stoi(command.substr(0, command.find(" "))); 
 
            command = command.substr(command.find(" ") + 1,  
                command.size()); 
            int value = std::stoi(command); 
 
            this->put(key, value); 
 
            return; 
        } 
        if (commandName == "get") 
        { 
            int key = std::stoi(command); 
 
            std::optional<int> value = this->get(key); 
 
            if (value == std::nullopt) out << "None" << std::endl; 
            else out << *value << std::endl; 
 
            return; 
        } 
    } 
 
private: 
 
    int _hash(const int & key) 
    { 
        return key % CAPACITY; 
    } 
}; 
 
int readCommandsNumber() 
{ 
    std::string line; 
    std::getline(in, line); 
    return std::stoi(line); 
} 
 
std::string readCommand() 
{ 
    std::string line; 
    std::getline(in, line); 
    return line; 
} 
 
int main() 
{ 
    std::ios_base::sync_with_stdio(false); 
    std::cin.tie(NULL); 
 
    HashTable table; 
 
    int commandsNumber = readCommandsNumber(); 
 
    while (commandsNumber--) table.processCommand(readCommand()); 
 
    return 0; 
}