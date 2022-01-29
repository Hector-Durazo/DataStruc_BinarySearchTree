// Assignment #6
// Name: Hector Durazo
// ASU Email Address: hmdurazo@asu.edu
// Description: This is a program that creates a binary tree of club objects and has several 
//              functionalities such as 3 types of tree walk, right and left rotate, tree max
//              and tree min.
//              
#include <iostream> //to use cout
#include <string>	//to use strings
#include <cstdlib>	//to use atoi

using namespace std;

// Club represents some club information
class Club
{
private:
	string clubName;
	string universityName;
	Club *left, *right, *parent;

public:
	// The following two functions are constructors
	Club()
	{
		clubName = "?";
		universityName = "?";
		parent = NULL;
		left = NULL;
		right = NULL;
	}

	Club(string clubName1, string universityName1)
	{
		clubName = clubName1;
		universityName = universityName1;

		parent = NULL;
		left = NULL;
		right = NULL;
	}

	// The following functions are accessor functions
	Club *getLeft()
	{
		return left;
	}

	Club *getRight()
	{
		return right;
	}

	Club *getParent()
	{
	  return parent;
	}

	string getClubName()
	{
		return clubName;
	}
	string getUniversityName()
	{
		return universityName;
	}

	// The following functions are mutator functions
	void setLeft(Club *other)
	{
		left = other;
	}

	void setRight(Club *other)
	{
		right = other;
	}

	void setParent(Club *other)
	{
		parent = other;
	}

	// The print method prints the clubName and universityName
	void print()
	{
		cout << "Club Name: " << clubName << endl;
		cout << "University Name: " << universityName << endl
			 << endl;
	}
};

// class BinarySearchTree will contains clubs
class BinarySearchTree
{
private:
	Club *root;
	int size;

public:
	BinarySearchTree();
	~BinarySearchTree();
	int postOrderTreeDelete(Club *);
	bool isEmpty();
	void inOrderTreePrint();
	void preOrderTreePrint();
	void postOrderTreePrint();
	void inOrderTreeWalk(Club *);
	void preOrderTreeWalk(Club *);
	void postOrderTreeWalk(Club *);
	Club *treeSearchNode(Club *, string, string);
	Club *treeSearch(string, string);
	Club *treeMinimum();
	Club *treeMaximum();
	Club *treeMinimumNode(Club *);
	Club *treeMaximumNode(Club *);
	Club *treeSuccessor(string, string);
	Club *treePredecessor(string, string);
	bool treeInsert(string, string);
	bool rightRotate(string, string);
	bool leftRotate(string, string);
	int delCount;
};

// The constructor initialize the root to be NULL
BinarySearchTree::BinarySearchTree()
{
	root = NULL;
}

// The descurtor deletes all nodes in the tree
// and perform garbage collections starting from leaves (bottom-up order).
BinarySearchTree::~BinarySearchTree()
{
	Club *delClub = root;
	postOrderTreeDelete(delClub);
	cout << "The number of nodes deleted: " << delCount << endl;
}

//this is a helper method for the destructor where the deletion takes place and keeps track of the number of nodes deleted
int BinarySearchTree::postOrderTreeDelete(Club *delClub)
{
	if (delClub == NULL)
		return delCount;

	postOrderTreeDelete(delClub->getLeft());
	postOrderTreeDelete(delClub->getRight());
	delCount += 1;
	delete delClub;
}

// Checks if the tree is empty
bool BinarySearchTree::isEmpty()
{
	if (root == NULL)
		return true;
	else
		return false;
}

// prints all nodes using in-order
void BinarySearchTree::inOrderTreePrint()
{
	if (isEmpty())
		cout << "tree is empty" << endl;
	else
	{
		cout << "\n";
		inOrderTreeWalk(root);
		cout << "\n";
	}
}

// prints all nodes using pre-order
void BinarySearchTree::preOrderTreePrint()
{
	if (isEmpty())
		cout << "tree is empty" << endl;
	else
	{
		cout << "\n";
		preOrderTreeWalk(root);
		cout << "\n";
	}
}

// prints all nodes using post-order
void BinarySearchTree::postOrderTreePrint()
{
	if (isEmpty())
		cout << "tree is empty" << endl;
	else
	{
		cout << "\n";
		postOrderTreeWalk(root);
		cout << "\n";
	}
}

//prints out the tree in order
void BinarySearchTree::inOrderTreeWalk(Club *clubIn)
{
	if (clubIn != NULL)
	{
		inOrderTreeWalk(clubIn->getLeft());
		cout << endl;
		cout << "Club Name: " << clubIn->getClubName() << endl;
		cout << "University Name: " << clubIn->getUniversityName() << endl;
		cout << endl;
		inOrderTreeWalk(clubIn->getRight());
	}
}

//prints the tree in pre order 
void BinarySearchTree::preOrderTreeWalk(Club *clubIn)
{
	if (clubIn == NULL)
		return;

	cout << endl;
	cout << "Club Name: " << clubIn->getClubName() << endl;
	cout << "University Name: " << clubIn->getUniversityName() << endl;
	cout << endl;
  //recursivly traverses through the tree after printing
	preOrderTreeWalk(clubIn->getLeft());
	preOrderTreeWalk(clubIn->getRight());
}

//print the tree out in post order
void BinarySearchTree::postOrderTreeWalk(Club *clubIn)
{
	if (clubIn == NULL)
		return;
  //traverses through the tree before printing
	postOrderTreeWalk(clubIn->getLeft());
	postOrderTreeWalk(clubIn->getRight());
	cout << endl;
	cout << "Club Name: " << clubIn->getClubName() << endl;
	cout << "University Name: " << clubIn->getUniversityName() << endl;
	cout << endl;
}

//finds the minimum node in the tree
Club *BinarySearchTree::treeMinimum()
{
	Club *t = root;
	if (t == NULL)
		return 0;
	while (t->getLeft() != NULL)
	{
		t = t->getLeft();
	}
	return t;
}
//finds the max node in the tree
Club *BinarySearchTree::treeMaximum()
{
	Club *t = root;
	if (t == NULL)
		return 0;
	while (t->getRight() != NULL)
	{
		t = t->getRight();
	}
	return t;
}

//finds the minimum node in the tree
Club *BinarySearchTree::treeMinimumNode(Club *clubIn)
{
	Club *t = clubIn;
	if (t == NULL)
		return 0;
	while (t->getLeft() != NULL)
	{
		t = t->getLeft();
	}
	return t;
}

//find the max node in the tree
Club *BinarySearchTree::treeMaximumNode(Club *clubIn)
{
	Club *t = clubIn;
	if (t == NULL)
		return 0;
	while (t->getRight() != NULL)
	{
		t = t->getRight();
	}
	return t;
}

//searches throught the whold tree until it find a specific node with matching key
Club *BinarySearchTree::treeSearchNode(Club *clubIn, string clubName, string univName)
{
  //checks if the club is null or if the club name and university name matches (if the keys match with user input)
	if (clubIn == NULL || (clubName.compare(clubIn->getClubName()) == 0 && univName.compare(clubIn->getUniversityName()) == 0))
    //if true return the that club
		return clubIn;
  //if only the university name matches but not the club name then it searches the left or right node depending on the comparison
	if (clubIn->getUniversityName().compare(univName) == 0)
	{
		if (clubName.compare(clubIn->getClubName()) < 0)
			return treeSearchNode(clubIn->getLeft(), clubName, univName);
		else
			return treeSearchNode(clubIn->getRight(), clubName, univName);
	}
  //if the University name does not match then it searches the left node
	else if (univName.compare(clubIn->getUniversityName()) < 0)
		return treeSearchNode(clubIn->getLeft(), clubName, univName);
  //else it searches the right node
	else
		return treeSearchNode(clubIn->getRight(), clubName, univName);
}

//method that returns the result of tree search
Club *BinarySearchTree::treeSearch(string clubName, string univName)
{
	return treeSearchNode(this->root, clubName, univName);
}

//this method allows the user to choose a specifc node and find its predecessor
Club *BinarySearchTree::treePredecessor(string clubName, string univName)
{
	Club *t = treeSearch(clubName, univName);
  //checks if the root node is empty, if so it returns 0
	if (root == NULL || t == NULL)
		return 0;
  //while the left node is not null it will continue going left
	if (t->getLeft() != NULL)
		return treeMaximumNode(t->getLeft());
	Club *y = t->getParent();

  //while y does not equal NULL and t equals the left cild of y
	while ((y != NULL) && (t == y->getLeft()))
	{
    //set t to y
		t = y;
    //set y equal to its left child
		y = y->getLeft();
	}
	return y;
}

//this method allows the user to choose a specifc node and find its successor
Club *BinarySearchTree::treeSuccessor(string clubName, string univName)
{
	Club *t = treeSearch(clubName, univName);
  //checks if the root node is empty, if so it returns 0
	if (root == NULL || t == NULL)
		return 0;
  //while the right node is not null it will continue going right
	if (t->getRight() != NULL)
		return treeMinimumNode(t->getRight());
	Club *y = t->getParent();
  
  //while y is not null and t equals the right child of y
	while (y != NULL && t == y->getRight())
	{
    //set t equal to y
		t = y;
    //set y equal to its parent node
		y = y->getParent();
	}
	return y;
}

//This method allows the user to insert a node into the binary tree
bool BinarySearchTree::treeInsert(string clubName, string univName)
{
	//checks to see if the club the user wathc to insert exists
  Club *exist = treeSearch(clubName, univName);
  if(exist != NULL)
	//returns false if a duplicate is found
    return 0;
    
	Club *z = new Club(clubName, univName);
	Club *y = NULL;
	Club *t = root;
	
	//while t does not equal null
	while (t != NULL)
	{
		y = t;
		//if the university names are the same as the node checking then
		if (univName.compare(y->getUniversityName()) == 0)
		{
			//if the club name is < the club name in the tree it goes to the left child
			if (clubName.compare(y->getClubName()) < 0)
				t = t->getLeft();
			//else it goes to the right child
			else
				t = t->getRight();
		}
		//if the univeristy names do not match
		else
		{
			//if the university name is less than the name in the tree then
			if (univName.compare(y->getUniversityName()) < 0)
				//t is set to left child
				t = t->getLeft();
			//if univ name is greater than then 
			else
				//t is set equal to its right child
				t = t->getRight();
		}
	}
	//set the parent of z equal to y node
	z->setParent(y);
	//if y is empty then the root is set to z
	if (y == NULL)
		root = z;
	else
	{
		//if the university names that are being compared are equal then
		if (univName.compare(y->getUniversityName()) == 0)
		{
			//if the club name is less than
			if (clubName.compare(y->getClubName()) < 0)
				//set the left child node of y equal to z
				y->setLeft(z);
			//if the club name is greater than
			else
				//set the right child equal to z
				y->setRight(z);
		}
		//if the univ names are different
		else
		{	
			//compare the univ names
			if (univName.compare(y->getUniversityName()) < 0)
				y->setLeft(z);
			else
				y->setRight(z);
		}
	}
	return true;
}

//left rotate allows the uer to ender a club name and univ name and rotate it to the left
bool BinarySearchTree::leftRotate(string clubName, string univName)
{
	//checks if the club exists
	Club *t = treeSearch(clubName, univName);
	if (t == NULL)
		return 0;
	//if the root equals null or if the right child equals null return false
	if (root == NULL || t->getRight() == NULL)
		return 0;

	//create a pointer to right child of t
	Club *y = t->getRight();

	//sets the right child of t to the left child of y
	t->setRight(y->getLeft());

	//check if the left child of y is null
	if (y->getLeft() != NULL)
		//if not null then the parent of the left child equal to t
		y->getLeft()->setParent(t);

	//set the parent of y equal to the parent of t
	y->setParent(t->getParent());

	//if the parent of t is null then set the root equal to y
	if (t->getParent() == NULL)
		this->root = y;
	//if t equals to the left child of the parent then set the left child equal to y
	else if (t == t->getParent()->getLeft())
		t->getParent()->setLeft(y);
	//else set the right child to y
	else
		t->getParent()->setRight(y);

	//set the left child of y to t
	y->setLeft(t);
	//set t parent eqaual to y
	t->setParent(y);
	return 1;
}

bool BinarySearchTree::rightRotate(string clubName, string univName)
{
	//checks if the club the user wants to rotate exists
	Club *t = treeSearch(clubName, univName);
	if (t == NULL)
		return 0;
	//if the root or left child of t is null then return false
	if (root == NULL || t->getLeft() == NULL)
		return 0;

	//creates a pointer to left child of t
	Club *y = t->getLeft();

	//sets the left child of t to the rgith child of y
	t->setLeft(y->getRight());

	//check if the right child of y is null
	if (y->getRight() != NULL)
		//if not null then set the right childs parent equal to t
		y->getRight()->setParent(t);
	//set the parent of y equal to ts parent
	y->setParent(t->getParent());

	//checks if the parent of t is null
	if (t->getParent() == NULL)
		this->root = y;
	//if the parent is equal to the parents left child set the parent left child to y
	else if (t == t->getParent()->getLeft())
		t->getParent()->setLeft(y);
	else
		t->getParent()->setRight(y);

	//set the right child to t
	y->setRight(t);
	//set the parent equal to y
	t->setParent(y);
	return 1;
}