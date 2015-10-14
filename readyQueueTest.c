/**
 * readyQueueTest.c
 *
 * @author Tyler Hughes, Harman Bains, Tan Pham
 */

#include <stdio.h>
#include <stdlib.h>
#include "readyQueue.h"


int getPriority(void);

void traverse(PriorityQueue *queue);


int main(int argc, char *argv[]) {
    PriorityQueue readyQueue = {};
    int processID = 0;
    
    int priority = getPriority();
    while (0 <= priority && priority < PRIORITY_CLASSES) {
        PCB *pcb = (PCB *) malloc(sizeof(PCB));
        pcb->processID = processID++;
        pcb->priority = priority;
        pcb->state = NEW;
        
        PriorityQueue_enqueue(&readyQueue, pcb);
        
        priority = getPriority();
    }
    
    traverse(&readyQueue);
    
    return 0;
}

int getPriority(void) {
    int priority;
    printf("Process priority [0, %d): ", PRIORITY_CLASSES);
    scanf("%d", &priority);
    return priority;
}

void traverse(PriorityQueue *queue) {
    PCB *pcb = PriorityQueue_dequeue(queue);
	while(pcb != NULL){
		printf("Process ID %d, with priority %d\n", pcb->processID, pcb->priority);
		pcb = PriorityQueue_dequeue(queue);
	}
}
