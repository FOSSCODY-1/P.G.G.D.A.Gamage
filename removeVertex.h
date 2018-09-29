#include <stdio.h>
#include <stdlib.h>
#include "Depth first search.h"

int removeEdge(struct node array[],int,int);


int removeVertex(struct node array[],int vertex){
	
	array[vertex-1].data=0;
	array[vertex-1].color=0;
	array[vertex-1].d=0;
	array[vertex-1].dtime=0;
	array[vertex-1].ftime=0;
	array[vertex-1].pre=NULL;
	array[vertex-1].next=NULL;
	
	for(int i=0;i<20;i++)
	{
		
		if((array[i].data)!=0)
		{
			printf("this is one\n");
			removeEdge(array,i+1,vertex);
			
		}
		
	}
	
	return 1;
}

int removeEdge(struct node array[],int parent,int child){
	int i=parent-1;
	int count=1;
	
	struct edge *temp,*preptr;
	temp=preptr=array[i].next;
	
	while(temp)
	{
		if(temp->data==child)
		{
			if(count==1)
			{              //If this is first node in the list
				array[i].next=temp->next;
				printf("this is two\n");
				free(temp);
				break;
			}
			else
			{
				preptr->next=temp->next;
				printf("this is three");		//If it is middele node in the list
				free(temp);
				break;
			}
			
		}
		
		preptr=temp;
		temp=temp->next;
		count++;
	}
	
}
