#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Car
{
protected:
	double price;
	int year;
public:
	Car(){}
	Car(double price, int year)
	{
		this->price = price;
		this->year = year;
	}
	double getPrice()
	{
		return this->price;
	}
	string toString(){}
	virtual double calculateSalePrice() = 0;
	virtual ~Car(){};
};
class SportCar : public Car
{
public:
	SportCar(double price, int year) : Car(price, year){}
	double calculateSalePrice()
	{
		return this->price;
	}
};
class ClassicCar : public Car
{
public:
	ClassicCar(double price, int year) : Car(price, year){}
	double calculateSalePrice()
	{
		return this->price;
	}
};

class CarExhibition
{
private:
	vector<Car*> carList;
public:
	CarExhibition(){}
	void addCar(Car* a_car)
	{
		this->carList.push_back(a_car);
		cout << "Car added!!"<<endl;
	}
	void numCar()
	{
		int spCar=0, clCar = 0;
		for(int i=0; i< this->carList.size(); i++)
		{
			if(dynamic_cast<SportCar*>(this->carList[i]))
			{
				spCar++;
			}
			else
			{
				clCar++;
			}
		}
		cout << "SportCar: " << spCar<<endl;
		cout << "ClassicCar: " << clCar << endl;
	}
	int getTotalPrice()
	{
		int TotalPrice = 0;
		for(int i=0; i<this->carList.size(); i++)
		{
			TotalPrice += this->carList[i]->getPrice();
		}
		return TotalPrice;
	}
};
int main()
{
	Car* a_car = new SportCar(1001.1, 2019);
	Car* b_car = new ClassicCar(1111.1, 2010);
	Car* c_car = new ClassicCar(1113.1, 2010);
	CarExhibition an_exhibition;
	an_exhibition.addCar(a_car);
	an_exhibition.addCar(b_car);
	an_exhibition.addCar(c_car);
	an_exhibition.numCar();
	cout << "The total price is: $" << an_exhibition.getTotalPrice() << endl;
	delete a_car;
	delete b_car;
	delete c_car;
}