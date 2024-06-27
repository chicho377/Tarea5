#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <cstdlib> // para usar system("CLS")
using namespace std;

// variables globales
const int MAX_EMPLEADOS = 100; // constante para el tamano de los arrays

// arrays
string cedulas[MAX_EMPLEADOS];
string nombres[MAX_EMPLEADOS];
int tipos[MAX_EMPLEADOS];
double salariosPorHora[MAX_EMPLEADOS];
double horasTrabajadas[MAX_EMPLEADOS];
double salariosOrdinarios[MAX_EMPLEADOS];
double aumentos[MAX_EMPLEADOS];
double salariosBrutos[MAX_EMPLEADOS];
double deduccionesCCSS[MAX_EMPLEADOS];
double salariosNetos[MAX_EMPLEADOS];

string tiposEmpleados[] = {"", "Operario", "Tecnico", "Profesional"};

// variables contadores / calculos
int numEmpleados = 0;
int cantOperarios = 0, cantTecnicos = 0, cantProfesionales = 0;
double acumuladoNetoOperarios = 0, acumuladoNetoTecnicos = 0, acumuladoNetoProfesionales = 0;

// inicializando las funciones para poder agregarlas al main
void mostrarMenu() {
    cout << "Menu Principal:\n";
    cout << "1. Agregar empleado\n";
    cout << "2. Consultar empleado\n";
    cout << "3. Modificar empleado\n";
    cout << "4. Borrar empleado\n";
    cout << "5. Mostrar estadisticas finales\n";
    cout << "6. Salir\n";
    cout << "Ingrese una opcion: ";
}


int main(int argc, char** argv) {
	int opcion;
	do{
		system("CLS"); // limpiar pantalla
		mostrarMenu();
		cin >> opcion;
		
		system("CLS");
	}while(opcion != 6);
	
	

	return 0;
}
