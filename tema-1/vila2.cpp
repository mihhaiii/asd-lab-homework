/*
  http://www.infoarena.ro/problema/vila2
*/
#include<fstream>
#include<deque>
 
using namespace std;
 
ifstream cin("vila2.in");
ofstream cout("vila2.out");
 
int n,k,i,Max,a[100010];
deque<int> q,p;
 
int main()
{
    cin>>n>>k;
    for (i=1;i<=n;i++)
    {
        cin>>a[i];
        while (!q.empty() && a[i]<a[q.back()]) q.pop_back();
        q.push_back(i);
        while (!p.empty() && a[i]>a[p.back()]) p.pop_back();
        p.push_back(i);
 
        if (q.front()==i-k-1) q.pop_front();
        if (p.front()==i-k-1) p.pop_front();
 
        Max = max (Max, a[p.front()]-a[q.front()]);
    }
    cout<<Max;
    return 0;
}
