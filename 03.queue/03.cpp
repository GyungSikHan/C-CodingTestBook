//https://school.programmers.co.kr/learn/courses/30/lessons/159994?language=cpp
#include <string>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    string answer = "";
    queue<string> q, q2, g;
    for(string s : cards1)
        q.push(s);
    for(string s : cards2)
        q2.push(s);
    for(string s : goal)
        g.push(s);

    while(g.empty() == false)
    {
        if(q.front() == g.front())
        {
            q.pop();
            g.pop();
        }
        else if(q2.front() == g.front())
        {
            q2.pop();
            g.pop();
        }
        else
            break;
    }

    if(g.empty() == false)
        answer = "No";
    else
        answer = "Yes";
    return answer;
}

int main()
{
    //vector<string> cards1 = {"i", "drink", "water"};
    vector<string> cards1 = {"i", "water","drink"};
    vector<string> cards2 = {"want", "to"};
    vector<string> goal = {"i", "want", "to", "drink", "water"};

    string answer = solution(cards1, cards2, goal);
    cout<<answer<<endl;
}