#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

typedef struct producto {
    int ProductoID; //Numerado en ciclo iterativo
    int Cantidad; // entre 1 y 10
    char *TipoProducto; // Algun valor del arreglo TiposProductos
    float PrecioUnitario; // entre 10 - 100
}p;

typedef struct Cliente {
    int ClienteID; // Numerado en el ciclo iterativo
    char *NombreCliente; // Ingresado por usuario
    int CantidadProductosAPedir; // (alteatorio entre 1 y 5)
    p *Productos; //El tamanio de este arreglo depende de la variable
    // â€œCantidadProductosAPedirâ€
}cliente;

void cargar(cliente **C, int per);
void mostrar(cliente **C, int a);

int main(){

    cliente *clien;
	char *tiposProductos[]={"Galletas","Snack","Cigarrillos","Caramelos","Bebidas"};
    int num, i=0;
    srand(time(NULL));
    
	printf("Numeros de visitas:");
    scanf("%d",&num);
    fflush(stdin);
    
	clien = (cliente*)malloc((num+1)*sizeof(cliente));
	if (clien== NULL){
		printf("espacio insuficiente");
	}
	
	while(i<num){
		cargar(&clien,i);
		fflush(stdin);
		i++;
		system("cls");	
	}
    mostrar(&clien,num);
    return 0;
}

void cargar(cliente **C, int per){
	srand(time(NULL));
	char nombre[10], aux[12];
	char *tiposProductos[]={"Galletas","Snack","Cigarrillos","Caramelos","Bebidas"};
	int a=1,i,j=0;
	cliente *c = *C;
	printf("ingrese el nombre del %d cliente: ",per+1);
	gets(nombre);
	c->NombreCliente = (char*)malloc(strlen(nombre)*sizeof(char));
	if (c->NombreCliente== NULL){
		printf("espacio insuficiente");
	}
	strcpy(c->NombreCliente,nombre);
	printf("ingrese ID del cliente: ");
	scanf("%d",c->ClienteID);
	//printf("\nla cantidad pedida es %d: ",c->CantidadProductosAPedir=rand()%6);
	c->CantidadProductosAPedir=rand()%5+1;
	c->Productos = malloc((c->CantidadProductosAPedir)*sizeof(c->Productos));
	//c->Productos = (c->Productos*)malloc((c->CantidadProductosAPedir)*sizeof(c->Productos));//no crea la memoria
	
	while(j <= c->CantidadProductosAPedir){
	
		printf("seleccione el nombre del producto\n");
		
		do{
			
			for(i=0;i<5;i++){
				printf("%d)- %s\n",i+1,tiposProductos[i]);
			}
			scanf("%d",&a);
			if(a<1 || a>5){
				printf("numero incorrecto, seleccione de nuevo\n");
			}else{
				strcpy(aux,tiposProductos[a]);
				//printf("%s",aux);
				//c->Productos->TipoProducto = (char*)malloc((strlen(aux)+1)*sizeof(char));
				c->Productos->TipoProducto = (char*)malloc((strlen(aux)+1)*sizeof(char));
				if (c->Productos->TipoProducto == NULL){
					printf("espacio insuficiente");
				}
				strcpy(c->Productos->TipoProducto,aux);
				//printf("%s",c->Productos->TipoProducto);
			}
		}while(a<1 || a>5 );
		printf("ingrese el ID del producto: ");
		scanf("%d",&c->Productos->ProductoID);
		c->Productos->Cantidad = rand() % 5 +1;
		printf("precio por unidad: ");
		scanf("%f",&c->Productos->PrecioUnitario);
		j++;
		system("cls");
		*(c->Productos+j);
	}
	c++;
	
}

void mostrar(cliente **C,int a){
	cliente *c = *C;
	int i=0,j;
	
	for(i=0;i<a;i++){
		//los productos que si guardan los datos son
		printf("\nEl ID del cliene: %d", c->ClienteID);//no
		printf("\nNombre del cliente: %s",c->NombreCliente);//si
		printf("\nCantidad de productos a Pedir: %d",c->CantidadProductosAPedir);//si
		
		for(j=0;j<c->CantidadProductosAPedir;j++){
			printf("\nEl producto pedido es: %d",c->Productos->TipoProducto);//no
			printf("\nEl ID del producto es: %d",c->Productos->ProductoID);//no
			printf("\nLa cantidad del productos: %d",c->Productos->Cantidad);//no
			printf("\nPrecio por unidad: %2.f",c->Productos->PrecioUnitario);//no
			*(c->Productos+j);
		}
		*(c++);
	}
}