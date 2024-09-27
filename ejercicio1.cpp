#include<iostream>
using namespace std;

struct monomio{
	int coef;
	int exp;
};

void ordenarPolinomio(monomio ter[], int n)
{
	for(int i = 0 ; i < n - 1 ; i++)
	{
		for(int j =  i+1 ; j < n  ; j++)
		{
			if( ter[i].exp > ter[j].exp)
			{
				monomio aux;
				aux = ter[i];
				ter[i] = ter[j];
				ter[j] = aux;
			}
		}
	}
	cout<<"Polinomio ordenado: "<<endl;
	for(int i=0; i<n; i++)
	{
		if(i>0 and ter[i].coef>0) 
		{
			cout<<" + "; 
		}
		if(ter[i].coef > 0)
		{
			cout<<ter[i].coef;
		}
		if(ter[i].exp == 0) 
		{
			cout<<ter[i].coef; 
		}
		else if (ter[i].exp == 1) 
		{
			cout<<"x"; 
		}
		else 
		{
			cout<< "x^" <<ter[i].exp;  
		}
	}
	cout<<endl;
	
}


int busquedaSecuencialOrd(monomio ter[], int n, monomio buscarDato)
{
	int i, pos;
	i=0;
	while(i<n and ter[i].exp<buscarDato.exp)
	{
		i=i+1;
	}
	if(i<n and ter[i].exp==buscarDato.exp and ter[i].coef==buscarDato.coef )
	{
		pos=i;
	}
	else
	{
		pos=-i;		
	}
	return pos;
}


int main()
{
	int n;
	cout<<"Ingrese la cantidad de elementos del arreglo: ";
	cin>>n;
	monomio ter[n];
	for(int i=0; i<n; i++)
	{
		cout<<"Ingrese el coeficiente del monomio [ "<<i+1<<" ]: ";
		cin>>ter[i].coef;
		cout<<"Ingrese el exponente del monomio [ "<<i+1<<" ]: ";
		cin>>ter[i].exp;
	}
	cout<<endl;
	ordenarPolinomio(ter, n);
	monomio buscarMonomio;
	cout<<"\nBUSCAR MONOMIO: "<<endl;
	cout<<"Ingrese el coeficiente del monomio: ";
	cin>>buscarMonomio.coef;
	cout<<"Ingrese el exponente del monomio: ";
	cin>>buscarMonomio.exp;
	cout<<endl;
	int posicion=busquedaSecuencialOrd(ter, n, buscarMonomio);
    if(posicion!=-1)
	{
		cout<<"El monomio si esta en el arreglo."<<endl;
        cout<<"El monomio se encuentra en la posicion: "<<posicion<< endl;
    } 
	else
	{
        cout<<"El monomio no se encuentra en el arreglo."<< endl;
    }

	
	
	return 0; 
}