/**********************************************************************
 *
 * APLOCProcessor.hh
 *
 * Author: mSatyam
 *
 * 2016, August
 *
 * Processes APLOC mode commands
 *
 * ********************************************************************/

#if !defined(APLOCPROCESSOR_HH)
#define APLOCPROCESSOR_HH

#define APLOC_PROMPT "\03>"
#define DEFAULT_MO_XML_FILE_PATH "./etc/mo.xml"

#include <MoTree.hh>
#include <MoList.hh>
#include <Mo.hh>

class APLOCProcessor {
    private:
        // XML file name
        string xmlFile;

        // MO Tree
        MoTree* currentMoTree;

        // current MO
        Mo* currentMo;

        // prompt string
        string prompt;

        // states whether term is in config mode or not
        bool configMode;

    public:
        // intialize the APLOCProcessor
        APLOCProcessor(string mo_xml_file = "");

        // returns response for an APLOC command
        Response getResponse(string command);

        // handles TAB character autocompletion functionality
        Response processTab(string command);

        // handles complete commands i.e. commands ending with ENTER key
        Response processEnter(string command);

        // checks whether the command is a non-MO command or not
        // from non-MO command list
        bool isNonMoCommand(string command);

        // handles non-MO commands
        Response handleNonMoCommand(string command);

        // updates the APLOC commandline prompt w.r.t. MO name
        void updatePrompt();
};
#endif
