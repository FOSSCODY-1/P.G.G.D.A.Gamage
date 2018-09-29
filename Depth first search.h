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
		printf("%d\n",ptr->data);
		return;
			
		
		
		}
		
		
	}



void DFS(struct node array[],int n){
	
	for(int i=0;i<n;i++)
	{
		if(array[i].color==0)
		{
			visit(array,array+i);
		}
	}
}

