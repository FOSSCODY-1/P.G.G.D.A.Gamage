#include <stdio.h>
#include "Breadth first search.h"

int time=0;

void visit(struct node array[], struct node *ptr){
	
	struct edge *temp=ptr->next;
	
	if(ptr->color!=0)
	{
		return;
	}
	else
	{
		time=time+1;
		ptr->dtime=time;
		ptr->color=1;
		
		while(temp)
		{
			
		visit(array,array+(temp->data-1));
		temp=temp->next;
		
		}
		time++;
		ptr->ftime=time;
		printf("\n%d",ptr->data);
		return;
			
		
		
		}
		
		
	}



void DFS(struct node array[],int n){
	for(int j=0;j<20;j++)
	{
		
		array[j].color=0;
	}
	 
	
	for(int i=0;i<n;i++)					//Depth first traversal is carried out even on graphs which are not strongly connected
	{										
		if(array[i].color==0)
		{
			visit(array,array+i);
		}
	}
}

