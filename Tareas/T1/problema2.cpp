#include <bits/stdc++.h>

/*
Implementación de un árbol binario de búsqueda no balanceado
Hijo izquierdo es menor
hijo derecho es mayor
@Author Daniel Vallejo Aldana
@Institution Universidad de Guanajuato, Licenciatura en Computación
*/
using namespace std;

template<class T> class Tnode
{
public:
  T item;
  Tnode *l,*r; // Apuntadores a los hijos del árbol
  Tnode()
  {
    this->l=NULL;
    this->r=NULL;
  }
  Tnode(T item)
  {
    this->item=item;
    this->l=NULL;
    this->r=NULL;
  }
};

template<class T> class BST
{
private:
  Tnode<T> root;
public:
  BST(){}
  BST(T item)
  {
    this->root.item=item;
    this->root.l=NULL;
    this->root.r=NULL;
  }
  T get_root()
  {
    return root.item;
  }
  void walk2insert(T item, Tnode<T> *current)
  {
    if(current->item >=item)
    {
      if (current->r == NULL)
      {
        current->r=new Tnode<T> (item);
      }
      else walk2insert(item,current->r);
    }
    else
    {
      if(current->l==NULL)
      {
        current->l=new Tnode<T> (item);
      }
      else walk2insert(item,current->l);
    }
  }
  void insert(T item)
  {
    if(!walk2visit(&root,item)) walk2insert(item,&root);
  }
  void printArbol(Tnode<T> *nodo)
  {
    if(nodo==NULL) return;
    printArbol(nodo->l);
    cout<<nodo->item<<" ";
    printArbol(nodo->r);
  }
  void print()
  {
    printArbol(&root);
    cout<<endl;
  }

  Tnode<T> * walk2visit(Tnode<T> *current,T item)
  {
    if(!current) return NULL;
    if(current->item==item) return current;
    else if(current->item >= item)
    {
      return walk2visit(current->r,item);
    }
    else
    {
      return walk2visit(current->l,item);
    }
  }
  bool find(T item)
  {
    return walk2visit(&root,item)!=NULL;
  }
  T Min(Tnode<T> *current)
  {
    while(current->l) current=current->l;
    return current->item;
  }
  T Max(Tnode<T> *current)
  {
    while(current->r) current=current->r;
    return current->item;
  }
  T minel()
  {
    return Min(&root);
  }
  T maxel()
  {
    return Max(&root);
  }

};

int main()
{
  BST<int> arbol(3);
  cout<<arbol.get_root()<<endl;
  arbol.insert(5);
  arbol.insert(14);
  arbol.print();
  cout<<arbol.find(14)<<endl;
  cout<<arbol.maxel()<<endl;
  cout<<arbol.minel()<<endl;
  arbol.insert(5);
  return 0;
}
