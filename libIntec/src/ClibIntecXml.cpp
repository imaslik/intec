#ifdef WIN32
	#pragma warning (disable: 4786 4788)
#endif
//#include "HalCrossPlatformsDefs.h"

#include <assert.h>
//#include "CStatIni.h"
#include <ctime>
#include "ClibIntecXml.h"

#define PACKAGE_NAME "ClibIntecXml"
#define MAX_LEN (512)

ClibIntecXml::ClibIntecXml(const char* fileName, bool read)
{
	read_ = read;
	fileName_ = fileName;
	documentNode_ = XMLNode::parseFile(fileName);
	if( read_ )
	{
		if( !documentNode_.isEmpty() )
		{
			IsLoaded_ = true;
			FocusOnRoot();
		}
		else
		{
			IsLoaded_ = false;
			printf("Cannot load xml file. %s was not found",fileName_.c_str());
		}
	}

	bookMarkIndex_ = 0;
}


ClibIntecXml::~ClibIntecXml()
{
	Flush();
}

void ClibIntecXml::SetFileName (const char* filename)
{
	fileName_ = filename;
	if( fileName_.empty() )
	{
		documentNode_ = XMLNode::parseFile(filename);
		IsLoaded_ = !documentNode_.isEmpty();
	}
	else
		IsLoaded_ = false;
}

char* ClibIntecXml::GetFileName () const
{
	 return const_cast<char*>(fileName_.c_str());
}

void ClibIntecXml::Flush () const
{
	if( !read_ )
		documentNode_.writeToFile(fileName_.c_str());
}

bool ClibIntecXml::FocusOnSubSection (const char* subNodeName)
{
  	if (subNodeName == NULL)  // it means we are looking for first subsection
		currentNode_ = currentNode_.getChildNode();
	else
		currentNode_ = currentNode_.getChildNode(subNodeName,0);

	return !currentNode_.isEmpty();
}

char* ClibIntecXml::FocusOnNextSection ()
{
	// Climbing to the parent of the current node & finding the index of the current
	// node within its parent.
	XMLNode parent = currentNode_.getParentNode();
	if ( parent.isEmpty() )
		return 0;
	int siblingIdx = parent.getChildNodeIndex(currentNode_) + 1;
	XMLNode tmp    = parent.getChildNode(siblingIdx);
	if ( tmp.isEmpty() ) // Setting currentNode_ only if we do have a sibling for it !!!, this is the previous semantics of this method.
		return 0;
	return const_cast<char*>( (currentNode_ = tmp).getName() ); // We have a sibling, so lets assign currentNode_ to it ans return its name.
}

bool ClibIntecXml::FocusOnRoot ()
{
	// Iterating on the documentNode sub _elements_ till we find element of type Node !, the 1st
	// one should be the root node.
	currentNode_ = documentNode_;
	int i = 0;
	while ( !currentNode_.isEmpty() && (currentNode_.isDeclaration() || currentNode_.getName() == 0) )
		currentNode_ = documentNode_.getChildNode(i++);

	return !currentNode_.isEmpty();
}

bool ClibIntecXml::GetData (const char* key, char* value, bool detachedSection) const
{
	if ((key == 0) || (!strcmp(key,"")) )
		return false;

	if (detachedSection)
	{
		XMLNode node = currentNode_.getChildNode(key,0);
		if ( node.isEmpty() )
			return false;

		XMLCSTR txt = node.getText();
		strcpy(value, txt == 0 ? "" : txt);
		return true;
	}
	else
	{
        XMLCSTR val = currentNode_.getAttribute(key,0);
		if ( val == 0 )
			return false;
		strcpy(value,val);
		return true;
	}
}

bool ClibIntecXml::GetData (const char* key, std::string& value, bool detachedSection) const
{
	if ((key == 0) || (!strcmp(key,"")) )
		return false;

	if (detachedSection)
	{
		XMLNode node = currentNode_.getChildNode(key,0);
		if ( node.isEmpty() )
			return false;

		XMLCSTR txt = node.getText();
		value = (txt == NULL) ? "" : txt;
		return true;
	}
	else
	{
		XMLCSTR val = currentNode_.getAttribute(key,0);
		if ( val == 0 )
			return false;
		value = val;
		return true;
	}
}

bool ClibIntecXml::GetData (const char* key,unsigned int & value, bool hex, bool detachedSection) const
{
	char tmp[MAX_LEN];
	if (!GetData(key, tmp, detachedSection))
		return false;
	value = (unsigned int)strtoul(tmp,0,hex ? 16 : 10);
	return true;
}

unsigned int ClibIntecXml::SetBookmark ()
{
	bookMarksMap_.insert(BookmarksMap::value_type(++bookMarkIndex_,currentNode_));
	return bookMarkIndex_;
}

bool ClibIntecXml::FocusOnBookmark (unsigned int bookmarkIndex)
{
	BookmarksMap::const_iterator it;
	it = bookMarksMap_.find(bookmarkIndex);
	if (it == bookMarksMap_.end())
		return false;

	currentNode_ = it->second;
	return true;
}

bool ClibIntecXml::ClearBookmark (unsigned int bookmarkIndex)
{
	BookmarksMap::iterator it;
	it = bookMarksMap_.find(bookmarkIndex);
	if (it == bookMarksMap_.end())
		return false;

	bookMarksMap_.erase(it);
	return true;
}





bool ClibIntecXml::SearchSection (const char* SectionName)
{
  	return true;
}

void ClibIntecXml::GetCurrentSectionName (char* SectionName)
{
	assert(currentNode_.getName());
	strcpy(SectionName,currentNode_.getName()); // CAUTION : Possible buffer overrun.
}

bool ClibIntecXml::AddAttribute (const char* NodeName, const char* AttributeName, const char* Value, unsigned int bookMark)
{
	if(read_)
	{
		return false; //File cannot be modified as it is opened in read-only mode.
	}
	bool    result  = false;
	XMLNode tmpNode = currentNode_;

	if( (NodeName==NULL) && !bookMark )
	{
		result = FocusOnRoot();
	}
	else if(bookMark)
	{
		result = FocusOnBookmark(bookMark);
	}
	else if(NodeName!=NULL)
	{
		result = FocusOnSubSection(NodeName);
	}
	else
	{
		printf("Both Parent Node and BookMark are non-zero, using BookMark to focus of section");
		result = FocusOnBookmark(bookMark);
	}
	if(!result)
	{
		currentNode_ = tmpNode;
		printf("Cannot AddText as unable to Focus on section");
		return false;
	}
	currentNode_.addAttribute(AttributeName,Value);
	currentNode_ = tmpNode;
	return true;
}

bool ClibIntecXml::SkipCommentSection (void)
{
	// The semantics of this method should be the same as FocusOnNextSection() :
	// simply iterating on the sub elements till a Node is found (and not comment or so).
	return (FocusOnNextSection() == 0) ? false : true;
}


XMLNode ClibIntecXml::GetCurrentSectionPtr ()
{
  return currentNode_;
}

bool ClibIntecXml::SearchSubtree (const char* Name, XMLNode pSectionPtr)
{
 	return false;
}

void VisitNode(XMLNode node,const char* NodeName,std::list<XMLNode>& list)
{
	if ( node.isEmpty() )
		return;
	XMLCSTR name = node.getName();
	if ( name )
	{
		if ( !strcmp(name,NodeName) )
			list.push_back(node);
	}
	int nChildNum = node.nChildNode();
	for (int i =0; i < nChildNum; ++i)
		VisitNode(node.getChildNode(i),NodeName,list);
}


std::list<XMLNode> ClibIntecXml::SearchForNode(XMLNode SectionPtr, const char* NodeName)
{
	XMLNode CurrentPtr = SectionPtr;
	// If given section pointer is empty/"NULL", start searching at the root level
	if (CurrentPtr.isEmpty() )
	{
		CurrentPtr = documentNode_;
		int i = 0;
		while ( !CurrentPtr.isEmpty() && (CurrentPtr.isDeclaration() || CurrentPtr.getName() == 0) )
			CurrentPtr = documentNode_.getChildNode(i++);
	}

	// Traversing the tree spanned one level below CurrentPtr , and collecting all of its
	// descendant nodes w/ the same name.
	std::list<XMLNode> nodesList;
	int nChildNode = CurrentPtr.nChildNode();
	for (int i = 0; i < nChildNode; ++i)
		VisitNode(CurrentPtr.getChildNode(i),NodeName,nodesList);

	return nodesList; // Could be empty.
}

bool ClibIntecXml::SearchForNodeWithAttribute(XMLNode SectionPtr, const char* NodeName,
		  const char* AttributeName, const char* AttributeValue)
{
	XMLNode CurrentPtr = SectionPtr;
	// If given section pointer is empty/"NULL", start searching at the root level
	if (CurrentPtr.isEmpty() )
	{
		CurrentPtr = documentNode_;
		int i = 0;
		while ( !CurrentPtr.isEmpty() && (CurrentPtr.isDeclaration() || CurrentPtr.getName() == 0) )
			CurrentPtr = documentNode_.getChildNode(i++);
	}

	// Get the list of nodes with the matching node name
	std::list<XMLNode> nodesList = SearchForNode(CurrentPtr, NodeName);
	std::list<XMLNode>::iterator it,itEnd = nodesList.end();
	for (it = nodesList.begin(); it != itEnd; ++it)
	{
		int     i = 0;
		XMLCSTR value;
		while ( (value = it->getAttribute(AttributeName,i++)) )
		{
			if ( !strcmp(value,AttributeValue) )
			{
				currentNode_ = *it;
				return true;
			}
		}
	}// end of looping of the nodes w/ the requested NodeName.
	return false;
}

bool ClibIntecXml::GetNumOfChildNodes(unsigned int & value)
{
	value = 0;
	if ( !currentNode_.isEmpty() )
		value = currentNode_.nChildNode();
	else
		return false;
	return true;
}
