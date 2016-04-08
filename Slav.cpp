#include "Slav.h"
#include <fstream>
#include <ctime>
#include <iterator>
vector <string> Slav::names;
int Slav::_counter = 0;

void Slav::init()
{
	srand(time(NULL));
	ifstream file("names.dat");
	copy(istream_iterator<string>(file),
		istream_iterator<string>(),
		back_inserter(names));
	file.close();
}

Slav::Slav()
{
	static int amountOfNames = (init(), names.size());
	_name = names[rand() % amountOfNames];
	_id = _counter++;
}

string Slav::description()
{
	return string("  ") + _name + " [" + to_string(_id) + "]";
}
	
Slav::sex Slav::determineSex() {
	sex rvalue;
	if(_name[_name.size()-1] == 'a') 
		rvalue = FEMALE;
	else
		rvalue = MALE;
	return rvalue;
}