#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <cstdlib> // para usar system("CLS")
using namespace std;

const int MAX_EMPLEADOS = 100;

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

int numEmpleados = 0;
int cantOperarios = 0, cantTecnicos = 0, cantProfesionales = 0;
double acumuladoNetoOperarios = 0, acumuladoNetoTecnicos = 0, acumuladoNetoProfesionales = 0;


int main(int argc, char** argv) {
	return 0;
}
