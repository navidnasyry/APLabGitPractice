#include <iostream>
using namespace std;

class container
{

	int size;

public:
	float *p;
	container() {}
	container(int s) : size(s) {}
	const int &getsize() { return size; }

	friend class vector;
};

class vector : public container
{
	int len;
	int call_num;

public:
	vector() {}
	explicit vector(int l)
	{
		p = new float();
		len = l;
		size = (1 * 100);
	}
	int &getlen()
	{
		return len;
	}
	~vector() = default;
};

int main()
{

	container c1(100);
	// vector v1 = c1; // you cant call parent in child
	vector v1;
	container &r1 = v1;
	container c2 = 100;
	// c2.getsize() = 20; u cant change the const size
	cout << c2.getsize();
	vector v2 = (vector)100;
	v2.getlen() = 40;
	cout << v2.getlen();
}

// 10040
