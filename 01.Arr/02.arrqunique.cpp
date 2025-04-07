#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool compare(int a, int b)
{
    return a > b;
}

vector<int> solution(vector<int> list)
{
    sort(list.begin(),list.end(), compare);
    vector<int>::iterator iter = unique(list.begin(), list.end());

    list.erase(iter,list.end());

    return list;
}

int main()
{
    int n{};
    cin>>n;
    vector<int> list(n,0);
    for(int i = 0; i<n;i++)
        cin>>list[i];

    vector<int> ret = solution(list);

    for(int i : ret)
        cout<<i<<", ";
}