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

void levantar(cuenta cuentas[])
{
    FILE *p1;
    int i=0;
    cuenta aux;
    if( p1 = fopen("cuentas.bic", "rb+"))
    {
        cout << endl << "Se han levantado las cuentas exitosamente" << endl << endl;
        while(fread(&aux,sizeof(cuenta),1,p1))
        {
            cuentas[i]=aux;
            i++;
        }
    }
    else
    {
        cout<<"El archivo no puede ser encontrado o es inexistente.";
    }
    fclose(p1);

    return;
}

int cant_cuentas()
{
    FILE *p1;
    cuenta x;
    int i=0;
    if(p1=fopen("cuentas.bic","rb"))
    {
        fread(&x,sizeof(cuenta),1,p1);
        while(!feof(p1))
        {
            i++;
            fread(&x,sizeof(cuenta),1,p1);
        };
    }
    return i;
}

void cargar_cuenta(cuenta cuentas[],int &cant)
{
    cuenta c;
    cout << endl;
    cout <<  "Ingrese el ID de la cuenta: ";
    cin >> c.cuentaID;
    cout << "Ingrese fecha de creacion (AAAAMMDD): ";
    cin >> c.fechaCreacion;
    cout << "Ingrese el saldo: ";
    cin >> c.saldo;
    cout << "Ingrese numero de cliente: ";
    cin >> c.nroCliente;
    c.activa = true;
    cout << "********** Cuenta " << c.cuentaID << " agregada **********" << endl << endl;
    cuentas[cant] = c;
    cant++;

    return;
}

void estado_cuenta(cuenta cuentas[], int cant)
{
    cuenta tarjeta;
    int ID;
    bool encontrado = false;
    cout << endl << "Ingrese el ID de la cuenta o el Nro de cliente: ";
    cin >> ID;
    cout << endl;

    for(int i = 0; i < cant; i++)
    {
        if(!encontrado && ID == cuentas[i].cuentaID)
        {
            cuentas[i].activa = false;
            encontrado = true;
            cout << "***** Se ha desactivado la cuenta " << cuentas[i].cuentaID << " *****" << endl << endl;
        } else if(!encontrado && ID == cuentas[i].nroCliente)
        {
            cuentas[i].activa = false;
            if(i == cant - 1)
            {
                encontrado = true;
                cout << "***** Se han desactivado todas las cuentas del cliente " << cuentas[i].nroCliente << " *****" << endl << endl;
            };
        } else if(i == cant - 1)
        {
            cout << "**** Por favor, ingrese un ID de cuenta o Nro de cliente valido *****" << endl << endl;
        };
    };

    return;
}

int main()
{
    int cant = cant_cuentas();
    cuenta cuentas[cant+10];
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
        levantar(cuentas);
      break;
      case '2':/*cargar cuenta*/
         cargar_cuenta(cuentas,cant);
      break;
      case '3':/*Desactivar una cuenta existente.*/
        estado_cuenta(cuentas,cant);
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
