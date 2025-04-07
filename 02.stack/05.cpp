#include <string>
#include <vector>
#include<iostream>
#include<stack>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    for (int i = 0; i < prices.size(); i++)
    {
        stack<int> st;
        for (int j = i+1; j < prices.size(); j++)
        {
            if(prices[i] <= prices[j])
                st.push(prices[i]);
        }
        answer.push_back(st.size());
    }
    
    return answer;
}

int main()
{
    int n{};
    cin>>n;
    vector<int> prices(n,0);
    for (int i = 0; i < n; i++)
    {
        cin>>prices[i];
    }
    
    vector<int> ret = solution(prices);
    for (int i : ret)
    {
        cout<<i<<endl;
    }
}