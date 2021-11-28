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

        while (i < rear)

        {
            if (((2 * i) + 1) > rear) //if the left kid is not there the node A[i] has no kids at all in a heap.
                break;                //to prevent accessing non existent kids
            if (((2 * i) + 2) > rear) //if the right kid is not there check the left and swap if it is smaller than A[i].
            {                         //to prevent accessing non existent kids
                if (A[(2 * i) + 1] < A[i])
                {
                    temp = A[i];
                    A[i] = A[(2 * i) + 1];
                    A[(2 * i) + 1] = temp;
                    break;
                }
            }

            if (A[(2 * i) + 1] < A[(2 * i) + 2])
            {
                if (A[(2 * i) + 1] > A[i])
                    break; ////no swap needed if the parent is smaller than the smaller kid(i.e, everyone is inplace)

                temp = A[i];
                A[i] = A[(2 * i) + 1];
                A[(2 * i) + 1] = temp;
                i = (2 * i) + 1;
            }
            else
            {
                if (A[(2 * i) + 2] > A[i])
                    break; //no swap needed if the parent is less than the smaller kid(i.e, everyone is inplace)

                temp = A[i];
                A[i] = A[(2 * i) + 2];
                A[(2 * i) + 2] = temp;
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