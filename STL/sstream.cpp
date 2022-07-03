#include<iostream>
#include<sstream>
#include<map>
using namespace std;

int main()
{
    string str("my name is semon");
    cout<<str<<endl;
    stringstream s(str);//or s<<str;//use for storing the string in the stream and splitting the str into words
    string word;//for storing the words
    int count=0;
    while(s >> word)//<< —> add a string to the stringstream object.
                    //>> —> read something from the stringstream object,
    {
        count++;
    }
    cout<<count<<endl;

    map<string,int> ms;
    stringstream s1(str);

    while(s1 >> word)
    {
        ms[word]++;
    }

    for(auto it=ms.begin();it!=ms.end();it++)
    {
        cout<<it->first<<"->"<<it->second<<endl;
    }

    cout<<"..............................."<<endl;

    string str1("this line should be without space");
    cout<<str1<<endl;

    stringstream ss;
    ss << str1;
    string temp;

    str1="";//making str1 empty;

    while(!ss.eof())
    {
        ss >> temp;

        str1 += temp;
    }

    cout<<str1<<endl;

    cout<<"..............................."<<endl;

    string num("12345");

    stringstream n(num);

    int x;
    n >> x;
    cout<<"string to int: "<<x<<endl;


    string num1("1234");
    string num2("3.143");

    int number1;
    double number2;

    number1 = stoi(num1);//string to int
    number2 = stod(num2);//string to double

    cout<<"stoi("<<num1<<") = "<<number1<<endl;
    cout<<"stod("<<num2<<") = "<<number2<<endl;

    cout<<"..............................."<<endl;

    int y=13455;
    string z;

    z = to_string(y);
    cout<<z<<endl;

}
