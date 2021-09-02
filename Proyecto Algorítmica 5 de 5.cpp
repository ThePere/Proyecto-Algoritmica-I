#include <iostream>
#include <conio.h>
#include <windows.h>
#include <string.h>
#include <stdlib.h>
#include <fstream>

using namespace std;

void menuPrincipal(ofstream &,ifstream &);
void servicios();
void adopciones();
void ventaArticulos();
void transicion(int,int,int,int);

void menuPacientes(ofstream &,ifstream &);
void agregarPaciente(ofstream &,ifstream &);
bool verificarCodigo(string,ifstream &);
void verPaciente(ifstream &);
void buscarPaciente(ifstream &);
void modificarPaciente(ofstream &,ifstream &);
void eliminarPaciente(ofstream &,ifstream &);

void menuAdopcion(ofstream &,ifstream &);
bool verifica(int, ifstream &);
bool ExistenciaCodigo(string, ifstream &);
bool verificarEspacioDisponiblePerros(ifstream &);
void ingresarPerroAdopcion(ofstream &,ifstream &);
void mostrarListaAdopcion(ifstream &);
void adoptarPerro(ofstream &,ifstream &);
void eliminar(ofstream &,ifstream &,string);
void mostrarRegistrosAdopcion(ifstream &);
void cambiarEstadoAdopcion(ofstream &,ifstream &);

void menuServicios(ofstream &,ifstream &);
void bano(float &);
void vacunas(float &);
void desparacitacion(float &);
void antipulgas(float &);
void tratamientos(float &);
void corte(float &);
void operaciones(float &);
void descarteEnfermedades(float &);
void analisisGeneral(float &);
void analisis(float &);
void generarBoleta(float []);
void menuCitas(ofstream &,ifstream &);
void agregarCita(ofstream &,ifstream &);
void verCita(ifstream &);
void buscarCita(ifstream &);
void modificarCita(ofstream &,ifstream &);
void eliminarCita(ofstream &,ifstream &);

void menuVentaDeArticulos(ofstream &,ifstream &);
bool verificarProducto(ifstream &,string);
void modificarCantidadProducto(ofstream &,ifstream &,string,int);
void agregarProducto(ofstream &,ifstream &);
void buscarProducto(ifstream &);
void verProductos(ifstream &);
bool verificarCantidadDisponible(ifstream &,string,int);
float obtenerPrecio(ifstream &,string);
void generarCompra(ofstream &,ifstream &);

void errorOpcionIngresada();
void confirmacion();
void archivoNoAbierto();
void gotoxy(int x, int y); //Sirve para manipular la ubicaci?n de los caracteres
void dibujarCuadrado(int,int,int,int);
void menuPacientes(ofstream &,ifstream &);

float precioServicios[6]={0,0,0,0,0,0};

int main(){
	ofstream escritura;
	ifstream lectura;
	system("mode con: cols=80 lines=31");
	SetConsoleCP(1252); // Cambiar cin -  Para maquinas Windows
	SetConsoleOutputCP(1252); // Cambiar cout - Para maquinas Windows
	system("Color 30");//Darle color al programa
	dibujarCuadrado(1,1,78,29);//Cuadro del fondo
	dibujarCuadrado(2,2,77,4);//Cuadro del titulo
	gotoxy(18,3);cout<<"VETERINARIA PARA PERROS - HUELLITAS UNIDAS"<<endl;
	menuPrincipal(escritura,lectura);
    return 0;
}
//======================================================================
void menuPrincipal(ofstream &escritura,ifstream &lectura){
	char opc;
	do{
		do{
			transicion(5,28,3,77);
			gotoxy(15,5);cout<<"MENÚ PRINCIPAL"<<endl;
		    gotoxy(4,7);cout<<"[1] Pacientes";
		    gotoxy(4,9);cout<<"[2] Servicios";
			gotoxy(4,11);cout<<"[3] Adopciones";
	    	gotoxy(4,13);cout<<"[4] Venta de artículos";
	    	gotoxy(4,15);cout<<"[0] Salir";
	   		gotoxy(4,19);cout<<"Digite una opción: ";cin>>opc;
	    	transicion(5,28,3,77);
        	if(opc!='1' && opc!='2' && opc!='3' && opc!='4' && opc!='0'){
        		errorOpcionIngresada();
			}
		}
		while(opc!='1' && opc!='2' && opc!='3' && opc!='4' && opc!='0');
  	 	switch(opc){
   			case '1':{
   				menuPacientes(escritura,lectura);
				break;
			   }
			case '2':{
				menuServicios(escritura,lectura);
				break;
			}
			case '3':{
				menuAdopcion(escritura,lectura);
				break;
			}
			case '4':{
				menuVentaDeArticulos(escritura,lectura);
				break;
			}
			case '0':{
				transicion(5,28,3,77);
				gotoxy(3,11);cout<<"¡Gracias por visitar a la Veterinaria Huellitas Unidas! :'D";
				gotoxy(3,13);cout<<"Presione una tecla para finalizar.";
				getch();
		   	}
  	 	}
	}
	while(opc!='0');
}
//======================================================================
void menuPacientes(ofstream &escritura,ifstream &lectura){
	char opc;
	do{
		do{
			transicion(5,28,3,77);
			gotoxy(15,5);cout<<"PACIENTES"<<endl;
			gotoxy(4,7);cout<<"[1] Ingresar nuevo paciente.";
			gotoxy(4,9);cout<<"[2] Ver pacientes.";
			gotoxy(4,11);cout<<"[3] Buscar paciente existente.";
			gotoxy(4,13);cout<<"[4] Modificar paciente.";
			gotoxy(4,15);cout<<"[5] Eliminar paciente.";
			gotoxy(4,17);cout<<"[0] Volver al menú principal.";
			gotoxy(4,19);cout<<"Ingrese una opción: ";cin>>opc;
			if(opc!='1' && opc!='2' && opc!='3' && opc!='4' && opc!='5' && opc!='0'){
				errorOpcionIngresada();
			}
		}
		while(opc!='1' && opc!='2' && opc!='3' && opc!='4' && opc!='5' && opc!='0');
		switch(opc){
			case '1':	agregarPaciente(escritura,lectura);break;
			case '2':	verPaciente(lectura);break;
			case '3':	buscarPaciente(lectura);break;
			case '4':	modificarPaciente(escritura,lectura);break;
			case '5':	eliminarPaciente(escritura,lectura);
		}
	}
	while(opc!='0');
}

void agregarPaciente(ofstream &escritura,ifstream &lectura){
	string codigo;
	escritura.open("Perritos.txt",ios::out|ios::app);
	transicion(5,28,3,77);
	gotoxy(7,5);cout<<"REGISTRE A SU MASCOTA";
	fflush(stdin);
	gotoxy(4,7);cout<<"Código de la mascota: ";getline(cin,codigo);
	if(verificarCodigo(codigo,lectura)){
		gotoxy(7,9);cout<<"--------Código ya en uso--------";
		getch();
	}
	else{
		string perrito,nombreDueno,raza,fecha;
		fflush(stdin);
		gotoxy(4,9);cout<<"Nombre del perrito: ";getline(cin,perrito);
		fflush(stdin);
		gotoxy(4,11);cout<<"Nombre del dueño: ";getline(cin,nombreDueno);
		fflush(stdin);
		gotoxy(4,13);cout<<"Raza del perro: ";getline(cin,raza);
		fflush(stdin);
		gotoxy(4,15);cout<<"Fecha de hoy: ";getline(cin,fecha);
		escritura<<codigo<<endl;
		escritura<<perrito<<endl;
		escritura<<nombreDueno<<endl;
		escritura<<raza<<endl;
		escritura<<fecha<<endl;
		confirmacion();
	}
	escritura.close();
}

bool verificarCodigo(string codigoBuscado,ifstream &lectura){
	lectura.open("Perritos.txt",ios::in);
	string perrito,nombreDueno,raza,fecha,codigo;
	bool encontrado=false;
	getline(lectura,codigo);
	while(!lectura.eof()&&encontrado==false){
		getline(lectura,perrito);
		getline(lectura,nombreDueno);
		getline(lectura,raza);
		getline(lectura,fecha);
		if(codigo==codigoBuscado){
			encontrado=true;
		}
		getline(lectura,codigo);
	}
	lectura.close();
	return encontrado;
}

void verPaciente(ifstream &lectura){
	lectura.open("Perritos.txt",ios::in);
	if(lectura.is_open()){
		string codigo,perrito,nombreDueno,raza,fecha;
		getline(lectura,codigo);
		while(!lectura.eof()){
			getline(lectura,perrito);
			getline(lectura,nombreDueno);
			getline(lectura,raza);
			getline(lectura,fecha);
			transicion(5,28,3,77);
			gotoxy(7,5);cout<<"PERRITOS REGISTRADOS";
			gotoxy(4,7);cout<<"Código del perrito: "<<codigo;
			gotoxy(4,9);cout<<"Nombre del perrito: "<<perrito;
			gotoxy(4,11);cout<<"Nombre del dueño: "<<nombreDueno;
			gotoxy(4,13);cout<<"Raza del perrito: "<<raza;
			gotoxy(4,15);cout<<"Fecha de inscripción: "<<fecha;
			gotoxy(4,17);cout<<"Presione una tecla para continuar...";
			getch();
			getline(lectura,codigo);
		}
		lectura.close();
	}
	else{
		archivoNoAbierto();
	}
}

void buscarPaciente(ifstream &lectura){
	lectura.open("Perritos.txt",ios::in);
	if(lectura.is_open()){
		string codigo,perrito,nombreDueno,raza,fecha,codigoBuscado;
		bool encontrado=false;
		transicion(5,28,3,77);
		gotoxy(7,5);cout<<"BUSCAR PERRITO";
		gotoxy(4,7);cout<<"Ingrese el código del perrito: ";cin>>codigoBuscado;
		getline(lectura,codigo);
		while(encontrado==false&&!lectura.eof()){
			getline(lectura,perrito);
			getline(lectura,nombreDueno);
			getline(lectura,raza);
			getline(lectura,fecha);
			if(codigo==codigoBuscado){
				transicion(5,28,3,77);
				gotoxy(7,5);cout<<"PERRITO ENCONTRADO";
				gotoxy(4,7);cout<<"Código del perrito: "<<codigo;
				gotoxy(4,9);cout<<"Nombre del perrito: "<<perrito;
				gotoxy(4,11);cout<<"Nombre del dueño: "<<nombreDueno;
				gotoxy(4,13);cout<<"Raza del perrito: "<<raza;
				gotoxy(4,15);cout<<"Fecha de inscripción: "<<fecha;
				encontrado=true;
			}
			getline(lectura,codigo);
		}
		if(encontrado==false){
			gotoxy(4,9);cout<<"Perrito no encontrado.";
		}
		lectura.close();
		getch();
	}
	else{
		archivoNoAbierto();
	}
}

void modificarPaciente(ofstream &escritura,ifstream &lectura){
	lectura.open("Perritos.txt",ios::in);
	if(lectura.is_open()){
		string codigo,perrito,nombreDueno,raza,fecha;
		string codAux,perritoAux,nombreAux,razaAux;
		bool encontrado=false;
		escritura.open("Auxiliar.txt",ios::out);
		transicion(5,28,3,77);
		gotoxy(8,5);cout<<"MODIFICAR DATOS DEL PACIENTE";
		fflush(stdin);
		gotoxy(4,7);cout<<"Digite el código del perrito a modificar: ";getline(cin,codAux);
		getline(lectura,codigo);
		while(!lectura.eof()){
			getline(lectura,perrito);
			getline(lectura,nombreDueno);
			getline(lectura,raza);
			getline(lectura,fecha);
			if(codigo==codAux){
				encontrado=true;
				gotoxy(4,9);cout<<"Nombre del perrito: ";getline(cin,perritoAux);
				gotoxy(4,11);cout<<"Nombre del dueño: ";getline(cin,nombreAux);
				gotoxy(4,13);cout<<"Raza del perrito: ";getline(cin,razaAux);
				escritura<<codAux<<endl;
				escritura<<perritoAux<<endl;
				escritura<<nombreAux<<endl;
				escritura<<razaAux<<endl;
				gotoxy(4,15);cout<<"Datos modificados con éxito, presione una tecla para regresar al menú.";
			}
			else{
				escritura<<codigo<<endl;
				escritura<<perrito<<endl;
				escritura<<nombreDueno<<endl;
				escritura<<raza<<endl;
			}
			escritura<<fecha<<endl;
			getline(lectura,codigo);
		}
		lectura.close();
		escritura.close();
		remove("Perritos.txt");
		rename("Auxiliar.txt","Perritos.txt");
		if(encontrado==false){
			gotoxy(4,9);cout<<"Perrito no encontrado.";
		}
		getch();
	}
	else{
		archivoNoAbierto();
	}
}

void eliminarPaciente(ofstream &escritura,ifstream &lectura){
	lectura.open("Perritos.txt",ios::in);
	if(lectura.is_open()){
		string codigo,perrito,nombreDueno,raza,fecha;
		string codAux;
		bool encontrado=false;
		escritura.open("Auxiliar.txt",ios::out);
		transicion(5,28,3,77);
		gotoxy(8,5);cout<<"ELIMINE LOS DATOS DEL PACIENTE";
		gotoxy(4,7);cout<<"Digite el código del perrito a eliminar: ";cin>>codAux;
		getline(lectura,codigo);
		while(!lectura.eof()){
			getline(lectura,perrito);
			getline(lectura,nombreDueno);
			getline(lectura,raza);
			getline(lectura,fecha);
			if(codigo==codAux){
				gotoxy(4,9);cout<<"Registro de paciente eliminado con éxito.";
				encontrado=true;
				getch();
			}
			else{
				escritura<<codigo<<endl;
				escritura<<perrito<<endl;
				escritura<<nombreDueno<<endl;
				escritura<<raza<<endl;
				escritura<<fecha<<endl;
			}
			getline(lectura,codigo);
		}
		lectura.close();
		escritura.close();
		remove("Perritos.txt");
		rename("Auxiliar.txt","Perritos.txt");
		if(encontrado==false){
			gotoxy(4,9);cout<<"Perrito no encontrado."<<endl;
		}
		getch();
	}
	else{
		archivoNoAbierto();
	}
}
//===================================================================================
void menuAdopcion(ofstream &escritura,ifstream &lectura){
	char opcion;
	transicion(5,28,3,77);
	gotoxy(4,5);cout<<"MENU ADOPCION";
	gotoxy(4,7);cout<<"[1] Ingresar nuevo perro.";
	gotoxy(4,9);cout<<"[2] Mostrar lista de perros.";
	gotoxy(4,11);cout<<"[3] Registrar adopcion."<<endl;
	gotoxy(4,13);cout<<"[4] Mostrar registros de adopcion.";
	gotoxy(4,15);cout<<"[5] Cambiar estado.";
	gotoxy(4,17);cout<<"[0] Salir.";
	do{
		gotoxy(4,21);cout<<"Ingrese el numero de la opcion: ";
		cin>>opcion;
	}while(opcion!='1' && opcion!='2' && opcion!='3' && opcion!='4' && opcion!='5' && opcion!='0');
	
	switch(opcion){
		case '1':{
			ingresarPerroAdopcion(escritura,lectura);
			menuAdopcion(escritura,lectura);
			break;
		}
		case '2':{
			mostrarListaAdopcion(lectura);
			menuAdopcion(escritura,lectura);
			break;
		}
		case '3':{
			transicion(5,28,3,77);
			adoptarPerro(escritura,lectura);
			menuAdopcion(escritura,lectura);
			break;
		}
		case '4':{
			transicion(5,28,3,77);
			mostrarRegistrosAdopcion(lectura);
			menuAdopcion(escritura,lectura);
			break;
		}
		case '5':{
			transicion(5,28,3,77);
			cambiarEstadoAdopcion(escritura,lectura);
			menuAdopcion(escritura,lectura);
			break;
		}
		case '0':{
			break;
		}
	}
}

bool verifica(int x, ifstream &lectura){
	lectura.open("guarderia.txt",ios::in);
	int cod;
	string nom;
	string edad;
	string tam;
	string raza;
	string ingreso;
	string estado;

	lectura>>cod;
	while(!lectura.eof()){
		if(cod>=x){
			lectura.close();
			return true;
		}
		lectura>>nom;
		lectura>>edad;
		lectura>>tam;
		lectura>>raza;
		lectura>>ingreso;
		lectura>>estado;
		lectura>>cod;
	}
	lectura.close();
	return false;
}

bool ExistenciaCodigo(string codigoBuscado,ifstream &lectura){
	lectura.open("guarderia.txt",ios::in);
	string cod;
	string nom;
	string edad;
	string tam;
	string raza;
	string ingreso;
	string estado;

	getline(lectura,cod);
	while(!lectura.eof()){
		getline(lectura,nom);
		if(cod==codigoBuscado){
			lectura.close();
			return false;
		}
		getline(lectura,edad);
		getline(lectura,tam);
		getline(lectura,raza);
		getline(lectura,ingreso);
		getline(lectura,estado);
		getline(lectura,cod);
	}
	lectura.close();
	return true;
}

bool verificarEspacioDisponiblePerros(ifstream &lectura){
	int n=0;
	lectura.open("guarderia.txt",ios::in);
	if(lectura.is_open()){	
		int cod;
		string nom;
		string edad;
		string tam;
		string raza;
		string ingreso;
		string estado;
	
		lectura>>cod;
		while(!lectura.eof()){
			lectura>>nom;
			n++;
			lectura>>edad;
			lectura>>tam;
			lectura>>raza;
			lectura>>ingreso;
			lectura>>estado;
			lectura>>cod;
		}
		lectura.close();
		if(n<6){
			return true;
		}else{
			return false;
		}
	}else{
		return true;
	}
}

void ingresarPerroAdopcion(ofstream &escritura,ifstream &lectura){
	int cod=1;
	char opc;
	string nom, edad, tam, raza, ingreso, estado;

	do{
		if(verificarEspacioDisponiblePerros(lectura)){
		transicion(5,28,3,77);
		gotoxy(30,5);cout<<"NUEVO PERRO";
		escritura.open("guarderia.txt",ios::app);
			
		if(escritura.fail()){
			archivoNoAbierto();
			menuAdopcion(escritura,lectura);
		}
			
		while(verifica(cod,lectura)){
			cod++;
		}
			
		fflush(stdin);
		gotoxy(4,7);cout<<"Nombre del Perro: ";getline(cin,nom);
		gotoxy(4,9);cout<<"Edad del Perro: ";getline(cin,edad);			
		gotoxy(4,11);cout<<"Tamano: ";getline(cin,tam);
		gotoxy(4,13);cout<<"Raza: ";getline(cin,raza);
		gotoxy(4,15);cout<<"Fecha de ingreso: ";getline(cin,ingreso);
		gotoxy(4,17);cout<<"Estado: ";getline(cin,estado);
			
		escritura<<cod<<endl; 
		escritura<<nom<<endl;
		escritura<<edad<<endl;
		escritura<<tam<<endl;
		escritura<<raza<<endl;
		escritura<<ingreso<<endl;
		escritura<<estado<<endl;
			
		escritura.close();
			
		gotoxy(4,19);cout<<"Quiere ingresar otro perro? (S/N): ";cin>>opc;	
		}
		else{
		gotoxy(4,22);cout<<"La guarderia ya no cuenta con mas espacio :( ";
		opc='n';
		}	
	}while (opc=='s' or opc=='S');
}

void mostrarListaAdopcion(ifstream &lectura){
	int n=9;
	transicion(5,28,3,77);
	lectura.open("guarderia.txt",ios::in);
	if(lectura.is_open()){
		gotoxy(15,5);cout<<"LISTA DE PERROS";
		gotoxy(4,7);cout<<"Codigo  Nombre  Edad  Tamano  Raza\t      Fecha       Estado";	
		int cod;
		string nom;
		string edad;
		string tam;
		string raza;
		string ingreso;
		string estado;
	
		lectura>>cod;
		while(!lectura.eof()){
			lectura>>nom;
			lectura>>edad;
			lectura>>tam;
			lectura>>raza;
			lectura>>ingreso;
			lectura>>estado;
			gotoxy(4,n);cout<<"["<<cod<<"]";
			gotoxy(12,n);cout<<nom;
			gotoxy(20,n);cout<<edad;
			gotoxy(26,n);cout<<tam;
			gotoxy(34,n);cout<<raza;
			gotoxy(46,n);cout<<ingreso;
			gotoxy(58,n);cout<<estado<<endl;
			n++;
			lectura>>cod;
		}
		lectura.close();
		getche();	
	}
	else{
		archivoNoAbierto();
	}
}

void adoptarPerro(ofstream &escritura,ifstream &lectura){
	string cod2, nombre,apellido,dni,direc,fecha;
	transicion(5,28,3,77);
	gotoxy(15,5);cout<<"GENERAR ADOPCION";
	ofstream escribir;
	escribir.open("adopcion.txt",ios::app);
	
	if(escribir.fail()){
		gotoxy(4,7);cout<<"No se pudo abrir el archivo, intentelo de nuevo";
		menuAdopcion(escritura,lectura);
	}
	
	fflush(stdin);
	gotoxy(4,7);cout<<"Nombre del Adoptante: ";getline(cin,nombre);
	gotoxy(4,9);cout<<"apellido: ";getline(cin,apellido);			
	gotoxy(4,11);cout<<"DNI: ";getline(cin,dni);
	gotoxy(4,13);cout<<"Direccion: ";getline(cin,direc);
	do{
		gotoxy(4,15);cout<<"Codigo del perro: ";getline(cin,cod2);
		if(ExistenciaCodigo(cod2,lectura)){
			fflush(stdin);
			gotoxy(4,17);cout<<"Codigo incorrecto, intente de nuevo.. ";
			getch();
			transicion(14,18,3,77);
		}
	}while(ExistenciaCodigo(cod2,lectura));
	eliminar(escritura,lectura,cod2);
	gotoxy(4,17);cout<<"Fecha de adopcion: ";getline(cin,fecha);
	
	escribir<<nombre<<endl;
	escribir<<apellido<<endl;
	escribir<<dni<<endl;
	escribir<<direc<<endl;
	escribir<<cod2<<endl;
	escribir<<fecha<<endl;
	
	escribir.close();		
}

void mostrarRegistrosAdopcion(ifstream &lectura){
	transicion(5,28,3,77);
	lectura.open("adopcion.txt",ios::in);
	if(lectura.is_open()){
		gotoxy(18,3);cout<<"VETERINARIA PARA PERROS - HUELLITAS UNIDAS";
		gotoxy(15,5);cout<<"REGISTRO DE ADOPCIONES";
		string nombre;
		string apellido;
		string dni;
		string direc;
		string cod2;
		string fecha;
	
			lectura>>nombre;
		while(!lectura.eof()){
			lectura>>apellido;
			lectura>>dni;
			lectura>>direc;
			lectura>>cod2;
			lectura>>fecha;
			transicion(5,23,3,77);
			gotoxy(7,5);cout<<"LISTA DE ADOPCIONES";
			gotoxy(4,7);cout<<"Nombre Adoptante: "<<nombre;
			gotoxy(4,9);cout<<"Apellido: "<<apellido;
			gotoxy(4,11);cout<<"DNI: "<<dni;
			gotoxy(4,13);cout<<"Direccion: "<<direc;
			gotoxy(4,15);cout<<"Cod perro: "<<cod2;
			gotoxy(4,17);cout<<"Fecha adopcion: "<<fecha;
			gotoxy(4,21);cout<<"Presione una tecla para continuar...";
			getch();
			lectura>>nombre;
		}
		lectura.close();	
	}else{
		gotoxy(4,7);cout<<"Error, No hay Adopciones o el archivo no existe"<<endl;
		getch();
	}
}

void eliminar(ofstream &escritura,ifstream &lectura, string codigo){
	int a=1;
	string cod, nom, edad, tam, raza, ingreso, estado;
	lectura.open("guarderia.txt", ios::in); 
	escritura.open("cambio.txt", ios::app);

	getline(lectura,cod);
	while(!lectura.eof()){
		getline(lectura,nom);
		getline(lectura,edad);
		getline(lectura,tam);
		getline(lectura,raza);
		getline(lectura,ingreso);
		getline(lectura,estado);
		if(cod == codigo){
			cout<<endl;				
		}else{
			escritura<<cod<<endl;
			escritura<<nom<<endl;
			escritura<<edad<<endl;
			escritura<<tam<<endl;
			escritura<<raza<<endl;
			escritura<<ingreso<<endl;
			escritura<<estado<<endl;
		}
	getline(lectura,cod);
	}
	lectura.close();
	escritura.close();
	remove("guarderia.txt");
	rename("cambio.txt", "guarderia.txt");
}

void cambiarEstadoAdopcion(ofstream &escritura,ifstream &lectura){
	transicion(5,28,3,77);
	string codigo, newestado, cod, nom, edad, tam, raza, ingreso, estado;
	lectura.open("guarderia.txt", ios::in); 
	escritura.open("cambio.txt", ios::app);
	gotoxy(15,5);cout<<"CAMBIO DE ESTADO";
	gotoxy(4,7);cout<<"Ingresar el codigo del perro: ";cin>>codigo;
	
	getline(lectura,cod);
	while(!lectura.eof()){
		getline(lectura,nom);
		getline(lectura,edad);
		getline(lectura,tam);
		getline(lectura,raza);
		getline(lectura,ingreso);
		getline(lectura,estado);
		if(cod == codigo){
			gotoxy(4,9);cout<<"Estado: "<<estado<<endl;
			gotoxy(4,11);cout<<"Ingresar Nuevo Estado: ";
			fflush(stdin);
			getline(cin, newestado);
			escritura<<cod<<endl;
			escritura<<nom<<endl;
			escritura<<edad<<endl;
			escritura<<tam<<endl;
			escritura<<raza<<endl;
			escritura<<ingreso<<endl;
			escritura<<newestado<<endl;				
		}else{
			escritura<<cod<<endl;
			escritura<<nom<<endl;
			escritura<<edad<<endl;
			escritura<<tam<<endl;
			escritura<<raza<<endl;
			escritura<<ingreso<<endl;
			escritura<<estado<<endl;
		}
	getline(lectura,cod);
	}
	lectura.close();
	escritura.close();
	remove("guarderia.txt");
	rename("cambio.txt", "guarderia.txt");
}

//======================================================================

void menuServicios(ofstream &escritura,ifstream &lectura){
	char opc;
	
	do{
		do{
			transicion(5,28,3,77);
			gotoxy(15,5);cout<<"MENÚ SERVICIOS"<<endl;
			gotoxy(4,7);cout<<"[1] Baños.";
			gotoxy(4,9);cout<<"[2] Vacunas.";
			gotoxy(4,11);cout<<"[3] Tratamientos.";
			gotoxy(4,13);cout<<"[4] Corte de pelo.";
			gotoxy(4,15);cout<<"[5] Operaciones.";
			gotoxy(4,17);cout<<"[6] Análisis.";
			gotoxy(4,19);cout<<"[7] Generar boleta.";
			gotoxy(4,21);cout<<"[8] Citas.";
			gotoxy(4,23);cout<<"[0] Volver al menú principal.";
			gotoxy(4,25);cout<<"Ingrese una opción: ";cin>>opc;
			if(opc!='1' && opc!='2' && opc!='3' && opc!='4' && opc!='5' && opc!='6' && opc!='7' && opc!='8' && opc!='0'){
				errorOpcionIngresada();
			}
		}
		while(opc!='1' && opc!='2' && opc!='3' && opc!='4' && opc!='5' && opc!='6' && opc!='7' && opc!='8' && opc!='0');
		switch(opc){
			case '1':	bano(precioServicios[0]);menuServicios(escritura,lectura);break;
			case '2':	vacunas(precioServicios[1]);break;
			case '3':	tratamientos(precioServicios[2]);break;
			case '4':	corte(precioServicios[3]);menuServicios(escritura,lectura);break;
			case '5':	operaciones(precioServicios[4]);break;
			case '6':	analisis(precioServicios[5]);break; 
			case '7':	generarBoleta(precioServicios);break;
			case '8':	menuCitas(escritura,lectura);
		}
	}
	while(opc!='0');
}

void bano(float &precioTotal){
	char opc;
	
	do{
		transicion(5,28,3,77);
		gotoxy(15,5);cout<<"BAÑOS"<<endl;
		gotoxy(4,7);cout<<"[1] Pequeño			S/.20";
		gotoxy(4,9);cout<<"[2] Mediano			S/.30";
		gotoxy(4,11);cout<<"[3] Grande			S/.40";
		gotoxy(4,13);cout<<"[0] Volver al menú";
		gotoxy(4,15);cout<<"Ingrese una opción: ";cin>>opc;
		if(opc!='1' && opc!='2' && opc!='3' && opc!='0'){
			errorOpcionIngresada();
		}
	}
	while(opc!='1' && opc!='2' && opc!='3' && opc!='0');
	if(opc!='0'){
		switch(opc){
			case '1':	precioTotal=20;break;
			case '2':	precioTotal=30;break;
			case '3':	precioTotal=40;
		}
		confirmacion();
	}
}

void vacunas(float &precioTotal){
	char opc;
	do{
		do{
			transicion(5,28,3,77);
			gotoxy(15,5);cout<<"VACUNAS"<<endl;
			gotoxy(4,7);cout<<"[1] Distemper		S/.80";
			gotoxy(4,9);cout<<"[2] Parvovirus		S/.90";
			gotoxy(4,11);cout<<"[3] Hepatitis		S/.70";
			gotoxy(4,13);cout<<"[4] Coronavirosis		S/.70";
			gotoxy(4,15);cout<<"[5] Parainfluencia		S/.60";
			gotoxy(4,17);cout<<"[6] Leptospirosis		S/.60";
			gotoxy(4,19);cout<<"[7] Rabia			S/.40";
			gotoxy(4,21);cout<<"[0] Volver al menú";
			gotoxy(4,23);cout<<"Ingrese una opción: ";cin>>opc;
			if(opc!='1' && opc!='2' && opc!='3' && opc!='4' && opc!='5' && opc!='6' && opc!='7' && opc!='0'){
				errorOpcionIngresada();
			}
		}
		while(opc!='1' && opc!='2' && opc!='3' && opc!='4' && opc!='5' && opc!='6' && opc!='7' && opc!='0');
		if(opc!='0'){
			switch(opc){
				case '1':	precioTotal+=80;break;
				case '2':	precioTotal+=90;break;
				case '3':	precioTotal+=70;break;
				case '4':	precioTotal+=70;break;
				case '5':	precioTotal+=60;break;
				case '6':	precioTotal+=60;break;
				case '7':	precioTotal+=40;
			}
			confirmacion();
		}
	}
	while(opc!='0');
}

void desparacitacion(float &precioTotal){
	char opc;
	do{
		do{
			transicion(5,28,3,77);
			gotoxy(15,5);cout<<"DESPARACITACIÓN"<<endl;
			gotoxy(4,7);cout<<"[1] Inyección		S/.20";
			gotoxy(4,9);cout<<"[2] Pastilla		S/.15";
			gotoxy(4,11);cout<<"[0] Volver al menú.";
			gotoxy(4,13);cout<<"Ingrese una opción: ";cin>>opc;
			if(opc!='1' && opc!='2' && opc!='0'){
				errorOpcionIngresada();
			}
		}
		while(opc!='1' && opc!='2' && opc!='0');
		if(opc!='0'){
			switch(opc){
				case '1':	precioTotal+=20;break;
				case '2':	precioTotal+=15;
			}
			confirmacion();
		}
	}
	while(opc!='0');
}

void antipulgas(float &precioTotal){
	char opc;
	do{
		do{
		transicion(5,28,3,77);
		gotoxy(15,5);cout<<"ANTIPULGAS"<<endl;
		gotoxy(4,7);cout<<"[1] Pipetas			S/.15";
		gotoxy(4,9);cout<<"[2] Pastilla		S/.20";
		gotoxy(4,11);cout<<"[3] Inyección		S/.25";
		gotoxy(4,13);cout<<"[0] Volver al menú.";
		gotoxy(4,15);cout<<"Ingrese una opción: ";cin>>opc;
			if(opc!='1' && opc!='2' && opc!='3' && opc!='0'){
				errorOpcionIngresada();
			}
		}
		while(opc!='1' && opc!='2' && opc!='3' && opc!='0');
		if(opc!='0'){
			switch(opc){
				case '1':	precioTotal+=15;break;
				case '2':	precioTotal+=20;break;
				case '3':	precioTotal+=25;
			}
			confirmacion();
		}
	}
	while(opc!='0');
}

void tratamientos(float &precioTotal){
	char opc;
	do{
		do{
			transicion(5,28,3,77);
			gotoxy(15,5);cout<<"TRATAMIENTOS"<<endl;
			gotoxy(4,7);cout<<"[1] Desparacitación.";
			gotoxy(4,9);cout<<"[2] Antipulgas.";
			gotoxy(4,11);cout<<"[0] Volver al menú.";
			gotoxy(4,13);cout<<"Ingrese una opción: ";cin>>opc;
			if(opc!='1' && opc!='2' && opc!='0'){
				errorOpcionIngresada();
			}
		}
		while(opc!='1' && opc!='2' && opc!='0');
		switch(opc){
			case '1':	desparacitacion(precioTotal);
						break;
			case '2':	antipulgas(precioTotal);
		}
	}
	while(opc!='0');
}

void corte(float &precioTotal){
	char opc;
		do{
			transicion(5,28,3,77);
			gotoxy(15,5);cout<<"CORTE DE PELO"<<endl;
			gotoxy(4,7);cout<<"[1] Corte León		S/.40";
			gotoxy(4,9);cout<<"[2] Corte Inglés		S/.45";
			gotoxy(4,11);cout<<"[3] Corte Holandés		S/.40";
			gotoxy(4,13);cout<<"[4] Corte Moderno		S/.45";
			gotoxy(4,15);cout<<"[5] Corte de Cachorro	S/.25";
			gotoxy(4,17);cout<<"[6] Corte de Verano		S/.35";
			gotoxy(4,19);cout<<"[0] Volver al menu";
			gotoxy(4,21);cout<<"Ingrese una opción: ";cin>>opc;
			if(opc!='1' && opc!='2' && opc!='3' && opc!='4' && opc!='5' && opc!='6' && opc!='0'){
				errorOpcionIngresada();
			}
		}
		while(opc!='1' && opc!='2' && opc!='3' && opc!='4' && opc!='5' && opc!='6' && opc!='0');
		if(opc!='0'){
			switch(opc){
				case '1':	precioTotal+=40;break;
				case '2':	precioTotal+=45;break;
				case '3':	precioTotal+=40;break;
				case '4':	precioTotal+=45;break;
				case '5':	precioTotal+=25;break;
				case '6':	precioTotal+=35;
			}
			confirmacion();
		}
}

void operaciones(float &precioTotal){
	char opc;
	ifstream lectura; 
	ofstream add;

	do{
		transicion(5,28,3,77);
		gotoxy(15,5);cout<<"OPERACIONES"<<endl;
		gotoxy(4,7);cout<<"[1] Esterilización		S/.200";
		gotoxy(4,9);cout<<"[2] Oftalmología		S/.250";
		gotoxy(4,11);cout<<"[3] Maxilofacial		S/.200";
		gotoxy(4,13);cout<<"[4] Abdominal		S/.300";
		gotoxy(4,15);cout<<"[5] Oncología		S/.400";
		gotoxy(4,17);cout<<"[6] Reconstructiva		S/.500";
		gotoxy(4,19);cout<<"[7] Urgencias		S/.400";
		gotoxy(4,21);cout<<"[0] Volver al menú";
		gotoxy(4,23);cout<<"Ingrese una opción: ";cin>>opc;
		if(opc!='1' && opc!='2' && opc!='3' && opc!='4' && opc!='5' && opc!='6' && opc!='7' && opc!='0'){
			errorOpcionIngresada();
		}
	}while(opc!='1' && opc!='2' && opc!='3' && opc!='4' && opc!='5' && opc!='6' && opc!='7' && opc!='0');
	if(opc!='0'){
		switch(opc){
			case '1':	precioTotal+=200;break;
			case '2':	precioTotal+=250;break;
			case '3':	precioTotal+=200;break;
			case '4':	precioTotal+=300;break;
			case '5':	precioTotal+=400;break;
			case '6':	precioTotal+=500;break;
			case '7':	precioTotal+=400;break;
		}
		transicion(5,28,3,77);
		gotoxy(3,13);cout<<"Registro exitoso, presione una tecla para ingresar Cita ";
		getch();
		agregarCita(add,lectura);
	}
}

void descarteEnfermedades(float &precioTotal){
	char opc;
	do{
		do{
			transicion(5,28,3,77);
			gotoxy(15,5);cout<<"DESCARTE DE ENFERMEDADES"<<endl;
			gotoxy(4,7);cout<<"[1] Distemper y Parvovirus	S/.100";
			gotoxy(4,9);cout<<"[2] Leptospirosis		S/.80";
			gotoxy(4,11);cout<<"[3] Micoplasmosis		S/.80";
			gotoxy(4,13);cout<<"[0] Volver al menú.";
			gotoxy(4,15);cout<<"Ingrese una opción: ";cin>>opc;
			if(opc!='1' && opc!='2' && opc!='3' && opc!='0'){
				errorOpcionIngresada();
			}
		}
		while(opc!='1' && opc!='2' && opc!='3' && opc!='0');
		if(opc!='0'){
			switch(opc){
				case '1':	precioTotal+=100;break;
				case '2':	precioTotal+=80;break;
				case '3':	precioTotal+=80;
			}
			confirmacion();
		}
	}
	while(opc!='0');	
}

void analisisGeneral(float &precioTotal){
	char opc;
	do{
		do{
			transicion(5,28,3,77);
			gotoxy(15,5);cout<<"ANÁLISIS GENERAL"<<endl;
			gotoxy(4,7);cout<<"[1] De sangre		S/.100";
			gotoxy(4,9);cout<<"[2] Físico			S/.120";
			gotoxy(4,11);cout<<"[3] Ambos			S/.210";
			gotoxy(4,13);cout<<"[0] Volver al menú.";
			gotoxy(4,15);cout<<"Ingrese una opción: ";cin>>opc;
			if(opc!='1' && opc!='2' && opc!='3' && opc!='0'){
				errorOpcionIngresada();
			}
		}
		while(opc!='1' && opc!='2' && opc!='3' && opc!='0');
		if(opc!='0'){
			switch(opc){
				case '1':	precioTotal+=100;break;
				case '2':	precioTotal+=120;break;
				case '3':	precioTotal+=210;
			}
			confirmacion();
		}
	}
	while(opc!='0');
}

void analisis(float &precioTotal){
	char opc;
	do{
		do{
			transicion(5,28,3,77);
			gotoxy(15,5);cout<<"ANÁLISIS"<<endl;
			gotoxy(4,7);cout<<"[1] Chequeo preoperatorio	S/.300";
			gotoxy(4,9);cout<<"[2] Descarte de enfermedades";
			gotoxy(4,11);cout<<"[3] Radiografías		S/.400";
			gotoxy(4,13);cout<<"[4] Tomografías		S/.400";
			gotoxy(4,15);cout<<"[5] General";
			gotoxy(4,17);cout<<"[0] Volver al menú";
			gotoxy(4,19);cout<<"Ingrese una opción: ";cin>>opc;
			if(opc!='1' && opc!='2' && opc!='3' && opc!='4' && opc!='5' && opc!='0'){
				errorOpcionIngresada();
			}
		}
		while(opc!='1' && opc!='2' && opc!='3' && opc!='4' && opc!='5' && opc!='0');
		switch(opc){
			case '1':	precioTotal+=300;
						confirmacion();
						break;
			case '2':	descarteEnfermedades(precioTotal);break;
			case '3':	precioTotal+=400;
						confirmacion();
						break;
			case '4':	precioTotal+=400;
						confirmacion();
						break;
			case '5':	analisisGeneral(precioTotal);
		}
	}
	while(opc!='0');
}

void generarBoleta(float precioTotal[]){
	string nombreCliente;
	float sumaPrecioTotal=0;
	transicion(5,28,3,77);
	fflush(stdin);
	gotoxy(3,13);cout<<"Ingrese el nombre del cliente: ";getline(cin,nombreCliente);
	transicion(5,28,3,77);
	gotoxy(27,5);cout<<"BOLETA DE COMPRA";
	gotoxy(4,7);cout<<"Nombre del cliente: "<<nombreCliente;
	gotoxy(4,9); cout<<"Baños ------------------------------------------------------- S/."<<precioTotal[0];
	gotoxy(4,11);cout<<"Vacunas ----------------------------------------------------- S/."<<precioTotal[1];
	gotoxy(4,13);cout<<"Tratamientos ------------------------------------------------ S/."<<precioTotal[2];
	gotoxy(4,15);cout<<"Corte de pelo ----------------------------------------------- S/."<<precioTotal[3];
	gotoxy(4,17);cout<<"Operaciones ------------------------------------------------- S/."<<precioTotal[4];
	gotoxy(4,19);cout<<"Análisis ---------------------------------------------------- S/."<<precioTotal[5];
	for(int i=0;i<6;i++){
		sumaPrecioTotal+=precioTotal[i];
	}
	gotoxy(4,21);cout<<"Total                                                             "<<sumaPrecioTotal;
	gotoxy(9,23);cout<<"¡Gracias por comprar en la Veterinaria Huellitas Unidas! :D";
	getch();
	for(int i=0;i<6;i++){
		precioTotal[i]=0;
	}
}

//===========================================================================================

void agregarCita(ofstream &escritura,ifstream &lectura){ 
	lectura.open("Perritos.txt",ios::in);
	if(lectura.is_open()){
		lectura.close();
		string codigo,tipo,fecha,hora;
		escritura.open("Citas.txt",ios::out|ios::app);
		transicion(5,28,3,77);
		gotoxy(7,5);cout<<"GENERAR CITA";
		fflush(stdin);
		gotoxy(4,7);cout<<"Código del perro: "; cin>>codigo;
		if(!verificarCodigo(codigo,lectura)){
			gotoxy(4,9);cout<<"--------Perro no encontrado--------";
			getch();
		}
		else{
			fflush(stdin);
			gotoxy(4,9);cout<<"Operación: ";getline(cin,tipo);
			fflush(stdin);	
			gotoxy(4,11);cout<<"Fecha: ";getline(cin,fecha);
			fflush(stdin);	
			gotoxy(4,13);cout<<"Hora: ";getline(cin,hora);
			escritura<<codigo<<endl;
			escritura<<tipo<<endl;
			escritura<<fecha<<endl;
			escritura<<hora<<endl;
			confirmacion();
		}
		escritura.close();
	}
	else{
		archivoNoAbierto();
	}
}

void verCita(ifstream &lectura){
	lectura.open("Citas.txt",ios::in);
	if(lectura.is_open()){
		string codigo,tipo,fecha,hora;
		getline(lectura,codigo);
		while(!lectura.eof()){
			getline(lectura,tipo);
			getline(lectura,fecha);
			getline(lectura,hora);
			transicion(5,28,3,77);
			gotoxy(7,5);cout<<"CITAS";
			gotoxy(4,7);cout<<"Código del perro: "<<codigo;
			gotoxy(4,9);cout<<"Tipo: "<<tipo;
			gotoxy(4,11);cout<<"Fecha: "<<fecha;
			gotoxy(4,13);cout<<"Hora: "<<hora;
			gotoxy(4,15);cout<<"Presione una tecla para continuar...";
			getch();
			getline(lectura,codigo);
		}
		lectura.close();
	}
	else{
		archivoNoAbierto();
	}
}

void buscarCita(ifstream &lectura){
	lectura.open("Citas.txt",ios::in);
	if(lectura.is_open()){
		string codigo,tipo,fecha,hora,codigoBuscado;
		bool encontrado=false;
		transicion(5,28,3,77);
		gotoxy(7,5);cout<<"BUSCAR CITA";
		fflush(stdin);
		gotoxy(4,7);cout<<"Ingrese el código del perrito: ";cin>>codigoBuscado;
		getline(lectura,codigo);
		while(encontrado==false&&!lectura.eof()){
			getline(lectura,tipo);
			getline(lectura,fecha);
			getline(lectura,hora);
			if(codigo==codigoBuscado){
				transicion(5,28,3,77);
				gotoxy(7,5);cout<<"CITA ENCONTRADA";
				gotoxy(4,7);cout<<"Código del perro: "<<codigo;
				gotoxy(4,9);cout<<"Tipo: "<<tipo;
				gotoxy(4,11);cout<<"Fecha: "<<fecha;
				gotoxy(4,13);cout<<"Hora: "<<hora;
				encontrado=true;
			}
			getline(lectura,codigo);
		}
		if(encontrado==false){
			gotoxy(4,9);cout<<"Perrito no encontrado.";
		}
		lectura.close();
		getch();
	}
	else{
		archivoNoAbierto();
	}
}

void modificarCita(ofstream &escritura,ifstream &lectura){
	lectura.open("Citas.txt",ios::in);
	if(lectura.is_open()){
		string codigo,tipo,fecha,hora,nuevaFecha,codigoAux,nuevaHora;
		bool encontrado=false;
		escritura.open("Auxiliar.txt",ios::out);
		transicion(5,28,3,77);
		gotoxy(8,5);cout<<"MODIFICAR FECHA DE CITA";
		fflush(stdin);
		gotoxy(4,7);cout<<"Digite el código del perro: ";getline(cin,codigoAux);
		getline(lectura,codigo);
		while(!lectura.eof()){
			getline(lectura,tipo);
			getline(lectura,fecha);
			getline(lectura,hora);
			escritura<<codigo<<endl;
			escritura<<tipo<<endl;
			if(codigo==codigoAux){
				encontrado=true;
				gotoxy(4,9);cout<<"Nueva fecha: ";getline(cin,nuevaFecha);
				gotoxy(4,11);cout<<"Nueva hora: ";getline(cin,nuevaHora);
				escritura<<nuevaFecha<<endl;
				escritura<<nuevaHora<<endl;
				gotoxy(4,13);cout<<"Datos modificados con éxito, presione una tecla para regresar al menú.";
			}
			else{
				escritura<<fecha<<endl;
				escritura<<hora<<endl;
			}
			getline(lectura,codigo);
		}
		lectura.close();
		escritura.close();
		remove("Citas.txt");
		rename("Auxiliar.txt","Citas.txt");
		if(encontrado==false){
			gotoxy(4,9);cout<<"Perrito no encontrado."<<endl;
		}
		getch();
	}
	else{
		archivoNoAbierto();
	}
}

void eliminarCita(ofstream &escritura,ifstream &lectura){
	lectura.open("Citas.txt",ios::in);
	if(lectura.is_open()){
		string codigo,tipo,fecha,hora,codigoAux;
		bool encontrado=false;
		escritura.open("Auxiliar.txt",ios::out);
		transicion(5,28,3,77);
		gotoxy(8,5);cout<<"ELIMINAR CITA";
		fflush(stdin);
		gotoxy(4,7);cout<<"Digite el código del perro: ";getline(cin,codigoAux);
		getline(lectura,codigo);
		while(!lectura.eof()){
			getline(lectura,tipo);
			getline(lectura,fecha);
			getline(lectura,hora);
			if(codigo==codigoAux){
				encontrado=true;
				gotoxy(4,9);cout<<"La cita se ha eliminado con éxito, presione una tecla para regresar al menú.";
			}
			else{
				escritura<<codigo<<endl;
				escritura<<tipo<<endl;
				escritura<<fecha<<endl;
				escritura<<hora<<endl;
			}
			getline(lectura,codigo);
		}
		lectura.close();
		escritura.close();
		remove("Citas.txt");
		rename("Auxiliar.txt","Citas.txt");
		if(encontrado==false){
			gotoxy(4,9);cout<<"Perrito no encontrado."<<endl;
		}
		getch();
	}
	else{
		archivoNoAbierto();
	}
}


void menuCitas(ofstream &escritura,ifstream &lectura){
	char opc;
	do{
		do{
			transicion(5,28,3,77);
			gotoxy(15,5);cout<<"CITAS"<<endl;
			gotoxy(4,7);cout<<"[1] Programar cita.";
			gotoxy(4,9);cout<<"[2] Ver citas.";
			gotoxy(4,11);cout<<"[3] Buscar personas.";
			gotoxy(4,13);cout<<"[4] Modificar cita.";
			gotoxy(4,15);cout<<"[5] Eliminar cita.";
			gotoxy(4,17);cout<<"[0] Salir.";
			gotoxy(4,19);cout<<"Ingrese una opción: ";cin>>opc;
			if(opc!='1' && opc!='2' && opc!='3' && opc!='4' && opc!='5' && opc!='0'){
				errorOpcionIngresada();
			}
		}
		while(opc!='1' && opc!='2' && opc!='3' && opc!='4' && opc!='5'&& opc!='0');
		switch(opc){
			case '1':	agregarCita(escritura,lectura);break;
			case '2':	verCita(lectura);break;
			case '3':	buscarCita(lectura);break;
			case '4':	modificarCita(escritura,lectura);break;
			case '5':	eliminarCita(escritura,lectura);
		}
	}
	while(opc!='0');
}

//============================================================================================

void menuVentaDeArticulos(ofstream &escritura,ifstream &lectura){
	char opc;
	do{
		do{
			transicion(5,28,3,77);
			gotoxy(33,5);cout<<"MENÚ ARTÍCULOS"<<endl;
			gotoxy(4,7);cout<<"[1] Ingresar un nuevo producto al sistema.";
			gotoxy(4,9);cout<<"[2] Buscar un producto en el sistema.";
			gotoxy(4,11);cout<<"[3] Ver productos en el sistema.";
			gotoxy(4,13);cout<<"[4] Generar compra.";
			gotoxy(4,15);cout<<"[0] Salir.";
			gotoxy(4,17);cout<<"Ingrese una opción: ";cin>>opc;
			if(opc!='1' && opc!='2' && opc!='3' && opc!='4' && opc!='0'){
				errorOpcionIngresada();
			}
		}
		while(opc!='1' && opc!='2' && opc!='3' && opc!='4' && opc!='0');
		switch(opc){
			case '1':	agregarProducto(escritura,lectura);break;
			case '2':	buscarProducto(lectura);break;
			case '3':	verProductos(lectura);break;
			case '4':	generarCompra(escritura,lectura);
		}
	}
	while(opc!='0');
}

bool verificarProducto(ifstream &lectura,string nombreProductoBuscado){
	lectura.open("Productos.txt",ios::in);
	string nombreProducto,espacio;
	float precioProducto;
	int cantidadProducto;
	bool encontrado=false;
	getline(lectura,nombreProducto);
	while(!lectura.eof()&&encontrado==false){
		lectura>>cantidadProducto;
		lectura>>precioProducto;
		if(nombreProducto==nombreProductoBuscado){
			encontrado=true;
		}
		getline(lectura,espacio);
		getline(lectura,nombreProducto);
	}
	lectura.close();
	return encontrado;
}

void modificarCantidadProducto(ofstream &escritura,ifstream &lectura,string nombreProductoBuscado,int cantidadAdicional){
	lectura.open("Productos.txt",ios::in);
	escritura.open("Auxiliar.txt",ios::out);
	string nombreProducto,espacio;
	float precioProducto;
	int cantidadProducto,cantidadAux;
	getline(lectura,nombreProducto);
	while(!lectura.eof()){
		lectura>>cantidadProducto;
		lectura>>precioProducto;
		escritura<<nombreProducto<<endl;
		if(nombreProducto==nombreProductoBuscado){
			cantidadAux=cantidadProducto+cantidadAdicional;
			escritura<<cantidadAux<<endl;
		}
		else{
			escritura<<cantidadProducto<<endl;
		}
		escritura<<precioProducto<<endl;
		getline(lectura,espacio);
		getline(lectura,nombreProducto);
	}
	escritura.close();
	lectura.close();
	remove("Productos.txt");
	rename("Auxiliar.txt","Productos.txt");
}

void agregarProducto(ofstream &escritura,ifstream &lectura){
	string nombreProducto;
	int cantidadProducto;
	escritura.open("Productos.txt",ios::out|ios::app);
	transicion(5,28,3,77);
	gotoxy(30,5);cout<<"INGRESAR UN PRODUCTO";
	fflush(stdin);
	gotoxy(4,7);cout<<"Nombre: ";getline(cin,nombreProducto);
	do{
		gotoxy(4,9);cout<<"Cantidad de productos: ";cin>>cantidadProducto;
		if(cantidadProducto<=0){
			gotoxy(4,11);cout<<"Cantidad ingresada no válida, presione una tecla para volver a intentarlo.";
			getch();
			transicion(9,11,3,77);
		}
	}
	while(cantidadProducto<=0);
	if(verificarProducto(lectura,nombreProducto)){
		modificarCantidadProducto(escritura,lectura,nombreProducto,cantidadProducto);
	}
	else{
		float precioProducto;
		do{
			gotoxy(4,11);cout<<"Precio: S/.";cin>>precioProducto;
			if(precioProducto<=0){
				gotoxy(4,13);cout<<"Precio no válido, presione una tecla para volver a intentarlo.";
				getch();
				transicion(11,13,3,77);
			}
		}
		while(precioProducto<=0);
		escritura<<nombreProducto<<endl;
		escritura<<cantidadProducto<<endl;
		escritura<<precioProducto<<endl;
	}
	confirmacion();
	escritura.close();
}

void buscarProducto(ifstream &lectura){
	lectura.open("Productos.txt",ios::in);
	if(lectura.is_open()){
		string nombreProducto,nombreProductoBuscado,espacio;
		int cantidadProducto;
		float precioProducto;
		bool encontrado=false;
		transicion(5,28,3,77);
		gotoxy(33,5);cout<<"BUSCAR PRODUCTO";
		gotoxy(4,7);cout<<"Ingrese el nombre del producto: ";cin>>nombreProductoBuscado;
		getline(lectura,nombreProducto);
		while(encontrado==false&&!lectura.eof()){
			lectura>>cantidadProducto;
			lectura>>precioProducto;
			if(nombreProducto==nombreProductoBuscado){
				transicion(5,28,3,77);
				gotoxy(31,5);cout<<"PRODUCTO ENCONTRADO";
				gotoxy(4,7);cout<<"Nombre: "<<nombreProducto;
				gotoxy(4,9);cout<<"Cantidad de productos: "<<cantidadProducto;
				gotoxy(4,11);cout<<"Precio: S/."<<precioProducto;
				encontrado=true;
			}
			getline(lectura,espacio);
			getline(lectura,nombreProducto);
		}
		if(encontrado==false){
			gotoxy(29,9);cout<<"Producto no encontrado.";
		}
		lectura.close();
		getch();
	}
	else{
		archivoNoAbierto();
	}
}

void verProductos(ifstream &lectura){
	lectura.open("Productos.txt",ios::in);
	if(lectura.is_open()){
		string nombreProducto,espacio;
		float precioProducto;
		int cantidadProducto;
		getline(lectura,nombreProducto);
		while(!lectura.eof()){
			lectura>>cantidadProducto;
			lectura>>precioProducto;
			transicion(5,28,3,77);
			gotoxy(30,5);cout<<"PRODUCTOS REGISTRADOS"<<endl;
			gotoxy(4,7);cout<<"Nombre: "<<nombreProducto;
			gotoxy(4,9);cout<<"Cantidad de productos: "<<cantidadProducto;
			gotoxy(4,11);cout<<"Precio: S/."<<precioProducto;
			gotoxy(4,13);cout<<"Presione una tecla para continuar...";
			getch();
			getline(lectura,espacio);
			getline(lectura,nombreProducto);
		}
		lectura.close();
	}
	else{
		archivoNoAbierto();
	}	
}

bool verificarCantidadDisponible(ifstream &lectura,string nombreProductoBuscado,int cantidadRequerida){
	lectura.open("Productos.txt",ios::in);
	string nombreProducto,espacio;
	float precioProducto;
	int cantidadProducto;
	bool disponible=true,encontrado=false;
	getline(lectura,nombreProducto);
	while(!lectura.eof()&&encontrado==false){
		lectura>>cantidadProducto;
		lectura>>precioProducto;
		if(nombreProducto==nombreProductoBuscado){
			encontrado=true;
			if(cantidadRequerida+cantidadProducto<0){
				disponible=false;
			}
		}
		getline(lectura,espacio);
		getline(lectura,nombreProducto);
	}
	lectura.close();
	return disponible;
}

float obtenerPrecio(ifstream &lectura,string nombreProductoBuscado){
	lectura.open("Productos.txt",ios::in);
	string nombreProducto,espacio;
	float precioProducto,precioProductoBuscado=-1;
	int cantidadProducto;
	getline(lectura,nombreProducto);
	while(!lectura.eof()&&precioProductoBuscado==-1){
		lectura>>cantidadProducto;
		lectura>>precioProducto;
		if(nombreProducto==nombreProductoBuscado){
			precioProductoBuscado=precioProducto;
		}
		getline(lectura,espacio);
		getline(lectura,nombreProducto);
	}
	lectura.close();
	return precioProductoBuscado;
}

void generarCompra(ofstream &escritura,ifstream &lectura){
	string nombreCliente,nombreProducto;
	int cantidadProducto;
	char otroProducto='N';
	float costoTotal=0;
	lectura.open("Productos.txt",ios::in);
	if(lectura.is_open()){
		lectura.close();
		fflush(stdin);
		transicion(5,28,3,77);
		gotoxy(33,5);cout<<"GENERAR COMPRA";
		gotoxy(4,7);cout<<"Nombre del cliente: ";getline(cin,nombreCliente);
		do{
			if(otroProducto='S'){
				transicion(9,15,3,77);
			}
			do{
				fflush(stdin);
				gotoxy(4,9);cout<<"Nombre del producto: ";getline(cin,nombreProducto);
				if(!verificarProducto(lectura,nombreProducto)){
					gotoxy(4,11);cout<<"Producto no encontrado, presione una tecla para volver a intentarlo.";
					getch();
					transicion(9,11,3,77);
				}
			}
			while(!verificarProducto(lectura,nombreProducto));
			do{
				gotoxy(4,11);cout<<"Cantidad requerida: ";cin>>cantidadProducto;
				if(!verificarCantidadDisponible(lectura,nombreProducto,cantidadProducto)){
					gotoxy(4,13);cout<<"Cantidad no disponible, presione una tecla para volver a intentarlo.";
					getch();
					transicion(11,13,3,77);
				}
			}
			while(!verificarCantidadDisponible(lectura,nombreProducto,cantidadProducto));
			gotoxy(4,13);cout<<"El costo total por el producto es S/. "<<cantidadProducto*obtenerPrecio(lectura,nombreProducto);
			costoTotal+=cantidadProducto*obtenerPrecio(lectura,nombreProducto);
			modificarCantidadProducto(escritura,lectura,nombreProducto,-cantidadProducto);
			do{
				gotoxy(4,15);cout<<"¿Desea agregar otro producto? (S:Sí|N:No): ";cin>>otroProducto;
				if(otroProducto!='S'&&otroProducto!='N'){
					gotoxy(4,17);cout<<"Respuesta no válida, presione una tecla para volver a intentarlo.";
					getch();
					transicion(15,17,3,77);
				}
			}
			while(otroProducto!='S'&&otroProducto!='N');
		}
		while(otroProducto=='S');
		gotoxy(4,17);cout<<"El costo total es S/."<<costoTotal;
		gotoxy(4,19);cout<<"¡La compra se ha generado correctamente!";
		getch();
	}
	else{
		archivoNoAbierto();
	}
}

//=======================================================================================0

void errorOpcionIngresada(){
	transicion(5,28,3,77);
	gotoxy(3,13);cout<<"Opcion no valida, presione una tecla para volver a intentarlo.";
	getch();
}

void confirmacion(){
	transicion(5,28,3,77);
	gotoxy(3,13);cout<<"Registro exitoso, presione una tecla para regresar al menu.";
	getch();
}

void archivoNoAbierto(){
	transicion(5,28,3,77);
	gotoxy(4,15);cout<<"ERROR. Registro no encontrado.";
	getch();	
}

//Hacer cuadrados, son para darle estetica y forma a nuestro menu?
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
//Funcion estetica para senalar posiciones en eje "x" "y" (rescatado de foros), porque antes existia la funcion gotoxy dentro de la libreria windows.h pero ahora debe ser manual
 void gotoxy(int x,int y){  
      HANDLE hcon;  
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
      COORD dwPos;  
      dwPos.X = x;  
      dwPos.Y= y;  
      SetConsoleCursorPosition(hcon,dwPos);  
 } 
 void transicion(int yInicio,int yFinal,int xInicio,int xFinal){
	int i,j;
	//hacer un barrido de "limpieza" en toda la pantalla que se muestra
	for(i=yInicio;i<=yFinal;i++){ //Como el cuadro est? hasta 24... y la transici?n est? hecho a base de espacios en blanco, para que no se borre el cuadrado principal, le damos un 23
		for(j=xInicio;j<=xFinal;j++){ //Como el cuadro est? hasta 78... y la transici?n est? hecho a base de espacios en blanco, para que no se borre el cuadrado principal, le damos un 77
			gotoxy(j,i);cout<<" ";
		}
	}
}