/*******************************************************************************
** Author: Patrick Armitage
** Date: 02/12/2016
** Description: Queue methods file which defines the methods of the
** Queue class that were prototyped within the Queue header file
*******************************************************************************/
#include <iostream>

#include "Queue.hpp"

using std::cout;
using std::endl;

/*----------------------------------------------------------------------------*/
/*
    Function Name: Queue
    Function Parameters: data integer
    What the function does: sets the current queue item pointer to NULL, and
                            adds a new queue item to the queue
*/
Queue::Queue(int item) {
    setCurrentItem(NULL);
    add(item);
}

/*----------------------------------------------------------------------------*/
/*
    Function Names: setCurrentItem, getCurrentItem
    Functions' Parameters: setter receives data integer param for queue item
    What the functions do: getter and setter which act as public options to
                           read/write the Queue class's private queueItem
*/
void Queue::setCurrentItem(QueueItem *item) {
    currentItem = item;
}

QueueItem *Queue::getCurrentItem() {
    return currentItem;
}

/*----------------------------------------------------------------------------*/
/*
    Function Name: add
    Function Parameters: data integer
    What the function does: initializes a new QueueItem struct, settings its
                            next and previous queue items to NULL, and its data
                            to the provided data integer.  Then gets the current
                            queue item; if it is NULL (queue empty), sets the
                            newly instantiated item as current item and returns.
                            Else, recurses through each next item in the queue
                            until the last item is found and sets the newly
                            instantiated queue item as the last item's next item
*/
void Queue::add(int item) {
    QueueItem *queueItem = new QueueItem;
    queueItem->nextItem = NULL;
    queueItem->previousItem = NULL;
    queueItem->someData = item;

    QueueItem *currItem = getCurrentItem();
    QueueItem *lastItem = currItem;
    if (currItem == NULL) {
        setCurrentItem(queueItem);
    } else {
        while (lastItem->nextItem != NULL) {
            lastItem = lastItem->nextItem;
        }

        lastItem->nextItem = queueItem;
        queueItem->previousItem = lastItem;
    }

    cout << "Added " << queueItem->someData << " to the Queue!" << endl;
    if (queueItem->previousItem == NULL) {
        cout << "There is no previous item on the Queue." << endl;
    } else {
        cout << "The previous item in the Queue is " << queueItem->previousItem->someData << endl;
    }
}

/*----------------------------------------------------------------------------*/
/*
    Function Name: remove
    Function Parameters: N/A
    What the function does: gets the current queue item and the next item from
                            the current item, then sets the next item as the new
                            current item, deleting the old current item and
                            returning its data integer
*/
int Queue::remove() {
    QueueItem *currItem = getCurrentItem();
    QueueItem *nextItem = currItem->nextItem;
    setCurrentItem(nextItem);

    cout << "Removed the value " << currItem->someData << " from the Queue!" << endl;
    QueueItem *newCurrItem = getCurrentItem();
    if (newCurrItem != NULL) {
        cout << "The new item in the front of the Queue is " << newCurrItem->someData << endl;
        if (newCurrItem->nextItem == NULL) {
            cout << "There is no next item on the Queue." << endl;
        } else {
            cout << "The next item in the Queue is " << newCurrItem->nextItem->someData << endl;
        }
    } else {
        cout << "There is no item in the Queue now except for NULL!!" << endl;
    }

    int data = currItem->someData;
    delete currItem;
    return data;
}
