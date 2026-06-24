class MyCircularQueue {
public:


    /*
        Algorithm:


        1. Create an array:

           The array stores queue elements.

           Example:

           k = 3

           arr:

           [ _ , _ , _ ]


           We maintain two pointers:

           front:
           - points to first element

           rear:
           - points to last element



        2. Initialize:

           front = -1
           rear = -1


           When both are -1:

           Queue is empty.



        3. enQueue operation:


           Before inserting:

           Check if queue is full.

           Full condition:

           (front == 0 && rear == size-1)
           OR
           front == rear + 1


           If empty:

           Increase front and rear.

           Insert value.



           If rear reaches the end:

           Move rear back to 0.

           This creates circular behavior.



           Otherwise:

           Move rear forward.

           Insert value.




        4. deQueue operation:


           Before deleting:

           Check if queue is empty.


           If only one element exists:

           Reset:

           front = -1
           rear = -1



           If front reaches the end:

           Move front to 0.



           Otherwise:

           Move front forward.




        5. Front operation:


           Return element at front.

           If empty:

           return -1.




        6. Rear operation:


           Return element at rear.

           If empty:

           return -1.




        Example:


        k = 3


        enQueue(1)

        arr:

        [1,_,_]

        front = 0
        rear = 0



        enQueue(2)

        arr:

        [1,2,_]

        front = 0
        rear = 1



        enQueue(3)

        arr:

        [1,2,3]

        front = 0
        rear = 2



        deQueue()

        remove 1

        front moves forward



        enQueue(4)

        rear reaches end,
        so it goes back to index 0


        arr:

        [4,2,3]


        Circular queue formed.



    */


    int* arr;
    int size;
    int front;
    int rear;



    MyCircularQueue(int k) {

        arr = new int[k];

        size = k;

        front = -1;
        rear = -1;
    }




    bool enQueue(int value) {


        // Queue is full

        if((front == 0 && rear == size-1) || front == rear + 1)
        {
            return false;
        }



        // First element

        else if(front == -1 && rear == -1)
        {
            front++;
            rear++;

            arr[rear] = value;
        }



        // Circular movement

        else if(rear == size-1 && front != 0)
        {
            rear = 0;

            arr[rear] = value;
        }



        // Normal insertion

        else
        {
            rear++;

            arr[rear] = value;
        }


        return true;
    }





    bool deQueue() {


        // Queue empty

        if(front == -1 && rear == -1)
        {
            return false;
        }



        // Only one element

        else if(front == rear)
        {
            front = -1;
            rear = -1;
        }



        // Circular movement

        else if(front == size-1)
        {
            front = 0;
        }



        // Normal deletion

        else
        {
            front++;
        }


        return true;
    }





    int Front() {


        // Empty queue

        if(front == -1)
        {
            return -1;
        }


        return arr[front];
    }





    int Rear() {


        // Empty queue

        if(rear == -1)
        {
            return -1;
        }


        return arr[rear];
    }





    bool isEmpty() {


        return front == -1 && rear == -1;
    }





    bool isFull() {


        return (front == 0 && rear == size-1) 
               || 
               front == rear + 1;
    }
};



// Time Complexity:
//
// enQueue  -> O(1)
// deQueue  -> O(1)
// Front    -> O(1)
// Rear     -> O(1)
// isEmpty  -> O(1)
// isFull   -> O(1)




// Space Complexity:
//
// Array stores k elements.
//
// O(k)
