#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool checksubsequence(vector<ll> v, ll sum, ll n, ll index , ll size)
{
    if (sum % n == 0 && size>=1)
    {
        return true;
    }

    if (index >= v.size())
    {
        return false;
    }

    ll checkleft = checksubsequence(v, sum + v[index], n, index + 1,size+1);
    ll checkright = checksubsequence(v, sum, n, index + 1,size);

    return checkleft || checkright;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    ll t;
    cin >> t;
    while (t--)
    {
        ll m, n;
        cin >> m >> n;
        vector<ll> v(m);
        bool flag = true;
        for (ll i = 0; i < m; i++)
        {
            cin >> v[i];
        }
        if (m == 1)
        {
            flag = false;
        }
        else
        {
            for (ll i = 0; i < m; i++)
            {
                vector<ll> copy;
                copy = v;
                copy.erase(copy.begin() + i);

                flag = checksubsequence(copy, 0, n, 0,0);
                if (flag == false)
                {
                    break;
                }
            }
        }

        if (flag)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}
