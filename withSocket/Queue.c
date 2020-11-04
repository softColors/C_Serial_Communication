//-----------------------------------------------------------------------------
// PROGRAMMER   : cucudas0127
// REVISION     : 2020.11.03
// DESCRIPTS    : Queue Function Tools
// Environment Setting
// OS : ubuntu 18.04
//-----------------------------------------------------------------------------

#include "header.h"

/*

Queue is typically FIFO(First-in-First-Out) function.

Example) 

        Push_Queue(queue,99)
        ===========
        |[ 1]  99 |  <-- 99
        ===========

        Push_Queue(queue,100)
        ======================
        |[ 1]  99 ||[ 2] 100 |  <-- 100
        ======================

        Pop_Queue(queue)
        ===========
99 <--  |[ 2] 100 |
        ===========

        Push_Queue(queue,101)
        ======================
        |[ 2] 100 ||[ 3] 101 |  <-- 101
        ======================
*/

//-----------------------------------------------------------------------------
// Function descripts : Initialization Queue
//-----------------------------------------------------------------------------
void Init_queue(Queue *q) {
	q->front = 0;
	q->rear = 0;
}
//-----------------------------------------------------------------------------
// Function descripts : push Queue
//-----------------------------------------------------------------------------
int Push_Queue(Queue *q, element data) {

	// check if the queue stack is full
    if (is_full(q))		return -1;
	
	q->rear =(q->rear + 1) % (MAX_QUEUE_SIZE);	
	q->data[q->rear] = data;	
	return 1;
}


//-----------------------------------------------------------------------------
// Function descripts : Pop Queue
//-----------------------------------------------------------------------------
element Pop_Queue(Queue *q) {

 	// check if the queue stack is empty
	if (is_empty(q))   return -1;
	
	q->front = (q->front + 1) % (MAX_QUEUE_SIZE);
	return q->data[q->front];
}


//-----------------------------------------------------------------------------
// Function descripts : check Queue Empty
//-----------------------------------------------------------------------------
bool is_empty(Queue *q) {
	if (q->front == q->rear) return 1;
	else return 0;
}

//-----------------------------------------------------------------------------
// Function descripts : check Queue Full
//-----------------------------------------------------------------------------
bool is_full(Queue *q) {
	if (((q->rear + 1) % MAX_QUEUE_SIZE) == q->front) return 1;
	else return 0;
}

//-----------------------------------------------------------------------------
// Function descripts : Queue constents print
//-----------------------------------------------------------------------------
void Queue_Print(Queue q) 
{
	int i = q.front;
	if (is_empty(&q)) 
    {
		printf("\nQueue stack is empty..!!\n");
		return;
	}
    if(is_full(&q)) 
    {
		printf("\nQueue stack is full..!!\n");
		return;
	}
	do {
		i = (i + 1) % MAX_QUEUE_SIZE;
        printf("|[%2d] %3d |",i, q.data[i]);
		if (i == q.rear) 
        {
			break;
		}
	}
    while (i != q.front);
	printf("\n=======================================================\n");
	return;
}



/* // For Test 
void main(void)
{

    
    Queue test_queue;
    Init_queue(&test_queue);

    Queue_Print(test_queue); 
    Push_Queue(&test_queue, 'c');

    Queue_Print(test_queue); 
    Push_Queue(&test_queue, 'd');
    Queue_Print(test_queue); 
    Pop_Queue(&test_queue);
    Queue_Print(test_queue); 
    Push_Queue(&test_queue, 'e');
    Queue_Print(test_queue); 
    Pop_Queue(&test_queue);
    Queue_Print(test_queue); 

}

*/