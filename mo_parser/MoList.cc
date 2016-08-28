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
	
// creates an empty Mo list
MoList::MoList()
{
}

// create a list of MO's from DOMNodeList
MoList::MoList(DOMNodeList* nodeList)
{
	Mo* temp;

	// MO List consists of only ELEMENT_NODES
	for (int i = 0; i < nodeList->getLength(); i++)
	{
		if (nodeList->item(i)->getNodeType() == DOMNode::ELEMENT_NODE)
		{
			temp = new Mo(nodeList->item(i));
			
			this->list.push_back(temp);
		}
	}
}

// appends Mo to the end of the MoList
void MoList::add(Mo* mo)
{
	// add to list end
	list.push_back(mo);
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
