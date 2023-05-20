#include <iostream>
using namespace std;

class container {
protected:
	int size;
public:
	float* p;
	container(int s){size =s;}
	const int& getsize() { return size;}

};

class vector :public container {

	int call_num;
public:
	explicit vector(int l) :len(l),container(100){
		p = new float();
	}
	int len;
	int& getlen() //const // this function can not be const!
	{
		call_num ++;
		return len;
	}
	~vector() {
		delete [] p ;}
};

int main() {

	container c1(100);
	vector v1(100); //= c1;//We cant equal a parent class to a  child class!
	container& r1 = v1;
	container c2 = 100;
	//c2.getsize() = 20;//c2.getsize() is a const method!
	cout << c2.getsize()<<endl;
	vector v2 (100);
	//v2.getlen = 40;
	cout << v2.getlen();
	
}
