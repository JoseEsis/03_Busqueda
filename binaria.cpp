#include<iostream>
using namespace std;

int busquedaBinaria(int arr[], int n, int dato)
{
	int izq, der, cen,  m, pos;
	izq=1;
	der=n;
	cen=0;
	while(izq<=der and cen==0)
	{
		m=(izq+der)/2;
		if(arr[m]==dato)
		{
			cen=1;
		}
		else if(arr[m]<dato)
		{
			izq=m+1;
		}
		else
		{
			der=m-1;
		}	
	}
	if(cen==1)
	{
		pos=m;
	}
	else
	{
		pos=-izq;
	}
	return pos;
}
       
int main()
{
	int n, dato;
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
	cout<<"El elemento esta en la posicion: "<<busquedaBinaria( arr, n, dato)<<endl;
	

	
	
	return 0;
}       
       
       
       
       
       
       
       
       