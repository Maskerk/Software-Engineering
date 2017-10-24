#include <iostream>
#include <string>
#include <ctime>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

#define N_department 20
#define N_student 300

void departRandom()
{
	int i,l,num_free;
	string label_interest[5] = {"ping-pang","football","basketball","opera","draw"};
	string free_week[7] = {"1","2","3","4","5","6","7"};
	string free_class[11] = {"A","B","C","D","E","F","G","H","I","J","K"};
	string name_part;
	int top_limit,num_interest;
	vector<string> vec_interest,vec_routine;
	vector<string>::iterator itr;
	ofstream out;
	out.open("department_input.txt");

	for(l = 0;l < N_department;l++)
	{
		name_part = "part"+to_string(l);//部门名称 part0~partN
		top_limit=rand() % 16;//随机上限 0~15
		
		num_interest = rand() % 5;//随机5个兴趣标签
		for(i = 0;i < num_interest;i++)
		{
			int random = rand() % 5;
			//随机生成一个数 与之前的数不同 生成数大小0~4 生成num_interest次
			if(i == 0)	vec_interest.push_back(label_interest[random]);
			else
			{
				itr = find(vec_interest.begin(),vec_interest.end(),label_interest[random]);
				if(itr != vec_interest.end())//说明重复了
				{
					--i;
					continue;
				}
				else	vec_interest.push_back(label_interest[random]);
			}
			
		}
		num_free = rand() % 12;//0~11个常规活动时间
		for(i = 0;i < num_free;i++)
		{
			int j = rand() % 7;
			int k = rand() % 11;
			string route = free_week[j] + free_class[k];
			if(i == 0)	vec_routine.push_back(route);
			else
			{
				itr = find(vec_routine.begin(),vec_routine.end(),route);
				if(itr != vec_routine.end())//说明与之前重复  重新进行一次随机生成空余时间
				{
					--i;
					continue;
				}
				else	vec_routine.push_back(route);
			}
		}
		//输出到文件部门信息

		out << name_part << '\n';
		out << top_limit << '\n';
		out << num_interest << '\n';
		for(itr = vec_interest.begin();itr != vec_interest.end();itr++)
		{
			out << *itr << '\n';
		}
		out << num_free<< '\n';
		for(itr = vec_routine.begin();itr != vec_routine.end();itr++)
		{
			out << *itr << '\n';
		}

		vec_interest.clear();
		vec_routine.clear();
	}
	out.close();
}

void studentRandom()
{
	int num_free,num_interest;
	int i,j,num_will_part;
	float grade;
	int id;
	vector<string>::iterator itr;
	vector<string> vec_free,vec_interest,vec_will_part;
	string free_week[7] = {"1","2","3","4","5","6","7"};
	string free_class[11] = {"A","B","C","D","E","F","G","H","I","J","K"};
	string label_interest[5] = {"ping-pang","football","basketball","opera","draw"};
	string will_part[20]={"part0","part1","part2","part3","part4","part5","part6","part7","part8",
							"part9","part10","part11","part12","part13","part14","part15",
							"part16","part17","part18","part19"};
	ofstream out;
	out.open("student_input.txt");
	for(j = 0;j < N_student;j++)
	{
		//生成七位数学号
		id = rand() % 10000000;
		while(id < 1000000 || id > 9999999)
		{
			id = rand() % 10000000;
		}
		//生成绩点
		grade = (rand() % 12) / 2.8;
		num_will_part = rand() % 5;//随机5个以内志愿部门
		for(i = 0;i < num_will_part;i++)
		{
			int random = rand() % 20;//part0~part19
			if(i == 0)	vec_will_part.push_back(will_part[random]);
			else
			{
				itr = find(vec_will_part.begin(),vec_will_part.end(),will_part[random]);//查询向量中有没有
				if(itr != vec_will_part.end())//说明重复了
				{
					//cout << 999 << endl;
					--i;
					//continue;
				}
				else	vec_will_part.push_back(will_part[random]);
			} 

		}
		num_interest = rand() % 5;//随机5个兴趣标签
		 for(i = 0;i < num_interest;i++)
		 {
			int random = rand() % 5;
			if(i == 0)	vec_interest.push_back(label_interest[random]);
			else
			{
			// 	//随机生成一个数 与之前的数不同 生成数大小0~4 生成num_interest次
			 	itr = find(vec_interest.begin(),vec_interest.end(),label_interest[random]);
			 	if(itr != vec_interest.end())//说明重复了
				{
					--i;
				}
				else	vec_interest.push_back(label_interest[random]);
			}
		 }
		num_free = rand() % 12;//0~11个空余时间
		 for(i = 0;i < num_free;i++)
		{
			int j = rand() % 7;
			int k = rand() % 11;
			string route = free_week[j] + free_class[k];
			if(i == 0)	vec_free.push_back(route);
			else
			{
				itr = find(vec_free.begin(),vec_free.end(),route);
				if(itr != vec_free.end())//说明与之前重复  重新进行一次随机生成空余时间
				{
					--i;
					continue;
				}
				else	vec_free.push_back(route);
			}
			
		}	

		out << id << '\n';
		out << grade << '\n';
		out << num_will_part << '\n';
		for(itr = vec_will_part.begin();itr != vec_will_part.end();itr++)
		{
			out << *itr << '\n';
		}
		out << num_interest<< '\n';
		for(itr = vec_interest.begin();itr != vec_interest.end();itr++)
		{
			out << *itr << '\n';
		}
		out << num_free << '\n';
		for(itr = vec_free.begin();itr != vec_free.end();itr++)
		{
			out << *itr << '\n';
		}
		vec_free.clear();
		vec_interest.clear();
		vec_will_part.clear();

	}
	out.close();
}

int main()
{
	srand((int)time(0));
	studentRandom();
	departRandom();
	return 0;
}