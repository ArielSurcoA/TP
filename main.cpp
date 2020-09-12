#include <iostream>
#include <stdio.h>
#include <conio.h>

using namespace std;

struct cuenta
{
   int cuentaID;
   int fechaCreacion;
   bool activa;
   float saldo;
   int nroCliente;
};

struct movimiento
{
    int movimientoID;
    int fechaHora;
    float monto;
    int cuentaID;
};

void menu()
{
    cout << "Seleccione una opcion:" << endl;
    cout << "1. Levantar las cuentas del archivo Cuentas.BIC" << endl;
    cout << "2. Cargar una nueva cuenta." << endl;
    cout << "3. Desactivar una cuenta existente." << endl;
    cout << "4. Buscar una cuenta por ID o por nro de cliente." << endl;
    cout << "5. Listar todas las cuentas activas ordenadas por saldo descendente." << endl;
    cout << "6. Procesar un lote de movimientos." << endl;
    cout << "7. Finalizar jornada (sobreescribir Cuentas.BIC)" << endl;
    cout << "ESC. Salir del programa" << endl;
}

int main()
{
    //int cant;
    //cuenta cuentas[cant+10];
    int opcion;
    do
    {
      menu();
    do
    {
     opcion=getch();

    }while(opcion>='8');

     switch(opcion)
     {
      case '1':/*Levanta las cuentas del archivo.*/
        //levantar(cuentas,cant);
      break;
      case '2':/*cargar cuenta*/
         //cargar_cuenta(cuentas,cant);
      break;
      case '3':/*Desactivar una cuenta existente.*/
        //estado_cuenta(cuentas,cant);
      break;
      case '4':/*Buscar una cuenta por id.*/
        //id_search(cuentas,cant);
      break;
      case '5':/*Listar todas las cuentas activas por saldo*/
        //active_list(cuentas,cant);
      break;
      case '6':/*Procesar lote de moviemientos*/
        //lote_proceso();
      break;
      case '7':/*Finalizar jornada.*/
       //fin_jornada();
      break;
     }
    }while(opcion!=27);

    return 0;
  }
