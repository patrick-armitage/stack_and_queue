/*******************************************************************************
** Author: Patrick Armitage
** Date: 02/12/2016
** Description: Queue class prototype which defines the QueueItem struct,
** getters and setters, the constructor, and the add and remove item functions
*******************************************************************************/

#ifndef QUEUE_HPP
#define QUEUE_HPP

struct QueueItem {
    QueueItem *nextItem;
    QueueItem *previousItem;
    int someData;
};

class Queue {
 private:
    QueueItem *currentItem;
 public:
    Queue(int item);
    QueueItem *getCurrentItem();
    void setCurrentItem(QueueItem *item);
    void add(int item);
    int remove();
};

#endif
