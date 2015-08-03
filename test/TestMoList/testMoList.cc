/******************************************************************************
 *
 * testMoList.cc
 *
 * Author: mSatyam
 *
 * 2015, August
 *
 * Tests functionality of MoList class.
 *
 *****************************************************************************/

#include <Mo.hh>
#include <MoTree.hh>
#include <MoList.hh>

int main()
{
    try
    {
        // init xerces XML Parser library
        XMLPlatformUtils::Initialize();
    }
    catch (const XMLException& ex)
    {
        cerr << ex.getMessage() << endl;
        return 1;
    }

    // create the base MoTree
    MoTree* tree = new MoTree("../data/test.xml");

    // get the root Mo
    Mo* root = tree->getRootMo();

    // create child MoList from root Mo
    MoList* list = root->getChildMos();

    // print each child Mo
    for (int i = 0; i < list->getLength(); i++)
    {
        cout << i << " Mo Name: " << list->getMoAtIndex(i)->getName() << endl;
    }


    return 0;
}
