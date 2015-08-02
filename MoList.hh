/******************************************************************************
 *
 * MoList.hh
 *
 * Author: mSatyam
 *
 * 2015, August
 *
 * This class provides a way to store and retreive ordered collection of MOS,
 * basically a wrapper to DOMNodeList.
 *
 * ***************************************************************************/

#if !defined(MO_LIST_HH)
#define MO_LIST_HH

#include "Mo.hh"
#include "headers.hh"
#include <vector>

class Mo;

typedef vector<Mo*> List;

class MoList {

	private:
		// represents our MO list
		List list;

	public:
		// create a list of MO's from DOMNodeList
		MoList(DOMNodeList* list);

		// return MO at specified index
		Mo* getMoAtIndex(size_t index);

		// returns number of MO's in the list
		size_t getLength();
};
#endif
