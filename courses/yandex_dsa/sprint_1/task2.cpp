// Успешная посылка: 78886703 
 
#include <iostream> 
#include <set> 
#include <vector> 
#include <algorithm> 
#include <fstream> 
 
#ifdef MY_IDE 
	#define out fout 
	#define in fin 
#else 
	#define out std::cout 
	#define in std::cin 
#endif 
 
std::ifstream fin("../in"); 
std::ofstream fout("../out"); 
 
int main() 
{ 
	short k; 
	in >> k; 
 
    int mas[10] = {0}; 
 
    for(int i = 0; i < 4; i++) 
    { 
        std::string str; 
        in >> str; 
        for(auto s : str)  
            if(s > '0' && s <= '9') mas[s - '0']++; 
    } 
 
    int result = 0; 
    for(int i = 1; i < 10; i++)  
        if(mas[i] > 0 && mas[i] <= 2 * k) result++; 
 
    out << result; 
	 
	return 0; 
}