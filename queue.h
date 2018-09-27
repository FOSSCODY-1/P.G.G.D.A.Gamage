#include <stdio.h>

int queue[20];
int front=-1,rear=-1;

void enqueue(int n){
	if(front==0 && rear==0){
		front++;
		queue[front]=n;
		rear++;
	}
	
	else{
		rear++;
		queue[rear]=n;
		
	}
}

int dequeue(){
	int temp;
	temp=queue[front];
	front++;
	return temp;
}

int main(){
	
}
