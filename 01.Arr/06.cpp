#include <iostream>
#include <vector>

#include<algorithm>

using namespace std;
bool compare(pair<float,int> a, pair<float, int> b)
{
    if (a.first == b.first) 
        return a.second < b.second; 
    return a.first>b.first;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<int> temp(N+2,0);
    for(int i : stages)
    {
        if(i < N+1)
        temp[i]++;
    }
    
    int faile = stages.size();
    vector<pair<float, int>> temp2;
    for (int i = 1; i <= N; i++)
    {
        if(faile != 0)
            temp2.push_back({(float)temp[i]/faile, i});
        else
            temp2.push_back({0.0f, i});
        faile-=temp[i];
    }
    
    sort(temp2.begin(), temp2.end(),compare);

    for(pair<float,int> i : temp2)
    {
        answer.push_back(i.second);
    }

    return answer;
}

int main()
{
    int n{};
    cin>>n;

    vector<int> stage{2,1,2,6,2,4,3,3};
    //vector<int> stage{4,4,4,4,4};

    vector<int> ret = solution(n, stage);
    for(int i : ret)
        cout<<i<<" ";
}