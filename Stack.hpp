/*******************************************************************************
** Author: Patrick Armitage
** Date: 02/12/2016
** Description: Stack class prototype which defines the basic functionality for
** a stack, including the StackItem struct, the current stack item data member
** and its getter and setter, the constructor, and the add and remove item
** stack methods
*******************************************************************************/

#ifndef STACK_HPP
#define STACK_HPP

struct StackItem {
    StackItem *previousItem;
    int someData;
};

class Stack {
 private:
    StackItem *currentItem;
 public:
    Stack(int item);
    StackItem *getCurrentItem();
    void setCurrentItem(StackItem *item);
    void add(int item);
    int remove();
};

#endif
