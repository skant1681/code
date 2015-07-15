# include <iostream>
# include <math.h>
using namespace std;

int main(){

	int number;
	int count=0;
	
	cin >> number;
	int limit = sqrt(number);

	for (int a = 0; a <= limit; ++a)
	{
		for(int b = a+1; b <= limit;++b)
		{
			for (int c = a+2; c <= limit; ++c)
			{
				if((a*a + b*b + c*c) == number){
					cout << a << ", " << b << ", " << c << endl;
					count++;
				}
			}
		}
	}

	cout << count << endl;

	return 0;
}