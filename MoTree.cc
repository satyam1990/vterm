/******************************************************************************
 *
 * MoTree.cc
 *
 * Author: mSatyam
 *
 * 2015, August
 *
 * File defines the operations one can perform on MO Tree which is represented
 * in a XML format. MO Tree has a root NODE with child and sub-child NODES.
 *
 * ***************************************************************************/

#include "MoTree.hh"

// loads default XML file which represents MO's
MoTree::MoTree()
{
	parser = new XercesDOMParser();

	// parse the default MO file
	try
	{
		parser->parse(MO_FILE_NAME);
	}
	catch (const XMLException& ex)
	{
		cerr << ex.getMessage() << endl;
		exit(1);
	}

	// get the document
	doc = parser->getDocument();

	// get root element
	root = doc->getDocumentElement();
}

// loads XML files as specified in the argument
MoTree::MoTree(string xmlFile)
{
	parser = new XercesDOMParser();

	// parse the default MO file
	try
	{
		parser->parse(xmlFile.c_str());
	}
	catch (const XMLException& ex)
	{
		cerr << ex.getMessage() << endl;
		exit(1);
	}

	// get the document
	doc = parser->getDocument();

	// get root element
	root = doc->getDocumentElement();
}

// returns root MO from the MO Tree
Mo* MoTree::getRootMo()
{
	DOMNode* node = dynamic_cast<DOMNode*>(root);
	Mo* mo = new Mo(node);

	return mo;
}

// returns all MO's in our MO Tree represented by XML file
MoList* MoTree::getAllMos()
{
	// TODO
	return NULL;
}

// returns MO with the Name specified
Mo* MoTree::getMoByName(const char* name)
{
	DOMNodeList* list = root->getElementsByTagName(XMLString::transcode(name));

	// most probably we have only one match thus for now returning first 
	// element only which will be the only element with that name
	Mo* mo = new Mo(dynamic_cast<DOMElement*>(list->item(0)));

	return mo;
}
