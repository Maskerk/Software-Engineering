#include <iostream>
#include <map>

using namespace std;

multimap<int ,int> num_index;
int n;
int result = 0;
int main()
{
	int i;
	multimap<int,int>::iterator iter;
	cin >> n;
	int arr_a[200],arr_b[200];
	//input
	for(i = 0;i < n;i++)	
		cin >> arr_a[i];
	for(i = 0;i < n;i++)	
		cin >> arr_b[i];
	for(i = 0;i < n;i++)	
		num_index.insert(pair<int,int>(arr_b[i],i));
	
	for(i = n;i > 0;i--)
	{
		int j = 0;
		iter = --num_index.end();
		result += arr_a[iter->second];

		if(int(iter->second) - 1 >= 0)
		{
			j = int(iter->second) - 1;
			while(arr_b[j] == -1 && j >= 0)		
				j--;
			if(arr_b[j] != -1 && j >= 0)		
				result += arr_b[j];
		}
		if(int(iter->second) + 1 < n)
		{
			j = int(iter->second) + 1;
			while(arr_b[j] == -1 && j < n)
				j++;
			if(arr_b[j] != -1 && j < n)
				result += arr_b[j];
		}
		arr_b[iter->second] = -1;
		num_index.erase(iter);
	}
	cout << result << endl;
	return 0;
}