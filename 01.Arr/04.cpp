//https://school.programmers.co.kr/learn/courses/30/lessons/42840
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> n{1,2,3,4,5};
vector<int> n2{2,1,2,3,2,4,2,5};
vector<int> n3{3,3,1,1,2,2,4,4,5,5};

vector<int> solution(vector<int> answers)
{
    vector<int> answer;
    vector<int> score(3, 0);
    for (int i = 0; i < answers.size(); i++)
    {
        if(n[i%n.size()] == answers[i])
            score[0]++;
        if(n2[i%n2.size()] == answers[i])
            score[1]++;
        if(n3[i%n3.size()] == answers[i])
            score[2]++;
    }
    
    int m = *max_element(score.begin(),score.end());

    for (int i = 0; i<3; i++)
    {
        if(score[i] == m)
            answer.push_back(i+1);
    }
    
    return answer;
}

int main()
{
    int n{};
    cin>>n;
    vector<int> answers(n,0);
    for (int i = 0; i < n; i++)
    {
        cin>>answers[i];
    }
    vector<int>ret = solution(answers);
    for (int i : ret)
    {
        cout<<i<<" ";
    }
    
}