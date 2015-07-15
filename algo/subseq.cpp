//you can generate all possible subsequences from this

#include <iostream>
#include <string>

using std::string;
using std::cin;
using std::cout;
using std::endl;

int main()
{
	int t,m,n;
	string str;
	
	cin >> t;

	
	int r;
	int k;
	
	int in;
	int count1,count2;

	while(t --> 0)
	{
		cin >> m;
		cin >> n;
		cin >> str;
		int l = str.length();
		int i=1 ;
		r=0;
		k=0;
		while(i < l+1)
		{
			for(in = 0; in < l-i+1; in++)
			{	
				count1=0;
				count2=0;
				for (int j = 0; j < i; j++)
				{
					if(str[in+j] == 'r')
						count1++;
					else if(str[in+j] == 'k')
						count2++;
				}
				if(count1 == m)
					r++;
				if(count2 == n)
					k++;
			}
			i++;
		}
		cout <<r<< " " << k <<endl;
	}

	

	return 0;
}
