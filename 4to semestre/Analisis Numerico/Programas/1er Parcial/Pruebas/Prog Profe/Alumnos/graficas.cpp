
/*
grafica de una funcion cartesiana
*/


//Directivas del preprocesador para incluir archivos de cabecera
#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <math.h>

//Constantes simbolicas predefinidas del programa
#define PUNTOS 250
#define DELTAX 0.001


//prototipos de las funciones usadas por el programa
void Ejes(void);
void Texto(void);
void Limites(void);
void GraficaF(void);
void GraficaG(void);
void Inicializar(void);
void Linea(float, float, float, float);


//Variables globales usadas por el programa
float x1,y1,x2,y2,mx,my,bx,by,factor;


// funcion principal del programa
int main(void)
{
   Limites();
   Inicializar();
   Ejes();
   Texto();
   GraficaF();
   GraficaG();
   getch();
   closegraph();
   return 0;
}


// funcion con el codigo de la funcion que se desea graficar
float f(float x)  
{
   return x*x*x - 5*x*x + x + 5;
}


// funcion para calcular el valor numerico de la derivada en un punto
float g(float x)  
{
   return (f(x+DELTAX)-f(x))/DELTAX;
}


int Xabs(float Xrel)  //
{
   return mx * Xrel + bx;
}


int Yabs(float Yrel)
{
   return my * Yrel + by;
}


// funcion para trazar un recuadro y los ejes coordenados
void Ejes(void) 
{
   int xmax = getmaxx(),
       ymax = getmaxy();

   mx =  xmax/(x2-x1);
   bx = -mx*x1;
   my = -ymax/(y2-y1);
   by = -my*y2;
   factor = 1;
   setcolor(LIGHTBLUE);
   rectangle(0,0,xmax,ymax);
   Linea(x1,0,x2,0);
   Linea(0,y1,0,y2);
}


//funcion para incluir un texto descriptivo dentro de la grafica
void Texto(void) 
{
   char cDominio[40],cRango[40];
   setcolor(YELLOW);
   settextstyle(TRIPLEX_FONT,HORIZ_DIR,2);
   outtextxy(100,20,"GRAFICA DE UNA FUNCION Y SU DERIVADA");
   setcolor(GREEN);
   settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
   sprintf(cDominio,"Dominio [%5.2f,%5.2f]",x1,x2);
   sprintf(cRango,"Rango [%5.2f,%5.2f]",y1,y2);
   outtextxy(40,80,cDominio);
   outtextxy(40,100,cRango);
}


// funcion para leer el dominio y rango de graficacion
void Limites(void)  
{
   clrscr();
   printf("\nDame el limite inferior de graficacion en x ");
   scanf("%f",&x1);
   printf("\nDame el limite superior de graficacion en x ");
   scanf("%f",&x2);
   printf("\nDame el limite inferior de graficacion en y ");
   scanf("%f",&y1);
   printf("\nDame el limite superior de graficacion en y ");
   scanf("%f",&y2);
}


//trazo de una linea de un punto inicial a otro final (relativo)
void Linea(float x1, float y1, float x2, float y2)
{
   int Xabs(float);
   int Yabs(float);

   line(Xabs(factor*x1),Yabs(y1),Xabs(factor*x2),Yabs(y2));
}


// Funcion para visualizar la grafica de la funcion
void GraficaF(void) 
{
   float f(float);

   float i = x1,
	dx = (x2-x1)/PUNTOS;

   setcolor(WHITE);
   for (i=x1; i<=x2-dx; i+=dx)
      Linea(i,f(i),i+dx,f(i+dx));
}


// Funcion para visualizar la grafica de la derivada
void GraficaG(void) 
{
   float g(float);

   float i = x1,
	dx = (x2-x1)/PUNTOS;

   setcolor(MAGENTA);
   for (i=x1; i<=x2-dx; i+=dx)
      Linea(i,g(i),i+dx,g(i+dx));
}


//rutina para verificar si se puede iniciar el modo grafico
void Inicializar(void)
{
   int tarjeta,modo,error;
   tarjeta = DETECT;
   initgraph(&tarjeta,&modo,"c:\\tc\\bgi");
   error = graphresult();
   if (error != grOk)
   {
      printf("No se puede graficar\n");
      printf(grapherrormsg(error));
      getch();
      exit(1);
   }
}


