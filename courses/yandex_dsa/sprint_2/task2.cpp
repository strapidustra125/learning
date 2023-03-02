/************************************************************************** 
 *  
 * Успешная попытка: 79330678 
 *  
 * -- ПРИНЦИП РАБОТЫ -- 
 *  
 * Вычитал в канале practice, что можно использовать встроенный стек, чем и 
 * воспользовался. Но в промежуточных задачах уже реализовывал стек,  
 * поэтому не сложно добавить самодельный в случае необходимости. 
 * Принцип работы: читаю символ, getOperator говорит мне, что это за  
 * оператор: если none - кладу элемент в стек и перехожу к следующему  
 * элементу, если одна из операций - достаю из стека 2 элемента и совершаю  
 * над ними операцию. Результат кладу в стек. Когда все входные данные  
 * закончатся, то, в случае правильности входных данных (верю наслово), в  
 * стеке останется результат. Его вывожу. 
 *  
 * -- ДОКАЗАТЕЛЬСТВО КОРРЕКТНОСТИ -- 
 *  
 * Результат текущей операции всегда помещается в стек и становится одним  
 * из операднов для следующей операции. 
 *  
 * -- ВРЕМЕННАЯ СЛОЖНОСТЬ -- 
 *  
 * Все используемые операции реализованные в std::stack выполняются за  
 * O(1). Самая затратрая операция - чтение входных данных за О(n) => общая  
 * сложность O(n). 
 *  
 * -- ПРОСТРАНСТВЕННАЯ СЛОЖНОСТЬ -- 
 *  
 * Все переменных, кроме самого стека - О(1). У стека максимальный размер в 
 * случае, если сначала во входных данных идут все числа, а потом все  
 * операторы, т.е. (n+1)/2 - оно же О(n). 
 *  
 *************************************************************************/ 
 
#include <iostream> 
#include <fstream> 
#include <string> 
#include <stack> 
 
#ifdef MY_IDE 
#define out fout 
#define in fin 
#else 
#define out std::cout 
#define in std::cin 
#endif 
 
std::ifstream fin("in.txt"); 
std::ofstream fout("out.txt"); 
 
#define MAX_DEQUE_SIZE 50000 
 
 
enum Operator 
{ 
    none, 
    addition, 
    subtraction, 
    multiplication, 
    division 
}; 
 
Operator getOperator(std::string symbol) 
{ 
    if (symbol == "+") return Operator::addition; 
    if (symbol == "-") return Operator::subtraction; 
    if (symbol == "*") return Operator::multiplication; 
    if (symbol == "/") return Operator::division; 
    return Operator::none; 
} 
 
int main() 
{ 
    std::ios_base::sync_with_stdio(false); 
    std::cin.tie(NULL); 
 
    std::stack<int> stack; 
 
    std::string symbol; 
    while (in >> symbol) 
    { 
        Operator oper = getOperator(symbol); 
 
        if (oper == Operator::none) 
        { 
            stack.push(std::stoi(symbol)); 
            continue; 
        } 
 
        int result; 
        int operand_2 = stack.top(); 
        stack.pop(); 
        int operand_1 = stack.top(); 
        stack.pop(); 
 
        switch (oper) 
        { 
        case addition: 
            result = operand_1 + operand_2; 
            break; 
        case subtraction: 
            result = operand_1 - operand_2; 
            break; 
        case multiplication: 
            result = operand_1 * operand_2; 
            break; 
        case division: 
            result = operand_1 / operand_2; 
            if(operand_1 % operand_2 != 0) 
                if (operand_1 < 0 && operand_2 > 0 ||  
					operand_1 > 0 && operand_2 < 0) result--; 
            break; 
        } 
 
        stack.push(result); 
    } 
 
    out << stack.top(); 
 
    return 0; 
}