#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>
using namespace std;

// 在生成数独矩阵时，左上角的第一个数为：（学号后两位相加）% 9 + 1
// 例如：学生A学号后2位是80，则该数字为（8+0）% 9 + 1 = 9

int N=0,now_N = 0;
int A[9];
int global_arr[9][9];
string FileName = "sudoku.txt";

//输出数独到txt文件
int arr_write(string name,int arr[][9])
{

    ofstream out;
    string filename = name;
    if(now_N == 1 || N == 0)
    {
        out.open(filename);
    }
    else
        out.open(filename,std::ofstream::app);

    if(!out)
    {
        cerr << "open the file \""<< filename <<"\" failed !" << endl;
        return 1;
    }


        for(int i = 0;i < 9;i++)
        {
            for(int j = 0;j < 9;j++)
            {
                if(N != 0)
                    out << arr[i][j] << ' ';

            }
            out << '\n';
        }
        out << '\n';

    out.close();

    return 0;
}

void build()
{
    int move[4];

    for(int q = 0;q < 3;q++)
    {
        if(q != 0)
        {
            //左移4位
            for(int j = 0;j < 4;j++)//左移4位
            {
                move[j] = A[j];
            }
            for(int j = 4;j < 9;j++)//左移4位
            {
                A[j-4]  = A[j];
            }
            for(int j = 5;j < 9;j++)//左移4位
            {
                A[j]  = move[j-5];
            }
        }
        //赋值第 0 3 6行
        for(int j = 0;j < 9;j++)
        {
            global_arr[q*3][j] = A[j];
        }

        for(int i = 1;i < 3;i++)
        {
            for(int j = 0;j < 3;j++)//左移三位
            {
                move[j] = A[j];
            }
            for(int j = 3;j < 9;j++)//左移三位
            {
                A[j-3]  = A[j];
            }
            for(int j = 6;j < 9;j++)//左移三位
            {
                A[j]  = move[j-6];
            }

            for(int j = 0;j < 9;j++)
            {
                global_arr[q*3+i][j] = A[j];
            }
        }



    }
     if(global_arr[0][0] == 7)//学号判断
     {
        arr_write(FileName,global_arr);
        now_N++;
     }
}


void my_rank(int depth1,int *rand_arr)
{
    if(now_N == N)  return   ;
    int depth = depth1;
    bool i_jump = false;
    if(depth == 9)
    {

        for(int i = 0;i < 9;i++)
        {

            A[i] = rand_arr[i];
        }


        build();
        return ;
    }
    int new_A[9];
    for(int i = 0;i < 9;i++)
    {
        new_A[i] = rand_arr[i];
    }
    //放置 i
    //for(int i = 1;i < 10;i++)
    //for(int i = 8;i > -1 ;i--)
    for(int i = 1;i < 10;i++)
    {

        if(depth == 0)
        {
            new_A[0] = 7;//修改学号位置
            my_rank(depth+1,new_A);
        }
        else
        {
            int j;
            for(j = 0;j < depth;j++)
            {
                // if repeat -- break
                if(new_A[j] == i)
                {
                    i_jump = true;
                    break;
                }

            }
            if(i_jump == true)
            {
                i_jump = false;
                continue;
            }
            new_A[j] = i;
            my_rank(depth+1,new_A);
        }
    }

}

int main(int argc, char *argv[])
{

    N = atoi(argv[2]);
    if(N == 0)
    {
         cout << "对不起，输入数据非法！ " << endl;
        arr_write(FileName,global_arr);
    }
    else
    {
        N++;
        if(N -1 < 0 || N -1  > 40320)
            cout << "对不起，最大尽可输出40320个数独，输入数据超出范围！ " << endl;
        else
            my_rank(0,A);
    }
    return 0;
}
