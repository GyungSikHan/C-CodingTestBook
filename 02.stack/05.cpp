//https://school.programmers.co.kr/learn/courses/30/lessons/42584 v
#include <string>
#include <vector>
#include<iostream>
#include<stack>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size(), 0);
    int num = prices.size();
    stack<int> st;

    for (int i = 0; i < num; i++)
    {
        //st.empty() == false면 현재 prices[i]와 과거 prices[st.top()]를 비교해 가격이 떨어졌는지 비교
        while (st.empty() == false && prices[st.top()] > prices[i])
        {
            //가격이 떨어졌으면 answer의 과거 index에 과거부터 현재까지 얼마나 지나 떨어졌는지 계산
            answer[st.top()] = i - st.top();
            st.pop(); 
        }

        st.push(i);
    }

    //st.empty() == false면 가격이 떨어지지 않은 애들 남아있으므로 총 흐른 시간에 st.top()-1을 빼주어 st.top()이 될동안 가격이 떨어지지 않은 시간 연산
    while (st.empty() == false)
    {
        answer[st.top()] = num - st.top()-1;
        st.pop();
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