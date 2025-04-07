//https://school.programmers.co.kr/learn/courses/30/lessons/68644?language=cpp
#include<iostream>
#include<vector>
#include<set>
#include<algorithm>

using namespace std;

// vector<int> solution(vector<int> numbers)
// {
//     vector<int> answer;
//     sort(numbers.begin(), numbers.end());

//     for (int i = 0; i < numbers.size(); i++)
//     {
//         for (int j = i+1; j < numbers.size(); j++)
//         {
//             answer.push_back(numbers[i]+numbers[j]);
//         }
        
//     }
//     sort(answer.begin(), answer.end());
//     answer.erase(unique(answer.begin(), answer.end()),answer.end());

//     return answer;
// }
vector<int> solution(vector<int> numbers)
{
    set<int> temp;
    for (int i = 0; i < numbers.size(); i++)
    {
        for (int j = i+1; j < numbers.size(); j++)
        {
            temp.insert(numbers[i]+numbers[j]);
        }
        
    }
    vector<int> answer(temp.begin(), temp.end());
   
    return answer;
}

int main()
{
    int n{};
    cin>>n;
    vector<int> numbers(n,0);
    for (int i = 0; i < n; i++)
    {
        cin>>numbers[i];
    }

    vector<int>ret = solution(numbers);
    for(int i: ret)
        cout<<i<<" ";
    
}