/*
    http://www.infoarena.ro/problema/deque
*/

#include<fstream>
#include<deque>

using namespace std;

ifstream cin("deque.in");
ofstream cout("deque.out");

const int nmax = 5000010;

int a[nmax],n,k,i;
long long sum=0;
deque<int> q;

int main()
{
    cin>>n>>k;
    for (i=1;i<=n;i++) cin>>a[i];

    for (i=1;i<=n;i++)
    {
        while ( !q.empty() && a[i]<a[q.back()] ) q.pop_back();
        q.push_back(i);

        if (q.front()==i-k) q.pop_front();

        if (i>=k) sum+=a[q.front()];
    }
    cout<<sum;
    return 0;
}
