#include<iostream>
#include <string>
#include <cstdlib>
using namespace std;

//menu general
int menuGeneral();

//Funciones
void analizadorLexico(string v);
void analizadorSintactico(string v);

int main (int argc, char *argv[]) {
	int opcionGeneral;
	system("color e0");
	cout<<"\n\t\t\t\t\t  ...::: BIENVENIDOS :::...";
	cout<<"\n\t         .:.		";
	cout<<"\n\t  				";
	cout<<"\n\t::::     :::		";
	cout<<"\n\t ::::    ::		";
	cout<<"\n\t ::  ::  ::		";
	cout<<"\n\t ::   :: ::  	Universidad";
	cout<<"\n\t:::    :.:::  	Privada del Norte";
	cout<<"\n\t    				";
	cout<<endl;
	cout<<"\nIntegrantes: "<<endl<<endl;
	cout<<"\t* Ignacio Velásquez Jhan Carlos"<<endl;
	cout<<"\t* Jeyson Chavez"<<endl;
	cout<<"\t* Braulio Anchante"<<endl;
	cout<<"\t* Brayan Vargas"<<endl;
	cout<<"\t* Camila Ortiz"<<endl;
	cout<<"\t* Ronald Ruiz"<<endl;
	
	cout<<endl;
	cout<<"\nDocente: "<<endl<<endl;
	cout<<"\t* Ing. Laura Sofia Bazan Diaz"<<endl<<endl;
	cout<<"\n\t\t\t\t ";
	cout<<"\n\t\t\t\t ";
	system("pause");
	system("cls");
	
	system("color f");
	
	do{
		system("color FC");
		opcionGeneral = menuGeneral();
		switch(opcionGeneral){
		case 1:{
			system("color E1");
			cout<<"\t\t..:: ANALIZADOR LÉXICO ::.."<<endl<<endl;
			
			cout<<"Ingrese expresión: ";
			string v;
			cin.ignore();
			getline(cin,v);
			
			cout<<""<<endl;
			analizadorLexico(v);
		}
			break;
		case 2:{
			//system("color E1");
			cout<<"\t\t..:: ANALIZADOR LÉXICO ::.."<<endl<<endl;
			
			cout<<"Ingrese expresión: ";
			//char v[LIM];
			string v1;
			//cin>>v;
			cin.ignore();
			getline(cin,v1);
			
			//analizadorSintactico(string v1);
			}
			break;
		case 3:{
			cout<<"\nFin del Programa"<<endl<<endl;
			}
			break;
		default:
			cout<<"\n¡Opcion no valida!"<<endl<<endl;	
		};
		cout<<""<<endl;
		system("pause");
	}while(opcionGeneral !=3);
	
	return 0;
}
//Menú
int menuGeneral(){
	system("cls");
	cout<<"\t...::: MENU DE OPCIONES :::..."<<endl;
	cout<<"[1] Analizador Léxico"<<endl;
	cout<<"[2] Analizador Sintáctico"<<endl;
	cout<<"[3] Salir"<<endl<<endl;
	cout<<"\tSeleccione una Opcion: ";
	int opcionGeneral;
	cin>>opcionGeneral;
	cout<<"-------------------------------------------"<<endl;
	
	return opcionGeneral;
}

//Funciones
void analizadorLexico(string v){
	int n=v.length();
	int c=0;
	string array;
	bool encontrado;
	
	for(int i=0; i<n; i++){
		encontrado = false;
		if(isspace(v[i]))
			i++;
		//operadores
		if(v[i]=='+' || v[i]=='-' || v[i]=='*' || v[i]=='/' || v[i]=='%'){
			for(int j=0;j<c;j++){
				if(array[j]==v[i]){
					encontrado = true;
					break;
				}
			}
			if(encontrado==false){
				array[c]=v[i];
				c++;
			}
		}
		//constantes numpericas
		else if(v[i]>=48 && v[i<=57]){
			for(int j=-1;j<c;j++){
				if(array[j+1]==v[i]){
					encontrado = true;
					break;
				}
			}
			if(encontrado==false){
				array[c]=v[i];
				c++;
			}
		}
		//identificadores
		else if(v[i]>=97 && v[i]<=122){
			for(int j=-1;j<c;j++){
				if(array[j+1]==v[i]){
					encontrado = true;
					break;
				}
			}
			if(encontrado==false){
				array[c]=v[i];
				c++;
			}
		}
		//simbolo de asignacion
		else if(v[i]==61){
			for(int j=-1;j<c;j++){
				if(array[j+1]==v[i]){
					encontrado = true;
					break;
				}
			}
			if(encontrado==false){
				array[c]=v[i];
				c++;
			}
		}
		//parentisis
		else if(v[i]>=40 && v[i]<=41){
			for(int j=-1;j<c;j++){
				if(array[j+1]==v[i]){
					encontrado = true;
					break;
				}
			}
			if(encontrado==false){
				array[c]=v[i];
				c++;
			}
		}
		//separador de sentencias
		else if(v[i]==59){
			for(int j=-1;j<c;j++){
				if(array[j+1]==v[i]){
					encontrado = true;
					break;
				}
			}
			if(encontrado==false){
				array[c]=v[i];
				c++;
			}
		}
		//indicador de principio y fin de bloque
		else if(v[i]==123 || v[i]==125){
			for(int j=-1;j<c;j++){
				if(array[j+1]==v[i]){
					encontrado = true;
					break;
				}
			}
			if(encontrado==false){
				array[c]=v[i];
				c++;
			}
		}
		//iPalabras reservadas
		else if(v[i]=='R' || v[i]=='W' || v[i]=='M'){
			for(int j=-1;j<c;j++){
				if(array[j+1]==v[i]){
					encontrado = true;
					break;
				}
			}
			if(encontrado==false){
				array[c]=v[i];
				c++;
			}
		}
		else{
			cout<<"\n\t¡Regla no definida!"<<endl;
		}
	}
	
	cout<<"\n...::: TABLA DE SIMBOLOS :::..."<<endl;
	for(int i=0;i<c;i++){

		cout<<"["<<i<<"] : "<<array[i]<<endl;

	}
	
	cout<<"\n\n\n ...::: SECUENCIA DE TOKENS :::..."<<endl;
	for(int i=0;i<n;i++){
		//operadores
		if(v[i]=='+' || v[i]=='-' || v[i]=='*' || v[i]=='/' || v[i]=='%'){
			for(int j=0;j<c;j++){
				if(v[i]==array[j]){
					cout<<"<oper, "<<j<<">"<<endl;
				}
			}
		}
		//constantes numpericas
		else if(v[i]>= 48 && v[i]<=57){
			for(int j=0;j<c;j++){
				if(v[i]==array[j]){
					cout<<"<num, "<<j<<">"<<endl;
				}
			}
		}
		//identificadores
		else if(v[i]>= 97 && v[i]<=122){
			for(int j=0;j<c;j++){
				if(v[i]==array[j]){
					cout<<"<iden, "<<j<<">"<<endl;
				}
			}
		}
		//simbolo de asignacion
		else if(v[i]==61){
			for(int j=0;j<c;j++){
				if(v[i]==array[j]){
					cout<<"<asig, "<<j<<">"<<endl;
				}
			}
		}
		//parentesis - agroup
		else if(v[i]>=40 && v[i]<=41){
			for(int j=0;j<c;j++){
				if(v[i]==array[j]){
					cout<<"<parentisis, "<<j<<">"<<endl;
				}
			}
		}
		//separador de sentencias
		else if(v[i]==59){
			for(int j=0;j<c;j++){
				if(v[i]==array[j]){
					cout<<"<sepSentencias, "<<j<<">"<<endl;
				}
			}
		}
		//indicador de principio y fin de bloque - group
		else if(v[i]==123 || v[i]==125){
			for(int j=0;j<c;j++){
				if(v[i]==array[j]){
					cout<<"<priFin, "<<j<<">"<<endl;
				}
			}
		}
		//palabras Reservadas
		else if(v[i]=='R' || v[i]=='W' || v[i]=='M'){
			for(int j=0;j<c;j++){
				if(v[i]==array[j]){
					cout<<"<PalReservadas, "<<j<<">"<<endl;
				}
			}
		}
		else if(v[i]==32){
			cout<<"";
		}
		else{
			cout<<"¡Error, no reconocido!"<<endl;
			/*\n\t¡Error, no definido!*/
		}
	}
}
	
void analizadorSintactico(string v1){
	//DEFINICIONES DE TERMINALES
	char terminales[30] = {'a','b','c','d','f','g','h','i','j','l','o','p','k','r','s','t','u','v','w','y','z'};
	
	//DEFINICIONES DE NO TERMINALES
	cout<<"!Hola Mundo XD¡"<<endl;
}

