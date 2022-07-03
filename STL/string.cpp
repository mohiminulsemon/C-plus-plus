#include<iostream>
#include<string>
#include<algorithm>//for use transform and toupper
#include<ios>//for <stremsize>
#include<limits>//for numeric_limits
using namespace std;

int main()
{
    string s("first string");
    cout<<"s = "<<s<<endl;

    string s1(s);
    cout<<"s1 = "<<s1<<endl;

    string s2(5,'#');
    cout<<"s2 = "<<s2<<endl;

    string s3(s,6,4);//6th index,4 characters of string s
    cout<<"s3 = "<<s3<<endl;

    string s4(s1.begin(),s1.begin()+5);
    cout<<"s4 = "<<s4<<endl;

    string s5=s3;
    cout<<"s5 = "<<s5<<endl;

    s3.clear();
    cout<<"size of s3 = "<<s3.size()<<" or "<<s3.length()<<endl;

    s4.at(0)='b';
    s4[1]='u';
    cout<<"s4 = "<<s4<<endl;

    cout<<"s.front = "<<s.front()<<" s.back = "<<s.back()<<endl;

    s4.append(" string");
    cout<<"s4 = "<<s4<<endl;

    string concatenate= s +" " + s4;
    cout<<"after concatenate: "<<concatenate<<endl;

    s4.append(s5,0,4);
    cout<<"s4 = "<<s4<<endl;


    int pos=s.find(s5);
    if(pos != string::npos)//string::npos = -1 or the end of the string
        cout<<"s5 found at "<<pos<<endl;
    else cout<<"s5 not found in s"<<endl;

    cout<<"substring of s = "<<s.substr(6,3)<<endl;
    cout<<"substring of s = "<<s.substr(4)<<endl;

    s.erase(6,6);
    cout<<"after erase,s = "<<s<<endl;

    s4.erase(s4.begin()+6,s4.end());
    cout<<"after erase,s4 = "<<s4<<endl;

    s4.replace(6,10,"out gently");//(a,b,str) means replaces b characters starting from index a by str
    cout<<"s4 = "<<s4<<endl;

    string s6=("google com bd");
    string s7=("%20");

    int n=0;
    while((n = s6.find(" ")) != string::npos)
    {
        s6.replace(n,1,s7);
        n += s7.length();
    }

    cout<<s6<<endl;

    if(s.compare(s1) ==0) cout << "strings are equal"<<endl;
    else cout<<"strings aren't equal"<<endl;

    cout<<"........................................."<<endl<<endl;

    string str("pushback");
    cout<<str<<endl;
    str.push_back('s');//enter a character at the end of string
    cout<<"after push back: "<<str<<endl;

    str.pop_back();
    cout<<"after pop back: "<<str<<endl;

    cout<<"after forward iterator:"<<endl;

    for(auto it=str.begin();it!=str.end();it++)
    {
        cout<<*it;
    }
    cout<<endl;

    cout<<"after backward iterator:"<<endl;

    for(auto it=str.rbegin();it!=str.rend();it++)
    {
        cout<<*it;
    }
    cout<<endl;

    string str1("popback");

    cout << "The strings before swapping is : ";
    cout << str <<" " <<str1<< endl;

    str.swap(str1);

    cout << "The strings after swapping is : ";
    cout << str <<" " <<str1<< endl;

    str.insert(7," push");
    cout<<"after inserting from 7th(0 based) index: "<<str<<endl;

    transform(str.begin(),str.end(),str.begin(),::toupper);//transform(starting index,ending index,output begin index,operattion);
    cout<<str<<endl;

    cout<<"........................................."<<endl<<endl;

    string fullname1,fullname2;
    cout<<"enter fullname1: "<<endl;
    cin>>fullname1;//takes input before spaces

    cin.ignore(numeric_limits<streamsize>::max(),'\n');//cin.ignore(1000,'\n');//for ignoring the input buffer
    cout<<"fullname1: "<<fullname1<<endl;

    cout<<"enter fullname2: "<<endl;
    getline(cin,fullname2);//takes input as full line
    cout<<"fullname2: "<<fullname2<<endl<<endl;



}
