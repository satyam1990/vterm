/******************************************************************************
 *
 * testMo.cc
 *
 * Author: mSatyam
 *
 * 2015, August
 *
 * Tests the functionality of Mo class.
 *
 * ***************************************************************************/

#include <Mo.hh>
#include <MoTree.hh>
#include <MoList.hh>

int main()
{
	try
	{	// init xerces XML Parser library
		XMLPlatformUtils::Initialize();
	}
	catch (const XMLException& toCatch)
	{
		cout << toCatch.getMessage() << endl;
		return 1;
	}

	// create the base Mo Tree
	string xmlfile = "../data/test.xml";
	MoTree* tree = new MoTree(xmlfile);

	// get the root Mo
	Mo* root = tree->getRootMo();

	// test get all childs and print their count
	MoList* list = root->getChildMos();
	cout << "Root Child count is: " << list->getLength() << endl;

	// print next Mo's followed by root
	Mo* next = root;
	Mo* last = next;
	while (next != NULL)
	{
		cout << "Name: " << next->getName() << endl;
        last = next;
		next = next->getChildMo();
	}

	// print MO's in reverse order
	while (last != NULL)
	{
		cout << "Last MO: " << last->getName() << endl;
		last = last->getParentMo();
	}

	// print child Mo with name "second"
	Mo* child = root->getChildMoByName("Second");
	if (child != NULL)
	{
		cout << "child: " << child->getName() << endl;
	}
	else
	{
		cout << "No child with that name" << endl;
	}

	// search for Mo which is not a child of root
	child = root->getChildMoByName("nameNotInXML");
	if (child != NULL)
	{
		cout << "child: " << child->getName() << endl;
	}
	else
	{
		cout << "No child with that name" << endl;
	}

	XMLPlatformUtils::Terminate();

	return 0;
}
