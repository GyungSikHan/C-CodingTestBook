//https://school.programmers.co.kr/learn/courses/30/lessons/42577
#include<iostream>
#include <string>
#include <vector>
#include<unordered_map>
#include<algorithm>

using namespace std;

// bool solution(vector<string> phone_book) {
//     bool answer = true;
    
//     sort(phone_book.begin(), phone_book.end());
    
//     for (int i = 0; i < phone_book.size()-1; i++)
//     {
//         if(phone_book[i] == phone_book[i+1].substr(0, phone_book[i].size()) )
//             return false;                
//     }

//     return answer;
// }

unordered_map<string, int> map;
bool isPrefix(string phone)
{
    string prefix{};

    for (const char c : phone)
    {   
        prefix+=c;

        if(map.find(prefix) != map.end() && prefix != phone)
            return true;
    }
    return false;
}

bool solution(vector<string> phone_book) 
{
    for (const string s : phone_book)
    {
        if(map.empty() == true)
            map.insert({s,1});
        else
            map[s]++;
    }

    for (const string s : phone_book)
    {
        if(isPrefix(s) == true)
            return false;
    }
    
    return true;
}

int main()
{
    //vector<string> phone_book{"119","987674223","1195524421"};
    //vector<string> phone_book{"123","456","789"};
    vector<string> phone_book{"12","123","1235","567","88"};

    cout<<solution(phone_book)<<endl;
}