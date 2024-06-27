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

// funciones

// funcion mostrar menu
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

// funcion agregar empleado
void agregarEmpleado(){
	
	// verificacion de numero maximo de empleados
	if(numEmpleado >= MAX_EMPLEADOS){
		cout << "Se ha alcanzado el numero maximo de empleados.\n";
		return;
	}
	
	// solicitar los datos
	cout << "Ingrese la cedula del empleado: ";
    cin >> cedulas[numEmpleados];

    cout << "Ingrese el nombre del empleado: ";
    cin.ignore(); // consumir el salto de linea pendiente 
    getline(cin, nombres[numEmpleados]);

    cout << "Ingrese el tipo de empleado (1-Operario, 2-Tecnico, 3-Profesional): ";
    cin >> tipos[numEmpleados];

    cout << "Ingrese el salario por hora: ";
    cin >> salariosPorHora[numEmpleados];

    cout << "Ingrese la cantidad de horas trabajadas: ";
    cin >> horasTrabajadas[numEmpleados];

    calcularSalarios(numEmpleados);

    numEmpleados++;
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
