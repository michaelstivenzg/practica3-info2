#include "funciones.h"

int main()
{
    unsigned short int metodo;
    unsigned int long semilla;

    //codificacion
    implementacion(&semilla,&metodo);
    if(COD()==1)
    {


        if(metodo==1)
        {  //el conteo en bits de lo sacado en el txt
            unsigned long long tamano ;
            //los nombre de los archivos de texto _E Entrada _S Salida
            char nombre_E[]="natural.txt",nombre_S[]="codificado.dat";
            tam(nombre_E,&tamano);

            char *texto=new char[(tamano)*8];
            lecturaM1(nombre_E,tamano,texto);
            m1_codificacion(tamano,semilla,nombre_S,texto);
            delete[] texto;

        }
        else
        {
            unsigned long long *tamano = new unsigned long long;
            string texto,nombre="natural.txt";
            texto=lecturam2(nombre,tamano);

            //texto.pop_back();
            //*tamano=texto.length();

            cout<<endl<<texto<<endl<<endl;
            m2_codificacion(*tamano,semilla,"codificado.dat",texto);


            delete tamano;
        }



    }
    //decodificacion
    else
    {


        if(metodo==1)
        {
            unsigned long long *tamano = new unsigned long long;
            char nombre_E[]="natural.txt",nombre_S[]="codificado.dat";
            tam(nombre_S,tamano);
            char *texto=new char[*tamano*8];
            texto=m1_decodificacion(*tamano,semilla,nombre_S,texto);
            escribirM1(texto,nombre_E,*tamano);
            cout<<endl<<texto<<endl;
            delete[] texto;
            delete tamano;

        }
        else
        {   unsigned long long *tamano = new unsigned long long;
            string texto,nombre="natural.txt";

            cout<<endl<<texto<<endl<<endl;
            //m2_codificacion(*tamano,semilla,"codificacion.dat",texto);
            texto=m2_decodificacion(tamano,semilla,"codificado.dat");
            escribirM2(texto,nombre);

            delete tamano;
        }
    }

    return 0;
}










