/*******************************************************************************
** Author: Patrick Armitage
** Date: 02/12/2016
** Description: Stack methods file which defines the methods of the
** Stack class that were prototyped within the Stack header file
*******************************************************************************/
#include <iostream>

#include "Stack.hpp"

using std::cout;
using std::endl;

/*----------------------------------------------------------------------------*/
/*
    Function Name: Stack
    Function Parameters: data integer
    What the function does: adds a new stack item to the stack
*/
Stack::Stack(int item) {
    add(item);
}

/*----------------------------------------------------------------------------*/
/*
    Function Names: setCurrentItem, getCurrentItem
    Functions' Parameters: setter receives data integer param for queue item
    What the functions do: getter and setter which act as public options to
                           read/write the Queue class's private queueItem
*/
void Stack::setCurrentItem(StackItem *item) {
    currentItem = item;
}

StackItem *Stack::getCurrentItem() {
    return currentItem;
}

/*----------------------------------------------------------------------------*/
/*
    Function Name: add
    Function Parameters: data integer
    What the function does: initializes a new StackItem struct, settings its
                            previous stack item to NULL, and its data
                            to the provided data integer.  Then gets the current
                            stack item and sets it as the current item.
*/
void Stack::add(int item) {
    StackItem *stackItem = new StackItem;
    StackItem *currItem = getCurrentItem();
    stackItem->previousItem = currItem;
    stackItem->someData = item;
    setCurrentItem(stackItem);
    cout << "Added " << getCurrentItem()->someData << " to the Stack!" << endl;
    if (getCurrentItem()->previousItem == NULL) {
        cout << "There is no previous item on the Stack." << endl;
    } else {
        cout << "The item below the top of the stack is " << getCurrentItem()->previousItem->someData << endl;
    }
}

/*----------------------------------------------------------------------------*/
/*
    Function Name: remove
    Function Parameters: N/A
    What the function does: gets the current stack item and the previos item from
                            the current item, then sets the previous item as the
                            new current item, deleting the old current item and
                            returning its data integer
*/
int Stack::remove() {
    StackItem *currItem = getCurrentItem();
    StackItem *prevItem = currItem->previousItem;

    setCurrentItem(prevItem);
    cout << "Popped the value " << currItem->someData << " from the Stack!" << endl;
    StackItem *newCurrItem = getCurrentItem();
    if (newCurrItem != NULL) {
        cout << "The new item on the top of the Stack is " << newCurrItem->someData << endl;
        if (newCurrItem->previousItem == NULL) {
            cout << "There is no previous item on the Stack." << endl;
        } else {
            cout << "The item below the top of the stack is " << newCurrItem->previousItem->someData << endl;
        }
    } else {
        cout << "There is no item on the Stack now except for NULL!!" << endl;
    }

    int data = currItem->someData;
    delete currItem;
    return data;
}
