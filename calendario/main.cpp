#include <iostream>
#include <fstream>
#include <string.h>
#include <cstdlib>
#include <windows.h>



using namespace std;

const int MAX_DIAS = 100;
const char nombreFichero[] = "miCalendario.dat";

typedef char TCadenaCorta[5];
typedef char TCadenaLarga[];

typedef struct{//cadena para las horas
    int minutos;
    int hora;
}THora;

typedef struct{//cadena de cada dia
    THora horaInicio;
    THora horaFinalizar;
    TCadenaCorta abreviacion;
    TCadenaLarga informacionDia;
}TDia;

typedef TDia TMes[MAX_DIAS];
typedef struct{
    TMes enero;
    TMes febrero;
    TMes marzo;
    TMes abril;
    TMes mayo;
    TMes junio;
    TMes julio;
    TMes agosto;
    TMes septiembre;
    TMes octubre;
    TMes noviembre;
    TMes diciembre;
}TAnyo;


//Declaracion de modulos
int menu();
int menu2();
void espaciado();
int salir(int opc);
void inicializarCadenas(TMes &dia);
void escribirCadenas(TAnyo &anyo2024, int &opc);
void borrarCadenas(TAnyo &anyo2024 , int &opc);
void verInformacion(TAnyo &anyo2024 , int &opc);
//meses
void enero(TAnyo &anyo2024);
void febrero(TAnyo &anyo2024);
void marzo(TAnyo &anyo2024);
void abril(TAnyo &anyo2024);
void mayo(TAnyo &anyo2024);
void junio(TAnyo &anyo2024);
void julio(TAnyo &anyo2024);
void agosto(TAnyo &anyo2024);
void septiembre(TAnyo &anyo2024);
void octubre(TAnyo &anyo2024);
void noviembre(TAnyo &anyo2024);
void diciembre(TAnyo &anyo2024);
//ficheros
void leerFichero(TAnyo &anyo2024);
void escribirFichero(TAnyo &anyo2024);
//funciones graficas sin utilizar
void dibujarCuadro(int x1,int y1,int x2,int y2);
void gotoxy(int x,int y);


int main(){
    int opc;
    int mes;
    char confirmar;
    TAnyo anyo2024;

    system("mode con: cols=120 lines=60"); //SE DEFINE LAS DIMENSIONES DE LA VENTANA DEL PROGRAMA A 80 COLUMNAS Y 25 FILAS
    system("color f0");



    opc = menu();

    while(opc != 0){
        switch(opc){
            case 1: mes = 1;
                   espaciado();
                   leerFichero(anyo2024);
                   inicializarCadenas(anyo2024.enero);
                    enero(anyo2024);
                    opc = salir(opc);
            break;
            case 2:
                    mes = 2;
                   espaciado();
                   leerFichero(anyo2024);
                   inicializarCadenas(anyo2024.febrero);
                    febrero(anyo2024);
                    opc = salir(opc);
            break;
            case 3: mes = 3;
                    espaciado();
                   leerFichero(anyo2024);
                   inicializarCadenas(anyo2024.marzo);
                    marzo(anyo2024);
                    opc = salir(opc);
            break;
            case 4: mes = 4;
                    espaciado();
                   leerFichero(anyo2024);
                   inicializarCadenas(anyo2024.abril);
                    abril(anyo2024);
                    opc = salir(opc);
            break;
            case 5: mes = 5;
                    espaciado();
                   leerFichero(anyo2024);
                   inicializarCadenas(anyo2024.mayo);
                    mayo(anyo2024);
                    opc = salir(opc);
            break;
            case 6: mes = 6;
                   espaciado();
                   leerFichero(anyo2024);
                   inicializarCadenas(anyo2024.junio);
                    junio(anyo2024);
                    opc = salir(opc);
            break;
            case 7:  mes = 7;
                   espaciado();
                   leerFichero(anyo2024);
                   inicializarCadenas(anyo2024.julio);
                    julio(anyo2024);
                    opc = salir(opc);
            break;
            case 8: mes = 8;
                    espaciado();
                   leerFichero(anyo2024);
                   inicializarCadenas(anyo2024.agosto);
                    agosto(anyo2024);
                    opc = salir(opc);
            break;
            case 9: mes = 9;
                   espaciado();
                   leerFichero(anyo2024);
                   inicializarCadenas(anyo2024.septiembre);
                    septiembre(anyo2024);
                    opc = salir(opc);
            break;
            case 10: mes = 10;
                   espaciado();
                   leerFichero(anyo2024);
                   inicializarCadenas(anyo2024.octubre);
                    octubre(anyo2024);
                    opc = salir(opc);
            break;
            case 11: mes = 11;
                   espaciado();
                   leerFichero(anyo2024);
                   inicializarCadenas(anyo2024.noviembre);
                    noviembre(anyo2024);
                    opc = salir(opc);
            break;
            case 12: mes = 12;
                  espaciado();
                   leerFichero(anyo2024);
                   inicializarCadenas(anyo2024.diciembre);
                    diciembre(anyo2024);
                    opc = salir(opc);
            break;
            case 13:
                    espaciado();
                    opc = menu2();
            break;
            case 14:
                    espaciado();
                    escribirCadenas(anyo2024, mes);
                    opc = mes;
                    break;
            case 15:
                    espaciado();
                    borrarCadenas(anyo2024, mes);
                    opc = mes;
                    break;
             case 16:
                    espaciado();
                    do{
                    confirmar = 's';
                    verInformacion(anyo2024, mes);
                    cout << "si quiere seguir viendo mas informacion pulse (s): ";
                    cin >> confirmar;
                    }while(confirmar == 's');
                    opc = 13;
                break;
        }
        leerFichero(anyo2024);
    }
    system("pause");

    return 0;
}

int menu(){
    int n;
    cout << "                                                                                          " << endl;
    cout << "   -----------------------------------------------" << endl;
    cout << "   |                                             |" << endl;
    cout << "   |    /Bienvenido a la aplicacion calendar!    |" << endl;
    cout << "   |                                             |" << endl;
    cout << "   |          +(0)-Salir del programa.           |" << endl;
    cout << "   |          +(1-12)-Elegir un mes.             |" << endl;
    cout << "   |                                             |" << endl;
    cout << "   -----------------------------------------------" << endl;

    cout << "   Elige una de las opciones: ";
    cin >> n;

    return n;
}

int menu2(){
    int n;
    cout << "                                                                                          " << endl;
    cout << "   -----------------------------------------------" << endl;
    cout << "   |                                             |" << endl;
    cout << "   |    /Vuelva a elegir la opcion que desea!    |" << endl;
    cout << "   |                                             |" << endl;
    cout << "   |          +(0)-Salir del programa.           |" << endl;
    cout << "   |          +(1-12)-Elegir un mes.             |" << endl;
    cout << "   |                                             |" << endl;
    cout << "   -----------------------------------------------" << endl;
    espaciado();
    cout << "   Elige una de las opciones: ";
    cin >> n;

    return n;
}


void espaciado(){
                    cout << endl;
                    cout << endl;
                    cout << endl;
                    cout << endl;
                    cout << endl;
                    cout << endl;
                    cout << endl;
                    cout << endl;

}

int salir(int opc){
    int opcion;
    espaciado();
    cout << "    Volver al menu (0)   || Avanzar un mes(1)   || Retroceder(2) || Escribir informacion(3)" << endl;
    cout << "    Borar informacion(4) || Ver informacion (5) : ";
    cin >> opcion;
    cout << endl;
    if(opcion == 0){
        opc = 13;
    }else if(opcion == 1){
        if(opc<12){
            opc = opc + 1;
        }else{
            opc = 1;
        }
        }else if(opcion == 2){
        if(opc>1){
            opc = opc - 1;
        }else{
            opc = 12;
        }
     }else if(opcion == 3){

        opc = 14;
     }else if(opcion == 4){
        opc = 15;
     }else if(opcion == 5){
        opc = 16;
     }
     return opc;
    }




void inicializarCadenas(TMes &dia){
    int i;
    for(i=0 ; i<100 ; i++){
        if(strlen( dia[i].informacionDia ) <7){
        strcpy( dia[i].abreviacion , "   ");
        }
    }
}

void escribirCadenas(TAnyo &anyo2024 , int &opc){
    int dia;

    do{
    cout << "Dime el dia al que quieres anyadirle informacion: ";
    cin >> dia;
    cout << endl;
    }while(dia > 31);
    cout << "Anyade la informacion que quieras: ";
    switch(opc){
        case 1: cin >> anyo2024.enero[dia-1].informacionDia;
                strncpy( anyo2024.enero[dia-1].abreviacion , anyo2024.enero[dia-1].informacionDia , 3);
                espaciado();
                enero(anyo2024);
        break;
        case 2: cin >> anyo2024.febrero[dia-1].informacionDia;
                strncpy( anyo2024.febrero[dia-1].abreviacion , anyo2024.febrero[dia-1].informacionDia , 3);
                espaciado();
                febrero(anyo2024);
        break;
        case 3: cin >> anyo2024.marzo[dia-1].informacionDia;
                strncpy( anyo2024.marzo[dia-1].abreviacion , anyo2024.marzo[dia-1].informacionDia , 3);
                espaciado();
                marzo(anyo2024);
        break;
        case 4: cin >> anyo2024.abril[dia-1].informacionDia;
                strncpy( anyo2024.abril[dia-1].abreviacion , anyo2024.abril[dia-1].informacionDia , 3);
                espaciado();
                abril(anyo2024);
        break;
        case 5: cin >> anyo2024.mayo[dia-1].informacionDia;
                strncpy( anyo2024.mayo[dia-1].abreviacion , anyo2024.mayo[dia-1].informacionDia , 3);
                espaciado();
                mayo(anyo2024);
        break;
        case 6: cin >> anyo2024.junio[dia-1].informacionDia;
                strncpy( anyo2024.junio[dia-1].abreviacion , anyo2024.junio[dia-1].informacionDia , 3);
                 espaciado();
                 junio(anyo2024);
        break;
        case 7: cin >> anyo2024.julio[dia-1].informacionDia;
                strncpy( anyo2024.julio[dia-1].abreviacion , anyo2024.julio[dia-1].informacionDia , 3);
                 espaciado();
                 julio(anyo2024);
        break;
        case 8: cin >> anyo2024.agosto[dia-1].informacionDia;
                strncpy( anyo2024.agosto[dia-1].abreviacion , anyo2024.agosto[dia-1].informacionDia , 3);
                 espaciado();
                 agosto(anyo2024);
        break;
        case 9: cin >> anyo2024.septiembre[dia-1].informacionDia;
                strncpy( anyo2024.septiembre[dia-1].abreviacion , anyo2024.septiembre[dia-1].informacionDia , 3);
                 espaciado();
                 septiembre(anyo2024);
        break;
        case 10: cin >> anyo2024.octubre[dia-1].informacionDia;
                strncpy( anyo2024.octubre[dia-1].abreviacion , anyo2024.octubre[dia-1].informacionDia , 3);
                 espaciado();
                 octubre(anyo2024);
        break;
        case 11: cin >> anyo2024.noviembre[dia-1].informacionDia;
                strncpy( anyo2024.noviembre[dia-1].abreviacion , anyo2024.noviembre[dia-1].informacionDia , 3);
                 espaciado();
                 noviembre(anyo2024);
        break;
        case 12: cin >> anyo2024.diciembre[dia-1].informacionDia;
                strncpy( anyo2024.diciembre[dia-1].abreviacion , anyo2024.diciembre[dia-1].informacionDia , 3);
                 espaciado();
                 diciembre(anyo2024);
        break;
    }
}
void borrarCadenas(TAnyo &anyo2024 , int &opc){
    int dia;
    char confirmar;

    do{
    cout << "Dime el dia al que quieres borrarle informacion: ";
    cin >> dia;
    cout << endl;
    }while(dia > 31);
    cout << "Pulsa s para confirmar: ";
    cin >> confirmar;

    if(confirmar == 's'){
    switch(opc){
        case 1:
                strcpy( anyo2024.enero[dia-1].abreviacion , "   ");
                strncpy(anyo2024.enero[dia-1].informacionDia , "                                                                    " , strlen(anyo2024.enero[dia-1].informacionDia));
                espaciado();
                enero(anyo2024);
        break;
        case 2: strcpy( anyo2024.febrero[dia-1].abreviacion , "   ");
                strncpy(anyo2024.febrero[dia-1].informacionDia , "                                                                    " , strlen(anyo2024.febrero[dia-1].informacionDia));
                espaciado();
                febrero(anyo2024);
        break;
        case 3: strcpy( anyo2024.marzo[dia-1].abreviacion , "   ");
                strncpy(anyo2024.marzo[dia-1].informacionDia , "                                                                    " , strlen(anyo2024.marzo[dia-1].informacionDia));
                espaciado();
                marzo(anyo2024);
        break;
        case 4: strcpy( anyo2024.abril[dia-1].abreviacion , "   ");
                strncpy(anyo2024.abril[dia-1].informacionDia , "                                                                    " , strlen(anyo2024.abril[dia-1].informacionDia));
                espaciado();
                abril(anyo2024);
        break;
        case 5: strcpy( anyo2024.mayo[dia-1].abreviacion , "   ");
                strncpy(anyo2024.mayo[dia-1].informacionDia , "                                                                    " , strlen(anyo2024.mayo[dia-1].informacionDia));
                espaciado();
                mayo(anyo2024);
        break;
        case 6: strcpy( anyo2024.junio[dia-1].abreviacion , "   ");
                strncpy(anyo2024.junio[dia-1].informacionDia , "                                                                    " , strlen(anyo2024.junio[dia-1].informacionDia));
                espaciado();
                junio(anyo2024);
        break;
        case 7: strcpy( anyo2024.julio[dia-1].abreviacion , "   ");
                strncpy(anyo2024.julio[dia-1].informacionDia , "                                                                    " , strlen(anyo2024.julio[dia-1].informacionDia));
                espaciado();
                julio(anyo2024);
        break;
        case 8: strcpy( anyo2024.agosto[dia-1].abreviacion , "   ");
                strncpy(anyo2024.agosto[dia-1].informacionDia , "                                                                    " , strlen(anyo2024.agosto[dia-1].informacionDia));
                espaciado();
                agosto(anyo2024);
        break;
        case 9: strcpy( anyo2024.septiembre[dia-1].abreviacion , "   ");
                strncpy(anyo2024.septiembre[dia-1].informacionDia , "                                                                    " , strlen(anyo2024.septiembre[dia-1].informacionDia));
                espaciado();
                septiembre(anyo2024);
        break;
        case 10: strcpy( anyo2024.octubre[dia-1].abreviacion , "   ");
                strncpy(anyo2024.octubre[dia-1].informacionDia , "                                                                    " , strlen(anyo2024.octubre[dia-1].informacionDia));
                espaciado();
                octubre(anyo2024);
        break;
        case 11: strcpy( anyo2024.noviembre[dia-1].abreviacion , "   ");
                strncpy(anyo2024.noviembre[dia-1].informacionDia , "                                                                    " , strlen(anyo2024.noviembre[dia-1].informacionDia));
                espaciado();
                noviembre(anyo2024);
        break;
        case 12: strcpy( anyo2024.diciembre[dia-1].abreviacion , "   ");
                strncpy(anyo2024.diciembre[dia-1].informacionDia , "                                                                    " , strlen(anyo2024.diciembre[dia-1].informacionDia));
                espaciado();
                diciembre(anyo2024);
        break;
    }
    }


}

void verInformacion(TAnyo &anyo2024 , int &opc){
    int dia;


    do{
    cout << "Dime el dia del que quieres ver la informacion: ";
    cin >> dia;
    cout << endl;
    }while(dia > 31);

    switch(opc){
        case 1:
                cout << anyo2024.enero[dia-1].informacionDia << endl;
                espaciado();
        break;
        case 2: cout << anyo2024.febrero[dia-1].informacionDia << endl;
                espaciado();
        break;
        case 3: cout << anyo2024.marzo[dia-1].informacionDia << endl;
                espaciado();
        break;
        case 4: cout << anyo2024.abril[dia-1].informacionDia << endl;
                espaciado();
        break;
        case 5: cout << anyo2024.mayo[dia-1].informacionDia << endl;
                espaciado();
        break;
        case 6: cout << anyo2024.junio[dia-1].informacionDia << endl;
                espaciado();
        break;
        case 7: cout << anyo2024.julio[dia-1].informacionDia << endl;
                espaciado();
        break;
        case 8: cout << anyo2024.agosto[dia-1].informacionDia << endl;
                espaciado();
        break;
        case 9: cout << anyo2024.septiembre[dia-1].informacionDia << endl;
                espaciado();
        break;
        case 10: cout << anyo2024.octubre[dia-1].informacionDia << endl;
                espaciado();
        break;
        case 11: cout << anyo2024.noviembre[dia-1].informacionDia << endl;
                espaciado();
        break;
        case 12: cout << anyo2024.diciembre[dia-1].informacionDia << endl;
                espaciado();
        break;
    }


}


void enero(TAnyo &anyo2024){




    cout << "                                      Enero(2024)                                         " << endl;
    cout << "   ---------------------------------------------------------------------------------------" << endl;
    cout << "   |  Lunes  |  Martes   | Miercoles |  Jueves   |  Viernes  |   Sabado     |  Domingo   |" << endl;
    cout << "   ---------------------------------------------------------------------------------------" << endl;
    cout << "   |1        |2          |3          |4          |5          |6             |7           |" << endl;
    cout << "   |      " << anyo2024.enero[0].abreviacion << "|        " << anyo2024.enero[1].abreviacion << "|        " << anyo2024.enero[2].abreviacion << "|        " << anyo2024.enero[3].abreviacion << "|        " << anyo2024.enero[4].abreviacion << "|           " << anyo2024.enero[5].abreviacion << "|         " << anyo2024.enero[6].abreviacion << "|" << endl;
    cout << "   |         |           |           |           |           |              |            |" << endl;
    cout << "   |---------|-----------|-----------|-----------|-----------|--------------|------------|" << endl;
    cout << "   |8        |9          |10         |11         |12         |13            |14          |" << endl;
    cout << "   |      " << anyo2024.enero[7].abreviacion << "|        " << anyo2024.enero[8].abreviacion << "|        " << anyo2024.enero[9].abreviacion << "|        " << anyo2024.enero[10].abreviacion << "|        " << anyo2024.enero[11].abreviacion << "|           " << anyo2024.enero[12].abreviacion << "|         " << anyo2024.enero[13].abreviacion << "|" << endl;
    cout << "   |         |           |           |           |           |              |            |" << endl;
    cout << "   |---------|-----------|-----------|-----------|-----------|--------------|------------|" << endl;
    cout << "   |15       |16         |17         |18         |19         |20            |21          |" << endl;
    cout << "   |      " << anyo2024.enero[14].abreviacion << "|        " << anyo2024.enero[15].abreviacion << "|        " << anyo2024.enero[16].abreviacion << "|        " << anyo2024.enero[17].abreviacion << "|        " << anyo2024.enero[18].abreviacion << "|           " << anyo2024.enero[19].abreviacion << "|         " << anyo2024.enero[20].abreviacion << "|" << endl;
    cout << "   |         |           |           |           |           |              |            |" << endl;
    cout << "   |---------|-----------|-----------|-----------|-----------|--------------|------------|" << endl;
    cout << "   |22       |23         |24         |25         |26         |27            |28          |" << endl;
    cout << "   |      " << anyo2024.enero[21].abreviacion << "|        " << anyo2024.enero[22].abreviacion << "|        " << anyo2024.enero[23].abreviacion << "|        " << anyo2024.enero[24].abreviacion << "|        " << anyo2024.enero[25].abreviacion << "|           " << anyo2024.enero[26].abreviacion << "|         " << anyo2024.enero[27].abreviacion << "|" << endl;
    cout << "   |         |           |           |           |           |              |            |" << endl;
    cout << "   |---------|-----------|-----------|-----------|-----------|--------------|------------|" << endl;
    cout << "   |29       |30         |31         |           |           |              |            |" << endl;
    cout << "   |      " << anyo2024.enero[28].abreviacion << "|        " << anyo2024.enero[29].abreviacion << "|        " << anyo2024.enero[30].abreviacion << "|           |           |              |            |" << endl;
    cout << "   |         |           |           |           |           |              |            |" << endl;
    cout << "   ---------------------------------------------------------------------------------------" << endl;

   escribirFichero(anyo2024);
}
void febrero(TAnyo &anyo2024){



     cout << "                                    Febrero(2024)                                         " << endl;
    cout << "   ---------------------------------------------------------------------------------------" << endl;
    cout << "   |  Lunes  |  Martes   | Miercoles |  Jueves   |  Viernes  |   Sabado     |  Domingo   |" << endl;
    cout << "   ---------------------------------------------------------------------------------------" << endl;
    cout << "   |         |           |           |1          |2          |3             |4           |" << endl;
    cout << "   |         |           |           |        " << anyo2024.febrero[0].abreviacion << "|        " << anyo2024.febrero[1].abreviacion << "|           " << anyo2024.febrero[2].abreviacion << "|         " << anyo2024.febrero[3].abreviacion << "|" << endl;
    cout << "   |         |           |           |           |           |              |            |" << endl;
    cout << "   |---------|-----------|-----------|-----------|-----------|--------------|------------|" << endl;
    cout << "   |5        |6          |7          |8          |9          |10            |11          |" << endl;
    cout << "   |      " << anyo2024.febrero[4].abreviacion << "|        " << anyo2024.febrero[5].abreviacion << "|        " << anyo2024.febrero[6].abreviacion << "|        " << anyo2024.febrero[7].abreviacion << "|        " << anyo2024.febrero[8].abreviacion << "|           " << anyo2024.febrero[9].abreviacion << "|         " << anyo2024.febrero[10].abreviacion << "|" << endl;
    cout << "   |         |           |           |           |           |              |            |" << endl;
    cout << "   |---------|-----------|-----------|-----------|-----------|--------------|------------|" << endl;
    cout << "   |12       |13         |14         |15         |16         |17            |18          |" << endl;
    cout << "   |      " << anyo2024.febrero[11].abreviacion << "|        " << anyo2024.febrero[12].abreviacion << "|        " << anyo2024.febrero[13].abreviacion << "|        " << anyo2024.febrero[14].abreviacion << "|        " << anyo2024.febrero[15].abreviacion << "|           " << anyo2024.febrero[16].abreviacion << "|         " << anyo2024.febrero[17].abreviacion << "|" << endl;
    cout << "   |         |           |           |           |           |              |            |" << endl;
    cout << "   |---------|-----------|-----------|-----------|-----------|--------------|------------|" << endl;
    cout << "   |19       |20         |21         |22         |23         |24            |25          |" << endl;
    cout << "   |      " << anyo2024.febrero[18].abreviacion << "|        " << anyo2024.febrero[19].abreviacion << "|        " << anyo2024.febrero[20].abreviacion << "|        " << anyo2024.febrero[21].abreviacion << "|        " << anyo2024.febrero[22].abreviacion << "|           " << anyo2024.febrero[23].abreviacion << "|         " << anyo2024.febrero[24].abreviacion << "|" << endl;
    cout << "   |         |           |           |           |           |              |            |" << endl;
    cout << "   |---------|-----------|-----------|-----------|-----------|--------------|------------|" << endl;
    cout << "   |26       |27         |28         |29         |           |              |            |" << endl;
    cout << "   |      " << anyo2024.febrero[25].abreviacion << "|        " << anyo2024.febrero[26].abreviacion << "|        " << anyo2024.febrero[27].abreviacion << "|        " << anyo2024.febrero[28].abreviacion << "|           |              |            |" << endl;
    cout << "   |         |           |           |           |           |              |            |" << endl;
    cout << "   ---------------------------------------------------------------------------------------" << endl;

    escribirFichero(anyo2024);
}
void marzo(TAnyo &anyo2024){
 cout << "                                         Marzo(2024)                                         " << endl;
    cout << "   ---------------------------------------------------------------------------------------" << endl;
    cout << "   |  Lunes  |  Martes   | Miercoles |  Jueves   |  Viernes  |   Sabado     |  Domingo   |" << endl;
    cout << "   ---------------------------------------------------------------------------------------" << endl;
    cout << "   |         |           |           |           |1          |2             |3           |" << endl;
    cout << "   |         |           |           |           |        " << anyo2024.marzo[0].abreviacion << "|           " << anyo2024.marzo[1].abreviacion << "|         " << anyo2024.marzo[2].abreviacion << "|" << endl;
    cout << "   |         |           |           |           |           |              |            |" << endl;
    cout << "   |---------|-----------|-----------|-----------|-----------|--------------|------------|" << endl;
    cout << "   |4        |5          |6          |7          |8          |9             |10          |" << endl;
    cout << "   |      " << anyo2024.marzo[3].abreviacion << "|        " << anyo2024.marzo[4].abreviacion << "|        " << anyo2024.marzo[5].abreviacion << "|        " << anyo2024.marzo[6].abreviacion << "|        " << anyo2024.marzo[7].abreviacion << "|           " << anyo2024.marzo[8].abreviacion << "|         " << anyo2024.marzo[9].abreviacion << "|" << endl;
    cout << "   |         |           |           |           |           |              |            |" << endl;
    cout << "   |---------|-----------|-----------|-----------|-----------|--------------|------------|" << endl;
    cout << "   |11       |12         |13         |14         |15         |16            |17          |" << endl;
    cout << "   |      " << anyo2024.marzo[10].abreviacion << "|        " << anyo2024.marzo[11].abreviacion << "|        " << anyo2024.marzo[12].abreviacion << "|        " << anyo2024.marzo[13].abreviacion << "|        " << anyo2024.marzo[14].abreviacion << "|           " << anyo2024.marzo[15].abreviacion << "|         " << anyo2024.marzo[16].abreviacion << "|" << endl;
    cout << "   |         |           |           |           |           |              |            |" << endl;
    cout << "   |---------|-----------|-----------|-----------|-----------|--------------|------------|" << endl;
    cout << "   |18       |19         |20         |21         |22         |23            |24          |" << endl;
    cout << "   |      " << anyo2024.marzo[17].abreviacion << "|        " << anyo2024.marzo[18].abreviacion << "|        " << anyo2024.marzo[19].abreviacion << "|        " << anyo2024.marzo[20].abreviacion << "|        " << anyo2024.marzo[21].abreviacion << "|           " << anyo2024.marzo[22].abreviacion << "|         " << anyo2024.marzo[23].abreviacion << "|" << endl;
    cout << "   |         |           |           |           |           |              |            |" << endl;
    cout << "   |---------|-----------|-----------|-----------|-----------|--------------|------------|" << endl;
    cout << "   |25       |26         |27         |28         |29         |30            |31          |" << endl;
    cout << "   |      " << anyo2024.marzo[24].abreviacion << "|        " << anyo2024.marzo[25].abreviacion << "|        " << anyo2024.marzo[26].abreviacion << "|        " << anyo2024.marzo[27].abreviacion << "|        " << anyo2024.marzo[28].abreviacion << "|           " << anyo2024.marzo[29].abreviacion << "|         " << anyo2024.marzo[30].abreviacion << "|" << endl;
    cout << "   |         |           |           |           |           |              |            |" << endl;
    cout << "   ---------------------------------------------------------------------------------------" << endl;
     escribirFichero(anyo2024);
}
void abril(TAnyo &anyo2024){
 cout << "                                         Abril(2024)                                         " << endl;
    cout << "   ---------------------------------------------------------------------------------------" << endl;
    cout << "   |  Lunes  |  Martes   | Miercoles |  Jueves   |  Viernes  |   Sabado     |  Domingo   |" << endl;
    cout << "   ---------------------------------------------------------------------------------------" << endl;
    cout << "   |1        |2          |3          |4          |5          |6             |7           |" << endl;
    cout << "   |      " << anyo2024.abril[0].abreviacion << "|        " << anyo2024.abril[1].abreviacion << "|        " << anyo2024.abril[2].abreviacion << "|        " << anyo2024.abril[3].abreviacion << "|        " << anyo2024.abril[4].abreviacion << "|           " << anyo2024.abril[5].abreviacion << "|         " << anyo2024.abril[6].abreviacion << "|" << endl;
    cout << "   |         |           |           |           |           |              |            |" << endl;
    cout << "   |---------|-----------|-----------|-----------|-----------|--------------|------------|" << endl;
    cout << "   |8        |9          |10         |11         |12         |13            |14          |" << endl;
    cout << "   |      " << anyo2024.abril[7].abreviacion << "|        " << anyo2024.abril[8].abreviacion << "|        " << anyo2024.abril[9].abreviacion << "|        " << anyo2024.abril[10].abreviacion << "|        " << anyo2024.abril[11].abreviacion << "|           " << anyo2024.abril[12].abreviacion << "|         " << anyo2024.abril[13].abreviacion << "|" << endl;
    cout << "   |         |           |           |           |           |              |            |" << endl;
    cout << "   |---------|-----------|-----------|-----------|-----------|--------------|------------|" << endl;
    cout << "   |15       |16         |17         |18         |19         |20            |21          |" << endl;
    cout << "   |      " << anyo2024.abril[14].abreviacion << "|        " << anyo2024.abril[15].abreviacion << "|        " << anyo2024.abril[16].abreviacion << "|        " << anyo2024.abril[17].abreviacion << "|        " << anyo2024.abril[18].abreviacion << "|           " << anyo2024.abril[19].abreviacion << "|         " << anyo2024.abril[20].abreviacion << "|" << endl;
    cout << "   |         |           |           |           |           |              |            |" << endl;
    cout << "   |---------|-----------|-----------|-----------|-----------|--------------|------------|" << endl;
    cout << "   |22       |23         |24         |25         |26         |27            |28          |" << endl;
    cout << "   |      " << anyo2024.abril[21].abreviacion << "|        " << anyo2024.abril[22].abreviacion << "|        " << anyo2024.abril[23].abreviacion << "|        " << anyo2024.abril[24].abreviacion << "|        " << anyo2024.abril[25].abreviacion << "|           " << anyo2024.abril[26].abreviacion << "|         " << anyo2024.abril[27].abreviacion << "|" << endl;
    cout << "   |         |           |           |           |           |              |            |" << endl;
    cout << "   |---------|-----------|-----------|-----------|-----------|--------------|------------|" << endl;
    cout << "   |29       |30         |           |           |           |              |            |" << endl;
    cout << "   |      " << anyo2024.abril[28].abreviacion << "|        " << anyo2024.abril[29].abreviacion << "|           |           |           |              |            |" << endl;
    cout << "   |         |           |           |           |           |              |            |" << endl;
    cout << "   ---------------------------------------------------------------------------------------" << endl;
     escribirFichero(anyo2024);
}
void mayo(TAnyo &anyo2024){
 cout << "                                         Mayo(2024)                                         " << endl;
    cout << "   ---------------------------------------------------------------------------------------" << endl;
    cout << "   |  Lunes  |  Martes   | Miercoles |  Jueves   |  Viernes  |   Sabado     |  Domingo   |" << endl;
    cout << "   ---------------------------------------------------------------------------------------" << endl;
    cout << "   |         |           |1          |2          |3          |4             |5           |" << endl;
    cout << "   |         |           |        " << anyo2024.mayo[0].abreviacion << "|        " << anyo2024.mayo[1].abreviacion << "|        " << anyo2024.mayo[2].abreviacion << "|           " << anyo2024.mayo[3].abreviacion << "|         " << anyo2024.mayo[4].abreviacion << "|" << endl;
    cout << "   |         |           |           |           |           |              |            |" << endl;
    cout << "   |---------|-----------|-----------|-----------|-----------|--------------|------------|" << endl;
    cout << "   |6        |7          |8          |9          |10         |11            |12          |" << endl;
    cout << "   |      " << anyo2024.mayo[5].abreviacion << "|        " << anyo2024.mayo[6].abreviacion << "|        " << anyo2024.mayo[7].abreviacion << "|        " << anyo2024.mayo[8].abreviacion << "|        " << anyo2024.mayo[9].abreviacion << "|           " << anyo2024.mayo[10].abreviacion << "|         " << anyo2024.mayo[11].abreviacion << "|" << endl;
    cout << "   |         |           |           |           |           |              |            |" << endl;
    cout << "   |---------|-----------|-----------|-----------|-----------|--------------|------------|" << endl;
    cout << "   |13       |14         |15         |16         |17         |18            |19          |" << endl;
    cout << "   |      " << anyo2024.mayo[12].abreviacion << "|        " << anyo2024.mayo[13].abreviacion << "|        " << anyo2024.mayo[14].abreviacion << "|        " << anyo2024.mayo[15].abreviacion << "|        " << anyo2024.mayo[16].abreviacion << "|           " << anyo2024.mayo[17].abreviacion << "|         " << anyo2024.mayo[18].abreviacion << "|" << endl;
    cout << "   |         |           |           |           |           |              |            |" << endl;
    cout << "   |---------|-----------|-----------|-----------|-----------|--------------|------------|" << endl;
    cout << "   |20       |21         |22         |23         |24         |25            |26          |" << endl;
    cout << "   |      " << anyo2024.mayo[19].abreviacion << "|        " << anyo2024.mayo[20].abreviacion << "|        " << anyo2024.mayo[21].abreviacion << "|        " << anyo2024.mayo[22].abreviacion << "|        " << anyo2024.mayo[23].abreviacion << "|           " << anyo2024.mayo[24].abreviacion << "|         " << anyo2024.mayo[25].abreviacion << "|" << endl;
    cout << "   |         |           |           |           |           |              |            |" << endl;
    cout << "   |---------|-----------|-----------|-----------|-----------|--------------|------------|" << endl;
    cout << "   |27       |28         |29         |30         |31         |              |            |" << endl;
    cout << "   |      " << anyo2024.mayo[26].abreviacion << "|        " << anyo2024.mayo[27].abreviacion << "|        " << anyo2024.mayo[28].abreviacion << "|        " << anyo2024.mayo[29].abreviacion << "|        " << anyo2024.mayo[30].abreviacion << "|              |            |" << endl;
    cout << "   |         |           |           |           |           |              |            |" << endl;
    cout << "   ---------------------------------------------------------------------------------------" << endl;
     escribirFichero(anyo2024);
}
void junio(TAnyo &anyo2024){
 cout << "                                         Junio(2024)                                         " << endl;
    cout << "   ---------------------------------------------------------------------------------------" << endl;
    cout << "   |  Lunes  |  Martes   | Miercoles |  Jueves   |  Viernes  |   Sabado     |  Domingo   |" << endl;
    cout << "   ---------------------------------------------------------------------------------------" << endl;
    cout << "   |         |           |           |           |           |1             |2           |" << endl;
    cout << "   |         |           |           |           |           |           " << anyo2024.junio[0].abreviacion << "|         " << anyo2024.junio[1].abreviacion << "|" << endl;
    cout << "   |         |           |           |           |           |              |            |" << endl;
    cout << "   |---------|-----------|-----------|-----------|-----------|--------------|------------|" << endl;
    cout << "   |3        |4          |5          |6          |7          |8             |9           |" << endl;
    cout << "   |      " << anyo2024.junio[2].abreviacion << "|        " << anyo2024.junio[3].abreviacion << "|        " << anyo2024.junio[4].abreviacion << "|        " << anyo2024.junio[5].abreviacion << "|        " << anyo2024.junio[6].abreviacion << "|           " << anyo2024.junio[7].abreviacion << "|         " << anyo2024.junio[8].abreviacion << "|" << endl;
    cout << "   |         |           |           |           |           |              |            |" << endl;
    cout << "   |---------|-----------|-----------|-----------|-----------|--------------|------------|" << endl;
    cout << "   |10       |11         |12         |13         |14         |15            |16          |" << endl;
    cout << "   |      " << anyo2024.junio[9].abreviacion << "|        " << anyo2024.junio[10].abreviacion << "|        " << anyo2024.junio[11].abreviacion << "|        " << anyo2024.junio[12].abreviacion << "|        " << anyo2024.junio[13].abreviacion << "|           " << anyo2024.junio[14].abreviacion << "|         " << anyo2024.junio[8].abreviacion << "|" << endl;
    cout << "   |         |           |           |           |           |              |            |" << endl;
    cout << "   |---------|-----------|-----------|-----------|-----------|--------------|------------|" << endl;
    cout << "   |17       |18         |19         |20         |21         |22            |23          |" << endl;
    cout << "   |      " << anyo2024.junio[16].abreviacion << "|        " << anyo2024.junio[17].abreviacion << "|        " << anyo2024.junio[18].abreviacion << "|        " << anyo2024.junio[19].abreviacion << "|        " << anyo2024.junio[20].abreviacion << "|           " << anyo2024.junio[21].abreviacion << "|         " << anyo2024.junio[22].abreviacion << "|" << endl;
    cout << "   |         |           |           |           |           |              |            |" << endl;
    cout << "   |---------|-----------|-----------|-----------|-----------|--------------|------------|" << endl;
    cout << "   |24       |25         |26         |27         |28         |29            |30          |" << endl;
    cout << "   |      " << anyo2024.junio[23].abreviacion << "|        " << anyo2024.junio[24].abreviacion << "|        " << anyo2024.junio[25].abreviacion << "|        " << anyo2024.junio[26].abreviacion << "|        " << anyo2024.junio[27].abreviacion << "|           " << anyo2024.junio[28].abreviacion << "|         " << anyo2024.junio[29].abreviacion << "|" << endl;
    cout << "   |         |           |           |           |           |              |            |" << endl;
    cout << "   ---------------------------------------------------------------------------------------" << endl;
     escribirFichero(anyo2024);
}
void julio(TAnyo &anyo2024){
 cout << "                                         Julio(2024)                                         " << endl;
    cout << "   ---------------------------------------------------------------------------------------" << endl;
    cout << "   |  Lunes  |  Martes   | Miercoles |  Jueves   |  Viernes  |   Sabado     |  Domingo   |" << endl;
    cout << "   ---------------------------------------------------------------------------------------" << endl;
    cout << "   |1        |2          |3          |4          |5          |6             |7           |" << endl;
    cout << "   |      " << anyo2024.julio[0].abreviacion << "|        " << anyo2024.julio[1].abreviacion << "|        " << anyo2024.julio[2].abreviacion << "|        " << anyo2024.julio[3].abreviacion << "|        " << anyo2024.julio[4].abreviacion << "|           " << anyo2024.julio[5].abreviacion << "|         " << anyo2024.julio[6].abreviacion << "|" << endl;
    cout << "   |         |           |           |           |           |              |            |" << endl;
    cout << "   |---------|-----------|-----------|-----------|-----------|--------------|------------|" << endl;
    cout << "   |8        |9          |10         |11         |12         |13            |14          |" << endl;
    cout << "   |      " << anyo2024.julio[7].abreviacion << "|        " << anyo2024.julio[8].abreviacion << "|        " << anyo2024.julio[9].abreviacion << "|        " << anyo2024.julio[10].abreviacion << "|        " << anyo2024.julio[11].abreviacion << "|           " << anyo2024.julio[12].abreviacion << "|         " << anyo2024.julio[13].abreviacion << "|" << endl;
    cout << "   |         |           |           |           |           |              |            |" << endl;
    cout << "   |---------|-----------|-----------|-----------|-----------|--------------|------------|" << endl;
    cout << "   |15       |16         |17         |18         |19         |20            |21          |" << endl;
    cout << "   |      " << anyo2024.julio[14].abreviacion << "|        " << anyo2024.julio[15].abreviacion << "|        " << anyo2024.julio[16].abreviacion << "|        " << anyo2024.julio[17].abreviacion << "|        " << anyo2024.julio[18].abreviacion << "|           " << anyo2024.julio[19].abreviacion << "|         " << anyo2024.julio[20].abreviacion << "|" << endl;
    cout << "   |         |           |           |           |           |              |            |" << endl;
    cout << "   |---------|-----------|-----------|-----------|-----------|--------------|------------|" << endl;
    cout << "   |22       |23         |24         |25         |26         |27            |28          |" << endl;
    cout << "   |      " << anyo2024.julio[21].abreviacion << "|        " << anyo2024.julio[22].abreviacion << "|        " << anyo2024.julio[23].abreviacion << "|        " << anyo2024.julio[24].abreviacion << "|        " << anyo2024.julio[25].abreviacion << "|           " << anyo2024.julio[26].abreviacion << "|         " << anyo2024.julio[27].abreviacion << "|" << endl;
    cout << "   |         |           |           |           |           |              |            |" << endl;
    cout << "   |---------|-----------|-----------|-----------|-----------|--------------|------------|" << endl;
    cout << "   |29       |30         |31         |           |           |              |            |" << endl;
    cout << "   |      " << anyo2024.julio[28].abreviacion << "|        " << anyo2024.julio[29].abreviacion << "|        " << anyo2024.julio[30].abreviacion << "|           |           |              |            |" << endl;
    cout << "   |         |           |           |           |           |              |            |" << endl;
    cout << "   ---------------------------------------------------------------------------------------" << endl;
     escribirFichero(anyo2024);
}
void agosto(TAnyo &anyo2024){
 cout << "                                         Agosto(2024)                                        " << endl;
    cout << "   ---------------------------------------------------------------------------------------" << endl;
    cout << "   |  Lunes  |  Martes   | Miercoles |  Jueves   |  Viernes  |   Sabado     |  Domingo   |" << endl;
    cout << "   ---------------------------------------------------------------------------------------" << endl;
    cout << "   |         |           |           |1          |2          |3             |4           |" << endl;
    cout << "   |         |           |           |        " << anyo2024.agosto[0].abreviacion << "|        " << anyo2024.agosto[1].abreviacion << "|           " << anyo2024.agosto[2].abreviacion << "|         " << anyo2024.agosto[3].abreviacion << "|" << endl;
    cout << "   |         |           |           |           |           |              |            |" << endl;
    cout << "   |---------|-----------|-----------|-----------|-----------|--------------|------------|" << endl;
    cout << "   |5        |6          |7          |8          |9          |10            |11          |" << endl;
    cout << "   |      " << anyo2024.agosto[4].abreviacion << "|        " << anyo2024.agosto[5].abreviacion << "|        " << anyo2024.agosto[6].abreviacion << "|        " << anyo2024.agosto[7].abreviacion << "|        " << anyo2024.agosto[8].abreviacion << "|           " << anyo2024.agosto[9].abreviacion << "|         " << anyo2024.agosto[10].abreviacion << "|" << endl;
    cout << "   |         |           |           |           |           |              |            |" << endl;
    cout << "   |---------|-----------|-----------|-----------|-----------|--------------|------------|" << endl;
    cout << "   |12       |13         |14         |15         |16         |17            |18          |" << endl;
    cout << "   |      " << anyo2024.agosto[11].abreviacion << "|        " << anyo2024.agosto[12].abreviacion << "|        " << anyo2024.agosto[13].abreviacion << "|        " << anyo2024.agosto[14].abreviacion << "|        " << anyo2024.agosto[15].abreviacion << "|           " << anyo2024.agosto[16].abreviacion << "|         " << anyo2024.agosto[17].abreviacion << "|" << endl;
    cout << "   |         |           |           |           |           |              |            |" << endl;
    cout << "   |---------|-----------|-----------|-----------|-----------|--------------|------------|" << endl;
    cout << "   |19       |20         |21         |22         |23         |24            |25          |" << endl;
    cout << "   |      " << anyo2024.agosto[18].abreviacion << "|        " << anyo2024.agosto[19].abreviacion << "|        " << anyo2024.agosto[20].abreviacion << "|        " << anyo2024.agosto[21].abreviacion << "|        " << anyo2024.agosto[22].abreviacion << "|           " << anyo2024.agosto[23].abreviacion << "|         " << anyo2024.agosto[24].abreviacion << "|" << endl;
    cout << "   |         |           |           |           |           |              |            |" << endl;
    cout << "   |---------|-----------|-----------|-----------|-----------|--------------|------------|" << endl;
    cout << "   |26       |27         |28         |29         |30         |31            |            |" << endl;
    cout << "   |      " << anyo2024.agosto[25].abreviacion << "|        " << anyo2024.agosto[26].abreviacion << "|        " << anyo2024.agosto[27].abreviacion << "|        " << anyo2024.agosto[28].abreviacion << "|        " << anyo2024.agosto[29].abreviacion << "|           " << anyo2024.agosto[30].abreviacion << "|            |" << endl;
    cout << "   |         |           |           |           |           |              |            |" << endl;
    cout << "   ---------------------------------------------------------------------------------------" << endl;
     escribirFichero(anyo2024);
}
void septiembre(TAnyo &anyo2024){
 cout << "                                       Septiembre(2024)                                      " << endl;
    cout << "   ---------------------------------------------------------------------------------------" << endl;
    cout << "   |  Lunes  |  Martes   | Miercoles |  Jueves   |  Viernes  |   Sabado     |  Domingo   |" << endl;
    cout << "   ---------------------------------------------------------------------------------------" << endl;
    cout << "   |         |           |           |           |           |              |1           |" << endl;
    cout << "   |         |           |           |           |           |              |            |" << endl;
    cout << "   |         |           |           |           |           |              |            |" << endl;
    cout << "   |---------|-----------|-----------|-----------|-----------|--------------|------------|" << endl;
    cout << "   |2        |3          |4          |5          |6          |7             |8           |" << endl;
    cout << "   |      " << anyo2024.septiembre[1].abreviacion << "|        " << anyo2024.septiembre[2].abreviacion << "|        " << anyo2024.septiembre[3].abreviacion << "|        " << anyo2024.septiembre[4].abreviacion << "|        " << anyo2024.septiembre[5].abreviacion << "|           " << anyo2024.septiembre[6].abreviacion << "|         " << anyo2024.septiembre[7].abreviacion << "|" << endl;
    cout << "   |         |           |           |           |           |              |            |" << endl;
    cout << "   |---------|-----------|-----------|-----------|-----------|--------------|------------|" << endl;
    cout << "   |9        |10         |11         |12         |13         |14            |15          |" << endl;
    cout << "   |      " << anyo2024.septiembre[8].abreviacion << "|        " << anyo2024.septiembre[9].abreviacion << "|        " << anyo2024.septiembre[10].abreviacion << "|        " << anyo2024.septiembre[11].abreviacion << "|        " << anyo2024.septiembre[12].abreviacion << "|           " << anyo2024.septiembre[13].abreviacion << "|         " << anyo2024.septiembre[14].abreviacion << "|" << endl;
    cout << "   |         |           |           |           |           |              |            |" << endl;
    cout << "   |---------|-----------|-----------|-----------|-----------|--------------|------------|" << endl;
    cout << "   |16       |17         |18         |19         |20         |21            |22          |" << endl;
    cout << "   |      " << anyo2024.septiembre[15].abreviacion << "|        " << anyo2024.septiembre[16].abreviacion << "|        " << anyo2024.septiembre[17].abreviacion << "|        " << anyo2024.septiembre[18].abreviacion << "|        " << anyo2024.septiembre[19].abreviacion << "|           " << anyo2024.septiembre[20].abreviacion << "|         " << anyo2024.septiembre[21].abreviacion << "|" << endl;
    cout << "   |         |           |           |           |           |              |            |" << endl;
    cout << "   |---------|-----------|-----------|-----------|-----------|--------------|------------|" << endl;
    cout << "   |23       |24         |25         |26         |27         |28            |29          |" << endl;
    cout << "   |      " << anyo2024.septiembre[22].abreviacion << "|        " << anyo2024.septiembre[23].abreviacion << "|        " << anyo2024.septiembre[24].abreviacion << "|        " << anyo2024.septiembre[25].abreviacion << "|        " << anyo2024.septiembre[26].abreviacion << "|           " << anyo2024.septiembre[27].abreviacion << "|         " << anyo2024.septiembre[28].abreviacion << "|" << endl;
    cout << "   |         |           |           |           |           |              |            |" << endl;
    cout << "   |---------|----------- ----------- ----------- ----------- -------------- ------------" << endl;
    cout << "   |30       |" << endl;
    cout << "   |      " <<  anyo2024.septiembre[29].abreviacion << "|" << endl;
    cout << "   |         |" << endl;
    cout << "    ---------" << endl;
     escribirFichero(anyo2024);
}
void octubre(TAnyo &anyo2024){
 cout << "                                        Octubre(2024)                                        " << endl;
    cout << "   ---------------------------------------------------------------------------------------" << endl;
    cout << "   |  Lunes  |  Martes   | Miercoles |  Jueves   |  Viernes  |   Sabado     |  Domingo   |" << endl;
    cout << "   ---------------------------------------------------------------------------------------" << endl;
    cout << "   |         |1          |2          |3          |4          |5             |6           |" << endl;
    cout << "   |         |        " << anyo2024.octubre[0].abreviacion << "|        " << anyo2024.octubre[1].abreviacion << "|        " << anyo2024.octubre[2].abreviacion << "|        " << anyo2024.octubre[3].abreviacion << "|           " << anyo2024.octubre[4].abreviacion << "|         " << anyo2024.octubre[5].abreviacion << "|" << endl;
    cout << "   |         |           |           |           |           |              |            |" << endl;
    cout << "   |---------|-----------|-----------|-----------|-----------|--------------|------------|" << endl;
    cout << "   |7        |8          |9          |10         |11         |12            |13          |" << endl;
    cout << "   |         |           |           |           |           |              |            |" << endl;
    cout << "   |         |           |           |           |           |              |            |" << endl;
    cout << "   |---------|-----------|-----------|-----------|-----------|--------------|------------|" << endl;
    cout << "   |14       |15         |16         |17         |18         |19            |20          |" << endl;
    cout << "   |      " << anyo2024.octubre[13].abreviacion << "|        " << anyo2024.octubre[14].abreviacion << "|        " << anyo2024.octubre[15].abreviacion << "|        " << anyo2024.octubre[16].abreviacion << "|        " << anyo2024.octubre[17].abreviacion << "|           " << anyo2024.octubre[18].abreviacion << "|         " << anyo2024.octubre[19].abreviacion << "|" << endl;
    cout << "   |         |           |           |           |           |              |            |" << endl;
    cout << "   |---------|-----------|-----------|-----------|-----------|--------------|------------|" << endl;
    cout << "   |21       |22         |23         |24         |25         |26            |27          |" << endl;
    cout << "   |      " << anyo2024.octubre[20].abreviacion << "|        " << anyo2024.octubre[21].abreviacion << "|        " << anyo2024.octubre[22].abreviacion << "|        " << anyo2024.octubre[23].abreviacion << "|        " << anyo2024.octubre[24].abreviacion << "|           " << anyo2024.octubre[25].abreviacion << "|         " << anyo2024.octubre[26].abreviacion << "|" << endl;
    cout << "   |         |           |           |           |           |              |            |" << endl;
    cout << "   |---------|-----------|-----------|-----------|-----------|--------------|------------|" << endl;
    cout << "   |28       |29         |30         |31         |           |              |            |" << endl;
    cout << "   |      " << anyo2024.octubre[27].abreviacion << "|        " << anyo2024.octubre[28].abreviacion << "|        " << anyo2024.octubre[29].abreviacion << "|        " << anyo2024.octubre[30].abreviacion << "|           |              |            |" << endl;
    cout << "   |         |           |           |           |           |              |            |" << endl;
    cout << "   ---------------------------------------------------------------------------------------" << endl;
     escribirFichero(anyo2024);
}
void noviembre(TAnyo &anyo2024){
    cout << endl;
 cout << "                                       Noviembre(2024)                                       " << endl;
    cout << "   ---------------------------------------------------------------------------------------" << endl;
    cout << "   |  Lunes  |  Martes   | Miercoles |  Jueves   |  Viernes  |   Sabado     |  Domingo   |" << endl;
    cout << "   ---------------------------------------------------------------------------------------" << endl;
    cout << "   |         |           |           |           |1          |2             |3           |" << endl;
    cout << "   |         |           |           |           |        " << anyo2024.noviembre[0].abreviacion << "|           "   << anyo2024.noviembre[1].abreviacion <<    "|         " << anyo2024.noviembre[2].abreviacion << "|" << endl;
    cout << "   |         |           |           |           |           |              |            |" << endl;
    cout << "   |---------|-----------|-----------|-----------|-----------|--------------|------------|" << endl;
    cout << "   |4        |5          |6          |7          |8          |9             |10          |" << endl;
    cout << "   |      " << anyo2024.noviembre[3].abreviacion << "|        " << anyo2024.noviembre[4].abreviacion << "|        " << anyo2024.noviembre[5].abreviacion << "|        " << anyo2024.noviembre[6].abreviacion << "|        " << anyo2024.noviembre[7].abreviacion << "|           " << anyo2024.noviembre[8].abreviacion << "|         " << anyo2024.noviembre[31].abreviacion << "|" << endl;
    cout << "   |         |           |           |           |           |              |            |" << endl;
    cout << "   |---------|-----------|-----------|-----------|-----------|--------------|------------|" << endl;
    cout << "   |11       |12         |13         |14         |15         |16            |17          |" << endl;
    cout << "   |      " << anyo2024.noviembre[10].abreviacion << "|        " << anyo2024.noviembre[11].abreviacion << "|        " << anyo2024.noviembre[12].abreviacion << "|        " << anyo2024.noviembre[13].abreviacion << "|        " << anyo2024.noviembre[14].abreviacion << "|           " << anyo2024.noviembre[15].abreviacion << "|         " << anyo2024.noviembre[16].abreviacion << "|" << endl;
    cout << "   |         |           |           |           |           |              |            |" << endl;
    cout << "   |---------|-----------|-----------|-----------|-----------|--------------|------------|" << endl;
    cout << "   |18       |19         |20         |21         |22         |23            |24          |" << endl;
    cout << "   |      " << anyo2024.noviembre[17].abreviacion << "|        " << anyo2024.noviembre[18].abreviacion << "|        " << anyo2024.noviembre[19].abreviacion << "|        " << anyo2024.noviembre[20].abreviacion << "|        " << anyo2024.noviembre[21].abreviacion << "|           " << anyo2024.noviembre[22].abreviacion << "|         " << anyo2024.noviembre[23].abreviacion << "|" << endl;
    cout << "   |         |           |           |           |           |              |            |" << endl;
    cout << "   |---------|-----------|-----------|-----------|-----------|--------------|------------|" << endl;
    cout << "   |25       |26         |27         |28         |29         |30            |30          |" << endl;
    cout << "   |      " << anyo2024.noviembre[24].abreviacion << "|        " << anyo2024.noviembre[25].abreviacion << "|        " << anyo2024.noviembre[26].abreviacion << "|        " << anyo2024.noviembre[27].abreviacion << "|        " << anyo2024.noviembre[28].abreviacion << "|           " << anyo2024.noviembre[29].abreviacion << "|         " << anyo2024.noviembre[30].abreviacion << "|" << endl;
    cout << "   |         |           |           |           |           |              |            |" << endl;
    cout << "   ---------------------------------------------------------------------------------------" << endl;
     escribirFichero(anyo2024);
}
void diciembre(TAnyo &anyo2024){
 cout << "                                       Diciembre(2024)                                       " << endl;
    cout << "   ---------------------------------------------------------------------------------------" << endl;
    cout << "   |  Lunes  |  Martes   | Miercoles |  Jueves   |  Viernes  |   Sabado     |  Domingo   |" << endl;
    cout << "   ---------------------------------------------------------------------------------------" << endl;
    cout << "   |         |           |           |           |           |              |1           |" << endl;
    cout << "   |         |           |           |           |           |              |         " << anyo2024.diciembre[0].abreviacion << "|" << endl;
    cout << "   |         |           |           |           |           |              |            |" << endl;
    cout << "   |---------|-----------|-----------|-----------|-----------|--------------|------------|" << endl;
    cout << "   |2        |3          |4          |5          |6          |7             |8           |" << endl;
    cout << "   |      " << anyo2024.diciembre[1].abreviacion << "|        " << anyo2024.diciembre[2].abreviacion << "|        " << anyo2024.diciembre[3].abreviacion << "|        " << anyo2024.diciembre[4].abreviacion << "|        " << anyo2024.diciembre[5].abreviacion << "|           " << anyo2024.diciembre[6].abreviacion << "|         " << anyo2024.diciembre[7].abreviacion << "|" << endl;
    cout << "   |         |           |           |           |           |              |            |" << endl;
    cout << "   |---------|-----------|-----------|-----------|-----------|--------------|------------|" << endl;
    cout << "   |9        |10         |11         |12         |13         |14            |15          |" << endl;
    cout << "   |      " << anyo2024.diciembre[8].abreviacion << "|        " << anyo2024.diciembre[9].abreviacion << "|        " << anyo2024.diciembre[10].abreviacion << "|        " << anyo2024.diciembre[11].abreviacion << "|        " << anyo2024.diciembre[12].abreviacion << "|           " << anyo2024.diciembre[13].abreviacion << "|         " << anyo2024.diciembre[14].abreviacion << "|" << endl;
    cout << "   |         |           |           |           |           |              |            |" << endl;
    cout << "   |---------|-----------|-----------|-----------|-----------|--------------|------------|" << endl;
    cout << "   |16       |17         |18         |19         |20         |21            |22          |" << endl;
    cout << "   |      " << anyo2024.diciembre[15].abreviacion << "|        " << anyo2024.diciembre[16].abreviacion << "|        " << anyo2024.diciembre[17].abreviacion << "|        " << anyo2024.diciembre[18].abreviacion << "|        " << anyo2024.diciembre[19].abreviacion << "|           " << anyo2024.diciembre[20].abreviacion << "|         " << anyo2024.diciembre[21].abreviacion << "|" << endl;
    cout << "   |         |           |           |           |           |              |            |" << endl;
    cout << "   |---------|-----------|-----------|-----------|-----------|--------------|------------|" << endl;
    cout << "   |23       |24         |25         |26         |27         |28            |29          |" << endl;
    cout << "   |      " << anyo2024.diciembre[22].abreviacion << "|        " << anyo2024.diciembre[23].abreviacion << "|        " << anyo2024.diciembre[24].abreviacion << "|        " << anyo2024.diciembre[25].abreviacion << "|        " << anyo2024.diciembre[26].abreviacion << "|           " << anyo2024.diciembre[27].abreviacion << "|         " << anyo2024.diciembre[28].abreviacion << "|" << endl;
    cout << "   |         |           |           |           |           |              |            |" << endl;
    cout << "   |---------|-----------|----------- ----------- ----------- -------------- ------------ " << endl;
    cout << "   |30       |31         |" << endl;
    cout << "   |      " << anyo2024.diciembre[29].abreviacion << "|        " << anyo2024.diciembre[30].abreviacion << "|" << endl;
    cout << "   |         |           |" << endl;
    cout << "    --------- ----------- " << endl;
     escribirFichero(anyo2024);
}

void leerFichero(TAnyo &anyo2024){
    ifstream fichero;

    fichero.open(nombreFichero, ios::in | ios::binary);
    if(fichero.is_open()){
        fichero.read((char*)&anyo2024 , sizeof(TAnyo));
    }
    fichero.close();
}

void escribirFichero(TAnyo &anyo2024){
    ofstream fichero;

    fichero.open(nombreFichero, ios::out | ios::binary);
    if(fichero.is_open()){
        fichero.write((const char *)&anyo2024, sizeof(TAnyo));
    }
    fichero.close();
}

//FUNCION GOTOXY

void gotoxy(int x,int y){

      HANDLE hcon;

      hcon = GetStdHandle(STD_OUTPUT_HANDLE);

      COORD dwPos;

      dwPos.X = x;

      dwPos.Y= y;

      SetConsoleCursorPosition(hcon,dwPos);

 }





//FUNCION QUE DIBUJA EL CUADRO

void dibujarCuadro(int x1,int y1,int x2,int y2){

	int i;



    for (i=x1;i<x2;i++){

		gotoxy(i,y1); cout << "\304"; //linea horizontal superior

		gotoxy(i,y2); cout << "\304"; //linea horizontal inferior

    }



    for (i=y1;i<y2;i++){

		gotoxy(x1,i); cout <<"\263"; //linea vertical izquierda

		gotoxy(x2,i); cout <<"\263"; //linea vertical derecha

	}



    gotoxy(x1,y1); cout<< "\332";

    gotoxy(x1,y2); cout<< "\300";

    gotoxy(x2,y1); cout<< "\277";

    gotoxy(x2,y2); cout<< "\331";

}

