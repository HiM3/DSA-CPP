#include <iostream>
using namespace std;


class Stack {
protected:
    int top;
    int size;
    int* arr;

public:
    Stack(int s) {
        size = s;
        arr = new int[size];
        top = -1;
    }

    virtual void push(int value) {
        if (isFull()) {
            cout << "Stack is full! Cannot push " << value << endl;
        } else {
            arr[++top] = value;
            cout << value << " pushed into stack." << endl;
        }
    }

    virtual int pop() {
        if (isEmpty()) {
            cout << "Stack is empty! Cannot pop." << endl;
            return -1;
        } else {
            cout << arr[top] << " popped from stack." << endl;
            return arr[top--];
        }
    }

    int topElement() {
        if (!isEmpty()) {
            return arr[top];
        } else {
            cout << "Stack is empty!" << endl;
            return -1;
        }
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == size - 1;
    }

    virtual ~Stack() {
        delete[] arr;
    }
};

class AdvancedStack : public Stack {
public:
    AdvancedStack(int s) : Stack(s) {}

    void push(int value) override {
        cout << "[AdvancedStack] Trying to push: " << value << endl;
        Stack::push(value);
    }

    int pop() override {
        cout << "[AdvancedStack] Trying to pop..." << endl;
        return Stack::pop();
    }
};

int main() {
    int stackSize;
    cout << "Enter stack size: ";
    cin >> stackSize;

    AdvancedStack s(stackSize);

    int choice, value;

    do {
        cout << "\nMenu:\n1. Push\n2. Pop\n3. Display Top\n4. Check if Empty\n5. Check if Full\n6. Exit\nEnter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to push: ";
                cin >> value;
                s.push(value);
                break;
            case 2:
                s.pop();
                break;
            case 3:
                cout << "Top element: " << s.topElement() << endl;
                break;
            case 4:
                cout << (s.isEmpty() ? "Stack is empty." : "Stack is not empty.") << endl;
                break;
            case 5:
                cout << (s.isFull() ? "Stack is full." : "Stack is not full.") << endl;
                break;
            case 6:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice!" << endl;
        }
    } while (choice != 6);

    return 0;
}
