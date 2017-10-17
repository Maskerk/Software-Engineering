#include <iostream>
#include<string>
#include <vector>
#include <map>
using namespace std;

#define N 200

typedef pair<int , int> PAIR;

int min_rank[200];
unsigned long num_sum[200],result = 0;
map<unsigned long ,int> num_index;
int index_i = 0;


int n;

void sum(unsigned long *,unsigned long *);
int main()
{
	int i;
	cin >> n;
	unsigned long arr_a[200],arr_b[200];
	//input
	for(i = 0;i < n;i++)
	{
		cin >> arr_a[i];
	}
	for(i = 0;i < n;i++)
	{
		cin >> arr_b[i];
	}

	sum(arr_a,arr_b);

	//建立索引
	for(i = 0;i < n;i++)
	{
		num_index.insert(pair<unsigned long,int>(num_sum[i],i));
	}

	//建立迭代
	map<unsigned long,int>::iterator iter;
	// num_index.erase(num_index.begin());
	// for(iter=num_index.begin();iter != num_index.end();iter++)
	// 	cout<<iter->first<<"   "<<iter->second<<endl;
	//去除
	for(i = 0;i < n;i++)
	{
		result += num_index.begin()->first;
		
		//左右重建
		if(i == 0)
		{
			for(iter = num_index.begin();iter != num_index.end();iter++)
			{
				if(iter->second == i + 1)
				{
					iter->first -= arr_b[num_index.begin()->second];
					break;
				}
			}
		}
		else if(i == n - 1)
		{

		}
		else
		{

		}
		//剔除
		num_index.erase(num_index.begin());
	}
	//output
	map<unsigned long,int>::iterator iter;
	for(iter=num_index.begin();iter != num_index.end();iter++)
		cout<<iter->first<<"   "<<iter->second<<endl;

	return 0;
}

void sum(unsigned long * arr_a,unsigned long * arr_b)
{
	int i;
	for(i = 0;i < n;i++)
	{
		if(i == 0)
		{
			num_sum[i] = arr_a[i] + arr_b[i+1];
		}
		else if(i == n - 1)
		{
			num_sum[i] = arr_a[i] + arr_b[i-1];
		}
		else
		{
			num_sum[i] = arr_a[i] + arr_b[i-1] + arr_b[i+1];
		}
	}
}

