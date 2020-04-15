#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct pc {
    int velocidad, anio, nucleos;
   char *tipo; 
}compu;

void cargar(compu *PC, int c);
void ordenar(compu *a, compu *b, compu PC);
void lista(compu *PC, int cantidad);
void anio(compu *PC, int cantidad);
void velocidad(compu *PC, int cantidad);

int main(){
	int i, cantidad, cont=0,x=1;
	int busqueda= 0;
	char a[10];
	compu *PC;
	
	printf("CARGUE LOS DATOS DE LA COMPUTADORA ");
	printf("\n\ningrese la cantidad de PC que hay: ");
	scanf("%d",&cantidad);
	
	PC = (compu*)malloc((cantidad)*sizeof(compu));
	if (PC== NULL){
		printf("espacio insuficiente");
	}
	
	do{
		//podria crear el vector dinamico dentro de la funcion para optimizar... pasta
		PC[cont].tipo = (char*)malloc((strlen(a)+1)*sizeof(char));
	if( PC[cont].tipo == NULL){
		printf("memoria insuficiente");
	}
		cargar(PC, cont);
		system("cls");
		cont++;
	}while(cont <cantidad);
	
	printf("¿desea buscar algo del inventario? \n1)SI	2)NO\n");
	scanf("%d",&x);
	fflush(stdin);
	
	do{
		system("cls");
		printf("seleccione:\n1- Busqueda por lista \n2- Busqueda por antiguedad \n3- Busqueda velocidad\n");
		scanf("%d",&busqueda);
		system("cls");
		if(busqueda==1){
			lista(PC,cantidad);
		}
		else if(busqueda==2){
			system("cls");
			anio(PC,cantidad);
		}
		else{
			system("cls");
			velocidad(PC,cantidad);
		}
		
		puts("¿desea buscar otro cosa?\n1)SI	 2)no\n");
		scanf("%d",&x);
	}while(x==1);
	
    return 0;
}
// cargar datos
void cargar(compu *PC, int c){
	int i, selec=0;
	
	char tipos[6][10]={"Intel","AMD","Celeron","Athlon","Core","Pentium"},a[10];
	
	do{
		printf("seleccione el tipo de procesador\n");
		for (i=0; i<6;i++){
 	 	  printf("%d)- %s\n",i+1, tipos[i]);
		}
		scanf("%d",&selec);
		
		if (selec <= 0 || selec > 6){
			printf("seleccion incorrecta");
		}
		
		strcpy(a,tipos[selec-1]);
			
	}while(selec <1 || selec >= 7);	
	
	strcpy(PC[c].tipo,a);
	printf("\nvelocidad del procesador:");
	scanf("%d",&PC[c].velocidad);
	printf("anio de fabricacion:");
	scanf("%d",&PC[c].anio);
	printf("Cantidad de nucleos:");
	scanf("%d",&PC[c].nucleos);
}
//muestra la estructura
void lista(compu *PC, int cantidad){
	int i;
	for(i=0;i<cantidad;i++){
		printf("NOMBRE: %s\n",PC[i].tipo);
		printf("Anio: %d\n",PC[i].anio);
		printf("CANT. NUCLEOS: %d\n",PC[i].nucleos);
		printf("VELOCIDAD: %d\n",PC[i].velocidad);		
		}
		
}

//ordenar la estructura para mostrarla

void anio(compu *PC, int cantidad){
	int i,j;
	
	for(i=0;i<cantidad;i++){
		for(j=1;j<cantidad;j++){
			if(PC[i].anio < PC[j].anio){
				ordenar(&PC[i],&PC[j], *PC);
			}
		}
	}
	printf("Desde el mas nuevo al mas viejo:\n");
	lista(PC, cantidad);
}

void velocidad(compu *PC, int cantidad){
	int i,j;
	
	for(i=0;i<cantidad;i++){
		for(j=1;j<cantidad;j++){
			if(PC[i].velocidad>PC[j].velocidad){
				ordenar(&PC[i],&PC[j], *PC);
			}
		}
	}
	printf("Desde el mas lento al mas rapido:\n");
	lista(PC, cantidad);
}

void ordenar(compu *a, compu *b, compu PC){
	compu  aux;
	aux = *a;
	*a = *b;
	*b = aux;
}

