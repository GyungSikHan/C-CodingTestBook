//https://school.programmers.co.kr/learn/courses/30/lessons/131127
#include<iostream>
#include <string>
#include <vector>
#include<unordered_map>

using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount)
{
    int answer = 0;
    unordered_map<string, int> map;

    for (int i = 0; i < want.size(); i++)
        map.insert({want[i], number[i]});
    
    // for (int i = 0; i < discount.size(); i++)
    // {
    //     unordered_map<string, int> temp = map;
    //     if(i+10 > discount.size())
    //         break;
    //     for (int j = i; j < i+10; j++)
    //     {
    //         if(temp.find(discount[j]) != temp.end())
    //             temp[discount[j]]--;
    //     }
    //     int count{};
    //     for(pair<string, int> iter : temp)
    //     {
    //         if(iter.second == 0)
    //             count++;
    //     }
    //     if(count == want.size())
    //         answer++;
    // }
    
    //2
    // for (int i = 0; i < discount.size()-9; i++)
    // {
    //     unordered_map<string,int> temp{};
    //     for (int j = i; j < i+10; j++)
    //         temp[discount[j]]++;

    //     if(map == temp)
    //         answer++;
    // }

    unordered_map<string, int> set;
    for (int i = 0; i < 9; i++)
        set[discount[i]]++;
    for (int i = 9; i < discount.size(); i++)
    {
        set[discount[i]]++;
        if(map == set)
            answer++;
        if(--set[discount[i-9]] == 0)
            set.erase(discount[i-9]);
    }
    

    return answer;
}

int main()
{
    vector<string> want{"banana", "apple", "rice", "pork", "pot"};
    vector<int> number{3, 2, 2, 2, 1};
    vector<string> discount{"chicken", "apple", "apple", "banana", "rice", "apple", "pork", "banana", "pork", "rice", "pot", "banana", "apple", "banana"};
    // vector<string> want{"apple"};
    // vector<int> number{10};
    // vector<string> discount{"banana", "banana", "banana", "banana", "banana", "banana", "banana", "banana", "banana", "banana"};
    cout<<solution(want,number,discount)<<endl;
}