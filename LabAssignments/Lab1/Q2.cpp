#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    ll n, b;
    cin >> n >> b;
    vector<ll> attack(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> attack[i];
    }
    // sort(attack.begin(), attack.end());
    vector<pair<ll, ll>> bases;

    for (ll i = 0; i < b; i++)
    {
        ll x, y;
        cin >> x >> y;
        bases.push_back(make_pair(x, y));
    }
    sort(bases.begin(), bases.end());
    vector<ll> prefixsum(b);
    prefixsum[0] = (bases[0].second);
    for (ll i = 1; i < b; i++)
    {
        prefixsum[i] = prefixsum[i - 1] + bases[i].second;
    }

    // for (auto it : attack)
    // {
    //     cout << it.first << " "<<it.second<<endl;
    // }
    // cout << endl;
    // for (auto b : bases)
    // {
    //     cout << b.first << " " << b.second << endl;
    // }
    ll i = 0;
    ll j = 0;
    ll index = 0;

    vector<ll> ans;

    while (i < n)
    {
        ll sum = 0;
        ll start = 0;
        ll end = b-1;
        ll index = -1;

        while (start <= end)
        {
            ll mid = start + (end - start) / 2;

            if (attack[i] >= bases[mid].first)
            {
                index = mid;
                start = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }
        if (index != -1)
        {
            sum = prefixsum[index];
        }
        else{
            sum=0;
        }
        ans.push_back(sum);
        i++;
    }

    for (auto its : ans)
    {
        cout << its << " ";
    }
}
