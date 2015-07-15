# include <iostream>
# include <string>
# include <cmath>

using namespace std;

int main(){
string s;
int alpha1[26],alpha2[26];
int min;

int n;
cin >> n;
while(n){

for (int i = 0; i < 26; ++i)
{
	alpha1[i]=0;
	alpha2[i]=0;
}
//getline(cin,s);
cin >> s;
int l=s.length();
if (l%2 != 0){
	cout<<"-1"<<endl;
	continue;
}

for (int i = 0; i < l/2; ++i)
	alpha1[s[i]-'a']++;

for (int i = l/2; i < l; ++i)
	alpha2[s[i]-'a']++;

min=l/2;

for (int i = 0; i < 26; ++i)
{
	if(alpha1[i]==0 || alpha2[i]==0)
		continue;
	else if(alpha2[i] <= alpha1[i])
		min -= alpha2[i];
	else
		min -= alpha1[i];
}
n--;
cout<<min<<endl;
}

return 0;

}