#include <iostream>
using namespace std;
//class for creating nodes on list
class Node {
public:
	int data;
	Node* next;


	// For Default constructor
	Node() {
		data = 0;
		next = nullptr;

	}

	//Overloaded Constructor
	Node(int data) {
		this->data = data;
		this->next = nullptr;
	}
};
//implmentation of singly linked list
class Linked_list {
	Node* head;

	public : 
		int num_items = 0;

	//For default contstructor
	Linked_list() {
		head = nullptr;
	}

	//destrucor
	~Linked_list(){
		while (head != nullptr) {
			Node* temp = head;
			head = head->next;
			delete temp;
		}
	}

	//Inserting node at start of list
	void push_front(int data) {

		//New node
		Node* newnode = new Node(data); //create memory for new pointer

		//if head is null it becomes the new head
		if (head == nullptr) {
			head = newnode;
			num_items++;
			return;
		}

		newnode->next = this->head;
		this->head = newnode;
		num_items++;
	}

	//add at the back
	void push_back(int data) {
		Node* newnode = new Node(data);

		if (head == nullptr) {
			head = newnode;
			num_items++;
				return;
		}
		//traverse the list
		Node* current = head;
		while (current->next != nullptr) {
			current = current->next;
		}

		//add node at end
		current->next = newnode;
		num_items++;
	}
	//remove end of the list
	void pop_back(int data) {
		//if empty do nothing
		if (head == nullptr)
			return;

		//if there is one node
		if (head->next == nullptr) {
			delete head;
			head = nullptr;
			num_items--;

		}

		//traverse to second to last
		Node* current = head;
		while (current->next->next != nullptr) {
			current = current->next;
		}

		//delete last node
		delete current->next;
		current->next = nullptr;
		num_items--;
	}
	//display the first element
	void front() {
		if (head == nullptr) {
			cout << "List is empty" << endl;
			return;
		}
		cout << head->data << endl;
	}
	//display the back element
	void back() {
		if (head == nullptr) {
			cout << "List is Empty" << endl;
			return;
		}

		//traverse to end of list
		Node* current = head;
		while (current->next != nullptr) {
			current = current->next;
		}
		cout << current->data << endl;

	}
	//see if the list is empty
	bool empty() {
		return head = nullptr;

	}
	//insert at a specified index 
	void insert(size_t index, int item){

		//if index is bigger than size add to end
		if (index >= num_items) {
			push_back(item);
			return;
		}

		//if inserting at beginning
		if (index == 0) {
			push_front(item);
			return;
		}
		//Create new node for item
		Node* newnode = new Node(item);

		//Traverse to one before insertion index
		Node* current = head;
		for (size_t i = 0; i < index; i++) {
			current = current->next;
		}

		//Insert node 
		newnode->next = current->next;
		current->next = newnode;
		num_items++;

	}
	//remove item at index and returrn if sucessful/or out of bounds
	bool remove(size_t index) {
		//index validation
		if (index >= num_items) {
			return false;
		}
		//removing first node
		if (index == 0) {
			Node* temp = head;
			head = head->next;
			delete temp;
			num_items--;
			return true;
		}

		//traverse tone before index
		Node* current = head;
		for (size_t i = 0; i < index - 1; i++) {
			current = current->next;
		}

		//remove the node 
		Node* temp = current->next; 
		current->next = temp->next; 
		delete temp;
		num_items--;

		return true; 

	}
	//find item in list, return size if not found
	size_t find(int item){
		Node* current = head;
		size_t position = 0;

		while (current != nullptr) {
			if (current->data == item) {
				return position;
			}
			current = current->next;
			position++;
		}

		return num_items;

	}

	//print the entire list
	void print() {
		Node* current = head;
		while (current != nullptr) {
			cout << current->data << "";
			current = current->next;
		}
		cout << endl;
	}
};
