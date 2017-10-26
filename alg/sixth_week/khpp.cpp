#include <iostream>
#include <string>
#include <stack>
using namespace std;

int match(string ,int *);
int main()
{
	int time;
	int n;
	int num[2];
	string str;
	cin>>str;
	cin>>time;
	for(int i = 0;i < time;i++)
	{
		cin >>num[0]>>num[1];
		n = match(str,num);
		cout<<n<<endl;
	}
	return 0;
}

int match(string str,int *num)
{
	int i,n=0;
	stack<char> s;
	for(i = num[0]-1;i<num[1];i++)
	{
		if(str.at(i) == '(')
		{
			s.push('(');
		}
		else if(str.at(i) == ')')
		{
			if(!s.empty() && s.top() == '(')
			{
				s.pop();
				n+=2;
			}
		}
	}
	return n;
}