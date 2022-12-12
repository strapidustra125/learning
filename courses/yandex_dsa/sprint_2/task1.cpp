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

class Deque
{
private:

	class Node
	{
	public:
		Node(int value, Node* prev)
		{
			this->value = value;
			this->prev = prev;
		}

		int value;
		Node* prev;
	};

	int _size;
	Node* _top;
	Node* _topMax;

public:

	StackMax()
	{
		_size = 0;
		_top = nullptr;
		_topMax = nullptr;
	}

	void push(int elem);
	void pop();
	void get_max();
	void print();
	void printMax();
};

void StackMax::push(int elem)
{
	if (_top == nullptr)
	{
		_top = new Node(elem, nullptr);
		_topMax = new Node(elem, nullptr);
	}
	else
	{
		Node* current = _top;
		_top = new Node(elem, current);

		Node* topMax = _topMax;
		if (elem >= topMax->value) _topMax = new Node(elem, topMax);
		else
		{
			if (topMax->prev == nullptr)
			{
				Node* temp = new Node(elem, nullptr);
				topMax->prev = temp;
			}
			else
			{
				while (elem < topMax->prev->value)
				{
					topMax = topMax->prev;
					if (topMax->prev == nullptr)
					{
						Node* temp = new Node(elem, nullptr);
						topMax->prev = temp;
						break;
					}
					
				}

				Node* temp = new Node(elem, topMax->prev);
				topMax->prev = temp;
			}
		}
	}

	_size++;
}

void StackMax::pop()
{
	if (_size == 0) out << "error" << std::endl;
	else
	{
		int elem = _top->value;

		_size--;
		if (_top->prev == nullptr) _top = nullptr;
		else _top = _top->prev;


		Node* topMax = _topMax;
		Node* next = _topMax;
		if (topMax->value == elem)
		{
			_topMax = _topMax->prev;
		}
		else
		{
			while (topMax->value != elem)
			{
				next = topMax;
				topMax = topMax->prev;
			}
			next->prev = topMax->prev;
		}

		
	}
}

void StackMax::get_max()
{
	Node* newTop = _top;
	if (_size == 0)
	{
		out << "None" << std::endl;
		return;
	}
	
	out << _topMax->value << std::endl;
}

void StackMax::print()
{
	std::cout << "Stack: { ";
	Node* newTop = _top;
	while (newTop != nullptr)
	{
		std::cout << newTop->value << " ";
		newTop = newTop->prev;
	}
	std::cout << "}" << std::endl;
}


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