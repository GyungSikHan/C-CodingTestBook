//https://www.acmicpc.net/problem/10808
#include<iostream>
#include<vector>

using namespace std;

void solution(string s, vector<int>& arr)
{
    for (int i = 0; i < s.size(); i++)
    {
        arr[s.at(i) - 'a'] += 1;
    }
    
}

int main()
{
    string s{};
    cin>>s;
    vector<int> arr(26, 0);
    solution(s, arr);
    for (int iter : arr)
    {
        cout<<iter<<" ";
    }
    
}