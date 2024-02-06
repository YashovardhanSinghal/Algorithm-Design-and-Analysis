#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll countCharacterInSubstring(const string& s, char character, ll start, ll end) {
    ll count = 0;
    for (ll i = start; i <end; i++) {
        if (s[i] == character) {
            count++;
        }
    }
    return count;
}

ll checkperfectstring(string s, char character)
{
    // cout << "Checking string: " << s << " with character: " << character << endl;

    if (s.size() == 1)
    {
        return (s == string(1, character)) ? 0 : 1;
    }
    // cout<<s.size()/2<<endl;
    ll leftchanges = s.size()/2-countCharacterInSubstring(s, character, 0, s.size() / 2);
    // cout << "Left changes: " << leftchanges << endl;

    ll rightchanges = s.size()/2-countCharacterInSubstring(s, character, (s.size()) / 2, s.size());
// cout << "Right changes: " << rightchanges << endl;
    ll min1 = checkperfectstring(s.substr(0, s.size() / 2), character + 1);
    ll min2 = checkperfectstring(s.substr((s.size()) / 2), character + 1);

    

    return min(min1 + rightchanges, min2 + leftchanges);
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        string s;
        cin >> s;
        ll res = checkperfectstring(s, 'a');
        cout << res << endl;
    }
}
