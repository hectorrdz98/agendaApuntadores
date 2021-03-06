// AplicacionAgendaListaEnlazada.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include "pch.h"
#include "Actividad.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>

#pragma warning(disable : 4996)         // Para evitar el error de seguridad

using namespace std;

Actividad * ultAct = NULL;
Actividad * primeraAct = NULL;

int totalAct = 0;

int mostrarMenu()
{
	int opcion;
	cout << "-Bievenido a su agenda-" << endl;
	cout << "1.- Ver agenda" << endl;
	cout << "2.- Control de la agenda" << endl;
	cout << "3.- Ver horas dedicadas" << endl;
	cout << "4.- Salir" << endl;
	cin >> opcion;
	return opcion;
}

int mostrarMenuControlAgenda() 
{
	system("cls");
	int opcion;
	cout << "-Control de agenda-" << endl;
	cout << "1.- Agregar actividad" << endl;
	cout << "2.- Modificar actividad" << endl;
	cout << "3.- Eliminar actividad" << endl;
	cout << "4.- Regresar" << endl;
	cin >> opcion;
	return opcion;
}

void imprimirBloqueAct(Actividad * actActual)
{
	cout << "- " << actActual->getNombre() << " -" << endl;
	string probHora = to_string(actActual->getHora());
	try {
		cout << actActual->getDia() << "/" << actActual->getMes() << "/" << actActual->getAnio() << " - " << probHora.at(0) << probHora.at(1) << ":" << probHora.at(2) << probHora.at(3) << " hrs. - " << endl;
	}
	catch (exception){
		cout << actActual->getDia() << "/" << actActual->getMes() << "/" << actActual->getAnio() << " - " << 0 << probHora.at(0) << ":" << probHora.at(1) << probHora.at(2) << " hrs. - " << endl;
	}
	
	int horas = actActual->getD_Duracion() / 60;
	cout << "Duracion: ";
	if (horas > 0) {
		cout << horas << " hrs. ";
	}
	cout << actActual->getD_Duracion() % 60 << " min." << endl;
	cout << "Lugar: " << actActual->getD_Lugar() << endl;
	cout << "Estatus: " << actActual->getEstatus() << endl;
	if (actActual->getEsRutina()!="no") {
		cout << "Es rutina " << actActual->getEsRutina() << endl;
	}
	else {
		cout << "No es rutina" << endl;
	}
}

bool checkBisiesto(int n_anio) {
	if (n_anio % 4 == 0) {
		if (n_anio % 100 != 0) {
			if (n_anio % 400 == 0) {
				return true;
			}
			else {
				return false;
			}
		}
		else {
			return true;
		}
	}
	else {
		return false;
	}
}

bool compFecha(int n_dia, int n_mes, int n_anio, int n_hora) {
	if (n_anio >= 2018 && n_anio <= 2099) {
		if (n_mes >= 1 && n_mes <= 7) {
			if (n_mes % 2 != 0) {
				if (n_dia >= 1 && n_dia <= 31) {
					if (n_hora >= 0 && n_hora <= 2400) {
						return true;
					}
					else {
						cout << "Hora no valida" << endl;
						return false;
					}
				}
				else {
					cout << "Dia no valido" << endl;
					return false;
				}
			}
			else {
				if (n_mes != 2) {
					if (n_dia >= 1 && n_dia <= 30) {
						if (n_hora >= 0 && n_hora <= 2400) {
							return true;
						}
						else {
							cout << "Hora no valida" << endl;
							return false;
						}
					}
					else {
						cout << "Dia no valido" << endl;
						return false;
					}
				}
				else {
					if (checkBisiesto(n_anio)) {
						if (n_dia >= 1 && n_dia <= 29) {
							if (n_hora >= 0 && n_hora <= 2400) {
								return true;
							}
							else {
								cout << "Hora no valida" << endl;
								return false;
							}
						}
						else {
							cout << "Dia no valido" << endl;
							return false;
						}
					}
					else {
						if (n_dia >= 1 && n_dia <= 28) {
							if (n_hora >= 0 && n_hora <= 2400) {
								return true;
							}
							else {
								cout << "Hora no valida" << endl;
								return false;
							}
						}
						else {
							cout << "Dia no valido" << endl;
							return false;
						}
					}
				}
			}
		}
		else if (n_mes > 7 && n_mes <= 12) {
			if (n_mes % 2 == 0) {
				if (n_dia >= 1 && n_dia <= 31) {
					if (n_hora >= 0 && n_hora <= 2400) {
						return true;
					}
					else {
						cout << "Hora no valida" << endl;
						return false;
					}
				}
				else {
					cout << "Dia no valido" << endl;
					return false;
				}
			}
			else {
				if (n_dia >= 1 && n_dia <= 30) {
					if (n_hora >= 0 && n_hora <= 2400) {
						return true;
					}
					else {
						cout << "Hora no valida" << endl;
						return false;
					}
				}
				else {
					cout << "Dia no valido" << endl;
					return false;
				}
			}
		}
		else {
			cout << "Mes no valido" << endl;
			return false;
		}
	}
	else {
		cout << "Anio no valido" << endl;
		return false;
	}
}

// Por ahora siempre es 1, mas adelante implementaremos esto, pero necesitamos ordenar la lista
int obtenerPrioridad(int n_dia, int n_mes, int n_anio, int n_hora) {
	return 1;
}

bool agregarActividad()
{
	system("cls");
	string nombre, lugar, estatus;
	int duracion, dia, mes, anio, hora;

	cout << "- Creacion de actividad -" << endl;
	cout << "Ingresa el nombre: ";
	cin >> nombre;
	cout << "Ingresa el dia: ";
	cin >> dia;
	cout << "Ingresa el mes: ";
	cin >> mes;
	cout << "Ingresa el anio: ";
	cin >> anio;
	cout << "Ingresa la hora (4 digitos): ";
	cin >> hora;
	if (to_string(hora).length() >= 3 && to_string(hora).length() <= 4) {
		if (compFecha(dia, mes, anio, hora)) {
			cout << "Ingresa la duracion (min): ";
			cin >> duracion;
			cout << "Ingresa el lugar: ";
			cin >> lugar;
			cout << "Es una rutina (si/no): ";
			string prob;
			cin >> prob;
			if (prob == "si") {
				string tipoRutina;
				cout << "Que tipo de rutina (Diaria, Semanal): ";
				cin >> tipoRutina;
				if (tipoRutina == "Diaria" || tipoRutina == "Semanal") {
					Actividad * auxAct = new Actividad(
						dia, mes, anio, hora, nombre, duracion, lugar, "Incompleta", obtenerPrioridad(dia, mes, anio, hora), tipoRutina, NULL
					);
					if (totalAct == 0) {
						primeraAct = auxAct;
					}
					else {
						ultAct->setSigAct(auxAct);
					}
					ultAct = auxAct;
					totalAct++;
					return true;
				}
				else {
					cout << "Tipo de rutina no valido...";
					system("pause");
					return false;
				}
			}
			else if (prob == "no") {
				Actividad * auxAct = new Actividad(
					dia, mes, anio, hora, nombre, duracion, lugar, "Incompleta", obtenerPrioridad(dia, mes, anio, hora), "no", NULL
				);
				if (totalAct == 0) {
					primeraAct = auxAct;
				}
				else {
					ultAct->setSigAct(auxAct);
				}
				ultAct = auxAct;
				totalAct++;
				return true;
			}
			else {
				cout << "Dato introducido no valido..." << endl;
				system("pause");
				return false;
			}

		}
		else {
			system("pause");
			return false;
		}
	}
	else {
		cout << "Hora introducida en el formato incorrecto..." << endl;
		system("pause");
		return false;
	}
	
}

void mostrarActividades() {
	system("cls");
	Actividad * auxAct = primeraAct;
	if (totalAct != 0) {
		for (int a = 0; a < totalAct; a++) {
			imprimirBloqueAct(auxAct);
			auxAct = auxAct->getSigAct();
			cout << "" << endl;
		}
	}
	else {
		cout << "No hay actividades" << endl;
	}
	system("pause");
	system("cls");
}

Actividad * buscarAct(string nombreAct) {
	Actividad * encAct = NULL;
	Actividad * probAct = primeraAct;
	for (int a = 0; a < totalAct; a++) {
		if (probAct->getNombre() == nombreAct) {
			encAct = probAct;
			break;
		}
		probAct = probAct->getSigAct();
	}
	return encAct;
}

bool posObtenidaEsActFinal(string nombreAct) {
	bool comp = false;
	Actividad * probAct = primeraAct;
	for (int a = 0; a < totalAct; a++) {
		if (probAct->getNombre() == nombreAct) {
			if (a + 1 == totalAct) {
				comp = true;
			}
			break;
		}
		probAct = probAct->getSigAct();
	}
	return comp;
}

bool cosaModExiste(string cosa) {
	if (cosa == "Fecha" || cosa == "Nombre" || cosa == "Duracion" || cosa == "Lugar" || cosa == "Estatus" || cosa == "Rutina") {
		return true;
	}
	else {
		return false;
	}
}

bool solicitarCambio(string cosa, Actividad * actActual) {
	if (cosa == "Fecha") {
		int dia, mes, anio, hora;
		cout << "Ingresa el dia: ";
		cin >> dia;
		cout << "Ingresa el mes: ";
		cin >> mes;
		cout << "Ingresa el anio: ";
		cin >> anio;
		cout << "Ingresa la hora: ";
		cin >> hora;
		if (compFecha(dia, mes, anio, hora)) {
			actActual->setFecha(dia, mes, anio, hora);
			return true;
		}
		else {
			return false;
		}
	}
	if (cosa == "Nombre") {
		string nombre;
		cout << "Ingresa el nombre: ";
		cin >> nombre;
		actActual->setNombre(nombre);
		return true;
	}
	if (cosa == "Duracion") {
		int duracion;
		cout << "Ingresa la duracion (min): ";
		cin >> duracion;
		actActual->setD_Duracion(duracion);
		return true;
	}
	if (cosa == "Lugar") {
		string lugar;
		cout << "Ingresa el lugar: ";
		cin >> lugar;
		actActual->setD_Lugar(lugar);
		return true;
	}
	if (cosa == "Estatus") {
		string estatus;
		cout << "¿Cual es el estatus de la actividad?: ";
		cin >> estatus;
		actActual->setEstatus(estatus);
		return true;
	}
	if (cosa == "Rutina") {
		cout << "Es una rutina (si/no): ";
		string prob;
		cin >> prob;
		if (prob == "si") {
			string tipoRutina;
			cout << "Que tipo de rutina (Diaria, Semanal): ";
			cin >> tipoRutina;
			if (tipoRutina == "Diaria" || tipoRutina == "Semanal") {
				actActual->setEsRutina(tipoRutina);
				return true;
			}
			else {
				cout << "Tipo de rutina no valido...";
				return false;
			}
		}
		else {
			actActual->setEsRutina("no");
			return true;
		}
	}
}

void modificarActividad() {
	system("cls");
	string nombreAct;
	cout << "Ingresa el nombre de la actividad a modificar: ";
	cin >> nombreAct;
	Actividad * actMod = buscarAct(nombreAct);
	if (actMod != NULL) {
		string cosaModificar;
		cout << "¿Que cosa deseas modicar...? ";
		cin >> cosaModificar;
		if (cosaModExiste(cosaModificar)) {
			if (solicitarCambio(cosaModificar, actMod)) {
				cout << "Cambio existoso" << endl;
			}
		}
		else {
			cout << "Lo que solicitaste modificar no existe..." << endl;
		}
	}
	else {
		cout << "No se encontro la actividad mencionada..." << endl;
	}
	system("pause");
}

Actividad * buscarActAnterior(string nombreAct) {
	Actividad * encAct = NULL;
	Actividad * probAct = primeraAct;
	for (int a = 0; a < totalAct; a++) {
		if (probAct->getSigAct() != NULL) {
			if (probAct->getSigAct()->getNombre() == nombreAct) {
				encAct = probAct;
				break;
			}
			probAct = probAct->getSigAct();
		}
	}
	return encAct;
}

void eliminarActividad() {
	system("cls");
	string nombreAct;
	cout << "Ingresa el nombre de la actividad a eliminar: ";
	cin >> nombreAct;
	Actividad * actMod = buscarAct(nombreAct);
	if (actMod != NULL) {
		Actividad * actAnterior = buscarActAnterior(nombreAct);
		if (actAnterior == NULL) {
			primeraAct = actMod->getSigAct();
		}
		else {
			actAnterior->setSigAct(actMod->getSigAct());
			if (posObtenidaEsActFinal) {
				ultAct = actAnterior;
			}
		}
		cout << actMod->getNombre() << " eliminada" << endl;
		totalAct--;
		delete actMod;
	}
	else {
		cout << "No se encontro la actividad mencionada..." << endl;
	}
	system("pause");
}

void checkHorasTotales() {
	system("cls");
	Actividad * auxAct = primeraAct;
	string nombreAct;
	cout << "Ingresa el nombre de la actividad a modificar: ";
	cin >> nombreAct;
	int totalHoras = 0;
	if (totalAct != 0) {
		for (int a = 0; a < totalAct; a++) {
			if (auxAct->getNombre() == nombreAct) {
				if (auxAct->getEsRutina() == "Diaria") {
					totalHoras += (7 * auxAct->getD_Duracion());
				}
				else {
					totalHoras += auxAct->getD_Duracion();
				}
				
			}
			auxAct = auxAct->getSigAct();
		}
		int horas = totalHoras / 60;
		cout << "Tiempo dedicado a " << nombreAct << " semanalmente: ";
		if (horas > 0) {
			cout << horas << " hrs. ";
		}
		cout << totalHoras % 60 << " min." << endl;
	}
	else {
		cout << "No hay actividades" << endl;
	}
	system("pause");
	system("cls");
}

int main()
{
	bool salir = false;
	do {
		switch (mostrarMenu()) {
			case 1: {
				mostrarActividades();
				break;
			}
			case 2: {
				bool salirsubmenu = false;
				do {
					switch (mostrarMenuControlAgenda()) {
						case 1: {
							agregarActividad();
							break;
						}
						case 2: {
							modificarActividad();
							break;
						}
						case 3: {
							eliminarActividad();
							break;
						}
						case 4: {
							salirsubmenu = true;
							system("cls");
							break;
						}
						default: {
							cout << "Opcion no valida" << endl;
							break;
						}
					}
				} while (!salirsubmenu);
				break;
			}
			case 3: {
				checkHorasTotales();
				break;
			}
			case 4: {	
				salir = true;
				break;
			}
			default: {
				cout << "Opcion no valida" << endl;
				break;
			}
		}
	} while (!salir);
}
