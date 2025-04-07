#include<iostream>
#include<stack>
#include<string>

using namespace std;

string solution(int declmal)
{
    stack<int> st;
    while (declmal != 0)
    {
        st.push(declmal%2);
        declmal /= 2;
    }

    string answer{};
    while (st.empty() == false)
    {
        answer += to_string(st.top());
        st.pop();
    }
    
    return answer;
}

int main()
{
    int n{};
    cin>>n;
    string s = solution(n);
    cout<<s<<endl;
}