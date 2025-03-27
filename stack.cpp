#include <iostream>
#include <vector>
using namespace std;
class Stack {
private:
	vector<int> stack;

public:

	//check if empty
	bool is_Empty() {
		return stack.empty();
	}


	//push onto stack
	void push(int value) {
		stack.push_back(value);

	}

	//pop last element off the stack
	int pop() {
		if (is_Empty()) {
			cout << "Stack Empty\n";
			return-1;
		}
		int value = stack.back();
		stack.pop_back();
		return value;
	}


	//get top element
	int top() {
		if (is_Empty()) {
			cout << "Stack is empty\n";
			return -1;

		}
		return stack.back();
	}

	double average() {
		if (is_Empty()) {
			cout << " Stack is empty cant get average\n";
			return 0.0;

		}
		int sum = 0;
		for (int num : stack) {
			sum += num;
		}
		return static_cast<double>(sum) / stack.size();
	}
};
