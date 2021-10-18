#include<bits/stdc++.h>

#define ll long long 
#define blocksize 500 

using namespace std;

ll power=0;

class Query
{
    public:
    ll l;
    ll r;
    ll i;
    Query(){}
    Query(ll l, ll r, ll i)
    {
        this->l=l;
        this->r=r;
        this->i=i;
    }
    bool operator < (const Query &p)
    {
        if (l/blocksize == p.l/blocksize)
        {
            return r<p.r;
        }
        return (l/blocksize < p.l/blocksize);
    }
    friend ostream& operator<<(ostream& os, const Query& q)
    {
        os <<"["<<q.l<<" "<<q.r<<"]";
        return os;
    }

};

vector<int> fre(1000001);
vector<int> ar(200001);
vector<int> resps(200001);
vector<Query> pregs(200001);


void add(int pos)
{
	ll cnt = fre[ar[pos]];
	fre[ar[pos]]++;
 
	power -= (cnt * cnt) * ar[pos] , cnt++;
	power += (cnt * cnt) * ar[pos];
}

void remove(int pos)
{
	ll cnt = fre[ar[pos]];
	fre[ar[pos]]--;
 
	power -= (cnt * cnt) * ar[pos] , cnt--;
	power += (cnt * cnt) * ar[pos];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
 ll n,t;
 cin>>n>>t;
 for(ll i=0;i<n;i++) cin>>ar[i];
 for(ll j=0;j<t;j++)
 {
     ll l,r;
     cin>>l>>r;
     l--;
     r--;
     pregs[j]=Query(l,r,j);
 }
 sort(pregs.begin(),pregs.begin()+t);
 int ML = 0 , MR = -1;
for(int i=0;i<t;i++)
	{
		int L = pregs[i].l;
		int R = pregs[i].r;
        while(ML > L)
		ML-- , add(ML);
        while(MR < R)
        MR++ , add(MR);
        while(ML < L)
        remove(ML) , ML++;
        while(MR > R)
        remove(MR) , MR--;
        resps[pregs[i].i] = power;
    }
//Sacar la solución
for(ll i=0;i<t;i++) cout<<resps[i]<<endl;
 return 0;
}
