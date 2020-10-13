// laboratorio 2 (banco).cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include "pch.h"
#include <iostream>
#include "Cuenta.h"
#include "administrarBanco.h"

administrarBanco* banco;

void cargar()
{
	banco = new administrarBanco();
	banco->agregarCliente("c1", "ana", "perez", Genero::FEMALE, 2334);
	banco->agregarCliente("c2", "toribio", "judas", Genero::MALE, 232334);
	banco->agregarCliente("c1", "ana", "perez", Genero::FEMALE, 2334);
	banco->agregarCuenta("c1", "111", 500);
	banco->agregarCuenta("c2", "222", 1000);
	banco->agregarCuenta("c1", "333", 100);
}

void agregraClientes()
{
	cargar();
	for (Cuenta* cuenta : banco->getCuentas())
	{
		cout << cuenta->toString()<<"PERTENECE A"<<cuenta->getCliente()->toString();
	}
}

void agragarCuentas()
{
	cargar();
	if (banco->agregarCuenta("c1", "3232", 50000))
		cout << "CUENTA AGRAGADA" << endl;
	else
		cout << "ERROR NO agrego" << endl;
}

void consignar()
{
	cargar();
	if (banco->consignacion("111", 80))
	{
		cout << "Se consigno a la cuenta" << endl;
		cout << banco->buscarCuenta("111")->toString();
	}
	else
		cout<<"ERROR NO hubo cosignacion"<<endl;
}

void retiro()
{
	cargar();
	if (banco->retiros("222", 1))
	{
		cout << "Se retiro a la cuenta" << endl;
		cout << banco->buscarCuenta("222")->toString();
	}
	else
		cout << "ERROR NO hubo RETIRO" << endl;
}

int main()
{
	agregraClientes();
	agragarCuentas();
	consignar();
	retiro();

	
	
	/*Cuenta c1("1a", 500);
	c1.devolverconsigna(100);

	Cuenta* c2 = new Cuenta("2a", 200);

	if (c1.retiro(300))
		cout << c1.getnumeroCuenta() << "=====>Retiro exitoso"<<endl;
	else
		cout << c1.getnumeroCuenta() << "=====>RETIRO FALLIDO"<<endl;

	if (c2->transferir(&c1, 100))
		cout << c1.getnumeroCuenta() << "=====>Transferencia exitosa" << endl;
	else
		cout << c1.getnumeroCuenta() << "=====> transferencia FALLIDA" << endl;

	cout << c1.toString() << endl;
	cout << c2->toString() << endl;

	delete (c2);*/
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
