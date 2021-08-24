#include<bits/stdc++.h>
#include<ctime>

using namespace std;

//Generación de numeros aleatorios grandes

typedef unsigned long long int UINT64;
//Generación de numeros grandes, numeros de 64 bits es 2^{64}-1 approx 10^19
UINT64 getRandom(UINT64 const& min = 0, UINT64 const& max = 0)
{
    return (((UINT64)(unsigned int)rand() << 32) + (UINT64)(unsigned int)rand()) % (max - min) + min;
}

int main()
{
  srand(time(NULL));
  cout<<"Presiona g para generar y q para salir"<<endl;
  char s;
  while(cin>>s && s!='q' && s=='g')
  {
    cout<<getRandom(0,ULLONG_MAX)<<endl;
    // ULLONG_MAX es el máximo número que puede ser generado con unsigned long long int que es 2^{64}-1
    // Ojo: la máquina debe de ser de 64 bits para que esto sea cierto
  }
  return 0;
}
