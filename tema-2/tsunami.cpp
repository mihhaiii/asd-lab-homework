/*
  http://www.infoarena.ro/problema/tsunami
*/
#include<fstream>
using namespace std;
 
const int nmax=1004;
const int dx[]={0,0,1,-1};
const int dy[]={1,-1,0,0};
 
 
int n,m, i,j, a[nmax][nmax], h, X[nmax*nmax], Y[nmax*nmax], p, u;
 
 
int main()
{
    ifstream cin("tsunami.in");
    ofstream cout("tsunami.out");
 
    cin >> n >> m >> h;
    for (i=1;i<=n;i++)
        for (j=1;j<=m;j++)
        cin >> a[i][j];
 
    for (i=1;i<=n;i++)
        for (j=1;j<=m;j++)
            if (a[i][j] && a[i][j]<h)
    {
        int ok = 0;
        for (int k=0;k<4 && !ok;k++)
        {
            int x = i+dx[k];
            int y = j+dy[k];
            if (x>0 && x<=n && y>0 && y<=m && a[x][y]==0)
                ok=1;
        }
        if (ok) X[++u] = i, Y[u] = j, a[i][j]=-1;
    }
 
    p=1;
    while (p<=u) {
        int x=X[p], y=Y[p];p++;
        for (int k=0;k<4;k++)
        {
            int nx=x+dx[k],ny=y+dy[k];
            if (x>0 && x<=n && y>0 && y<=m)
                if (a[nx][ny]<h && a[nx][ny]>0)
                X[++u]=nx,Y[u]=ny, a[nx][ny]=-1;
        }
    }
    int nr = 0;
    for (i=1;i<=n;i++) {
        for (j=1;j<=m;j++)
              {
                //cout << a[i][j]<< " ";
                if (a[i][j]==-1)nr++;
              }
           // cout << "\n";
    }
    cout << nr;
    return 0;
}
