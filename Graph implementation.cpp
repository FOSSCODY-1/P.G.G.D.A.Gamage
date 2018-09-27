#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *next;
};


//struct node *adj[5];



void create_graph(struct node *adj[],int no_of_nodes){
	
	for(int i=0;i<no_of_nodes;i++){
		
		int c;
		struct node *last = NULL;
		
		printf("Enter No of adjacent nodes to node %d: ",i+1);
		scanf("%d",&c);
		
		for(int j=0;j<c;j++){
			
			struct node *newNode;
			int val;
			
			printf("Enter value of %d adjacent node of %d: ",j+1,i+1);
			scanf("%d",&val);
			
			newNode = (struct node*)malloc(sizeof(struct node));
			newNode->data=val;
			newNode->next=NULL;
			
			if(last==NULL){
				adj[i]=newNode;
				
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
	struct node *adj[n];
	
	
	create_graph(adj,n);
	
}
