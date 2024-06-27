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

void mostrarMenu();
void agregarEmpleado();
void consultarEmpleado();
void modificarEmpleado();
void borrarEmpleado();
void mostrarEstadisticas();
void calcularSalarios(int index);


int main(int argc, char** argv) {
	// ciclo do while para poder manejar las opciones del menu
	int opcion;
	do{
		system("CLS"); // limpiar pantalla
		mostrarMenu();
		cin >> opcion;
		
		system("CLS"); // limpiar pantalla
		
		// switch para poder usar el menu
		switch(opcion){
			 case 1:
                agregarEmpleado();
                break;
            case 2:
                consultarEmpleado();
                break;
            case 3:
                modificarEmpleado();
                break;
			case 4:
                borrarEmpleado();
                break;
            case 5:
                mostrarEstadisticas();
                break;
            case 6:
                cout << "Saliendo del programa...\n";
                break;
			default:
				cout << "Opcion no valida. Intente de nuevo.\n";
				break;
		}
		
		if (opcion != 6) {
            cout << "Presione cualquier tecla para continuar...";
            getch(); // pausa antes de limpiar la pantalla y mostrar el menu nuevamente
        }
		
	}while(opcion != 6);
	
	return 0;
}

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
	if(numEmpleados >= MAX_EMPLEADOS){
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

// funcion consultar empleado
void consultarEmpleado() {
    string cedula;
    cout << "Ingrese la cedula del empleado a consultar: ";
    cin >> cedula;
    bool encontrado = false;
    
    // iterar en el array de empleados
    for (int i = 0; i < numEmpleados; i++) {
    	// verificar que la cedula coincida para imprimir los datos solicitados
        if (cedulas[i] == cedula) {
            cout << "\nDatos del empleado:\n";
            cout << "--------------------------------------------------\n";
            cout << "Cedula: " << cedulas[i] << "\n";
            cout << "Nombre: " << nombres[i] << "\n";
            cout << "Tipo Empleado: " << tiposEmpleados[tipos[i]] << "\n";
            cout << "Salario por Hora: " << salariosPorHora[i] << "\n";
            cout << "Cantidad de Horas: " << horasTrabajadas[i] << "\n";
            cout << "--------------------------------------------------\n";
            cout << "Salario Ordinario: " << salariosOrdinarios[i] << "\n";
            cout << "Aumento: " << aumentos[i] << "\n";
            cout << "Salario Bruto: " << salariosBrutos[i] << "\n";
            cout << "Deduccion CCSS: " << deduccionesCCSS[i] << "\n";
            cout << "Salario Neto: " << salariosNetos[i] << "\n";
            cout << "--------------------------------------------------\n";
            encontrado = true;
            break;
        }
    }
    if (!encontrado) {
        cout << "Empleado no encontrado.\n";
    }
}

// funcion modificar empleado
void modificarEmpleado() {
    string cedula;
    cout << "Ingrese la cedula del empleado a modificar: ";
    cin >> cedula;
    bool encontrado = false;
    for (int i = 0; i < numEmpleados; i++) {
    	// verificacion del empleado que se desea modificar sea el correcto
        if (cedulas[i] == cedula) {
            encontrado = true;

            cout << "Ingrese el nuevo nombre del empleado: ";
            cin.ignore(); // consumir el salto de linea pendiente 
            getline(cin, nombres[i]);

            cout << "Ingrese el nuevo tipo de empleado (1-Operario, 2-Tecnico, 3-Profesional): ";
            cin >> tipos[i];

            cout << "Ingrese el nuevo salario por hora: ";
            cin >> salariosPorHora[i];

            cout << "Ingrese la nueva cantidad de horas trabajadas: ";
            cin >> horasTrabajadas[i];

            calcularSalarios(i);

            cout << "Empleado modificado correctamente.\n";
            break;
        }
    }
    if (!encontrado) {
        cout << "Empleado no encontrado.\n";
    }
}

// funcion borrar empleado
void borrarEmpleado() {
    string cedula;
    cout << "Ingrese la cedula del empleado a borrar: ";
    cin >> cedula;
    bool encontrado = false;
    // verificar empleado a eliminar
    for (int i = 0; i < numEmpleados; i++) {
        if (cedulas[i] == cedula) {
            encontrado = true;

            // actualizar acumulados antes de borrar
            if (tipos[i] == 1) {
                cantOperarios--;
                acumuladoNetoOperarios -= salariosNetos[i];
            } else if (tipos[i] == 2) {
                cantTecnicos--;
                acumuladoNetoTecnicos -= salariosNetos[i];
            } else if (tipos[i] == 3) {
                cantProfesionales--;
                acumuladoNetoProfesionales -= salariosNetos[i];
            }

            // mover el ltimo empleado a la posicixion actual
            cedulas[i] = cedulas[numEmpleados - 1];
            nombres[i] = nombres[numEmpleados - 1];
            tipos[i] = tipos[numEmpleados - 1];
            salariosPorHora[i] = salariosPorHora[numEmpleados - 1];
            horasTrabajadas[i] = horasTrabajadas[numEmpleados - 1];
            salariosOrdinarios[i] = salariosOrdinarios[numEmpleados - 1];
            aumentos[i] = aumentos[numEmpleados - 1];
            salariosBrutos[i] = salariosBrutos[numEmpleados - 1];
            deduccionesCCSS[i] = deduccionesCCSS[numEmpleados - 1];
            salariosNetos[i] = salariosNetos[numEmpleados - 1];

            numEmpleados--;
            cout << "Empleado borrado correctamente.\n";
            break;
        }
    }
    if (!encontrado) {
        cout << "Empleado no encontrado.\n";
    }
}

// funcion mostrar estadisticas
void mostrarEstadisticas() {
    cout << "\nEstadisticas finales:\n";
    cout << "--------------------------------------------------\n";
    cout << "Cantidad de Empleados Tipo Operarios: " << cantOperarios << "\n";
    if (cantOperarios > 0) {
        cout << "Acumulado Salario Neto para Operarios: " << acumuladoNetoOperarios << "\n";
        cout << "Promedio Salario Neto para Operarios: " << acumuladoNetoOperarios / cantOperarios << "\n";
    } else {
        cout << "Acumulado Salario Neto para Operarios: N/A\n";
        cout << "Promedio Salario Neto para Operarios: N/A\n";
    }

    cout << "--------------------------------------------------\n";
    cout << "Cantidad de Empleados Tipo Tecnico: " << cantTecnicos << "\n";
    if (cantTecnicos > 0) {
        cout << "Acumulado Salario Neto para Tecnicos: " << acumuladoNetoTecnicos << "\n";
        cout << "Promedio Salario Neto para Tecnicos: " << acumuladoNetoTecnicos / cantTecnicos << "\n";
    } else {
        cout << "Acumulado Salario Neto para Tecnicos: N/A\n";
        cout << "Promedio Salario Neto para Tecnicos: N/A\n";
    }

    cout << "--------------------------------------------------\n";
    cout << "Cantidad de Empleados Tipo Profesional: " << cantProfesionales << "\n";
    if (cantProfesionales > 0) {
        cout << "Acumulado Salario Neto para Profesionales: " << acumuladoNetoProfesionales << "\n";
        cout << "Promedio Salario Neto para Profesionales: " << acumuladoNetoProfesionales / cantProfesionales << "\n";
    } else {
        cout << "Acumulado Salario Neto para Profesionales: N/A\n";
        cout << "Promedio Salario Neto para Profesionales: N/A\n";
    }
    cout << "--------------------------------------------------\n";
}

// funcion calcular salario
void calcularSalarios(int index) {
    salariosOrdinarios[index] = salariosPorHora[index] * horasTrabajadas[index];

    switch (tipos[index]) {
        case 1: // operario
            aumentos[index] = salariosOrdinarios[index] * 0.15;
            salariosBrutos[index] = salariosOrdinarios[index] + aumentos[index];
            deduccionesCCSS[index] = salariosBrutos[index] * 0.0917;
            salariosNetos[index] = salariosBrutos[index] - deduccionesCCSS[index];
            acumuladoNetoOperarios += salariosNetos[index];
            cantOperarios++;
            break;
        case 2: // tecnico
            aumentos[index] = salariosOrdinarios[index] * 0.10;
            salariosBrutos[index] = salariosOrdinarios[index] + aumentos[index];
            deduccionesCCSS[index] = salariosBrutos[index] * 0.0917;
            salariosNetos[index] = salariosBrutos[index] - deduccionesCCSS[index];
            acumuladoNetoTecnicos += salariosNetos[index];
            cantTecnicos++;
            break;
        case 3: // profesional
            aumentos[index] = salariosOrdinarios[index] * 0.05;
            salariosBrutos[index] = salariosOrdinarios[index] + aumentos[index];
            deduccionesCCSS[index] = salariosBrutos[index] * 0.0917;
            salariosNetos[index] = salariosBrutos[index] - deduccionesCCSS[index];
            acumuladoNetoProfesionales += salariosNetos[index];
            cantProfesionales++;
            break;
        default:
            cout << "Tipo de empleado no valido.\n";
            return;
    }
}
