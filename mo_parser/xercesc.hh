/*********************************************************************
 *
 * xercesc.hh
 *
 * Author: mSatyam
 *
 * 2016, August
 *
 * Contains all XERCES XML API headers required by our MO parser.
 *
 * *******************************************************************/

#if !defined(XERCESC_HH)
#define XERCESC_HH

#include <xercesc/util/PlatformUtils.hpp>
#include <xercesc/parsers/XercesDOMParser.hpp>
#include <xercesc/dom/DOMDocument.hpp>
#include <xercesc/dom/DOMNode.hpp>
#include <xercesc/dom/DOMElement.hpp>
#include <xercesc/util/XMLString.hpp>
#include <xercesc/dom/DOMNodeList.hpp>

// namespace for XML parsing
using namespace xerces;
#endif
