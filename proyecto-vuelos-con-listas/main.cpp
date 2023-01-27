/************************************************************************************************
taller numero 7 estructura de datos
univercidad tecnologica de pereira 03/04/2022
brayan chiquito
    objetivo:    La aerolínea “VIAJAR”, desea hacer un manejo adecuado de los vuelos que realiza
                 periódicamente. De cada vuelo se tienen los siguientes datos: Nro de vuelo,
                 ciudad origen, ciudad destino, matrícula del avión, nombre del piloto,
                 hora del vuelo y fecha del vuelo, además se tiene el estado del vuelo
                 (programado o realizado). Cada vuelo tiene a su vez asignado una lista de
                 pasajeros; de cada pasajero se tiene la cédula, el nombre, el teléfono y el
                 estado (con reserva o a bordo siempre que el vuelo no se haya realizado).

                 La información de los vuelos viene en el archivo de texto “VUELOS.TXT” con el
                 siguiente formato: nro de vuelo (6 caracteres), origen (8), destino (8),
                 matricula del avion (6), nombre del piloto (20), hora de vuelo (4), fecha de
                 vuelo (6), estado (0: programado, 1: realizado). Ejemplo de registro:

                 "123445 BOGOTA MEDELLIN 222222 FELIPE-MONTENEGRO 1200 250122 0123445 BOGOTA
                 MEDELLIN 222222 FELIPE-MONTENEGRO 1200 250122 0"

                 Los datos de cada pasajero vienen en el archivo de texto “PASAJERO.TXT”, numero
                 de vuelo (6 caracteres), cédula (9), nombre (20), telefono (10), estado
                 (1: reserva, 2: a bordo). Ejemplo de registro:

                 "123445 5687654321 ANA-MARIA-RAMIREZ 03632134521 2"
                 La información de los vuelos se sube a memoria y se almacenan en una lista que
                 contiene  una estructura con el mismo formato del archivo, con los pasajeros
                 también sucede lo mismo.

                 El programa debe permitir hacer lo siguiente:

                 1.Crear una estructura de multilista para el manejo de los datos de la
                 aerolinea, con los vuelos como la lista principal y para cada vuelo la
                 sublista de pasajeros.
                 2.Se debe poder adicionar vuelos.
                 3.Adicionar pasajeros.
                 3.Obtener listados (pasajeros de un vuelo realizado o programado, lista de
                   vuelos programados, lista de vuelos realizados).
                 4.Dada la cédula de una persona, obtener un listado de los vuelos que ha
                   realizado y de los vuelos que tiene programado realizar.
                 5.Cuando se hace un vuelo, se debe modificar el estado del vuelo a realizado.
                 6.Se debe tener una opción que permita registrar cuando un pasajero pasa a bordo.

************************************************************************************************/

#include <iostream>
#include <fstream>
#include <string.h>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
using namespace std;
/************************************************************************************************
estructura validar fecha
************************************************************************************************/
struct Fecha{
    int dd;
    int mm;
    int aaaa;
};
/************************************************************************************************
estructutura nodo vuelp
************************************************************************************************/
struct Vuelo{
    char NroVuelo[7];
    char Origen[13];
    char Destino[13];
    char MatriAvion[7];
    char NombrePilo[20];
    char Horavuelo[5];
    char fechaVuelo[7];
    int estado;
    Vuelo *sgte;
    struct Pasajero *ListaP;
};
/************************************************************************************************
estrucutura nodo pasajero
************************************************************************************************/
struct Pasajero{
    char NroVuelo[7];
    char cedula[11];
    char nombre[20];
    char telefono[12];
    int estado;
    Pasajero *sgte;
};
/************************************************************************************************
definicion de litas
************************************************************************************************/
typedef struct Vuelo *Tlista;
typedef struct Pasajero *TlistaPasa;

/************************************************************************************************
funcion gotoxy
    objetivo:      manejar de uan forma mas estetica los menus
************************************************************************************************/
void gotoxy(int x,int y){
    HANDLE hcon;
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y = y;
    SetConsoleCursorPosition(hcon,dwPos);
}

/***********************************************************************************************
funcion validar fecha
    objetivo:       validar si una fecha es valida o no teniendo en cuenta los años bisiestos
    funcion:        ValidarFecha(Fecha anio,Fecha dia,Fecha mes)
    ejemplo:        ingresar 20/01/21

    resultado:      "fecha valida."
***********************************************************************************************/
bool ValidarFecha(Fecha anio,Fecha dia,Fecha mes){
    bool r;
    if(anio.aaaa%4!=0 || (anio.aaaa%100==0 && anio.aaaa%400!=0)){     //se determina si es o no un año bisiesto
        switch(mes.mm){                 //se busca el mes
            case 1:
                if(dia.dd<=31){
                    r=true;
                }
            break;
            case 2:
                if(dia.dd<=28){
                    r=true;
                }
            break;
            case 3:
                if(dia.dd<=31){
                    r=true;
                }
            break;
            case 4:
                if(dia.dd<=30){
                    r=true;
                }
            break;
            case 5:
                if(dia.dd<=31){
                    r=true;
                }
            break;
            case 6:
                if(dia.dd<=30){
                    r=true;
                }
            break;
            case 7:
                if(dia.dd<=31){
                    r=true;
                }
            break;
            case 8:
                if(dia.dd<=31){
                    r=true;
                }
            break;
            case 9:
                if(dia.dd<=30){
                    r=true;
                }
            break;
            case 10:
                if(dia.dd<=31){
                    r=true;
                }
            break;
            case 11:
                if(dia.dd<=30){
                    r=true;
                }
            break;
            case 12:
                if(dia.dd<=31){
                    r=true;
                }
            break;
            default:                    //en caso de no estar fecha no valida
                r=false;
        }
    }
    else{
        switch(mes.mm){
            case 1:
                if(dia.dd<=31){
                    r=true;
                }
            break;
            case 2:
                if(dia.dd<=29){
                    r=true;
                }
            break;
            case 3:
                if(dia.dd<=31){
                    r=true;
                }
            break;
            case 4:
                if(dia.dd<=30){
                    r=true;
                }
            break;
            case 5:
                if(dia.dd<=31){
                    r=true;
                }
            break;
            case 6:
                if(dia.dd<=30){
                    r=true;
                }
            break;
            case 7:
                if(dia.dd<=31){
                    r=true;
                }
            break;
            case 8:
                if(dia.dd<=31){
                    r=true;
                }
            break;
            case 9:
                if(dia.dd<=30){
                    r=true;
                }
            break;
            case 10:
                if(dia.dd<=31){
                    r=true;
                }
            break;
            case 11:
                if(dia.dd<=30){
                    r=true;
                }
            break;
            case 12:
                if(dia.dd<=31){
                    r=true;
                }
            break;
            default:
                r=false;
        }
    }
    return r;
}

/************************************************************************************************
funcion leer archivo 2
    objetivo:     leer archivo de pasajeros y guardar en la lista respectiva
    funcion:      leerArchivo2(TlistaPasa &pasajeros,int numVuel)
                  leer de el archivo "PASAJEROS.TXT" los datos donde se filtran solo los pasajeros
                  que tengas el mismo numero de vuelo enviado desde la funcion crear archivos 1
                  donde tabien se crea la sublista de pasajero ligada al numero de vuelo
                  correspondiente
    ejemplo:      (lista,123445)

    resultado:    (pasajeros)
                  123445 5687654321 ANA-MARIA-RAMIREZ 03632134521 2
                  123445 5680000021 CLARA-HERNANDEZ 03600004521 2
                  123445 1680003021 FERNANDO-SUAREZ 03600554521 2
************************************************************************************************/

void leerArchivo2(TlistaPasa &pasajeros,int numVuel){
    ifstream leer;
    TlistaPasa p;
    int aux;
	char cadena[20];                //cadena para lectura
	fflush(stdin);
	leer.open ("PASAJEROS.txt");    //abrir archivo
	if(leer.good()){
        while(!leer.eof()){         //leer hasta que documento este vacion
            leer>>cadena;
            aux=atoi(cadena);
            if(aux==numVuel){       //solo crear pasajero si tiene le mismo numero de vuelo
                p=new(Pasajero);    //nodo pasajero
                strcpy(p->NroVuelo,cadena);     //asignar valores
                fflush(stdin);                  //limpiar buffer
                leer>>cadena;
                strcpy(p->cedula,cadena);
                fflush(stdin);
                leer>>cadena;
                strcpy(p->nombre,cadena);
                fflush(stdin);
                leer>>cadena;
                strcpy(p->telefono,cadena);
                fflush(stdin);
                leer>>cadena;
                p->estado=atoi(cadena);
                fflush(stdin);
                p->sgte=pasajeros;              //p siguiente apunta a pasajero -> NULL o -> dato
                pasajeros = p;                  //pasajero apunta a p
            }
        }
	}
	leer.close();                               //cerrar lectura
}
/************************************************************************************************
funcion leer archivos 1
	objetivo:      leer datos de vuelos y guardar en lista respectiva
    funcion:       leerArchivo1(Tlista &lista)
                   leer del archivo "VUELOS.TXT" cada dato genrando un nuevo nodo en la lsita y
                   a su ves asiganadole a cada vuelo una sublista de la funcion leer vuelos 2
                   creando una lista de vuelos
    ejemplo:       (lista)

    resultado:     123445 BOGOTA MEDELLIN 222222 FELIPE-MONTENEGRO 1200 250122 0
                   123654 PERERIRA CALI 222000 MANOLO-PEREZ 1430 210421 0
                   132543 BARRANQUILLA CALI 111000 LEONARDO-DAVINCI 1000 220421 1
                   876543 SAN-ANDRES BUENAVENTURA 111111 CLAUDIA-LOPEZ 1100 231142 1
************************************************************************************************/

void leerArchivo1(Tlista &lista){
    ifstream leer;          //leer
    Tlista q;               //nodo tipo lista
    int numVuel;
	char cadena[20];        //cadena para lectura
	fflush(stdin);
	leer.open ("VUELOS.txt");       //abrir archivo
	if(leer.good()){
        while(!leer.eof()){         //leer hasta que documento este vacion
            TlistaPasa pasajeros = NULL;        //nodo tipo pasajeros
            q=new(Vuelo);                       //nuevo nodo
            leer>>cadena;                       //leer en cadena
            strcpy(q->NroVuelo,cadena);         //asignar valor
            numVuel=atoi(cadena);
            fflush(stdin);                      //limpiar buffer
            leer>>cadena;
            strcpy(q->Origen,cadena);
            fflush(stdin);
            leer>>cadena;
            strcpy(q->Destino,cadena);
            fflush(stdin);
            leer>>cadena;
            strcpy(q->MatriAvion,cadena);
            fflush(stdin);
            leer>>cadena;
            strcpy(q->NombrePilo,cadena);
            fflush(stdin);
            leer>>cadena;
            strcpy(q->Horavuelo,cadena);
            fflush(stdin);
            leer>>cadena;
            strcpy(q->fechaVuelo,cadena);
            fflush(stdin);
            leer>>cadena;
            q->estado=atoi(cadena);
            fflush(stdin);
            leerArchivo2(pasajeros,numVuel);    //llamar a leer 2 para pasajeros y generar sublista
            q->ListaP=pasajeros;                //asigar puntero a sublista de vuelos
            q->sgte=lista;                      //q siguiente apunta a lista -> NULL o -> dato
            lista = q;                          //lista apunta a q
        }
	}
	leer.close();                               //cerrar lectura
}
/************************************************************************************************
menu principal
************************************************************************************************/
void menu(){
   for(int i=0;i<20;i++){           //recuadro para indicar menu
        cout<<char(223)<<char(223);
    }
    gotoxy(12,1);
    cout<<"MENU PRICIPAL";
    gotoxy(0,2);
    for(int i=0;i<20;i++){          //recuadro apra indicar menu
        cout<<char(223)<<char(223);
    }
    gotoxy(4,3);
    cout<<"1.ADICIONAR VUELO";
    gotoxy(4,4);
    cout<<"2.ADICIONAR PASAJEROS";
    gotoxy(4,5);
    cout<<"3.LISTADOS";
    gotoxy(4,6);
    cout<<"4.REGISTRO POR CEDULA DE VUELOS";
    gotoxy(4,7);
    cout<<"5.MODIFICAR ESTADO DE VUELO";
    gotoxy(4,8);
    cout<<"6.REGISTRAR PASAJERO";
    gotoxy(4,9);
    cout<<"7.SALIR";
    gotoxy(0,10);
    for(int i=0;i<20;i++){              //cerrar cuadro
        cout<<char(196)<<char(196);
    }
    gotoxy(0,11);
    cout<<"DIGITE OPCION:";
}

/***********************************************************************************************
funcion agregar vuelo
    objetivo:       Se debe poder adicionar vuelos.
    funcion:        agregarVuelo(Tlista &lista)
                    mediantes esta funcion se crea un nuevo nodo agragarndo los dato pedidos
                    por la esctructura y dejando a las sublista apuntando a NULL
                    fecha(char dia1[3],char mes1[3], char anio1[3],int &i)
                    se valida si la fecha es corrcta para ingresarala en la estructura del nodo
    ejemplo:        ingresar
                    INGRESE NUMERO DE VUELO: 123456
                    INGRESE ORIGEN: BOGOTA
                    INGRESE DESTINO: PEREIRA
                    INGRESE MATRUCULA DEL AVION: 444444
                    INGRESE NOMBRE DE PILOTO(ESPACIO EN -): JHON-GIRALDO
                    INGRESE HORA DE VUELO(24H->0000): 1500
                    ingrese dia: 20
                    ingrese mes: 01
                    ingrese annio: 21
    resultado:      fecha valida.
                    200121.
                    vuelo agregado.
                    (123456 BOGOTA PEREIRA 444444 JHON-GIRALDO 1500 200121 0)
***********************************************************************************************/

void fecha(char dia1[3],char mes1[3], char anio1[3],int &i){
    Fecha dia,mes,anio;         //estrucutura para fecha
    bool bande=false;           //bandera para saber si fecha fue valida
    int bande2=0;               //bandera 2 para salir de ingresar fecha
    do{
        gotoxy(2,i);i++;        //ingresar datos
        cout<<"ingrese dia: ";
        cin.getline(dia1,3);
        gotoxy(2,i);i++;
        cout<<"ingrese mes: ";
        cin.getline(mes1,3);
        gotoxy(2,i);i++;
        cout<<"ingrese annio: ";
        cin.getline(anio1,3);
        dia.dd=atoi(dia1);      //convertir char a int
        mes.mm=atoi(mes1);
        anio.aaaa=atoi(anio1);
        bande=ValidarFecha(anio,dia,mes);   //validar fecha
        if(bande==true){                    //en cas de ser valido salir con bande2=1
            bande2=1;
        }
        else{
            cout<<"fecha no valida.";
        }
    }while(bande!=1);
}

void agregarVuelo(Tlista &lista){
        system("cls");
        TlistaPasa aux=NULL;                //nodo de sublista en NULL para iniciar vacia
        char dia1[3],mes1[3],anio1[3];      //variables fecha
        int i,a,b=0;
        char fech[7];                       //fecha char
        Tlista q;
        gotoxy(0,0);
        for(int i=0;i<20;i++){              //linea de cuadro
            cout<<char(196)<<char(196);
        }
        gotoxy(2,1);
        q=new(Vuelo);                       //nuevo nodo tipo vuelo
        cin.ignore();
        cout<<"INGRESE NUMERO DE VUELO: ";  //ingresar datos
        cin.getline(q->NroVuelo,7);
        gotoxy(2,2);
        cout<<"INGRESE ORIGEN:  ";
        cin.getline(q->Origen,13);
        gotoxy(2,3);
        cout<<"INGRESE DESTINO: ";
        cin.getline(q->Destino,13);
        gotoxy(2,4);
        cout<<"INGRESE MATRUCULA DEL AVION: ";
        cin.getline(q->MatriAvion,7);
        gotoxy(2,5);
        cout<<"INGRESE NOMBRE DE PILOTO(ESPACIO EN -): ";
        cin.getline(q->NombrePilo,20);
        gotoxy(2,6);
        cout<<"INGRESE HORA DE VUELO(24H->0000): ";
        cin.getline(q->Horavuelo,5);
        i=7;
        q->ListaP=aux;              //sublista apuntando a NULL
        fecha(dia1,mes1,anio1,i);   //ingresar fecha
        gotoxy(2,i);i++;
        cout<<"fecha valida."<<endl;
        for(a=0;a<7;a++){           //bucle para ingresar las fechas valdas en un solo char
            if(a<2){
                fech[a]=dia1[b];
                b++;
            }
            if(a>=2&&a<4){
                fech[a]=mes1[b-2];
                b++;
            }
            if(a>=4){
                fech[a]=anio1[b-4];
                b++;
            }
        }
        gotoxy(2,i);i++;
        cout<<fech;
        strcpy(q->fechaVuelo,fech);
        q->estado=0;
        q->sgte=lista;
        lista = q;
        gotoxy(2,i);
        i++;
        cout<<"Vuelo agregado.";
        gotoxy(0,i);
        i++;
        for(int i=0;i<20;i++){
            cout<<char(196)<<char(196);
        }
        gotoxy(0,i);
}

/***********************************************************************************************
funcion ingresar pasajero
    objetivo:       Adicionar pasajeros.
    funcion:        agregarPasajero(Tlista &lista)
                    se busca el numero de vuelo donde sa valida que este vuelo ya no se haya
                    realizado para luego ubicar la sublista donde se añafira el nuevo pasajero
                    agregarPasajero2(TlistaPasa &pasajeros,int &i,char numVue[7])
                    luego de haber validado lo anterior se ingresan los datos para el nuevo
                    nodo tipo sublista pasajero
    ejemplo:        INGRESE EL NUMERO DE VUELO:123445
                    Cedula: 1122445566
                    NOMBRE (ESPACIOS EN -): LEONA-PEREZ
                    TELEFONO: 3211147852
    resultado:      Pasajero agregado.
                    (123445 1122445566 LEONA-PEREZ 3211147852 1)
***********************************************************************************************/

void agregarPasajero2(TlistaPasa &pasajeros,int &i,char numVue[7]){
    TlistaPasa p;               //nodo tipo Pasajeo
    p=new(Pasajero);
    gotoxy(2,i);
    i++;
    cout<<"NUEVO PASAJERO ";    //agregar datos
    strcpy(p->NroVuelo,numVue);
    gotoxy(2,i);
    i++;
    cout<<"Cedula: ";
    cin.getline(p->cedula,11);
    gotoxy(2,i);
    i++;
    cout<<"NOMBRE (ESPACIOS EN -): ";
    cin.getline(p->nombre,20);
    gotoxy(2,i);
    i++;
    cout<<"TELEFONO: ";
    cin.getline(p->telefono,12);
    p->estado=1;
    p->sgte=pasajeros;          //apuntar a nodo sieguiente
    pasajeros = p;
    gotoxy(2,i);
    i++;
    cout<<"Pasajero agregado.";
}

void agregarPasajero(Tlista &lista){
    system("cls");
    Tlista aux;             //auxlilar tipo lista
    TlistaPasa aux2;        //auxiliar tipo t lista
    aux=lista;
    char numVue[7];         //char para numero de vuelo
    int indi=0,indi2=0,i;
    gotoxy(0,0);
    for(int i=0;i<20;i++){          //recuadro
        cout<<char(196)<<char(196);
    }
    gotoxy(2,1);
    cout<<"INGRESE EL NUMERO DE VUELO: ";   //ingresar numero de vuelo
    cin.ignore();
    cin.getline(numVue,7);
    i=2;
    while(aux!=NULL){
        if(strcmp(numVue,aux->NroVuelo)==0){    //comparara hasta que coincidan los numeor de vuelo
            indi=1;                             //indicador para saber si vuelo encontrado
            if(aux->estado==0){                 //si vuelo esta en reserva se puede agregar
                aux2=aux->ListaP;               //auxliar 2 se le da la direccion de la sublista
                indi2=1;                        //indicador para saber si se puede agregar al vuelo
                agregarPasajero2(aux2,i,numVue);    //ingresar usuario 2
                aux->ListaP=aux2;               //aux lista se le da la sublista con el nuevo ususario
            }
        }
        aux=aux->sgte;
    }
    gotoxy(2,i);
    i++;
    if(indi==0){                                //en caso de vuelo no ecnontrado mostrar
        cout<<"NUMERO DE VUELO NO ENCONTRADO";
    }
    if(indi==1&&indi2==0){
        cout<<"VUELO YA REALIZADO";             //si el vuelo ya se realizo mostrar
    }
    gotoxy(0,i);
    for(int i=0;i<20;i++){                      //cerrar recuadro
        cout<<char(196)<<char(196);
    }
    i++;
    gotoxy(0,i);
}

/***********************************************************************************************
submenu de lista de vuelos
***********************************************************************************************/
void menu3(){
    system("cls");
    for(int i=0;i<20;i++){
        cout<<char(223)<<char(223);
    }
    gotoxy(4,1);
    cout<<"1.CONSULTAR PASAJEROS DE UN VUELO";
    gotoxy(4,2);
    cout<<"2.LISTA DE VUELOS PROGRAMADOS";
    gotoxy(4,3);
    cout<<"3.LISTA DE VUELOS REALIZADOS";
    gotoxy(4,4);
    cout<<"4.VOLVER";
    gotoxy(0,5);
    for(int i=0;i<20;i++){
        cout<<char(196)<<char(196);
    }
    gotoxy(0,6);
    cout<<"DIGITE OPCION:";
}

/************************************************************************************************
funciones de mostrar listados de vuelos con pasajeros, vuelos programados, vueos realizados
	objetivo:       Obtener listados (pasajeros de un vuelo realizado o programado, lista de
                    vuelos programados, lista de vuelos realizados).
    funcion:        listaPasaVuelos(Tlista lista)
                    se muestran los vuelos que estan el sistema y se pide que se digite uno de
                    ellos para mostrar los pasajeros que estan dentro de ese vuelo y medianten
                    un auxlilar se recorre la sublista del vuelo selecinado
                    listaVueProgra(Tlista lista)
                    mediante un auxliar se recorre la lista y se buscan los vuelos con estado
                    programado para mostralos
                    listaVuelReali(Tlista lista)
                    mediante un auxliar se recorre la lista y se buscan los vuelos con estado
                    realizado para motrarlos
    ejemplo:        opcion: 1 -> 123445
                    opcion: 2
                    opcion: 3
    resultado:      opcion(1)
                    VUELO->123445 ORIGEN->BOGOTA DESTINO->MEDELLIN ESTADO->0(0.pendiente 1.realizado)
                        cedula: 1680003021
                        nombre: FERNANDO-SUAREZ
                        telefono: 03600554521
                        estado: a bordo
                    opcion(2)
                        Numero de vuelo: 123654
                        Origen: PERERIRA
                        Destino: CALI
                        Placa avion: 222000
                    Piloto: MANOLO-PEREZ
                    Hora: 14:30
                    Fecha: 21/04/21

                    opcion(3)
                        Numero de vuelo: 876543
                        Origen: SAN-ANDRES
                        Destino: BUENAVENTURA
                        Placa avion: 111111
                        Piloto: CLAUDIA-LOPEZ
                        Hora: 11:00
                        Fecha: 23/11/42
************************************************************************************************/
void listaPasaVuelos(Tlista lista){
    system("cls");
    int i=3,op,numVuelo;
    Tlista aux;             //auxiliar tipo lista
    TlistaPasa aux2;        //auxiliar tipo pasajero
    aux=lista;
    for(int i=0;i<20;i++){          //encabezado
        cout<<char(223)<<char(223);
    }
    gotoxy(12,1);
    cout<<"VUELOS TOTALES";
    gotoxy(0,2);
    for(int i=0;i<20;i++){      //cerrar encabezado
        cout<<char(223)<<char(223);
    }
    while(aux!=NULL){           //mostrar vuelos totales
        gotoxy(16,i);
        cout<<aux->NroVuelo;
        i++;
        aux=aux->sgte;
    }
    aux=lista;
    gotoxy(0,i);
    for(int i=0;i<20;i++){
        cout<<char(196)<<char(196);
    }
    i+=1;
    gotoxy(0,i);
    cout<<"DIGITE VUELO: ";cin>>op;     //ingresar numero de vuelo
    system("cls");
    gotoxy(0,0);
    for(int i=0;i<20;i++){
        cout<<char(196)<<char(196);
    }
    gotoxy(2,1);
    cout<<"LISTA DE PASAJEROS";
    gotoxy(0,2);
    for(int i=0;i<20;i++){
        cout<<char(196)<<char(196);
    }
    i=3;
    while(aux!=NULL){
        numVuelo=atoi(aux->NroVuelo);
        if(numVuelo==op){               //comparar hasta ecnontra numero de vuelo
            gotoxy(0,i);                //mostrar vuelo y pasajeros
            cout<<"VUELO->"<<aux->NroVuelo<<" ORIGEN->"<<aux->Origen<<" DESTINO->"<<aux->Destino<<" ESTADO->"<<aux->estado<<"(0.pendiente 1.realizado)";
            i+=2;
            aux2=aux->ListaP;
            while(aux2!=NULL){
                gotoxy(4,i);
                cout<<"cedula: "<<aux2->cedula;
                i++;
                gotoxy(4,i);
                cout<<"nombre: "<<aux2->nombre;
                i++;
                gotoxy(4,i);
                cout<<"telefono: "<<aux2->telefono;
                i++;
                gotoxy(4,i);
                cout<<"estado: ";
                if(aux2->estado==1){
                    cout<<"reserva";
                }
                else{
                    cout<<"a bordo";
                }
                i+=2;
                aux2=aux2->sgte;
            }
        }
        aux=aux->sgte;
    }
    gotoxy(0,i);
    for(int i=0;i<20;i++){          //cerrar recuadro
        cout<<char(196)<<char(196);
    }
    cout<<endl;
}

void listaVueProgra(Tlista lista){
    system("cls");
    int i=3,op,estadoVuel;
    char hora[5],fecha[7];
    Tlista aux;             //auxlilar tipo lista
    aux=lista;
    for(int i=0;i<20;i++){
        cout<<char(223)<<char(223);
    }
    gotoxy(8,1);
    cout<<"LISTA VUELOS PROGRAMADOS";
    gotoxy(0,2);
    for(int i=0;i<20;i++){
        cout<<char(223)<<char(223);
    }
    i=3;
    while(aux!=NULL){
        if(aux->estado==0){     //buscar vuelos programados
            gotoxy(4,i);        //mostrar vuelos programados
            cout<<"Numero de vuelo: "<<aux->NroVuelo;
            i++;
            gotoxy(4,i);
            cout<<"Origen: "<<aux->Origen;
            i++;
            gotoxy(4,i);
            cout<<"Destino: "<<aux->Destino;
            i++;
            gotoxy(4,i);
            cout<<"Placa avion: "<<aux->MatriAvion;
            i++;
            gotoxy(4,i);
            cout<<"Piloto: "<<aux->NombrePilo;
            i++;
            gotoxy(4,i);
            cout<<"Hora: ";
            strcpy(hora,aux->Horavuelo);
            for(int a=0;a<5;a++){
                if(a==2){
                    cout<<":";
                }
                cout<<hora[a];
            }
            i++;
            gotoxy(4,i);
            cout<<"Fecha: ";
            strcpy(fecha,aux->fechaVuelo);
            for(int a=0;a<7;a++){
                if(a==2||a==4){
                    cout<<"/";
                }
                cout<<fecha[a];
            }
            i+=2;
        }
        aux=aux->sgte;
    }
    gotoxy(0,i);
    for(int i=0;i<20;i++){
        cout<<char(196)<<char(196);
    }
    cout<<endl;
}

void listaVuelReali(Tlista lista){
    system("cls");
    int i=3,op,estadoVuel;
    char hora[5],fecha[7];
    Tlista aux;             //auxiliar tipo lista
    aux=lista;
    for(int i=0;i<20;i++){
        cout<<char(223)<<char(223);
    }
    gotoxy(8,1);
    cout<<"LISTA VUELOS REALIZADOS";
    gotoxy(0,2);
    for(int i=0;i<20;i++){
        cout<<char(223)<<char(223);
    }
    i=3;
    while(aux!=NULL){
        if(aux->estado==1){     //buscar vuelos relizados
            gotoxy(4,i);        //mostrar vuelos
            cout<<"Numero de vuelo: "<<aux->NroVuelo;
            i++;
            gotoxy(4,i);
            cout<<"Origen: "<<aux->Origen;
            i++;
            gotoxy(4,i);
            cout<<"Destino: "<<aux->Destino;
            i++;
            gotoxy(4,i);
            cout<<"Placa avion: "<<aux->MatriAvion;
            i++;
            gotoxy(4,i);
            cout<<"Piloto: "<<aux->NombrePilo;
            i++;
            gotoxy(4,i);
            cout<<"Hora: ";
            strcpy(hora,aux->Horavuelo);
            for(int a=0;a<5;a++){
                if(a==2){
                    cout<<":";
                }
                cout<<hora[a];
            }
            i++;
            gotoxy(4,i);
            cout<<"Fecha: ";
            strcpy(fecha,aux->fechaVuelo);
            for(int a=0;a<7;a++){
                if(a==2||a==4){
                    cout<<"/";
                }
                cout<<fecha[a];
            }
            i+=2;
        }
        aux=aux->sgte;
    }
    gotoxy(0,i);
    for(int i=0;i<20;i++){
        cout<<char(196)<<char(196);
    }
    cout<<endl;
}

/***********************************************************************************************
submenu listado de vuelos por cedula
***********************************************************************************************/
void menu4(){
    system("cls");
    for(int i=0;i<20;i++){
        cout<<char(223)<<char(223);
    }
    gotoxy(4,1);
    cout<<"1.LISTA DE VUELOS REALIZADOS";
    gotoxy(4,2);
    cout<<"2.LISTA DE VUELOS PROGRAMADOS";
    gotoxy(4,3);
    cout<<"3.VOLVER";
    gotoxy(0,4);
    for(int i=0;i<20;i++){
        cout<<char(196)<<char(196);
    }
    gotoxy(0,5);
    cout<<"DIGITE OPCION:";
}

/***********************************************************************************************
funcion buscar vuelos por cedula
    objetivo:       Dada la cédula de una persona, obtener un listado de los vuelos que ha
                    realizado y de los vuelos que tiene programado realizar.
    funcion:        listadoPersonaVuel(Tlista lista)
                    se da alejir la opcion pra saber que listado se quiere buscra
                    listadoPersonaVuelReal(Tlista lista)
                    se busca en los vuelos realizados si se ecenutra entre sus sublistas el numero
                    de celuda
                    listadoPersonaVuelProgra(Tlista lista)
                    se busca en los vuelos programados si se ecenutra entre sus sublistas el numero
                    de celuda
    ejemplo:        opcion:1 -> 1977646644
                    opcion:2 -> 5687654321
    resultado:      opcion(1->1977646644)
                    Numero de vuelo: 876543
                    Origen-> SAN-ANDRES Destino-> BUENAVENTURA

                    Numero de vuelo: 132543
                    Origen-> BARRANQUILLA Destino-> CALI
                    opcion2(2->5687654321)
                    Numero de vuelo: 123654
                    Origen->PERERIRA Destino->CALI

                    Numero de vuelo: 123445
                    Origen->BOGOTA Destino->MEDELLIN
***********************************************************************************************/

void listadoPersonaVuelReal(Tlista lista){
    system("cls");
    Tlista aux;         //auxiliar tipo lista
    TlistaPasa aux2;    //auxliar tipo pasajero
    aux=lista;
    int i,indi=0,indi2=0;
    char cedula1[11];
    gotoxy(0,0);
    for(int i=0;i<20;i++){          //recuadro
        cout<<char(196)<<char(196);
    }
    gotoxy(2,1);
    cout<<"INGRESE CEDULA: ";
    cin.ignore();               //ingresar cedula
    cin.getline(cedula1,11);
    i=2;
    while(aux!=NULL){           //recorrer hasat llegar a l final
        aux2=aux->ListaP;
        while(aux2!=NULL){
                if(strcmp(aux2->cedula,cedula1)==0){    //comparar si se eceuntra cedula
                    indi=1;
                    if(aux2->estado==2&&aux->estado==1){    //comprobra si estado es igual a bordo y vuelo realizado
                        indi2=1;
                        gotoxy(2,i);                        //mostrar vuelo
                        cout<<"Numero de vuelo: "<<aux->NroVuelo;
                        i++;
                        gotoxy(2,i);
                        cout<<"Origen-> "<<aux->Origen<<" Destino-> "<<aux->Destino;
                        i+=2;
                    }
            }
            aux2=aux2->sgte;
        }
        aux=aux->sgte;
    }
    gotoxy(2,i);
    if(indi==0){    //en caso de no econtrar cedula
        cout<<"PASAJERO NO ECNONTRADO";
    }
    if(indi==1&&indi2==0){          //en caso de no econtrar vuelos realizados
       cout<<"EL PASAJERO NO TIENE VUELOS REALIZADOS";
    }
    gotoxy(0,i+1);
    for(int i=0;i<20;i++){          //cerrar recuadro
        cout<<char(196)<<char(196);
    }
    gotoxy(0,i+2);
}

void listadoPersonaVuel(Tlista lista){
    system("cls");
    for(int i=0;i<20;i++){
        cout<<char(223)<<char(223);
    }
    gotoxy(4,1);
    cout<<"1.LISTA DE VUELOS REALIZADOS";
    gotoxy(4,2);
    cout<<"2.LISTA DE VUELOS PROGRAMADOS";
    gotoxy(4,3);
    cout<<"3.VOLVER";
    gotoxy(0,4);
    for(int i=0;i<20;i++){
        cout<<char(196)<<char(196);
    }
    gotoxy(0,5);
    cout<<"DIGITE OPCION:";
}

void listadoPersonaVuelProgra(Tlista lista){
    system("cls");
    Tlista aux;             //auxlilar tipo lista
    TlistaPasa aux2;        //auxiliar tipo parajero
    aux=lista;
    int i,indi=0,indi2=0;
    char cedula1[11];
    gotoxy(0,0);
    for(int i=0;i<20;i++){      //recuadro
        cout<<char(196)<<char(196);
    }
    gotoxy(2,1);
    cout<<"INGRESE CEDULA: ";
    cin.ignore();
    cin.getline(cedula1,11);
    i=2;
    while(aux!=NULL){
        aux2=aux->ListaP;
        while(aux2!=NULL){
                if(strcmp(aux2->cedula,cedula1)==0){       //buscar cedula
                    indi=1;
                    if((aux2->estado==1&&aux->estado==0)||(aux2->estado==2&&aux->estado==0)){   //comparar estado y si vuelo es porgamado
                        indi2=1;
                        gotoxy(2,i);                    //mostrar
                        cout<<"Numero de vuelo: "<<aux->NroVuelo;
                        i++;
                        gotoxy(2,i);
                        cout<<"Origen->"<<aux->Origen<<" Destino->"<<aux->Destino;
                        i+=2;
                    }
            }
            aux2=aux2->sgte;
        }
        aux=aux->sgte;
    }
    gotoxy(2,i);
    if(indi==0){    //en caso de pasajero no ecnontrado
        cout<<"PASAJERO NO ECNONTRADO";
    }
    if(indi==1&&indi2==0){  //en caso de no ecnontrar vuelos programados
       cout<<"EL PASAJERO NO TIENE VUELOS PROGRAMADOS";
    }
    gotoxy(0,i+1);
    for(int i=0;i<20;i++){      //cerrar recuadro
        cout<<char(196)<<char(196);
    }
    gotoxy(0,i+2);
}

/***********************************************************************************************
funcion modificar estado de vuelo
    objetivo:       Cuando se hace un vuelo, se debe modificar el estado del vuelo a realizado.
    funcion:        modificarestadoVuel(Tlista &lista)
                    se busca si el vuelo se eceuntra prgramado y se le cambia el estado
    ejemplo:        DIGITE NUMERO DE VUELO: 123445

    resultado:      Estado cambio a realizado.
***********************************************************************************************/

void modificarestadoVuel(Tlista &lista){
    system("cls");
    Tlista aux;         //auxliliar tipo lista
    aux=lista;
    int indi=0,indi2=0;
    char numVuel[7];
    gotoxy(0,0);
    for(int i=0;i<20;i++){  //recuadro
        cout<<char(196)<<char(196);
    }
    gotoxy(2,1);
    cout<<"DIGITE NUMERO DE VUELO: ";
    cin.ignore();
    cin.getline(numVuel,7);
    gotoxy(2,2);
    while(aux!=NULL){       //recorrer lista
        if(strcmp(numVuel,aux->NroVuelo)==0){       //compara para econotrar numero de vuelo
            indi=1;
            if(aux->estado==0){                     //si estado es programado pasar a realizado
                indi2=1;
                cout<<"Estado cambio a realizado.";
                aux->estado=1;
            }
        }
        aux=aux->sgte;
    }
    gotoxy(2,3);
    if(indi==0){        //en caso de no encontrar vuelo
        cout<<"VUELO NO ENCONTRADO";
    }
    if(indi==1&&indi2==0){      //en caso de que el vuelo ya este realizado
        cout<<"VUELO YA REALIZADO";
    }
    gotoxy(2,4);
    for(int i=0;i<20;i++){      //cerrar recuadro
        cout<<char(196)<<char(196);
    }
    gotoxy(0,5);
}

/**************************************************************************************************
funcion registrar pasajero a bordo
    objetivo:       Se debe tener una opción que permita registrar cuando un pasajero pasa a bordo.
    funcion:        registrarAbordo(Tlista &lista)
                    se pide el vuelo y se revisa que el vuelo este programado para cambiar su estado
    ejemplo:        INGRESE NUMERO DE VUELO: 123445

    resultado:      Estado pasa ser a bordo
***************************************************************************************************/

void registrarAbordo(Tlista &lista){
    system("cls");
    Tlista aux;     //auxlilar tipo lista
    aux=lista;
    TlistaPasa aux2;    //auxiliar tipo pasajero
    int numVuelo1,numVuelo2,indi=0,indi2=0,bande=0,bande2=0;
    char cedula1[11],cedula2[11];
    gotoxy(0,0);
    for(int i=0;i<20;i++){      //recuadro
        cout<<char(196)<<char(196);
    }
    gotoxy(2,1);
    cout<<"INGRESE NUMERO DE VUELO: ";cin>>numVuelo1;   //ingresar numero de vuelo
    gotoxy(2,2);
    while(aux!=NULL){
        numVuelo2=atoi(aux->NroVuelo);
        if(numVuelo1==numVuelo2){           //comparar para encontrar numero de vuelo
            indi=1;
            if(aux->estado==0){             //ver si vuelo se ecuntra programado
                bande=1;
                cout<<"INGRESE CEDULA: ";
                cin.ignore();               //ingresar cedula
                cin.getline(cedula1,11);
                aux2=aux->ListaP;           //asignar a auxlilar 2 la sublista
                    while(aux2!=NULL){      //recorrer sublista
                        gotoxy(2,3);
                        strcpy(cedula2,aux2->cedula);
                        if(strcmp(cedula1,cedula2)==0){     //buscar cedula
                            indi2=1;
                            if(aux2->estado==1){            // si estado es en reserva pasar a bordo
                                cout<<"Estado pasa ser a bordo";
                                aux2->estado=2;
                            }
                            else{                           //sino el pasajero ya se encuentr a bordo
                                cout<<"Pasajero ya se encuentra a bordo";
                            }
                        }
                        aux2=aux2->sgte;
                    }
             }
        }
        aux=aux->sgte;
    }
    if(indi==0&&bande==0){      //en caso de no econtrar vuelo
        cout<<"VUELO NO ENCONTRADO";
    }
    if(indi==1&&bande==0){      //en caso de vuelo ya realizado
        cout<<"VUELO YA REALIZADO";
    }
    if(indi==1&&bande==1){
        if(indi2==0){           //en caso de no encontrar pasajero
            cout<<"PASAJERO NO ECNONTRADO";
        }
    }
    gotoxy(0,4);
    for(int i=0;i<20;i++){      //cerrar recuadro
        cout<<char(196)<<char(196);
    }
    gotoxy(2,5);
}

/***********************************************************************************************
funcion principal
***********************************************************************************************/
main(){
    Tlista lista = NULL;
    leerArchivo1(lista);
    int op;
    system("color 0b");
    do{
        menu();
            cin>>op;
            switch(op){
                case 1:
                    agregarVuelo(lista);
                    system("pause");
                break;
                case 2:
                    agregarPasajero(lista);
                    system("pause");
                break;
                case 3:{
                    int opci;
                    do{
                        menu3();cin>>opci;
                        switch(opci){
                            case 1:
                                listaPasaVuelos(lista);
                                system("pause");
                            break;
                            case 2:
                                listaVueProgra(lista);
                                system("pause");
                            break;
                            case 3:
                                listaVuelReali(lista);
                                system("pause");
                            break;
                        }
                        if(opci>4){
                            opci=4;
                        }
                    }while(opci!=4);
                }
                break;
                case 4:
                    {
                    int opci2;
                    do{
                        menu4();cin>>opci2;
                        switch(opci2){
                            case 1:
                                listadoPersonaVuelReal(lista);
                                system("pause");
                            break;
                            case 2:
                                listadoPersonaVuelProgra(lista);
                                system("pause");
                            break;
                        }
                        if(opci2>3){
                            opci2=3;
                        }
                    }while(opci2!=3);
                }
                break;
                case 5:
                    modificarestadoVuel(lista);
                    system("pause");
                break;
                case 6:
                    registrarAbordo(lista);
                    system("pause");
                break;
            }
            cout<<endl<<endl;
            system("cls");
    }while(op!=7);
    system("pause");
    return 0;
}
