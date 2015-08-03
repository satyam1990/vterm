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
	MoTree* tree = new MoTree("../data/test.xml");

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

	XMLPlatformUtils::Terminate();

	return 0;
}
