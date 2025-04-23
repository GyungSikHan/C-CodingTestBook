#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

bool solution(vector<int> arr, int target)
{
    vector<int> hash(target+1,0);

    for(int i = 0; i < arr.size(); i++)
    {
        if(arr[i] > target)
            continue;
        hash[arr[i]] = 1;
    }

    for(int i = 0; i < arr.size(); i++)
    {
        int temp = target - arr[i];
        if(temp == arr[i])
            continue;
        if(temp < 0)
            continue;
        if(hash[temp] == 1)
            return true;
    }
    return false;
}

int main()
{
    int n{}, target{};
    cin>>n;
    vector<int> arr(n,0);

    for(int i = 0; i < n; i++)
        cin>>arr[i];
    
    cin>>target;

    cout<<solution(arr, target)<<endl;
}