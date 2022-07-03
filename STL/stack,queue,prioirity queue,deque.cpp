#include<iostream>
#include<stack>
#include<queue>
#include<deque>
#include<algorithm>
using namespace std;

int test=1;

template<typename T>
void display(stack<T> s)
{
    cout<<"test = "<<test++<<endl;
//    for(auto i: s)//no iterator supported(stack,queue and priority_queue)
//    {
//        cout<<i<<" ";
//    }
    while(!s.empty())
        {
            T element=s.top();
            cout<<element<<" ";
            s.pop();
        }
    cout<<endl<<endl;
}

template<typename T>
void display1(queue<T> s)
{
    cout<<"test = "<<test++<<endl;
     while(!s.empty())
        {
            T element=s.front();
            cout<<element<<" ";
            s.pop();
        }
    cout<<endl<<endl;
}

template<typename T>
void display2(priority_queue<T> s)
{
    cout<<"test = "<<test++<<endl;
    while(!s.empty())
        {
            T element=s.top();
            cout<<element<<" ";
            s.pop();
        }
    cout<<endl<<endl;
}

template<typename T>
void display2(priority_queue<T,vector<T>,greater<T> > s)
{
    cout<<"test = "<<test++<<endl;
    while(!s.empty())
        {
            T element=s.top();
            cout<<element<<" ";
            s.pop();
        }
    cout<<endl<<endl;
}

template<typename T>
void display3(deque<T> s)
{
    cout<<"test = "<<test++<<endl;
    for(auto i: s)
    {
        cout<<i<<" ";
    }
    cout<<endl<<endl;
}

int main()
{
    stack<int> s;//last in,first out

    s.push(10);
    s.push(30);
    s.push(50);

    display(s);
    cout<<"top = "<<s.top()<<endl;
    cout<<"size =  "<<s.size()<<endl<<endl;
    s.pop();
    display(s);

    queue<int> q;//first in,first out

    q.push(10);
    q.push(30);
    q.push(50);

    display1(q);
    cout<<"front = "<<q.front()<<" back = "<<q.back()<<endl;
    cout<<"size =  "<<q.size()<<endl<<endl;
    q.back()=60;
    q.pop();
    display1(q);

    priority_queue<int> pq;

    pq.push(5);
    pq.push(8);
    pq.push(1);
    pq.push(3);
    pq.push(2);

    display2(pq);
    cout<<"top = "<<pq.top()<<endl;
    cout<<"size =  "<<pq.size()<<endl<<endl;

    pq.pop();
    display2(pq);

    priority_queue<int,vector<int>,greater<int> > pq1;

    pq1.push(5);
    pq1.push(8);
    pq1.push(1);
    pq1.push(3);
    pq1.push(2);

    display2(pq1);
    cout<<"top = "<<pq1.top()<<endl;
    cout<<"size =  "<<pq1.size()<<endl<<endl;

    pq1.pop();
    display2(pq1);


    deque<int> d(5,3);
    display3(d);

    d.push_back(5);
    d.push_front(1);
    display3(d);

    d.at(2)=4;
    d[3]=6;
    display3(d);

    cout<<"front = "<<d.front()<<" back = "<<d.back()<<endl;
    cout<<"size =  "<<d.size()<<endl<<endl;

    d.pop_front();
    d.pop_back();
    display3(d);

    sort(d.begin(),d.end());//that means deque support all iterators;
    display3(d);


}
