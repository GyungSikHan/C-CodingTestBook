//https://school.programmers.co.kr/learn/courses/30/lessons/42579
#include<iostream>
#include <string>
#include <vector>
#include<unordered_map>
#include<algorithm>

using namespace std;

bool compare(pair<string, int> a, pair<string,int> b)
{
    return a.second > b.second;
}
bool compare2(pair<int, int> a, pair<int, int> b)
{
    if(a.second == b.second)
        return a.first < b.first;
    return a.second > b.second;
}

vector<int> solution(vector<string> genres, vector<int> plays) 
{
    vector<int> answer;
    vector<int> number = plays; 
    unordered_map<string, int> map{};
    unordered_map<int, pair<string, int>> map2{};//todo string int 묶어서 음악 종유와 고유번호 묶어서 해보기
    //unordered_map<int, pair<string, int>> map3{};
    for (int i = 0; i < genres.size(); i++)
    {
        map[genres[i]]+= plays[i];
        map2[i] = make_pair(genres[i], plays[i]);
        //map3[plays[i]] = genres[i];
    }

    vector<pair<string, int>> v{};
    for(auto iter : map)
        v.push_back(iter); 
    sort(v.begin(), v.end(), compare);
    int size = v.size();
    vector<pair<int, int>> temp{};
    for (int i = 0; i < v.size(); i++)
    {
        vector<pair<int, int>> v2{};
        for (auto iter : map2)
        {
            if(iter.second.first == v[i].first)
            {
                v2.push_back({iter.first, iter.second.second});
            }
        }
        sort(v2.begin(), v2.end(), compare2);
        for(int i = 0; i < 2; i++)
        {
            if(v2.size() > i)
                temp.push_back(v2[i]);
        }

    }

    for(pair<int, int> iter : temp) 
        answer.push_back(iter.first);

    return answer;
}

int main()
{
    // vector<string> genres{"classic", "pop", "classic", "classic", "pop"};
    // vector<int>players{500, 600, 150, 800, 2500};
    vector<string> genres{"classic", "pop", "classic", "classic"};
    vector<int>players{800,600,150,800};
    vector<int> ret = solution(genres, players);

    for(int i : ret)
        cout<<i<<" ";
    cout<<endl;
}