#pragma once
#include "Cuenta.h"
#include "Cliente.h"

class administrarBanco
{
private:
	vector<Cuenta*> cuentas;
	vector<Cliente*> clientes;
public:
	administrarBanco();
	Cliente* buscarCliente(string);
	bool agregarCliente(string,string,string, Genero, int);
	Cuenta* buscarCuenta(string);
	bool agregarCuenta(string,string, double);
	bool consignacion(string, double);
	bool retiros(string, double);
	bool transferencia(string,string, double);
	vector<Cliente*> getClientes();
	vector<Cuenta*> getCuentas();
	virtual ~administrarBanco();
};

