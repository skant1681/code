/*Given a 2D matrix. Each cell was filled with a specific color denoted by single character eg.
for blue ­‘B’. If one position is clicked (x,y), colour present at that position would be deleted. If
the same colour is present in neighbourhood  (up/down/left/right) then it would also be deleted.
After deletion blank spaces will be replaced by the value present in the cell  above that. In case
no value present above the  cell then blank entry will be replaced by 0.*/


#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	cout<< "dimension of array: ";
	cin >> n;
	char array[n][n];
	int ar[2*n];

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
			cin >> array[i][j];
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
			cout << array[i][j] << "  ";
		cout << endl;
	}
	int a,b;
	cout << "clicked index: ";
	cin >> a >> b;
	int index = -1;

	for (int i = 1; i <= b; i++)
	{
		if(array[a][b] == array[a][b-i]){
			array[a][b-i] = '0';
			ar[++index]=a;
			ar[++index]=b-i;

		}
		else
			break;
	}
	for (int i = 1; i < n-b; i++)
	{
		if(array[a][b] == array[a][b+i]){
			array[a][b+i] = '0';
			ar[++index]=a;
			ar[++index]=b+i;
		}
		else
			break;
	}
	for (int i = 1; i <= a; i++)
	{
		if(array[a][b] == array[a-i][b]){
			array[a-i][b] = '0';
			ar[++index]=a-i;
			ar[++index]=b;
		}
		else
			break;
	}
	for (int i = 1; i < n-a ; i++)
	{
		if(array[a][b] == array[a+i][b]){
			array[a+i][b] = '0';
			ar[++index]=a+i;
			ar[++index]=b;
		}
		else
			break;
	}
	array[a][b] = '0';
	ar[++index] = a;
	ar[++index] = b;
	
	for (int i = 0; i < index+1; i+=2)
	{
		if((array[ar[i]-1][ar[i+1]] != '0') && (ar[i]-1) >= 0){
			array[ar[i]][ar[i+1]] = array[ar[i]-1][ar[i+1]];
			array[ar[i]-1][ar[i+1]] = '0';
		}
		
	}



	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
			cout << array[i][j] << "  ";
		cout << endl;
	}


	return 0;
}