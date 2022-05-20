//Librerias relevantes
#include<iostream>
#include<cstdlib>
#include<conio.h>
#include<string.h>
#include<fstream>
#include<ctime>
#include<cmath>
using namespace std;
//Estructura de clinte
struct cliente
{// antes hice el codigo solo para 3 registros y por eso tuve que hacer una especie de vector o amtirz, y al mi anterior pograma ser muy limitado, empece uno desde el inicio
	char nombre[30];
	int edad;
	int tratamiento;
	double codigo;
	int costo;
	cliente* next;
};
//
cliente* first = NULL;
cliente* last = NULL;
cliente* Registro = NULL;
//Declaracion de variables
int accion, day, week, month, back;
//Delaracion Dias de la semana
char dw[7][15] = { "Lunes", "Martes", "Miercoles" ,"Jueves", "Viernes", "Sabado", "Domingo" };
//Declaracion Meses
char m[12][15] = { "Enero", "Febrero", "Marzo", "Abril", "Mayo", "Junio", "Julio", "Agosto", "Septiembre", "Octubre", "Noviembre", "Diciembre" };
//Declaracion de funciones
void agendarcita();
void fechadelacita();
void mostrarcita();
void eliminarcita();
void modificarcita();
void guardarclientes();
void montototal();
int main()
{
	while (true)
	{
		//Manual de Usuario Cambiar las descripciones
			//bienvenida
		cout << "Bienvenido a Greath Imperial Corporation" << endl;
		cout << "Guia a continuacion sobre el uso del pograma se le asistira con un breve manual" << endl;
		system("pause");
		system("cls");
		cout << "De forma estrucuturada,coherente y breve Trataremos de explicar como funciona nuestra plataforma de Imperial Corp." << endl;
		//Explcia que para escoger opciones y menus solo se usaran los numeros, pero al rellanar con nombres, apellidos u otra informacion que le pida el pograma
		cout << "Para facilitar el uso de la plataforma para nuestros clientes se utilizaran solo numeros para seleccionar los menus u opciones a excepcion de los tratamientos y el nombre del cliente" << endl;
		system("pause");
		system("cls");
		//Explica como agendar citas y que el pograma pedira que rellene varios campos con informacion.
		cout << "Para la forma de agendar una cita, se le pedira que rellene distintos campos con informacion, posteriormente se le pedira que introduzca la fecha de la cita" << endl;
		//En esta seccion le explica al usario bajo el formato que utilizara para escoger la fecha requisada.  
		cout << "La forma de confirmar una fecha sera los dias de la semana (1/7), los meses en numerados (1/12) para agendar exitosamente una fecha" << endl;
		system("pause");
		system("cls");
		//Como la misma opcion dice este apartado se usara para modificar y/o eliminar algun parametro de infromacion anteriormente registrado.
		cout << "La opcion modificar/eliminar funcionara para cambiar algun parametro anteriormente registrado exitosamente" << endl;
		cout << "Si al tener un caso por parte de un desntista o por una forma externa a la plataforma  simplemente en la seccion de Tratamiento ingresara los tratamientos disponibles o escriba Otro" << endl;
		system("pause");
		system("cls");
		// Fin del manual, sobre el pograma.
		cout << "Con eso finalizaria la asistencia proporcionada, se espera que tanta informacion no lo haya confundido y todo haya quedado mas que claro, cualquier duda o pregunta a si como una aclaracion es libre de comunicarse por via telefonica. \n Le recordamos guardar celosamente su numero de folio.\n Le desamos un buen dia cualquier duda o pregunta estaremos felices de atenderlo." << endl;
		system("pause");
		system("cls");

		//apartado de mennu entre otras funcionalidades, cada opcion esta vinculada con su operacion mas adelante.
		do
		{
			system("pause");
			system("cls");
			//Se muestra el menu
			cout << "Bienvenido a la plataforma de Imperial Corps, Seleccione la opcion que desea hacer" << endl;
			cout << "1-Agendar una Cita" << endl;
			cout << "2-Ver una Cita" << endl;
			cout << "3-Modificar una Cita" << endl;
			cout << "4-Cancelar una Cita" << endl;
			cout << "5-guardarclientes Citas" << endl;
			cout << "6-Salir de la plataforma" << endl;
			cin >> accion;
			//Pide seleccionar un numero del menu
			switch (accion)
			{
			case 1:
			{
				system("cls");
				agendarcita();
				system("pause");
				system("cls");
				cout << "Volver al menu principal?\n1-Si  2-No" << endl;
				cin >> back;
			}break;
			case 2:
			{
				system("cls");
				mostrarcita();
				system("pause");
				system("cls");
				cout << "Volver al menu principal?\n1-Si  2-No" << endl;
				cin >> back;
			}
			break;
			case 3:
			{
				system("cls");
				modificarcita();
				system("pause");
				system("cls");
				cout << "Volver al menu principal?\n1-Si  2-No" << endl;
				cin >> back;

			}
			break;
			case 4:
			{
				system("cls");
				eliminarcita();
				system("pause");
				system("cls");
				cout << "Volver al menu principal?\n1-Si  2-No" << endl;
				cin >> back;
			}
			break;
			case 5:
			{
				system("cls");
				guardarclientes();
				system("pause");
				system("cls");
				cout << "Volver al menu principal?\n1-Si  2-No" << endl;
				cin >> back;
			}
			break;
			case 6:
			{
				return 0;
			}
			break;
			default:
				break;
			}
		} while (back == 1);


	}
	system("pause");
	return 0;
}

void agendarcita()
{
	if (first != NULL) {
		last->next = new cliente;   // Se pregunta aquí si inicio es diferente de NULL, al ser correcto e inicio tiene algo dentro, el apuntador fin se deberá
		last = last->next;
	}
	else {
		first = new cliente;           //en caso de que inicio sea igual a NULL inicio deberá crear un nuevo producto en la posición inicial y fin apuntará al 
		last = first;					 //mismo lugar que inicio.
	}
	cout << "\nNombre (sin espacios en blanco): ";
	cin >> last->nombre;
	cout << "\nEdad:" << endl;
	cin >> last->edad;
	// Cambiar nombres
	cout << "\nTratamiento:" << endl;
	cout << "\n-(1)Limpieza Dental las limpiezas bucales ayudan a eliminar el sarro que se acumula en la línea de nuestras encías o el cuello de nuestros dientes." << endl;
	cout << "\n-(2)Brackets. se utilizan para corregir la mordedura deficiente u oclusión dental defectuosa (cuando los dientes están amontonados o torcidos)." << endl;
	cout << "\n-(3)Endodoncia. tratamiento de los conductos dentales, concretamente de la raíz y nervios, sector llamado pulpa dentaria." << endl;
	cout << "\n-(4)Implantes dentales  una forma popular y efectiva de reemplazar los dientes perdidos y están diseñados para disimularse entre los otros dientes." << endl;
	cout << "\n-(5)Extraccion de muelas del juicio o cordales. implica sacar los molares que se encuentran en la parte posterior de la boca, llamados muelas del juicio o cordales" << endl;
	cout << "\n-(6)Empastes-Dentales Los empastes se usan para tratar pequeños agujeros, o caries, en los dientes. Para reparar una caries, el dentista extrae el tejido dental dañado y luego rellena el espacio con un material de empaste." << endl;
	cin >> last->tratamiento;
	// Llamada a la funcion "total".
	montototal();
	// Cambiar texto "folio"
	cout << "\nGenerando codigo de busqueda:" << endl;
	srand(time(NULL));
	// Cambiar variable "rand"
	printf("%d", rand());
	//cambiar ingresa folio
	cout << "\nIngrese el codigo generado:";
	cin >> last->codigo;
	// llama a funcion fecha de cita
	fechadelacita();
	last->next = NULL;
	cout << "Cita confirmada" << endl;
}
void fechadelacita()
{
	system("pause");
	system("cls");
	//cambiar descripciones  y variables (dia mes y dia de la semana).
	cout << "Ingrese el numero del dia(1 al 30)\n" << endl;
	cout << "";
	cin >> day;

	cout << "Ingrese el dia de la semana en numero(1 al 7)\n" << endl;
	cout << "";
	cin >> week;

	cout << "Ingrese numero del mes(1 al 12)\n" << endl;
	cout << "";
	cin >> month;
	cout << "Fecha de la cita:" << dw[week - 1] << " " << day << " de " << m[month - 1] << endl;
}
void mostrarcita()
{
	cliente* Registro = first;
	// Validar que no tenga citas vacias
	if (first == NULL)
	{
		cout << "Sin citas registradas" << endl;
		return;
	}
	// Mientras tenga cita se mostraran lo da (CAmbiar variable "auxiliar")
	while (Registro != NULL)
	{
		cout << "\ncliente:" << Registro->nombre << endl << "\nEdad:" << Registro->edad << endl << "\nFolio de registro:" << Registro->codigo << endl << "\nTratamiento por aplicar:" << Registro->tratamiento << endl;
		Registro = Registro->next;

	}

}
void modificarcita()
{
	cliente* Registro = first;
	if (first == NULL) {
		cout << "La lista esta vacia." << endl;
		return;
	}
	// cambiar Clinteelimi
	int clientemodificar;
	cout << "escriba el folio a modificar" << endl;
	cin >> clientemodificar;

	while ((Registro != NULL) && (Registro->codigo != clientemodificar))
	{
		Registro = Registro->next;
	}
	cout << "Nombre:" << "(Actual:" << Registro->nombre << ")" << endl;
	cin >> Registro->nombre;

	cout << "Edad:" << "(Actual:" << Registro->edad << ")" << endl;
	cin >> Registro->edad;

	cout << "Tratamiento:" << "(Antes era:" << Registro->tratamiento << ")" << endl;
	cin >> Registro->tratamiento;

	fechadelacita();

	cout << "Informacion Actualizada" << endl;
}
void eliminarcita()
{
	// cambiar AUXILIAR!!!!!!!!!!!!!!!!!!!!!!!!!!
	cliente* Registro = first;
	cliente* anterior = NULL;
	// Comprobacion en caso de falta de registro general de clientes.
	if (first == NULL)
	{
		cout << "Sin clientes registrados" << endl;
		return;
	}
	int Folioeliminar;
	cout << "Folio del cliente a eliminar:" << endl;
	cin >> Folioeliminar;
	while ((Registro != NULL) && (Registro->codigo != Folioeliminar))
	{
		anterior = Registro;
		Registro = Registro->next;
	}
	if (first == last && Registro == first)
	{
		delete Registro;
		first = NULL;
		last = NULL;
		cout << "Informacion eliminada Exitosamente" << endl;
		return;
	}
	if (anterior == NULL)
	{
		first = Registro->next;
	}
	else
	{
		anterior->next = anterior->next->next;
		if (Registro->next == NULL)
		{
			last = anterior;
		}
	}
}
void guardarclientes() {
	cliente* Registro = first;
	// Validacion, Cambiar Auxiliar ==> Registro.... Cambiar escribir ==>write
	if (first == NULL) {
		cout << "La lista esta vacia" << endl;
		return;
	}
	char cadena[255];
	cout << "Nombre del archivo:";
	cin >> cadena;
	ofstream escribir;
	escribir.open(cadena, ios::out | ios::binary);
	if (escribir.is_open()) {
		while (Registro != NULL) {
			escribir.write(reinterpret_cast<char*>(Registro), sizeof(cliente));
			Registro = Registro->next;
		}
	}
	escribir.close();
	cout << "Guardado exitosamente." << endl << endl;
}
void montototal()
{
	int precio, totalclientes;
	cout << "Vuelva a seleccionar para confirmar el servicio que desea recibir" << endl;
	cin >> last->tratamiento;
	switch (last->tratamiento)
	{
		// Cambiar descripciones/precios, Cambiar variable totalclientes ==> Cantidad de clientes Precio total
	case 1:
		precio = 200;
		cout << "Limpieza dental" << endl;
		cout << "Descripcion limpiezas bucales ayudan a eliminar el sarro que se acumula en la línea de nuestras encías:\n" << endl;
		cout << "Precio:" << precio << endl;
		cout << "Cantidad de clientes:";
		cin >> totalclientes;
		last->costo = precio * totalclientes;
		cout << "Precio total:" << last->costo;
		break;

	case 2:
		precio = 950;
		cout << "Brackets" << endl;
		cout << "Descripcion son la parte más visible de la ortodoncia, pequeñas piezas de forma cuadrangular que se colocan y adhieren en los dientes.:\nson instrumentos utilizados con el objetivo de poder reparar una serie de problemas dentales\nPara corregir los dientes torcidos o volver a la posición normal aquellos que se encuentran mal ubicados." << endl;
		cout << "Precio:" << precio << endl;;
		cout << "Cantidad de clientes a tratar:";
		cin >> totalclientes;
		last->costo = precio * totalclientes;
		cout << "El costo sera de:" << last->costo;
		break;
	case 3:
		precio = 1900;
		cout << "Endodoncia" << endl;
		cout << "Descripcion tratamiento de los conductos dentales, concretamente de la raíz y nervios:\n" << endl;
		cout << "Precio:" << precio << endl;
		cout << "Cantidad de clientes a tratar:";
		cin >> totalclientes;
		last->costo = precio * totalclientes;
		cout << "El costo sera de:" << last->costo;
		break;
	case 4:
		precio = 2000;
		cout << "Implantes Dentales" << endl;
		cout << "Descripcion forma popular y efectiva de reemplazar los dientes perdidos y están diseñados para disimularse entre los otros dientes:\n" << endl;
		cout << "Precio:" << precio << endl;
		cout << "Cantidad de clientes a tratar:";
		cin >> totalclientes;
		last->costo = precio * totalclientes;
		cout << "El costo sera de:" << last->costo;
		break;
	case 5:
		precio = 1000;
		cout << "Extraccion de muelas del juicio" << endl;
		cout << "La extracción de muelas del juicio implica sacar los molares que se encuentran en la parte posterior de la boca, llamados muelas del juicio o cordales, que están causando dolor u otros problemas.:\n" << endl;
		cout << "Precio:" << precio << endl;
		cout << "Cantidad de clientes a tratar:";
		cin >> totalclientes;
		last->costo = precio * totalclientes;
		cout << "El costo sera de:" << last->costo;
		break;
	case 6:
		precio = 1700;
		cout << "Empastes Dentales" << endl;
		cout << "Descripcion Los empastes se usan para tratar pequeños agujeros, o caries, en los dientes. Para reparar una caries, el dentista extrae el tejido dental dañado y luego rellena el espacio con un material de empaste.:\n" << endl;
		cout << "Precio:" << precio << endl;
		cout << "Cantidad de clientes a tratar:";
		cin >> totalclientes;
		last->costo = precio * totalclientes;
		cout << "El costo sera de:" << last->costo;
		break;
	default:
		break;
	}
}
