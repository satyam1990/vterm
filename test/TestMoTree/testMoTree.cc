/******************************************************************************
 *
 * TestMoTree.cc
 *
 * Author: mSatyam
 *
 * 2015, August
 *
 * Tests MoTree functionality.
 *
 * ***************************************************************************/

#include <headers.hh>
#include <MoTree.hh>
#include <Mo.hh>

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
	
	string xmlfile = "../data/test.xml";

	MoTree* tree = new MoTree(xmlfile);

	// get root MO and print its name
	Mo* root = tree->getRootMo();

	cout << "Root MO Name: " << root->getName() << endl;

	XMLPlatformUtils::Terminate();

	return 0;
}
