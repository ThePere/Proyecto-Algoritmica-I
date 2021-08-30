#include <iostream>
#include <conio.h>
#include <windows.h>
#include <string.h>
#include <stdlib.h>
#include <fstream>
#include <locale.h> 

using namespace std;

void menu_principal(ofstream &,ifstream &);
void servicios();
void adopciones();
void ventaArticulos();
void transicion();

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
void menuCitas();
void agregar(ofstream &);
void verCitas(ifstream &);
void buscarPersona(ifstream &);
void modificar(ifstream &);
void eliminar(ifstream &);



void menuVentaDeArticulos();
bool verificarProducto(string,ifstream &,float &,int &);
void buscarProductosEnSistema(ifstream &);
void agregarProducto(ofstream &,ifstream &);
void modificarCantidadProducto(ifstream &,string,int);
void generarCompra(ifstream &);

void errorOpcionIngresada();
void confirmacion();
void archivoNoAbierto();
void gotoxy(int x, int y); //Sirv para manipular la ubicaci?n de los caracteres
void dibujarCuadrado(int x1,int y1,int x2,int y2);
void menuPacientes(ofstream &,ifstream &);

int datos[6]={0,0,0,0,0,0};


int main(){
	setlocale(LC_ALL, "Spanish"); //llamada a la librerÃ­a locale.h, el "ALL" indica que queremos adaptar nuestro programa a todos los parametros locales 
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
		gotoxy(4,5);cout<<"MENÃš PRINCIPAL"<<endl;
	    gotoxy(4,7);cout<<"[1] Pacientes";
	    gotoxy(4,9);cout<<"[2] Servicios";
	    gotoxy(4,11);cout<<"[3] Adopciones";
	    gotoxy(4,13);cout<<"[4] Venta de artÃ­culos";
	    gotoxy(4,15);cout<<"[0] Salir";
	    gotoxy(4,19);cout<<"Digite una opciÃ³n: ";
	    cin>>opc;
	    transicion();
        if(opc!='1' and opc!='2' and opc!='3' and opc!='4' and opc!='0'){
        	errorOpcionIngresada();
        	getch();
        	transicion();
		}
		cin.ignore();
    }while(opc!='1' and opc!='2' and opc!='3' and opc!='4' and opc!='0');
    
   	switch (opc){
   		case '1':{
   			menuPacientes(escritura,lectura);
			transicion();
   			menu_principal(escritura,lectura);
			break;
	   	}
		case '2':{
			menu_servicios(escritura,lectura);
			transicion();
			menu_principal(escritura,lectura);
			break;
		}
		case '3':{
			menu_adopcion(escritura,lectura);
			transicion();
			menu_principal(escritura,lectura);
			break;
		}
		case '4':{
			menuVentaDeArticulos();
			transicion();
			menu_principal(escritura,lectura);
			break;
		}
		case '0':{
			transicion();
			gotoxy(3,11);cout<<"Â¡Gracias por visitar a la Veterinaria Huellitas Unidas! :'D";
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
			transicion();
			gotoxy(15,5);cout<<"PACIENTES"<<endl;
			gotoxy(4,7);cout<<"[1] Ingresar nuevo paciente.";
			gotoxy(4,9);cout<<"[2] Ver pacientes.";
			gotoxy(4,11);cout<<"[3] Buscar paciente existente.";
			gotoxy(4,13);cout<<"[4] Modificar paciente.";
			gotoxy(4,15);cout<<"[5] Eliminar paciente.";
			gotoxy(4,17);cout<<"[0] Volver al menciÃ³n principal.";
			gotoxy(4,19);cout<<"Ingrese una opciÃ³n: ";cin>>opc;

		}
		while(opc!='1' && opc!='2' && opc!='3' && opc!='4' && opc!='5' && opc!='0');
		switch(opc){
			case '1':	agregarPaciente(escritura,lectura);break;
			case '2':	verPaciente(lectura);break;
			case '3':	buscarPaciente(lectura);break;
			case '4':	modificarPaciente(escritura,lectura);break;
			case '5':	eliminarPaciente(escritura,lectura);break;
		}
	}
	while(opc!='0');
}

void agregarPaciente(ofstream &escritura,ifstream &lectura){
	string codigo;
	escritura.open("Perritos.txt",ios::out|ios::app);
	transicion();
	gotoxy(7,5);cout<<"REGISTRE A SU MASCOTA";
	fflush(stdin);
	gotoxy(4,7);cout<<"Codigo de la mascota: ";getline(cin,codigo);
	fflush(stdin);
	if(verificarCodigo(codigo,lectura)){
		gotoxy(7,9);cout<<"--------CÃ³digo ya en uso--------";
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
			transicion();
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
		transicion();
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
				transicion();
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
		transicion();
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
		transicion();
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
	transicion();
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
			transicion();
			adoptar(escritura,lectura);
			menu_adopcion(escritura,lectura);
			break;
		}
		
		case '4':{
			transicion();
			registro(lectura);
			menu_adopcion(escritura,lectura);
			break;
		}
		
		case '5':{
			transicion();
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
		transicion();
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
		gotoxy(4,7);cout<<"Nombre: ";getline(cin,nom);
		gotoxy(4,9);cout<<"Edad: ";getline(cin,edad);			
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
	transicion();
	lectura.open("guarderia.txt",ios::in);
	if(lectura.is_open()){
		gotoxy(15,5);cout<<"LISTA DE PERROS"<<endl;
		gotoxy(4,7);cout<<"Codigo  Nombre  Edad  TamaÃ±o  Raza\t      Fecha       Estado"<<endl;	
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
	transicion();
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
	transicion();
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
			transicion();
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
	transicion();
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
	transicion();
    gotoxy(15,5);cout<<"SERVICIOS";
    gotoxy(4,7);cout<<"[1]:BaÃ±os";
    gotoxy(4,9);cout<<"[2]:Vacunas";
    gotoxy(4,11);cout<<"[3]:Tratamientos";
    gotoxy(4,13);cout<<"[4]:Corte de pelo";
    gotoxy(4,15);cout<<"[5]:Operaciones";
    gotoxy(4,17);cout<<"[6]:AnÃ¡lisis";
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

        case '1':
            datos[0]=bano();
            menu_servicios(escritura,lectura);
			
            break;
        
        case '2':
            datos[1]=vacunas();
			transicion();
            menu_servicios(escritura,lectura);
            break;
        
        case '3':
            datos[2]=tratamientos(escritura,lectura);
            menu_servicios(escritura,lectura);
            break;
        
        case '4':
            datos[3]=corte();
            menu_servicios(escritura,lectura);
            break;
        
        case '5':
            datos[4]=operaciones(escritura,lectura);
            menu_servicios(escritura,lectura);
            break;

        case '6':
            datos[5]=analisis(escritura,lectura);
            menu_servicios(escritura,lectura);
            break;
		
		case '7':
			boleta(datos);
			menu_servicios(escritura,lectura);

		case '8':
			menuCitas();
			menu_servicios(escritura,lectura);
			
        case '0':
			transicion();
			menu_principal(escritura,lectura);
            getch();
            break;
    }
    
}
int bano(){
	char tamano;
	int preciobano=0;
	do{
	transicion();
	gotoxy(15,5);cout<<"BAÃ‘O";
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
	transicion();
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
    transicion();
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
			transicion();
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
			transicion();
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
	transicion();
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
    transicion();
	gotoxy(15,5);cout<<"OPERACIONES";
	gotoxy(4,7);cout<<"Tiene chequeo preoperatorio?(s:si  n:no): ";
	
	do{
		gotoxy(44,7);cout<<"[ ]"<<"\b\b";
		cin>>confirm;
	}while(confirm!='s' && confirm!='n' );
	
	if(confirm=='n'||confirm=='N'){
		analisis(escritura,lectura);
	}
	do{
		transicion();
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
			gotoxy(4,27);cout<<"Opcion equivocada, Intente de nuevo...";getch;
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
		agregar(add);
	}
	return precio;
}
//cuando escribes un digito que no esta en las opciones de anÃ¡lisis no se borra
int analisis(ofstream &escritura,ifstream &lectura){
	char m,p,p2,m2;
    int analisis[5]={0,0,0,0,0},totalanalisis=0,descarte[3]={0,0,0},sumadescart=0,general[3]={0,0,0},sumageneral=0;
	do{
	do{
    transicion();
	gotoxy(15,5);cout<<"ANALISIS";
	gotoxy(4,7);cout<<"[1] Chequeo preoperatorio       S/80";
	gotoxy(4,9);cout<<"[2] Descarte de enfermedades"<<endl;
	gotoxy(4,11);cout<<"[3] Radiografias                S/100";
	gotoxy(4,13);cout<<"[4] Tomografias                 S/100";
	gotoxy(4,15);cout<<"[5] General.";
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
			transicion();
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
					//	cita();
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
				transicion();
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
					menuCitas();
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
	transicion();
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

void agregar(ofstream &add){ //que indique para que es la cita ***********************
	transicion();
	string nom;
	string nomperrito;
	string dni;
	string fecha;
	string hora;

	add.open("Citas.txt", ios::out|ios::app);
	gotoxy(7,5);cout<<"GENERAR CITA";
	gotoxy(4,7);cout<<"Nombre del dueño: "; cin>>nom; //nomDueno
	gotoxy(4,9);cout<<"Nombre del perrito: "; cin>>nomperrito;	//perrito
	gotoxy(4,11);cout<<"DNI "; cin>>dni;
	gotoxy(4,13);cout<<"Fecha: "; cin>>fecha;
	gotoxy(4,15);cout<<"Hora: "; cin>>hora;


	add<<nom<<" "<<dni<<" "<<fecha<<" "<<hora<<" "<<"\n";
	add.close();
}

void verCitas(ifstream &Lec){
	string nom;
	string nomperrito;
	string dni;
	string fecha;
	string hora;

	string operacion;
	Lec.open("Citas.txt", ios::in); //para archivos de lectura
	Lec>>nom;
	while(!Lec.eof()){
		
		Lec>>nomperrito;
		Lec>>dni;
		Lec>>fecha;
		Lec>>hora;

		transicion();
		gotoxy(15,5);cout<<"CITA PARA"<<operacion<<endl;
		gotoxy(4,7);cout<<"Nombre del dueño: "<<nom<<endl;
     	gotoxy(4,9);cout<<"Nombre del perrito: "<<nomperrito;			
		gotoxy(4,11);cout<<"DNI "<<dni<<endl;
		gotoxy(4,13);cout<<"Fecha: "<<fecha<<endl;
		gotoxy(4,15);cout<<"Hora: "<<hora<<endl;

		gotoxy(4,21);cout<<"Presione una tecla para continuar...";
			getch();
		Lec>>nom;
	}
	Lec.close();
	system("pause");
}

void buscarPersona(ifstream &Lec){
	transicion();
	Lec.open("Citas.txt", ios::in);
	string nom,nomperrito, dni,fecha, hora, doctor, dniaux;
	bool encontrado=false;
	gotoxy(7,5);cout<<"CITAS REGISTRADAS";
	gotoxy(4,7);cout<<"Digite el dni: "; cin>>dniaux;
	Lec>>nom;
	while(!Lec.eof() && !encontrado){
		Lec>>nomperrito;
		Lec>>dni;
		Lec>>fecha;
		Lec>>hora;
		Lec>>doctor;
		if(dni==dniaux){
		gotoxy(4,11);cout<<"Nombre del dueño: "<<nom;
		gotoxy(4,13);cout<<"Nombre del perrito: "<<nom;
		gotoxy(4,15);cout<<"DNI "<<dni;
		gotoxy(4,17);cout<<"Fecha: "<<fecha;
		gotoxy(4,19);cout<<"Hora: "<<hora;

		encontrado=true;
		}
		Lec>>nom;
	}
	Lec.close();
	if(!encontrado){
		errorOpcionIngresada();
	}
	getch();
}

void modificar(ifstream &Lec){
	transicion();
	string nom;
	string nomperrito;
	string dni;
	string fecha;
	string hora;

	string dniaux;
	string fechaaux;
	Lec.open("citas.txt", ios::in);
	ofstream aux("auxiliar.txt", ios::out);
	if (Lec.is_open()){
		gotoxy(15,5);cout<<"CAMBIO DE FECHA";
		gotoxy(4,7);cout<<"DNI: "; cin>>dniaux;
		
		
		Lec>>nom;		
		while(!Lec.eof()){
			Lec>>nomperrito;
			Lec>>dni;
			Lec>>fecha;
			Lec>>hora;

			if(dni==dniaux){
				gotoxy(4,9);cout<<"Digite nueva fecha: "; cin>>fechaaux;
				aux<<nom<<nomperrito<<" "<<dni<<" "<<fechaaux<<" "<<hora<<" "<<"\n";
			}
			else{
				aux<<nom<<nomperrito<<" "<<dni<<" "<<fecha<<" "<<hora<<" "<<"\n";
				gotoxy(4,9);cout<<"DNI no econtrado";
				getch();
				menuCitas();
				}
			Lec>>nom;
		}
		
		Lec.close();
		aux.close();	
		}
		else{
			archivoNoAbierto();
		}
		remove("citas.txt");
		rename("auxiliar.txt", "citas.txt");
		getch();
	}

void eliminar(ifstream &Lec){
	transicion();
	string nom;
	string nomperrito;
	string dni;
	string fecha;
	string hora;

	string dniaux;
	string fechaaux;
	Lec.open("citas.txt", ios::in);
	ofstream aux("auxiliar.txt", ios::out);
	if (Lec.is_open()){
		gotoxy(15,5);cout<<"ELIMINAR CITA";
		gotoxy(4,7);cout<<"DNI: "; cin>>dniaux;
		Lec>>nom;
		while(!Lec.eof()){
			Lec>>nomperrito;
			Lec>>dni;
			Lec>>fecha;
			Lec>>hora;

			if(dni==dniaux){
				gotoxy(4,11);cout<<"Eliminado ok.\n";
				Sleep(1500);
			}
			else{
				aux<<nom<<nomperrito<<" "<<dni<<" "<<fecha<<" "<<hora<<" "<<"\n";
				gotoxy(4,9);cout<<"DNI no econtrado";
				getch();
				menuCitas();
			}
			Lec>>nom;
		}
		Lec.close();
		aux.close();	
		}
		else{
			archivoNoAbierto();
		}
		remove("citas.txt");
		rename("auxiliar.txt", "citas.txt");
		getch();
	}


void menuCitas(){
	char x;
	transicion();
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
		case '1': {
			agregar(Esc);
			break;
		}
		case '2':{
			verCitas(Lee);
			break;
		}
		case '3':{
			buscarPersona(Lee);
			break;
		}
		case '4':{
			modificar(Lee);
			break;
		}
		case '5':{
			eliminar(Lee);
			break;
		}
	}
		
}

//============================================================================================

void menuVentaDeArticulos(){ //poner transicion y gotoxy **************************
	transicion();
	ofstream escribirBaseProductos;
	ifstream leerBaseProductos;
	char opc;
	system("CLS");
	cout<<"\tVENTA DE ARTICULOS"<<endl;
	cout<<"(1) Productos en sistema."<<endl;
	cout<<"(2) Generar compra."<<endl;
	cout<<"(3) Ingrese un nuevo producto al sistema."<<endl;
	cout<<"(4) Salir"<<endl;
	cout<<"Ingrese una opciÃ¯Â¿Â½n: ";cin>>opc;
	switch(opc){
		case '1':buscarProductosEnSistema(leerBaseProductos);break;
		case '2':generarCompra(leerBaseProductos);;break;
		case '3':agregarProducto(escribirBaseProductos,leerBaseProductos);break;
	}
	escribirBaseProductos.close();
	getch();
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
		cout<<"No se ha aÃ¯Â¿Â½adido ningÃ¯Â¿Â½n producto al sistema."<<endl;
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
			cout<<"Ingresar otro producto (SÃ¯Â¿Â½:1 || No:0): ";cin>>ingresarOtro;
			i++;
		}
		while(ingresarOtro);
		cout<<"\n\t*** TOTAL A PAGAR: S/."<<totalPagar<<" ***"<<endl;	
		leerBaseProductos.close();
	}
	else{
		cout<<"No se ha aÃ¯Â¿Â½adido ningÃ¯Â¿Â½n producto al sistema."<<endl;
	}
	system("pause");
	system("CLS");
}

//=======================================================================================0

void errorOpcionIngresada(){
	transicion();
	gotoxy(3,13);cout<<"Opcion no valida, presione una tecla para volver a intentarlo.";
	getch();
}

void confirmacion(){
	transicion();
	gotoxy(3,13);cout<<"Registro exitoso, presione una tecla para regresar al menu.";
	getch();
}

void archivoNoAbierto(){
	transicion();
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
 void transicion(){
	int i,j;
	//hacer un barrido de "limpieza" en toda la pantalla que se muestra
	for(i=5;i<=28;i++){ //Como el cuadro est? hasta 24... y la transici?n est? hecho a base de espacios en blanco, para que no se borre el cuadrado principal, le damos un 23
		for(j=3;j<=77;j++){ //Como el cuadro est? hasta 78... y la transici?n est? hecho a base de espacios en blanco, para que no se borre el cuadrado principal, le damos un 77
			gotoxy(j,i);cout<<" ";
		}
	}
}