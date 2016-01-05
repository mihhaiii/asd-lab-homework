/*
https://open.kattis.com/problems/goblingardenguards
*/
# include <bits/stdc++.h>
using namespace std;

# define forn(i,n) for(int i=0;i<(n);++i)
# define endl '\n'
# define FOR(i,a,b) for(int i=(a);i<=(b);++i)
# define FORD(i,a,b) for(int i=(a);i>=(b);--i)
# define debug(x) cerr << (#x) << " = " << (x) << endl

int n, m;
int viz[100055];
vector < int > P[20005];
vector < int > id[20005];
vector < int > sp[20005];


int main()
{
    cin>>n;
    forn(i,n)
    {
        int x,y;
        cin>>x>>y;
        P[y].push_back(x);
        id[y].push_back(i);
    }
    forn(i,10001) {
        sp[i].resize(P[i].size()+4,0);
        if (P[i].size()) {
                sort(P[i].begin(),P[i].end());
        }
    }

    cin>>m;
    forn(i,m)
    {
        int xR, yR, R;
        cin>>xR>>yR>>R;

        FOR(y,yR-R,yR+R)
        {
            if (P[y].size()==0) continue;
            double x1 = xR - sqrt( R*R - (y-yR)*(y-yR) );
            double x2 = xR + sqrt( R*R - (y-yR)*(y-yR) );
            int posA = (lower_bound(P[y].begin(),P[y].end(),x1) - P[y].begin());
            int posB = upper_bound(P[y].begin(),P[y].end(),x2) - P[y].begin(); posB--;
            if (posA > posB) continue;
            sp[y][posA]++; sp[y][posB+1]--;
         //   debug(posA); debug(posB);
        }
    }

    forn(i,10001)
    {
        forn(j,P[i].size()) {
            if (j) sp[i][j] += sp[i][j-1];
            if (sp[i][j]>0) viz[id[i][j]] = 1;
        }
    }
    int ans=0;

    forn(i,n) if (viz[i]==0) ans++;
    cout<<ans;
    return 0;
}
