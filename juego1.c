#include <stdio.h>
#include <time.h>
#include <stdlib.h>
//1)-6) dibujar el tablero con numeros y lineas-complilacion Ok
//7) marcar el numero seleccionado con X, si compilo ok
//8) funcionamieneto del rival.
//para realizarla uso time.h que funciones aleatorios- no funciono, faltaba stdlib p276 y si OK
//9)modificacion de funcion loop para ejecutar juego jugador vs rival
//10) funcion para declarar al ganador. Juego funciona pero aun tengo el problema que en la 1ra jugada
//se queda el mensaje de "colocar una ficha"
void loop (char c[3][3]);
//3)declaracion de la funcion loop con prototipo
//declaracion sin prototipo: void loop();
void Intro_Primera(char c[3][3]);
//5) declaramos la funcion con su prototipo
//prototipo del 6)
void tablero(char c[3][3]);
//prototipo del 7)
void Intro_Yo(char c[3][3]);
//prototipo del 8)
void Intro_IA(char c[3][3]);
//prototipo del 10)
int ganador(char c[3][3]);
int	main()
{
	char c[3][3];
	//1)matriz 3 por 3 que sera el tablero y se le pasa a cada funcion
	//crearemos una funcion "loop", que es un bucle, y le pasamos "c"
	//llamara a las funciones fundamentales del juego y hara un refresco de la pantalla
	loop(c);
	return 0;
}
//2)luego de escribir el loop en el main,creamos la funcion loop del tipo void (traduccion:vacio)
//esta funcion loop se encargara de llamar a las funciones fundamentales del juego
//void : este tipo de funcion se puede utilizar donde no sea requerido el valor p220
void loop (char c[3][3]){
/*	Intro_Primera(c);
	tablero(c);
	Intro_Yo(c);
	tablero(c);
	Intro_IA(c);
	tablero(c);
*/
//9)ponemos como comentario el contenido hecho en loop de 1-8
	//creamos un contador de jugadas, solo son maximas 9 por tener 9 casillas
	int i,j; //j la declaramos al hacer 10.1
	i = 0;
	//hacemos do para que el bucle se repita mientras que
	Intro_Primera(c);
	//tablero(c); //En 9.3 reacomodamos dentro del do
	do
	{
		system("clear"); //9.1 Borra todo lo que hay en pantalla, p184 y tbn p277
		//ahora haremos los turnos, consideramos que primero es el jugador
		//si el primer turno es mio, y serian los turnos 0 2 4 6 8 todos pares y 
		//al ser pares si son divididos entre 2 el residuo siempre sera cero (y somos dos usuarios que juegan)
		//9.3 para que se vea el tablero luego del clear
		tablero(c);
		if(i % 2 == 0){
			Intro_Yo(c);
		}else{
			Intro_IA(c);
		}
		j = ganador(c); // 10.1 cada vez que suceda el do vamos a ver si hemos ganado
		i++; //9.2 aumenta uno a uno la variable i (limitado por la cantidad de casillas, el 9 en while)
	} while ( i <= 9 && j == 2);// 10.2 añadi j.se siga haciendo el juego porque j no es 1 o 0, que es donde hay un ganador
	//10.2 saber si alguien gano o empate
	//10.3 al compilar no marca la ultima X o O del ganador entonces nuevamente system y tablero:
	system("clear");
	tablero(c);
	if(j == 0){
		printf("Haz ganado!\n");
	}else if(j == 1){
		printf("Haz perdido!\n");
	}else{
		printf("Han empatado!\n");
	}
}
//4creamos las funciones fundamentales del juego
/*Intro_Primera dara los valores a la matriz
mostrara los numeros del tablero, usaremos dos bucles por eso necesitamos dos variables
El tablero sera de 3 por 3 entonces el primero y segundo for debe ser como el escrito
creamos una variable del tipo caracter llamado "auxiliar"
auxiliar comenzara con el caracter (un numero en este caso) 1
Y en los fors sera el inicial ese uno pero aumentara una cantidad hasta lo limitado por los fors
*/
void Intro_Primera(char c[3][3]){
	int i,j;
	char aux; //auxiliar
	aux = '1'; 
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
			{
				c[i][j] = aux++;
			}	
	}

}
//6 siguiente funcion fundamental del juego: dibujar el tablero 
/*
Para dibujar el tablero necesitamos recorrer los fors, como el caso anterior, nuevamente
creamos las variables dos variables
1|2|3| pero con el if 1|2|3
luego falta dibujar la linera horizontal, entonces, nos ubicamos fuera del primer for y escribimos
la linea: ---- porque es: (espacio)caracter(espacio)vertical //repetido solo dos veces porque el ultimo
// es (esoacio)caracter(espacio) entonces: ---
en total son son once //%c indica el numero y su posicion
pero ese conjunto de lineas horizontales (son 3) dibuja la ultima y solo son dos centrales entonces aplico
if, similar al caso anterior de las verticales. En esta ocacion es la i quien valida, y no consideramos
un else porque no queremos que haga algo al final de esa horizontal que no cumple la condicion

*/
//7) funcion donde el jugador introduce los valores a la tabla de juego
/*
creamos dos do, en el primero solicitamos al jugador ingresar el valor de la ficha a marcar
mientras que se respete los numeros disponibles 1-9 y declaramos la variable al inicio de la funcion
Evaluamos cada caso segun el valor seleccionado por el jugador con el switch/case
las variables i son las verticales y las j los horizontales no olvidarse
  0 1 2
0 1|2|3
  -----
1 4|5|6
  -----
2 7|8|9

*/
void Intro_Yo(char c[3][3]){	
	int i,j,k; //7.6, k lo escribimos/declaramos luego de hacer el case
	char aux;
	do
	{
		do
		{
			printf("Coloca una ficha: ");//7.1 do
			fflush(stdin);//no deberia funcionar,segun comentarios en internet xq no es de gnu linux,
			//ver si mas adelante influye en algo. p266. investigar.
			//(sin fflush funciona igual.)
			//OJO: EL 1ER COLOCA UNA FICHA SE MANTIENE AL SEGUIR LAS JUGADAS, PUEDE SER ERROR DE ESTE FFLUS
			//SERA POR NO PONER PAUSE EN EL MAIN? TODO LO DEMAS DEL CODIGO ES IGUAL AL VIDEO
			scanf("%c",&aux);
		} while (aux < '1' || aux > '9');//7.2 ingresar un numero.ojo:podria mejorar este while
			k = 0 ; // se escribe luego de declarar la variable  en int, sabemos que k en algun momento
			//sera diferente a uno entonces usamos el numero cero en esta situacion.
		switch(aux){
			//7.3 case, con la seleccion de algun numero entre 1 y 9 usado en el while anterior
			case '1':{
				i = 0;
				j = 0;
				//7.4 si la celda seleccionada contiene X o O la variable k sera 1 y la usare mas abajo
				if (c[i][j] == 'X' || c[i][j] == 'O')
				{
					k = 1;
					printf("Por favor ingresar otro numero\n");
				}
				break;
			}
			//7.8 pasamos a copiar cada case hasta el 9:
			//modificando el case 'numero nuevo' y valor de ij de ser necesario segun ubicacion horizontal/vertical
			case '2':{
				i = 0;
				j = 1;				
				if (c[i][j] == 'X' || c[i][j] == 'O')
				{
					k = 1;
					printf("Por favor ingresar otro numero\n");
				}
				break;
			}
			case '3':{
				i = 0;
				j = 2;				
				if (c[i][j] == 'X' || c[i][j] == 'O')
				{
					k = 1;
					printf("Por favor ingresar otro numero\n");
				}
				break;
			}
			case '4':{
				i = 1;
				j = 0;				
				if (c[i][j] == 'X' || c[i][j] == 'O')
				{
					k = 1;
					printf("Por favor ingresar otro numero\n");
				}
				break;
			}
			case '5':{
				i = 1;
				j = 1;				
				if (c[i][j] == 'X' || c[i][j] == 'O')
				{
					k = 1;
					printf("Por favor ingresar otro numero\n");
				}
				break;
			}
			case '6':{
				i = 1;
				j = 2;				
				if (c[i][j] == 'X' || c[i][j] == 'O')
				{
					k = 1;
					printf("Por favor ingresar otro numero\n");
				}
				break;
			}
			case '7':{
				i = 2;
				j = 0;				
				if (c[i][j] == 'X' || c[i][j] == 'O')
				{
					k = 1;
					printf("Por favor ingresar otro numero\n");
				}
				break;
			}
			case '8':{
				i = 2;
				j = 1;				
				if (c[i][j] == 'X' || c[i][j] == 'O')
				{
					k = 1;
					printf("Por favor ingresar otro numero\n");
				}
				break;
			}
			case '9':{
				i = 2;
				j = 2;				
				if (c[i][j] == 'X' || c[i][j] == 'O')
				{
					k = 1;
					printf("Por favor ingresar otro numero\n");
				}
				break;
			}
		}

	} while ( k == 1);//7.5, mientras el usuario sigue escribiendo un numero ya seleccionado
	c[i][j] = 'X'; //7.7,valor ij sera X


}
//8)funcinamiento de rival
void Intro_IA(char c[3][3]){
	int i,j,k; //creamos dos numero aleatorios8.2 (i,j) luego k al hacer if dentro del do
	srand(time(NULL));
	// 8.1 acabamos de generar arriba, algo llamado semilla p51 p276
	//i = rand() % 3; // 8.2 un numero aleatorio que puede ser 0, 1 o 2 p276
	//j = rand() % 3; 
	//8.3 hay que comprobar que las casillas seleccionadas no esten repetidas, hacemos un do similar lineas arriba
	//8.4 i y j con rand lo ingresamos en el do	
	do
	{
		i = rand() % 3; 
		j = rand() % 3;	
		k = 0;
		if( c[i][j] == 'X' || c[i][j] == 'O' ){
			k = 1;
		}
	} while (k == 1);
	c[i][j] = 'O';
}
//6)tablero
void tablero(char c[3][3]){
	int i,j;
	for (i = 0; i < 3; ++i)
	{
		for (j= 0; j < 3; ++j)
		{
			//printf(" %c |",c[i][j]); Pero dibuja una linea vertical al final y solo deseamos dos centrales
			if (j < 2)
			{
				printf(" %c |",c[i][j]);
			}else{
				printf(" %c ",c[i][j]);
			}
		}
		//printf("\n-----------\n");// lo ponemos como comentario porque solo deseamos dos centrales
		if (i < 2)
		{
			printf("\n-----------\n");
		}

	}
	printf("\n\n");		
}
//10) hacemos funcion ganador
//vemos todas las combinaciones posibles de que alguien gane
//usamos el centro(numero 5) y marcamos todas las posibilidades, luego en los extremos de la diagonal y son
//dos ala izquierda (vertical y horizontal) y dos a la derecha(vertical y horizontal) la del centro no consideramos
//porque ya se considero al considerar la del centro. Ubicamos cada posibilidad de exito en la matriz

int ganador(char c[3][3]){	
	//partiendo de la primera casilla superior del lado izquierdo (0,0)
	if(c[0][0] == 'X' || c[0][0] == 'O'){
		//caso de que las casillas horizontales (superior) esten cubiertas por un jugador
		if(c[0][0] == c[0][1] && c[0][0] == c[0][2]){
			if(c[0][0] == 'X'){
				return 0; // 0 entonces jugador ganara
			}else{
				return 1; // 1 entonces AI ganara
			}
		}
		//caso de que las casillas verticales (primera de la izquierda) esten cubiertas por un jugador
		if(c[0][0] == c[1][0] && c[0][0] == c[2][0] ){
			if(c[0][0] == 'X'){
				return 0;
			}else{
				return 1;
			}
		}

	}
	//partiendo de la casilla central donde esta el numero 5
	if(c[1][1] == 'X' || c[1][1] == 'O'){
		//diagonas de izquierda a derecha 1-5-9
		if(c[1][1] == c[0][0]  && c[1][1] == c[2][2]){
			if(c[1][1] == 'X'){
				return 0;
			}else{
				return 1;
			}

		}
		//horizontal del medio
		if(c[1][1] == c[1][0] && c[1][1] == c[1][2]){
			if(c[1][1] == 'X'){
				return 0;
			}else{
				return 1;
			}

		}
		//diagonal 7-5-3
		if(c[1][1] == c[0][2] && c[1][1] ==c[2][0]){
			if(c[1][1] == 'X'){
				return 0;
			}else{
				return 1;
			}
		}
		//vertical del medio
		if(c[1][1] == c[0][1] && c[1][1] ==c[2][1]){
			if(c[1][1] == 'X'){
				return 0;
			}else{
				return 1;
			}
		}
	}
	//empezando del 9
	if(c[2][2] == 'X' || c[2][2] == 'O'){
		//7-8-9
		if(c[2][2] == c[2][0] && c[2][2]== c[2][1]){
			if(c[2][2] == 'X'){
				return 0;
			}else{
				return 1;
			}
		}
		//3-6-9
		if(c[2][2] == c[0][2] && c[2][2]== c[1][2]){
			if(c[2][2] == 'X'){
				return 0;
			}else{
				return 1;
			}
		}

	}
	return 2; //sino ocurre nada(no ganamos ni perdimos)
}

/* podria ser alternativa para fflush
void clean_stdin(void)
{
    int c;
    do {
        c = getchar();
    } while (c != '\n' && c != EOF);
}
*/