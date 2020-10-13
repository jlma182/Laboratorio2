#include "pch.h"
#include "Cuenta.h"
#include <sstream>
#include <iostream>

const int Cuenta::minSaldo = 100;

Cuenta::Cuenta()
{
	this->numeroCuenta = std::string();
	this->cliente = NULL;
	this->saldo = 0;
	this->consigna = 0;
	this->retiros = 0;
}

Cuenta::Cuenta(Cliente* cliente, const string &vnumeroCuenta, int vsaldo) : numeroCuenta(vnumeroCuenta), saldo(vsaldo)
{
	setNumeroCuenta(vnumeroCuenta);
	setCliente(cliente);
	setSaldo(vsaldo);
	this->consigna = 0;
	this->retiros = 0;
}

void Cuenta::setNumeroCuenta(string vnuemroCuenta)
{
	numeroCuenta = vnuemroCuenta;
}

void Cuenta::setCliente(Cliente* cliente)
{
	Cuenta::cliente = cliente;
}

void Cuenta::setSaldo(int vsaldo)
{
	saldo = vsaldo;
}

string Cuenta::parseNum(int valor)
{
	std::ostringstream aux;
	aux << valor;
	return aux.str();
}

string Cuenta::getnumeroCuenta()
{
	return numeroCuenta;
}

int Cuenta::getsaldo()
{
	return saldo;
}

int Cuenta::getconsigna()
{
	return consigna;
}

int Cuenta::getretiros()
{
	return retiros;
}

void Cuenta::devolverconsigna(int valor)
{
	setSaldo(getsaldo() + valor);
	consigna++;
}

bool Cuenta::retiro(int valor)
{
	if (valor <= getsaldo() - minSaldo)
	{
		setSaldo(getsaldo() - valor);
		retiros++;
		return true;
	}
	return false;
}

bool Cuenta::transferir(Cuenta* c, int monto)
{
	if (retiro(monto))
	{
		c->devolverconsigna(monto);
		return true;
	}
	return false;
}

string Cuenta::parseString(int valor)
{
	ostringstream aux;
	aux << valor;
	return aux.str();
}

string Cuenta::toString()
{
	return "Cuenta[nuemro de cuenta: " + numeroCuenta + ", saldo: " + parseString(saldo) + ", consigna: " + parseString(consigna) + ",retiros=" + parseString(retiros) + "]\n";
}

Cliente* Cuenta::getCliente()
{
	return cliente;
}

Cuenta::~Cuenta()
{
	std::cout << "espacio---->" << numeroCuenta << endl;
}