#pragma once

#ifndef Actividad_h
#define Actividad_h

#include <stdio.h>
#include <string>

using namespace std;

struct Detalles {
	int duracion;
	string lugar;
};

struct Fecha {
	int dia;
	int mes;
	int anio;
	int hora;
};

class Actividad
{
	Fecha fecha;
	string nombre;
	Detalles detalles;
	string estatus;
	int prioridad;
	string esRutina;
	Actividad * sigAct;

public:

	Actividad(int, int, int, int, string, int, string, string, int, string, Actividad *);

	int getDia() { return this->fecha.dia; }
	int getMes() { return this->fecha.mes; }
	int getAnio() { return this->fecha.anio; }
	int getHora() { return this->fecha.hora; }
	string getNombre() { return this->nombre; }
	int getD_Duracion() { return this->detalles.duracion; }
	string getD_Lugar() { return this->detalles.lugar; }
	string getEstatus() { return this->estatus; }
	int getPrioridad() { return this->prioridad; }
	string getEsRutina() { return this->esRutina; }

	Actividad * getSigAct() { return this->sigAct; }

	void setFecha(int n_dia, int n_mes, int n_anio, int n_hora) { this->fecha.dia = n_dia; this->fecha.mes = n_mes; this->fecha.anio = n_anio; this->fecha.hora = n_hora; }
	void setNombre(string n_nombre) { this->nombre = n_nombre; }
	void setD_Duracion(int n_duracion) { this->detalles.duracion = n_duracion; }
	void setD_Lugar(string n_lugar) { this->detalles.lugar = n_lugar; }
	void setEstatus(string n_estatus) { this->estatus = n_estatus; }
	void setPrioridad(int n_prioridad) { this->prioridad = n_prioridad; }
	void setEsRutina(string n_esRutina) { this->esRutina = n_esRutina; }

	void setSigAct(Actividad * n_sigAct) { this->sigAct = n_sigAct; }

	//void imprimirBloqueAct();
};

#endif 