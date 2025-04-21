// https://www.acmicpc.net/problem/6064
#include <iostream>
#include <vector>

using namespace std;

int t, m, n, x, y;

int gcd(int a, int b)
{
    if(b != 0)
        return gcd(b,a%b);
    
    return a;
}
int lcm(int a, int b)
{
    return a / gcd(a,b)*b;
}

int solution(int cx,int cy, int count)
{
    if (cx == x && cy == y)
        return count;
    if (cx >= m)
        cx = 1;
    else
        cx++;
    if (cy >= n)
        cy = 1;
    else
        cy++;
    int ret = solution(cx,cy, count + 1);

    return ret;
}

int main()
{
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> m >> n >> x >> y;
        
        cout << solution(1,1, 1) << endl;
    }
}