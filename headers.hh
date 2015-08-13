/******************************************************************************
 *
 * headers.hh
 *
 * Author: msatyam
 *
 * 2015, August
 *
 * Contains all Xerces XML API headers required by our application and default
 * namespaces and other common headers.
 *
 * ***************************************************************************/

#if !defined(HEADERS_HH)
#define HEADERS_HH

#include <xercesc/util/PlatformUtils.hpp>
#include <xercesc/parsers/XercesDOMParser.hpp>
#include <xercesc/dom/DOMDocument.hpp>
#include <xercesc/dom/DOMNode.hpp>
#include <xercesc/dom/DOMElement.hpp>
#include <xercesc/util/XMLString.hpp>
#include <xercesc/dom/DOMNodeList.hpp>

#include <iostream>
#include <string>
#include <cstdlib>
#include <cstdio>

// default namespace
using namespace std;
using namespace xercesc;

#endif
