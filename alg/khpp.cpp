#include <iostream>
#include <string>
#include <stack>
using namespace std;

unsigned long match(string ,unsigned long *);
int main()
{
	unsigned long time;
	unsigned long n;
	unsigned long num[2];
	string str;
	cin>>str;
	cin>>time;
	for(unsigned long i = 0;i < time;i++)
	{
		cin >>num[0]>>num[1];
		n = match(str,num);
		cout<<n<<endl;
	}
	return 0;
}

unsigned long match(string str,unsigned long *num)
{
	unsigned long i,n=0;
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