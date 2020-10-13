#pragma once
#include <string>
#include "Cliente.h"
using namespace std;

class Cliente;

class Cuenta
{
private:
	string numeroCuenta;
	int saldo;
	int consigna;
	int retiros;
	void setSaldo(int);
	string parseString(int);
	Cliente* cliente;
public:
	const static int minSaldo;
	Cuenta();
	Cuenta(Cliente * cliente, const string & vnumeroCuenta, int vsaldo);
	//Cuenta(Cliente*,string, int);
	//Cuenta(Cliente*, string &number, double residue);

	void setCliente(Cliente*);
	void setNumeroCuenta(string);
	string getnumeroCuenta();
	int getsaldo();
	int getconsigna();
	int getretiros();
	Cliente* getCliente();
	void devolverconsigna(int);
	bool retiro(int);
	bool transferir(Cuenta*, int);
	static string parseNum(int);
	string toString();
	virtual ~Cuenta();
};

