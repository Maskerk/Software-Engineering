#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <fstream>  

using namespace std;

#define N_department 20
#define N_student 300

class Department;
class Student;

int pos = 0,pos1 = 0,pos2 = 0;

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
		return num_stu;
	}

	// void addStuNum()
	// {
	// 	num_stu_in_part++;
	// }

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
		return sdt_dpt.size();/////////////////
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
	ifstream in;
	char buffer[256]; 
	in.open("department_input.txt");
	for(int i = 0;i < N_department;i++)
	{
		in.getline(buffer,100);
		name_part =  buffer;//部门名称
		//cout << name_part << endl;
		in.getline(buffer,100);  
		top_limit = atoi(buffer);//人数上限
		in.getline(buffer,100);  
		num_tag = atoi(buffer);//特点标签个数
		for(j = 0;j < num_tag;j++)
		{
			in.getline(buffer,100);  
			str = buffer;
			tag.push_back(str); //特点标签
		}
		in.getline(buffer,100);  
		num_routine = atoi(buffer);//常规活动时间个数
		
		for(j = 0;j < num_routine;j++)
		{
			in.getline(buffer,100);  
			str = buffer;
			routine.push_back(str); //常规活动时间
		}

		//创建该部门对象
		part[i] = new Department(name_part,top_limit,tag,routine);
		tag.clear();
		routine.clear();

		// vector<string> id;

		// id = part[i]->getParName();
		// cout << "id.size():" << id.size() << endl;

	}
	in.close();
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

	ifstream in;
	char buffer[256]; 
	in.open("student_input.txt");


	for(int i = 0;i < N_student;i++)
	{
		in.getline(buffer,100);  
		str = buffer;//学号
		id = str;
		in.getline(buffer,100);  
		grade = atof(buffer);//学分绩点
		in.getline(buffer,100);  
		num_sdt_dpt = atoi(buffer);//意愿部门个数

		for(j = 0;j < num_sdt_dpt;j++)
		{
			in.getline(buffer,100);  
			str = buffer;//意愿部门个数
			sdt_dpt.push_back(str);
		}
		in.getline(buffer,100);  
		num_interest = atoi(buffer);//兴趣标签个数
		for(j = 0;j < num_interest;j++)
		{
			in.getline(buffer,100);  
			str = buffer;//兴趣标签
			interest.push_back(str);
		}

		in.getline(buffer,100);  
		num_free_time = atoi(buffer);//空闲时间个数

		for(j = 0;j < num_free_time;j++)
		{
			in.getline(buffer,100);  
			str = buffer;//空闲时间段
			free_time.push_back(str);
		}

		//创建该对象
		stu[i] = new Student(id,grade,interest,sdt_dpt,free_time);

		interest.clear();
		sdt_dpt.clear();
		free_time.clear();

		

	}
	in.close();

}

void matchFree()
{
	//查看所有学生的空余时间是不是匹配自己申报部门的例会时间 如果不符合就排除该意愿
	int i,j,k,l;
	vector<string> *sdt_dpt;
	int begin_flag = 0;
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
		for(iter = sdt_dpt->begin();iter != sdt_dpt->end();)
		{
			if(begin_flag) begin_flag = 0;
			//cout << "总共志愿-----------------------------" << pos2++ << endl;
			 for(k = 0;k < N_department;k++)
			 {
				//if(*iter == "123")
			 	if( *iter == part[k]->getParName())//如果意愿部门就是该部门
			 	{
					 routine = part[k]->getRoutine();
					//查询空余时间是否包含该部门所有例会时间
					for(iter3 = routine.begin();iter3 != routine.end();iter3++)//例会时间片段
					{
						iter2 = find(free_time.begin(),free_time.end(),*iter3);
						if(iter2 != free_time.end())//在空余时间段中
						{
							//cout << "录取志愿--------------" << pos1++ << endl;
							continue;//检查下一个例会片段
						}
						else//不在空余时间段中  排除该志愿
						{
							//cout << "排除该志愿" << pos++ << endl;
							vector<string>::iterator iter_;
							iter_ = iter;
							if(iter == sdt_dpt->begin())	
							{
								sdt_dpt->erase(iter_);
								iter = sdt_dpt->begin();
								begin_flag = 1;
								break;

							}
							else
							{
								sdt_dpt->erase(iter_);
								--iter;
								break;
							}

							//++iter;
							
						}
					}
			 	}
			 }
			 if(!begin_flag) iter++;
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
						//vec->erase(iter2);//删除该学生的该志愿
						//查询下一个志愿
						break;
					}
				}
			}
		}

	}
}

void outputDepartment()
{

	vector<string> id;
	string part_name;
	int i;
	vector<string>::iterator id_iter;
	vector<string> * vec_str;
	for(i = 0;i < N_department;i++)
	{
		//cout << 123 << endl;
		//id = part[i]->getID();
		//cout << "id.size():" << id.size() << endl;
		//cout << part[i]->getParName() << endl;
		cout << "part" << i << "  :" << part[i]->getParStuNum() << endl;
		// for(id_iter = id.begin();id_iter != id.end();id_iter++)
		// {
		// 	cout << *id_iter << endl;
		// 	cout << 123 << endl;
		// }
	}
	for(i = 0;i < N_student;i++)
	{
		// vec_str = stu[i]->getSdtDpt();
		// cout << stu[i]->getNumSdtDpt() << endl;
		// for(id_iter = vec_str->begin();id_iter != vec_str->end();id_iter++)
		// {

		// 	cout << *id_iter << "  ";
		// }
		// cout << endl;


		//cout << 123 << endl;
		//id = part[i]->getID();
		//cout << "id.size():" << id.size() << endl;
		//cout << stu[i]->getID() << "--" << i << endl;
		// for(id_iter = id.begin();id_iter != id.end();id_iter++)
		// {
		// 	cout << *id_iter << endl;
		// 	cout << 123 << endl;
		// }
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