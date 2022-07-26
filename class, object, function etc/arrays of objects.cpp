///arrays of objects
#include<iostream>
using namespace std;
class student
{
public:
    char name[30];
    int roll;
    int marks1,marks2,marks3;
    void input()
    {
       cout<<"enter name & roll:"<<endl;
       gets(name);
       cin>>roll;
       cout<<"enter marks:"<<endl;
       cin>>marks1>>marks2>>marks3;
       getchar();
   }
   void output();
};

 void student::output()
 {
     cout<<"name:"<<name<<endl;
     cout<<"roll:"<<roll<<endl;
     cout<<"marks1-"<<marks1<<endl;
     cout<<"marks2-"<<marks2<<endl;
     cout<<"marks3-"<<marks3<<endl;
 }

 int main()
 {
    int i;
   student s[5];
  for(i=0;i<5;i++)
  {
      s[i].input();
  }
  for(i=0;i<5;i++)
  {
      s[i].output();
  }
 }

