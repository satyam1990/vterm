/******************************************************************************
 *
 * Mo.cc
 *
 * Author: mSatyam
 *
 * 2015, August
 *
 * This class represents a single MO from a specific MO Tree one can say a
 * single NODE of a MO Tree XML file and opertions that can be perfomed on it.
 *
 * ***************************************************************************/

#include "Mo.hh"

// creates a MO with the specified Node of the XML file
Mo::Mo(DOMNode* ourMo)
{
	this->ourMo = ourMo;

	if (ourMo != NULL)
	{
		name = XMLString::transcode(ourMo->getNodeName());
	}
}

// returns all the child MO's of this MO
MoList* Mo::getChildMos()
{
	DOMNodeList* list = ourMo->getChildNodes();
	MoList* moList = new MoList(list);

	return moList;
}

// returns the next MO immediately following this MO
Mo* Mo::getChildMo()
{
	DOMNode* next = ourMo->getFirstChild();
	while (next && next->getNodeType() != DOMNode::ELEMENT_NODE)
	{
		/* MO's are equivalent to ELEMENT_NODE if something else found
		 * most probably a TEXT_NODE then we need to call getNextSibling
		 * instead see example below.
		 * Example XML is: <root>some_text<myMO></myMO></root>
		 * In above case if we call getFirstChild on <root> MO we will
		 * get TEXT_NODE("some_text") but we need child MO which is equivalent
		 * to ELEMENT_NODE so calling getFirstChild on TEXT_NODE
		 * will return NULL thus we need to call getNextSibling in order
		 * to get <myMo> MO as it is a sibling of TEXT_NODE and not a child of TEXT_NODE
		 * As a matter of fact TEXT_NODE do not have child NODES.
		 */
		next = next->getNextSibling();
	}

	if (next == NULL)
	{
		return NULL;
	}

	Mo* mo = new Mo(next);

	return mo;
}

// returns the child Mo as the name specified in argument (if any)
Mo* Mo::getChildMoByName(string name)
{
	// Mo to return
	Mo* matchedMo = NULL;

	// get all child Mos
	MoList *list = getChildMos();

	// iterate over each Mo
	for (int i = 0; i < list->getLength(); i++)
	{
		// compare Mo name with passed name ignoring case
		// store if match found and break
		if (Helper::equalsIgnoreCase(name, 
				list->getMoAtIndex(i)->getName()))
		{
			matchedMo = list->getMoAtIndex(i);
			break;
		}
	}

	return matchedMo;
}

// return parent Mo of this MO
Mo* Mo::getParentMo()
{
	DOMNode* parent = ourMo->getParentNode();
	while (parent && parent->getNodeType() != DOMNode::ELEMENT_NODE)
	{
		parent = parent->getParentNode();
	}

	if (parent == NULL)
	{
		return NULL;
	}

	Mo* mo = new Mo(parent);

	return mo;
}

// returns name of this MO
string Mo::getName()
{
	return name;
}

// states whether this MO is an interactive command MO
bool Mo::isInteractive()
{
	// TODO
	return false;
}
