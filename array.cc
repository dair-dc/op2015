#include <fstream>
#include <iostream>
#include <string>

template <typename T>
class Array {
	T *buf;
	unsigned int capacity;
	unsigned int size_;  
public:
	Array() : buf(NULL), capacity(0), size_(0) {}
    ~Array() { delete[] buf; }
	void push_back(const T &x);
	T& operator[](unsigned int i) { return buf[i]; }
	unsigned int size() const { return size_; }
};

template <typename T>
void Array<T>::push_back(const T &x)
{
	if (capacity == size_)
	{
		T *tmp;

		capacity += 10;
		tmp = new T[capacity];
		for (unsigned int i = 0; i < size_; i++)
		{
			tmp[i] = buf[i];
		}

		delete[] buf;
		buf = tmp;
	}
	buf[size_] = x;
	size_++;
}

int main()
{
	Array<int> a;
	Array<std::string> s2;
	int x;
	std::string s;
	std::ifstream in("num.txt");
	std::ifstream in1("in.txt");

	while (in >> x)
		a.push_back(x);

	while (in1 >> s)
	{
		s2.push_back(s);
	}

	for (unsigned int i = 0; i < a.size(); i++)
		std::cout << a[i] << " ";
	for (unsigned int i = 0; i < s2.size(); i++)
		std::cout << s2[i] << " ";

	std::cout << std::endl;
	return 0;
}
