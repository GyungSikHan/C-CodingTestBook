//https://school.programmers.co.kr/learn/courses/30/lessons/81303
#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

int CMD(char c)
{
    if(c == 'U')
        return 0;
    else if(c == 'D')
        return 1;
    else if(c == 'C')
        return 2;
    return 3;
}

string solution(int n, int k, vector<string> cmd) 
{
    string answer = "";
    int start = k;
    stack<int> deleted;
    vector<int> up;
    vector<int> down;

    for(int i = 0; i < n; i++)
    {
        up.push_back(i-1);
        down.push_back(i+1);
    }
    
    for(int i = 0; i < cmd.size(); i++)
    {
        int temp = CMD(cmd[i][0]);
        if(temp == 0)
        {
            start = up[start];
        }
        else if(temp == 1)
        {
            start = down[start];
        }
        else if(temp == 2)
        {
            deleted.push(start);
            if(start + 1 < n)
                up[down[start]] = up[start];
            if(start - 1 >= 0)
                down[up[start]] = down[start]; 
            
            if(down[start] < n)
                start = down[start];
            else
                start = up[start];
        }
        else
        {
            int temp2 = deleted.top();
            deleted.pop();
            up[down[temp2]] = temp2;
            down[up[temp2]] = temp2;
        }
    }

    for(int i = 0; i < n; i++)
        answer += 'O';
    while(!deleted.empty())
    {
        answer[deleted.top()] = 'X';
        deleted.pop();
    }
    return answer;
}

int main()
{
    int n{};
    int k{};
    cin >> n >> k;
    vector<string> cmd = {"D 2","C","U 3","C","D 4","C","U 2","Z","Z","U 1","C"};
    //vector<string> cmd = {"D 2","C","U 3","C","D 4","C","U 2","Z","Z"};
    //vector<string> cmd = {"D 1","C","U 2","C","Z","Z"};
    cout << solution(n,k,cmd) << endl;
}