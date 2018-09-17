#include "pch.h"
#include "Actividad.h"
#include <string>

using namespace std;

Actividad::Actividad(int n_dia, int n_mes, int n_anio, int n_hora, string n_nombre, int n_duracion, string n_lugar, string n_estatus, int n_prioridad, string n_esRutina, Actividad * ult)
{
	this->fecha.dia = n_dia;
	this->fecha.mes = n_mes;
	this->fecha.anio = n_anio;
	this->fecha.hora = n_hora;
	this->nombre = n_nombre;
	this->detalles.duracion = n_duracion;
	this->detalles.lugar = n_lugar;
	this->estatus = n_estatus;
	this->prioridad = n_prioridad;
	this->esRutina = n_esRutina;
	this->sigAct = ult;
};