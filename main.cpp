#include <iostream>
#include <string>
#include <stdio.h>
#include <windows.h>
#include <math.h>

using namespace std;

struct student
{
    int ID;
    string name;
    int age;
    float mark_1;
    float mark_2;
    float mark;
    void setInfor (student s)
    {
        cout << "Nhap ID sinh vien: ";
        cin >> s.ID;
        fflush(stdin);
        cout << "Nhap ten sinh vien:";
        getline(cin,s.name);
        cout << "Nhap tuoi sinh vien:";
        cin >> s.age;
        cout << "Nhap diem ky 1 cua thang nay: ";
        cin >> s.mark_1;
        cout << "Nhap diem ky 2 cua thang nay: ";
        cin >> s.mark_2;
        mark = ((mark_1 + mark_2)/2);
    }
};

void printList (student list[], int num );

float findMax (student group[], int N);

float meanGroup (student group[] , int N);

void setTopList (student group[], student *top , int N , float mP , int &num_max );

void setImproveList (student group[], student *improve , int N , int &num_improve);

int main()
{
    char s;
    int N;
    int num_max = 0;
    int num_improve = 0;
    float mean_group = 0;
    float mP;
    do
    {
        cout << "CHUONG TRINH THONG KE" << endl;
        cout << "---------------------" << endl;
        cout << "Nhap so sinh vien: ";
        cin >> N;
        student group[N];
        student top[N];
        student improve[N];
        for(int i = 0; i < N ; i++)
        {
            cout <<"--------------" << endl;
            cout <<"Sinh vien thu " << i + 1 << endl;
            cout <<"--------------" << endl;
            group[i].setInfor(group[i]);
        }
        system("cls");
        mean_group = meanGroup(group , N);
        mP = findMax(group , N);
        setTopList (group,top,N,mP,num_max);
        setImproveList(group,improve,N,num_improve);
        system("cls");
        cout << "KET QUA THONG KE DUOC" << endl;
        cout << "---------------------" << endl;
        cout << "So sinh vien cua lop: " << N << endl;
        cout << "Diem trung binh cuoi nam cua ca lop: " << mean_group << endl;
        cout << "Nhung sinh vien co diem cuoi nam cao nhat: " << endl;
        printList (top, num_max);
        cout << "Nhung sinh vien co tien bo: " << endl;
        printList(improve, num_improve);
        cout << "Ban co muon tiep tuc (c/k): ";
        cin >> s;
        system ("cls");
    }
    while(s != 'k');
}

void printList (student list[], int num )
{
    if (num == 1)
        cout << list[0].ID << "_" << list[0].name << "_" << list[0].mark << "p" << endl;
    else
        for (int i = 0; i < num ; i++)
        {
            cout << i + 1 << "> " << list[i].ID << "_" << list[i].name << "_" << list[i].mark << "p" << endl;
        }
}

float findMax (student group[], int N)
{
    int i;
    float mP = group[0].mark;
    for (i = i; i < N ; i++)
    {
        if (group[i].mark > mP) mP = group[i].mark;
    }
    return mP;
}

float meanGroup (student group[] , int N)
{
    float mean_group, sum_group = 0;
    for (int i = 0; i < N ; i++)
    {
       sum_group = sum_group + group[i].mark;
    }
    return (sum_group / N);
}

void setTopList (student group[], student *top , int N , float mP , int &num_max )
{
    int j = -1;
    num_max = 0;
    for (int i = 0; i < N ; i++)
    {
        if (group[i].mark == mP)
        {
            j = j + 1;
            num_max = num_max + 1;
            *(top + j) = group[i];
        }
    }
}

void setImproveList (student group[], student *improve , int N , int &num_improve)
{
    int k = -1;
    num_improve = 0;
    for (int i = 0; i < N ; i++)
    {
        if (group[i].mark_1 < group[i].mark_2)
        {
            k = k + 1;
            num_improve = num_improve + 1;
            *(improve + k) = group[i];
        }
    }
}



