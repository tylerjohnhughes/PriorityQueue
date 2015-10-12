#include <stdio.h>
#include "readyQueue.h"


PCB *PriorityQueue_dequeue(PriorityQueue *queue) {
    int i = 0;
	while(i<64){
		if(queue->queues[i].head != NULL){
			PCB *toReturn = queue->queues[i].head->pcb;
			queue->queues[i].head = queue->queues[i].head->next;
			return toReturn;
		}
		i++;
	}
	return NULL;
}

void PriorityQueue_enqueue(PriorityQueue *queue, const PCB *pcb) {
	PCBNode *pcbn;
	pcbn->pcb = pcb;
	pcbn->next = NULL;
	int i = pcb->priority;
	if(queue->queues[i].head == queue->queues[i].tail == NULL ){
		queue->queues[i].head = queue->queues[i].tail = pcbn;
	}else{
		queue->queues->tail->next = pcbn;
		queue->queues->tail = pcbn;
	}

}
