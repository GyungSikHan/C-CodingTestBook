#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

long long polynomial_hasy(const string& str)
{
    const int p = 31;
    const long long m = 1000000007;
    long long hasy{};

    for(char c : str)
        hasy = (hasy*p+c)%m;
    
    return hasy;
}

vector<bool> solution(vector<string> string_list, vector<string> query_list)
{
    vector<bool> answer{};
    unordered_set<long long> set;

    for(const string& s : string_list)
    {
        long long hasy = polynomial_hasy(s);
        set.insert(hasy);
    }

    for(const string& query : query_list)
    {
        long long hasy = polynomial_hasy(query);
        bool found = set.find(hasy) != set.end();
        answer.push_back(found);
    }

    return answer;
}

int main()
{
    vector<string> string_list{"apple", "banana", "cherry"};
    vector<string> query_list{"banana", "kiwi", "melon", "apple"};
    vector<bool> result = solution(string_list, query_list);

    for(bool iter : result)
        cout<<iter<<" ";
    cout<<endl;
}