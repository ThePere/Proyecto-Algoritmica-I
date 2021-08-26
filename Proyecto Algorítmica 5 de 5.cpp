#include <iostream>
#include <conio.h>
#include <windows.h>
#include <string.h>
#include <stdlib.h>
#include <fstream>

using namespace std;

void menu_principal();
//Como no existe el gotoxy en el Dev, declaramos una funci?n para que haga la misma funci?n
void gotoxy(int x, int y); //Sirv para manipular la ubicaci?n de los caracteres
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
bool verifica(int);
bool cantidad();
void nuevoingreso();
void lista();
void adoptar();
void eliminar();
void registro();
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

int datos[6]={0,0,0,0,0,0};

int main(){
	ofstream esc;
	char opc;
	SetConsoleCP(1252); // Cambiar cin -  Para m?quinas Windows
	SetConsoleOutputCP(1252); // Cambiar cout - Para m?quinas Windows
    system("Color 30");//Darle color al programa
    dibujarCuadrado(1,1,78,24);//Cuadro del fondo
	dibujarCuadrado(2,2,77,4);//Cuadro del titulo
    gotoxy(18,3);cout<<"VETERINARIA PARA PERROS - HUELLITAS UNIDAS"<<endl;
        menu_principal();
	getch();
    return 0;
}

void menu_principal(){
	char opc;
	do{
	gotoxy(4,5);cout<<"MENÚ PRINCIPAL"<<endl;
    gotoxy(4,7);cout<<"[1] Pacientes";
    gotoxy(4,9);cout<<"[2] Servicios";
    gotoxy(4,11);cout<<"[3] Adopciones";
    gotoxy(4,13);cout<<"[4] Venta de artículos";
    gotoxy(4,15);cout<<"[0] Salir";
    gotoxy(4,19);cout<<"Digite una opción: ";
    cin>>opc;
    transicion();
        if(opc!='1' and opc!='2' and opc!='3' and opc!='4' and opc!='0'){
        	gotoxy(3,13);cout<<"Opcion invalida, presione una tecla para volver a intentarlo."<<endl;
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
	system("CLS");
	dibujarCuadrado(1,1,78,24);
	dibujarCuadrado(2,2,77,4);
    gotoxy(18,3);cout<<"VETERINARIA PARA PERROS - HUELLITAS UNIDAS"<<endl;
	ofstream escperro;
	ifstream leerperro;
	char opc2;
	int repetido=0; //ver si algun codigo de perro se repite
	do{
		gotoxy(4,5);cout<<"MENU PACIENTES"<<endl;
		gotoxy(4,7);cout<<"[1] Ingresar nuevo paciente.";
		gotoxy(4,9);cout<<"[2] Ver pacientes.";
		gotoxy(4,11);cout<<"[3] Buscar paciente existente.";
		gotoxy(4,13);cout<<"[4] Modificar paciente.";
		gotoxy(4,15);cout<<"[5] Eliminar paciente.";
		gotoxy(4,17);cout<<"[0] Volver al menú principal.";
		gotoxy(4,21);cout<<"Ingrese opción: ";cin>>opc2;
		transicion();
		if(opc2!='1' and opc2!='2' and opc2!='3' and opc2!='4' and opc2!='5' and opc2!='0'){
			gotoxy(3,13);cout<<"Opción no válida, presiona una tecla para volver a ingresar un valor...";
			getch();
			transicion();
		}
	}while(opc2!='1' and opc2!='2' and opc2!='3' and opc2!='4' and opc2!='5' and opc2!='0');
	switch(opc2){
		//Opci?n Ingresar Paciente
		case '1':{
			agregarPaciente(escperro);
			pacientes();
			break;
		}
		//Opci?n Ver Paciente
		case '2':{
			transicion();
			verPaciente(leerperro);
			pacientes();
			break;
		}
		//Opci?n Busar Paciente
		case '3':{
			buscarPaciente(leerperro);
			pacientes();
			break;
		}
		//Opci?n Modificar Paciente
		case '4':{
			transicion();
			modificarPaciente(leerperro);
			pacientes();
			break;
		}
		//Opci?n Eliminar paciente
		case '5':{
			eliminarPaciente(leerperro);
			transicion();
			pacientes();
			break;
		}
		//Opci?n Salir al men?
		case '0':{
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
	//Verificar que no se repitan los c?digos
	if(verificar_cod(codigo)){
		esc<<perrito<<" "<<codigo<<" "<<nombre_dueno<<" "<<apellido_dueno<<" "<<raza<<" "<<fecha<<"\n";
	}
	esc.close();
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
	dibujarCuadrado(2,2,77,4);
	string codigo, perrito, nombre_dueno, apellido_dueno, raza, fecha;
	leer.open("Perritos.txt",ios::in);
	if(leer.is_open()){
		gotoxy(18,3);cout<<"VETERINARIA PARA PERROS - HUELLITAS UNIDAS"<<endl;
		gotoxy(7,5);cout<<"Perritos Registrados"<<endl<<endl;
		leer>>perrito;
	while(!leer.eof()){
		leer>>codigo;
		leer>>nombre_dueno;
		leer>>apellido_dueno;
		leer>>raza;
		leer>>fecha;
		cout<<"\tNombre del Perrito: "<<perrito<<endl;
		cout<<"\tCódigo del Perrito: "<<codigo<<endl;
		cout<<"\tNombre del Due?o: "<<nombre_dueno<<endl;
		cout<<"\tApellido del Due?o: "<<apellido_dueno<<endl;
		cout<<"\tRaza del Perrito: "<<raza<<endl;
		cout<<"\tFecha de inscripción: "<<fecha<<endl;
		cout<<"\tCita: "<<"No"<<endl;
		cout<<"\t----------------------------------"<<endl;
		leer>>perrito;
	}
	leer.close();
}else{
	gotoxy(4,15);cout<<"ERROR al abrir el archivo";
}
	getch();
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
}

void eliminarPaciente(ifstream &lec){
	string codigo, perrito, nombre_dueno, apellido_dueno, raza, fecha;
	string codaux,perritoaux,nombreaux,apellidoaux,razaaux,fechaaux;
	lec.open("Perritos.txt",ios::in);
	ofstream aux("auxiliar.txt",ios::out);
	if(lec.is_open()){
		gotoxy(8,5);cout<<"ELIMINE LOS DATOS DEL PACIENTE";
		gotoxy(4,7);cout<<"Digite el código del perrito a Eliminar: ";
		cin>>codaux;
		lec>>perrito;
		while(!lec.eof()){
			lec>>codigo;
			lec>>nombre_dueno;
			lec>>apellido_dueno;
			lec>>raza;
			lec>>fecha;
			if(codigo==codaux){
				gotoxy(4,17);cout<<"\t-------- Registro de Paciente eliminado con éxito --------- ";
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
}

void menu_adopcion(){
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
			nuevoingreso();
			menu_adopcion();
			break;
		}
		
		case '2':{
			lista();
			menu_adopcion();
			break;
		}
			
		case '3':{
			transicion();
			adoptar();
			menu_adopcion();
			break;
		}
		
		case '4':{
			transicion();
			registro();
			menu_adopcion();
			break;
		}
		
		case '5':{
			transicion();
			cambio();
			menu_adopcion();
			break;
		}
		case '0':{
			break;
		}
	}
	
}

bool verifica(int x){
	ifstream leer;
	leer.open("guarderia.txt",ios::in);
	int cod;
	string nom;
	string edad;
	string tam;
	string raza;
	string ingreso;
	string estado;

	leer>>cod;
	while(!leer.eof()){
		if(cod==x){
			leer.close();
			return true;
		}
		leer>>nom;
		leer>>edad;
		leer>>tam;
		leer>>raza;
		leer>>ingreso;
		leer>>estado;
		leer>>cod;
	}
	leer.close();
	return false;
}

bool cantidad(){
	int n=0;
	ifstream leer;
	leer.open("guarderia.txt",ios::in);
	if(leer.is_open()){	
		int cod;
		string nom;
		string edad;
		string tam;
		string raza;
		string ingreso;
		string estado;
	
		leer>>cod;
		while(!leer.eof()){
			leer>>nom;
			n++;
			leer>>edad;
			leer>>tam;
			leer>>raza;
			leer>>ingreso;
			leer>>estado;
			leer>>cod;
		}
		
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

void nuevoingreso(){
	int cod=1;
	char opc;
	string nom, edad, tam, raza, ingreso, estado;

	do{
		if(cantidad()){
		transicion();
		gotoxy(30,5);cout<<"NUEVO PERRO"<<endl;
		ofstream escribir;
		escribir.open("guarderia.txt",ios::app);
			
		if(escribir.fail()){
			cout<<"No se pudo abrir el archivo, intentelo de nuevo";
			menu_adopcion();
		}
			
		while(verifica(cod)){
			cod++;
		}
			
		fflush(stdin);
		gotoxy(4,7);cout<<"Nombre: ";getline(cin,nom);
		gotoxy(4,9);cout<<"Edad: ";getline(cin,edad);			
		gotoxy(4,11);cout<<"Tamano: ";getline(cin,tam);
		gotoxy(4,13);cout<<"Raza: ";getline(cin,raza);
		gotoxy(4,15);cout<<"Fecha de ingreso: ";getline(cin,ingreso);
		gotoxy(4,17);cout<<"Estado: ";getline(cin,estado);
			
		escribir<<cod<<endl;
		escribir<<nom<<endl;
		escribir<<edad<<endl;
		escribir<<tam<<endl;
		escribir<<raza<<endl;
		escribir<<ingreso<<endl;
		escribir<<estado<<endl;
			
		escribir.close();
			
		gotoxy(4,19);cout<<"Quiere ingresar otro perro? (S/N): ";cin>>opc;	
		}
		else{
		gotoxy(4,19);cout<<"\nLa guarderia ya no cuenta con mas espacio :( ";
		}	
	}while (opc=='s' or opc=='S');
	getche();
}

void lista(){
	int n=9;
	transicion();
	ifstream leer;
	leer.open("guarderia.txt",ios::in);
	if(leer.is_open()){
		gotoxy(15,5);cout<<"LISTA DE PERROS"<<endl;
		gotoxy(4,7);cout<<"Codigo  Nombre  Edad  Tamaño  Raza\t      Fecha     Estado"<<endl;	
		int cod;
		string nom;
		string edad;
		string tam;
		string raza;
		string ingreso;
		string estado;
	
		leer>>cod;
		while(!leer.eof()){
			leer>>nom;
			leer>>edad;
			leer>>tam;
			leer>>raza;
			leer>>ingreso;
			leer>>estado;
			gotoxy(4,n);cout<<"["<<cod<<"]";
			gotoxy(12,n);cout<<nom;
			gotoxy(20,n);cout<<edad;
			gotoxy(26,n);cout<<tam;
			gotoxy(34,n);cout<<raza;
			gotoxy(46,n);cout<<ingreso;
			gotoxy(56,n);cout<<estado<<endl;
			n++;
			leer>>cod;
		}
		getche();	
	}
	else{
		gotoxy(4,7);cout<<"Error, No hay perros registrados o el archivo no existe"<<endl;
		getche();
	}
}

void adoptar(){

	string cod2, nombre,apellido,dni,direc,fecha;

	transicion();
	gotoxy(15,5);cout<<"\t\tGENERAR ADOPCION"<<endl<<endl;
	ofstream escribir;
	escribir.open("adopcion.txt",ios::app);
	
	if(escribir.fail()){
		gotoxy(4,7);cout<<"No se pudo abrir el archivo, intentelo de nuevo";
		menu_adopcion();
	}
	
	fflush(stdin);
	gotoxy(4,7);cout<<"Nombre: ";getline(cin,nombre);
	gotoxy(4,9);cout<<"apellido: ";getline(cin,apellido);			
	gotoxy(4,11);cout<<"DNI: ";getline(cin,dni);
	gotoxy(4,13);cout<<"Direccion: ";getline(cin,direc);
	eliminar();
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

	getche();
}

void registro(){
	system("CLS");
	dibujarCuadrado(2,2,77,4);
	ifstream leer;
	leer.open("adopcion.txt",ios::in);
	if(leer.is_open()){
		gotoxy(18,3);cout<<"VETERINARIA PARA PERROS - HUELLITAS UNIDAS"<<endl;
		gotoxy(15,5);cout<<"REGISTRO DE ADOPCIONES"<<endl<<endl;
	
		string nombre;
		string apellido;
		string dni;
		string direc;
		string cod2;
		string fecha;
	
			leer>>nombre;
		while(!leer.eof()){
			leer>>apellido;
			leer>>dni;
			leer>>direc;
			leer>>cod2;
			leer>>fecha;
			cout<<"\tNombre: "<<nombre<<endl;
			cout<<"\tApellido: "<<apellido<<endl;
			cout<<"\tDNI: "<<dni<<endl;
			cout<<"\tDireccion: "<<direc<<endl;
			cout<<"\tCod perro: "<<cod2<<endl;
			cout<<"\tFecha adopcion: "<<fecha<<endl;
			cout<<"\n\t-------------------------------"<<endl;
			leer>>nombre;
		}
		getche();	
	}
	else{
		gotoxy(4,7);cout<<"Error, No hay Adopciones o el archivo no existe"<<endl;
		getche();
	}
}

void eliminar(){
	string codigo, newestado, cod, nom, edad, tam, raza, ingreso, estado;
	ifstream lee("guarderia.txt", ios::in); 
	ofstream reempl("cambio.txt", ios::app);
	gotoxy(4,15);cout<<"Codigo del perro: ";cin>>codigo;
	
	getline(lee,cod);
	while(!lee.eof()){
		getline(lee,nom);
		getline(lee,edad);
		getline(lee,tam);
		getline(lee,raza);
		getline(lee,ingreso);
		getline(lee,estado);
		if(cod == codigo){
			cout<<endl;
						
		}else{
			reempl<<cod<<endl;
			reempl<<nom<<endl;
			reempl<<edad<<endl;
			reempl<<tam<<endl;
			reempl<<raza<<endl;
			reempl<<ingreso<<endl;
			reempl<<estado<<endl;
				
		}
	getline(lee,cod);
		
	}
	
	lee.close();
	reempl.close();
	remove("guarderia.txt");
	rename("cambio.txt", "guarderia.txt");
}

void cambio(){
	transicion();
	string codigo, newestado, cod, nom, edad, tam, raza, ingreso, estado;
	ifstream lee("guarderia.txt", ios::in); 
	ofstream reempl("cambio.txt", ios::app);
	gotoxy(4,7);cout<<"Ingresar el codigo del perro --> ";cin>>codigo;
	
	getline(lee,cod);
	while(!lee.eof()){
		getline(lee,nom);
		getline(lee,edad);
		getline(lee,tam);
		getline(lee,raza);
		getline(lee,ingreso);
		getline(lee,estado);
		if(cod == codigo){
			gotoxy(4,9);cout<<"Estado-------> "<<estado<<endl;
			gotoxy(4,13);cout<<"Ingresar Nuevo Estado ----> ";
			fflush(stdin);
			getline(cin, newestado);
			reempl<<cod<<endl;
			reempl<<nom<<endl;
			reempl<<edad<<endl;
			reempl<<tam<<endl;
			reempl<<raza<<endl;
			reempl<<ingreso<<endl;
			reempl<<newestado<<endl;
						
		}else{
			reempl<<cod<<endl;
			reempl<<nom<<endl;
			reempl<<edad<<endl;
			reempl<<tam<<endl;
			reempl<<raza<<endl;
			reempl<<ingreso<<endl;
			reempl<<estado<<endl;
				
		}
	getline(lee,cod);
		
	}
	
	lee.close();
	reempl.close();
	remove("guarderia.txt");
	rename("cambio.txt", "guarderia.txt");
}
//Hacer cuadrados, son para darle est?tica y forma a nuestro men?
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
//Funci?n est?tica para se?alar posiciones en eje "x" "y" (rescatado de foros), porque antes exist?a la funci?n gotoxy dentro de la librer?a windows.h pero ahora debe ser manual
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
	for(i=5;i<=23;i++){ //Como el cuadro est? hasta 24... y la transici?n est? hecho a base de espacios en blanco, para que no se borre el cuadrado principal, le damos un 23
		for(j=3;j<=77;j++){ //Como el cuadro est? hasta 78... y la transici?n est? hecho a base de espacios en blanco, para que no se borre el cuadrado principal, le damos un 77
			gotoxy(j,i); printf(" ");}}
}

void transicion2(){
	int i,j;
	//hacer un barrido de "limpieza" en toda la pantalla que se muestra
	for(i=0;i<=80;i++){ //Como el cuadro est? hasta 80... y la transici?n est? hecho a base de espacios en blanco, para borrar todo lo que aparezca en la pantalla
		for(j=0;j<=300;j++){ //Como el cuadro est? hasta 78... y la transici?n est? hecho a base de espacios en blanco, para borrar todo lo que aparezca en la pantalla
			gotoxy(j,i); printf(" ");}}
}

void menu_servicios(){
    char opc;
	transicion();
    gotoxy(15,5);cout<<"SERVICIOS";
    gotoxy(4,7);cout<<"[1]:Baños";
    gotoxy(4,9);cout<<"[2]:Vacunas";
    gotoxy(4,11);cout<<"[3]:Tratamientos";
    gotoxy(4,13);cout<<"[4]:Corte de pelo";
    gotoxy(4,15);cout<<"[5]:Operaciones";
    gotoxy(4,17);cout<<"[6]:Análisis";
    gotoxy(4,19);cout<<"[7]:Boleta";
    gotoxy(4,21);cout<<"[0]:Salir";
    
    do{
        gotoxy(5,21);cout<<"Digite una opcion: ";cin>>opc;
        if(opc!='1' and opc!='2' and opc!='3' and opc!='4' and opc!='5' and opc!='6' and opc!='7' and opc!='0'){
        	transicion();
        	gotoxy(5,15);cout<<"Error, presione una tecla para volver a intentarlo";
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
		
		case '7':
			boleta(datos);
			menu_servicios();
        case '0':
            getch();
            break;
    }
    
}
int bano(){
	char tamano;
	int preciobano=0;
	transicion();
	gotoxy(15,5);cout<<"BAÑO";
	gotoxy(4,7);cout<<"1. Pequeño					s/20 ";
	gotoxy(4,9);cout<<"2. Mediano					s/30 ";
	gotoxy(4,11);cout<<"3. Grande					s/40 ";
    gotoxy(4,13);cout<<"0. Salir ";	

    do{
	   	gotoxy(4,15);cout<<"Ingrese una opción: ";
		cin>>tamano; 
	if(tamano!='0'&&tamano!='1'&&tamano!='2'&&tamano!='3'){
		transicion();
		gotoxy(5,17);cout<<"Opción fuera del rango"<<endl;	
	}
	}while(tamano!='0'&&tamano!='1'&&tamano!='2'&&tamano!='3');		
	
	if(tamano=='1'){
	    preciobano=20;
	}
	if(tamano=='2'){
	    preciobano=30;      
	}
	if(tamano=='3'){
	    preciobano=40;
	}   
	gotoxy(4,19);cout<<"Registrado con éxito"<<endl; 
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
	gotoxy(4,23);cout << "Ingrese una opción: ";
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
    gotoxy(4,25);cout<<"Desea agregar otra vacuna? (S/N): ";cin>>opc2;
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
    transicion();
	gotoxy(15,5);cout<<"TRATAMIENTOS";
	gotoxy(4,7);cout<<"[1] Desparacitacion";
	gotoxy(4,9);cout<<"[2] Antipulgas ";
    gotoxy(4,11);cout <<"[0] Salir";

    do{
    gotoxy(4,13);cout<<"Ingrese opcion: ";
    cin>>opc;
        if(opc!='0' && opc!='1' && opc!='2'){
            gotoxy(4,15);cout<<" Ingreso mal de valor. Presione una tecla para volver a ingresar.."<<endl;
            getch();
        }
	}while(opc!='0' && opc!='1' && opc!='2'&& opc!='0');
	
	switch(opc){
		case '1': 
			transicion();
			gotoxy(15,5);cout<<"DESPARACITACION";
			gotoxy(4,7);cout<<"[1] Inyeccion          s/20";
			gotoxy(4,9);cout<<"[2] Pastilla           s/15";	
			gotoxy(4,11);cout<<"[0] Salir ";
			
			do{
				gotoxy(4,13);cout<<"Ingrese opcion: ";
				cin>>desparacitacion;
				if(desparacitacion!='0' && desparacitacion!='1' && desparacitacion!='2')
					gotoxy(4,15);cout<<"Opcion fuera del rango "<<endl;
				switch(desparacitacion){
					case '1': 
						preciodesparacitacion=20;
						gotoxy(4,15);cout<<"Opción registrada"<<endl;
						break;
						
					case '2':
						preciodesparacitacion=15;
						gotoxy(4,15);cout<<"Opción registrada"<<endl;
						break;
						
					case '0':
						tratamientos();
					}
			}while(desparacitacion!='0' && desparacitacion!='1' && desparacitacion!='2');
		break;
		
		case '2':
			transicion();
			gotoxy(15,5);cout<<"ANTIPULGAS";
			gotoxy(4,7);cout<<"[1] Pipetas            s/15";
			gotoxy(4,9);cout<<"[2] Pastilla           s/20 ";		
			gotoxy(4,11);cout<<"[3] Inyeccion          s/25";	
			gotoxy(4,13);cout<<"[0] Salir ";

    		do{
				gotoxy(4,15);cout<<"Ingrese opcion: ";
				cin>>opantipulgas;
				if(opantipulgas!='0' && opantipulgas!='1' && opantipulgas!='2'&& opantipulgas!='3'){
					gotoxy(4,15);cout<<"Opcion fuera del rango ";
					system("pause");
					}
				switch(opantipulgas){
					case '1': precioantipulgas=15;
					break;
					case '2': precioantipulgas=20;
					break;
					case '3': precioantipulgas=25;
					break;
					case '0': tratamientos();
				}
			//gotoxy(4,15); cout<<"Opción registrada."; <- No sé dónde ponerlo (1)
				 }while(opantipulgas!='0' && opantipulgas!='1' && opantipulgas!='2'&& opantipulgas!='3');
			//gotoxy(4,15); cout<<"Opción registrada."; <-No sé dónde ponerlo (2)
		break;
		case '0': menu_servicios();
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
	gotoxy(4,11);cout<<"[3] Corte Holandes		        	s/40 ";
	gotoxy(4,13);cout<<"[4] Corte Moderno				s/45 ";
	gotoxy(4,15);cout<<"[5] Corte de cachorro			s/25 ";
	gotoxy(4,17);cout<<"[6] Corte de verano		    	        s/35 ";
	gotoxy(4,19);cout <<"[0] Salir"; 

    do{
	gotoxy(4,21);cout<< "Ingrese opción: ";
	cin>>op;
    }while(op!='0' && op!='1'&& op!='2'&& op!='3'&&op!='4' &&op!='5'&&op!='6');
	
    switch(op){
    	//Esta parte debería ser con un if para al final poner el mensaje de opción registrada
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
	} gotoxy(4,23);cout<<"Opción registrada";
	getch();
	return preciocorte;
}

int operaciones(){
	char opc, confirm;
	int precio;
    transicion();
	gotoxy(15,5);cout<<"OPERACIONES";
	gotoxy(4,7);cout<<"Tiene chequeo preoperatorio?(s:si  n:no): ";
		cin>>confirm;
		if(confirm=='n'||confirm=='N'){
			analisis();
		}
		
			gotoxy(4,9);cout<<"[1] Esterilizaciones    	  S/200"<<endl;
			gotoxy(4,11);cout<<"[2] Oftalmologia          S/250"<<endl;
			gotoxy(4,13);cout<<"[3] Maxilofacial          S/200"<<endl;
			gotoxy(4,15);cout<<"[4] Abdominal             S/300"<<endl;
			gotoxy(4,17);cout<<"[5] Oncologica            S/400"<<endl;
			gotoxy(4,19);cout<<"[6] Reconstructiva        S/500"<<endl;
			gotoxy(4,21);cout<<"[7] Urgencias             S/400"<<endl;
			gotoxy(4,23);cout<<"[0] Salir"<<endl;
            do{
			gotoxy(4,25);cout<<"\tElija su opcion: ";
			cin>>opc;
            } while(opc!='0' && opc!='1'&& opc!='2'&& opc!='3'&&opc!='4' &&opc!='5'&&opc!='6'&&opc!='7');
			switch(opc){
				case '1': gotoxy(4,27);cout<<"\nEsterilizaciones"<<endl;
				  	precio=200;
				//	cita();
				break;
				case '2': gotoxy(4,27);cout<<"\nOftalomologica"<<endl;
					precio=250;
				//	cita();
				break;
				case '3': gotoxy(4,27);cout<<"\nMaxilofacial"<<endl;
					precio=200;
				//	cita();
				break;
				case '4': gotoxy(4,27);cout<<"\nAbdominal"<<endl;
					precio=300;
				//	cita();
				break;
				case '5': gotoxy(4,27);cout<<"\nOncologica"<<endl;
					precio=400;
				//cita();
				break;
				case '6': gotoxy(4,27);cout<<"\nReconstructiva"<<endl;
					precio=500;
				//	cita();
				break;
				case '7': gotoxy(4,27);cout<<"\nUrgencias"<<endl;
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
    transicion();
	gotoxy(15,5);cout<<"ANÁLISIS";
	gotoxy(4,7);cout<<"[1] Chequeo preoperatorio       S/80";
	gotoxy(4,9);cout<<"[2] Descarte de enfermedades"<<endl;
	gotoxy(4,11);cout<<"[3] Radiografias                S/100";
	gotoxy(4,13);cout<<"[4] Tomografias                 S/100";
	gotoxy(4,15);cout<<"[5] General.";
	gotoxy(4,17);cout<<"[0] Volver";
	
	do{
	gotoxy(5,19);cout<<"Elija su opcion: ";
	cin>>m;
    }while(m!='0' && m!='1'&& m!='2'&& m!='3'&&m!='4' &&m!='5');

		switch (m){
			case '1': 
			gotoxy(5,21);cout<<"Chequeo preoperatorio"<<endl;
				analisis[0]=80;
			//cita();
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
               gotoxy(4,15);cout<<"Elija su opcion: ";
			cin>>p; 
            }while(p!='0' && p!='1'&& p!='2'&& p!='3');
			
			switch(p){
				case '1': {
					gotoxy(4,17);cout<<"Distemper y Parvovirus";
					descarte[0]=100;
					//	cita();
					break;
				}
				
				case '2': {
					gotoxy(4,17);cout<<"Leptospirosis";
					descarte[1]=80;
					//	cita();
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
			//	cita();
			break;  
            }

			case '4':{
                gotoxy(5,21);cout<<"Tomografia";
			    	analisis[3]=400;
			//	cita();
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
                gotoxy(4,15);cout<<"Elija su opcion: ";
                    cin>>p; 
                }while(p!='0' && p!='1'&& p!='2'&& p!='3');

                switch(p){
                    case '1': {
                    	gotoxy(4,15);cout<<"Analisis de sangre"<<endl;
                    	analisis[4]=100;
                		//	cita();
						break;
					}
                    case '2': {
                    	gotoxy(4,15);cout<<"Analisis fisico"<<endl;
                    	analisis[4]=120;
                		//	cita();
						break;
					}
                    case '3': {
                    	gotoxy(4,15);cout<<"Analisis de sangre y fisico"<<endl;
                    	analisis[4]=210;
                		//   cita();
						break;
					}
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
		gotoxy(4,22);cout<<"¿Desea agregar otro analisis? (S/N): ";cin>>m2;			
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
	transicion();
	gotoxy(15,5);cout<<"VENTA DE ARTÍCULOS";
	gotoxy(4,7);cout<<"[1] Productos en sistema.";
	gotoxy(4,9);cout<<"[2] Generar compra.";
	gotoxy(4,11);cout<<"[3] Ingrese un nuevo producto al sistema.";
	gotoxy(4,13);cout<<"[4] Salir";
	//Falta consistencia
	gotoxy(4,15);cout<<"Ingrese una opción: ";cin>>opc;
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
	transicion();
	leerBaseProductos.open("productos.txt",ios::in);
	if(leerBaseProductos.is_open()){
		gotoxy(15,5);cout<<"PRODUCTOS EN SISTEMA";
		fflush(stdin);
		gotoxy(4,7);cout<<"Escriba el nombre del producto: ";getline(cin,nombreProductoAux);
		fflush(stdin);
		if(verificarProducto(nombreProductoAux,leerBaseProductos,precioProductoAux,cantidadProductoAux)==false){
			gotoxy(4,9);cout<<"Nombre del producto ---------------- "<<nombreProductoAux;
			gotoxy(4,11);cout<<"Precio del producto ---------------- S/."<<precioProductoAux;
			gotoxy(4,13);cout<<"Cantidad del producto -------------- "<<cantidadProductoAux;
		}
		else{
			gotoxy(4,11);cout<<"Producto no encontrado.";
		}
		leerBaseProductos.close();
	}
	else{
		gotoxy(4,11);cout<<"No se ha añadido ningún producto al sistema."<<endl;
	}
	system("pause");
	transicion();
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
	transicion();
	gotoxy(15,5);cout<<"INGRESAR UN NUEVO PRODUCTO AL SISTEMA";	
	fflush(stdin);
	gotoxy(4,7);cout<<"Ingresar el nombre del producto: ";getline(cin,nombreProducto);
	fflush(stdin);
	gotoxy(4,9);cout<<"Ingresar la cantidad de productos: ";cin>>cantidadProductoAdicional;
	fflush(stdin);
	if(verificarProducto(nombreProducto,leerBaseProductos,precioProducto,cantidadProducto)){
		gotoxy(4,11);cout<<"Ingresar el precio del producto (S/.): ";cin>>precioProducto;
		fflush(stdin);
		escribirBaseProductos<<precioProducto<<" "<<cantidadProductoAdicional<<" "<<nombreProducto<<endl;	
		escribirBaseProductos.close();
	}
	else{
		gotoxy(4,11);cout<<"El precio establecido es: "<<precioProducto<<endl;
		cantidadProducto+=cantidadProductoAdicional;
		modificarCantidadProducto(leerBaseProductos,nombreProducto,cantidadProducto);
		gotoxy(4,13);cout<<"La nueva cantidad es: "<<cantidadProducto<<endl;
	}
	system("pause");
	transicion();
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
	transicion2();
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
			cout<<"Ingresar otro producto (S?:1 || No:0): ";cin>>ingresarOtro;
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
	transicion2();
}

/*CITA+BOLETA--> POR ARREGLAR
	void cita(){
	system("cls");
	char nombre[10], dni[10], fecha[10], hora[6];
	cout<<"\tProgramacion de cita"<<endl;
	cout<<"parte de ruben"<<endl;
	cout<<"\nIngrese la fecha: ";
	cin.getline(fecha,10,'\n');
	cin.ignore();
	cout<<"\nIngrese la hora: ";
	cin.getline(hora,6,'\n');
	cin.ignore();
}
*/
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

