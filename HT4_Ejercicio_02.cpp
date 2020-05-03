/*
Ejercicio#2 Una persona desea realizar un muestreo con un numero de personas para determinar el 
porcentaje de niños, jóvenes, adultos y adultos mayores que existen en la zona en donde vive. 
La categoría se determina en base a la siguiente tabla: 

CATEGORIA 		   EDAD
Niños        		0-12
Jovenes	     		13-29
Adultos      		30-59
Adultos Mayores 	60 en adelante

Teniendo en cuenta que para el muestreo de personas no será mayor a 50, 
realice un programa que en primer lugar reciba como dato el numero de personas del 
muestreo y luego por cada persona permita el ingreso de su edad y grabar todo a un archivo. 
El programa deberá leer los datos del archivo y mostrar como resultado el porcentaje de personas que hay por cada una de las categorías. 
*/

#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
using namespace std; 
struct muestreo{
	int cantidad_p=50;
	int personas=1;
	int edad;
	float categoria;
};
void mp();
void grabar();
void mostrar();
int main(){
	mp();
}
void mp(){
	int resp;
	do {
		system("CLS");
		cout<<"--------------------------"<<"\n";
		cout<<" Menu Principal Xterminio S.A. "<<"\n";
		cout<<"-------------------"<<"\n";
		cout<<" 1 - Ingresar Edad "<<"\n";
		cout<<" 2 - Mostrar Reporte "<<"\n";
		cout<<" 3 - Salir"<<"\n";
		cout<<"--------------------------"<<"\n";
		cout<<" Seleccione su opcion: ";
		cin>>resp;
		if (resp==1){		
			system("CLS");
			grabar();			
		}
		else if (resp==2){		
			system("CLS");
			mostrar();
		}			
		else if (resp==3)
			break;
		else 
			break;
		
	} while(resp!=3);	
}
void grabar(){
	int cantidad_p=50;
	int personas;
	int edad;
	float categoria;
	float n=0;
	float j=0;
	float a=0;
	float am=0;
	string s;
	
		cout<<"----- Muestreo de Personas -----"<<endl;
	cout<<"¿Cual es la cantidad de personas para la muestra?: ";
	cin>>personas;
	while (personas<=cantidad_p){
	cout<<" Ingrese su edad: "<<endl;
	cin>>edad;
	if (edad >=0 && edad <=12){
		categoria+=n;
		cout<<"Eres un niño"<<endl; 	
	}
	else if (edad >=13 && edad <=29){
		categoria+=j; 	
		cout<<"Eres un joven"<<endl;
	} else if (edad >=30 && edad <=59){
		categoria+=a;  
		cout<<"Eres un adulto"<<endl;
	} else if (edad >=60){
		categoria+=am; 
		cout<<"Eres un adulto mayor"<<endl;
	}else {
		cout<<"Solo se permiten 50 registros"<<endl;
	}
ofstream grabar;
	try{
		grabar.open("muestreo.txt",ios::app);
		grabar<<edad<<"\t"<<categoria<<endl;
		grabar.close();
	}
	catch(exception X){
		cout<<"Error en la manipulacion del archivo"<<endl;
	}
	cout<<"\n"<<"Registros actuales"<<endl;
	cout<<"Edad "<<"\t"<<"Categoria"<<endl;
	ifstream mostrar;
	try {
		mostrar.open("muestreo.txt",ios::in);				
		while (getline(mostrar, s))
			cout<<s<<endl;		
		mostrar.close();
	}
	catch(exception X){
		cout<<"Error en la manipulacion del archivo"<<endl;
	}
	
}
}
void mostrar(){
	ifstream mostrar;
	float personas,n,j,a,am;
	try{	
		mostrar.open("muestreo.txt",ios::in);
		mostrar.close();
		cout<<setprecision(5)<<"Total de Personas:          "<<personas<<endl;
		cout<<"Desgloce por categorias:  "<<endl;
		cout<<setprecision(5)<<"  Niños  "<<n<<" - % sobre el total: "<<setprecision(3)<<n*100/personas<<endl;
		cout<<setprecision(5)<<" Jovenes "<<j<<" - % sobre el total: "<<setprecision(3)<<j*100/personas<<endl;
		cout<<setprecision(5)<<" Adultos   "<<a<<" - % sobre el total: "<<setprecision(3)<<a*100/personas<<endl;
		cout<<setprecision(5)<<" Adultos Mayores"<<am<<" - % sobre el total: "<<setprecision(3)<<am*100/personas<<endl;
	}
	catch (exception X){		
			cout<<"Error para abrir archivo"<<endl;			
			exit(1);
	}		
	
	
}
	
