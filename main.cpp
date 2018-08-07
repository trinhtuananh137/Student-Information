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
};

void getInfor( int &i, int &ID, string &name, int &age, float &mark_1, float &mark_2, float &mark)
{
    cout <<"--------------" << endl;
    cout <<"Sinh vien thu " << i + 1 << endl;
    cout <<"--------------" << endl;
    cout << "Nhap ID sinh vien: ";
    cin >> ID;
    fflush(stdin);
    cout << "Nhap ten sinh vien:";
    getline(cin,name);
    cout << "Nhap tuoi sinh vien:";
    cin >> age;
    cout << "Nhap diem ky 1 cua thang nay: ";
    cin >> mark_1;
    cout << "Nhap diem ky 2 cua thang nay: ";
    cin >> mark_2;
    mark = ((mark_1 + mark_2)/2);
}

void printInfor(student s)
{
    cout << s.ID << "_" << s.name << "_" << s.mark << endl;
}

int main()
{
    char s;
    int N;
    int i;
    int j = -1;
    int k = -1;
    int num_max = 0;
    int num_improve = 0;
    float group_mark = 0;
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
        for(i = 0; i < N ; i++)
        {
            getInfor(i, group[i].ID, group[i].name, group[i].age, group[i].mark_1, group[i].mark_2, group[i].mark);
        }
        system("cls");
        mP = group[0].mark;
        for(i = 0; i < N ; i++)
        {
            group_mark = (group_mark * i + group[i].mark)/(i+1);
            if (group[i].mark > mP)
                mP = group[i].mark;
        }
        for (i = 0; i < N; i++)
        {
            if (group[i].mark == mP)
            {
                j = j+1;
                num_max = num_max + 1;
                top[j] = group[i];
            }
            if (group[i].mark_2 > group[i].mark_1)
            {
                k = k + 1;
                improve[k] = group[i];
            }
        }
        system("cls");
        cout << "KET QUA THONG KE DUOC" << endl;
        cout << "---------------------" << endl;
        cout << "So sinh vien cua lop: " << N << endl;
        cout << "Diem trung binh cuoi nam cua ca lop: " << group_mark << endl;
        cout << "Nhung sinh vien co diem cuoi nam cao nhat: " << endl;
        if (num_max == 1)
        {
            printInfor(top[0]);
        }
        else
        {
            for (i = 0; i < num_max ; i++)
            {
                cout << i + 1 << "> ";
                printInfor(top[i]);
            }
        }
        cout << "Nhung sinh vien co tien bo: " << endl;
        if (num_improve == 1)
        {
            printInfor(improve[0]);
        }
        else if( num_improve == 0)
            cout << "Nobody :(" << endl;
        else
        {
            for (i = 0; i < num_improve ; i++)
            {
                cout << i + 1 << "> ";
                printInfor(improve[i]);
            }
        }
        cout << "Ban co muon tiep tuc (c/k): ";
        cin >> s;
    }
    while(s != 'k');
}

