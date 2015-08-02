/******************************************************************************
 *
 * MoList.cc
 *
 * Author: mSatyam
 *
 * 2015, August
 *
 * This class provides a way to store and retreive ordered collection of MOS,
 * basically a wrapper to DOMNodeList.
 *
 * ***************************************************************************/

#include "MoList.hh"
	
// create a list of MO's from DOMNodeList
MoList::MoList(DOMNodeList* list)
{
	Mo* temp;

	// MO List consists of only ELEMENT_NODES
	for (int i = 0; i < list->getLength(); i++)
	{
		if (list->item(i)->getNodeType() == DOMNode::ELEMENT_NODE)
		{
			temp = new Mo(list->item(i));
			
			this->list.push_back(temp);
		}
	}
}

// return MO at specified index
Mo* MoList::getMoAtIndex(size_t index)
{
	return list.at(index);
}

// returns number of MO's in the list
size_t MoList::getLength()
{
	return list.size();
}
