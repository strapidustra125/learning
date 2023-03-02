// Успешная посылка: 78886466 
 
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
 
#ifndef MY_IDE 
	std::ios_base::sync_with_stdio(false); 
	std::cin.tie(NULL); 
#endif 
 
	long n; 
	in >> n; 
 
	int* numbers = new int[n]; 
	int firstZero_index = -1; 
	int increment = 0; 
 
	for (int i = 0; i < n; i++) 
	{ 
		in >> numbers[i]; 
 
		if (numbers[i] == 0) 
		{ 
			if (firstZero_index == -1) firstZero_index = i; 
			else  
			{ 
				for (int j = 0; j < increment / 2; j++)  
					numbers[i - j - 1] -= increment - 1 - 2 * j; 
			} 
 
			increment = 0; 
		} 
		else  
		{ 
			numbers[i] = ++increment; 
		} 
	} 
 
	for (int i = 0; i < n; i++) 
	{ 
		while (firstZero_index) 
		{ 
			out << firstZero_index-- << (i == n - 1 ? "" : " "); 
			i++; 
		} 
 
		out << numbers[i] << (i == n - 1 ? "" : " "); 
	} 
	 
	return 0; 
}