///create bank account
#include<iostream>
using namespace std;
class bank
{
    int amount;
public:
    void set_amount(int x)
    {
        amount=x;
    }
    void deposit(int x)
    {
        amount+=x;
    }
    void withdraw(int x)
    {
        amount-=x;
    }
    int balance_check()
    {
        return amount;
    }
};
int main()
{
    bank semon;
    semon.set_amount(500);
    semon.deposit(100);
    semon.withdraw(200);
    cout<<"balance: "<<semon.balance_check();
}
