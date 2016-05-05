/*
  https://open.kattis.com/problems/conundrum
*/
# include <bits/stdc++.h>
// modificat aici
using namespace std;

# define forn(i,n) for(int i=0;i<(n);i++)
# define debug(x) cerr << (#x) << " = " << (x) << endl

string s;
int ans = 0;

int main()
{
    cin>>s;
    forn(i,s.size())
     if ( (i%3==0 && s[i]!='P') || (i%3==1 && s[i]!='E') || (i%3==2 && s[i]!='R') ) ans++;
     cout<<ans;
    return 0;
}
