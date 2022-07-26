///find the largest in a class
#include<iostream>
using namespace std;
class l_value
{
    int a,b;
    int largest();
public:
    void get_input();
    void show_output();
};
int l_value::largest()
{
    if(a>=b)
        return a;
    else
        return b;
}
void l_value::get_input()
{
    cin>>a>>b;
}
void l_value::show_output()
{
    cout<<a<<b<<endl;
    cout<<"largest value is : "<<largest();
}
int main()
{
    l_value x;
    x.get_input();
    x.show_output();
}
