#include <iostream>
#include <stdio.h>
#include <conio.h>

using namespace std;

struct cuenta{
   long tarjetaid;
   int fechadecreacion;
   bool activa = true;
   float saldo;
   int nrocliente;
};

struct movimiento
{
    int movimientoid;
    long fechahora;
    float monto;
    int cuentaid;
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

int cant_cuentas()
{
    FILE *p1;
    cuenta x;
    int i=1;
    p1=fopen("cuentas.bic","rb");
    fread(&x,sizeof(cuenta),1,p1);
    while(!feof(p1))
    {
        i++;
        fread(&x,sizeof(cuenta),1,p1);
    }
    return i;
}

void levantar(cuenta cuentas[],int &cant)
{
   FILE *p1;
   int i=0;
   cuenta aux;
   if( p1 = fopen("cuentas.bic", "wt"))
   {
     fread(&aux,sizeof(cuenta),1,p1);
     cuentas[i]=aux;
     i++;
   }
  else
  {
    cout<<"El archivo no pude ser encontrado o es inexistente.";
  }

    fclose(p1);

    cant = cant_cuentas();
    return;
}

void cargar_cuenta(cuenta cuentas[],int &cant)
{
   FILE *p1;
   cuenta c;
   p1=fopen("cuentas.bic","ab");
    cout << "Ingrese id tarjeta: " << endl;
    cin >> c.tarjetaid;
    cout << "Ingrese fecha de creacion" << endl;
    cin >> c.fechadecreacion;
    cout << "Ingrese saldo:" << endl;
    cin >> c.saldo;
    cout << "Ingrese numero de cliente" << endl;
    cin >> c.nrocliente;
    cant++;
    cuentas[cant]=c;
   fwrite(&c,sizeof(cuenta),1,p1);
   fclose(p1);
}

void estado_cuenta(cuenta cuentas[], int cant)
{
    int ID;
    cout << "Ingrese el ID de la cuenta o el Nro de cliente" << endl;
    cin >> ID;
    for(int i=0; i<cant; i++)
    {
        if(cuentas[i].tarjetaid == ID || cuentas[i].nrocliente == ID)
        {
            cuentas[i].activa = false;
        };
    };
    cout << "La cuenta de ID " << ID << " ha sido desactivada" << endl;
    return;
}

void id_search(cuenta cuentas[], int &cant)
{
    int ID,anio,mes,dia;
    cout << "Ingrese el ID de la cuenta o el Nro de cliente" << endl;
    cin >> ID;

    cout << "ID de Cuenta | Fecha de Creacion | Saldo Disponible | Nro de Cliente" << endl;
    for(int i=0; i<cant; i++)
    {
        anio = cuentas[i].fechadecreacion / 10000;
        mes = cuentas[i].fechadecreacion % 10000 / 100;
        dia = cuentas[i].fechadecreacion % 100;
        if(cuentas[i].tarjetaid == ID || cuentas[i].nrocliente == ID)
        {
            cout << cuentas[i].tarjetaid << " | " << dia << "/" << mes << "/" << anio << " | " << cuentas[i].saldo << " | " <<     cuentas[i].nrocliente;
        };
    };
    return;
}

  void active_list(cuenta cuentas[],int cant)
{
   cuenta aux;
   cuenta aux2[cant];
   int o = 0;
   for(int h=0;h<cant;h++)
   {
   if(cuentas[h].activa==true)
   {
    aux2[o]=cuentas[h];
    o++;
   }

   }

   for(int i=0;i<cant;i++)
   {
       for(int j=0;j<cant;j++)
       {
           if(aux2[j].saldo<aux2[j+1].saldo)
           {
               aux=aux2[j+1];
               aux2[j+1]=aux2[j];
               aux2[j]=aux;
           }
       }

   }

   for(int i=0;i<cant;i++)
   {
       cout<<"Id tarjeta: "<<cuentas[i].tarjetaid<<endl;
   }

}



void lote_proceso()
{

}

void fin_jornada()
{

}

int main()
{

    int cant;
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
        levantar(cuentas,cant);
      break;
      case '2':/*cargar cuenta*/
         cargar_cuenta(cuentas,cant);
      break;
      case '3':/*Desactivar una cuenta existente.*/
        estado_cuenta(cuentas,cant);
      break;
      case '4':/*Buscar una cuenta por id.*/
        id_search(cuentas,cant);
      break;
      case '5':/*Listar todas las cuentas activas por saldo*/
        active_list(cuentas,cant);
      break;
      case '6':/*Procesar lote de moviemientos*/
        lote_proceso();
      break;
      case '7':/*Finalizar jornada.*/
       fin_jornada();
      break;
     }
    }while(opcion!=27);


    return 0;
  }
