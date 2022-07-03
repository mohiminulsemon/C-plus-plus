#include<iostream>
#include<vector>
#include<algorithm>

///see dfs algorithm for a different type of 2d vector

using namespace std;

int test=0;

///type-1 display
template <typename T>
void display(vector< vector <T> > &v)
{
    cout<<"test = "<<test++<<endl;
    for(auto i: v)
    {
        for(auto j: i) cout<<j<<"\t";
        cout<<endl;
    }
    cout<<endl<<endl;
}

///type-2 display
template <typename T>
void display1(vector< vector <T> > &v)
{
    cout<<"test = "<<test++<<endl;
    for(auto i=0;i<v.size();i++)
    {
        for(auto j=0;j<v[i].size();j++) cout<<v[i][j]<<" ";
        cout<<endl;
    }
    cout<<endl<<endl;
}

///type-3 display
template <typename T>
void display2(vector< vector <T> > &v)
{
    cout<<"test = "<<test++<<endl;
    for(auto i=0;i<v.size();i++)
    {
        for(auto it = v[i].begin();
            it != v[i].end(); it++) cout<<*it<<" ";//iterator used when we use begin/end
        cout<<endl;
    }
    cout<<endl<<endl;
}

int main()
{
    vector<vector<int> >v{{1,3,4},{4,5,7}};
    display(v);

    vector<vector<int> >v1;//vctor of vector//vector<vector<int> >v1(100) means there are 100 vectors in v1
    vector<int>v2{1,2,3},v3{4,5,6};
    v1.push_back(v3);
    v1.push_back(v2);
    display(v1);
    vector<vector<int> >vec;//">>" cause compile error,for that we use space
    int row=5,column=5,element=10;
    for(int i=0;i<row;i++)
    {
        vector<int>v4;
        for(int j=0;j<column;j++)
        {
            v4.push_back(element);
            element+=5;
        }
        vec.push_back(v4);
    }

    display(vec);

    vec[4].pop_back();
    display(vec);
    vec.pop_back();
    display(vec);

    vector<vector<int> > vec1;
    vec1.resize(row,vector<int>(column));//resizing according to row and column ,it saves memory,and initialize all by 0
    display(vec1);

    vec1.assign(row,vector<int>(column,5));
    display(vec1);

}
