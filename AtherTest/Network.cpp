//https://school.programmers.co.kr/learn/courses/30/lessons/43162
#include<iostream>
#include <string>
#include <vector>

using namespace std;

bool DFS(int n, int i, vector<vector<int>> computers, vector<vector<bool>>& visited)
{
    bool b{};
    int temp{};
    for (int j = 0; j < n; j++)
    {
        if(computers[i][j] != 0 && visited[i][j] == false) 
        {
            b = true;
            visited[i][j] = true;
            visited[j][i] = true;
            DFS(n,j,computers,visited);
            temp = 0;
        }
        else
        {
            temp++;
        }
    }
    if(b == false && temp >= n)
        b = true;
    return b;
}

int solution(int n, vector<vector<int>> computers) 
{
    int answer = 0;
    vector<vector<bool>> visited(n,vector<bool>(n,0));
    for (int i = 0; i < n; i++)
    {
        visited[i][i] = true;
        if(DFS(n,i,computers,visited))
        {
            answer++;
        }
    }
        
    return answer;
}

int main()
{
    int n{};
    cin>>n;
    vector<vector<int>> v(n,vector<int>(n,0));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin>>v[i][j];

    solution(n, v);
}