#include "pch.h"
#include <sstream>
#include "Cliente.h"


Cliente::Cliente()
{
}

Cliente::Cliente(string vidCliente, string vNombre, string vApellido, Genero vGenero, int vTelefono)
{
	idCliente = vidCliente;
	nombre = vNombre;
	apellido = vApellido;
	genero = vGenero;
	telefono = vTelefono;
}

const string &Cliente::getIdCliente() const 
{
	return idCliente;
}

void Cliente::setIdCliente(const string &idCliente)
{
	Cliente::idCliente = idCliente;
}

const string &Cliente::getNombre() const 
{
	return nombre;
}

void Cliente::setNombre(const string &Nombre) 
{
	Cliente::nombre = Nombre;
}

const string &Cliente::getApellido() const
{
	return apellido;
}

void Cliente::setApellido(const string &Apellido)
{
	Cliente::apellido = Apellido;
}

Genero Cliente::getGenero() const
{
	return genero;
}

void Cliente::setGenero(Genero Genero)
{
	Cliente::genero = Genero;
}

const int &Cliente::getTelefono() const
{
	return telefono;
}

void Cliente::setTelefono(const int &Telefono)
{
	Cliente::telefono = Telefono;
}

//agregamos cuenta con una referencia valida
void Cliente::agregarCuenta(Cuenta* cuenta)
{
	cuentas.push_back(cuenta);
}

//devuelve arreglo de cuentas de cliente
std::vector<Cuenta *> Cliente::getCuentas()
{
	return vector<Cuenta *>(Cliente::cuentas);
}


string Cliente::toString()
{
	string genero = Cliente::genero == Genero::FEMALE ? "Femenino" : "Masculino";
	
	return "Cliente[idcliente=" + idCliente + ", apelledo= " + apellido + ", nombre= " + nombre + ", genero= " + genero + ", telefono= "  "]\n";
}

Cliente::~Cliente()
{
	for (Cuenta* cuenta : cuentas) 
	{
		delete(cuenta);
	}
}
