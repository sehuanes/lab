#include<iostream>
#include<typeinfo>

using namespace std;

struct Complex
{

double	real;
double	imag;

};

enum state;
float latina_stereo = 100.9;
extern unsigned long int n1; 
const float n2 = 3.1416;
const double n3 = 123456789.987654321123456789567444433321;
short int n4;
const unsigned char letra_a;



void funcion_no_optimizable(void)
{
	volatile unsigned char extr_var;
	if(&extr_var != NULL)
		cout<<"2. Optimizer no debe optimizar a extr_var.."<<endl;
}


void funcion_erronea(void)
{
	double x = 14e12;
	cout<<"3. El valor de x en la funcion erronea es: "<<x<<endl;
}


void tipo_del_resultado(void)
{
	int Int = -45;
	unsigned char Char = 125;
	short Short = 10500;
	float Float = 62.23;
	double Double = 3.8678908e5;
	
	double result = Float * Int + Char + Double - Short;
	cout<<"4. El tipo de dato de result en la funcion resultado es: "<<typeid(result).name()<<endl;
}

   
void declaracion_explicita(void)
{
	double oper_1 = 5678983456.44444444444;
	unsigned long oper_2 = 5e15;
    double result = 0;
	
	result = oper_1 + oper_2;
	cout<<"5. El tipo de dato de result "<<result<<" en la funcion declaracion_explicita es: "<<typeid(result).name()<<endl;
}



void funcion_amiga(void)
{
	
 letra_a = 'A';
}

void funcion_necesitada(void)
{
	
	if(letra_a == 'A')
		cout<<"6. Es el caracter esperado: "<<letra_a<<endl;
	else
		cout<<"Esperando el caracter adecuado..."<<endl;
			
}

void state_machine(void)
{
	unsigned char sm_counter = 0x30;   /* Esta variable debe almacenar un valor entero positivo menor a 256
	                     Ademas el valor de la variable debe conservarse entre llamados de la funcion
						 Inicialice esta variable con el valor 0x30;*/
						 
	/* De aqui en adelante y por el resto de la funcion, no es necesario que modifique nada */
	
	switch (state){
		case INICIAL:
			cout<<"Estado incial de la maquina: SM_COUNTER = "<<++sm_counter<<endl;
			state = PREPARACION;
			break;
		case PREPARACION:
			cout<<"Estado preparacion de la maquina: SM_COUNTER = "<<++sm_counter<<endl;
			state = TRABAJANDO;
			break;
		case TRABAJANDO:
			cout<<"Estado en trabajo de la maquina: SM_COUNTER = "<<++sm_counter<<endl;
			state = FINALIZACION;
			break;
		case FINALIZACION:
			cout<<"Estado en finalizacion de la maquina: SM_COUNTER = "<<++sm_counter<<endl;
			state = INICIAL;
			sm_counter = 0x30;
			break;
		default:
			state = INICIAL;
			sm_counter = 0x30;
			break;
	}			
}

/* 13. Pregunta para profundizar: Suponga que usted declara dos variables int a = -1 y unsigned int b = 2
   Luego suponga que usted compara (en C++) las dos variables para saber cual es mayor. ¿Cuál diria C++ que es la mayor entre a y b?
   ¿Por qué? ¿Cuál sería la forma adecuada de hacer la comparación en C++? */

int main()
{	/* Espacio para declaraciones en la funcion main */
	
	struct Complex complejo;
	
	complejo.real = 1;
	complejo.imag = 2;
	/* De esta linea en adelante usted no debe modificar nada */
	cout<<"1. Complejo es igual a: "<<complejo.real<<((complejo.imag > 0)?"+":"-")<<(abs(complejo.imag))<<"j"<<endl;
	
	funcion_no_optimizable();
	funcion_erronea();
	tipo_del_resultado();
	declaracion_explicita();
	funcion_amiga();
	funcion_necesitada();
	for(int i = 0; i<5; i++)
		state_machine();
	
	return 0;
}

