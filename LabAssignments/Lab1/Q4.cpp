#include <bits/stdc++.h>
#define ll long long
using namespace std;

void breakAndSum(vector<ll> &arr, set<ll> &result)
{

    if (arr.size() <= 1)
    {
        // cout << "only element " << arr[0] << endl;
        result.insert(arr[0]);
        return;
    }

    double avg = (arr.front() + arr.back()) / 2.0;
    // cout<<avg<<endl;

    auto it = upper_bound(arr.begin(), arr.end(), avg);

    ll splitIndex = it - arr.begin();
    // cout << "splitindex " << splitIndex - 1 << endl;

    // Split the array into left and right subarrays
    vector<ll> leftArray(arr.begin(), it);
    // cout << "size " << leftArray.size() << endl;
    vector<ll> rightArray(it, arr.end());

    // Calculate the sum of the current subarray
    ll leftSum = accumulate(leftArray.begin(), leftArray.end(), 0);
    ll rightsum = accumulate(rightArray.begin(), rightArray.end(), 0);
    // cout << "leftsum " << leftSum << endl;
    // cout << "rightsum " << rightsum << endl;
    // cout<<"----result value---"<<endl;
    result.insert(leftSum);
    result.insert(rightsum);
    // for(auto val:result){
    //     cout<<val<<" ";
    // }
    // cout<<endl;
    if (rightsum == 0 || leftSum == 0)
    {
        return;
    }
    breakAndSum(leftArray, result);
    // cout << "starting right " << endl;
    breakAndSum(rightArray, result);
}

int main()
{
    ll NoOfTestcases, N, total_list, a, b_ele;
    vector<ll> elements;
    cin >> NoOfTestcases;

    for (ll i = 0; i < NoOfTestcases; i++)
    {
        cin >> N >> total_list;

        elements.clear();
        for (ll j = 0; j < N; j++)
        {
            cin >> a;
            elements.push_back(a);
        }

        sort(elements.begin(), elements.end());
        set<ll> answer;
        answer.insert(accumulate(elements.begin(),elements.end(),0));
        breakAndSum(elements, answer);
        for (ll j = 0; j < total_list; j++)
        {
            cin >> b_ele;
            auto pos = answer.find(b_ele);
            if (pos == answer.end())
            {
                cout << "No" << endl;
            }
            else{
                cout<<"Yes"<<endl;
            }
        }
    }

    return 0;
}
