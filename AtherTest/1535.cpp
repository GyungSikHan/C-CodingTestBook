// https://www.acmicpc.net/problem/1535
#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> L, J;
int hp = 100;
int happy;

void DFS(int index, int HP, int Happy)
{
    if (HP <= 0)
    {
        happy = max(happy, Happy - J[index-1]);
        return;
    }
    if (index == n)
    {
        happy = max(Happy, happy);
    }

    for (int i = index; i < n; i++)
    {
        DFS(i + 1, HP - L[i], Happy + J[i]);
    }
}

int main()
{
    cin >> n;
    L.resize(n, 0);
    J.resize(n, 0);

    for (int i = 0; i < n; i++)
        cin >> L[i];
    for (int i = 0; i < n; i++)
        cin >> J[i];

    for (int i = 0; i < n; i++)
    {
        DFS(i, 100, 0);
    }

    cout<<happy<<endl;

}