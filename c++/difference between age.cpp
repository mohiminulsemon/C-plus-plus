///difference between age
#include<iostream>
using namespace std;
class age
{
    int day;
    int month;
    int year;
public:
    void get_input()
    {
       cin>>year>>month>>day;
    }
    void show_age()
    {
        cout<<year<<month<<day;
    }
    void differ(age,age);
};
void age::differ(age d1,age d2)
{
    day= d1.day-d2.day;
    if(day<0) day=30-d2.day;
    month=d1.month-d2.month;
    if(month<0) month=12-d2.month;
    year=d1.year-d2.year;
}

int main()
{
    age x,y,z;
    x.get_input();
    y.get_input();
    z.differ(x,y);
    z.show_age();
}


