#include <stdio.h>
#include <stdlib.h>
#include "removeVertex.h"

// Add vertex to Graph but edges has to be created explicitly by calling 'addEdge' method
int addVertex(struct node adj[],int data){
		
		int i = data -1;
	
		adj[i].data=i+1;
		adj[i].color=0;
		adj[i].d=0;
		adj[i].pre=NULL;
		adj[i].next=NULL;
		
		return 1;
	
}

// Creates one edge at a time

int addEdge(struct node array[],int parent,int child){
	
	int i=parent-1;
	struct edge *temp,*newNode;
	
	temp=(array+i)->next;
	
	while(temp->next)
	{
		temp=temp->next;
	}
	

	newNode = (struct edge*)malloc(sizeof(struct edge));
	newNode->data=child;			
	newNode->next=NULL;
	
	temp->next=newNode;
	//printf("Edge succesfully created\n");
	
	
	return 1;
	
	
	

}
