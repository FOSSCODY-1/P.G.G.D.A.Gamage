#include <stdio.h>

//Creating structures

 													//for edge
struct edge{
	int data;
	struct edge *next;
};

													//for vertex
struct node{
	int data;
	int color;
	int d;
	int dtime;
	int ftime;	
	struct node *pre;
	struct edge *next;
};
//Queue has been introduced carry out Breadth first search properly


// start of queue

struct node *queue[20];
int front=-1,rear=-1;

void enqueue(struct node *n){
	
	if(front==-1 && rear==-1)
	{
		front++;
		queue[front]=n;
		rear++;
		
	}
	
	else
	{
		rear++;
		queue[rear]=n;
		
	}
}

struct node * dequeue(){
	
	struct node *temp;
	temp=queue[front];
	front++;
	
	return temp;
}

// End of queue




void BFS(struct node array[]){
	
	struct edge *current=NULL;					//Numbers has been used to keep track of the Breadth first travesal process
											    //All nodes start out with 0(white color in basic algorithm)
	array->color=1;								//Number 1 for Gray color
	array->d=0;									//Number 2 for black color
	array->pre=NULL;
	
	enqueue(array+0);
	
	while(front<=rear)
	{
		int i=0;
		struct node *u=NULL;
		
		u=dequeue();		
		current=u->next;
		
		while(current)
		{
			
			if(array[(current->data)-1].color==0)
			{
				
				array[(current->data)-1].color=1;
				array[(current->data)-1].d=u->d+1;
				array[(current->data-1)].pre=u;
			
				int c=(current->data)-1;
				enqueue(array+c);
			
				
				
				
			}
			
			current=current->next;
			
		}
		
		printf("\n%d",u->data);		
		
	}
	
}
	
	


