//https://school.programmers.co.kr/learn/courses/30/lessons/42586
#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds)
{
    vector<int> answer;
    queue<pair<int, int>> q;
    int count{};
    for(int i = 0; i < progresses.size(); i++)
    {
        q.push({progresses[i], speeds[i]});
    }
    while(q.empty() == false)
    {
        for(int i = 0; i < q.size(); i++)
        {
            q.push({q.front().first + q.front().second, q.front().second});
            q.pop();
        }

        if(q.front().first >= 100)
        {
            int size = q.size();
            for(int i = 0; i < size; i++)
            {
                if(q.front().first >= 100)
                {
                    count++;
                    q.pop();
                }
                else
                    break;
            }
            answer.push_back(count);
            count = 0;
        }
    }

    return answer;
}

int main()
{
    //vector<int> progresses = {93, 30, 55};
    //vector<int> speeds = {1, 30, 5};
    // vector<int> progresses = {95, 90, 99, 99, 80, 99};
    // vector<int> speeds = {1, 1, 1, 1, 1, 1};
    vector<int> progresses = {95, 95, 95,95};
    vector<int> speeds = {4, 3,2,1};

    vector<int> answer = solution(progresses, speeds);

    for(int i = 0; i < answer.size(); i++)
        cout << answer[i] << " ";
    cout<<endl;
}