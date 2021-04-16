//An example for exercise 9 in the practice test 3.

#include <iostream>
using namespace std;

class Base
{
private:
	static int a; //Dont accept initialization.
public:

	Base(){}
	void increase_a()
	{
		this->a = this->a + 1;
	}
	void print_a(){
		cout << a<<endl;
	}
};
int	Base::a = 3;


int main()
{
	Base o;
	o.print_a();
	Base b;
	b.print_a();
	o.increase_a();
	b.print_a();
}