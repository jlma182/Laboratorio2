#include "pch.h"
#include "administrarBanco.h"


administrarBanco::administrarBanco()
{
}


administrarBanco::~administrarBanco()
{
}

Cliente *administrarBanco::buscarCliente(string idCliente) 
{
	for (Cliente* cliente : clientes)
	{
		if (cliente->getIdCliente().compare(idCliente) == 0) 
		{
			return cliente;
		}
	}
	return NULL;
}

bool administrarBanco::agregarCliente(string idCliente,string nombre,string apellido, Genero genero, int telefono) 
{
	if (!buscarCliente(idCliente)) 
	{
		clientes.push_back(new Cliente(idCliente, nombre, apellido, genero, telefono));
		return true;
	}
	return false;
}

Cuenta *administrarBanco::buscarCuenta(string idCuenta) {
	for (Cuenta* cuenta : cuentas)
	{
		if (cuenta->getnumeroCuenta().compare(idCuenta) == 0) 
			return cuenta;
	}
	return NULL;
}

bool administrarBanco::agregarCuenta(string idCliente,string numero, double valor)
{
	Cliente* cliente = buscarCliente(idCliente);
	if (cliente)
	{
		if (!buscarCuenta(numero)) 
		{
			Cuenta* cuenta = new Cuenta(cliente, numero, valor);
			cuentas.push_back(cuenta);
			cliente->agregarCuenta(cuenta);
			return true;
		}
		return false;
	}
	return false;
}

bool administrarBanco::consignacion(string numero, double valor)
{
	Cuenta* cuenta = buscarCuenta(numero);
	if (cuenta) 
	{
		cuenta->devolverconsigna(valor);
		return true;
	}
	return false;
}

bool administrarBanco::retiros(string numero, double valor) 
{
	Cuenta* cuenta = buscarCuenta(numero);
	if (cuenta)
	{
		return cuenta->retiro(valor);
	}
	return false;
}

bool administrarBanco::transferencia(string origen,string destino, double valor)
{
	Cuenta* ctaOrigen = buscarCuenta(origen);
	Cuenta* ctaDestino = buscarCuenta(destino);
	if (ctaOrigen && ctaDestino) 
	{
		return ctaOrigen->transferir(ctaDestino, valor);
	}
	return false;
}

vector<Cliente *> administrarBanco::getClientes()
{
	return vector<Cliente *>(clientes);
}

vector<Cuenta *> administrarBanco::getCuentas()
{
	return vector<Cuenta *>(cuentas);
}