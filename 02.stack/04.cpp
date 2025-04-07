//https://school.programmers.co.kr/learn/courses/30/lessons/12973
#include <iostream>
#include<string>
#include<stack>
using namespace std;

int solution(string s)
{
    int answer = 0;
    stack<char>st;

    for (int i = 0; i < s.size(); i++)
    {
        if(st.empty() == true)
            st.push(s.at(i));
        else if(st.top() == s.at(i))
            st.pop();
        else
            st.push(s.at(i));
    }

    if(st.empty() == true)
        answer=1;
    
    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    cout << "Hello Cpp" << endl;

    return answer;
}

int main()
{
    string s{};
    cin>>s;
    cout<<solution(s)<<endl;
}