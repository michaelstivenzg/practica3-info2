#ifndef FUNCIONES_H
#define FUNCIONES_H


#include <iostream>
#include <fstream>
#include <math.h>
#include <string>
#include <cstdlib>
#include <cstring>



#include "metodo_1.h"



using namespace std;

int COD();
void implementacion(unsigned long int*,unsigned short int*);


//metodo I
void m1_codificacion(unsigned long long int  ,unsigned long int ,char* ,char* );
void m1_decodificacion(unsigned long long int ,unsigned long int ,char *,char *);
void tam(char* ,unsigned long long *);
char* lecturaM1(char*,unsigned long long );
char *traduccionM1(unsigned long long, char *);
char* binarioM1(unsigned long long,char *);
void metodo1(char* ,unsigned long long ,unsigned long ,unsigned long ,unsigned long ,unsigned long long );
void r_metodo1(char* ,unsigned long long ,unsigned long ,unsigned long ,unsigned long ,unsigned long long );
void sentencia(unsigned long,unsigned long,int8_t*);
void escribirM1 (char *,char *);
//metodo II

void m2_codificacion(unsigned long long int ,unsigned long int,string,string);
string m2_decodificacion(unsigned long long int *,unsigned long int,string);
string lecturam2(string,unsigned long long*);
string bin_m2( unsigned int );
string metodo2(string,unsigned long long,unsigned long int,unsigned long int);
string traduccionM2(unsigned long long int tamano, string bina);
void escribirM2 ( string ,string );
string r_metodo2(string , unsigned long long , unsigned long int  ,unsigned long int );



// cajero

void administrador(string,string);

#endif // FUNCIONES_H
