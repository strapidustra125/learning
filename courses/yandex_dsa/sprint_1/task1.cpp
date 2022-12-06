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

std::ifstream fin("in.txt");
std::ofstream fout("out.txt");

int main()
{
	long n;
	in >> n;

	int* numbers = new int[n];
	bool firstZero_flag = true;
	int firstZero_index = 0;
	int increment = 0;

	for (int i = 0; i < n; i++)
	{
		in >> numbers[i];

		if (numbers[i] == 0)
		{
			if (firstZero_flag)
			{
				firstZero_flag = false;
				firstZero_index = i;
			}
			else for (int j = 0; j < increment / 2; j++) numbers[i - j - 1] -= increment - 1 - 2 * j;

			increment = 0;
		}
		else numbers[i] = ++increment;
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