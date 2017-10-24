#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

#define N_department 20
#define N_student 300

class Department;
class Student;



//部门类
class Department
{
public:
	Department(){}
	Department(string name_part,int top_limit,vector<string> tag,vector<string> routine)
	{
		this->top_limit = top_limit;
		this->name_part = name_part;
		vector<string>::iterator iter;
		for(iter = tag.begin();iter!=tag.end();iter++)
			this->tag.push_back(*iter);

		for(iter = routine.begin();iter!=routine.end();iter++)
			this->routine.push_back(*iter);

		//num_stu_in_part++;
	}

	bool addStu(string id)
	{
		if(num_stu+1 <= top_limit)
		{
			++num_stu;
			this->id.push_back(id);
			return true;
		}
		return false;
	}
	int getTagLength()
	{
		vector<string>::iterator iter;
		int i;
		for(iter = tag.begin();iter!=tag.end();iter++)
			i++;
		return i;
	}

	int getParStuNum()
	{
		return num_stu_in_part;
	}

	void addStuNum()
	{
		num_stu_in_part++;
	}

	string getParName()
	{
		return name_part;
	}
	vector<string> getRoutine()
	{
		return routine;
	}
	vector<string> getID()
	{
		return id;
	}
private:
	int num_stu = 0;
	int top_limit,num_stu_in_part = 0;
	vector<string> tag;
	vector<string> routine;
	string name_part; 
	vector<string> id;

};

//学生类
class Student
{
public:
	Student(){}
	Student(string id,float grade,vector<string> interest,vector<string> sdt_dpt,vector<string> free_time)
	//Student(id,grade,interest,sdt_dpt,free_time);
	{
		num_free_time = 0;
		vector<string>::iterator iter_str;
		this->grade = grade;
		this->id = id;
		for(iter_str = interest.begin();iter_str != interest.end();iter_str++)
		{
			this->interest = interest;
		}
		vector<string>::iterator iter_Dep;
		for(iter_Dep = sdt_dpt.begin();iter_Dep != sdt_dpt.end();iter_Dep++)
		{
			this->sdt_dpt = sdt_dpt;
			++num_sdt_dpt;
		}

		for(iter_str = free_time.begin();iter_str != free_time.end();iter_str++)
		{
			this->free_time = free_time;
			++num_free_time;
		}

	}

	vector<string> * getSdtDpt()
	{
		return & sdt_dpt;
	}

	int getNumFreeTime()
	 {
		return num_free_time;
	}
	int getNumSdtDpt()
	{
		return num_sdt_dpt;
	}
	void addDepart()
	{
		++num_depart;
	}
	int numDepart()
	{
		return num_depart;
	}
	vector<string> getFreeTime()
	{
		return free_time;
	}
	float getGrade()
	{
		return grade;
	}
	string getID()
	{
		return id;
	}
private:
	float grade;//绩点
	int num_depart = 0;//////////////////////////////////
	int num_free_time,num_sdt_dpt = 0;
	vector<string> interest;
	//vector<Department> sdt_dpt;//学生选择部门
	vector<string> sdt_dpt;//学生选择部门
	vector<string> free_time;//空余时间段
	string id;
};


Student *stu[N_student];
Department *part[N_department];

void set_Department()
{
	int top_limit,num_tag,num_routine;
	vector<string> tag;
	vector<string> routine;
	string str;
	string name_part;
	int j;

	for(int i = 0;i < N_department;i++)
	{
		cout << "请输入第" << i << "个部门的部门名称：" << endl;
		cin >> name_part;
		cout << "请输入第" << i << "个部门需要学生数要求的上限：" << endl;
		cin >> top_limit;
		cout << "请输入第" << i << "个有几个特点标签：" << endl;
		cin >> num_tag;

		for(j = 0;j < num_tag;j++)
		{
			cout << "请输入第" << i << "个部门第" << j << "个兴趣标签：" << endl;
			cin >> str;
			tag.push_back(str); 
		}

		cout << "请输入第" << i << "个有几个常规活动时间：" << endl;
		cin >> num_routine;
		
		for(j = 0;j < num_routine;j++)
		{
			cout << "请输入第" << i << "个部门第" << j << "个常规活动时间：" << endl;
			cin >> str;
			routine.push_back(str); 
		}

		//创建该部门对象

		part[i] = new Department(name_part,top_limit,tag,routine);
		tag.clear();
		routine.clear();
	}
	
}

void set_Student()
{
	int num_interest,num_intest,num_sdt_dpt,num_free_time;
	float grade;
	vector<string> interest;
	string id;
	vector<string> sdt_dpt;//学生选择部门
	vector<string> free_time;//空余时间段
	int j;
	string str;
	string str1;
	for(int i = 0;i < N_student;i++)
	{
		cout << "请输入第" << i << "个学生的学号：" << endl;
		cin >> str1;
		cout << "请输入第" << i << "个学生的学分绩点：" << endl;
		cin >> grade;
		cout << "请输入第" << i << "个学生的意愿部门个数：" << endl;
		cin >> num_sdt_dpt;
		for(j = 0;j < num_sdt_dpt;j++)
		{
			cout << "请输入第" << i << "个学生第" << j << "个意愿部门：" << endl;
			cin >> str;
			sdt_dpt.push_back(str);
		}
		cout << "请输入第" << i << "个学生的兴趣标签个数：" << endl;
		cin >> num_interest;
		for(j = 0;j < num_interest;j++)
		{
			cout << "请输入第" << i << "个学生第" << j << "个兴趣标签：" << endl;
			cin >> str;
			interest.push_back(str);
		}

		cout << "请输入第" << i << "个学生的空闲时间段个数：" << endl;
		cin >> num_free_time;
		for(j = 0;j < num_free_time;j++)
		{
			cout << "请输入第" << i << "个学生第" << j << "个空闲时间段：" << endl;
			cin >> str;
			free_time.push_back(str);
		}

		//创建该对象
		stu[i] = new Student(id,grade,interest,sdt_dpt,free_time);

		interest.clear();
		sdt_dpt.clear();
		free_time.clear();

	}

}

void matchFree()
{
	//查看所有学生的空余时间是不是匹配自己申报部门的例会时间 如果不符合就排除该意愿
	int i,j,k,l;
	vector<string> *sdt_dpt;

	vector<string> free_time;
	vector<string> routine;
	for(i = 0;i < N_student;i++)
	{
		int num_free_time = stu[i]->getNumFreeTime();//空余时间片段个数
		int num_sdt_dpt = stu[i]->getNumSdtDpt();//意愿部门个数

		sdt_dpt = stu[i]->getSdtDpt();//第i个学生的部门意愿向量
		free_time = stu[i]->getFreeTime();

		//判断是否所有空余时间片段有没有对任意一个部门的所有例会都不适合的 有的话就排除该部门意愿

		vector<string>::iterator iter;
		vector<string>::iterator iter2;
		vector<string>::iterator iter3;
		for(iter = sdt_dpt->begin();iter != sdt_dpt->end();iter++)
		{
			for(k = 0;k < N_department;k++)
			{
				
				if(*iter == part[i]->getParName())//如果意愿部门就是该部门
				{
					routine = part[i]->getRoutine();
					//查询空余时间是否包含该部门所有例会时间
					for(iter3 = routine.begin();iter3 != routine.end();iter3++)//例会时间片段
					{
						iter2 = find(free_time.begin(),free_time.end(),*iter3);
						if(iter2 != free_time.end())//在空余时间段中
						{
							continue;//检查下一个例会片段
						}
						else//不在空余时间段中  排除该志愿
						{
							sdt_dpt->erase(iter);
						}
					}
				}
			}
		}
	}

}

void byGrade()
{
	map<float,Student*> rank_grade;
	vector<string> * vec;
	Student * stu_i;
	int i;
	for(i = 0;i < N_student;i++)
	{
		rank_grade.insert(pair<float,Student*>(stu[i]->getGrade(),stu[i]));
	}

	map<float,Student*>::reverse_iterator riter;
	vector<string>::iterator iter2;
	for(riter = rank_grade.rbegin();riter != rank_grade.rend() ;riter++)
	{
		stu_i = riter->second;
		vec = stu_i->getSdtDpt();
		for(iter2 = vec->begin();iter2 != vec->end();iter2++)
		{
			for(int j = 0;j < N_department;j++)
			{
				if(*iter2 == part[j]->getParName())
				{
					if(part[j]->addStu(stu_i->getID()))//进入部门&&如果进入部门返回成功
					{
						//(stu_i->getSdtDpt)->erase(iter2);
						vec->erase(iter2);//删除该学生的该志愿
					}
				}
			}
		}

	}
}

void outputDepartment()
{
	vector<string> id;
	vector<string>::iterator id_iter;
	for(int i = 0;i < N_department;i++)
	{
		id = part[i]->getID();
		for(id_iter = id.begin();id_iter != id.end();id_iter++)
		{
			cout << *id_iter << endl;
		}
	}
}
int main()
{
	set_Department();//部门信息录入
	set_Student();//学生信息录入
	matchFree();
	byGrade();
	outputDepartment();
	return 0;
}