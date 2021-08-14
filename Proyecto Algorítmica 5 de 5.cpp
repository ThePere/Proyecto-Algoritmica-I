#include <iostream>
#include <conio.h>
#include <windows.h>
#include <string.h>
#include <stdlib.h>
#include <fstream>

using namespace std;

struct perro{
	int codigo;
	char nombre[30];
	int edad;
	string enfermedad;
	char tamano[8];
	string raza;
	char fecha[9];
	string estado;
}dog[99];

struct cliente{
	char nombre[50];
	char dni[8];
	int edad;
	int codigo;
}persona[99];

void menu_principal();
//Como no existe el gotoxy en el Dev, declaramos una función para que haga la misma función
void gotoxy(int x, int y); //Sirv para manipular la ubicación de los caracteres
void dibujarCuadrado(int x1,int y1,int x2,int y2);
void pacientes();
void servicios();
void adopciones();
void ventaArticulos();
void transicion();
void transicion2();
void agregarPaciente(ofstream &esc);
bool verificar_cod(string cod);
void verPaciente(ifstream &leer);
void buscarPaciente(ifstream &lec);
void modificarPaciente(ifstream &lec);
void eliminarPaciente(ifstream &lec);
void menu_adopcion();
void nuevoingreso(int&,int&);
void lista(int&);
void adoptar(int&,int&,int&);
void registro(int&);
void cambio();
void menu_servicios();
int bano();
int vacunas();
int tratamientos();
int corte();
int operaciones();
int analisis();
void cita();
void boleta(int vec[]);
void ventaDeArticulos();
bool verificarProducto(string,ifstream &,float &,int &);
void buscarProductosEnSistema(ifstream &);
void agregarProducto(ofstream &,ifstream &);
void modificarCantidadProducto(ifstream &,string,int);
void generarCompra(ifstream &);
int a=0,b=0,cod=0,cod2=0;

int main(){
	ofstream esc;
	char opc;
	SetConsoleCP(1252); // Cambiar cin -  Para máquinas Windows
	SetConsoleOutputCP(1252); // Cambiar cout - Para máquinas Windows
    system("Color 30");//Darle color al programa
    dibujarCuadrado(1,1,78,24);//Cuadro del fondo
	dibujarCuadrado(2,2,77,4);//Cuadro del titulo
    gotoxy(18,3);cout<<"VETERINARIA PARA PERROS - HUELLITAS UNIDAS"<<endl;
        menu_principal();
	getch();
    return 0;
}

void menu_principal(){
	system("cls");
	char opc;
	dibujarCuadrado(1,1,78,24);//Cuadro del fondo
	dibujarCuadrado(2,2,77,4);//Cuadro del titulo
	gotoxy(18,3);cout<<"VETERINARIA PARA PERROS - HUELLITAS UNIDAS"<<endl;
	do{
	gotoxy(15,5);cout<<"MENÚ"<<endl;
    gotoxy(4,7);cout<<"(1) Pacientes";
    gotoxy(4,9);cout<<"(2) Servicios";
    gotoxy(4,11);cout<<"(3) Adopciones";
    gotoxy(4,13);cout<<"(4) Venta de artículos";
    gotoxy(4,15);cout<<"(0) Salir";
    gotoxy(4,17);cout<<"Digite una opción: ";
    cin>>opc;
    transicion();
        if(opc!='1' and opc!='2' and opc!='3' and opc!='4' and opc!='0'){
        	gotoxy(3,13);cout<<"Error, presione una tecla para volver a intentarlo."<<endl;
        	getch();
        	transicion();
		}
		cin.ignore();
    }while(opc!='1' and opc!='2' and opc!='3' and opc!='4' and opc!='0');
   	switch (opc){
   		case '1':{
   			transicion();
   			pacientes();
   			getch();
   			menu_principal();
			break;
	   	}
		case '2':{
			transicion();
			menu_servicios();
			getch();
			menu_principal();
			break;
		}
		case '3':{
			transicion();
			menu_adopcion();
			getch();
			menu_principal();
			break;
		}
		case '4':{
			transicion();
			ventaDeArticulos();
			getch();
			menu_principal();
			break;
		}
		case '0':{
			fflush (stdin);
			gotoxy(3,13);cout<<"Gracias por visitar a la Veterinaria Huellitas Unidas";
			getch();
			break;
		}
  	 }
}

void pacientes(){
	ofstream escperro;
	ifstream leerperro;
	char opc2;
	int repetido=0; //ver si algun codigo de perro se repite
	do{
		gotoxy(15,5);cout<<"PACIENTES"<<endl;
		gotoxy(4,7);cout<<"(1) Ingresar nuevo paciente.";
		gotoxy(4,9);cout<<"(2) Ver pacientes.";
		gotoxy(4,11);cout<<"(3) Buscar paciente existente.";
		gotoxy(4,13);cout<<"(4) Modificar paciente.";
		gotoxy(4,15);cout<<"(5) Eliminar paciente.";
		gotoxy(4,17);cout<<"(6) Volver al menú principal.";
		gotoxy(4,19);cout<<"Ingrese opción: ";cin>>opc2;
		transicion();
		if(opc2!='1' and opc2!='2' and opc2!='3' and opc2!='4' and opc2!='5' and opc2!='6'){
			gotoxy(3,13);cout<<"Opción no válida, presiona una tecla para volver a ingresar un valor...";
			getch();
			transicion();
		}
	}while(opc2!='1' and opc2!='2' and opc2!='3' and opc2!='4' and opc2!='5' and opc2!='6');
	switch(opc2){
		//Opción Ingresar Paciente
		case '1':{
			agregarPaciente(escperro);
			break;
		}
		//Opción Ver Paciente
		case '2':{
			transicion();
			verPaciente(leerperro);
			break;
		}
		//Opción Busar Paciente
		case '3':{
			buscarPaciente(leerperro);
			break;
		}
		//Opción Modificar Paciente
		case '4':{
			transicion();
			modificarPaciente(leerperro);
			break;
		}
		//Opción Eliminar paciente
		case '5':{
			eliminarPaciente(leerperro);
			transicion();
			break;
		}
		//Opción Salir al menú
		case '6':{
			transicion();
			menu_principal();
			break;
		}
	}

}

void agregarPaciente(ofstream &esc){
	transicion();
	string codigo, perrito, nombre_dueno, apellido_dueno, raza, fecha;
	esc.open("Perritos.txt", ios::out | ios::app);
	gotoxy(7,5);cout<<"REGISTRE A SU MASCOTA";
	gotoxy(4,7);cout<<"Nombre del perrito: ";
	cin>>perrito;
	gotoxy(4,9);cout<<"Código del perrito: ";
	cin>>codigo;
	gotoxy(4,11);cout<<"Nombre del dueño: ";
	cin>>nombre_dueno;
	gotoxy(4,13);cout<<"Apellido del dueño: ";
	cin>>apellido_dueno;
	gotoxy(4,15);cout<<"Raza del perro: ";
	cin>>raza;
	gotoxy(4,17);cout<<"Fecha de hoy: ";
	cin>>fecha;
	//Verificar que no se repitan los códigos
	if(verificar_cod(codigo)){
		esc<<perrito<<" "<<codigo<<" "<<nombre_dueno<<" "<<apellido_dueno<<" "<<raza<<" "<<fecha<<"\n";
	}
	esc.close();
	transicion();
	menu_principal();
}

bool verificar_cod(string cod){
	ifstream leer("Perritos.txt", ios::in);
	string perrito, nombre_dueno, apellido_dueno, raza, fecha, codigo;
	leer>>perrito;
	while(!leer.eof()){
		leer>>codigo;
		leer>>nombre_dueno;
		leer>>apellido_dueno;
		leer>>raza;
		leer>>fecha;
		if(codigo == cod){
			gotoxy(4,21);cout<<"--------Código ya en uso------"<<endl<<endl;
			getch();
			leer.close();
			return false;
		}
		leer>>perrito;
	}
	leer.close();
	return true;
}

void verPaciente(ifstream &leer){
	system("cls");
	string codigo, perrito, nombre_dueno, apellido_dueno, raza, fecha;
	leer.open("Perritos.txt",ios::in);
	if(leer.is_open()){
	cout<<"----------<<Perritos Registrados>>----------"<<endl<<endl;
	leer>>perrito;
	while(!leer.eof()){
		leer>>codigo;
		leer>>nombre_dueno;
		leer>>apellido_dueno;
		leer>>raza;
		leer>>fecha;
		cout<<"Nombre del Perrito: "<<perrito<<endl;
		cout<<"Código del Perrito: "<<codigo<<endl;
		cout<<"Nombre del Dueño: "<<nombre_dueno<<endl;
		cout<<"Apellido del Dueño: "<<apellido_dueno<<endl;
		cout<<"Raza del Perrito: "<<raza<<endl;
		cout<<"Fecha de inscripción: "<<fecha<<endl;
		cout<<"Cita: "<<"No"<<endl;
		cout<<"----------------------------------"<<endl;
		leer>>perrito;
	}
	leer.close();
}else{
	gotoxy(4,15);cout<<"ERROR al abrir el archivo";
}
	getch();
	transicion2();
	menu_principal();
}

void buscarPaciente(ifstream &lec){
	transicion();
	lec.open("Perritos.txt", ios::in);
	string codigo, perrito, nombre_dueno, apellido_dueno, raza, fecha;
	string codaux;
	bool encontrado=false;
	gotoxy(4,7);cout<<"Digite el código de la mascota: ";
	cin>>codaux;
	transicion();
	lec>>perrito;
	while(!lec.eof() && !encontrado){
		lec>>codigo;
		lec>>nombre_dueno;
		lec>>apellido_dueno;
		lec>>raza;
		lec>>fecha;
		if(codigo == codaux){
			gotoxy(4,7);cout<<"Nombre del Perrito: "<<perrito<<endl;
			gotoxy(4,10);cout<<"Código del Perrito: "<<codigo<<endl;
			gotoxy(4,13);cout<<"Nombre del Dueño: "<<nombre_dueno<<endl;
			gotoxy(4,16);cout<<"Apellido del Dueño: "<<apellido_dueno<<endl;
			gotoxy(4,19);cout<<"Raza del Perrito: "<<raza<<endl;
			gotoxy(4,22);cout<<"Fecha de inscripción: "<<fecha<<endl;
			encontrado=true;
		}
		lec>>perrito;
	}
	lec.close();
	if(!encontrado){
		gotoxy(4,10);cout<<"Dato no encontrado"<<endl;
	}
	getch();
	transicion();
	menu_principal();
}

void modificarPaciente(ifstream &lec){
	string codigo, perrito, nombre_dueno, apellido_dueno, raza, fecha;
	string codaux,perritoaux,nombreaux,apellidoaux,razaaux,fechaaux;
	lec.open("Perritos.txt",ios::in);
	ofstream aux("auxiliar.txt",ios::out);
	if(lec.is_open()){
		gotoxy(8,5);cout<<"MODIFIQUE DATO DEL PACIENTE";
		gotoxy(4,7);cout<<"Digite el código del perrito a modificar: ";
		cin>>codaux;
		lec>>perrito;
		while(!lec.eof()){
			lec>>codigo;
			lec>>nombre_dueno;
			lec>>apellido_dueno;
			lec>>raza;
			lec>>fecha;
			if(codigo==codaux){
				gotoxy(4,9);cout<<"Nuevo nombre del perrito: ";
				cin>>perritoaux;
				gotoxy(4,11);cout<<"Nombre del dueño: ";
				cin>>nombreaux;
				gotoxy(4,13);cout<<"Apellido del dueño: ";
				cin>>apellidoaux;
				gotoxy(4,15);cout<<"Raza del perrito: ";
				cin>>razaaux;
				aux<<perritoaux<<" "<<codaux<<" "<<nombreaux<<" "<<apellidoaux<<" "<<razaaux<<" "<<fecha<<endl;
			}
			else{
				aux<<perrito<<" "<<codigo<<" "<<nombre_dueno<<" "<<apellido_dueno<<" "<<raza<<" "<<fecha<<endl;
			}
			lec>>perrito;
		}
		lec.close();
		aux.close();
	}else{
		gotoxy(5,8);cout<<"ERROR"<<endl;
	}
	remove("Perritos.txt");
	rename("auxiliar.txt", "Perritos.txt");
	getch();
	transicion();
	menu_principal();
}

void eliminarPaciente(ifstream &lec){
	string codigo, perrito, nombre_dueno, apellido_dueno, raza, fecha;
	string codaux,perritoaux,nombreaux,apellidoaux,razaaux,fechaaux;
	lec.open("Perritos.txt",ios::in);
	ofstream aux("auxiliar.txt",ios::out);
	if(lec.is_open()){
		gotoxy(8,5);cout<<"ELIMINE LOS DATOS DEL PACIENTE";
		gotoxy(4,7);cout<<"Digite el código del perrito a modificar: ";
		cin>>codaux;
		lec>>perrito;
		while(!lec.eof()){
			lec>>codigo;
			lec>>nombre_dueno;
			lec>>apellido_dueno;
			lec>>raza;
			lec>>fecha;
			if(codigo==codaux){
				gotoxy(4,9);cout<<"-------- Registro de Paciente eliminado con éxito --------- ";
			}
			else{
				aux<<perrito<<" "<<codigo<<" "<<nombre_dueno<<" "<<apellido_dueno<<" "<<raza<<" "<<fecha<<endl;
			}
			lec>>perrito;
		}
		lec.close();
		aux.close();
	}else{
		gotoxy(5,8);cout<<"ERROR"<<endl;
	}
	remove("Perritos.txt");
	rename("auxiliar.txt", "Perritos.txt");
	getch();
	transicion();
	menu_principal();
}

void menu_adopcion(){
	char opcion;

	system("cls");
	cout<<"\t\t\t\tMENU PRINCIPAL"<<endl;
	cout<<"\t\t\t\t=============="<<endl;
	cout<<"[1]: Ingreso nuevo"<<endl;
	cout<<"[2]: Lista de perros"<<endl;
	cout<<"[3]: Registrar adopcion"<<endl;
	cout<<"[4]: Mostrar registros de adopcion"<<endl;
	cout<<"[5]: Cambio de estado"<<endl;
	cout<<"[0]: Salir"<<endl;
	
	do{
		cout<<"\nIngrese el numero de la opcion: [ ]"<<"\b\b";
		cin>>opcion;
	}while(opcion!='1' && opcion!='2' && opcion!='3' && opcion!='4' && opcion!='5' && opcion!='0');
	
	switch(opcion){
		case '1':
			nuevoingreso(cod,a);
			menu_adopcion();
		break;
		
		case '2':
			lista(cod);
			menu_adopcion();
		
		case '3':
			adoptar(cod,cod2,b);
			menu_adopcion();
		break;
		
		case '4':
			registro(cod2);
			menu_adopcion();
		break;
		
		case '5':
			cambio();
			menu_adopcion();
		break;
		
		case '0':
		break;
	}
	
}


void nuevoingreso(int& cod,int& a){
	char opc;
	
	cout<<"\tNUEVO PERRO";
	dog[a].codigo=cod+1;
	cin.ignore();
	cout<<"\nNombre: ";cin.getline(dog[a].nombre,30,'\n');
	cout<<"Edad: ";cin>>dog[a].edad;
	cin.ignore();
	cout<<"Enfermedad: ";getline(cin,dog[a].enfermedad);				
	cout<<"Tamano: ";cin.getline(dog[a].tamano,8,'\n');
	fflush(stdin);
	cout<<"Raza: ";getline(cin,dog[a].raza);
	cout<<"Fecha de ingreso: ";gets(dog[a].fecha);
	cout<<"Estado: ";cin>>dog[a].estado;
	cod++;a++;
	
	cout<<"Quiere ingresar otro perro? (S/N): ";cin>>opc;
	if(opc=='s' or opc=='S'){
		nuevoingreso(cod,a);
	}
	getche();
}

void lista(int& cod){
	int cod1;
	
	if(cod>=1){
		cod1=cod;
		system("cls");
		cout<<"\tLISTA DE PERROS";
		for(int i=0;i<cod1;i++){
			cout<<"\n["<<dog[i].codigo<<"]";
			cout<<" Nombre: "<<dog[i].nombre;
			cout<<"\tEdad: "<<dog[i].edad;
			cout<<"\t\tEnfermedad: "<<dog[i].enfermedad;
			cout<<"\t\tTamano: "<<dog[i].tamano;
			cout<<"\t\tRaza: "<<dog[i].raza;
			cout<<"\n  Fecha de ingreso: "<<dog[i].fecha;
			cout<<"\tEstado: "<<dog[i].estado;
		}				
	}
	else{
		cout<<"\nNo hay perros registrados";
	}
	getche();
}

void adoptar(int& cod,int& cod2,int& b){
	int aux;
	string adop="adoptado";
	
	if(cod>0){
		system("cls");
		cout<<"\tNUEVO ADOPTANTE";
		cin.ignore();				
		cout<<"\nNombre: ";gets(persona[b].nombre);
		cout<<"DNI: ";gets(persona[b].dni);
		cout<<"Edad: ";cin>>persona[b].edad;
		cout<<"Codigo del perro: ";cin>>persona[b].codigo;
		aux=persona[b].codigo;
		dog[aux-1].estado=adop;				
		cod2++;b++;					
	}
	else{
		cout<<"\nNo hay perros en la guarderia";	
	}
	getche();
}

void registro(int& cod2){
	system("cls");	
	
	if(cod2>0){
		cout<<"\tLISTA DE ADOPTANTES";
		for(int i=0;i<cod2;i++){
			cout<<"\nNombre: "<<persona[i].nombre;
			cout<<"\tDNI: "<<persona[i].dni;
			cout<<"\tEdad: "<<persona[i].edad;
			cout<<"\tCodigo del perro: "<<persona[i].codigo;
		}				
	}
	else{
		cout<<"\nNo hay personas que adoptaron perros";
	}
	getche();
}

void cambio(){
	int opc1,cod3;
	string cambio="", vacio="";
	cout<<"\nQUE RASGO DESEA CAMBIAR?"<<endl;
	cout<<"\n[1] Enfermedad"<<endl;
	cout<<"[2] Estado"<<endl;
	do{
		 cout<<"\ningrese la opcion: ";cin>>opc1;    				 	
	 }
    while(opc1<1||opc1>2);
    if(opc1==1){
    	cout<<"Ingrese el codigo del perro";cin>>cod3;
       	cout<<"Ingrese el cambio de -> Enfermedad: ";cin>>cambio;
       	dog[cod3-1].enfermedad=cambio;
       	cambio=vacio;
	}
	else {
      	cout<<"Ingrese el codigo del perro: ";cin>>cod3;
       	cout<<"Ingrese el cambio de -> Estado: ";cin>>cambio;
       	dog[cod3-1].estado=cambio;
       	cambio=vacio;					
		}
	
	getche();
	
}

//Hacer cuadrados, son para darle estética y forma a nuestro menú
void dibujarCuadrado(int x1,int y1,int x2,int y2){
    int i;
    for (i=x1;i<x2;i++){
		gotoxy(i,y1); cout << "-";
		gotoxy(i,y2); cout << "-";
    }

    for (i=y1;i<y2;i++){
		gotoxy(x1,i); cout << "|";
		gotoxy(x2,i); cout << "|";
    }
    
    gotoxy(x1,y1); cout << "-";
    gotoxy(x1,y2); cout << "-";
    gotoxy(x2,y1); cout << "-";
    gotoxy(x2,y2); cout << "-";
}
//Función estética para señalar posiciones en eje "x" "y" (rescatado de foros), porque antes existía la función gotoxy dentro de la librería windows.h pero ahora debe ser manual
 void gotoxy(int x,int y){  
      HANDLE hcon;  
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
      COORD dwPos;  
      dwPos.X = x;  
      dwPos.Y= y;  
      SetConsoleCursorPosition(hcon,dwPos);  
 } 
 void transicion(){
	int i,j;
	//hacer un barrido de "limpieza" en toda la pantalla que se muestra
	for(i=5;i<=23;i++){ //Como el cuadro está hasta 24... y la transición está hecho a base de espacios en blanco, para que no se borre el cuadrado principal, le damos un 23
		for(j=3;j<=77;j++){ //Como el cuadro está hasta 78... y la transición está hecho a base de espacios en blanco, para que no se borre el cuadrado principal, le damos un 77
			gotoxy(j,i); printf(" ");}}
}

void transicion2(){
	int i,j;
	//hacer un barrido de "limpieza" en toda la pantalla que se muestra
	for(i=0;i<=80;i++){ //Como el cuadro está hasta 80... y la transición está hecho a base de espacios en blanco, para borrar todo lo que aparezca en la pantalla
		for(j=0;j<=300;j++){ //Como el cuadro está hasta 78... y la transición está hecho a base de espacios en blanco, para borrar todo lo que aparezca en la pantalla
			gotoxy(j,i); printf(" ");}}
}

void menu_servicios(){
    char opc;
    int datos[6]={0,0,0,0,0,0};

	system("cls");
    cout<<"\t\tSERVICIOS"<<endl;
    cout<<"[1]:Baños"<<endl;
    cout<<"[2]:Vacunas"<<endl;
    cout<<"[3]:Tratamientos"<<endl;
    cout<<"[4]:Corte de pelo"<<endl;
    cout<<"[5]:Operaciones"<<endl;
    cout<<"[6]:Análisis"<<endl;
   // cout<<"[7]:Boleta"<<endl;
    cout<<"[0]:Salir"<<endl;
    
    do{
        cout<<"\nDigite una opción: ";cin>>opc;
        if(opc!='1' and opc!='2' and opc!='3' and opc!='4' and opc!='5' and opc!='6' and opc!='7' and opc!='0'){
        	cout<<"Error, presione una tecla para volver a intentarlo"<<endl;
        }
	}
    while(opc!='1' and opc!='2' and opc!='3' and opc!='4' and opc!='5' and opc!='6' and opc!='7' and opc!='0');

    switch (opc){

        case '1':
            datos[0]=bano();
            menu_servicios();
            break;
        
        case '2':
            datos[1]=vacunas();
            menu_servicios();
            break;
        
        case '3':
            datos[2]=tratamientos();
            menu_servicios();
            break;
        
        case '4':
            datos[3]=corte();
            menu_servicios();
            break;
        
        case '5':
            datos[4]=operaciones();
            menu_servicios();
            break;

        case '6':
            datos[5]=analisis();
            menu_servicios();
            break;
		
	/*	case '7':
			boleta(datos);
	*/	
        case '0':
            getch();
            break;
    }
    
}
int bano(){
	char tamano;
	int preciobano=0;
		system("cls");
	cout<<"BANO"<<endl;
	cout<<"1. Pequeño					s/20 "<<endl;
	cout<<"2. Mediano					s/30 "<<endl;
	cout<<"3. Grande					s/40 "<<endl;
    cout<<"0. Salir "<<endl;	

    do{
	   	cout<<"Ingrese una opción: ";
		cin>>tamano; 
	if(tamano!='0'&&tamano!='1'&&tamano!='2'&&tamano!='3'){
		cout<<"Opción fuera del rango"<<endl;	
	}
	}while(tamano!='0'&&tamano!='1'&&tamano!='2'&&tamano!='3');		
	
	if(tamano=='1'){
	    preciobano=20;
        cout<<"\nRegistrado con éxito"<<endl;
	}
	if(tamano=='2'){
	    preciobano=30;
        cout<<"\nRegistrado con éxito"<<endl;        
	}
	if(tamano=='3'){
	    preciobano=40;
        cout<<"\nRegistrado con éxito"<<endl; 
	}    
    	system("pause");
	return preciobano;
}

int vacunas(){
	char op,opc2;
    int vac[7]={0,0,0,0,0,0,0}, total_vacuna=0;

    do{
	system("cls");
	cout<<"VACUNAS"<<endl;
	cout<<"1.Distemper          s/80"<<endl;
	cout<<"2.Parvovirus         s/90 "<<endl;
	cout<<"3.Hepatitis          s/70"<<endl;	
	cout<<"4.Coronavirosis      s/70"<<endl;
	cout<<"5.Parainfluencia     s/60"<<endl;		
	cout<<"6.Leptospirosis      s/60"<<endl;
	cout<<"7.Rabia              s/40"<<endl;
    cout<<"0.Salir"<<endl;

	do{
	cout << "\nIngrese una opción: ";
	cin>>op;
    }while(op!='0' && op!='1'&& op!='2'&& op!='3'&&op!='4' &&op!='5'&&op!='6'&&op!='7');
    
    switch (op){
        case '1':{ vac[0]=80 ; break;
        }
        case '2':{ vac[1]=90 ; break;
        }
        case '3':{ vac[2]=70 ; break;
        }
         case '4':{ vac[3]=70; break;
        }
        case '5':{ vac[4]=60; break;
        }
         case '6':{ vac[5]=60; break;
        }
         case '7':{ vac[6]=40; break;
        }
         case '0':{  break;
        }
        system("pause");
    }
    cout<<"\ndesea agregar otra vacuna? (S/N): ";cin>>opc2;
    }while(opc2=='s' || opc2=='S');

    for(int i=0; i<7; i++){
        total_vacuna+=vac[i];
    }
	
	return total_vacuna;
}

int tratamientos(){
	char opc,desparacitacion,opantipulgas;
    int preciodesparacitacion=0,precioantipulgas=0,total=0;
   
	do{ 
    system("CLS");
	cout<<"TRATAMIENTOS"<<endl;
	cout<<"1.Desparacitacion"<<endl;
	cout<<"2.Antipulgas "<<endl;
    cout <<"0.Salir"<<endl;

    do{
    cout << "\nIngrese opcion: ";
    cin>>opc;
        if(opc!='0' && opc!='1' && opc!='2'){
            cout<<" Ingreso mal el valor. Presione una tecla para volver a ingresar.."<<endl;
            getch();
        }
	}while(opc!='0' && opc!='1' && opc!='2'&& opc!='0');
	
    if(opc=='1'){
    
    system("CLS");
    cout<<"DESPARACITACION"<<endl;
	cout<<"1.Inyeccion          s/20"<<endl;
	cout<<"2.Pastilla           s/15"<<endl;	
    cout<<"0.Salir "<<endl;

    do{
    cout << "\nIngrese opcion: ";
    cin>>desparacitacion;
    if(desparacitacion!='0' && desparacitacion!='1' && desparacitacion!='2'){
		cout<<"Opcion fuera del rango "<<endl;
    }
    }while(desparacitacion!='0' && desparacitacion!='1' && desparacitacion!='2');

        if(desparacitacion=='1'){
            preciodesparacitacion=20;
            cout<<"opcion registrada"<<endl;
        }
        if(desparacitacion='2'){
            preciodesparacitacion=15;
            cout<<"opcion registrada"<<endl;
        }
        if(desparacitacion='0'){
           tratamientos();
        }
        system("pause");
	}

	if(opc=='2'){
   
    system("cls");
    cout<<"ANTIPULGAS"<<endl;
	cout<<"1.Pipetas            s/15"<<endl;
	cout<<"2.Pastilla           s/20 "<<endl;		
	cout<<"3.Inyeccion          s/25"<<endl;	
    cout<<"0.Salir "<<endl;

    do{
    cout << "\nIngrese opcion: ";
    cin>>opantipulgas;
    if(opantipulgas!='0' && opantipulgas!='1' && opantipulgas!='2'&& opantipulgas!='3'){
		cout<<"Opcion fuera del rango "<<endl;
		system("pause");}
    }while(opantipulgas!='0' && opantipulgas!='1' && opantipulgas!='2'&& opantipulgas!='3');
       
        if(opantipulgas=='1'){
        	cout<<"opcion registrada"<<endl;
            precioantipulgas=15;
        }
        if(opantipulgas=='2'){
        	cout<<"opcion registrada"<<endl;
            precioantipulgas=20;
        }
        if(opantipulgas=='3'){
        	cout<<"opcion registrada"<<endl;
            precioantipulgas=25;
        }
        if(opantipulgas=='0'){
            tratamientos();
        }
        system("pause");
	}
	if (opc=='0'){
		menu_servicios();
	}
	}while(desparacitacion!='0');
	
	total=preciodesparacitacion+precioantipulgas;
	return total;
} 

int corte(){
	char op;
	int preciocorte=0;
	
		system("cls");
	cout<<"CORTE DE PELO"<<endl;
	cout<<"1.Corte leon				s/40 "<<endl;
	cout<<"2.Corte Ingles				s/45 "<<endl;
	cout<<"3.Corte Holandes			s/40 "<<endl;
	cout<<"4.Corte Moderno				s/45 "<<endl;
	cout<<"5.Corte de cachorro			s/25 "<<endl;
	cout<<"6.Corte de verano			s/35 "<<endl;
	cout <<"0.Salir"<<endl; 

    do{
	cout << "\nIngrese opcion: ";
	cin>>op;
    }while(op!='0' && op!='1'&& op!='2'&& op!='3'&&op!='4' &&op!='5'&&op!='6');
	
    switch(op){
		case '1':{
			preciocorte=40;
			cout<<"Opción registrada"<<endl;
			break;
		}
		case '2':{
			preciocorte=45;
			cout<<"Opción registrada"<<endl;			
			break;
		}
		case '3':{
			preciocorte=40;
			cout<<"Opción registrada"<<endl;			
			break;
		}
		case '4':{
			preciocorte=45;
			cout<<"Opción registrada"<<endl;			
			break;
		}
		case '5':{
			preciocorte=25;
			cout<<"Opción registrada"<<endl;			
			break;
		}
		case '6':{
			preciocorte=35;
			cout<<"opcion registrada"<<endl;			
			break;
		}
		case '0':{
			
			break;
		}
		system("pause");
	} 
	return preciocorte;
}

int operaciones(){
	char opc, confirm;
	int precio;
    system("cls");
	cout<<"\tOperaciones"<<endl;
	cout<<"Tiene chequeo preoperatorio?(s:si  n:no): ";
		cin>>confirm;
		if(confirm=='n'||confirm=='N'){
			analisis();
		}
		
			cout<<"\n1.- Esterilizaciones     S/200"<<endl;
			cout<<"2.- Oftalmologia          S/250"<<endl;
			cout<<"3.- Maxilofacial          S/200"<<endl;
			cout<<"4.- Abdominal             S/300"<<endl;
			cout<<"5.- Oncologica            S/400"<<endl;
			cout<<"6.- Reconstructiva        S/500"<<endl;
			cout<<"7.- Urgencias             S/400"<<endl;
			cout<<"0.- Salir"<<endl;
            do{
			cout<<"\tElija su opcion: ";
			cin>>opc;
            } while(opc!='0' && opc!='1'&& opc!='2'&& opc!='3'&&opc!='4' &&opc!='5'&&opc!='6'&&opc!='7');
			switch(opc){
				case '1': cout<<"\nEsterilizaciones"<<endl;
				  	precio=200;
				//	cita();
				break;
				case '2':cout<<"\nOftalomologica"<<endl;
					precio=250;
				//	cita();
				break;
				case '3': cout<<"\nMaxilofacial"<<endl;
					precio=200;
				//	cita();
				break;
				case '4':cout<<"\nAbdominal"<<endl;
					precio=300;
				//	cita();
				break;
				case '5': cout<<"\nOncologica"<<endl;
					precio=400;
				//cita();
				break;
				case '6':cout<<"\nReconstructiva"<<endl;
					precio=500;
				//	cita();
				break;
				case '7':cout<<"\nUrgencias"<<endl;
					precio=400;
					//cita();
				break;
				case '0': break;
			}
	return precio;
}

int analisis(){
	char m,p,p2,m2;
    int analisis[5]={0,0,0,0,0},totalanalisis=0,descarte[3]={0,0,0},sumadescart=0,general[3]={0,0,0},sumageneral=0;
	do{
    system("cls");
	cout<<"\tAnalisis"<<endl;
	cout<<"1.- Chequeo preoperatorio       S/300"<<endl;
	cout<<"2.- Descarte de enfermedades"<<endl;
	cout<<"3.- Radiografias                S/400"<<endl;
	cout<<"4.- Tomografias                 S/400"<<endl;
	cout<<"5.- General."<<endl;
	cout<<"0.- Volver"<<endl;
	
	do{
	cout<<"\tElija su opcion: ";
	cin>>m;
    }while(m!='0' && m!='1'&& m!='2'&& m!='3'&&m!='4' &&m!='5');

		switch (m){
			case '1': 
			cout<<"\tChequeo preoperatorio"<<endl;
				analisis[0]=300;
			//cita();
			break;
			
			case '2':
			system("cls");
			do{
			cout<<"\tDescarte de enfermedades"<<endl;
			cout<<"1.- Distemper y Parvovirus   S/100"<<endl;
			cout<<"2.- Leptospirosis            S/80"<<endl;
			cout<<"3.- Micoplasmosis            S/80"<<endl;
			cout<<"0.- Volver"<<endl;
            do{
               cout<<"\tElija su opcion: ";
			cin>>p; 
            }while(p!='0' && p!='1'&& p!='2'&& p!='3');
			
			switch(p){
				case '1': cout<<"\nDistemper y Parvovirus"<<endl;
					descarte[0]=100;
			//	cita();
				break;
				case '2': cout<<"\nLeptospirosis"<<endl;
					descarte[1]=80;
			//	cita();
				break;
				case '3': cout<<"\nMicoplasmosis"<<endl;
					descarte[2]=80;
			//	cita();
				break;
				case '0':  
				break;
			}
			cout<<"\ndesea agregar otro descarte? (S/N): ";cin>>p2;
			}while(p2=='s'|| p2=='S');
			for(int i=0; i<3;i++){
				sumadescart+=descarte[i];
			}
			analisis[1]=sumadescart;
			break;

			case '3': {
                cout<<"\tRadiografia"<<endl;
			    	analisis[2]=400;
			//	cita();
			break;  
            }

			case '4':{
                cout<<"\tTomografia"<<endl;
			    	analisis[3]=400;
			//	cita();
            break;
            }

			case '5': {
				system("cls");
                cout<<"\tAnalisis General"<<endl;
                cout<<"1.- De sangre    S/100"<<endl;
                cout<<"2.- Fisico       S/120"<<endl;
                cout<<"3.- Ambos        S/210"<<endl;
                cout<<"0.- Volver"<<endl;
                do{
                cout<<"\tElija su opcion: ";
                    cin>>p; 
                }while(p!='0' && p!='1'&& p!='2'&& p!='3');

                switch(p){
                    case '1': cout<<"\nAnalisis de sangre"<<endl;
                    	analisis[4]=100;
                //	cita();
                    break;
                    case '2': cout<<"\nAnalisis fisico"<<endl;
                    	analisis[4]=120;
                //	cita();
                    break;
                    case '3': cout<<"\nAnalisis de sangre y fisico"<<endl;
                    	analisis[4]=210;
                 //   cita();
                    break;
                    case '0': m2='N'; 
					break;
                }
			break;  
            }
			
			case '0':{
                menu_servicios();
            break;
            }
		}
	if(m2!='N'){
		cout<<"\ndesea agregar otro analisis? (S/N): ";cin>>m2;			
	}
	}while(m2=='s'|| m2=='S');
	
	for(int i=0; i<5; i++){
		totalanalisis+=analisis[i];
	}
	return totalanalisis;
}

void ventaDeArticulos(){
	ofstream escribirBaseProductos;
	ifstream leerBaseProductos;
	char opc;
	system("CLS");
	cout<<"\tVENTA DE ARTÍCULOS"<<endl;
	cout<<"(1) Productos en sistema."<<endl;
	cout<<"(2) Generar compra."<<endl;
	cout<<"(3) Ingrese un nuevo producto al sistema."<<endl;
	cout<<"(4) Salir"<<endl;
	cout<<"Ingrese una opción: ";cin>>opc;
	switch(opc){
		case '1':buscarProductosEnSistema(leerBaseProductos);break;
		case '2':generarCompra(leerBaseProductos);;break;
		case '3':agregarProducto(escribirBaseProductos,leerBaseProductos);break;
	}
	escribirBaseProductos.close();
}

void buscarProductosEnSistema(ifstream &leerBaseProductos){
	string nombreProductoAux;
	bool repetir=false;
	int cantidadProductoAux=0;
	float precioProductoAux=0;
	system("CLS");
	leerBaseProductos.open("productos.txt",ios::in);
	if(leerBaseProductos.is_open()){
		cout<<"\tPRODUCTOS EN SISTEMA"<<endl;
		fflush(stdin);
		cout<<"Escriba el nombre del producto: ";getline(cin,nombreProductoAux);
		fflush(stdin);
		if(verificarProducto(nombreProductoAux,leerBaseProductos,precioProductoAux,cantidadProductoAux)==false){
			cout<<"Nombre del producto ---------------- "<<nombreProductoAux<<endl;
			cout<<"Precio del producto ---------------- S/."<<precioProductoAux<<endl;
			cout<<"Cantidad del producto -------------- "<<cantidadProductoAux<<endl;
		}
		else{
			cout<<"Producto no encontrado."<<endl;
		}
		leerBaseProductos.close();
	}
	else{
		cout<<"No se ha añadido ningún producto al sistema."<<endl;
	}
	system("pause");
	system("CLS");
}

bool verificarProducto(string nombreProductoBuscado,ifstream &leerBaseProductos,float &precioProductoBuscado,int &cantidadProductoBuscado){
	leerBaseProductos.open("productos.txt",ios::in);
	float precioProducto;
	string nombreProducto;
	int cantidadProducto;
	leerBaseProductos>>precioProducto;
	while(!leerBaseProductos.eof()){
		leerBaseProductos>>cantidadProducto;
		leerBaseProductos>>nombreProducto;
		if(nombreProducto==nombreProductoBuscado){
			leerBaseProductos.close();
			precioProductoBuscado=precioProducto;
			cantidadProductoBuscado=cantidadProducto;
			return false;
		}
		leerBaseProductos>>precioProducto;
	}
	leerBaseProductos.close();
	return true;
}

void agregarProducto(ofstream &escribirBaseProductos,ifstream &leerBaseProductos){
	float precioProducto=0;
	string nombreProducto;
	int cantidadProducto=0,cantidadProductoAdicional;
	escribirBaseProductos.open("productos.txt",ios::app|ios::out);
	system("CLS");
	cout<<"\tINGRESAR UN NUEVO PRODUCTO AL SISTEMA"<<endl;	
	fflush(stdin);
	cout<<"Ingresar el nombre del producto: ";getline(cin,nombreProducto);
	fflush(stdin);
	cout<<"Ingresar la cantidad de productos: ";cin>>cantidadProductoAdicional;
	fflush(stdin);
	if(verificarProducto(nombreProducto,leerBaseProductos,precioProducto,cantidadProducto)){
		cout<<"Ingresar el precio del producto (S/.): ";cin>>precioProducto;
		fflush(stdin);
		escribirBaseProductos<<precioProducto<<" "<<cantidadProductoAdicional<<" "<<nombreProducto<<endl;	
		escribirBaseProductos.close();
	}
	else{
		cout<<"El precio establecido es: "<<precioProducto<<endl;
		cantidadProducto+=cantidadProductoAdicional;
		modificarCantidadProducto(leerBaseProductos,nombreProducto,cantidadProducto);
		cout<<"La nueva cantidad es: "<<cantidadProducto<<endl;
	}
	system("pause");
	system("CLS");
}

void modificarCantidadProducto(ifstream &leerBaseProductos,string nombreProductoBuscado,int nuevaCantidadProducto){
	leerBaseProductos.open("productos.txt",ios::in);
	ofstream aux("auxiliar.txt",ios::out);
	float precioProducto;
	string nombreProducto;
	int cantidadProducto;
	leerBaseProductos>>precioProducto;
	while(!leerBaseProductos.eof()){
		leerBaseProductos>>cantidadProducto;
		leerBaseProductos>>nombreProducto;
		if(nombreProducto==nombreProductoBuscado){
			aux<<precioProducto<<" "<<nuevaCantidadProducto<<" "<<nombreProducto<<"\n";
		}
		else{
			aux<<precioProducto<<" "<<cantidadProducto<<" "<<nombreProducto<<"\n";
		}
		leerBaseProductos>>precioProducto;
	}
	leerBaseProductos.close();
	aux.close();
	remove("productos.txt");
	rename("auxiliar.txt","productos.txt");
}

void generarCompra(ifstream &leerBaseProductos){
	ofstream escribirCompras;
	string nombreProductoComprar,nombreCliente;
	float precioProductoComprar=0,gastoPorProducto=0,totalPagar=0;
	bool ingresarOtro;
	int cantidadProducto=0,cantidadProductoComprar,i=1;
	escribirCompras.open("compras.txt",ios::app);
	system("CLS");
	if(leerBaseProductos.is_open()){
		cout<<"\tGENERAR COMPRA"<<endl;
		fflush(stdin);
		cout<<"Digite el nombre del cliente: ";getline(cin,nombreCliente);
		escribirCompras<<nombreCliente<<"\n";
		do{
			do{
				fflush(stdin);
				cout<<"\nDigite el nombre del producto: ";getline(cin,nombreProductoComprar);
				if(verificarProducto(nombreProductoComprar,leerBaseProductos,precioProductoComprar,cantidadProducto)){
					cout<<"ERROR. Producto no encontrado."<<endl;
				}
			}
			while(verificarProducto(nombreProductoComprar,leerBaseProductos,precioProductoComprar,cantidadProducto));
			do{
				cout<<"Digite la cantidad de productos a comprar: ";cin>>cantidadProductoComprar;
				if(cantidadProductoComprar>cantidadProducto){
					cout<<"ERROR. La cantidad ingresada es mayor a la cantidad disponible."<<endl;
				}
			}
			while(cantidadProductoComprar>cantidadProducto);
			gastoPorProducto=precioProductoComprar*cantidadProductoComprar;
			totalPagar+=gastoPorProducto;
			cantidadProducto-=cantidadProductoComprar;
			modificarCantidadProducto(leerBaseProductos,nombreProductoComprar,cantidadProducto);
			escribirCompras<<nombreProductoComprar<<" "<<precioProductoComprar<<" "<<cantidadProductoComprar<<" "<<gastoPorProducto<<"\n";
			cout<<"\n\t*** PRODUCTO "<<i<<" ***"<<endl;
			cout<<"Nombre del producto: "<<nombreProductoComprar<<endl;
			cout<<"Precio por por unidad: S/."<<precioProductoComprar<<endl;
			cout<<"Cantidad a comprar: "<<cantidadProductoComprar<<endl;
			cout<<"Gasto total por producto: S/."<<gastoPorProducto<<endl;
			cout<<"Ingresar otro producto (Sí:1 || No:0): ";cin>>ingresarOtro;
			i++;
		}
		while(ingresarOtro);
		cout<<"\n\t*** TOTAL A PAGAR: S/."<<totalPagar<<" ***"<<endl;	
		leerBaseProductos.close();
	}
	else{
		cout<<"No se ha añadido ningún producto al sistema."<<endl;
	}
	system("pause");
	system("CLS");
}

/*CITA+BOLETA--> POR ARREGLAR
	void cita(){
	system("cls");
	char nombre[30], dni[10], fecha[10], hora[6];
	cout<<"\tProgramacion de cita"<<endl;
	cout<<"parte de ruben"<<endl;
	cout<<"\nIngrese la fecha: ";
	cin.getline(fecha,10,'\n');
	cin.ignore();
	cout<<"\nIngrese la hora: ";
	cin.getline(hora,6,'\n');
	cin.ignore();
}

void boleta(int vec[]){
	int total;
	
	system("cls");
	cout<<"\t\tBOLETA DE PAGO"<<endl;
	if(vec[0]>0){
		cout<<"\n\nBanos -----------------"<<vec[0]<<endl;
	}
	if(vec[1]>0){
		cout<<"\nVacunas ----------------"<<vec[1]<<endl;
	}
	if(vec[2]>0){
		cout<<"\nTratamientos -----------"<<vec[2]<<endl;
	}
	if(vec[3]>0){
		cout<<"\nCOrte de Pelo ----------"<<vec[3]<<endl;
	}
	if(vec[4]>0){
		cout<<"\nOperaciones ------------"<<vec[4]<<endl;
	}
	if(vec[5]>0){
		cout<<"\nAnalisis ---------------"<<vec[5]<<endl;
	}	
	
	for(int i=0;i<6;i++){
		total+=vec[i];
	}
	
	cout<<"\n\nTotal a pagar: "<<total;
}
FIN PARTE POR ARREGLAR*/


