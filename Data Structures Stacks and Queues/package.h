#pragma once
// Auther: Lane Murray
// Date: 9/21/2021
#include <string>
#include <iostream>

using namespace std;

class package
{
private:
	string destinationName;
	string address;
	string city;
	string state;
	int zipCode;
	int postalClass; // I'm using an int since we have 7 options for postal class. I can sort based on the size of the number to determine the class.
public:
	// Constructors
	package(string destinationName, string address, string city, string state, int zipCode, int postalClass);
	package();
	// Destructor
	~package();

	// Getters
	string getDestinationName() const;
	string getAddress() const;
	string getCity() const;
	string getState() const;
	int getZipCode() const;
	int getPostalClass() const;

	// Overloaded Operators
	bool operator==(const int postalClassTwo);
	bool operator!=(const int postalClassTwo);
	bool operator<=(const int postalClassTwo);
	bool operator>=(const int postalClassTwo);
	bool operator>(const int postalClassTwo);
	bool operator<(const int postalClassTwo);
	friend ostream & operator<<(ostream &out, const package &packageInfo);
};

// Constructors
package::package(string destinationName, string address, string city, string state, int zipCode, int postalClass) 
{
	this->destinationName = destinationName;
	this->address = address;
	this->city = city;
	this->state = state;
	this->zipCode = zipCode;
	this->postalClass = postalClass;
}

package::package()
{
	this->destinationName = " ";
	this->address = " ";
	this->city = " ";
	this->state = " ";
	this->zipCode = 0;
	this->postalClass = 0;
}

// Destructor
package::~package()
{

}

// Getters
string package::getDestinationName() const
{
	return destinationName;
}

string package::getAddress() const
{
	return address;
}

string package::getCity() const
{
	return city;
}

string package::getState() const 
{
	return state;
}

int package::getZipCode() const
{
	return zipCode;
}

int package::getPostalClass() const
{
	return postalClass;
}

bool package::operator==(const int postalClassOne) // Overload for the == operator.
{
	if (postalClassOne == this->postalClass)
	{
		return true;
	}
	else 
		return false;
}

bool package::operator!=(const int postalClassOne) // Overload for the != operator.
{
	if (postalClassOne != this->postalClass)
	{
		return true;
	}
	else
		return false;
}

bool package::operator<=(const int postalClassOne) // Overload for the <= operator.
{
	if (postalClassOne <= this->postalClass)
	{
		return true;
	}
	else
		return false;
}

bool package::operator>=(const int postalClassOne) // Overload for the >= operator.
{
	if (postalClassOne >= this->postalClass)
	{
		return true;
	}
	else
		return false;
}

bool package::operator>(const int postalClassOne) // Overload for the > operator.
{
	if (postalClassOne > this->postalClass)
	{
		return true;
	}
	else
		return false;
}

bool package::operator<(const int postalClassOne) // Overload for the < operator.
{
	if (postalClassOne < this->postalClass)
	{
		return true;
	}
	else
		return false;
}

ostream & operator<<(ostream &output, const package &packageInfo) // Overload for the << operator.
{
	cout << packageInfo.getDestinationName() << endl;
	cout << packageInfo.getAddress() << endl;
	cout << packageInfo.getCity() << ", " << packageInfo.getState() << " " << packageInfo.getZipCode() << endl;
	switch (packageInfo.getPostalClass())
	{
	case  1:
		cout << "Priority Mail Express" << endl;
		break;
	case 2:
		cout << "Priority Mail" << endl;
		break;
	case 3:
		cout << "First-Class Mail" << endl;
		break;
	case 4:
		cout << "Periodicals" << endl;
		break;
	case 5:
		cout << "USPS Marketing Mail" << endl;
		break;
	case 6:
		cout << "Package Services" << endl;
		break;
	case 7:
		cout << "USPS Retail Ground" << endl;
		break;
	default:
		cout << "Error... No valid Postal Class.";

	}
	cout << endl;

	return output;
}