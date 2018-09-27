#include <stdio.h>

int time=0;

void visit(struct node array[], struct node *ptr){
	if(ptr->color!=0){
		return;
	}
	else{
		time=time+1;
		ptr->dtime=time;
		ptr->color=1;
		for(int j=0;j<n;j++){
			visit(array[],);
		}
		
		
	}
	
}




void DFS(struct node array[],int n){
	
	for(int i=0;i<n;i++){
		if(array[i].color==0){
			visit(struct node array[],array+i);
		}
	}
}

