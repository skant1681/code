/*Printing a string in wave like pattern. If the current character is greater than that
of previous character then print it above, if it is less than current then print below and if its
equal then in same line.*/


#include <iostream>
#include <string>
using namespace std;

int main(){

	string str;
	cin>>str;
	int len = str.length();
	int newline[len];

	newline[0]=0;
	int max=0;
	int min = 0;

	for (int i = 0; i < len; ++i)
	{
		if(str[i+1] > str[i])
			newline[i+1] = newline[i]+ 1;
		else if(str[i+1] < str[i])
			newline[i+1] = newline[i]-1;
		else
			newline[i+1] = newline[i];
		if(max < newline[i+1])
			max = newline[i+1];
		if(min > newline[i+1])
			min = newline[i+1];
	}
	

	/*for (int i = 0; i < len; ++i)
	{
		cout << newline[i] << " ";
	}
	cout << endl ;*/

	while(max >= min){
		string temp;
		for (int i = 0; i < len; ++i)
		{
			
			if(newline[i] == max){
				temp = temp + str[i];
			}
			else
				temp = temp + ' ';
		}

		cout << temp << endl;
		max--;
	}



	return 0;
}
