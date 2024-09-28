#include <iostream>
#include <string>
using namespace std;
struct Fecha {
    int dia;
    int mes;
    int anio;
};

struct Personal {
    string DNI;
    string nombres;
    Fecha fechaNacimiento;
};

int compararFechas(Fecha f1, Fecha f2) 
{
    if (f1.anio!=f2.anio) 
	{
        return f1.anio-f2.anio; 
        
    }else if (f1.mes!=f2.mes){
    	
        return f1.mes-f2.mes;
		   
    } 
	else
	{
        return f1.dia-f2.dia;   
    }
}

void ordenarInsercionDirectaPorFecha(Personal arr[], int& n) 
{
	int k;
	for(int i = 1; i < n; i++)
	{
		Personal aux = arr[i];
		k = i - 1;
		while(k >= 0 and compararFechas(aux.fechaNacimiento, arr[k].fechaNacimiento) < 0) { 
			arr[k + 1] = arr[k];
			k = k - 1;
		}
		arr[k + 1] = aux;
	}

    cout<<"\nDATOS ORDENADOS POR FECHA DE NACIMIENTO: \n"<<endl;
    for(int i=0; i<n; i++)
    {
    	cout<<"Datos de la persona ["<<i+1<<"]: "<<endl;
    	cout<<"DNI:"<<arr[i].DNI<<endl;
    	cout<<"Nombres:"<<arr[i].nombres<<endl;
    	cout<<"Fecha de nacimiento:"<<arr[i].fechaNacimiento.dia << "/" 
         << arr[i].fechaNacimiento.mes << "/" << arr[i].fechaNacimiento.anio << endl;
         cout<<endl;
	}
}
int busquedaBinariaPorFecha(Personal arr[], int n, Fecha fechaBuscada)
{
	int izq, der, cen,  m, pos;
	izq=0;
	der=n-1;
	cen=0;
	pos=-1;
	while(izq<=der and cen==0)
	{
		m=(izq+der)/2;
		int comparar=compararFechas(arr[m].fechaNacimiento, fechaBuscada);


		if(comparar==0)
		{
			cen=1;
			pos=m;
		}
		else if(comparar<0)
		{
			izq=m+1;
		}
		else
		{
			der=m-1;
		}	
	}
	if(cen==0)
	{
		pos=-1;
	}
	return pos;
}

int main() 
{    
    Personal arr[5] = {
        {"12345678", "Juan Perez", {15, 3, 1995}},
        {"23456789", "Ana Gomez", {7, 7, 1989}},
        {"34567890", "Carlos Diaz", {25, 12, 2000}},
        {"45678901", "Maria Lopez", {1, 1, 1990}},
        {"56789012", "Luis Fernandez", {18, 5, 1993}}
    };
    int n;
    n=5;
    ordenarInsercionDirectaPorFecha(arr, n);
    cout<<endl;
    Fecha fechaBuscada;
    cout<<"\nIngrese la fecha de nacimiento a buscar: \n";
    cout<<"Dia: ";
	cin>>fechaBuscada.dia;
    cout<<"Mes: ";
	cin>>fechaBuscada.mes;
    cout<<"Anio: "; 
	cin>>fechaBuscada.anio;
	cout<<endl;
	
	int posicion=busquedaBinariaPorFecha(arr, n, fechaBuscada);
    
    if(posicion!=-1) 
	{
        cout<<"\nPersona encontrada: "<<arr[posicion].nombres<<" - DNI: "<<arr[posicion].DNI<<endl;
    } 
	else 
	{
        cout<<"\nNinguna persona fue registrada con esa fecha de nacimiento."<< endl;
    }
    return 0;
}