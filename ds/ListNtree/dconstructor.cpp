#include <iostream>
#include <string>
using namespace std;

class student
{

private:
	double roll;
public:
	string name;
	int id;

	student()
	{
		name = "";
		id = 0;
		roll = 324;
	}
	double getroll() { return roll; }

};

int main()
{
	student std1;
	char n[] = "SHAHSI";
	std1.name = n;
	//std1.id = 12;
	student std2 = std1;
	cout << std1.name <<" " << std1.id << endl;
	cout << std2.name << " " << std2.id << endl; 
	std2.name[0] = 'B';
	std1.id = 234;
	cout << std1.name <<" " << std1.id << endl;
	cout << std2.name << " " << std2.id << endl; 
	cout << std1.getroll() << endl;
	return 0;
}