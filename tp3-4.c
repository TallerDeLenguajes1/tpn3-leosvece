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

void cargarcliente(cliente **C, int per);
void cargarproductos(cliente **C, int per);
void mostrar(cliente **C, int a);
void calcularproducto(int cantidad, int precio,int i);


int main(){

    cliente *clien;
    int num, i=0;
    srand(time(NULL));
    
	printf("Numeros de visitas: ");
    scanf("%d",&num);
    fflush(stdin);
    
	clien = (cliente*)malloc((num+1)*sizeof(cliente));
	if (clien== NULL){
		printf("espacio insuficiente");
	}
	
	for(i=0;i<num;i++){
		cargarcliente(&clien,i);
		cargarproductos(&clien,i);
	}
	
    mostrar(&clien,num);
	free(clien);

	return 0;
}

void cargarcliente(cliente **C, int per){
	cliente *c = *C;
	char nombre[100];
	printf("ingrese el nombre del %d cliente: ",per+1);
	gets(nombre);
	c[per].NombreCliente = (char*)malloc(strlen(nombre)*sizeof(char));
	if (c[per].NombreCliente== NULL){
		printf("espacio insuficiente");
	}
	strcpy(c[per].NombreCliente,nombre);
	c[per].ClienteID = per;
	c[per].CantidadProductosAPedir=1+ rand()% 5;

}
/*
void cargarproductos(cliente **C, int per){ //prueba para ver si salia bien
	cliente *c = *C;
	char *tiposProductos[]={"Galletas","Snack","Cigarrillos","Caramelos","Bebidas"};
	int i,j;
	c[per].Productos = malloc((c->CantidadProductosAPedir)*sizeof(c[per].Productos));
	
	if (c[per].Productos == NULL){
		printf("espacio insuficiente");
	}

		c[per].Productos->ProductoID = per;
		j = rand()%5;
		c[per].Productos->TipoProducto = (char*)malloc((strlen(tiposProductos[j])+1)*sizeof(char));
		if (c->Productos->TipoProducto == NULL){
					printf("espacio insuficiente");
				}
		strcpy (c[per].Productos->TipoProducto,tiposProductos[j]);
		c[per].Productos->Cantidad = rand() %10+1;
		c[per].Productos->PrecioUnitario =10 + rand() % (100-10); 
}

*/


void cargarproductos(cliente **C, int per){
	cliente *c = *C;
	char *tiposProductos[]={"Galletas","Snack","Cigarrillos","Caramelos","Bebidas"};
	int i,j;
	c[per].Productos = malloc((c[per].CantidadProductosAPedir)*sizeof(c[per].Productos));
	
	if (c[per].Productos == NULL){
		printf("espacio insuficiente");
	}
	
	for(i=0;i<c[per].CantidadProductosAPedir;i++){
		c[per].Productos[i].ProductoID = per;
		j = rand()%5;
		c[per].Productos[i].TipoProducto = (char*)malloc((strlen(tiposProductos[j])+1)*sizeof(char));
		if (c[per].Productos[i].TipoProducto == NULL){
					printf("espacio insuficiente");
				}
		strcpy(c[per].Productos[i].TipoProducto,tiposProductos[j]);
		c[per].Productos[i].Cantidad = rand() %10+1;
		c[per].Productos[i].PrecioUnitario =10 + rand() % (100-10); 
	}
		
}


void mostrar(cliente **C,int a){
	cliente *c = *C;
	int i=0,j;
	float total;
	
	for(i=0; i < a;i++){
		total =0;		
		printf("\nEl ID del cliene: %d", c[i].ClienteID);
		printf("\nNombre del cliente: %s",c[i].NombreCliente);
		printf("\nCantidad de productos a Pedir: %d",c[i].CantidadProductosAPedir);
		
		for(j=0;j<c[i].CantidadProductosAPedir;j++){
		printf("\nEl producto pedido es: %s",c[i].Productos[j].TipoProducto);
		printf("\nEl ID del producto es: %d",c[i].Productos[j].ProductoID);
		printf("\nLa cantidad del productos: %d",c[i].Productos[j].Cantidad);
		printf("\nPrecio por unidad: %2.f",c[i].Productos[j].PrecioUnitario);
		printf("\n");
		total = (c[i].Productos[j].Cantidad * c[i].Productos[j].PrecioUnitario) + total;
		}
		printf("el total a pagar: %f\n\n",total);	
	}
	
}	


