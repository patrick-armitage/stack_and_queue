#include <iostream>
#include "Stack.hpp"
#include "Queue.hpp"

using std::cin;
using std::cout;
using std::endl;

int getSelection();

int main() {
    int sel;
    sel = getSelection();

    while ((sel != 1) && (sel != 2)) {
        cout << "Whoops!  That isn't a valid selection.  Please try again." << endl;
        getSelection();
    }

    if (sel == 1) {
        int stackData[3];
        cout << "Okay!  Let's demo the Stack.  Please enter 3 numbers to push to the stack" << endl;
        cout << "Please enter your first number: ";
        cin >> stackData[0];
        if ((stackData[0] < 0) || (stackData[0] > 9999)) {
            cout << "Sorry, not a valid number!  I'll just put the number 5 in its place." << endl;
            stackData[0] = 5;
        }
        cout << "Please enter your second number: ";
        cin >> stackData[1];
        if ((stackData[1] < 0) || (stackData[1] > 9999)) {
            cout << "Sorry, not a valid number!  I'll just put the number 6 in its place." << endl;
            stackData[1] = 6;
        }
        cout << "Please enter your third number: ";
        cin >> stackData[2];
        if ((stackData[2] < 0) || (stackData[2] > 9999)) {
            cout << "Sorry, not a valid number!  I'll just put the number 7 in its place." << endl;
            stackData[2] = 7;
        }

        cout << endl << "Creating stack and adding first number." << endl;
        Stack *stack = new Stack(stackData[0]);

        cout << endl << "Okay now let's add second number!" << endl;
        stack->add(stackData[1]);

        cout << endl << "Great!  Let's add third number" << endl;
        stack->add(stackData[2]);

        cout << endl << "Now we've got the full Stack!  ;)";
        cout << "  Let's try popping the items now!" << endl << endl;
        int poppedItem;
        poppedItem = stack->remove();
        cout << "We just removed " << poppedItem << " from the Stack!" << endl << endl;
        poppedItem = stack->remove();
        cout << "We just removed " << poppedItem << " from the Stack!" << endl << endl;
        poppedItem = stack->remove();
        cout << "We just removed " << poppedItem << " from the Stack!" << endl << endl;

        cout << "And there you have it folks, FIRST IN, LAST OUT!!" << endl;
    } else if (sel == 2) {
        int queueData[3];
        cout << "Okay!  Let's demo the Queue.  Please enter 3 numbers to push to the queue" << endl;
        cout << "Please enter your first number: ";
        cin >> queueData[0];
        if ((queueData[0] < 0) || (queueData[0] > 9999)) {
            cout << "Sorry, not a valid number!  I'll just put the number 5 in its place." << endl;
            queueData[0] = 5;
        }
        cout << "Please enter your second number: ";
        cin >> queueData[1];
        if ((queueData[1] < 0) || (queueData[1] > 9999)) {
            cout << "Sorry, not a valid number!  I'll just put the number 6 in its place." << endl;
            queueData[1] = 6;
        }
        cout << "Please enter your third number: ";
        cin >> queueData[2];
        if ((queueData[2] < 0) || (queueData[2] > 9999)) {
            cout << "Sorry, not a valid number!  I'll just put the number 7 in its place." << endl;
            queueData[2] = 7;
        }

        cout << endl << "Creating queue and adding first number." << endl;
        Queue *queue = new Queue(queueData[0]);

        cout << endl << "Okay now let's add second number!" << endl;
        queue->add(queueData[1]);

        cout << endl << "Great!  Let's add third number" << endl;
        queue->add(queueData[2]);

        cout << endl << "We're all queued up!  ;)";
        cout << "  Let's try clearing the items now!" << endl << endl;
        int clearedItem;
        clearedItem = queue->remove();
        cout << "We just cleared " << clearedItem << " from the Queue!" << endl << endl;
        clearedItem = queue->remove();
        cout << "We just cleared " << clearedItem << " from the Queue!" << endl << endl;
        clearedItem = queue->remove();
        cout << "We just cleared " << clearedItem << " from the Queue!" << endl << endl;

        cout << "What now you crazy kids?! FIRST IN, FIRST OUT!!" << endl;
    }

    return 0;
}

int getSelection() {
    int selection;
    cout << "Welcome to Stack and Queue Demos.  Please select a data structure to demo:" << endl;
    cout << "[1] Stack, [2] Queue" << endl;
    cin >> selection;

    return selection;
}
