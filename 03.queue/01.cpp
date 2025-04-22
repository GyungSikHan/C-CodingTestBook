//요세푸스 문제
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int solution(int N, int K)
{
    queue<int> q;

    for(int i = 0; i < N; i++)
        q.push(i+1);
    
    while(q.empty() == false)
    {
        if(q.size() == 1)
            return q.front();

        for(int i = 0; i < K-1; i++)
        {
            q.push(q.front());
            q.pop();
        }

        q.pop();
    }

    return 0;
}

int main()
{
    int n{}, k{};
    cin >> n >> k;

    cout << solution(n, k)<<endl;
}