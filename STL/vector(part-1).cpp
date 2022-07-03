#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int test=1;

template <typename T>
void display(vector<T> &v)
{
    cout<<"test = "<<test++<<endl;
    for(auto x: v)
    {
        cout<<x<<" ";
    }
    cout<<endl<<endl;
}
template <typename T>
void display1(vector<T> &v)
{
    for(auto x: v)
    {
        cout<<x<<" ";
    }
    cout<<endl<<endl;
}

bool sort_(int x,int y)
        {
            return x>y;//it means whether x should go first or not,if true x will go before y else y will go before x
        }
int main()
{
    ios_base:: sync_with_stdio(false);// that line will speed up cin/cout like printf/scanf
    cin.tie(NULL);

    int i,x;

    vector<int> v{1,2,3,4,5};//initialization  like an array
    display(v);//1

    vector<int> v1(10);//like an array v[10];//it automatically assign 10 element to 0;
    display(v1);//2
    for(i=0;i<10;i++)
    {
        //scanf("%d",&v1[i]);
        v1[i]=i;

    }
    display1(v1);

    vector<int> v3(10,1);//initialize 10 array with 1;
    display(v3);//3
    v3.push_back(4);//push element after 10 element
    display1(v3);
    v3.pop_back();
    v3.pop_back();
    display1(v3);

    int n=10;
    v3.assign(n,5);
    display1(v3);//assign 10 values with 5

    vector<int> v4;
    v4.emplace_back(1);//emplace_back is more efficient than push_back
    display(v4);//4
    v4.pop_back();
    bool isemptpy = v4.empty();
    if(isemptpy) cout<<"empty"<<endl;
    else cout<<"not empty"<<endl;

    v4=v3;//replace v4 with v3
    display(v4);//5

    vector<int> vec{1,2,3,4,5};
    vector<int> vec1{10,20,30,40,50};

    cout<<"\ntest = "<<test++<<endl;//6
    cout<<vec.size()<<endl;
    cout<<vec.at(0)<<endl;
    cout<<vec[0]<<endl;
    cout<<vec.front()<<endl;
    cout<<vec.back()<<endl;

    display(vec1);//7
    auto low=lower_bound(vec1.begin(),vec1.end(),20);//low <=20
    cout<<"lower bound of 20: "<<*low<<endl;
    auto high=upper_bound(vec1.begin(),vec1.end(),20);//high > 20
    cout<<"upper bound of 20: "<<*high<<endl<<endl;

    vec.swap(vec1);
    display(vec);//8
    display1(vec1);

    auto it = find(vec.begin(),vec.end(),30);//vector<int>::iterator it == auto it
    int index = distance(vec.begin(),it);//index= it-vec.begin();//0 based index as vec.begin() = 0 always;
    if(it!=vec.end()) cout<<*it<<" is found at index:"<<index<<endl;
    else cout<<"item not found"<<endl;

    vec.insert(it,7);
    display1(vec);

    auto it1 = find(vec.begin(),vec.end(),40);
    vec.insert(it1,vec1.begin(),vec1.end());
    display1(vec);

    sort(vec.begin(),vec.end());//ascending
    display(vec);//9
    sort(vec.rbegin(),vec.rend());//descending
    display1(vec);
    sort(vec.begin(),vec.end(),[](int x,int y) {return x>y;});//descending
    display1(vec);
    sort(vec.begin(),vec.end(),sort_);//descending
    display1(vec);
    sort(vec.begin(),vec.end(),greater<int>());//descending
    display1(vec);

    auto it2 = find(vec.begin(),vec.end(),40);
    vec.erase(it2);
    display(vec);//10
    vec.erase(vec.begin(),vec.begin()+4);
    display1(vec);
    auto it3=vec.begin();
    while(it3!=vec.end())
    {
        if(*it3%2==0) vec.erase(it3);
        else it3++;
    }
    display1(vec);

    copy(vec1.begin(),vec1.end(),back_inserter(vec));//copy vec1 from last index of vec
    display(vec);//11

    display(vec1);//12
    vec1.clear();
    bool is_emptpy = vec1.empty();
    if(is_emptpy) cout<<"empty"<<endl;
    else cout<<"not empty"<<endl;

}
