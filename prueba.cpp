/*#include <iostream>
#include <fstream>
#include <math.h>
#include <string>
#include <cstdlib>
#include <cstring>

using namespace std;

void metodo1(char* ,unsigned long long ,unsigned long ,unsigned long ,unsigned long ,unsigned long long );
void r_metodo1(char* ,unsigned long long ,unsigned long ,unsigned long ,unsigned long ,unsigned long long );
void sentencia(unsigned long,unsigned long,int8_t*);
void metodo2(string &, unsigned long long , unsigned long int  ,unsigned long int );
void r_metodo2(string &, unsigned long long , unsigned long int  ,unsigned long int );



int main()
{   // 1001 0010 1010 1010 1111 1001
    string binario="100100101010101011111001";
    unsigned long long tamano= 3;
    unsigned long semilla=3;
    cout<<binario<<endl;
    metodo2(binario,tamano,semilla,0);
    cout<<binario<<endl;
    r_metodo2(binario,tamano,semilla,0);
    cout<<binario<<endl;

    unsigned int cantidad=1;
    unsigned long long *claves = new unsigned long long [cantidad];

}


void metodo1(char* binario,unsigned long long tamano,unsigned long semilla,unsigned long ceros,unsigned long unos,unsigned long long posicion)
{
    int8_t aplicacion,regla;
    for(unsigned long int i = 0;i<((tamano*8)/semilla) and posicion< tamano*8 ;i++)
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
    if(tamano*8%semilla != 0)
    {
        unsigned long int sobras =(tamano*8)-posicion;
        metodo1(binario,tamano,sobras,ceros,unos,posicion);
    }
}

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

    if(tamano*8%semilla != 0)
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

void metodo2(string &text, unsigned long long tamano, unsigned long int  semilla,unsigned long int posicion)
{

    string nex,ultimo;

    for(unsigned int i=0;i<(tamano*8)/semilla and posicion<tamano*8;i++)
    {
        ultimo=text[posicion+semilla-1];
        nex=text[posicion+1];
        if(2<=semilla)
        {
            text[posicion+1]=text[posicion];
            text[posicion]=ultimo[0];
            posicion=posicion+2;
        }

        for(unsigned int e=2;e<semilla;e++,posicion++)
        {
            ultimo=nex;
            nex=text[posicion];
            text[posicion]=ultimo[0];
        }
    }

    if((tamano*8)%semilla != 0)
    {   unsigned long int conteo=(tamano*8)-posicion;
        metodo2(text,tamano,conteo,posicion);
    }
}

void r_metodo2(string &text, unsigned long long tamano, unsigned long int  semilla,unsigned long int posicion)
{
    string atras,ultimo;

    for(unsigned int i=0;i<(tamano*8)/semilla and posicion<tamano*8;i++)
    {
        ultimo=text[posicion];
        atras=text[posicion+1];
        text[posicion]=atras[0];
        posicion++;
        for(unsigned int e=1;e<semilla;e++,posicion++)
        {
            atras=text[posicion+1];
            text[posicion]=atras[0];
        }
        text[posicion-1]=ultimo[0];
    }
    if((tamano*8)%semilla != 0)
    {
        unsigned long int conteo=(tamano*8)-posicion;
        metodo2(text,tamano,conteo,posicion);
    }
}
