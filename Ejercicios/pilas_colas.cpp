#include <bits/stdc++.h>

using namespace std;

template<class T> class exstack
{
private:
  stack<pair<T,T>> pila;
public:
  void push(T el)
  {
    if (pila.size()>0)
    {
        pila.push(make_pair(el,min(el,pila.top().second)));
    }
    else
    {
      pila.push(make_pair(el,el));
    }
  }
   void pop()
  {
    pila.pop();
  }
  T top()
  {
    return pila.top().first;
  }
  T minel()
  {
    return pila.top().second;
  }
  bool empty()
  {
    return pila.empty();
  }
  unsigned int size()
  {
      return pila.size();
  }
};

template<class T> class extqueue
{
private:
  exstack<T> fstack;
  exstack<T> sstack;
  void exchage()
  {
    while(!fstack.empty())
    {
      sstack.push(fstack.top());
      fstack.pop();
    }
  }
public:
  void push(T el)
  {
    fstack.push(el);
  }
  void pop()
  {
    exchage();
    if(!sstack.empty())
    {
      sstack.pop();
    }
  }
  T back()
  {
    exchage();
    if (!sstack.empty())
    {
      return sstack.top();
    }
  }
  T minel()
  {
      if (!fstack.empty() && !sstack.empty())
      {
        return min(fstack.minel(),sstack.minel());
      }
      else if (!fstack.empty() && sstack.empty())
      {
        return fstack.minel();
      }
      else
      {
        return sstack.minel();
      }
  }
};


int main()
{
  extqueue<double> pext;
  pext.push(10.0);
  pext.push(-1123.54);
  pext.push(12.2123);
  pext.push(-1123.23);
  pext.push(132.0);
  cout<<"Elemento minimo de la pila: "<<pext.minel()<<endl;
  cout<<"Ultimo elemento de la cola: "<<pext.back()<<endl;
  pext.pop();
  cout<<"Ultimo elemento de la cola: "<<pext.back()<<endl;
  pext.pop();
  cout<<"Elemento minimo de la pila: "<<pext.minel()<<endl;
  return 0;
}
