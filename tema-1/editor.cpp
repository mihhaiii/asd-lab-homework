/*
  http://www.infoarena.ro/problema/editor
*/
#include<fstream>
#include<stack>
#include<string>
 
using namespace std;
 
string s;
int p[60003];
 
int t,i;
 
int main()
{
    ifstream cin("editor.in");
    ofstream cout("editor.out");
 
    cin>>t;
    while (t--)
    {
        cin>>s;
        p[0]=0;
        for (i=0;i<s.size()-1;i++)
            if (s[i]=='*') { if (p[0]) p[0]--; }
             else {
                ++p[0];
                if (s[i]=='(')p[p[0]]=1;
                if (s[i]==')')p[p[0]]=2;
                if (s[i]=='[')p[p[0]]=3;
                if (s[i]==']')p[p[0]]=4;
             }
        stack<int> st;
        for (i=1;i<=p[0];i++) if (st.size()==0) st.push(p[i]);
         else {
            if ((st.top()==1 && p[i]==2) || (st.top()==3 && p[i]==4))
                st.pop(); else st.push(p[i]);
         }
         if (st.size()) cout<<":(";else cout<<":)"; cout<<'\n';
    }
    return 0;
}
