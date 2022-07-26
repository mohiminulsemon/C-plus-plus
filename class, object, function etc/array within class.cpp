///array within class(array of member function of a class)
#include<iostream>
using namespace std;
class student
{
public:
    char name[30];
    int roll,i;
    int marks[5];
    void input()//declaring function inside class
    {
       cout<<"enter name & roll:"<<endl;
       gets(name);
       cin>>roll;
       cout<<"enter marks:"<<endl;
       for(i=0;i<5;i++)//marks is a member function and it is declared as array
       {
           cin>>marks[i];
       }
   }
   void output();//declaring function outside the class
};

 void student::output()//return_type class name :: function name()
 {
     cout<<"name:"<<name<<endl;
     cout<<"roll:"<<roll<<endl;
     for(i=0;i<5;i++)
     {
        cout<<"marks:"<<marks[i]<<endl;
     }
 }

 int main()
 {
   student s;
   s.input();
   s.output();
 }
