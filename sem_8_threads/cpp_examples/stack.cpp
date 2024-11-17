#include <iostream>
#include <thread>
#include <mutex>
#include <atomic>
 
template<typename T>
struct Node
{
    T data;
    Node* next;
    Node(const T& data) : data(data), next(nullptr) {}
};
 
template<typename T>
class Stack
{
    std::atomic<Node<T>*> head;
public:
  
  
void push(const T& data) {
	
	Node* new_node = new Node(data);

	new_node->next = head;
	head = new_node;

}



	



void push(const T& data) {
        Node<T>* new_node = new Node<T>(data);
 
        // put the current value of head into new_node->next
        new_node->next = head.load();
 
        // now make new_node the new head, but if the head
        // is no longer what's stored in new_node->next
        // (some other thread must have inserted a node just now)
        // then put that new head into new_node->next and try again
        while (!head.compare_exchange_weak(new_node->next, new_node))
            ; // the body of the loop is empty
    }
};
 
int main()
{
    Stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
}

