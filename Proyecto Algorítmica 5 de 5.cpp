#include <iostream>
#include <conio.h>
#include <windows.h>
#include <string.h>
#include <stdlib.h>
#include <fstream>

using namespace std;

void menu_principal(ofstream &,ifstream &);
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

void menu_adopcion(ofstream &,ifstream &);
bool verifica(int, ifstream &);
bool cantidad(ifstream &);
void nuevoingreso(ofstream &,ifstream &);
void lista(ifstream &);
void adoptar(ofstream &,ifstream &);
void eliminar(ofstream &,ifstream &);
void registro(ifstream &);
void cambio(ofstream &,ifstream &);

void menu_servicios(ofstream &,ifstream &);
int bano();
int vacunas();
int tratamientos(ofstream &,ifstream &);
int corte();
int operaciones(ofstream &,ifstream &);
int analisis(ofstream &,ifstream &);
void boleta(int vec[]);
void menuCitas(ofstream &,ifstream &);
void agregarCita(ofstream &,ifstream &);
void verCita(ifstream &);
void buscarCita(ifstream &);
void modificarCita(ofstream &,ifstream &);
void eliminarCita(ifstream &,ofstream &);

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

int datos[6]={0,0,0,0,0,0};

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
	menu_principal(escritura,lectura);
    return 0;
}
//======================================================================
void menu_principal(ofstream &escritura,ifstream &lectura){
	char opc;
	do{
		gotoxy(4,5);cout<<"MENU PRINCIPAL"<<endl;
	    gotoxy(4,7);cout<<"[1] Pacientes";
	    gotoxy(4,9);cout<<"[2] Servicios";
	    gotoxy(4,11);cout<<"[3] Adopciones";
	    gotoxy(4,13);cout<<"[4] Venta de articulos";
	    gotoxy(4,15);cout<<"[0] Salir";
	    gotoxy(4,19);cout<<"Digite una opcion: ";
	    cin>>opc;
	    transicion(5,23,3,77);
        if(opc!='1' and opc!='2' and opc!='3' and opc!='4' and opc!='0'){
        	errorOpcionIngresada();
        	getch();
        	transicion(5,23,3,77);
		}
		cin.ignore();
    }while(opc!='1' and opc!='2' and opc!='3' and opc!='4' and opc!='0');
    
   	switch (opc){
   		case '1':{
   			menuPacientes(escritura,lectura);
			transicion(5,23,3,77);
   			menu_principal(escritura,lectura);
			break;
		   }
		case '2':{
			menu_servicios(escritura,lectura);
			transicion(5,23,3,77);
			menu_principal(escritura,lectura);
			break;
		}
		case '3':{
			menu_adopcion(escritura,lectura);
			transicion(5,23,3,77);
			menu_principal(escritura,lectura);
			break;
		}
		case '4':{
			menuVentaDeArticulos(escritura,lectura);
			transicion(5,23,3,77);
			menu_principal(escritura,lectura);
			break;
		}
		case '0':{
			transicion(5,23,3,77);
			gotoxy(3,11);cout<<"¡Gracias por visitar a la Veterinaria Huellitas Unidas! :'D";
			gotoxy(3,13);cout<<"Presione una tecla para finalizar.";
			getch();
			break;
	   	}
  	 }
}
//======================================================================
void menuPacientes(ofstream &escritura,ifstream &lectura){
	char opc;
	do{
		do{
			transicion(5,23,3,77);
			gotoxy(15,5);cout<<"PACIENTES"<<endl;
			gotoxy(4,7);cout<<"[1] Ingresar nuevo paciente.";
			gotoxy(4,9);cout<<"[2] Ver pacientes.";
			gotoxy(4,11);cout<<"[3] Buscar paciente existente.";
			gotoxy(4,13);cout<<"[4] Modificar paciente.";
			gotoxy(4,15);cout<<"[5] Eliminar paciente.";
			gotoxy(4,17);cout<<"[0] Volver al menu principal.";
			gotoxy(4,19);cout<<"Ingrese una opcion: ";cin>>opc;

		}
		while(opc!='1' && opc!='2' && opc!='3' && opc!='4' && opc!='5' && opc!='0');
		switch(opc){
			case '1':{	agregarPaciente(escritura,lectura);break;}
			case '2':{	verPaciente(lectura);break;}
			case '3':{	buscarPaciente(lectura);break;}
			case '4':{	modificarPaciente(escritura,lectura);break;}
			case '5':{	eliminarPaciente(escritura,lectura);break;}
		}
	}
	while(opc!='0');
}

void agregarPaciente(ofstream &escritura,ifstream &lectura){
	string codigo;
	escritura.open("Perritos.txt",ios::out|ios::app);
	transicion(5,23,3,77);
	gotoxy(7,5);cout<<"REGISTRE A SU MASCOTA";
	fflush(stdin);
	gotoxy(4,7);cout<<"Codigo de la mascota: ";getline(cin,codigo);
	fflush(stdin);
	if(verificarCodigo(codigo,lectura)){
		gotoxy(7,9);cout<<"--------Codigo ya en uso--------";
	}
	else{
		string perrito,nombreDueno,apellidoDueno,raza,fecha;
		fflush(stdin);
		gotoxy(4,9);cout<<"Nombre del perrito: ";getline(cin,perrito);
		fflush(stdin);
		gotoxy(4,11);cout<<"Nombre del dueno: ";getline(cin,nombreDueno);
		fflush(stdin);
		gotoxy(4,13);cout<<"Apellido del dueno: ";getline(cin,apellidoDueno);
		fflush(stdin);
		gotoxy(4,15);cout<<"Raza del perro: ";getline(cin,raza);
		fflush(stdin);
		gotoxy(4,17);cout<<"Fecha de hoy: ";getline(cin,fecha);
		fflush(stdin);
		escritura<<perrito<<" "<<codigo<<" "<<nombreDueno<<" "<<apellidoDueno<<" "<<raza<<" "<<fecha<<"\n";
		confirmacion();
	}
	escritura.close();
	getch();
}

bool verificarCodigo(string codigoBuscado,ifstream &lectura){
	lectura.open("Perritos.txt",ios::in);
	string perrito,nombreDueno,apellidoDueno,raza,fecha,codigo;
	lectura>>perrito;
	while(!lectura.eof()){
		lectura>>codigo;
		lectura>>nombreDueno;
		lectura>>apellidoDueno;
		lectura>>raza;
		lectura>>fecha;
		if(codigo==codigoBuscado){
			lectura.close();
			return true;
		}
		lectura>>perrito;
	}
	lectura.close();
	return false;
}

void verPaciente(ifstream &lectura){
	lectura.open("Perritos.txt",ios::in);
	if(lectura.is_open()){
		string codigo,perrito,nombreDueno,apellidoDueno,raza,fecha;
		lectura>>perrito;
		while(!lectura.eof()){
			lectura>>codigo;
			lectura>>nombreDueno;
			lectura>>apellidoDueno;
			lectura>>raza;
			lectura>>fecha;
			transicion(5,23,3,77);
			gotoxy(7,5);cout<<"PERRITOS REGISTRADOS";
			gotoxy(4,7);cout<<"Nombre del perrito: "<<perrito;
			gotoxy(4,9);cout<<"Codigo del perrito: "<<codigo;
			gotoxy(4,11);cout<<"Nombre del dueno: "<<nombreDueno;
			gotoxy(4,13);cout<<"Apellido del dueno: "<<apellidoDueno;
			gotoxy(4,15);cout<<"Raza del perrito: "<<raza;
			gotoxy(4,17);cout<<"Fecha de inscripcion: "<<fecha;
			gotoxy(4,21);cout<<"Presione una tecla para continuar...";
			getch();
			lectura>>perrito;
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
		string codigo,perrito,nombreDueno,apellidoDueno,raza,fecha,codigoBuscado;
		bool encontrado=false;
		transicion(5,23,3,77);
		gotoxy(7,5);cout<<"BUSCAR PERRITO";
		gotoxy(4,7);cout<<"Ingrese el codigo del perrito: ";cin>>codigoBuscado;
		lectura>>perrito;
		while(!encontrado&&!lectura.eof()){
			lectura>>codigo;
			lectura>>nombreDueno;
			lectura>>apellidoDueno;
			lectura>>raza;
			lectura>>fecha;
			if(codigo==codigoBuscado){
				transicion(5,23,3,77);
				gotoxy(7,5);cout<<"PERRITO ENCONTRADO";
				gotoxy(4,7);cout<<"Nombre del derrito: "<<perrito;
				gotoxy(4,9);cout<<"Codigo del perrito: "<<codigo;
				gotoxy(4,11);cout<<"Nombre del dueno: "<<nombreDueno;
				gotoxy(4,13);cout<<"Apellido del dueno: "<<apellidoDueno;
				gotoxy(4,15);cout<<"Raza del perrito: "<<raza;
				gotoxy(4,17);cout<<"Fecha de inscripcion: "<<fecha;
				encontrado=true;
			}
			lectura>>perrito;
		}
		if(!encontrado){
			gotoxy(4,9);cout<<"Perrito no encontrado.";
		}
		lectura.close();
	}
	else{
		archivoNoAbierto();		
	}
	getch();
}

void modificarPaciente(ofstream &escritura,ifstream &lectura){
	lectura.open("Perritos.txt",ios::in);
	if(lectura.is_open()){
		string codigo,perrito,nombreDueno,apellidoDueno,raza,fecha;
		string codAux,perritoAux,nombreAux,apellidoAux,razaAux,fechaAux;
		bool encontrado=false;
		escritura.open("Auxiliar.txt",ios::out);
		transicion(5,23,3,77);
		gotoxy(8,5);cout<<"MODIFICAR DATOS DEL PACIENTE";
		gotoxy(4,7);cout<<"Digite el codigo del perrito a modificar: ";cin>>codAux;
		lectura>>perrito;
		while(!lectura.eof()){
			lectura>>codigo;
			lectura>>nombreDueno;
			lectura>>apellidoDueno;
			lectura>>raza;
			lectura>>fecha;
			if(codigo==codAux){
				encontrado=true;
				gotoxy(4,9);cout<<"Nuevo nombre del perrito: ";cin>>perritoAux;
				gotoxy(4,11);cout<<"Nombre del dueno: ";cin>>nombreAux;
				gotoxy(4,13);cout<<"Apellido del dueno: ";cin>>apellidoAux;
				gotoxy(4,15);cout<<"Raza del perrito: ";cin>>razaAux;
				escritura<<perritoAux<<" "<<codAux<<" "<<nombreAux<<" "<<apellidoAux<<" "<<razaAux<<" "<<fecha<<"\n";
				gotoxy(4,17);cout<<"Datos modificados con exito, presione una tecla para regresar al menu.";
			}
			else{
				escritura<<perrito<<" "<<codigo<<" "<<nombreDueno<<" "<<apellidoDueno<<" "<<raza<<" "<<fecha<<"\n";
			}
			lectura>>perrito;
		}
		lectura.close();
		escritura.close();
		remove("Perritos.txt");
		rename("Auxiliar.txt","Perritos.txt");
		if(!encontrado){
			gotoxy(4,9);cout<<"Perrito no encontrado."<<endl;
		}
	}
	else{
		archivoNoAbierto();
	}
	getch();
}

void eliminarPaciente(ofstream &escritura,ifstream &lectura){
	lectura.open("Perritos.txt",ios::in);
	if(lectura.is_open()){
		string codigo,perrito,nombreDueno,apellidoDueno,raza,fecha;
		string codAux,perritoAux,nombreAux,apellidoAux,razaAux,fechaAux;
		bool encontrado=false;
		escritura.open("Auxiliar.txt",ios::out);
		transicion(5,23,3,77);
		gotoxy(8,5);cout<<"ELIMINE LOS DATOS DEL PACIENTE";
		gotoxy(4,7);cout<<"Digite el codigo del perrito a eliminar: ";cin>>codAux;
		lectura>>perrito;
		while(!lectura.eof()){
			lectura>>codigo;
			lectura>>nombreDueno;
			lectura>>apellidoDueno;
			lectura>>raza;
			lectura>>fecha;
			if(codigo==codAux){
				gotoxy(4,9);cout<<"Registro de paciente eliminado con exito.";
				encontrado=true;
			}
			else{
				escritura<<perrito<<" "<<codigo<<" "<<nombreDueno<<" "<<apellidoDueno<<" "<<raza<<" "<<fecha<<"\n";
			}
			lectura>>perrito;
		}
		lectura.close();
		escritura.close();
		remove("Perritos.txt");
		rename("Auxiliar.txt","Perritos.txt");
		if(!encontrado){
			gotoxy(4,9);cout<<"Perrito no encontrado."<<endl;
		}		
	}
	else{
		archivoNoAbierto();
	}
	getch();
}
//===================================================================================
void menu_adopcion(ofstream &escritura,ifstream &lectura){
	char opcion;
	transicion(5,23,3,77);
	gotoxy(4,5);cout<<"MENU ADOPCION"<<endl;
	gotoxy(4,7);cout<<"[1]: Ingreso nuevo"<<endl;
	gotoxy(4,9);cout<<"[2]: Lista de perros"<<endl;
	gotoxy(4,11);cout<<"[3]: Registrar adopcion"<<endl;
	gotoxy(4,13);cout<<"[4]: Mostrar registros de adopcion"<<endl;
	gotoxy(4,15);cout<<"[5]: Cambio de estado"<<endl;
	gotoxy(4,17);cout<<"[0]: Salir"<<endl;
	
	do{
		gotoxy(4,21);cout<<"Ingrese el numero de la opcion: [ ]"<<"\b\b";
		cin>>opcion;
	}while(opcion!='1' && opcion!='2' && opcion!='3' && opcion!='4' && opcion!='5' && opcion!='0');
	
	switch(opcion){
		case '1':{
			nuevoingreso(escritura,lectura);
			menu_adopcion(escritura,lectura);
			break;
		}
		case '2':{
			lista(lectura);
			menu_adopcion(escritura,lectura);
			break;
		}
		case '3':{
			transicion(5,23,3,77);
			adoptar(escritura,lectura);
			menu_adopcion(escritura,lectura);
			break;
		}
		case '4':{
			transicion(5,23,3,77);
			registro(lectura);
			menu_adopcion(escritura,lectura);
			break;
		}
		case '5':{
			transicion(5,23,3,77);
			cambio(escritura,lectura);
			menu_adopcion(escritura,lectura);
			break;
		}
		case '0':{
			getch();
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

bool cantidad(ifstream &lectura){
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
		}
		else{
			return false;
		}
	}
	else{
		return true;
	}
}

void nuevoingreso(ofstream &escritura,ifstream &lectura){
	int cod=1;
	char opc;
	string nom, edad, tam, raza, ingreso, estado;

	do{
		if(cantidad(lectura)){
		transicion(5,23,3,77);
		gotoxy(30,5);cout<<"NUEVO PERRO"<<endl;
		escritura.open("guarderia.txt",ios::app);
			
		if(escritura.fail()){
			archivoNoAbierto();
			menu_adopcion(escritura,lectura);
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
	getche();
}

void lista(ifstream &lectura){
	int n=9;
	transicion(5,23,3,77);
	lectura.open("guarderia.txt",ios::in);
	if(lectura.is_open()){
		gotoxy(15,5);cout<<"LISTA DE PERROS"<<endl;
		gotoxy(4,7);cout<<"Codigo  Nombre  Edad  Tamano  Raza\t      Fecha       Estado"<<endl;	
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

void adoptar(ofstream &escritura,ifstream &lectura){
	string cod2, nombre,apellido,dni,direc,fecha;
	transicion(5,23,3,77);
	gotoxy(15,5);cout<<"\t\tGENERAR ADOPCION"<<endl<<endl;
	ofstream escribir;
	escribir.open("adopcion.txt",ios::app);
	
	if(escribir.fail()){
		gotoxy(4,7);cout<<"No se pudo abrir el archivo, intentelo de nuevo";
		menu_adopcion(escritura,lectura);
	}
	
	fflush(stdin);
	gotoxy(4,7);cout<<"Nombre del Adoptante: ";getline(cin,nombre);
	gotoxy(4,9);cout<<"apellido: ";getline(cin,apellido);			
	gotoxy(4,11);cout<<"DNI: ";getline(cin,dni);
	gotoxy(4,13);cout<<"Direccion: ";getline(cin,direc);
	eliminar(escritura,lectura);
	fflush(stdin);
	gotoxy(4,17);cout<<"Confirma el Codigo del perro: ";getline(cin,cod2);
	gotoxy(4,19);cout<<"Fecha de adopcion: ";getline(cin,fecha);
	
	escribir<<nombre<<endl;
	escribir<<apellido<<endl;
	escribir<<dni<<endl;
	escribir<<direc<<endl;
	escribir<<cod2<<endl;
	escribir<<fecha<<endl;
	
	escribir.close();		

	getch();
}

void registro(ifstream &lectura){
	transicion(5,23,3,77);
	lectura.open("adopcion.txt",ios::in);
	if(lectura.is_open()){
		gotoxy(18,3);cout<<"VETERINARIA PARA PERROS - HUELLITAS UNIDAS"<<endl;
		gotoxy(15,5);cout<<"REGISTRO DE ADOPCIONES"<<endl<<endl;
	
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
		getch();	
	}
	else{
		gotoxy(4,7);cout<<"Error, No hay Adopciones o el archivo no existe"<<endl;
		getch();
	}
}

void eliminar(ofstream &escritura,ifstream &lectura){
	string codigo, newestado, cod, nom, edad, tam, raza, ingreso, estado;
	lectura.open("guarderia.txt", ios::in); 
	escritura.open("cambio.txt", ios::app);
	gotoxy(4,15);cout<<"Codigo del perro: ";cin>>codigo;
	
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

void cambio(ofstream &escritura,ifstream &lectura){
	transicion(5,23,3,77);
	string codigo, newestado, cod, nom, edad, tam, raza, ingreso, estado;
	lectura.open("guarderia.txt", ios::in); 
	escritura.open("cambio.txt", ios::app);
	gotoxy(4,7);cout<<"Ingresar el codigo del perro --> ";cin>>codigo;
	
	getline(lectura,cod);
	while(!lectura.eof()){
		getline(lectura,nom);
		getline(lectura,edad);
		getline(lectura,tam);
		getline(lectura,raza);
		getline(lectura,ingreso);
		getline(lectura,estado);
		if(cod == codigo){
			gotoxy(4,9);cout<<"Estado-------> "<<estado<<endl;
			gotoxy(4,13);cout<<"Ingresar Nuevo Estado ----> ";
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
	getch();
}

//======================================================================

void menu_servicios(ofstream &escritura,ifstream &lectura){
    char opc;
	
   do{    
	transicion(5,23,3,77);
    gotoxy(15,5);cout<<"SERVICIOS";
    gotoxy(4,7);cout<<"[1]:Banos";
    gotoxy(4,9);cout<<"[2]:Vacunas";
    gotoxy(4,11);cout<<"[3]:Tratamientos";
    gotoxy(4,13);cout<<"[4]:Corte de pelo";
    gotoxy(4,15);cout<<"[5]:Operaciones";
    gotoxy(4,17);cout<<"[6]:Analisis";
    gotoxy(4,19);cout<<"[7]:Boleta";
	gotoxy(4,21);cout<<"[8]:Citas";
    gotoxy(4,23);cout<<"[0]:Salir";
    

        gotoxy(4,25);cout<<"Ingrese el numero de la opcion: [ ]"<<"\b\b";
        cin>>opc;
        if(opc!='1' and opc!='2' and opc!='3' and opc!='4' and opc!='5' and opc!='6' and opc!='7' and opc!='8' and opc!='0'){
        	gotoxy(4,27);cout<<"Error, presione una tecla para volver a intentarlo";
        	getch();
        }
	}
    while(opc!='1' and opc!='2' and opc!='3' and opc!='4' and opc!='5' and opc!='6' and opc!='7' and opc!='8' and opc!='0');
    switch (opc){

        case '1':{
            datos[0]=bano();
            menu_servicios(escritura,lectura);
            break;
		}
        case '2':{
            datos[1]=vacunas();
			transicion(5,23,3,77);
            menu_servicios(escritura,lectura);
            break;
		}
        case '3':{
            datos[2]=tratamientos(escritura,lectura);
            menu_servicios(escritura,lectura);
            break;
		}
        case '4':{
            datos[3]=corte();
            menu_servicios(escritura,lectura);
            break;
		}
        case '5':{
            datos[4]=operaciones(escritura,lectura);
            menu_servicios(escritura,lectura);
            break;
		}
        case '6':{
            datos[5]=analisis(escritura,lectura);
            menu_servicios(escritura,lectura);
            break;
		}
		case '7':{
			boleta(datos);
			menu_servicios(escritura,lectura);
		}
		case '8':{
			menuCitas(escritura,lectura);
			menu_servicios(escritura,lectura);
		}
        case '0':{
			transicion(5,23,3,77);
			menu_principal(escritura,lectura);
            getch();
            break;
		}
    }
    
}
int bano(){
	char tamano;
	int preciobano=0;
	do{
	transicion(5,23,3,77);
	gotoxy(15,5);cout<<"BANO";
	gotoxy(4,7);cout<<"[1]. PequeÃ±o					s/20 ";
	gotoxy(4,9);cout<<"[2]. Mediano					s/30 ";
	gotoxy(4,11);cout<<"[3]. Grande						s/40 ";
    gotoxy(4,13);cout<<"[0]. Salir ";	

 
		gotoxy(4,17);cout<<"Ingrese el numero de la opcion: [ ]"<<"\b\b";
		cin>>tamano;
        if(tamano!='0'&&tamano!='1'&&tamano!='2'&&tamano!='3'){
        	gotoxy(4,27);cout<<"Error, presione una tecla para volver a intentarlo";
        	getch();
        }
	}while(tamano!='0'&&tamano!='1'&&tamano!='2'&&tamano!='3');	
	
	switch(tamano){
		case '1': preciobano=20;
			confirmacion();
			break;
		case '2': preciobano=30;
			confirmacion(); 
			break;
		case '3': preciobano=40;
			confirmacion();
			break;
		case '0': break;
			}	
			getch();
	return preciobano;
}

int vacunas(){
	char op,opc2;
    int vac[7]={0,0,0,0,0,0,0}, total_vacuna=0;

    do{
	transicion(5,23,3,77);
	gotoxy(15,5);cout<<"VACUNAS";
	gotoxy(4,7);cout<<"[1] Distemper          s/80";
	gotoxy(4,9);cout<<"[2] Parvovirus         s/90 ";
	gotoxy(4,11);cout<<"[3] Hepatitis          s/70";	
	gotoxy(4,13);cout<<"[4] Coronavirosis      s/70";
	gotoxy(4,15);cout<<"[5] Parainfluencia     s/60";		
	gotoxy(4,17);cout<<"[6] Leptospirosis      s/60";
	gotoxy(4,19);cout<<"[7] Rabia              s/40";
    gotoxy(4,21);cout<<"[0] Salir";

	do{
		gotoxy(4,23);cout<<"Ingrese el numero de la opcion: [ ]"<<"\b\b";
		cin>>op;
	}while(op!='0' && op!='1'&& op!='2'&& op!='3'&&op!='4' &&op!='5'&&op!='6'&&op!='7');
    
    switch (op){
        case '1': vac[0]=80 ; break;
        
        case '2': vac[1]=90 ; break;
        
        case '3': vac[2]=70 ; break;
        
         case '4': vac[3]=70; break;
        
        case '5': vac[4]=60; break;
        
         case '6': vac[5]=60; break;
        
         case '7': vac[6]=40; break;
        
         case '0':  break; 
		 
        system("pause");
    }
    
	if(op!='0'){
		gotoxy(4,25);cout<<"Desea agregar otra vacuna? (S/N): "; cin>>opc2;
	}
	else{
		opc2='n';
	}
    }while(opc2=='s' || opc2=='S');

    for(int i=0; i<7; i++){
        total_vacuna+=vac[i];
    }
	return total_vacuna;
}

int tratamientos(ofstream &escritura,ifstream &lectura){
	char opc,desparacitacion,opantipulgas;
    int preciodesparacitacion=0,precioantipulgas=0,total=0;
   
	do{ 
    transicion(5,23,3,77);
	gotoxy(15,5);cout<<"TRATAMIENTOS";
	gotoxy(4,7);cout<<"[1] Desparacitacion";
	gotoxy(4,9);cout<<"[2] Antipulgas ";
    gotoxy(4,11);cout <<"[0] Salir";

	do{
		gotoxy(4,15);cout<<"Ingrese el numero de la opcion: [ ]"<<"\b\b";
		cin>>opc;
	}while(opc!='0' && opc!='1' && opc!='2');
	
	switch(opc){
		case '1': {
			transicion(5,23,3,77);
			gotoxy(15,5);cout<<"DESPARACITACION";
			gotoxy(4,7);cout<<"[1] Inyeccion          s/20";
			gotoxy(4,9);cout<<"[2] Pastilla           s/15";	
			gotoxy(4,11);cout<<"[0] Salir ";

				do{
					gotoxy(4,13);cout<<"Ingrese el numero de la opcion: [ ]"<<"\b\b";
					cin>>desparacitacion;
				}while(desparacitacion!='0' && desparacitacion!='1' && desparacitacion!='2');
				
				switch(desparacitacion){
					case '1': {
						preciodesparacitacion=20;
						confirmacion();
						break;
					}
			
					case '2':{
						preciodesparacitacion=15;
						confirmacion();						
						break;
					}
					case '0':
						tratamientos(escritura,lectura);
					}
					getch();
			break;

		}
		
		case '2':{
			transicion(5,23,3,77);
			gotoxy(15,5);cout<<"ANTIPULGAS";
			gotoxy(4,7);cout<<"[1] Pipetas            s/15";
			gotoxy(4,9);cout<<"[2] Pastilla           s/20 ";		
			gotoxy(4,11);cout<<"[3] Inyeccion          s/25";	
			gotoxy(4,13);cout<<"[0] Salir ";

			do{
				gotoxy(4,15);cout<<"Ingrese el numero de la opcion: [ ]"<<"\b\b";
				cin>>opantipulgas;
			}while(opantipulgas!='0' && opantipulgas!='1' && opantipulgas!='2'&& opantipulgas!='3');
	
			switch(opantipulgas){
					case '1': precioantipulgas=15;
					break;
					case '2': precioantipulgas=20;
					break;
					case '3': precioantipulgas=25;
					break;
					case '0': tratamientos(escritura,lectura);
				}
			if(opantipulgas!=0){
				confirmacion();
			}				
			getch();
			break;
		}
		case '0': menu_servicios(escritura,lectura);
		}
    }while(desparacitacion!='0');
	total=preciodesparacitacion+precioantipulgas;
	return total;
    }

int corte(){
	char op;
	int preciocorte=0;
	transicion(5,23,3,77);
	gotoxy(15,5);cout<<"CORTE DE PELO";
	gotoxy(4,7);cout<<"[1] Corte leon				s/40 ";
	gotoxy(4,9);cout<<"[2] Corte Ingles				s/45 ";
	gotoxy(4,11);cout<<"[3] Corte Holandes		   	s/40 ";
	gotoxy(4,13);cout<<"[4] Corte Moderno			s/45 ";
	gotoxy(4,15);cout<<"[5] Corte de cachorro		s/25 ";
	gotoxy(4,17);cout<<"[6] Corte de verano		    s/35 ";
	gotoxy(4,19);cout <<"[0] Salir";

	do{
		gotoxy(4,21);cout<<"Ingrese el numero de la opcion: [ ]"<<"\b\b";
		cin>>op;
	}while(op!='0' && op!='1'&& op!='2'&& op!='3'&&op!='4' &&op!='5'&&op!='6');
	
    switch(op){
		case '1':{
			preciocorte=40;	
			break;
		}
		case '2':{
			preciocorte=45;		
			break;
		}
		case '3':{
			preciocorte=40;			
			break;
		}
		case '4':{
			preciocorte=45;		
			break;
		}
		case '5':{
			preciocorte=25;		
			break;
		}
		case '6':{
			preciocorte=35;		
			break;
		}
		case '0':
			break;
	} 
		if(preciocorte!=0){
			confirmacion();
	}
	getch();
	return preciocorte;
}

int operaciones(ofstream &escritura,ifstream &lectura){
	char opc, confirm;
	int precio;
	string operacion;
	ofstream Esc;
	ofstream add;
	do{
		transicion(5,23,3,77);
		gotoxy(15,5);cout<<"OPERACIONES";
		gotoxy(4,9);cout<<"[1] Esterilizaciones    	 S/200"<<endl;
		gotoxy(4,11);cout<<"[2] Oftalmologia          S/250"<<endl;
		gotoxy(4,13);cout<<"[3] Maxilofacial          S/200"<<endl;
		gotoxy(4,15);cout<<"[4] Abdominal             S/300"<<endl;
		gotoxy(4,17);cout<<"[5] Oncologica            S/400"<<endl;
		gotoxy(4,19);cout<<"[6] Reconstructiva        S/500"<<endl;
		gotoxy(4,21);cout<<"[7] Urgencias             S/400"<<endl;
		gotoxy(4,23);cout<<"[0] Salir"<<endl;
		gotoxy(4,25);cout<<"Ingrese el numero de la opcion: [ ]"<<"\b\b";
		cin>>opc;
		if(opc!='0' && opc!='1'&& opc!='2'&& opc!='3'&&opc!='4' &&opc!='5'&&opc!='6'&&opc!='7'){
			gotoxy(4,27);cout<<"Opcion equivocada. Intente de nuevo...";getch;
		}
    } while(opc!='0' && opc!='1'&& opc!='2'&& opc!='3'&&opc!='4' &&opc!='5'&&opc!='6'&&opc!='7');
			
	switch(opc){
		case '1': gotoxy(4,27);cout<<"\nEsterilizaciones"<<endl;
		  	precio=200;
		  	operacion="Esterilizacion";
		break;
		case '2': gotoxy(4,27);cout<<"\nOftalomologica"<<endl;
			precio=250;
			operacion="Oftamologia";
		break;
		case '3': gotoxy(4,27);cout<<"\nMaxilofacial"<<endl;
			precio=200;
			operacion="Maxilofacial";
		break;
		case '4': gotoxy(4,27);cout<<"\nAbdominal"<<endl;
			precio=300;
			operacion="Abdominal";
		break;
		case '5': gotoxy(4,27);cout<<"\nOncologica"<<endl;
			precio=400;
			operacion="Oncología";
		break;
		case '6': gotoxy(4,27);cout<<"\nReconstructiva"<<endl;
			precio=500;
			operacion="Reconstrucción";
		break;
		case '7': gotoxy(4,27);cout<<"\nUrgencias"<<endl;
			precio=400;
			operacion="Urgencias";
		break;
		case '0': break;
	}
	if(opc !='0'){
		agregarCita(add,lectura);
	}
	return precio;
}
//cuando escribes un digito que no esta en las opciones de anÃ¡lisis no se borra
int analisis(ofstream &escritura,ifstream &lectura){
	char m,p,p2,m2;
    int analisis[5]={0,0,0,0,0},totalanalisis=0,descarte[3]={0,0,0},sumadescart=0,general[3]={0,0,0},sumageneral=0;
	do{
	do{
    transicion(5,23,3,77);
	gotoxy(15,5);cout<<"ANALISIS";
	gotoxy(4,7);cout<<"[1] Chequeo preoperatorio       S/80";
	gotoxy(4,9);cout<<"[2] Descarte de enfermedades"<<endl;
	gotoxy(4,11);cout<<"[3] Radiografias                S/100";
	gotoxy(4,13);cout<<"[4] Tomografias                 S/100";
	gotoxy(4,15);cout<<"[5] General";
	gotoxy(4,17);cout<<"[0] Volver";
	gotoxy(5,19);cout<<"Ingrese el numero de la opcion: [ ]"<<"\b\b";
	cin>>m;
    }while(m!='0' && m!='1'&& m!='2'&& m!='3'&&m!='4' &&m!='5');

		switch (m){
			case '1': 
			gotoxy(5,21);cout<<"Chequeo preoperatorio"<<endl;
				analisis[0]=80;
			
			break;
			
			case '2':{
			transicion(5,23,3,77);
			do{
			gotoxy(15,5);cout<<"Descarte de enfermedades";
			gotoxy(4,7);cout<<"[1] Distemper y Parvovirus   S/100";
			gotoxy(4,9);cout<<"[2] Leptospirosis            S/80";
			gotoxy(4,11);cout<<"[3] Micoplasmosis            S/80";
			gotoxy(4,13);cout<<"[0] Volver";
            do{
               gotoxy(4,15);cout<<"Ingrese el numero de la opcion: [ ]"<<"\b\b";
			cin>>p; 
            }while(p!='0' && p!='1'&& p!='2'&& p!='3');
			
			switch(p){
				case '1': {
					gotoxy(4,17);cout<<"Distemper y Parvovirus";
					descarte[0]=100;
					break;
				}
				
				case '2': {
					gotoxy(4,17);cout<<"Leptospirosis";
					descarte[1]=80;
					break;
				}
				
				case '3': {
					gotoxy(4,17);cout<<"Micoplasmosis";
					descarte[2]=80;
					break;
				}
				
				case '0':  
				break;
			}
			gotoxy(5,19);cout<<"¿Desea agregar otro descarte? (S/N): ";cin>>p2;
			}while(p2=='s'|| p2=='S');
			for(int i=0; i<3;i++){
				sumadescart+=descarte[i];
			}
			analisis[1]=sumadescart;
			break;
			}
			case '3': {
                gotoxy(5,21);cout<<"Radiografia";
			    	analisis[2]=400;
				;
				break;  
            }

			case '4':{
                gotoxy(5,21);cout<<"Tomografia";
			    	analisis[3]=400;
				
            break;
            }

			case '5': {
				transicion(5,23,3,77);
                gotoxy(15,5);cout<<"Analisis General";
                gotoxy(4,7);cout<<"[1] De sangre    S/100";
                gotoxy(4,9);cout<<"[2] Fisico       S/120";
                gotoxy(4,11);cout<<"[3] Ambos        S/210";
                gotoxy(4,13);cout<<"[0] Volver";
                do{
                gotoxy(4,15);cout<<"Ingrese el numero de la opcion: [ ]"<<"\b\b";
                    cin>>p; 
                }while(p!='0' && p!='1'&& p!='2'&& p!='3');

                switch(p){
                    case '1': {
                    	gotoxy(4,15);cout<<"Analisis de sangre"<<endl;
                    	analisis[4]=100;
                	
						break;
					}
                    case '2': {
                    	gotoxy(4,15);cout<<"Analisis fisico"<<endl;
                    	analisis[4]=120;
                		
						break;
					}
                    case '3': {
                    	gotoxy(4,15);cout<<"Analisis de sangre y fisico"<<endl;
                    	analisis[4]=210;
                		
						break;
					}
                    case '0': m2='N'; 
					break;
                }
				if(p2 !=0){
					menuCitas(escritura,lectura);
				}
			break;  
            }
			
			case '0':{
                menu_servicios(escritura,lectura);
            break;
            }
		}
	if(m2!='N'){
		gotoxy(4,22);cout<<"¿Desea agregar otro analisis? (S/N): ";cin>>m2;			
	}
	}while(m2=='s'|| m2=='S');
	
	for(int i=0; i<5; i++){
		totalanalisis+=analisis[i];
	}
	return totalanalisis;
}

void boleta(int vec[]){
	int total;
	transicion(5,23,3,77);
	gotoxy(4,5);cout<<"\t\tBOLETA DE PAGO"<<endl;
	if(vec[0]>0){
		cout<<"\n\n\tBanos -----------------"<<vec[0]<<endl;
	}
	if(vec[1]>0){
		cout<<"\n\tVacunas ----------------"<<vec[1]<<endl;
	}
	if(vec[2]>0){
		cout<<"\n\tTratamientos -----------"<<vec[2]<<endl;
	}
	if(vec[3]>0){
		cout<<"\n\tCorte de Pelo ----------"<<vec[3]<<endl;
	}
	if(vec[4]>0){
		cout<<"\n\tOperaciones ------------"<<vec[4]<<endl;
	}
	if(vec[5]>0){
		cout<<"\n\tAnalisis ---------------"<<vec[5]<<endl;
	}	
	
	total=vec[0]+vec[1]+vec[2]+vec[3]+vec[4]+vec[5];
	
	cout<<"\n\n\tTotal a pagar: "<<total;
	getch();
}
//===========================================================================================

void agregarCita(ofstream &add, ifstream &lectura){ //que indique para que es la cita ***********************
	string cod;
	string tipo;
	string fecha;
	string hora;

	add.open("Citas.txt", ios::out|ios::app);
	
	do{
		transicion(5,23,3,77);
		gotoxy(7,5);cout<<"GENERAR CITA";
		gotoxy(4,7);cout<<"Codigo de cliente: "; cin>>cod;
		if(!verificarCodigo(cod,lectura)){
			gotoxy(4,9);cout<<"El codigo ingresado no existe, intente de nuevo";
			getch();
		}
	}while(!verificarCodigo(cod,lectura));
	 
	gotoxy(4,9);cout<<"Operacion: "; cin>>tipo;	
	gotoxy(4,13);cout<<"Fecha: "; cin>>fecha;
	gotoxy(4,15);cout<<"Hora: "; cin>>hora;

	add<<cod<<" "<<tipo<<" "<<fecha<<" "<<hora<<" "<<"\n";
	add.close();
}

void verCita(ifstream &Lec){
	string cod;
	string tipo;
	string fecha;
	string hora;
	Lec.open("Citas.txt", ios::in); 
	Lec>>cod;
	while(!Lec.eof()){
		Lec>>tipo;
		Lec>>fecha;
		Lec>>hora;
		transicion(5,23,3,77);
		gotoxy(15,5);cout<<"CITA PARA"<<tipo<<endl;
		gotoxy(4,7);cout<<"Codigo de cliente: "<<cod<<endl;
		gotoxy(4,9);cout<<"Fecha: "<<fecha<<endl;
		gotoxy(4,11);cout<<"Hora: "<<hora<<endl;

		gotoxy(4,17);cout<<"Presione una tecla para continuar...";
			getch();
		Lec>>cod;
	}
	Lec.close();
	system("pause");
}

void buscarCita(ifstream &Lec){
	transicion(5,23,3,77);
	Lec.open("Citas.txt", ios::in);
	string cod;
	string tipo;
	string fecha;
	string hora;
	string codaux;
	bool encontrado=false;
	gotoxy(7,5);cout<<"CITAS REGISTRADAS";
	gotoxy(4,7);cout<<"El codigo del cliente: "; cin>>codaux;
	Lec>>cod;
	while(!Lec.eof() && !encontrado){
		Lec>>tipo;
		Lec>>fecha;
		Lec>>hora;
		if(cod==codaux){
		gotoxy(4,11);cout<<"Codigo del paciente: "<<cod;
		gotoxy(4,13);cout<<"Tipo de operacion: "<<tipo;
		gotoxy(4,17);cout<<"Fecha: "<<fecha;
		gotoxy(4,19);cout<<"Hora: "<<hora;

		encontrado=true;
		}
		Lec>>cod;
	}
	Lec.close();
	if(!encontrado){
		errorOpcionIngresada();
	}
	getch();
}

void modificarCita(ofstream &escritura,ifstream &lectura){
	transicion(5,23,3,77);
	string cod;
	string tipo;
	string fecha;
	string hora;
	string codaux;
	string fechaaux;
	lectura.open("citas.txt", ios::in);
	ofstream aux("auxiliar.txt", ios::out);
	if (lectura.is_open()){
		gotoxy(15,5);cout<<"CAMBIO DE FECHA";
		gotoxy(4,7);cout<<"Codigo de cliente: "; cin>>codaux;
		
		lectura>>cod;		
		while(!lectura.eof()){
			lectura>>tipo;
			lectura>>fecha;
			lectura>>hora;

			if(cod==codaux){
				gotoxy(4,9);cout<<"Digite nueva fecha: "; cin>>fechaaux;
				aux<<cod<<" "<<tipo<<" "<<fechaaux<<" "<<hora<<" "<<"\n";
			}
			else{
				aux<<cod<<" "<<tipo<<" "<<fecha<<" "<<hora<<" "<<"\n";
				gotoxy(4,9);cout<<"DNI no econtrado";
				getch();
				menuCitas(escritura,lectura);
				}
			lectura>>cod;
		}
		
		lectura.close();
		aux.close();
		}
		else{
			archivoNoAbierto();
		}
		remove("citas.txt");
		rename("auxiliar.txt", "citas.txt");
		getch();
	}

void eliminarCita(ifstream &Lectura,ofstream &escritura){
	transicion(5,23,3,77);
	string cod;
	string tipo;
	string fecha;
	string hora;
	string codaux;
	string fechaaux;
	Lectura.open("citas.txt", ios::in);
	ofstream aux("auxiliar.txt", ios::out);
	if (Lectura.is_open()){
		gotoxy(15,5);cout<<"ELIMINAR CITA";
		gotoxy(4,7);cout<<"Código del paciente: "; cin>>codaux;
		Lectura>>cod;
		while(!Lectura.eof()){
			Lectura>>tipo;
			Lectura>>fecha;
			Lectura>>hora;
			if(cod==codaux){
				gotoxy(4,11);cout<<"Eliminado ok.\n";
				Sleep(1500);
			}
			else{
				aux<<cod<<" "<<tipo<<" "<<fecha<<" "<<hora<<" "<<"\n";
				gotoxy(4,9);cout<<"DNI no econtrado";
				getch();
				menuCitas(escritura,Lectura);
			}
			Lectura>>cod;
		}
		Lectura.close();
		aux.close();	
		}
		else{
			archivoNoAbierto();
		}
		remove("citas.txt");
		rename("auxiliar.txt", "citas.txt");
		getch();
	}


void menuCitas(ofstream &escritura,ifstream &lectura){
	char x;
	transicion(5,23,3,77);
	do{
		gotoxy(15,5);cout<<"CITAS"<<endl<<endl;
		gotoxy(4,7);cout<<"[1] Programar cita"<<endl;
		gotoxy(4,9);cout<<"[2] Ver citas"<<endl;
		gotoxy(4,11);cout<<"[3] Buscar personas"<<endl;
		gotoxy(4,13);cout<<"[4] Modificar cita"<<endl;
		gotoxy(4,15);cout<<"[5] Eliminar cita"<<endl;
		gotoxy(4,17);cout<<"[6] Salir"<<endl;
		gotoxy(4,19);cout<<"Opcion: "; cin>>x;

	}while(x!='1' && x!='2' && x!='3' && x!='4' && x!='5' && x!='0');
	
	ofstream Esc;//para grabar datos
	ifstream Lee; //para leer datos

	switch(x){
		case '1': 
			agregarCita(Esc,lectura);
			break;
		
		case '2':
			verCita(Lee);
			break;
		
		case '3':
			buscarCita(Lee);
			break;
		
		case '4':
			modificarCita(escritura,lectura);
			break;
		
		case '5':
			eliminarCita(lectura,escritura);
			break;
	}
}

//============================================================================================

void menuVentaDeArticulos(ofstream &escritura,ifstream &lectura){
	char opc;
	do{
		do{
			transicion(5,23,3,77);
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
	while(!lectura.eof()&&!encontrado){
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
		if(nombreProducto==nombreProductoBuscado){
			cantidadAux=cantidadProducto+cantidadAdicional;
			escritura<<nombreProducto<<endl;
			escritura<<cantidadAux<<endl;
			escritura<<precioProducto<<endl;
		}
		else{
			escritura<<nombreProducto<<endl;
			escritura<<cantidadProducto<<endl;
			escritura<<precioProducto<<endl;
		}
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
	transicion(5,23,3,77);
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
		transicion(5,23,3,77);
		gotoxy(33,5);cout<<"BUSCAR PRODUCTO";
		gotoxy(4,7);cout<<"Ingrese el nombre del producto: ";cin>>nombreProductoBuscado;
		getline(lectura,nombreProducto);
		while(!encontrado&&!lectura.eof()){
			lectura>>cantidadProducto;
			lectura>>precioProducto;
			if(nombreProducto==nombreProductoBuscado){
				transicion(5,23,3,77);
				gotoxy(31,5);cout<<"PRODUCTO ENCONTRADO";
				gotoxy(4,7);cout<<"Nombre: "<<nombreProducto;
				gotoxy(4,9);cout<<"Cantidad de productos: "<<cantidadProducto;
				gotoxy(4,11);cout<<"Precio: S/."<<precioProducto;
				encontrado=true;
			}
			getline(lectura,espacio);
			getline(lectura,nombreProducto);
		}
		if(!encontrado){
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
			transicion(5,23,3,77);
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
	while(!lectura.eof()&&!encontrado){
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
		transicion(5,23,3,77);
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
				gotoxy(4,15);cout<<"¿Desea agregar otro producto? (S:Si|N:No): ";cin>>otroProducto;
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
	transicion(5,23,3,77);
	gotoxy(3,13);cout<<"Opcion no valida, presione una tecla para volver a intentarlo.";
	getch();
}

void confirmacion(){
	transicion(5,23,3,77);
	gotoxy(3,13);cout<<"Registro exitoso, presione una tecla para regresar al menu.";
	getch();
}

void archivoNoAbierto(){
	transicion(5,23,3,77);
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