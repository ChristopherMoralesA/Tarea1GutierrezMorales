#include "pthread.h"  // Inclusión de la distintas bibliotecas necesarias para la prueba 
#include <iostream>   
#include <stdio.h>
#include <stdlib.h>
#include <chrono>

using namespace std;  

const int i = 4000000; // definición del tamaño del tamaño del arreglo

pthread_t thread0, thread1, thread2, thread3, thread4;    //Declaración de los 5 hilos necesarios 

int Arreglo [i]; // Creación del arreglo de numeros 
int cuad0 = 0;      
int cuad1 = 0;
int cuad2 = 0; // Creación de las distintas variables dinamicas en las que se calcula las potencias
int cuad3 = 0;
int cuad4 = 0;
	
void arr_init()  // Función que crea un array con numeros aleatorios 
{
	for(int j=0; j<i; j++)
	{
		Arreglo[j] = rand()%100; // Función random que crea numeros de 0 a 100
	}
}

void *pot(void *arg) //Función que se encarga de elevar cada elemento del array al cuadrado
{
	int val = *((int*)arg); //Asigna a "val" el valor tipo "int" apuntado por *arg
	switch (val)
	{
	case 0: // Caso para que solo un hilo realice todo el recorrido 
		for (int a=0; a<i; ++a)
		{
			cuad0 = Arreglo[a]*Arreglo[a];
		}
		return NULL;
	case 1: // Caso para que un hilo recorra el primer cuarto del recorrido total 
		for (int b=0; b<1000000; ++b)
		{
			cuad1 = Arreglo[b]*Arreglo[b];
		}
		break;
	case 2: // Caso para que otro hilo recorra el segundo cuarto del recorrido total 
		for (int c=1000000; c<2000000; ++c)
		{
			cuad2 = Arreglo[c]*Arreglo[c];
		}
		break;
	case 3: // Caso para que otro hilo recorra el tercer cuarto del recorrido total
		for (int d=2000000; d<3000000; ++d)
		{
			cuad3 = Arreglo[d]*Arreglo[d];
		}
		break;
	case 4: // Caso para que otro hilo recorra el último cuarto del recorrido total
		for (int e=3000000; e<i; ++e)
		{
			cuad4 = Arreglo[e]*Arreglo[e];
		}
		break;

	}
	return NULL;
}

using namespace std::chrono;
int main() //Menú principal del programa
{
	int value0 = 0; 
	int value1 = 1;
	int value2 = 2; //Definición del las variables de cada subproceso 
	int value3 = 3;
	int value4 = 4;
	
	arr_init(); // Llama a la función para generar el array con elementos aleatorios 

	auto start1 = high_resolution_clock::now(); // Marca el momento que inicia el recorrido con cuatro hilo
	pthread_create(&thread1, NULL, pot, &value1);
	pthread_create(&thread2, NULL, pot, &value2);  //Crea cada uno de los hilos e los envia a ejecutar sus respectiva rutinas 
	pthread_create(&thread3, NULL, pot, &value3);
	pthread_create(&thread4, NULL, pot, &value4);
	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);  //Une el proceso de de los hilos al proceso general 
	pthread_join(thread3, NULL);
	pthread_join(thread4, NULL);
	auto stop1 = high_resolution_clock::now(); // Marca el momento que finaliza el recorrido con cuatro hilo
	auto duration1 = duration_cast<microseconds>(stop1 - start1); // Calculo del tiempo de recorrido total en microsegundos
	cout << "con 4 hilos tardo: " << duration1.count() << endl; // Muestra en pantalla el tiempo del proceso con cuatro hilos 


	auto start2 = high_resolution_clock::now(); // Marca el momento que inicia el recorrido con un hilo
	pthread_create(&thread0, NULL, pot, &value0); //Crea el hilo e los envia a ejecutar su respectiva rutina 
	pthread_join(thread0, NULL); //Une el proceso del hilo al proceso general
	auto stop2 = high_resolution_clock::now(); // Marca el momento que finaliza el recorrido con un hilo
	auto duration2 = duration_cast<microseconds>(stop2 - start2); // Calculo del tiempo de recorrido total en microsegundos
	cout << "con 1  hilo tardo: " << duration2.count() << endl; // Muestra en pantalla el tiempo del proceso con un hilo

	return 0;
};
