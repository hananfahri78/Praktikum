#include "queue.h"

void createQueue(Queue &Q) {
    Q.head = -1; 
    Q.tail = -1;
}

bool isEmptyQueue(Queue Q) {
    if (Q.head == -1 && Q.tail == -1){
        return true;
    }else{
        return false;
    }
}


// Full queue

/* Full Alter 1
bool isFullQueue(Queue Q) {
    if (Q.tail == MAX - 1) {
        return true;
    }else{
        return false;
    }
}
*/

/* Full ALter 2
bool isFullQueue(Queue Q) {
    return (Q.head == 0 && Q.tail == MAX - 1);
}
*/


// Full Alter 3
bool isFullQueue(Queue Q) {
    return ((Q.tail + 1) % MAX == Q.head);
}


// enqueue

/* enqueue Alter 1 
void enqueue(Queue &Q, infotype x) {

    if(isFullQueue(Q) == true) {
        cout << "queue is full!\n";
    }else{
        if (isEmptyQueue(Q) == true) {
            Q.head = 0;
            Q.tail = 0;
        }else{
            Q.tail++;
        }
        Q.info[Q.tail] = x;
    }

}
*/

/* enqueue Alter 2
void enqueue(Queue &Q, infotype x) {
    if (isEmptyQueue(Q)) {
        Q.head = 0;
        Q.tail = 0;
        Q.info[Q.tail] = x;
    }else if (Q.tail == MAX - 1) {
        if (Q.head == 0) {
            cout << "queue is full!\n";
        }else{
            int j = 0;
            for (int i = Q.head; i <= Q.tail; i++) {
                Q.info[j] = Q.info[i];
                j++;
            }
            Q.tail -= Q.head;
            Q.head = 0;
            Q.tail++;
            Q.info[Q.tail] = x;
        }
    }else{
        Q.tail++;
        Q.info[Q.tail] = x;
    }
}
*/

// enqueue Alter 3
void enqueue(Queue &Q, infotype x) {
    if (isFullQueue(Q)) {
        cout << "queue is full!\n";
    }else{
        if (isEmptyQueue(Q)) {
            Q.head = 0;
            Q.tail = 0;
        }else{
            Q.tail = (Q.tail + 1) % MAX;
        }
        Q.info[Q.tail] = x;
    }
}


// deqeueue 

/* dequeue ALter 1 
infotype dequeue(Queue &Q) {
    if(isEmptyQueue(Q) == true) {
        cout << "empty queue\n";
        return -1;
    }
    infotype val = Q.info[Q.head];

    if (Q.head == Q.tail) {
        Q.head = -1; 
        Q.tail = -1;
    }else{
        for (int i = Q.head; i < Q.tail; i++) {
            Q.info[i] = Q.info[i+1];
        }
        Q.tail--;
    }    
    return val;
}
*/

/* dequeue Alter 2
infotype dequeue(Queue &Q) {
    if(isEmptyQueue(Q) == true) {
        cout << "empty queue\n";
        return -1;
    }
    infotype val = Q.info[Q.head];

    if (Q.head == Q.tail) {
        Q.head = -1; 
        Q.tail = -1;
    }else{
        Q.head++;
    }
    return val;
}
*/

// dequeue Alter 3
infotype dequeue(Queue &Q) {
    if (isEmptyQueue(Q)) {
        cout << "empty queue\n";
        return -1;
    }
    infotype val = Q.info[Q.head];
    if (Q.head == Q.tail) {
        Q.head = -1;
        Q.tail = -1;
    }else{
        Q.head = (Q.head + 1) % MAX;
    }

    return val;
}


// printQueue

/* printInfo ALter 1 & 2 
void printInfo(Queue Q) {
    
    if (isEmptyQueue(Q) == true) {
        cout << "-1 - -1  | empty queue\n";
    }else{
        cout << Q.head << " - " << Q.tail << "    | ";
        for (int i = Q.head; i <= Q.tail; i++) {
            cout << Q.info[i];
            if (i < Q.tail) {
                cout << " ";
            }
        }
        cout << endl;
    }

}
*/

// printInfo ALter 3
void printInfo(Queue Q) {
    
    if (isEmptyQueue(Q) == true) {
        cout << "-1 - -1  | empty queue\n";
    }else{
        cout << Q.head << " - " << Q.tail << "    | ";
        int i = Q.head;
        while (true) {
            cout << Q.info[i];
            if (i == Q.tail) {
                break;;
            }
            cout << " ";
            i = (i + 1) % MAX;
        }
        cout << endl;    
    }
}