#ifndef StrConvert_h
#define StrConvert_h 1

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

template <class T>
class StrConvert
{

  public:

      static std::string convertToStr (const T& value, int decPoint = 5);

      static std::string convertToStrHex (const T& value, int decPoint = 5, bool add0x=true);

      static const T convertFromStr (const std::string& value);
      static const T convertFromStrHex (const std::string& value);


  protected:

  private:

  private:

};

template <class T>
inline std::string StrConvert<T>::convertToStr (const T& value, int decPoint)
{
    std::stringstream strStream("");

    // Set the precision of the stream
    strStream.precision(decPoint);

    if (!(strStream << value)) { return ""; }
    else                       { return strStream.str();}
}

template <class T>
inline std::string StrConvert<T>::convertToStrHex (const T& value, int decPoint, bool add0x)
{
    std::stringstream strStream("");

    // Set the precision of the stream
    strStream.precision(decPoint);

	if (add0x)	{ strStream << "0x" << std::hex << value;	}
	else        {strStream << std::hex << value;	}

    if (!strStream)					  { return ""; 	}
    else                              { return strStream.str();}
}

template <class T>
inline const T StrConvert<T>::convertFromStr (const std::string& value)
{
    std::stringstream strStream("");
    T result;

    // Copy input string to temporary result value
    strStream << value;
    strStream >> result;

    return result;
}

template <class T>
inline const T StrConvert<T>::convertFromStrHex (const std::string& value)
{
    std::stringstream strStream("");
    T result;

    // Copy input string to temporary result value
    strStream << value; //std::hex << value.substr(2);
    strStream >> std::hex >> result;

    return result;
}

class CStrCnv
{
public:
    static void strToUpper(std::string& data)
    {
        std::transform(data.begin(), data.end(),data.begin(), ::toupper);
    }

    static void strToLower(std::string& data)
    {
        std::transform(data.begin(), data.end(),data.begin(), ::tolower);
    }

    static void strToTokens(const std::string& sourceStr, std::vector<std::string>& vTokens, const char& del)
    {
        std::stringstream tokensStream("");
        std::string strToken("");

        // Copy source string to strings stream
        tokensStream << sourceStr;

        while (!tokensStream.eof()) // While still tokens in the stream
        {
            getline(tokensStream,strToken,del);  // Read next token
            if (!strToken.empty())  // Do not insert "empty" tokens
            {
                vTokens.push_back(strToken);         // Store token to a list
            }
        }

        return;
    }

    static void strGetToken(const std::string& sourceStr, std::string& token, const char& del, const int& index)
    {
        std::vector<std::string> vTokens;

        strToTokens(sourceStr,vTokens,del);  // Convert to tokens list
        if (index >= (int)vTokens.size())  // Check if legal index
        {
            token = "NOT_FOUND";
            return;
        }

        token = vTokens[index];  // Store token index

        return;
    }

    static void strRemoveToken(std::string& sourceStr, const char& del, const int& index)
    {
        // Note: the index parameters is counted form "0"

        std::string::size_type curPos=0, prevPos = 0;
        std::string tmpStr = del+sourceStr;

        // Locate the correct delimiter
        for (int i = 0; i < index+1; i++)
        {
            curPos  = tmpStr.find(del,curPos+1);

            // If illegal index
            if (curPos == std::string::npos)
                return;
        }
        // Find preceding delimiter
        prevPos = tmpStr.rfind(del,curPos-1);
        // Erase token
        tmpStr.erase(prevPos,curPos-prevPos);

        // Remove preceding delimiter
        sourceStr = tmpStr.substr(1);
    }

    static void strInsertToken(std::string& sourceStr, const std::string& token, const std::string& del, const int& index)
    {
        // Note: the index parameters is counted form "0"

        std::string::size_type curPos=0;
        std::string tmpStr = del+sourceStr;

        // Locate the correct delimiter
        for (int i = 0; i < index; i++)
        {
            curPos  = tmpStr.find(del,curPos+1);

            // If illegal index
            if (curPos == std::string::npos)
                return;
        }

        // Erase token
        tmpStr.insert(curPos+1,token+del);

        // Remove preceding delimiter
        sourceStr = tmpStr.substr(1);
    }

    static bool strReplace(std::string& sourceStr, const std::string& oldStr, const std::string& newStr)
    {
        std::string::size_type curPos=0;

        // Find the occurrence of the old string
        curPos  = sourceStr.find(oldStr,curPos);

        // If found
        if (curPos != std::string::npos)
        {
            // Replace the oldStr with newSrt
            sourceStr.replace(curPos, oldStr.size(),newStr);
            return true;
        }

        return false;
    }

    static void StrReplaceDelimiter(std::string& sourceStr, const std::string& oldDel, const std::string& newDel)
    {

        bool delFound = true;

        // While there are occurrences of oldDel in sourceStr
        while (delFound == true)
        {
            // Replace the oldDel with newDel
            delFound = strReplace(sourceStr,oldDel,newDel);
        }
    }
};
#endif
