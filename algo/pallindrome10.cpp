#include <iostream>
#include <cmath>
using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	int rem;
	int temp=0;
	int count=0;
	int m=n;

	if((n%2)==0){
		cout<< "-1"<<endl;
		return 0;
	}
	while(n){
		rem = n%2;
		temp+=rem*pow(2,count);
		cout << rem;
		n=n/2;
		count++;
	}
	cout<<endl;
	cout << temp<<endl;
	if(temp == m)
		cout<<count<<endl;
	else
		cout<<"-1"<<endl;

	return 0;
}
