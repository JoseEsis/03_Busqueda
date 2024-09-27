#include<iostream>

using namespace std;

int busquedaSecuencialDesor(int arr[], int n, int dato)
{
	int pos, i;
	pos=0;
	i=1;
	while(i<=n and arr[i]!=dato)
	{
		i=i+1;
	}
	if(i<=n)
	{
		pos=i;
	}
	else
	{
		return pos;		
	}
}
int busquedaSecuencialOrd(int arr[], int n, int dato)
{
	int i, pos;
	i=1;
	while(i<=n and arr[i]<dato)
	{
		i=i+1;
	}
	if(i>n or arr[i]!=dato)
	{
		pos=-i;
	}
	else
	{
		pos=i;		
	}
	return pos;
	 
}

int main()
{
	
	int opc;
	do{
		cout<<"\nBUSQUEDA SECUENCIAL"<<endl;
		cout<<"1. Datos desordenados. "<<endl;
		cout<<"2. Datos ordenados. "<<endl;
		cout<<"3. Salir del programa. "<<endl;
		cout<<"Ingrese una opcion: ";
		cin>>opc;
		switch(opc)
		{
			case 1:
				{
					cout<<"\nBusqueda para datos desordenados: "<<endl;
					int n;
					int dato;
					cout<<"Ingrese la cantidad de elementos del arreglo: ";
					cin>>n;
					int arr[n];
					cout<<"Ingrese los valores del arreglo: "<<endl;
					for(int i=0; i<n; i++)
					{
						cout<<"arr[ "<<i<<" ]: ";
						cin>>arr[i];
					}
					cout<<"Los valores ingresados: "<<endl;
					for(int i=0; i<n; i++)
					{
						cout<<arr[i]<<" ";
					}
					cout<<endl;
					cout<<"Ingrese el dato a buscar: "<<endl;
					cin>>dato;
					
					cout<<"\nEl elemento esta en la posicion: "<<busquedaSecuencialDesor(arr, n, dato)<<endl;
					break;
				}
			case 2:
				{
					cout<<"\nBusqueda para datos ordenados: "<<endl;
					int n;
					int dato;
					cout<<"Ingrese la cantidad de elementos del arreglo: ";					
					cin>>n;
					int arr[n];
					cout<<"Ingrese los valores del arreglo: "<<endl;
					for(int i=0; i<n; i++)
					{
						cout<<"arr[ "<<i<<" ]: ";
						cin>>arr[i];
					}
					cout<<"Los valores ingresados: "<<endl;
					for(int i=0; i<n; i++)
					{
						cout<<arr[i]<<" ";
					}
					cout<<endl;
					cout<<"Ingrese el dato a buscar: "<<endl;
					cin>>dato;
					cout<<"\nEl elemento esta en la posicion: "<<busquedaSecuencialOrd(arr, n, dato)<<endl;					
					break;
				}
			case 3:
				{
					cout<<"\nSaliendo del programa. "<<endl;
					break;
					
				}
			default:
				{
					cout<<"\nDato invalido..."<<endl;		
				} 
			
		}
		
	}while(opc!=3);
	
	
	return 0;
}