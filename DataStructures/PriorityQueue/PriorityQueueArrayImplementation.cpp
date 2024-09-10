// priority queue implementation using Arrays
#include <iostream>
using namespace std;
const int MAX_SIZE = 100;
class PriorityQueue {
private:
    int arr[MAX_SIZE];
    int front;
    int rear;
public:
    PriorityQueue(){
        front = -1;
        rear = -1;
    }
    bool isEmpty(){
        return (front == -1 && rear == -1);
    }
    bool isFull(){
        return (rear == MAX_SIZE-1);
    }

    void enqueue(int item){
        int pos;
        if(rear == MAX_SIZE-1){
            cout << "PriorityQueue is full ! " <<endl;
        }
        else {
            pos = rear;
            rear = rear+1;
            while(pos >=0 && arr[pos] >= item){
                arr[pos+1] = arr[pos];
                pos = pos -1;
            }
            arr[pos+1] = item;
            if(front = -1){
                front = front +1;
            }

        }

    }
    void dequeue(){
        if (isEmpty()){
            cout << "PriorityQueue is empty. Can't delete items." << endl;
        }else if (front == rear){
            front = rear = -1;
        }else{
            front++;
        }
    }
    int peek(){
        if (isEmpty()){
            cout << "PriorityQueue is empty." << endl;
            return -1;
        }else{
            return arr[front];
        }
    }
    void display(){
        if (isEmpty()){
            cout << "PriorityQueue is empty." << endl;
            return;
        }
        for (int i=front; i<=rear; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};
int main(){
    PriorityQueue pq;
    pq.enqueue(5);
    pq.enqueue(2);
    pq.enqueue(4);
    pq.enqueue(4);
    pq.display();
    cout << "Peek = " << pq.peek() << endl;
    pq.dequeue();
    pq.display();
    cout << "Peek = " << pq.peek() << endl;
    return 0;
}