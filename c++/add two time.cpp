///add two time
#include<iostream>
using namespace std;
class time
{
    int hour;
    int minute;
public:
    void get_input()
    {
       cin>>hour>>minute;
    }
    void show_time()
    {
        cout<<hour<<minute;
    }
    void sum(time,time);
};
void time::sum(time t1,time t2)
{
    minute=t1.minute+t2.minute;
    hour=minute/60;
    minute=minute%60;
    hour=hour+t1.hour+t2.hour;
}

int main()
{
    time x,y,z;
    x.get_input();
    y.get_input();
    z.sum(x,y);
    z.show_time();
}

