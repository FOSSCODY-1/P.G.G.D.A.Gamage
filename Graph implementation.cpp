#include <stdio.h>
#include <stdlib.h>

#include "Depth first search.h"

//struct node *adj[5];
void create_graph(struct node adj[],int no_of_nodes){
	
	for(int i=0;i<no_of_nodes;i++){
		int c;
		struct edge *last = NULL;
		
		printf("Enter No of adjacent nodes to node %d: ",i+1);
		scanf("%d",&c);
		
		for(int j=0;j<c;j++){
			
			struct edge *newNode;
			int val;
			
			printf("Enter value of %d adjacent node of %d: ",j+1,i+1);
			scanf("%d",&val);
			
			newNode = (struct edge*)malloc(sizeof(struct edge));
			newNode->data=val;
			
			newNode->next=NULL;
			
			if(last==NULL){
				adj[i].next=newNode;
				
			}
			else{
				last->next=newNode;				
			}
			
			last=newNode;
			
			
		}
		
	}
	
}
int main(){
	
	int n;
	printf("Enter number of nodes");
	scanf("%d",&n);
	struct node adj[n];
	
	
	for(int i=0;i<n;i++){
		adj[i].data=i+1;
		adj[i].color=0;
		adj[i].d=0;
		adj[i].pre=NULL;
		adj[i].next=NULL;
	}
	
	create_graph(adj,n);
	DFS(adj,n);
	
}
