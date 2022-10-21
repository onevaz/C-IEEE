#include <cstring> // se usa para arreglos de tipo char y es de c 
#include <conio.h> // se usa para comandos getch clrscr gotoxy textcolor textbackground
#include <iostream> // permite la entrada y salida de datos 
#include <stdint.h> // define los tamaños de tipo entero 



using namespace std;

struct BIT_RECEIVE_PACKET //creamos la estructura que almacenara nuestra informacion de los metodos de la libreria
{
	 uint16_t MAC;
	 uint8_t LENGTH;
	 uint8_t OPTION;
	 uint8_t RSSI;
	 string PAYLOAD;
	 bool CHECKSUM;
};

BIT_RECEIVE_PACKET f;
	
#include <C:/Users/52312/Documents/Dev C++/iEEE_802_15_4.h>// incluye la libreria que creamos //

int opcion;// es la variable que usamos para la selecion del menu
	

int main(){

	while(opcion!=7)//repite un ciclo del menu hasta que el usuario seleccione la opcion de salir
	{
	cout<<"Elige lo que quieras de esta trama de IEEE 802.15.4"<<endl;
	cout<<"Obtener MAC de Destino [1]\nObtener la logitud [2]\nObtener el tipo de mensaje[3]\n";
	cout<<"Obtener Calidad de la Seña [4]\nObtener el Mensaje Oculto [5]\nChequeo de Mensaje [6]\nSalir[7]"<<endl;
	cin>>opcion;
switch (opcion)
		{
	case 1://al seleciona la opcion 1 nos regresara la mac de nuestra trama
		GET_MAC();
		cout<<"La direccion es\n0x";
		printf("%x\n",f.MAC);
		break;
		
	case 2://al seleciona la opcion 1 nos regresara la longitud de nuestra trama	
		GET_LENGTH();
		cout<<"Tu longitud es ";
		cout<<((int)f.LENGTH);
		cout<<"\n";
		break;
		
	case 3://al seleciona la opcion 1 nos regresara el tipo de nuestra trama
		GET_OPTION();
		if (f.OPTION=!0x81){
			
			cout<< "la trama cambio";
			
		} 
		else{
			cout<< "la trama es 16-bit receive packet 0x81\n";
		}
		break;
		
	case 4://al seleciona la opcion 1 nos regresara la intensidad de la señal de nuestra trama
		GET_RSSI();
		cout<<"Tu senial es de -";
		cout<<((int)f.RSSI)<<"dm\n"; 
		break;
		
	case 5://al seleciona la opcion 1 nos regresara el mensaje oculto de nuestra trama
		GET_PAYLOAD();
		cout<<"Tu mensaje es\n";
		cout<<f.PAYLOAD<<"\n";
		break;
	
	case 6://al seleciona la opcion 1 nos regresara la valoracion de la salud de nuestra trama
		GET_CHECKSUM();
		if (f.CHECKSUM == true){
			cout<<"Tu trama esta bien\n";
		}
		else{
			cout<<"Tu trama esta danada\n";
		} 
		break;
		}
	}
return 0;
}
