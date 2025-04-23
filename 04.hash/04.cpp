//https://school.programmers.co.kr/learn/courses/30/lessons/12981
#include<iostream>
#include <string>
#include <vector>
#include<unordered_map>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;

    unordered_map<string, int> m;
    int temp = 1;
    string stemp{};
    vector<int> count(n+1,0);
    for(string s : words)
    {
        cout << s << " "<< temp << endl;
        if(m.empty() == true)
            m.insert({s,temp});
        else
        {
            if(stemp[stemp.size()-1] != s[0])
            {
                answer.push_back(temp);
                answer.push_back(count[temp]+1);
                return answer;
            }
                        
            if(m.find(s) != m.end())
            {
                answer.push_back(temp);
                answer.push_back(count[temp]+1);
                break;
            }
            else
                m.insert({s,temp});
        }
        count[temp]++;
        temp++;
        if(temp > n)
            temp = 1;
        stemp = s;
    }
    if(answer.empty() == true)
    {
        answer.push_back(0);
        answer.push_back(0);
    }

    return answer;
}

int main()
{
    int n{};
    cin>>n;
    vector<string> words{"tank","kick","know","wheel","land","dream","mother","robot", "tank"};
    //vector<string> words{"hello", "observe", "effect", "take", "either", "recognize", "encourage", "ensure", "establish", "hang", "gather", "refer", "reference", "estimate", "executive"};
    //vector<string> words{"hello", "one", "even", "never", "now", "world", "draw"};

    vector<int> ret = solution(n, words);

    for (int i : ret)
        cout<<i<<" ";
    cout<<endl;
    
}