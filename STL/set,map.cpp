#include<iostream>
#include<set>
#include<map>
using namespace std;
int test=1;

template<typename T>
void display(set<T> s)
{
    cout<<"test ="<<test++<<endl;
    for(auto i:s)
    {
        cout<<i<<" ";
    }
    cout<<endl<<endl;
}

template<typename T1,typename T2>
void display1(map<T1,T2> s)
{
    cout<<"test ="<<test++<<endl;
    for(auto i:s)
    {
        cout<<i.first<<" : "<<i.second<<endl;
    }
    cout<<endl<<endl;
}

template<typename T,typename T1>
void display2(map<T,set<T1> > s)
{
    cout<<"test ="<<test++<<endl;
    for(auto i:s)
    {
        cout<<i.first<<" [";
        for(auto j: i.second)
        {
            cout<<j<<" ";
        }
        cout<<"]"<<endl;
    }
    cout<<endl<<endl;
}

void Set()
{
    set<int> s{1,1,2,3,4,4,5,6,7,7};
    display(s);

    s.insert(0);
    s.insert(8);
    display(s);

    if(s.count(8)) cout<<"8 is in the set"<<endl;//in set count returns 0 or 1
    else cout<< "8 is not in the set"<<endl;

    s.erase(5);
    display(s);

    auto it=s.find(7);
    if(it != s.end())
    {
        cout<<"found "<<*it<<endl;
        s.erase(it);
    }
    display(s);

    s.clear();
    if(s.empty()) cout<<"the set is empty"<<endl<<endl;
    else cout<<"the set is not empty"<<endl<<endl;
}

void Map()
{
    map<string,int> m{{"mohiminul",1}};
    display1(m);

    pair<string,int> p{"semon",2};
    m.insert(p);
    display1(m);

    m.insert(pair<string,int>("ahmadullah",3));
    display1(m);

    m.insert(make_pair("eram",4));
    display1(m);

    m["musa"]=5;
    display1(m);

    m["eram"]=5;
    m.at("musa") -= 1;
    display1(m);

    m.erase("ahmadullah");
    display1(m);

    auto It=m.find("musa");
    if(It != m.end()) cout<<"found : "<<It->first<<":"<<It->second<<endl<<endl;

    m.clear();
    display1(m);

    map<string,set<int> > n{
    {"semon",{1,3,5}},
    {"eram",{4,6,9}}
    };
    display2(n);

    n["semon"].insert(7);
    display2(n);

    auto itr = n.find("eram");
    if(itr != n.end())
    {
        itr->second.insert(5);
    }
    display2(n);


}

int main()
{
    Set();
    Map();
}
