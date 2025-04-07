//https://school.programmers.co.kr/learn/courses/30/lessons/12949
#include<iostream>
#include<vector>
#include<string>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2)
{
    vector<vector<int>> answer;
    int n = arr1.size();
    int m = arr1[0].size();
    int l = arr2[0].size();

    answer.resize(n, vector<int>(l, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < l; j++)
        {
            for (int k = 0; k < m; k++)
            {
                answer[i][j]+= arr1[i][k]*arr2[k][j]; 
            }
            
        }
        
    }
    return answer;
}

int main()
{
    int n{},m{},l{},o{};
    cin>>n>>m;
    cin>>l>>o;
    vector<vector<int>> arr1(n,vector<int>(m,0));
    vector<vector<int>> arr2(l,vector<int>(o,0));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin>>arr1[i][j];
    for (int i = 0; i < l; i++)
        for (int j = 0; j < o; j++)
            cin>>arr2[i][j];
    vector<vector<int>> ret = solution(arr1,arr2);

    for(vector<int> i : ret)
    { 
        for (int j : i)
        {
            cout<<j<<" ";
        }
        cout<<endl;
    }
}