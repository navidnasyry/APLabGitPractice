#include <iostream>
using namespace std;

class container {

	int size;
public:
	float* p;
	container(int s) :size(s) {}
	//getsize method should return an int and be a const method
//	const int& getsize() { return size; }
	int getsize() const { return size; }
};

class vector :public container {

	int call_num;
public:
	//i changed the member initializer list of vector constructor because
	//it was initializing data members of based class without using its copy constructor
	explicit vector(int l) :len(l), container{ 100 }{
		p = new float();
	}
	int len;
	//you should not return a reference to a private data member
	//and you are changing a data member in your const method which is wrong
	/*int& getlen() const {
		call_num++;
		return len;
	}*/
	//getlen() method should return int and be a const method
	int getlen() const {
		return len;
	}

	~vector() = default;
};

int main() {

	container c1(100);
	//you can not create a derived class by copy constructor from base class
	// so i created vector v3 by its constructor and v1 from v2 by copy constructor
	//vector v1 = c1;
	vector v3{ 100 };
	vector v1 = v3;
	container& r1 = v1;
	container c2 = 100;
	//you are treating return type of getsize() which is const int& as lvalue which is wrong
	// we use getsize method to return size and print it
	//c2.getsize() = 20;
	cout << c2.getsize();
	//vector constructor is explicit which prevents implicit casting
	//vector v2 = 100;
	// I created v3 by using copy constructor and v3
	vector v2{ v3 };
	//we use getlen() method to return len an print it not returning a reference to len to change it
	//v2.getlen = 40;
	cout << v2.getlen();
}