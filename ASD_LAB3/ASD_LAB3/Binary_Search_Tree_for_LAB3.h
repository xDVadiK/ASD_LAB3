#pragma once

#include <iostream>
#include "Iterator_for_LAB3.h"

using namespace std;

// Class Binary Search Tree
class Binary_Search_Tree
{
private:

    // Binary tree element class
    class Element_tree
    {
    public:

        int key; // Key
        Element_tree* left_node; // Pointer to the left descendant
        Element_tree* right_node; // Pointer to the right descendant

        // Constructor of the binary search tree element class
        Element_tree(int key = 0, Element_tree* left_node = nullptr, Element_tree* right_node = nullptr)
        {
            this->key = key;
            this->left_node = left_node;
            this->right_node = right_node;
        }
        // The destructor of the binary search tree element class
        ~Element_tree()
        {
            key = 0;
            left_node = nullptr;
            right_node = nullptr;
        };

    };

    size_t size_tree; // Tree size
    Element_tree* root_node; // Pointer to the root node of the tree

public:

    // Constructor of the binary search tree class
    Binary_Search_Tree()
    {
        root_node = nullptr;
        size_tree = 0;
    }
    // The destructor of the binary search tree class
    ~Binary_Search_Tree()
    {
        clear_tree();
        root_node = nullptr;
        size_tree = 0;
    };

    size_t get_size_tree(); // Getting the tree size
    void clear_tree(); // Deleting all tree elements

    bool contains(int); // Search for an element in the tree by key
    void insert(int); // Adding an element to the tree by key.  Works for O(logn)
    void remove(int); // Deleting a tree element by key

    Iterator* create_dft_iterator(); // Ñreating an iterator that implements a direct traversal in depth (depth - first traverse)
    Iterator* create_bft_iterator(); // Ñreating an iterator that implements breadth-first traversal methods (breadth - first traverse)

    // Getting the root element of the tree
    Element_tree* get_root_node() 
    {
        if (get_size_tree() != 0)
        {
            return root_node;
        }
        else throw domain_error("Tree is empty");
    }; 

    // Getting the left child of the root element of the tree
    Element_tree* get_root_node_left() 
    {
        if (get_root_node() != nullptr)
        {
            return root_node->left_node;
        }
        else throw domain_error("Tree is empty");
    }

    // Getting the right child of the root element of the tree
    Element_tree* get_root_node_right()
    {
        if (get_root_node() != nullptr)
        {
            return root_node->right_node;
        }
        else throw domain_error("Tree is empty");
    }

    // Class Stack
    class Stack
    {
        // Class Stack element
        class Stack_element
        {
        public:

            Element_tree* data; // Pointer to the node of the binary search tree
            Stack_element* next; // Pointer to the next stack element

            // Constructor of the stack element class
            Stack_element(Element_tree* data = nullptr, Stack_element* next = nullptr)
            {
                this->data = data;
                this->next = next;
            };
            // Stack element class destructor
            ~Stack_element() 
            {
                data = nullptr;
                next = nullptr;
            }
        };

        Stack_element* head; // Pointer to the beginning of the stack
        size_t size_stack; // Stack Size

    public:

        // Stack ñlass ñonstructor
        Stack()
        {
            head = nullptr;
            size_stack = 0;
        };
        // Destructor for the stack class
        ~Stack()
        {
            clear_stack();
        };

        // Checking the stack for emptiness
        bool stack_is_empty()
        {
            return size_stack == 0;
        };

        // Getting the stack size
        int get_size_stack()
        {
            return size_stack;
        };

        // Adding an element to the top of the stack
        void push(Element_tree* data)
        {
            Stack_element* new_element = new Stack_element(data);
            if (stack_is_empty())
            {
                head = new_element;
                size_stack++;
            }
            else
            {
                new_element->next = head;
                head = new_element;
                size_stack++;
            }
        };

        // Removing an element from the stack
        Element_tree* pop()
        {
            if (!stack_is_empty())
            {
                Element_tree* element;
                Stack_element* delete_element;
                if (get_size_stack() == 1)
                {
                    element = head->data;
                    delete head;
                    head = nullptr;
                    size_stack = 0;
                    return element;
                }
                else
                {
                    element = head->data;
                    delete_element = head;
                    head = head->next;
                    delete delete_element;
                    size_stack--;
                    return element;
                }
            }
            else return nullptr;
        };

        // Clearing the stack
        void clear_stack()
        {
            if (!stack_is_empty())
            {
                while (!stack_is_empty())
                {
                    pop();
                }
                head = nullptr;
                size_stack = 0;
            }
        }

        // Overloading the output operator for the stack
        friend ostream& operator<<(ostream& stream, const Stack& stack)
        {
            if (stack.head != nullptr)
            {
                Stack::Stack_element* current = stack.head;
                while (current != nullptr)
                {
                    stream << current->data->key << " ";
                    current = current->next;
                }
                return stream;
            }
            else return stream << "Stack is empty\n\n";
        };
    };

    // Class Queue
    class Queue
    {
        // Class Queue element
        class Queue_element
        {
        public:

            Element_tree* data; // Pointer to the node of the binary search tree
            Queue_element* next; // Pointer to the next queue element

            // Constructor of the queue element class
            Queue_element(Element_tree* data = nullptr, Queue_element* next = nullptr)
            {
                this->data = data;
                this->next = next;
            }
            // The destructor of the queue element class
            ~Queue_element()
            {
                data = nullptr;
                next = nullptr;
            }
        };

        Queue_element* head; // Pointer to the beginning of the queue
        Queue_element* tail; // Pointer to the end of the queue
        size_t size_queue; // Queue size

    public:

        // Queue Class Constructor
        Queue()
        {
            head = nullptr;
            tail = nullptr;
            size_queue = 0;
        }
        // Queue class destructor
        ~Queue()
        {
            clear_queue();
        };

        // Checking the queue for emptiness
        bool queue_is_empty()
        {
            return size_queue == 0;
        }

        // Getting the queue size
        int get_size_queue()
        {
            return size_queue;
        }

        // Adding an element to the queue
        void enqueue(Element_tree* data)
        {
            Queue_element* current = new Queue_element(data);
            if (queue_is_empty())
            {
                head = current;
                tail = current;
                size_queue++;
            }
            else
            {
                tail->next = current;
                tail = current;
                size_queue++;
            }
        };

        // Removing an element from the queue
        Element_tree* dequeue()
        {
            if (!queue_is_empty())
            {
                Element_tree* element;
                Queue_element* delete_element;
                if (size_queue == 1)
                {
                    element = head->data;
                    delete head;
                    head = nullptr;
                    tail = nullptr;
                    size_queue = 0;
                    return element;
                }
                else
                {
                    element = head->data;
                    delete_element = head;
                    head = head->next;
                    delete delete_element;
                    size_queue--;
                    return element;
                }
            }
            else return nullptr;
        }

        // Clearing the queue
        void clear_queue()
        {
            if (!queue_is_empty())
            {
                while (!queue_is_empty())
                {
                    dequeue();
                }
                head = nullptr;
                tail = nullptr;
                size_queue = 0;
            }
        }

        // Overloading the output operator for the queue
        friend ostream& operator<<(ostream& stream, const Queue& queue)
        {
            if (queue.head != nullptr)
            {
                Queue::Queue_element* current = queue.head;
                while (current != nullptr)
                {
                    stream << current->data->key << " ";
                    current = current->next;
                }
                return stream;
            }
            else return stream << "Queue is empty\n\n";
        };
    };

    // Direct bypass in depth
    class Depth_first_traverse_iterator : public Iterator
    {

        Element_tree* current; // Pointer to an element of the binary search tree
        Stack stack; // Creating a stack to implement tree traversal in depth

    public:

        // Constructor of the tree traversal class in depth
        Depth_first_traverse_iterator(Element_tree* root_node)
        {
            current = root_node;
            stack.push(current);
        }
        // The destructor of the tree traversal class in depth
        ~Depth_first_traverse_iterator()
        {
            current = nullptr;
            stack.clear_stack();
        }

        int next() override;
        bool has_next() override;

    };

    // Breadth traversal
    class Breadth_first_traverse_iterator : public Iterator
    {

        Element_tree* current; // Pointer to an element of the binary search tree 
        Queue queue; // Creating a queue to implement a tree-wide traversal

    public:

        // Constructor of the tree-wide traversal class
        Breadth_first_traverse_iterator(Element_tree* root_node)
        {
            current = root_node;
            queue.enqueue(current);
        };
        // The destructor of the tree-wide traversal class
        ~Breadth_first_traverse_iterator() 
        {
            current = nullptr;
            queue.clear_queue();
        };

        int next() override;
        bool has_next() override;
    };
};

// Getting the tree size
size_t Binary_Search_Tree::get_size_tree()
{
    return size_tree;
}

// Deleting all tree elements
void Binary_Search_Tree::clear_tree()
{
    if (get_size_tree() != 0)
    {
        while (get_size_tree() != 0)
        {
            remove(root_node->key);
        }
        root_node = nullptr;
        size_tree = 0;
    }
}

// Search for an element in the tree by key
bool Binary_Search_Tree::contains(int key)
{
    if (get_size_tree() != 0)
    {
        bool Element_found(false);
        Element_tree* current_element = root_node;
        while (!Element_found)
        {
            if (key == current_element->key)
            {
                return true;
            }
            else if (key > current_element->key)
            {
                current_element = current_element->right_node;
            }
            else if (key < current_element->key)
            {
                current_element = current_element->left_node;
            }
            if (current_element == nullptr)
            {
                return false;
            }
        }
    }
    else throw domain_error("The element cannot be found because the tree is empty");
};

// Adding an element to the tree by key.  Works for O(logn)
void Binary_Search_Tree::insert(int key)
{
    if (get_size_tree() != 0)
    {
        bool New_element_added(false);
        Element_tree* current_element = root_node;
        while (!New_element_added)
        {
            if (key >= current_element->key && current_element->right_node == nullptr)
            {
                current_element->right_node = new Element_tree(key);
                New_element_added = true;
                size_tree++;
            }
            else if (key < current_element->key && current_element->left_node == nullptr)
            {
                current_element->left_node = new Element_tree(key);
                New_element_added = true;
                size_tree++;
            }
            else if (key >= current_element->key)
            {
                current_element = current_element->right_node;
            }
            else if (key < current_element->key)
            {
                current_element = current_element->left_node;
            }
        }
    }
    else
    {
        root_node = new Element_tree(key);
        size_tree++;
    }
};

// Deleting a tree element by key
void Binary_Search_Tree::remove(int key)
{
    if (contains(key))
    {
        bool Element_removed(false);
        Element_tree* current_element = root_node;
        Element_tree* previous_element = nullptr;
        while (!Element_removed)
        {
            if (key == current_element->key)
            {
                // The tree element has no descendants
                if (current_element->right_node == nullptr && current_element->left_node == nullptr)
                {
                    if (current_element == root_node)
                    {
                        delete current_element;
                        root_node = nullptr;
                        Element_removed = true;
                        size_tree = 0;
                    }
                    else
                    {
                        if (previous_element->right_node == current_element)
                        {
                            previous_element->right_node = nullptr;
                        }
                        else previous_element->left_node = nullptr;
                        delete current_element;
                        Element_removed = true;
                        size_tree--;
                    }
                }
                // The tree element has no right descendant
                else if (current_element->right_node == nullptr)
                {
                    if (current_element == root_node)
                    {
                        root_node = current_element->left_node;
                        delete current_element;
                        Element_removed = true;
                        size_tree--;
                    }
                    else
                    {
                        if (previous_element->right_node == current_element)
                        {
                            previous_element->right_node = current_element->left_node;
                        }
                        else previous_element->left_node = current_element->left_node;
                        delete current_element;
                        Element_removed = true;
                        size_tree--;
                    }
                }
                // The tree element has no left descendant
                else if (current_element->left_node == nullptr)
                {
                    if (current_element == root_node)
                    {
                        root_node = current_element->right_node;
                        delete current_element;
                        Element_removed = true;
                        size_tree--;
                    }
                    else
                    {
                        if (previous_element->left_node == current_element)
                        {
                            previous_element->left_node = current_element->right_node;
                        }
                        else previous_element->right_node = current_element->right_node;
                        delete current_element;
                        Element_removed = true;
                        size_tree--;
                    }
                }
                // The left descendant of the tree element has no right descendant
                else if (current_element->left_node->right_node == nullptr)
                {
                    if (current_element == root_node)
                    {
                        current_element->left_node->right_node = current_element->right_node;
                        root_node = current_element->left_node;
                        delete current_element;
                        Element_removed = true;
                        size_tree--;
                    }
                    else
                    {
                        if (previous_element->left_node == current_element)
                        {
                            previous_element->left_node = current_element->left_node;
                        }
                        else previous_element->right_node = current_element->left_node;
                        current_element->left_node->right_node = current_element->right_node;
                        delete current_element;
                        Element_removed = true;
                        size_tree--;
                    }
                }
                // The right descendant of the tree element has no left descendant
                else if (current_element->right_node->left_node == nullptr)
                {
                    if (current_element == root_node)
                    {
                        current_element->right_node->left_node = current_element->left_node;
                        root_node = current_element->right_node;
                        delete current_element;
                        Element_removed = true;
                        size_tree--;
                    }
                    else
                    {
                        if (previous_element->left_node == current_element)
                        {
                            previous_element->left_node = current_element->right_node;
                        }
                        else previous_element->right_node = current_element->right_node;

                        current_element->right_node->left_node = current_element->left_node;
                        delete current_element;
                        Element_removed = true;
                        size_tree--;
                    }
                }
                // A tree element and its descendants have all descendants
                else
                {
                    Element_tree* delete_item = current_element->left_node;
                    while (delete_item->right_node->right_node != nullptr)
                    {
                        delete_item = delete_item->right_node;
                    }
                    current_element->key = delete_item->right_node->key;
                    delete delete_item->right_node;
                    delete_item->right_node = nullptr;
                    Element_removed = true;
                    size_tree--;
                }
            }
            else if (key > current_element->key)
            {
                previous_element = current_element;
                current_element = current_element->right_node;
            }
            else if (key < current_element->key)
            {
                previous_element = current_element;
                current_element = current_element->left_node;
            }
        }
    }
    else throw domain_error("An element with such a key is missing in the tree");
}

// Creating an iterator of a direct tree traversal in depth
Iterator* Binary_Search_Tree::create_dft_iterator()
{
    if (get_size_tree() != 0)
    {
        return new Depth_first_traverse_iterator(root_node);
    }
    else throw domain_error("Binary Search Tree is empty");
}

// Processing of the current node by the algorithm of direct tree traversal in depth
int Binary_Search_Tree::Depth_first_traverse_iterator::next()
{
    if (has_next())
    {
        current = stack.pop();
        if (current->right_node != nullptr)
        {
            stack.push(current->right_node);
        }
        if (current->left_node != nullptr)
        {
            stack.push(current->left_node);
        }
        return current->key;
    }
    else throw domain_error("There are no tree elements to process");
};

// Checking for the presence of elements not bypassed by the iterator of the direct tree traversal in depth
bool Binary_Search_Tree::Depth_first_traverse_iterator::has_next()
{
    return !stack.stack_is_empty();
}

// Creating a tree-wide traversal iterator
Iterator* Binary_Search_Tree::create_bft_iterator()
{
    if (get_size_tree() != 0)
    {
        return new Breadth_first_traverse_iterator(root_node);
    }
    else throw domain_error("Binary Search Tree is empty");
}

// Processing of the current node by a tree-wide traversal algorithm
int Binary_Search_Tree::Breadth_first_traverse_iterator::next()
{
    if (has_next())
    {
        current = queue.dequeue();
        if (current->left_node != nullptr)
        {
            queue.enqueue(current->left_node);
        }
        if (current->right_node != nullptr)
        {
            queue.enqueue(current->right_node);
        }
        return current->key;
    }
    else throw domain_error("There are no tree elements to process");
}

// Checking for the presence of elements not bypassed by the iterator of traversing the tree in width
bool Binary_Search_Tree::Breadth_first_traverse_iterator::has_next()
{
    return !queue.queue_is_empty();
}