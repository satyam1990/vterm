/******************************************************************************
 *
 * MoTree.hh
 *
 * Author: mSatyam
 *
 * 2015, August
 *
 * File defines the operations one can perform on MO Tree which is represented
 * in a XML format. MO Tree has a root NODE with child and sub-child NODES.
 *
 * ***************************************************************************/

#if !defined(MO_TREE_HH)
#define MO_TREE_HH

#define MO_FILE_NAME "res/mo.xml"

#include "Mo.hh"
#include "MoList.hh"
#include "headers.hh"

class MoTree {
	
	private:
		// Parses the MO Tree XML file
		XercesDOMParser* parser;

		// Represents the XML document
		DOMDocument* doc;

		// Represents the root element
		DOMElement* root;

	public:
		// loads default XML file which represents MO's
		MoTree();

		// loads XML files as specified in the argument
		MoTree(const char* xmlFile);

		// returns root MO from the MO Tree
		Mo* getRootMo();

		// returns all MO's in our MO Tree represented by XML file
		MoList* getAllMos();

		// returns MO with the Name specified
		Mo* getMoByName(const char* name);
};
#endif
