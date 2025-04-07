//https://school.programmers.co.kr/learn/courses/30/lessons/76502
#include<iostream>
#include <string>
#include <vector>
#include<stack>
using namespace std;

int solution(string s) 
{
    int answer = -1;
    string temp = s;
    int count{};
    do
    {
        stack<char> st;
        for (int i = 0; i < temp.size(); i++)
        {
            if(st.empty() == true)
                st.push(temp.at(i));
            else
            {
                if(st.top() == '(' && temp.at(i) == ')')
                    st.pop();             
                else if(st.top() == '{' && temp.at(i) == '}')
                    st.pop();
                else if(st.top() == '[' && temp.at(i) == ']')
                    st.pop();
                else
                    st.push(temp.at(i));
            }
        }
        if(st.empty() == true)
            count++;
        char c{};
        for (int i = 0; i < temp.size(); i++)
        {
            if(i == 0)
                c = temp.at(i);
            else
                temp[i-1] = temp[i];
        }
        temp[temp.size()-1] = c;
        
    }while(temp != s);
    
    answer = count;
    return answer;
}

int main()
{
    string s{};
    cin>>s;
    cout<<solution(s);
}