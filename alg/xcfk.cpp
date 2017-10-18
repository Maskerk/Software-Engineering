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
	// for(iter=num_index.begin();iter != num_index.end();iter++)
	while(num_index.begin() != num_index.end())
	{
		result += num_index.begin()->first;

		//前边那个减去
		//num_index.begin()->first -= num_index.begin()->second - 1;
		//判断　-1
		int pre_pos = num_index.begin()->second - 1;
		while(arr_b[pre_pos] == -1 && pre_pos > 0)
		{
			pre_pos--;
		}
		if(arr_b[pre_pos] != -1)
		{
			for(iter = num_index.begin();iter != num_index.end();iter++)
			{
				
				if(iter->second == pre_pos)
				{
					// iter->first -= arr_b[ num_index.begin()->second ];/////////////////////
					num_index.insert(pair<unsigned long,int>(iter->first - arr_b[pre_pos],iter->second));
					num_index.erase(iter);
					//判断　+1
					//iter.first += arr_b[num_index.begin()->second + 1];

					//arr_b[num_index.begin()->second] = - 1;
				}
			}
		}
		
		//后边那个减去
		int aft_pos = num_index.begin()->second + 1;
		while(arr_b[aft_pos] == -1 && aft_pos < n)
		{
			aft_pos++;
		}
		if(arr_b[aft_pos] != -1)
		{
			for(iter = num_index.begin();iter != num_index.end();iter++)
			{
				
				if(iter->second == aft_pos)
				{
					// iter->first -= arr_b[num_index.begin()->second];///////////////////////
					num_index.insert(pair<unsigned long,int>(iter->first - arr_b[aft_pos],iter->second));
					num_index.erase(iter);
					//判断　+1
					//iter.first += arr_b[num_index.begin()->second + 1];

					//arr_b[num_index.begin()->second] = - 1;
				}
			}
		}
		

		//arr_b 置-1
		arr_b[num_index.begin()->second] = -1;

		//剔除
		num_index.erase(num_index.begin());

		//前边的加上后边
		if(arr_b[pre_pos] != -1 && arr_b[aft_pos] != -1)	
		{
			for(iter = num_index.begin();iter != num_index.end();iter++)
			{
				if(iter->second == pre_pos)
				{
					// iter->first += arr_b[aft_pos];//////////////////////////////////////
					num_index.insert(pair<unsigned long,int>(iter->first + arr_b[aft_pos],iter->second));
					num_index.erase(iter);
				}
			}
		}
		//后边那个加上前边
		if(arr_b[pre_pos] != -1 && arr_b[aft_pos] != -1)
		{
			for(iter = num_index.begin();iter != num_index.end();iter++)
			{
				if(iter->second == aft_pos)
				{
					//iter->first = iter->first+arr_b[pre_pos];//////////////////////////
					num_index.insert(pair<unsigned long,int>(iter->first + arr_b[pre_pos],iter->second));
					num_index.erase(iter);
					//num_index.insert(pair<unsigned long,int>(num_sum[i],i));
				}
			}
		}

	}

	cout << result << endl;

	// 	 

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

