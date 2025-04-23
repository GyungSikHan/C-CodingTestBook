//https://school.programmers.co.kr/learn/courses/30/lessons/42576
#include<iostream>
#include <string>
#include <vector>
#include<unordered_map>
using namespace std;

string solution(vector<string> participant, vector<string> completion) 
{
    string answer = "";
    unordered_map<string, int> map;
    for(string s : participant)
    {
        if(map.empty() == false && map.find(s) != map.end())
            map[s]++;
        else
            map.insert({s,1});
    }

    for (string s : completion)
    {
        if(map.find(s) != map.end())
            map[s]--;
    }
    
    for(pair<string, int> i : map)
    {
        if(i.second != 0)
        {
            answer = i.first;
            break;
        }
    }
    return answer;
}

int main()
{
    //vector<string> participant{"leo", "kiki", "eden"};
    //vector<string> participant{"marina", "josipa", "nikola","vinko","filia"};
    vector<string> participant{"mislav", "stanko", "mislav","ana"};
    //vector<string> completion{"eden","kiki"};
    //vector<string> completion{"josipa","filia","marina","nikola"};
    vector<string> completion{"stanko","ana", "mislav"};

    cout<<solution(participant, completion)<<endl;
}