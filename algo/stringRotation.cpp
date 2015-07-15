/*is string1 Rotation of string2
Algo: concatenate string1+strin1 and check if string2 is substring of string1+string1*/

#include <iostream>
#include <string>


using namespace std;

int main(int argc, char const *argv[])
{
	string str1,str2;

	string temp;

	cin >> str1 >> str2;

	temp = str1+str1;

	int l1 = str1.length();
	int l2 = str2.length();
	int l3 = 2*l1;
	int f=0;
	if(l1 != l2){
		cout << "-1";
		return 0;
	}

	else{
		for (int i = 0; i < l3 - l2; ++i)
		{
			f=0;
			for (int j = i; j < l2+i; ++j)
			{
				if(temp[j] != str2[j-i]){
					f=1;
					break;
				}
			}	
			if(f == 0){
				cout << "yes" << endl;
				return 0;
			}
		}
	}
	if(f == 1)
		cout << "-2" << endl;

	return 0;
}