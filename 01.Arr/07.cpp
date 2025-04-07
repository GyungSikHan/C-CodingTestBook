#include <iostream>
#include <string>
using namespace std;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};
bool arr[11][11][4];

int dir(char c)
{
    if (c == 'U')
        return 0;
    else if (c == 'R')
        return 1;
    else if (c == 'D')
        return 2;
    else
        return 3;

    return 0;
}

bool IsNotValid(int x, int y)
{
    return x<0||y<0||x>10||y>10;
}
int ReverseDir(int dir)
{
    return (dir + 2) % 4;
}

int solution(string dirs)
{
    int answer = 0;
    int x = 5, y = 5;

    for (char c : dirs)
    {
        int temp = dir(c);
        int nx = x + dx[temp];
        int ny = y + dy[temp];
        if (IsNotValid(nx,ny) == true)
            continue;
        if (arr[x][y][temp] == false)
        {
            arr[x][y][temp] = true;
            arr[nx][ny][ReverseDir(temp)] = true;
            answer++;
        }

        x = nx;
        y = ny;
    }

    return answer;
}

int main()
{
    string s{};
    cin >> s;
    cout << solution(s);
}