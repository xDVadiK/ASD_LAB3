#include "pch.h"
#include "CppUnitTest.h"
#include "..\ASD_LAB3\Binary_Search_Tree_for_LAB3.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestforLAB3
{
	TEST_CLASS(UnitTestforLAB3)
	{
	public:
		
		Binary_Search_Tree* Tree; // Pointer to the binary search tree

		// Initializing a pointer to a binary search tree
		TEST_METHOD_INITIALIZE(INITIALIZE)
		{
			Tree = new Binary_Search_Tree();
		}

		// Clearing the pointer to the binary search tree
		TEST_METHOD_CLEANUP(CLEANUP)
		{
			delete Tree;
		}

		// Checking the search for an element in the tree by key, if the element is present in the tree
		TEST_METHOD(Contains_Element_Tree_Present)
		{
			Tree->insert(20);
			Tree->insert(10);
			Tree->insert(30);
			Iterator* bft_iterator = Tree->create_bft_iterator();
			stringstream output;
			while (bft_iterator->has_next())
			{
				output << bft_iterator->next() << " ";
			}
			Assert::IsTrue(output.str() == "20 10 30 ");
			Assert::IsTrue(Tree->contains(30) == true);
		}

		// Checking the search for an element in the tree by key, if the element is missing in the tree
		TEST_METHOD(Contains_Element_Tree_Missing)
		{
			Tree->insert(20);
			Tree->insert(10);
			Tree->insert(30);
			try
			{
				Iterator* bft_iterator = Tree->create_bft_iterator();
				stringstream output;
				while (bft_iterator->has_next())
				{
					output << bft_iterator->next() << " ";
				}
				Assert::IsTrue(output.str() == "20 10 30 ");
				Tree->contains(40);
			}
			catch (const domain_error error)
			{
				Assert::AreEqual("Binary Search Tree is empty", error.what());
			}
		}

		// Checking the search for an element in an empty tree by key
		TEST_METHOD(Contains_Element_Tree_Empty_Tree)
		{
			try
			{
				Iterator* bft_iterator = Tree->create_bft_iterator();
				stringstream output;
				while (bft_iterator->has_next())
				{
					output << bft_iterator->next() << " ";
				}
			}
			catch (const domain_error error)
			{
				Assert::AreEqual("Binary Search Tree is empty", error.what());
			}
			try
			{
				bool element = Tree->contains(40);
			}
			catch (const domain_error error)
			{
				Assert::AreEqual("The element cannot be found because the tree is empty", error.what());
			}
		}

		// Checking the addition of an element to an empty tree by key
		TEST_METHOD(Insert_Element_Tree_Empty_Tree) 
		{
			try
			{
				Iterator* bft_iterator = Tree->create_bft_iterator();
				stringstream output;
				while (bft_iterator->has_next())
				{
					output << bft_iterator->next() << " ";
				}
			}
			catch (const domain_error error)
			{
				Assert::AreEqual("Binary Search Tree is empty", error.what());
			}
			Assert::IsTrue(Tree->get_size_tree() == 0);
			Tree->insert(20);
			Assert::IsTrue(Tree->get_size_tree() != 0);
			Iterator* bft_iterator = Tree->create_bft_iterator();
			stringstream output;
			while (bft_iterator->has_next())
			{
				output << bft_iterator->next() << " ";
			}
			Assert::IsTrue(output.str() == "20 ");
			Assert::IsTrue(Tree->contains(20) == true);
			Assert::IsTrue(Tree->get_root_node()->key == 20);
		}

		// Checking the addition of an element to a non-empty tree by key
		TEST_METHOD(Insert_Element_Tree) 
		{
			Tree->insert(20);
			Tree->insert(10);
			Tree->insert(30);
			Iterator* bft_iterator = Tree->create_bft_iterator();
			stringstream output;
			while (bft_iterator->has_next())
			{
				output << bft_iterator->next() << " ";
			}
			Assert::IsTrue(output.str() == "20 10 30 ");
			Assert::IsTrue(Tree->get_size_tree() != 0);
			Tree->insert(40);
			bft_iterator = Tree->create_bft_iterator();
			stringstream output_after_insert;
			while (bft_iterator->has_next())
			{
				output_after_insert << bft_iterator->next() << " ";
			}
			Assert::IsTrue(output_after_insert.str() == "20 10 30 40 ");
			Assert::IsTrue(Tree->contains(40) == true);
		}

		// Checking the deletion of a missing element in the tree by key
		TEST_METHOD(Remove_Element_Tree_Missing) 
		{
			Tree->insert(20);
			Tree->insert(10);
			Tree->insert(30);
			Iterator* bft_iterator = Tree->create_bft_iterator();
			stringstream output;
			while (bft_iterator->has_next())
			{
				output << bft_iterator->next() << " ";
			}
			Assert::IsTrue(output.str() == "20 10 30 ");
			Assert::IsTrue(Tree->get_size_tree() != 0);
			try
			{
				Tree->remove(40);
			}
			catch (const domain_error error)
			{
				Assert::AreEqual("An element with such a key is missing in the tree", error.what());
			}
		}

		// Checking the deletion of a tree element that has no descendants by the key
		TEST_METHOD(Remove_Element_Tree_Without_Descendants) 
		{
			Tree->insert(20);
			Tree->insert(10);
			Tree->insert(30);
			Iterator* bft_iterator = Tree->create_bft_iterator();
			stringstream output;
			while (bft_iterator->has_next())
			{
				output << bft_iterator->next() << " ";
			}
			Assert::IsTrue(output.str() == "20 10 30 ");
			Assert::IsTrue(Tree->get_size_tree() == 3);
			Tree->remove(30);
			bft_iterator = Tree->create_bft_iterator();
			stringstream output_after_remove;
			while (bft_iterator->has_next())
			{
				output_after_remove << bft_iterator->next() << " ";
			}
			Assert::IsTrue(output_after_remove.str() == "20 10 ");
			Assert::IsTrue(Tree->get_size_tree() == 2);
		}

		// Checking the deletion of a tree element that does not have a right descendant by the key
		TEST_METHOD(Remove_Element_Tree_Without_Right_Descendant) 
		{
			Tree->insert(20);
			Tree->insert(10);
			Tree->insert(5);
			Tree->insert(30);
			Tree->insert(25);
			Tree->insert(40);
			Iterator* bft_iterator = Tree->create_bft_iterator();
			stringstream output;
			while (bft_iterator->has_next())
			{
				output << bft_iterator->next() << " ";
			}
			Assert::IsTrue(output.str() == "20 10 30 5 25 40 ");
			Assert::IsTrue(Tree->get_size_tree() == 6);
			Tree->remove(10);
			bft_iterator = Tree->create_bft_iterator();
			stringstream output_after_remove;
			while (bft_iterator->has_next())
			{
				output_after_remove << bft_iterator->next() << " ";
			}
			Assert::IsTrue(output_after_remove.str() == "20 5 30 25 40 ");
			Assert::IsTrue(Tree->get_size_tree() == 5);
		}

		// Checking the deletion of a tree element that does not have a left child by the key
		TEST_METHOD(Remove_Element_Tree_Without_Left_Descendant)
		{
			Tree->insert(20);
			Tree->insert(10);
			Tree->insert(15);
			Tree->insert(30);
			Tree->insert(25);
			Tree->insert(40);
			Iterator* bft_iterator = Tree->create_bft_iterator();
			stringstream output;
			while (bft_iterator->has_next())
			{
				output << bft_iterator->next() << " ";
			}
			Assert::IsTrue(output.str() == "20 10 30 15 25 40 ");
			Assert::IsTrue(Tree->get_size_tree() == 6);
			Tree->remove(10);
			bft_iterator = Tree->create_bft_iterator();
			stringstream output_after_remove;
			while (bft_iterator->has_next())
			{
				output_after_remove << bft_iterator->next() << " ";
			}
			Assert::IsTrue(output_after_remove.str() == "20 15 30 25 40 ");
			Assert::IsTrue(Tree->get_size_tree() == 5);
		}

		// Checking the deletion of a tree element whose left descendant has no right descendant, by key
		TEST_METHOD(Remove_Element_Tree_Left_Descendant_Without_Right) 
		{
			Tree->insert(20);
			Tree->insert(10);
			Tree->insert(5);
			Tree->insert(30);
			Tree->insert(25);
			Tree->insert(40);
			Iterator* bft_iterator = Tree->create_bft_iterator();
			stringstream output;
			while (bft_iterator->has_next())
			{
				output << bft_iterator->next() << " ";
			}
			Assert::IsTrue(output.str() == "20 10 30 5 25 40 ");
			Assert::IsTrue(Tree->get_size_tree() == 6);
			Tree->remove(20);
			bft_iterator = Tree->create_bft_iterator();
			stringstream output_after_remove;
			while (bft_iterator->has_next())
			{
				output_after_remove << bft_iterator->next() << " ";
			}
			Assert::IsTrue(output_after_remove.str() == "10 5 30 25 40 ");
			Assert::IsTrue(Tree->get_size_tree() == 5);
		}

		// Checking the deletion of a tree element whose right descendant has no left descendant, by the key
		TEST_METHOD(Remove_Element_Tree_Right_Descendant_Without_Left) 
		{
			Tree->insert(20);
			Tree->insert(10);
			Tree->insert(30);
			Tree->insert(5);
			Tree->insert(15);
			Tree->insert(40);
			Iterator* bft_iterator = Tree->create_bft_iterator();
			stringstream output;
			while (bft_iterator->has_next())
			{
				output << bft_iterator->next() << " ";
			}
			Assert::IsTrue(output.str() == "20 10 30 5 15 40 ");
			Assert::IsTrue(Tree->get_size_tree() == 6);
			Tree->remove(20);
			bft_iterator = Tree->create_bft_iterator();
			stringstream output_after_remove;
			while (bft_iterator->has_next())
			{
				output_after_remove << bft_iterator->next() << " ";
			}
			Assert::IsTrue(output_after_remove.str() == "30 10 40 5 15 ");
			Assert::IsTrue(Tree->get_size_tree() == 5);
		}

		// Checking the deletion of a tree element in which it and its descendants have all descendants, by key
		TEST_METHOD(Remove_Element_Tree_All_Descendants_Have_Descendants) 
		{
			Tree->insert(20);
			Tree->insert(10);
			Tree->insert(30);
			Tree->insert(5);
			Tree->insert(15);
			Tree->insert(25);
			Tree->insert(40);
			Iterator* bft_iterator = Tree->create_bft_iterator();
			stringstream output;
			while (bft_iterator->has_next())
			{
				output << bft_iterator->next() << " ";
			}
			Assert::IsTrue(output.str() == "20 10 30 5 15 25 40 ");
			Assert::IsTrue(Tree->get_size_tree() == 7);
			Tree->remove(20);
			bft_iterator = Tree->create_bft_iterator();
			stringstream output_after_remove;
			while (bft_iterator->has_next())
			{
				output_after_remove << bft_iterator->next() << " ";
			}
			Assert::IsTrue(output_after_remove.str() == "15 10 30 5 25 40 ");
			Assert::IsTrue(Tree->get_size_tree() == 6);
		}

		// Checking for getting the tree size
		TEST_METHOD(Get_Size_Tree) 
		{
			Tree->insert(20);
			Tree->insert(10);
			Tree->insert(30);
			Iterator* bft_iterator = Tree->create_bft_iterator();
			stringstream output;
			while (bft_iterator->has_next())
			{
				output << bft_iterator->next() << " ";
			}
			Assert::IsTrue(output.str() == "20 10 30 ");
			Assert::IsTrue(Tree->get_size_tree() == 3);
		}

		// Checking to get the root element of the tree if the tree is non-empty
		TEST_METHOD(Get_Root_Node_Not_Empty_Tree)
		{
			Tree->insert(20);
			Tree->insert(10);
			Tree->insert(30);
			Iterator* bft_iterator = Tree->create_bft_iterator();
			stringstream output;
			while (bft_iterator->has_next())
			{
				output << bft_iterator->next() << " ";
			}
			Assert::IsTrue(output.str() == "20 10 30 ");
			Assert::IsTrue(Tree->get_root_node()->key == 20);
		}

		// Checking to get the root element of the tree if the tree is empty
		TEST_METHOD(Get_Root_Node_Empty_Tree)
		{
			try
			{
				Iterator* bft_iterator = Tree->create_bft_iterator();
				stringstream output;
				while (bft_iterator->has_next())
				{
					output << bft_iterator->next() << " ";
				}
			}
			catch (const domain_error error)
			{
				Assert::AreEqual("Binary Search Tree is empty", error.what());
			}
			Assert::IsTrue(Tree->get_size_tree() == 0);
			try
			{
				int element = Tree->get_root_node()->key;
			}
			catch (const domain_error error)
			{
				Assert::AreEqual("Tree is empty", error.what());
			}
		}

		// Checking to get the value of the left child of the root element of the tree if the tree is non-empty
		TEST_METHOD(Get_Root_Node_Left_Not_Empty_Tree) 
		{
			Tree->insert(20);
			Tree->insert(10);
			Tree->insert(30);
			Iterator* bft_iterator = Tree->create_bft_iterator();
			stringstream output;
			while (bft_iterator->has_next())
			{
				output << bft_iterator->next() << " ";
			}
			Assert::IsTrue(output.str() == "20 10 30 ");
			Assert::IsTrue(Tree->get_root_node_left()->key == 10);
		}

		// Checking for getting the right-left root element of the tree if the tree is empty
		TEST_METHOD(Get_Root_Node_Left_Empty_Tree) 
		{
			try
			{
				Iterator* bft_iterator = Tree->create_bft_iterator();
				stringstream output;
				while (bft_iterator->has_next())
				{
					output << bft_iterator->next() << " ";
				}
			}
			catch (const domain_error error)
			{
				Assert::AreEqual("Binary Search Tree is empty", error.what());
			}
			Assert::IsTrue(Tree->get_size_tree() == 0);
			try
			{
				int element = Tree->get_root_node_left()->key;
			}
			catch (const domain_error error)
			{
				Assert::AreEqual("Tree is empty", error.what());
			}
		}

		// Checking to get the value of the right child of the root element of the tree if the tree is non-empty
		TEST_METHOD(Get_Root_Node_Right_Not_Empty_Tree) 
		{
			Tree->insert(20);
			Tree->insert(10);
			Tree->insert(30);
			Iterator* bft_iterator = Tree->create_bft_iterator();
			stringstream output;
			while (bft_iterator->has_next())
			{
				output << bft_iterator->next() << " ";
			}
			Assert::IsTrue(output.str() == "20 10 30 ");
			Assert::IsTrue(Tree->get_root_node_right()->key == 30);
		}

		// Checking to get the right child of the root element of the tree if the tree is empty
		TEST_METHOD(Get_Root_Node_Right_Empty_Tree) 
		{
			try
			{
				Iterator* bft_iterator = Tree->create_bft_iterator();
				stringstream output;
				while (bft_iterator->has_next())
				{
					output << bft_iterator->next() << " ";
				}
			}
			catch (const domain_error error)
			{
				Assert::AreEqual("Binary Search Tree is empty", error.what());
			}
			Assert::IsTrue(Tree->get_size_tree() == 0);
			try
			{
				int element = Tree->get_root_node_right()->key;
			}
			catch (const domain_error error)
			{
				Assert::AreEqual("Tree is empty", error.what());
			}
		}

		// Checking tree cleaning
		TEST_METHOD(Clear_Tree) 
		{
			Tree->insert(20);
			Tree->insert(10);
			Tree->insert(30);
			Iterator* bft_iterator = Tree->create_bft_iterator();
			stringstream output;
			while (bft_iterator->has_next())
			{
				output << bft_iterator->next() << " ";
			}
			Assert::IsTrue(output.str() == "20 10 30 ");
			Tree->clear_tree();
			try
			{
				Iterator* bft_iterator = Tree->create_bft_iterator();
				stringstream output;
				while (bft_iterator->has_next())
				{
					output << bft_iterator->next() << " ";
				}
			}
			catch (const domain_error error)
			{
				Assert::AreEqual("Binary Search Tree is empty", error.what());
			}
			try
			{
				int element = Tree->get_root_node()->key;
			}
			catch (const domain_error error)
			{
				Assert::AreEqual("Tree is empty", error.what());
			}
			Assert::IsTrue(Tree->get_size_tree() == 0);
		}

		// Checking the stack for emptiness
		TEST_METHOD(Is_Empty_Stack) 
		{
			Tree->insert(20);
			Tree->insert(30);
			Tree->insert(10);
			Binary_Search_Tree::Stack stack;
			stack.push(Tree->get_root_node());
			stack.push(Tree->get_root_node_left());
			stack.push(Tree->get_root_node_right());
			stringstream output;
			output << stack;
			Assert::IsTrue(output.str() == "30 10 20 ");
			Assert::IsTrue(stack.stack_is_empty() == false);
		}

		// Checking to get the stack size
		TEST_METHOD(Get_Size_Stack) 
		{
			Tree->insert(20);
			Tree->insert(30);
			Tree->insert(10);
			Binary_Search_Tree::Stack stack;
			stack.push(Tree->get_root_node());
			stack.push(Tree->get_root_node_left());
			stack.push(Tree->get_root_node_right());
			stringstream output;
			output << stack;
			Assert::IsTrue(output.str() == "30 10 20 ");
			Assert::IsTrue(stack.stack_is_empty() == false);
			Assert::IsTrue(stack.get_size_stack() == 3);
		}

		// Checking for adding an element to an empty stack
		TEST_METHOD(Push_Empty_Stack) 
		{
			Tree->insert(20);
			Binary_Search_Tree::Stack stack;
			Assert::IsTrue(stack.stack_is_empty() == true);
			Assert::IsTrue(stack.get_size_stack() == 0);
			stack.push(Tree->get_root_node());
			stringstream output;
			output << stack;
			Assert::IsTrue(output.str() == "20 ");
			Assert::IsTrue(stack.stack_is_empty() == false);
			Assert::IsTrue(stack.get_size_stack() == 1);
		}

		// Checking the addition of an element to a non-empty stack
		TEST_METHOD(Push_Not_Empty_Stack) 
		{
			Tree->insert(20);
			Tree->insert(30);
			Binary_Search_Tree::Stack stack;
			stack.push(Tree->get_root_node());
			stack.push(Tree->get_root_node_right());
			stringstream output;
			output << stack;
			Assert::IsTrue(output.str() == "30 20 ");
			Assert::IsTrue(stack.stack_is_empty() == false);
			Assert::IsTrue(stack.get_size_stack() == 2);
			Tree->insert(10);
			stack.push(Tree->get_root_node_left());
			stringstream output_aften_push;
			output_aften_push << stack;
			Assert::IsTrue(output_aften_push.str() == "10 30 20 ");
			Assert::IsTrue(stack.stack_is_empty() == false);
			Assert::IsTrue(stack.get_size_stack() == 3);
		}

		// Checking the removal of an element from an empty stack
		TEST_METHOD(Pop_Empty_Stack) 
		{
			Binary_Search_Tree::Stack stack;
			Assert::IsTrue(stack.stack_is_empty() == true);
			Assert::IsTrue(stack.get_size_stack() == 0);
			Assert::IsTrue(stack.pop() == nullptr);
		}

		// Checking the removal of an element from the stack containing a single element
		TEST_METHOD(Pop_Single_Element_Stack) 
		{
			Tree->insert(20);
			Binary_Search_Tree::Stack stack;
			stack.push(Tree->get_root_node());
			stringstream output;
			output << stack;
			Assert::IsTrue(output.str() == "20 ");
			Assert::IsTrue(stack.stack_is_empty() == false);
			Assert::IsTrue(stack.get_size_stack() == 1);
			Assert::IsTrue(stack.pop()->key == 20);
			Assert::IsTrue(stack.stack_is_empty() == true);
			Assert::IsTrue(stack.get_size_stack() == 0);
		}

		// Checking the removal of an element from a non-empty stack
		TEST_METHOD(Pop_Not_Empty_Stack) 
		{
			Tree->insert(20);
			Tree->insert(30);
			Tree->insert(10);
			Binary_Search_Tree::Stack stack;
			stack.push(Tree->get_root_node());
			stack.push(Tree->get_root_node_left());
			stack.push(Tree->get_root_node_right());
			stringstream output;
			output << stack;
			Assert::IsTrue(output.str() == "30 10 20 ");
			Assert::IsTrue(stack.stack_is_empty() == false);
			Assert::IsTrue(stack.get_size_stack() == 3);
			Assert::IsTrue(stack.pop()->key == 30);
			stringstream output_aften_pop;
			output_aften_pop << stack;
			Assert::IsTrue(output_aften_pop.str() == "10 20 ");
			Assert::IsTrue(stack.stack_is_empty() == false);
			Assert::IsTrue(stack.get_size_stack() == 2);
		}

		// Checking the stack cleaning
		TEST_METHOD(Clear_Stack) 
		{
			Tree->insert(20);
			Tree->insert(30);
			Tree->insert(10);
			Binary_Search_Tree::Stack stack;
			stack.push(Tree->get_root_node());
			stack.push(Tree->get_root_node_left());
			stack.push(Tree->get_root_node_right());
			stringstream output;
			output << stack;
			Assert::IsTrue(output.str() == "30 10 20 ");
			Assert::IsTrue(stack.stack_is_empty() == false);
			Assert::IsTrue(stack.get_size_stack() == 3);
			stack.clear_stack();
			Assert::IsTrue(stack.stack_is_empty() == true);
			Assert::IsTrue(stack.get_size_stack() == 0);
		}

		// Checking the output statement for an empty stack
		TEST_METHOD(Operator_Output_Empty_Stack) 
		{
			Binary_Search_Tree::Stack stack;
			stringstream output;
			output << stack;
			Assert::IsTrue(output.str() == "Stack is empty\n\n");
		}

		// Checking the output statement for a non-empty stack
		TEST_METHOD(Operator_Output_Stack) 
		{
			Tree->insert(20);
			Tree->insert(30);
			Tree->insert(10);
			Binary_Search_Tree::Stack stack;
			stack.push(Tree->get_root_node());
			stack.push(Tree->get_root_node_left());
			stack.push(Tree->get_root_node_right());
			stringstream output;
			output << stack;
			Assert::IsTrue(output.str() == "30 10 20 ");
		}

		// Checking the queue for emptiness
		TEST_METHOD(Is_Empty_Queue) 
		{
			Tree->insert(20);
			Tree->insert(10);
			Tree->insert(30);
			Binary_Search_Tree::Queue queue;
			queue.enqueue(Tree->get_root_node());
			queue.enqueue(Tree->get_root_node_left());
			queue.enqueue(Tree->get_root_node_right());
			stringstream output;
			output << queue;
			Assert::IsTrue(output.str() == "20 10 30 ");
			Assert::IsTrue(queue.queue_is_empty() == false);
		}

		// Checking to get the queue size
		TEST_METHOD(Get_Size_Queue) 
		{
			Tree->insert(20);
			Tree->insert(30);
			Tree->insert(10);
			Binary_Search_Tree::Queue queue;
			queue.enqueue(Tree->get_root_node());
			queue.enqueue(Tree->get_root_node_left());
			queue.enqueue(Tree->get_root_node_right());
			stringstream output;
			output << queue;
			Assert::IsTrue(output.str() == "20 10 30 ");
			Assert::IsTrue(queue.queue_is_empty() == false);
			Assert::IsTrue(queue.get_size_queue() == 3);
		}

		// Checking for adding an element to an empty queue
		TEST_METHOD(Enqueue_Empty_Queue) 
		{
			Tree->insert(20);
			Binary_Search_Tree::Queue queue;
			Assert::IsTrue(queue.queue_is_empty() == true);
			Assert::IsTrue(queue.get_size_queue() == 0);
			queue.enqueue(Tree->get_root_node());
			stringstream output;
			output << queue;
			Assert::IsTrue(output.str() == "20 ");
			Assert::IsTrue(queue.queue_is_empty() == false);
			Assert::IsTrue(queue.get_size_queue() == 1);
		}

		// Checking for adding an element to a non-empty queue
		TEST_METHOD(Enqueue_Not_Empty_Queue) 
		{
			Tree->insert(20);
			Tree->insert(30);
			Binary_Search_Tree::Queue queue;
			queue.enqueue(Tree->get_root_node());
			queue.enqueue(Tree->get_root_node_right());
			stringstream output;
			output << queue;
			Assert::IsTrue(output.str() == "20 30 ");
			Assert::IsTrue(queue.queue_is_empty() == false);
			Assert::IsTrue(queue.get_size_queue() == 2);
			Tree->insert(10);
			queue.enqueue(Tree->get_root_node_left());
			stringstream output_aften_enqueue;
			output_aften_enqueue << queue;
			Assert::IsTrue(output_aften_enqueue.str() == "20 30 10 ");
			Assert::IsTrue(queue.queue_is_empty() == false);
			Assert::IsTrue(queue.get_size_queue() == 3);
		}

		// Checking for deleting an element from an empty queue
		TEST_METHOD(Dequeue_Empty_Queue) 
		{
			Binary_Search_Tree::Queue queue;
			Assert::IsTrue(queue.queue_is_empty() == true);
			Assert::IsTrue(queue.get_size_queue() == 0);
			Assert::IsTrue(queue.dequeue() == nullptr);
		}

		// Checking the deletion of an element from a queue containing a single element
		TEST_METHOD(Dequeue_Single_Element) 
		{
			Tree->insert(20);
			Binary_Search_Tree::Queue queue;
			queue.enqueue(Tree->get_root_node());
			stringstream output;
			output << queue;
			Assert::IsTrue(output.str() == "20 ");
			Assert::IsTrue(queue.queue_is_empty() == false);
			Assert::IsTrue(queue.get_size_queue() == 1);
			Assert::IsTrue(queue.dequeue()->key == 20);
			Assert::IsTrue(queue.queue_is_empty() == true);
			Assert::IsTrue(queue.get_size_queue() == 0);
		}

		// Checking for deleting an element from a non-empty queue
		TEST_METHOD(Dequeue_Not_Empty_Queue) 
		{
			Tree->insert(20);
			Tree->insert(30);
			Tree->insert(10);
			Binary_Search_Tree::Queue queue;
			queue.enqueue(Tree->get_root_node());
			queue.enqueue(Tree->get_root_node_left());
			queue.enqueue(Tree->get_root_node_right());
			stringstream output;
			output << queue;
			Assert::IsTrue(output.str() == "20 10 30 ");
			Assert::IsTrue(queue.queue_is_empty() == false);
			Assert::IsTrue(queue.get_size_queue() == 3);
			Assert::IsTrue(queue.dequeue()->key == 20);
			stringstream output_aften_dequeue;
			output_aften_dequeue << queue;
			Assert::IsTrue(output_aften_dequeue.str() == "10 30 ");
			Assert::IsTrue(queue.queue_is_empty() == false);
			Assert::IsTrue(queue.get_size_queue() == 2);
		}

		// Checking for queue clearing
		TEST_METHOD(Clear_Queue) 
		{
			Tree->insert(20);
			Tree->insert(30);
			Tree->insert(10);
			Binary_Search_Tree::Queue queue;
			queue.enqueue(Tree->get_root_node());
			queue.enqueue(Tree->get_root_node_left());
			queue.enqueue(Tree->get_root_node_right());
			stringstream output;
			output << queue;
			Assert::IsTrue(output.str() == "20 10 30 ");
			Assert::IsTrue(queue.queue_is_empty() == false);
			Assert::IsTrue(queue.get_size_queue() == 3);
			queue.clear_queue();
			Assert::IsTrue(queue.queue_is_empty() == true);
			Assert::IsTrue(queue.get_size_queue() == 0);
		}

		// Checking the output operator for an empty queue
		TEST_METHOD(Operator_Output_Empty_Queue) 
		{
			Binary_Search_Tree::Queue queue;
			stringstream output;
			output << queue;
			Assert::IsTrue(output.str() == "Queue is empty\n\n");
		}

		// Checking the output operator for a non-empty queue
		TEST_METHOD(Operator_Output_Queue) 
		{
			Tree->insert(20);
			Tree->insert(30);
			Tree->insert(10);
			Binary_Search_Tree::Queue queue;
			queue.enqueue(Tree->get_root_node());
			queue.enqueue(Tree->get_root_node_left());
			queue.enqueue(Tree->get_root_node_right());
			stringstream output;
			output << queue;
			Assert::IsTrue(output.str() == "20 10 30 ");
		}

		// Checking the creation of an iterator of a direct tree traversal in depth
		TEST_METHOD(Ñreate_DFT_Iterator) 
		{
			Tree->insert(20);
			Tree->insert(10);
			Tree->insert(30);
			Tree->insert(5);
			Tree->insert(15);
			Iterator* dft_iterator = Tree->create_dft_iterator();
			stringstream output;
			while (dft_iterator->has_next())
			{
				output << dft_iterator->next() << " ";
			}
			Assert::IsTrue(output.str() == "20 10 5 15 30 ");
		}

		// Checking the creation of a forward tree traversal iterator in depth for an empty tree
		TEST_METHOD(Ñreate_DFT_Iterator_Empty_Tree) 
		{
			try
			{
				Iterator* dft_iterator = Tree->create_dft_iterator();
				stringstream output;
				while (dft_iterator->has_next())
				{
					output << dft_iterator->next() << " ";
				}
			}
			catch (const domain_error error)
			{
				Assert::AreEqual("Binary Search Tree is empty", error.what());
			}
		}

		// Checking for the presence of non-traversed tree elements by the iterator of a direct tree traversal in depth
		TEST_METHOD(DFT_Iterator_Has_Next) 
		{
			Tree->insert(20);
			Tree->insert(10);
			Tree->insert(30);
			Tree->insert(5);
			Tree->insert(15);
			Iterator* dft_iterator = Tree->create_dft_iterator();
			Assert::IsTrue(dft_iterator->has_next() == true);
			Assert::IsTrue(dft_iterator->next() == 20);
			Assert::IsTrue(dft_iterator->has_next() == true);
			Assert::IsTrue(dft_iterator->next() == 10); 
			Assert::IsTrue(dft_iterator->has_next() == true);
			Assert::IsTrue(dft_iterator->next() == 5);
			Assert::IsTrue(dft_iterator->has_next() == true);
			Assert::IsTrue(dft_iterator->next() == 15);
			Assert::IsTrue(dft_iterator->has_next() == true);
			Assert::IsTrue(dft_iterator->next() == 30);
			Assert::IsTrue(dft_iterator->has_next() == false);
			try
			{
				dft_iterator->next();
			}
			catch (const domain_error error)
			{
				Assert::AreEqual("There are no tree elements to process", error.what());
			}
		}

		// Checking the processing of the current node by the algorithm of direct tree traversal in depth
		TEST_METHOD(DFT_Iterator_Next) 
		{
			Tree->insert(20);
			Tree->insert(10);
			Tree->insert(30);
			Tree->insert(5);
			Tree->insert(15);
			Iterator* dft_iterator = Tree->create_dft_iterator();
			Assert::IsTrue(dft_iterator->next() == 20);
			Assert::IsTrue(dft_iterator->next() == 10);
			Assert::IsTrue(dft_iterator->next() == 5);
			Assert::IsTrue(dft_iterator->next() == 15);
			Assert::IsTrue(dft_iterator->next() == 30);
			try
			{
				dft_iterator->next();
			}
			catch (const domain_error error)
			{
				Assert::AreEqual("There are no tree elements to process", error.what());
			}
		}

		// Checking the creation of a tree-wide traversal iterator
		TEST_METHOD(Ñreate_BFT_Iterator) 
		{
			Tree->insert(20);
			Tree->insert(10);
			Tree->insert(30);
			Tree->insert(5);
			Tree->insert(15);
			Iterator* bft_iterator = Tree->create_bft_iterator();
			stringstream output;
			while (bft_iterator->has_next())
			{
				output << bft_iterator->next() << " ";
			}
			Assert::IsTrue(output.str() == "20 10 30 5 15 ");
		}

		// Checking the creation of a tree-wide traversal iterator for an empty tree
		TEST_METHOD(Ñreate_BFT_Iterator_Empty_Tree) 
		{
			try
			{
				Iterator* bft_iterator = Tree->create_bft_iterator();
				stringstream output;
				while (bft_iterator->has_next())
				{
					output << bft_iterator->next() << " ";
				}
			}
			catch (const domain_error error)
			{
				Assert::AreEqual("Binary Search Tree is empty", error.what());
			}
		}

		// Checking for non-traversed tree elements by a tree-wide traversal iterator
		TEST_METHOD(BFT_Iterator_Has_Next) 
		{
			Tree->insert(20);
			Tree->insert(10);
			Tree->insert(30);
			Tree->insert(5);
			Tree->insert(15);
			Iterator* bft_iterator = Tree->create_bft_iterator();
			Assert::IsTrue(bft_iterator->has_next() == true);
			Assert::IsTrue(bft_iterator->next() == 20);
			Assert::IsTrue(bft_iterator->has_next() == true);
			Assert::IsTrue(bft_iterator->next() == 10);
			Assert::IsTrue(bft_iterator->has_next() == true);
			Assert::IsTrue(bft_iterator->next() == 30);
			Assert::IsTrue(bft_iterator->has_next() == true);
			Assert::IsTrue(bft_iterator->next() == 5);
			Assert::IsTrue(bft_iterator->has_next() == true);
			Assert::IsTrue(bft_iterator->next() == 15);
			Assert::IsTrue(bft_iterator->has_next() == false);
			try
			{
				bft_iterator->next();
			}
			catch (const domain_error error)
			{
				Assert::AreEqual("There are no tree elements to process", error.what());
			}
		}

		// Checking the processing of the current node by a tree-wide traversal algorithm
		TEST_METHOD(BFT_Iterator_Next) 
		{
			Tree->insert(20);
			Tree->insert(10);
			Tree->insert(30);
			Tree->insert(5);
			Tree->insert(15);
			Iterator* bft_iterator = Tree->create_bft_iterator();
			Assert::IsTrue(bft_iterator->next() == 20);
			Assert::IsTrue(bft_iterator->next() == 10);
			Assert::IsTrue(bft_iterator->next() == 30);
			Assert::IsTrue(bft_iterator->next() == 5);
			Assert::IsTrue(bft_iterator->next() == 15);
			try
			{
				bft_iterator->next();
			}
			catch (const domain_error error)
			{
				Assert::AreEqual("There are no tree elements to process", error.what());
			}
		}

	};
}
