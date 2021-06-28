#include<iostream>
#include <string>
#include <cstdlib>
using namespace std;

//menu general
int menuGeneral();

//Funciones
void analizadorLexico(string v);
void analizadorSintactico(string v);
void errores (int codigo);

string v;

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
			cin.ignore();
			getline(cin,v);
			
			cout<<""<<endl;
			analizadorLexico(v);
		}
			break;
		case 2:{
			cout<<"\t\t..:: ANALIZADOR SINTANTICO ::.."<<endl<<endl;
			cout<<""<<endl;
			analizadorSintactico(v);
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
void errores(int codigo){
	int x;
	cout<<" ERROR SINTACTICO "<<codigo;
	switch (codigo)
	{
	case 1 :cout<<" :ESPERABA UN ;"<<endl;break;
	case 2 :cout<<" :ESPERABA UNA }"<<endl;break;
	case 3 :cout<<" :ESPERABA UN ="<<endl;break;
	case 4 :cout<<" :ESPERABA UN )"<<endl;break;
	case 5 :cout<<" :ESPERABA UN IDENTIFICADOR"<<endl;break;
	case 6 :cout<<" :INSTRUCCION DESCONOCIDA"<<endl;break;
	case 7 :cout<<" :ESPERABA UNA CONSTANTE"<<endl;break;
	case 8 :cout<<" :ESPERABA UNA M DE MAIN"<<endl;break;
	case 9 :cout<<" :ESPERABA UNA {"<<endl;break;
	default:
		cout<<" :NO DOCUMENTADO"<<endl;
	}
	cin>>x;
	exit(1);
}
		
void analizadorSintactico(string v1){
	//DEFINICIONES DE TERMINALES

	int n=v.length();
	string parse = "1 2";
	//M { R a; R b; c = a + b - 2 ; W c }
	//M {R x; R y; d = x * x + y * y; i = x * x - y * y; c = (d + x) / (d -y); W d; W i; W c}
	cout<<"\n\n\n ...::: PARSE :::..."<<endl;
	for(int i=0;i<n;i++){
		if(v[i]=='R')
			parse=parse+"6 21 ";
		if(v[i]=='W')
			parse=parse+"7 22 ";
		if(v[i]=='(')
			parse=parse+"18 ";
		if(v[i]=='+'){
			parse=parse+"10 13 19 ";
		}if(v[i]=='-'){
			parse=parse+"11 13 19 ";
		}
		if(v[i]==';'){
			if((v[i-2]=='a'||v[i-2]=='b'||v[i-2]=='2')&&(v[i-3]=='*'||v[i-3]=='-'||v[i-3]=='+'||v[i-3]=='/'))
				parse=parse+"17 ";
		}
//		else errores(1);
//		break;
		if(v[i]==';'){
			parse=parse+"3 ";
			if(v[i+4]=='='){
				parse=parse+"5 8 ";
			}
		}
		if(v[i]=='*'){
			parse=parse+"14 ";
		}
		else if(v[i]=='a'){
			parse=parse+"23 ";
		}else if(v[i]=='b'){
			parse=parse+"24 ";
		}else if(v[i]=='c'){
			parse=parse+"25 ";
			if(v[i+2]=='='){
				parse=parse+"9 13 19 ";	
			}
		}else if(v[i]=='d'){
			parse=parse+"26 ";
		}else if(v[i]=='e'){
			parse=parse+"27 ";
		}else if(v[i]=='f'){
			parse=parse+"28 ";
		}else if(v[i]=='g'){
			parse=parse+"29 ";
		}else if(v[i]=='h'){
			parse=parse+"30 ";
		}else if(v[i]=='i'){
			parse=parse+"31 ";
		}else if(v[i]=='j'){
			parse=parse+"32 ";
		}else if(v[i]=='k'){
			parse=parse+"33 ";
		}else if(v[i]=='l'){
			parse=parse+"34 ";
		}else if(v[i]=='m'){
			parse=parse+"35 ";
		}else if(v[i]=='n'){
			parse=parse+"36 ";
		}else if(v[i]=='o'){
			parse=parse+"37 ";
		}else if(v[i]=='p'){
			parse=parse+"38 ";
		}else if(v[i]=='q'){
			parse=parse+"39 ";
		}else if(v[i]=='r'){
			parse=parse+"40 ";
		}else if(v[i]=='s'){
			parse=parse+"41 ";
		}else if(v[i]=='t'){
			parse=parse+"42 ";
		}else if(v[i]=='u'){
			parse=parse+"43 ";
		}else if(v[i]=='v'){
			parse=parse+"44 ";
		}else if(v[i]=='w'){
			parse=parse+"45 ";
		}else if(v[i]=='x'){
			parse=parse+"46 ";
		}else if(v[i]=='y'){
			parse=parse+"47 ";
		}else if(v[i]=='z'){
			parse=parse+"48 ";
		}else if(v[i]=='0'){
			parse=parse+"49 ";
		}else if(v[i]=='1'){
			parse=parse+"50 ";
		}else if(v[i]=='2'){
			parse=parse+"51 ";
		}else if(v[i]=='3'){
			parse=parse+"52 ";
		}else if(v[i]=='4'){
			parse=parse+"53 ";
		}else if(v[i]=='5'){
			parse=parse+"54 ";
		}else if(v[i]=='6'){
			parse=parse+"55 ";
		}else if(v[i]=='7'){
			parse=parse+"56 ";
		}else if(v[i]=='8'){
			parse=parse+"57 ";
		}else if(v[i]=='9'){
			parse=parse+"58 ";
		}
	}
	cout<<endl;
	cout<<"parse: "<<parse<<endl;
}
			
			
			
