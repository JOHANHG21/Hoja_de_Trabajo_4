/* Ejercicio#1
En la región de la sierra de los Cuchumatanes la compañía Xterminio s.a. , tiene las siguientes tarifas:
 Tipo   Servicio     Costo x Hectárea
 1		Mala Hierba      10.00
 2		Langostas		 20.00	
 3		Gusanos			 30.00

 4		Todo lo anterior 50.00
 
Además si el área a fumigar es mayor a 500.00 hectáreas se tiene un descuento del 5%. Adicionalmente,
si el total a pagar por el servicio es mayor a Q1500.00 se tiene un descuento adicional del 10% sobre el
excedente.
La compañía necesita las estadísticas de los servicios que ha ofrecido a un grupo de agricultores durante
un periodo de tiempo. Por cada servicio debe ingresar los datos siguientes: Tipo de Fumigación (1 a 4) y
el número de hectáreas, toda esta información deberá almacenarse en una base de datos (archivo plano).
Se le pide que realice un programa en C++ que solicite el ingreso de la información de cada servicio
realizado a un grupo de agricultores. El programa deberá de leer los datos del archivo que tiene la
información antes almacenada y mostrar la cantidad de servicios de cada tipo de fumigación, determinar
el tipo servicio con mayor demanda y el monto total pagado por los clientes. */

#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
using namespace std;

struct xterminio{
	int tipo_f;
	float desc;
	float precio;
	int hectareas;
	float pago_total;
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
		cout<<" 1 - Grabar Servicio "<<"\n";
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
	int tipo_f;
	float precio;
	int hectareas;
	float desc;
	float pago_total;
	string s;
	
		cout<<"----- Compañia <<Xterminio S.A.>> -----"<<endl;
	cout<<" Ingrese tipo de fumigacion: "<<endl;
	cout<<"   Mala Hierba    (Q10.00) -> 1  - "<<endl;
	cout<<"   Langostas      (Q20.00) -> 2  - "<<endl;
	cout<<"   Gusanos        (Q30.00) -> 3  - "<<endl;
	cout<<" Todo lo anterior (Q50.00) -> 4  - "<<endl;
	cout<<" Desc. 5% en area mayor a Q500.00  - "<<endl;
	cout<<" Desc. 10% en area mayor a Q1500.00 - "<<endl;
	cin>>tipo_f;
	cout<<"Ingrese la cantidad de hectareas a fumigar: "<<endl;
	cin>>hectareas;
	if (tipo_f ==1){
		precio = 10.00;
		pago_total = precio*hectareas; 	
	}
	else if (tipo_f ==2){
		precio = 20.00;
		pago_total = precio*hectareas; 	
	} else if (tipo_f ==3){
		precio = 30.00;
		pago_total = precio*hectareas; 
	} else if (tipo_f ==4){
		precio = 50.00;
		pago_total = precio*hectareas;
	}
	if(pago_total > 500 && pago_total <= 1500){
		desc = 0.05;
		pago_total = (precio - (desc*precio)*hectareas); 
	} else if (pago_total > 1500){
		desc = 0.10;
		pago_total = (precio - (desc*precio)*hectareas); 
	}
	ofstream grabar;
	try{
		grabar.open("xterminio.txt",ios::app);
		grabar<<tipo_f<<"\t"<<desc<<"\t"<<precio<<"\t"<<hectareas<<"\t"<<pago_total<<endl;
		grabar.close();
	}
	catch(exception X){
		cout<<"Error en la manipulacion del archivo"<<endl;
	}
	cout<<"\n"<<"Ventas Actuales"<<endl;
	cout<<"Tipo de fumigacion Servicio  Desc.  Precio  Hectareas  Total_Venta"<<endl;
	ifstream mostrar;
	try {
		mostrar.open("xterminio.txt",ios::in);				
		while (getline(mostrar, s))
			cout<<s<<endl;		
		mostrar.close();
	}
	catch(exception X){
		cout<<"Error en la manipulacion del archivo"<<endl;
	}
	
}	
	
void mostrar(){
	ifstream mostrar;
	float tf,d,p,h,pt=0;
	float sumatotal=0;
	float tf1=0;
	float tf2=0;
	float tf3=0;
	float tf4=0;	
	try{	
		mostrar.open("xterminio.txt",ios::in);
		
		while (mostrar >>tf >> d >>p>> h>>pt){
			sumatotal+= pt;	
			if (tf==1){
				tf1+=pt;
			}else if (tf==2){
				tf2+=pt;
			}else if (tf==3){
				tf3+=pt;
			}else if (tf==4){
				tf4+=pt;
			}
		}	
		mostrar.close();
		
		cout<<setprecision(5)<<"Total de Ventas:          "<<sumatotal<<endl;
		cout<<"Desgloce por producto:  "<<endl;
		cout<<setprecision(5)<<"  Mala Hierba  "<<tf1<<endl;
		cout<<setprecision(5)<<" Langostas "<<tf2<<endl;
		cout<<setprecision(5)<<" Gusanos   "<<tf3<<endl;
		cout<<setprecision(5)<<" Todo lo anterior"<<tf4<<endl;
	}
	catch (exception X){		
			cout<<"Error para abrir archivo"<<endl;			
			exit(1);
	}		
	
	
}

	
