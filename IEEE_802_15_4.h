uint8_t multiple[]={0x7E,0x00,0x35,0x81,0x11,0x11,0x13,0x01,0x45,0x73,0x74,0x65,0x20,0x65,0x73,0x20,0x65,0x6C,
0x20,0x65,0x71,0x75,0x69,0x70,0x6F,0x20,0x31,0x20,0x64,0x65,0x20,0x35,0x43,0x20,0x79,0x20,0x73,0x61,0x62,0x65,
0x6D,0x6F,0x73,0x20,0x70,0x72,0x6F,0x67,0x72,0x61,0x6D,0x61,0x72,0x20,0x65,0x6E,0x20,0x43,0x2B,0x2B,0x0F};
//esta es nuestra trama con la cual estaremos trabajando 


int lon = sizeof(multiple)/sizeof(multiple[0]); //declaramos una var global que es la longitud de nuesta trama
//declaramos nuestra funcion mac de nuestra clase
uint16_t GET_MAC(){              
	uint16_t v= multiple[4]*256+multiple[5];
	f.MAC = v;
	} 
//declaramos nuestra funcion de longitud  de nuestra clase  
uint8_t GET_LENGTH(){; 
	f.LENGTH = multiple[1]+multiple[2];
	
	}
//declaramos nuestra funcion para que nos regrese el tipo a nuestra instancia de estructura de nuestra clase
uint8_t GET_OPTION(){
	 f.OPTION = multiple[3];
	}
//declaramos nuestra funcion de RSSI que es la intensidad de la señal 
uint8_t GET_RSSI(){
	f.RSSI = multiple[6];         
	}
//declaramos nuestra funcion que nos muestra nuestro mensaje oculto 
uint8_t GET_PAYLOAD(){
	cout<<"\n";
	int i=7;
					//en el ciclo usamos nuestra variable global
	while(i<lon-2){//hacemos un ciclo while para ir guardando los caracteres de la trama en un sting de nuesta estructura
	i++;
	f.PAYLOAD+=multiple[i];
		}
	cout<<"\n";
	}
//declaramos nuestra funcion que nos evalua si es cierto o falso la calidad de la trama
uint8_t GET_CHECKSUM(){
	int i=3;
	uint8_t s=0;
	int r= (int(0xFF));
	while (i<lon) //hacemos un ciclo que nos vaya sumando cada valor de nuestra tramma desde la posicion 3
	//en el ciclo usamos nuestra variable global
	{
		s+=(multiple[i]);
		i++;
	}
	if(r-s==multiple[lon-1]){//evaluamo si nuesta resta es igual al ultimo valor de nuestra trama
	f.CHECKSUM = true;
	}
	else //si no es el caso anterior en nustra estructura f se guardara un false
	f.CHECKSUM = false;
}
	

//};