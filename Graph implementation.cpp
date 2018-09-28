#include <stdio.h>
#include <stdlib.h>
//#include "Depth first search.h"
#include "addVertex.h"
//#include "removeVertex.h"


struct node adj[20];


void callBFS(){											// 	This function will make color of every vertex before performing BFS
	
	for(int j=0;j<20;j++)
	{
		
		adj[j].color=0;
	}
	 
	for(int i=0;i<20;i++)
	{
									// 	This is will perfom BFS even on Graphs which are not strongly connected
		if(adj[i].data!=0 && adj[i].color==0)
		{
			BFS(adj+i);
		}
		
	}
	
}
// Create Graph 

void create_graph(struct node adj[],int no_of_nodes){
	
	for(int i=0;i<no_of_nodes;i++)
	{
		int c;
		struct edge *last = NULL;
		
		printf("\nEnter No of adjacent nodes to node %d : ",i+1);
		scanf("%d",&c);
		printf("\nEnter values of adjacent node of %d : \n",i+1);
		
		for(int j=0;j<c;j++)
		{
			int val;
			struct edge *newNode;			
			scanf("%d",&val);
			
			newNode = (struct edge*)malloc(sizeof(struct edge));
			newNode->data=val;			
			newNode->next=NULL;
			
			if(last==NULL)
			{
				adj[i].next=newNode;
				
			}
			else
			{
				last->next=newNode;				
			}
			
			last=newNode;
			
			
		}
		
	}
	
}
int main(){
	
	int n,op;
	printf("Enter number of nodes : ");
	scanf("%d",&n);
	
// Initialize the Adj[] array for vertices	
	
	for(int i=0;i<n;i++)
	{
		adj[i].data=i+1;
		adj[i].color=0;
		adj[i].d=0;
		adj[i].pre=NULL;
		adj[i].next=NULL;
	}
	
	create_graph(adj,n);
	
	
	printf("Select next operation :\n 1.Add Vertex\n 2.Add Edge\n 3.Remove Vertex\n 4.Remove Edge 5.Breadth first Search\n 6.Depth First Search\n");
	scanf("%d",&op);
	
	
	switch(op){
		case 1:
			int val;
			printf("Enter value of new vertex:");			
			scanf("%d",&val);	
			addVertex(adj,val);
			printf("Vertex successfully created\n");
			break;
		case 2:	
			int parent,child;
			printf("Enter parent and child:");
			scanf("%d %d",&parent,&child);
			addEdge(adj,parent,child);
			printf("Edge successfully created\n");
			break;
		case 3:	
			
			printf("Enter value of vertex you want to delete :");	
			scanf("%d",&val);	
			removeVertex(adj,val);
			printf("Vertex successfully deleted\n");
			break;
		case 4:
			
			printf("Enter parent and child:");
			scanf("%d %d",&parent,&child);
			removeEdge(adj,parent,child);
			printf("Edge successfully deleted\n");
			break;	
		
		case 5:
			callBFS();			
			break;
			
		case 6:
			DFS(adj,n);	
			
			
	}
	

	
	
	
	
	
	

	
}



