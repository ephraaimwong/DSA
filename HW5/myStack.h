/**
 * @file myStack.h
 * @author iampo (3452838+ephraaimwong@users.noreply.github.com)
 * @brief 
 * @version 0.1
 * @date 2024-03-28
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <iostream>
/**
 * @brief Stack data Structure
 * 
 * Class provides basic stack operations like push, pop, top and isEmpty.
 * 
 * @tparam Type Type of element stored in stack
 */
template <class Type>
class myStack {
public:
    myStack();
    myStack(const myStack<Type>&);
    const myStack<Type>& operator=(const myStack<Type>&);
    ~myStack();
    void push(const Type&);
    void pop();
    Type top() const;
    bool isEmpty() const;

private:
    struct node {
        Type item;
        node* next;
    };
    node* topOfMyStack;
};
/**
 * @brief Default Constructor: Construct a new myStack<Type>::myStack object
 * 
 * @tparam Type Type of element stored in stack
 */
template<class Type>
myStack<Type>::myStack() : topOfMyStack(nullptr) {}

/**
 * @brief Deep Copy Constructor: Construct a new my Stack<Type>::my Stack object
 * 
 * @tparam Type Type of element stored in stack
 * @param copy Stack to be copied
 */
template<class Type>
myStack<Type>::myStack(const myStack<Type>& copy) {
    if (copy.topOfMyStack == nullptr) { topOfMyStack = nullptr; return; }// nothing to copy
    //deep copy
    topOfMyStack = new node{ copy.topOfMyStack->item,nullptr }; // create new node with next pointer set to nullptr
    node* curr = topOfMyStack; // curr points to topOfMyStack
    node* currCopy = copy.topOfMyStack->next; //currCopy points to topOfMyStack.next
    while (currCopy != nullptr) { //while not at bottom of stack
        curr->next = new node(currCopy->item,nullptr); // create new node in copied stack with next pointer set to nullptr
        curr = curr->next; //move to next node in copied stack
        currCopy = currCopy->next; //move to next node in original stack
    }
}
/**
 * @brief Assignment operator overload. Assigns the contents of one stack to another.
 * 
 * @tparam Type The type of elements stored in the stack
 * @param rhs The stack to be assigned
 * @return A reference to the assigned stack

 */
template<class Type>
const myStack<Type>& myStack<Type>::operator=(const myStack<Type>& rhs) {
    if (this == &rhs) { return *this; } //self assignment check
    while (!isEmpty()) { pop(); } //clear current content
    if (rhs.topOfMyStack == nullptr) { topOfMyStack = nullptr; return *this;} // if rhs is empty, set topOfMyStack to nullptr and return
    //deep copy of rhs to this stack
    topOfMyStack = new node{ rhs.topOfMyStack->item,nullptr }; // copy top node
    node* curr = topOfMyStack; // pointer to iterate this stack
    node* currCopy = rhs.topOfMyStack->next; // pointer to iterate rhs stack
    while (currCopy != nullptr) { // while not at bottom of rhs
        curr->next = new node(currCopy->item,nullptr);  // copy corresponding rhs node data
        curr = curr->next; // iterate to next node in this stack
        currCopy = currCopy->next; // iterate to next node in rhs stack
    }
    return *this; // reference to this stack
}
/**
 * @brief Destructor: Destroy the myStack<Type>::myStack object
 * 
 * @tparam Type Type of element stored in stack
 */
template<class Type>
myStack<Type>::~myStack(){
    while (!isEmpty()) { pop(); } //pop each element in stack till empty
}
/**
 * @brief Push element on top of stack
 * 
 * @tparam Type Type of element stored in stack
 * @param insert Element to insert
 */
template<class Type>
void myStack<Type>::push(const Type& insert) {
    node* temp = new node{ insert, topOfMyStack }; // new node with insert data and pointing to topOfMyStack as next node
    topOfMyStack = temp; //update topOfMyStack to inserted node
}
/**
 * @brief Removes head element of stack
 * 
 * @tparam Type Type of element stored in stack
 */
template<class Type>
void myStack<Type>::pop() {
    if (!isEmpty()) { //while stack not empty
        node* curr = topOfMyStack; 
        topOfMyStack = topOfMyStack->next; //reassign topOfMyStack to 2nd top
        delete curr; // delete top 
    }
}
/**
 * @brief Returns top element of stack
 * 
 * If stack empty, returns default Type() object
 * 
 * @tparam Type Type of element stored in stack
 * @return Top of Stack or default Type() object 
 */
template<class Type>
Type myStack<Type>::top() const {
    if (!isEmpty()) { return topOfMyStack->item; }
    return Type();
}
/**
 * @brief Check if stack is empty
 * 
 * @tparam Type Type of element stored in stack
 * @return bool value  
 */
template<class Type>
bool myStack<Type>::isEmpty() const {
    return topOfMyStack == nullptr; // if stack is empty, topofmystack == nullptr; if stack !empty, topofmystack != nullptr
}
