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

    std::string maxPrefix()
    {
        std::string result = "";

        Node* cur = this->_root;

        while (cur->children.size() == 1)
        {
            auto elem = *(cur->children.begin());
            Node* next = elem.second;
            result += elem.first;
            cur = next;
        }

        return result;
    }

private:

    Node* _root = new Node;
};


std::string unpackString(std::string s)
{
    
        std::stack<char> stack;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == ']') {
                std::string decodedString = "";
                // get the encoded string
                while (stack.top() != '[') {
                    decodedString += stack.top();
                    stack.pop();
                }
                // pop [ from stack
                stack.pop();
                int base = 1;
                int k = 0;
                // get the number k
                while (!stack.empty() && isdigit(stack.top())) {
                    k = k + (stack.top() - '0') * base;
                    stack.pop();
                    base *= 10;
                }
                int currentLen = decodedString.size();
                // decode k[decodedString], by pushing decodedString k times into stack
                while (k != 0) {
                    for (int j = decodedString.size() - 1; j >= 0; j--) {
                        stack.push(decodedString[j]);
                    }
                    k--;
                }
            }
            // push the current character to stack
            else {
                stack.push(s[i]);
            }
        }
        // get the result from stack
        std::string result;
        for (int i = stack.size() - 1; i >= 0; i--) {
            result = stack.top() + result;
            stack.pop();
        }
        return result;
}



int unpack(int pos, std::string& s, std::string& res) 
{
    if (s[pos] == '[') {
        //cerr << "start of parsing on [\n";
        return pos + 1;

    }
    if (s[pos] == ']') {
        //cerr << "start of parsing on ]\n";
        return pos + 1;
    }
    while (pos < s.size() && s[pos] != ']') {
        if ('a' <= s[pos] && s[pos] <= 'z') {
            while (pos < s.size() && 'a' <= s[pos] && s[pos] <= 'z') {
                res += s[pos];
                pos++;
            }
        }
        else {
            while (pos < s.size() && '0' <= s[pos] && s[pos] <= '9') {
                std::string sub = "";
                int new_pos = unpack(pos + 2, s, sub);
                int n = s[pos] - '0';
                for (int i = 0; i < n; i++ ) {
                    res += sub;
                }
                pos = new_pos + 1;
            }
        }
    }

    return pos;
}


std::string unpackString(std::string s, int& end, int start = 0, int k = 1)
{
    std::string result = "";
    int i = 0;
    while (k--)
    {
        i = start;
        for (; s[i] != ']'; i++)
        {
            if (s[i] >= 'a' && s[i] <= 'z')
            {
                result += s[i];
            }
            else if (s[i] >= '1' && s[i] <= '9')
            {
                int change;
                result += unpackString(s, change, i + 2, s[i] - 48);
                i = change;
            }
        }
    }

    end = i;
    return result;
}

std::string prefix(std::vector<std::string> a)
{
	int len = 0; 
	int n = a.size(); 
	while (true) 
	{
		for (int i = 0; i < n; i++) 
		{
			if (len == a[i].size()) return a[0].substr(0, len);
			if (a [i] [len] != a[0] [len]) return a[0].substr(0, len);
		}
		len++;
	}
	return a[0].substr(0, len);
}



int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    in >> n;

	std::vector<std::string> vec;

    while (n--)
    {
        std::string input;
        in >> input;
        
        std::string newString;
        // unpack(0, input, newString);

		int end;
        vec.push_back(unpackString("[" + input + "]", end));
    }

    out << prefix(vec);

    return 0;
}