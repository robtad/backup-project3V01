#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
const int MAX = 10;
int A[10];
int front = -1;
int rear = -1;
int i, temp;
int node, left, right, father;

void getFamily(int i)
{
    node = A[i];
    father = A[(i - 1) / 2];
    left = A[2 * i + 1];
    right = A[2 * i + 2];
}
void setFamilyNF()
{
    A[i] = node;
    A[(i - 1) / 2] = father;
}
void setFamilyNL()
{
    A[i] = node;
    A[2 * i + 1] = left;
}
void setFamilyNR()
{
    A[i] = node;
    A[2 * i + 2] = right;
}
void swapNF()
{
    temp = node;
    node = father;
    father = temp;
}
void swapNL()
{
    temp = node;
    node = left;
    left = temp;
}
void swapNR()
{
    temp = node;
    node = right;
    right = temp;
}
bool isEmpty()
{
    if (front == -1 && rear == -1)
        return true;
    else
        return false;
}
bool isFull()
{
    if (rear == MAX - 1)
        return true;
    else
        return false;
}
void addToPQ(int x)
{
    if (isEmpty())
    {
        front = rear = 0;
        A[rear] = x;
        printf("element %d is added to PQ successfully!\n", A[rear]);
    }
    else if (isFull())
    {
        printf("Sorry! The PQ is full.");
        return;
    }
    else //if there is atleast one element in the PQ
    {
        rear += 1;
        A[rear] = x;
        printf("element %d is added to PQ successfully!\n", A[rear]);
        i = rear;

        while (i > front)
        {
            getFamily(i);
            if (node < father)
            {
                swapNF(); //swap current node with its father
            }
            setFamilyNF(); //to put the swaped element in array;
            i = (i - 1) / 2;
        }
    }
}
void removeFromPQ()
{
    if (isEmpty())
    {
        printf("can't remove, the PQ is empty\n");
        return;
    }
    else if (front == rear) //if there is only one element in pq(i,e only root)
    {
        printf("element %d is dequeued/removed from PQ\n", A[front]);
        front = -1; //dequeueing when front == rear makes the queue empty.
        rear = -1;
        return;
    }
    else //if there are more than one elements
    {
        printf("%d is dequeued/removed from PQ\n", A[front]);
        A[front] = A[rear]; //putting the last element in the root(since root is removed)
        rear -= 1;          //since the rear element goes to the root rear points to the next rear element (which is rear-1)
        int i = front;
        //int depth = log2(rear);
        getFamily(i);
        while (i < rear)

        {
            if (((2 * i) + 1) > rear) //if the left kid is not there the node A[i] has no kids at all in a heap.
                break;                //to prevent accessing non existent kids
            if (((2 * i) + 2) > rear) //if the right kid is not there check the left and swap if it is smaller than A[i].
            {                         //to prevent accessing non existent kids
                if (left < node)
                {
                    swapNL(); //swap node and its left child
                    setFamilyNL();
                    break;
                }
            }

            if (left < right)
            {
                if (left > node)
                    break; ////no swap needed if the parent is smaller than the smaller kid(i.e, everyone is inplace)
                else
                {
                    swapNL(); //swap node and its left child
                    setFamilyNL();
                }
                i = (2 * i) + 1;
            }
            else
            {
                if (right > node)
                    break; //no swap needed if the parent is less than the smaller kid(i.e, everyone is inplace)
                else
                {
                    swapNR();
                    setFamilyNR();
                }
                i = (2 * i) + 2;
            }
            /*NB if the left and right kids have the same landingTime (i.e,  (A[(2 * i) + 1] == A[(2 * i) + 2]))
             swap according to their priorityId(swap with the smallest priotityId) if they have the same priorityId,
             swap with the smaller planeNo. and add 1 hour to the landingTime of the 
             plane which is not swapped.
            */
        }

        return;
    }
}

int main()
{

    /*int node = A[i];
    int left = A[2 * i + 1];
    int right = A[2 * i + 2];
    int father = A[(i - 1) / 2];*/
    /*printf("\n\n");
    /////////ctr+k+c comment out, ctr+k+u uncomment
    // printf(isEmpty() ? "Yes,it is empty!\n" : "No, it is not empty!\n");
    // printf(isFull() ? "Yes,it is full!\n" : "No, it is not full!\n");
    // atFront();
    //dequeue();
    addToPQ(33);

    removeFromPQ();
    removeFromPQ();

    for (int i = 0; i < MAX; i++)
    {
        addToPQ(i * 10);
    }
    printf("front: %d\nrear: %d\n", front, rear);

    for (int i = 0; i < 5; i++)
    {
        printf("rootNow: %d\n", A[front]);
        removeFromPQ();
        
        printf("\n");
    }
    printf("front: %d\nrear: %d\n", front, rear);

    for (int i = 0; i < 6; i++)
    {
        addToPQ(i + 12);
    }
    printf("front: %d\nrear: %d\n", front, rear);

    printf("\n\n\n");
*/

    addToPQ(80);
    printf("front=%d    rear=%d\nroot=%d    tail=%d\n", front, rear, A[front], A[rear]);

    addToPQ(40);
    printf("front=%d    rear=%d\nroot=%d    tail=%d\n", front, rear, A[front], A[rear]);

    addToPQ(70);
    printf("front=%d    rear=%d\nroot=%d    tail=%d\n", front, rear, A[front], A[rear]);

    addToPQ(60);
    printf("front=%d    rear=%d\nroot=%d    tail=%d\n", front, rear, A[front], A[rear]);

    addToPQ(10);
    printf("front=%d    rear=%d\nroot=%d    tail=%d\n", front, rear, A[front], A[rear]);

    addToPQ(30);
    printf("front=%d    rear=%d\nroot=%d    tail=%d\n", front, rear, A[front], A[rear]);

    addToPQ(50);
    printf("front=%d    rear=%d\nroot=%d    tail=%d\n", front, rear, A[front], A[rear]);
    for (int i = 0; i < MAX; i++)
        printf("%d  ", A[i]);

    printf("front=%d    rear=%d\nroot=%d    tail=%d\n", front, rear, A[front], A[rear]);

    printf("\n");
    removeFromPQ();
    printf("front=%d    rear=%d\nroot=%d    tail=%d\n", front, rear, A[front], A[rear]);
    printf("\n");
    removeFromPQ();
    printf("front=%d    rear=%d\nroot=%d    tail=%d\n", front, rear, A[front], A[rear]);
    printf("\n");
    removeFromPQ();
    printf("front=%d    rear=%d\nroot=%d    tail=%d\n", front, rear, A[front], A[rear]);
    printf("\n");
    removeFromPQ();
    printf("front=%d    rear=%d\nroot=%d    tail=%d\n", front, rear, A[front], A[rear]);
    printf("\n");
    removeFromPQ();
    printf("front=%d    rear=%d\nroot=%d    tail=%d\n", front, rear, A[front], A[rear]);
    printf("\n");
    removeFromPQ();
    printf("front=%d    rear=%d\nroot=%d    tail=%d\n", front, rear, A[front], A[rear]);
    printf("\n");
    removeFromPQ();
    printf("front=%d    rear=%d\nroot=%d    tail=%d\n", front, rear, A[front], A[rear]);
    printf("\n");
    removeFromPQ();
    printf("front=%d    rear=%d\nroot=%d    tail=%d\n", front, rear, A[front], A[rear]);
    printf("\n");
    return 0;
}