/*
  http://main.edu.pl/en/archive/oi/20/usu
*/
# include <bits/stdc++.h>
using namespace std;

int n,k;
string s;
vector<int> sum;
stack<int> st;
vector<int>  sol;
int main()
{
    cin>>n>>k>>s;

    sum.resize(n+1);

    for (int i=0;i<n;i++) {
        st.push(i);
        int x=st.size();
        sum[x] = sum[x-1] + (s[i] == 'c' ? 1 : 0);
        if (x >= k+1) {
            if (sum[x] - sum[x-k-1] == 1)
              for(int l=0;l<k+1;l++) sol.push_back(st.top()+1), st.pop();
        }
    }

    int lim=n/(k+1);
     for (int i=n-1,l=0;i>=0;i--) {
        l++;
        cout<<sol[i]<<" ";
        if (l==k+1) {
            cout<<endl;
            l=0;
        }
     }
    return 0;

}
