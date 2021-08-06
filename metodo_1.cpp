#include "funciones.h"

//codificacion o decodificacion
int COD()
{   int resultado=0;
    char cod=0;

    while (true)
    {
        cout<<"1.codificacion \n"
                "2.decodificacion"<<endl;
        cin>>cod;

        if(cod<=50 and cod>48)
        {
            break;
        }
        cout<<endl<<"porfavor precionar el numero correspondiente al metodo"<<endl;
    }
    return resultado=int(cod)-48;
}

void implementacion(unsigned long int* semilla,unsigned short int* metodo)
{
    cout<<"ingresa la semilla de codificacion"<<endl;cin>>*semilla;


    while (true)
    {
        cout<<endl<<" selecciona metodo de codificacion \n "
                "1.primer metodo \n 2.segundo metodo  "<<endl;cin>>*metodo;

        if(*metodo<=3 and *metodo>0)
        {
            break;
        }
        cout<<endl<<"porfavor precionar el numero correspondiente al metodo"<<endl;
    }

}

void m1_codificacion(unsigned long long int tamano ,unsigned long int semilla,char* nombre,char* texto)
{


    cout<<endl<<texto<<endl;
    metodo1(texto,tamano,semilla,0,0,0);
    cout<<endl<<texto<<endl;
    texto=traduccionM1(tamano,texto);
    cout<<endl<<texto<<endl;
    escribirM1(texto,nombre,tamano);
}
char* m1_decodificacion(unsigned long long int tamano ,unsigned long int semilla,char *nombre,char *texto)
{
    lecturaM1(nombre,tamano,texto);
    cout<<endl<<texto<<endl;

    r_metodo1(texto,tamano,semilla,0,0,0);
    texto=traduccionM1(tamano,texto);
    return texto;

}
void tam(char* nombre ,unsigned long long *tamano)
{
    fstream archivo(nombre, fstream::in | fstream::ate);
    *tamano=archivo.tellg();
    archivo.close();
}

void lecturaM1(char* nombre,unsigned long long tamano,char * datos)
{

    fstream archivo;
            archivo.open(nombre, fstream::in );

    for(unsigned long long int i=0, posicion=0 ; i<tamano ;i++)
    {    int letra=archivo.get();
        cout<<endl<<datos<<endl;
         binarioM1(&posicion,letra,datos);
    }
    archivo.close();
}


void escribirM1 ( char *datos, char *nombre, unsigned long long tamano)
{

    fstream text(nombre, fstream::out  |fstream::binary);
    text.write( datos,tamano);
    //text<< datos;
    text.close();
}



void binarioM1(unsigned long long int* posicion, unsigned ascii,char* codificado)
{
    char bits[8];

    int contador;


        contador=7;
        while (ascii > 0)
        {

            if (ascii % 2 == 0) bits[contador] = '0' ;

            else bits[contador]= '1';

            ascii = (int) ascii/2;
            contador--;
        }
        unsigned long long posi=*posicion;
        for (int e=0 ; e<8; e++, posi++ )
        {
            if (e <= contador)
            {
                codificado[posi]= '0';
            }
            else
            {
                codificado[posi]=bits[e];
            }

        }
        *posicion=posi;
}




char * traduccionM1(unsigned long long int tamano, char *bina)
{
    char *escribir= new char (tamano);
    int letra;

    for(unsigned int i=0,e=0;e<tamano;e++)
    {   letra=0;
        for(int a=7;0<=a;i++,a--)
        {
            letra=letra+(pow((int(bina[i])-48)*2,a));
        }
        if(bina[i-1]=='0') escribir[e]= char(letra-1);
        else escribir[e]= char(letra);
    }
    return escribir;
    delete  escribir;
}

//codificacion metodo I
void metodo1(char* binario,unsigned long long tamano,unsigned long semilla,unsigned long ceros,unsigned long unos,unsigned long long posicion)
{
    int8_t aplicacion,regla;
    for(unsigned long int i = 0;i<(tamano*8)/semilla and posicion < tamano*8 ;i++)
    {
        sentencia(ceros,unos,&regla);
        aplicacion=0;
        ceros=0;
        unos=0;
        for(unsigned long a=posicion,e=0;e<semilla;e++,a++)
        {
            if(binario[a]=='1') unos++;
        }
        ceros= semilla-unos;
        for(unsigned long e=0;e<semilla;posicion++,e++)
        {
            if(regla==aplicacion)
            {
                if(binario[posicion]=='1')binario[posicion]='0';
                else binario[posicion]='1';
                aplicacion=0;
            }
            else aplicacion++;
        }
    }
    if((tamano*8-posicion)%semilla != 0)
    {
        unsigned long int sobras =(tamano*8)-posicion;
        metodo1(binario,tamano,sobras,ceros,unos,posicion);
    }
}

//decodificacion metodo II
void r_metodo1(char* binario,unsigned long long tamano,unsigned long semilla,unsigned long ceros,unsigned long unos,unsigned long long posicion)
{
    int8_t aplicacion,regla;
    for(unsigned long int i = 0;i<((tamano*8)/semilla) and posicion< tamano*8 ;i++)
    {
        sentencia(ceros,unos,&regla);
        aplicacion=0;
        ceros=0;
        unos=0;

        for(unsigned long e=0;e<semilla;posicion++,e++)
        {
            if(regla==aplicacion)
            {
                if(binario[posicion]=='1')binario[posicion]='0';
                else binario[posicion]='1';
                aplicacion=0;
            }
            else aplicacion++;
        }
        for(unsigned long a=posicion-1,e=0;e<semilla;e++,a--)
        {
            if(binario[a]=='1') unos++;
        }
        ceros= semilla-unos;
    }

    if((tamano*8-posicion)%semilla != 0)
    {
        unsigned long int sobras =(tamano*8)-posicion;
        r_metodo1(binario,tamano,sobras,ceros,unos,posicion);
    }
}

void sentencia(unsigned long ceros,unsigned long unos,int8_t*reglas)
{
    if(ceros== unos)*reglas=0;
    else if( ceros > unos)*reglas=1;
    else *reglas=2;
}
