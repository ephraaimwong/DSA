/**
 * @file HW4_CS2413.cpp
 * @author iampo (ephraaimwong@github.com)
 * @brief Singly Linked List
 * @version 0.1
 * @date 2024-03-09
 *
 * @copyright Copyright (c) 2024
 *
 */
#include <iostream>
using namespace std;
/**
 * @brief Node class
 *
 */
class Node
{
	/**
	 * @brief private fields
	 *
	 */
private:
	int SID;
	float GPA;
	Node *p_next;
/**
 * @brief public fields
 * 
 */
public:
	void Set_SID(int x);
	void Set_GPA(float y);
	int Get_SID();
	float Get_GPA();
	void Set_Pnext(Node *p);
	Node *Get_Pnext();
	Node();
};
/**
 * @brief Set SID in node
 * 
 * @param x new SID
 */
void Node::Set_SID(int x)
{
	SID = x;
}
/**
 * @brief Set GPA in node
 * 
 * @param y new GPA
 */
void Node::Set_GPA(float y)
{
	GPA = y;
}
/**
 * @brief Get SID in node
 * 
 * @return int SID
 */
int Node::Get_SID()
{
	return SID;
}
/**
 * @brief Get GPA in node
 * 
 * @return float GPA
 */
float Node::Get_GPA()
{
	return GPA;
}
/**
 * @brief Update next node pointer
 * 
 * @param p Pointer to next node
 */
void Node::Set_Pnext(Node *p)
{
	p_next = p;
}
/**
 * @brief Get mext node pointer
 * 
 * @return Node* Next node
 */
Node *Node::Get_Pnext()
{
	return p_next;
}
/**
 * @brief Construct a new Node:: Node object
 * 
 */
Node::Node()
{
	SID = -1;
	GPA = -1;
	p_next = NULL;
}
/**
 * @brief Singly Linked List
 * 
 */
class List
{
	/**
	 * @brief private fields
	 * 
	 */
private:
	Node *head;
	/**
	 * @brief public fields
	 * 
	 */
public:
	List();
	void PrtSID();
	/**
	 * @brief Populate List with Nodes
	 * 
	 * Continuously reads SID and GPA, each new node is placed at head->Pnext
	 */
	void Create()
	{
		int sid;
		float gpa;
		while (cin >> sid >> gpa)
		{
			Node *curr = new Node();
			curr->Set_SID(sid);
			curr->Set_GPA(gpa);
			curr->Set_Pnext(head);
			head = curr;
		}
	}

/**
 * @brief List Size
 * 
 * @return int No. of Nodes in List
 */
	int Lsize()
	{
		int ct = 0;
		Node *curr = head;
		while (curr != NULL)
		{
			//couter increments as it transverses the list
			ct++;
			curr = curr->Get_Pnext();
		}
		//returns 0 if list is empty
		return ct;
	}

	/**
	 * @brief Find Node based on SID
	 * 
	 * @param key Target SID
	 * @return Node* Node which matches target SID
	 */
	Node *Find(int key)
	{

		Node *curr = head;
		//traversing list
		while (curr != NULL)
		{
			if (curr->Get_SID() == key)
			{
				return curr;
			}
			curr = curr->Get_Pnext();
		}
		//NULL if key not in list
		return NULL;
	}

	/**
	 * @brief Insert new node at idx
	 * 
	 * @param p new node address
	 * @param idx insert position in list
	 * @return int 1 if success -1 if fail
	 */
	int Insert(Node *p, int idx)
	{
		//out of bounds
		if (idx < 1 || idx > Lsize())
		{
			return -1;
		}
		//insert at head
		if (idx == 1)
		{
			p->Set_Pnext(head);
			head = p;
		}
		else
		{
			Node *curr = head;
			//moving to node idx-1
			for (int i = 1; i < idx - 1; i++)
			{
				curr = curr->Get_Pnext();
			}
			// set new node address as curr->next
			p->Set_Pnext(curr->Get_Pnext());
			//set curr->next to new node
			curr->Set_Pnext(p);
		}
		return 1;
	}

	/**
	 * @brief Remove node at idx
	 * 
	 * @param idx Removal Position
	 * @return int 1 if success -1 if fail
	 */
	int Remove(int idx)
	{
		//out of bounds
		if (idx < 1 || idx > Lsize())
		{
			return -1;
		}
		Node *curr = head;
		//removal at head
		if (idx == 1)
		{
			//curr is still pointing to old head
			head->Set_Pnext(head->Get_Pnext());
		}
		else
		{
			Node *prev = NULL;
			//traverse to idx
			for (int i = 1; i < idx; i++)
			{
				prev = curr;
				curr = curr->Get_Pnext();
			}
			//skips address of curr
			prev->Set_Pnext(curr->Get_Pnext());
		}
		delete curr;
		return 1;
	}

	/**
	 * @brief Reverse Node order in List
	 * 
	 */
	void Reverse()
	{
		Node *prev = NULL;
		Node *curr = head;
		Node *next = NULL;
		//traversing list
		while (curr != NULL)
		{
			next = curr->Get_Pnext();
			//reverses pointer
			curr->Set_Pnext(prev);
			prev = curr;
			curr = next;
		}
		//head is now right most node
		head = prev;
	}

	/**
	 * @brief clears all nodes in list
	 * 
	 */
	void Clear()
	{
		Node *curr = head;
		//traverse list
		while (curr != NULL)
		{
			//delete each node
			Node *temp = curr;
			curr = curr->Get_Pnext();
			delete temp;
		}
		head = NULL;
	}
};
// The constructor has been defined for you.
List::List()
{
	head = NULL;
}
// The print function has been defined for you.
void List::PrtSID()
{
	Node *temp = head;
	while (temp != NULL)
	{
		cout << temp->Get_SID();
		temp = temp->Get_Pnext();
	}
}
int main()
{
	int mode, key, sid, idx;
	float gpa;
	// The first five inputs are for testing.
	// "mode" determines which function to test.
	// "key" is used to evaluate Find().
	// "sid" and "gpa" are used to evaluate Insert().
	// "idx" is used to evaluate Insert() and Remove().
	//
	// After these inputs, the rest inputs are used
	// to create the initial singly linked list.
	cin >> mode >> key >> sid >> gpa >> idx;
	// declare a singly linked list named "x"
	List x;
	// input data to x.
	// After this, a list should be created
	// and stored at address "head".
	x.Create();
	// Mode 0: test Create()
	if (mode == 0)
	{
		x.PrtSID();
	}
	// Mode 1: test Lsize()
	else if (mode == 1)
	{
		cout << x.Lsize();
	}
	// Mode 2: test Find()
	else if (mode == 2)
	{
		Node *temp = x.Find(key);
		if (temp == NULL)
		{
			cout << -1;
		}
		else
		{
			cout << temp->Get_GPA();
		}
	}
	// Mode 3: test Insert()
	else if (mode == 3)
	{
		Node *temp = new Node;
		temp->Set_SID(key);
		temp->Set_GPA(3.5);
		x.Insert(temp, idx);
		x.PrtSID();
	}
	// Mode 4: test Remove()
	else if (mode == 4)
	{
		x.Remove(idx);
		x.PrtSID();
	}
	// Mode 5: test Reverse()
	else if (mode == 5)
	{
		x.Reverse();
		x.PrtSID();
	}
	// Mode 6: test Clear()
	else if (mode == 6)
	{
		x.Clear();
		cout << x.Lsize();
	}
	return 0;
}