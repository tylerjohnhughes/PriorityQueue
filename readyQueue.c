/**
 * readyQueue.c
 *
 * @author Tyler Hughes, Harman Bains, Tan Pham
 */

#include <stdio.h>
#include <stdlib.h>
#include "readyQueue.h"


PCB *PriorityQueue_dequeue(PriorityQueue *queue) {
    int i = 0;
	while (i < PRIORITY_CLASSES) {
		while (queue->queues[i].head != NULL) {
            PCBNode *node = queue->queues[i].head;
			PCB *pcb = node->pcb;
			queue->queues[i].head = queue->queues[i].head->next;
            free(node);
			return pcb;
		}
		i++;
	}
	return NULL;
}

void PriorityQueue_enqueue(PriorityQueue *queue, PCB *pcb) {
	PCBNode *pcbn = (PCBNode *) malloc(sizeof(PCBNode));
	pcbn->pcb = pcb;
	pcbn->next = NULL;
	int i = pcb->priority;
	if (queue->queues[i].tail == NULL) {
        queue->queues[i].head = pcbn;
        queue->queues[i].tail = pcbn;
	} else {
		queue->queues[i].tail->next = pcbn;
		queue->queues[i].tail = pcbn;
	}
}

PCB *PriorityQueue_peekProcess(PriorityQueue *queue, int processID) {
    PCBNode *curr;
    for (int i = 0; i < PRIORITY_CLASSES; ++i) {
        curr = queue->queues[i].head;
        while (curr != NULL) {
            if (curr->pcb->processID == processID) {
                return curr->pcb;
            }
            curr = curr->next;
		}
    }
    return NULL;
}
