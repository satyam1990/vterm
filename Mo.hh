/******************************************************************************
 *
 * Mo.hh
 *
 * Author: mSatyam
 *
 * 2015, August
 *
 * This class represents a single MO from a specific MO Tree one can say a
 * single NODE of a MO Tree XML file and opertions that can be perfomed on it.
 *
 * ***************************************************************************/


#if !defined(MO_HH)
#define MO_HH

#include "MoList.hh"
#include "headers.hh"

class MoList;

class Mo {

	private:
		// Mo Name
		string name;

		// this mo
		DOMNode* ourMo;

	public:
		// creates a MO with the specified Node of the XML file
		Mo(DOMNode* ourMo);

		// returns all the child MO's of this MO
		MoList* getChildMos();

		// returns the next MO immediately following this MO
		Mo* getChildMo();

		// return parent Mo of this MO
		Mo* getParentMo();

		// returns name of this MO
		string getName();

		// states whether this MO is an interactive command MO
		bool isInteractive();
};
#endif
