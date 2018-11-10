//
//  Hotel.c
//  
//
//  Created by Francesca Man Ging and Hugo Wong on 1/11/18.
//
#include <string.h>
#include <stdio.h>

int reservar_habitacion(int habitacion);
void cancelar_reserva(int habitacion);
int habitaciones_ocupadas(int suma);
void calcular_total(int suma, float IVA, float precio_habitacion,float subtotal,float total,float impuesto);
int hotel[50];
int habitacion;
int temp;
int j;
int main()

{   int i,suma=0;
    habitacion =0;
    char opcion;
    float IVA = 0.12, precio_habitacion=120.0,subtotal=0,total=0,impuesto;
    
    
    for (i=0;i<50;i++){
        hotel[i]=0;
    }   do {
        
        
        printf("%s","\n\n\t HOTEL ESPOL\n");
        printf("%s","1. Realizar reservación\n");
        printf("%s","2. Pagar reservación\n");
        printf("%s","3. Cancelar reservación\n");
        printf("%s","4. Ocupación del hotel\n");
        printf("%s","5. Salir\n");
        printf("%s","\nOPCIÓN:");
        
        scanf("%c", &opcion);
        
        switch(opcion)
        
        { case '1':
                printf("%s","\nIngrese el número de la habitacion (1-50): ");
                scanf("%d", &habitacion);
                habitacion = habitacion-1;
                if(reservar_habitacion(habitacion) ==0){
                    while(getchar()!='\n');
                    break;
                }
                while(getchar()!='\n');
                break;
                
            case '2':
                suma = habitaciones_ocupadas(suma);
                calcular_total(suma,IVA, precio_habitacion,subtotal,total,impuesto);
                
                while(getchar()!='\n');
                break;
                
            case '3':
                
                printf("%s","\nIngrese El número de la habitación(1-50):");
                scanf("%d", &habitacion);
                habitacion = habitacion-1;
                cancelar_reserva(habitacion);
                while(getchar()!='\n');
                break;
                
            case '4':
                
                printf("%s","OCUPADAS: \n");
                
                for (i=0;i<=49;i++){
                    if(hotel[i]==1){
                        j=i+1;
                        printf("Habitación %d\n",j);
                    }
                }
                printf("%s","\nDISPONIBLES: \n");
                
                for (i=0;i<=49;i++){
                    if(hotel[i]==0){
                        j=i+1;
                        printf("Habitación %d\n",j);
                    }
                }
                while(getchar()!='\n');
                break;
                
            case '5':
                while(getchar()!='\n');
                break;
                
            default:
                
                printf("%s","\n  ");
                
        }
        
        
    } while (opcion != '5');
    
    printf("%s","\n Gracias por su visita");
    return 0;
    
}

int reservar_habitacion(int habitacion){
    
    if ((habitacion<0)||(habitacion>49)){
        printf("%s","\n La habitación seleccionada no existe");
        return 0;
    }else{
        
        if (hotel[habitacion]==0){
            hotel[habitacion]=1;
            
            printf("%s","La habitación ha sido reservada exitosamente");
            
        }else
        printf("%s","La habitación no se encuentra disponible");
        return 1;
    }
    
    
}

void cancelar_reserva(int habitacion){
    if (hotel[habitacion]==0){
        printf("%s","\nLa habitación no ha sido reservada");
        
    }else{
        hotel[habitacion]=0;
        printf("%s","\nLa habitación ha sido cancelada exitosamente");
    }
}


void calcular_total (int suma, float IVA, float precio_habitacion,float subtotal,float total,float impuesto) {
    subtotal = suma * precio_habitacion;
    impuesto = subtotal * IVA;
    total = subtotal + impuesto;
    printf("IVA: 12 porciento");
    printf("\nSubtotal: %.2f\n",subtotal);
    printf("Total: %.2f\n",total);
}

int habitaciones_ocupadas(int suma){
    int i;
    for (i=0;i<=49;i++){
        if(hotel[i]==1)
        suma++;
    }
    return suma;
}
