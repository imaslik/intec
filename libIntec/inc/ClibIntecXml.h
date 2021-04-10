  #ifndef ClibIntecXml_h
#define ClibIntecXml_h 1

#include <map>
//#include "StringList.h"

#include "xmlParser.h"
#include <string.h>
//#include "IFileParser.h"

class ClibIntecXml
{

	typedef std::map<unsigned int, XMLNode> BookmarksMap;

	public:

		ClibIntecXml (const char* fileName = "", bool read = true);

		~ClibIntecXml();

		virtual void SetFileName (const char* filename);

		char* GetFileName () const;

		virtual void Flush () const;

		bool FocusOnSubSection (const char* subNodeName);

		char* FocusOnNextSection ();

		bool FocusOnRoot ();

		bool GetData (const char* key, char* value, bool detachedSection = false) const;

	    bool GetData (const char* key, std::string& value, bool detachedSection = false) const;

		bool GetData (const char* key, unsigned int & value, bool hex, bool detachedSection = false) const;

		unsigned int SetBookmark ();

		bool FocusOnBookmark (unsigned int bookmarkIndex);

	    bool ClearBookmark (unsigned int bookmarkIndex);


		bool SearchSection (const char* SectionName);

		void GetCurrentSectionName (char* SectionName);

		bool AddAttribute (const char* NodeName, const char* AttributeName, const char* Value, unsigned int bookMark = 0);

		bool SkipCommentSection ();

		XMLNode GetCurrentSectionPtr ();

		bool SearchSubtree (const char* Name, XMLNode pSectionPtr);


		// This function searches for nodes with the given name under the given section ptr
		std::list<XMLNode> SearchForNode(XMLNode SectionPtr, const char* NodeName);

		// This function searches for a node with a particular name and containing an attribute
		// with a particular value
		bool SearchForNodeWithAttribute(XMLNode SectionPtr, const char* NodeName,
		  const char* AttributeName, const char* AttributeValue);

		//This Function returns the next sibling with the given tag name
		bool FocusOnNextSectionByName(const char* NodeName);



		//This function returns the number of child nodes of the current Node
		bool GetNumOfChildNodes( unsigned int & value);

  private:

	  XMLNode        documentNode_;  // Not to be confused w/ the so called document/rootElment !!!, this _node_ simply represents the XML documnet/file.
	  XMLNode        currentNode_;
	  BookmarksMap   bookMarksMap_;
      unsigned int   bookMarkIndex_;
      bool           read_;
      bool           IsLoaded_;
	  std::string    fileName_;
};

#endif

