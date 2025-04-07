#include<iostream>
#include<vector>
#include<stack>
#include <string>

using namespace std;

bool solution(string s)
{
    stack<char> st;
    for (int i = 0; i < s.size(); i++)
    {
        if(s.at(i) == '(')
            st.push(s.at(i));
        else
            st.pop();
    }

    if(st.empty() == true)
        return true;
    return false;
}

int main()
{
    string s{};
    cin>>s;
    cout<<solution(s)<<endl;
}