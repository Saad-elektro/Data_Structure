#include<stdio.h>
#include<malloc.h>
#include<memory.h>
#include <stdbool.h>

//Modification git1

typedef struct {   // Container Design

int *buffer; // Points to data array
size_t head;
size_t tail;
int count;
int length;

} CB;


// Circular Buffer Initialization

CB* Buffer_Init(int* buf, size_t cap){       // The user provides the data buffer --> he can choose Static/Dynamic allocation  
						// The function returns a pointer to the structure, which allows the user to manipulate the original structure
	
CB* CB_buffer  = (CB*) malloc (sizeof(CB));  // We allocate dynamically the strcuture

/*	
	//Static allocation : Instatiate the stucture
	  CB CB_Buffer;
	// Pointer to the structure  
	CB* pt_buffer = &CB_Buffer;  
*/	 
	 
	CB_buffer->buffer = buf;
	CB_buffer->head = 0;
	CB_buffer->tail = 0;
	
	CB_buffer->length = cap;
	CB_buffer->count = 0;
	
	return CB_buffer;
}


bool is_buffer_full(CB* BUFFER) {

if (BUFFER->head +1 == BUFFER->length|| BUFFER->head == BUFFER->tail + (BUFFER->length -1) ){


 //if (BUFFER->head+1 == BUFFER->tail || BUFFER->head == BUFFER->tail + (BUFFER->length -1) ) {   // if the head is in the element previous to the tail
  printf(" BUFFER IS FULL")	;							// if the head is in the last position and the tail is at position 0
  return true;}
else{

printf(" BUFFER IS not full  \r\n")	;

return false;}
}


void Push_data(CB* Cbuffer, int item){
	
//	 1) Check if the buffer is full  (fct is full)
	// Check condition of methode 2 (voir resumé)
	//if ((Cbuffer->count &&  Cbuffer->head) == Cbuffer->tail){
	
//	if (is_buffer_full(Cbuffer)==true){
	//	printf (" the buffer is full\r\n");
		//	}
		
		//size_t capacity = Cbuffer->head - Cbuffer->tail ;
		
	if(Cbuffer->count && (Cbuffer->head % Cbuffer->length) == Cbuffer->tail) // if Cbuffer->count == true and (Cbuffer->head % Cbuffer->length) == Cbuffer->tail
                                                                            // means that the count and head are wrapped around the base or the tail (RAZ) -> reset

	

	{
	  
	
	 printf ("overwrite element %d = %d\r\n", Cbuffer->tail, Cbuffer->buffer[Cbuffer->tail] );
	 
	 Cbuffer->tail++;
	 Cbuffer->count--;
}
	 printf("Added element : Element[%d] = %d \r\n", Cbuffer->head, item);
	 Cbuffer->buffer[Cbuffer->head] = item;
	 
	 
	 Cbuffer->head++;
	 Cbuffer->count++;
	
	}	
	
int Read_out_data (CB* Rbuffer,int* data){
	
//int data;
	
	// Check if the buffer is empty
	if (Rbuffer->count<=0 || Rbuffer->head == Rbuffer->tail){     
		printf ("Empty buffer ");
	}
	
	if ((Rbuffer->count || Rbuffer->tail)!= Rbuffer->head){
		
		*data = Rbuffer->buffer[Rbuffer->tail];
		Rbuffer->tail++;
		Rbuffer->count--;
		//printf ("data %d", *data);
	}
		//return data;
	}

//}
	
int main(){
	
	int read_data; // The variable where we load the read data from data_buffer
	
	CB* user_buffer;
// Static allocation
/*
	int data_buffer[5];  
	int *buf = &data_buffer; // the buf pointer is pointing to data_buffer Array --> Static allocation
	
	// we can also use directly the data_buffer[5] and passed it into init function 	user_buffer = Buffer_Init(data_buffer, 5) since data_buffer is a pointer (array)
	
	printf ("buffer = %d\r\n", buf);
*/
	int* buf = (int* )malloc(sizeof(5)); // The user has choosed to allocate the data buffer dynamically
	//printf ( "ok");
	user_buffer = Buffer_Init(buf, 5);  // The fct init create a container (struct) with the members(buf, tail,head, capacity), then
										// Then allocate dynamically this container, and return a pointer that is assigned to user_buffer
	
	
	printf ("Buffer Initialized\r\n");
	
	printf ("Adding element\r\n");
	
	Push_data(user_buffer, 265);
	Push_data(user_buffer, 32);
	Push_data(user_buffer, 3);
	Push_data(user_buffer, 4);
	Push_data(user_buffer, 5);
	Push_data(user_buffer, 6);
        Push_data(user_buffer, 1);
        Push_data(user_buffer, 98);
	
	printf ("the number of element is : %d \r\n", user_buffer->count);
	

	
	//read_data = Read_out_data (user_buffer);
   Read_out_data (user_buffer, &read_data)	; // we pass to the function the adress of the variable where we would stock the read data
 
  //printf ("read data %d\r\n", read_data);
  
  printf ("the number of element is : %d \r\n", user_buffer->count);
  
  printf ("read data %d\r\n", read_data);
  
  // read_data = Read_out_data (user_buffer)	;
  
  Read_out_data (user_buffer, &read_data)	;
 
   printf ("read data %d\r\n", read_data);
    
    printf ("the number of element is : %d \r\n", user_buffer->count);
    
    Read_out_data (user_buffer, &read_data)	;
 
   printf ("read data %d\r\n", read_data);
    
    printf ("the number of element is : %d \r\n", user_buffer->count);
    
    Read_out_data (user_buffer, &read_data)	;
 
   printf ("read data %d\r\n", read_data);
    
    printf ("the number of element is : %d \r\n", user_buffer->count);
    
    Read_out_data (user_buffer, &read_data)	;
 
   printf ("read data %d\r\n", read_data);
    
    printf ("the number of element is : %d \r\n", user_buffer->count);
    
    Read_out_data (user_buffer, &read_data)	;
 
   printf ("read data %d\r\n", read_data);
    
    printf ("the number of element is : %d \r\n", user_buffer->count);
	
	
	return 1;

}	
	
	




