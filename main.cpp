#include <iostream>
#include "Linked_list.cpp"
#include "stack.cpp"


using namespace std;

int main() {
    Stack s;

    // Check if stack is empty
    cout << "Is stack empty? " << (s.is_Empty() ? "Yes" : "No") << "\n";

    // Push elements onto the stack
    s.push(10);
    s.push(20);
    s.push(30);
    cout << "Inserted 10, 20, 30 into the stack.\n";

    // Get top element
    cout << "Top element: " << s.top() << "\n";

    // Pop an element
    cout << "Popped element: " << s.pop() << "\n";

    // Get top element after pop
    cout << "Top element after pop: " << s.top() << "\n";

    // Compute and display average of stack elements
    cout << "Average of stack elements: " << s.average() << "\n";

    return 0;
}

