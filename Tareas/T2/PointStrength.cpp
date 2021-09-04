#include <bits/stdc++.h>


#define ll long long
#define INF 10000000000
using namespace std;

class Pareja
{
public:
  pair<ll,ll> par;
  ll pos;
};

bool operator < (const Pareja &p,const Pareja &q)
{
  if(p.par.second < q.par.second) return true;
  else if(p.par.second == q.par.second)
  {
    if(p.par.first < q.par.first) return true;
    else return false;
  }
  else return false;
}

int main()
{

  vector<Pareja> pvec;
  int testcases;
  cin>>testcases;
  for(int i=0;i<testcases;i++)
  {
    ll a,b;
    cin>>a>>b;
    Pareja pr;
    pr.par=make_pair(a,b);
    pr.pos=i;
    pvec.push_back(pr);
  }
  sort(pvec.begin(),pvec.end());
  reverse(pvec.begin(),pvec.end());
  vector<int> vecdom(testcases,0); //De longitud test cases y relleno con 0
  ll min=pvec[0].par.second+1;
  ll minx=-INF;
  ll cnt=0;
  for (vector<Pareja>::iterator it=pvec.begin();it!=pvec.end();++it)
  {
    //cout<<(*it).par.first<<" "<<(*it).par.second<<endl;
    if ((*it).par.second <= min)
    {
      if((*it).par.first <= minx)
      {
        cnt=distance(pvec.begin(),it);
      }
    }
    min=(*it).par.second;
    minx=(*it).par.first;
    vecdom[(*it).pos]=cnt;
  }

  for (vector<int>::iterator it=vecdom.begin();it!=vecdom.end();++it)
  {
    cout<<*it<<endl;
  }
  return  0;
}
