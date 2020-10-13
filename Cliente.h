#pragma once
#include <string>
#include <vector>
#include "Cuenta.h"
#include "Genero.h"
using namespace std;

class Cuenta;
class Cliente
{
private:
	string idCliente;
	string nombre;
	string apellido;
	Genero genero;
	int telefono;
	vector <Cuenta*> cuentas;

public:
	Cliente();
	Cliente(string,string,string, Genero,int);
	const string &getIdCliente() const;
	void setIdCliente(const string &idCliente);
	const string &getNombre() const;
	void setNombre(const string &Nombre);
	const string &getApellido() const;
	void setApellido(const string &Apellido);
	Genero getGenero() const;
	void setGenero(Genero genero);
	const int &getTelefono()const;
	void setTelefono(const int &telefono);
	Cuenta* buscarCuenta(string);
	void agregarCuenta(Cuenta*);
	vector <Cuenta*> getCuentas();
	string toString();
	virtual ~Cliente();
};

