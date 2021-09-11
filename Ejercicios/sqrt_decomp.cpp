#include<bits/stdc++.h>
#include<ctime> 
#define ll long long int
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //Es una herramienta secreta que nos servirá mas tarde
    ll n;
    cin>>n;
    vector<ll> a(n);
    for(int i=0;i<n;i++) a[i]=rand() % 201 - 100;
    // Creamos el arreglo que contiene la iformación del bloque de raíz de n
    vector<ll> b((ll)sqrt(n)+1);
    cout<<"Bloques de la descomposicion: "<<b.size()<<endl;
    for (int i=0;i<a.size();i++)
    {
        b[i/b.size()]+=a[i];
    }
    cout<<"Consulta en un intervalo [l,r]"<<endl;
    ll l,r;
    cin>>l>>r;
    ll sum;
    sum=0;
    //SQRT decomposition
    clock_t begin = clock();
    for(ll i=l;i<=r;)
    {
        //Tenemos dos casos, que el intervalo de la consulta sea el de [l,r]
        // O que elementos aislados queden en partes del bloque
        if(i % b.size() == 0 && i + b.size()-1 <= r)
        {
            sum+=b[i/b.size()];
            i+=b.size();
        }
        else{
            sum+=a[i];
            i++;
        }
    }
    clock_t end = clock();
    double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
    cout<<"Suma en el intervalo ["<<l<<","<<r<<"]: "<<sum<<" terminada en "<<elapsed_secs<<" secs"<<endl; 
    //Metodo tradicional
    ll suma2=0;
    begin=clock();
    for(ll i=l;i<=r;i++) suma2+=a[i];
    end= clock();
    double elapsed_secs1 = double(end - begin) / CLOCKS_PER_SEC;
    cout<<"Suma en el intervalo ["<<l<<","<<r<<"]: "<<suma2<<" terminada en "<<elapsed_secs<<" secs"<<endl;
    cout<<"Tiempo menor?: "<<(elapsed_secs< elapsed_secs1)<<endl;
    return 0;
}