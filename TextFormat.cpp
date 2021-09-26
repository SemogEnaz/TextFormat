
#include "TextFormat.h"

//this is for calculating the title bar
TextFormat::TextFormat(stringstream& inputStr)
: originalInputString(inputStr.str())
{
    processInput(FINDTITLE);
}

//this is to use a pre-set value, the user can specify the length to set in the constructor
TextFormat::TextFormat(stringstream& inputStr, int lenOfBar2Set)
: originalInputString(inputStr.str()),
  titleBarLength(lenOfBar2Set)
{
    processInput(USESETTITLE);
}

void TextFormat::processInput(TextFormatEnum barLenChoice)
{
    string lineData = "";

    size_t indexCenter = 0;
    size_t indexJustify = 0;
    size_t indexWrap = 0;
    size_t indexBar = 0;

    //when using, you can set the title pre function call and mention it in the second argument and then just the hard value or you can opt for the deduction by the program (5% larger) MAKE CONSTRUCTOR OPTION TO BE ABLE TO CHANGE THE %INCREASE
    if (barLenChoice == FINDTITLE)
        calculateBarLength();

    while(getline(originalInputString, lineData))
    {
        //now we search the string for the commands

        indexCenter = lineData.find(centerChar);
        indexJustify = lineData.find(justifyChar);
        indexWrap = lineData.find(wrapChar);
        indexBar = lineData.find(barChar);

        if (indexCenter != std::string::npos)
        { 
            removeCmdChar(lineData, centerChar);
            centerText(lineData);
        }
        else if (indexJustify != std::string::npos)
            justifyText(lineData);
        else if (indexWrap != std::string::npos)
        {
            removeCmdChar(lineData, wrapChar);
            centerTextWrapper(lineData);
        }
        else if (indexBar != std::string::npos)
            appendTitleBar();
        else
            outputString << lineData << "\n";
    }
}

bool checkForEven(int num)
{
    if(num % 2 == 0)
        return true;
    
    return false;
}

//find the bar length needed and 
void TextFormat::calculateBarLength()
{
    //THERE IS A MINOR ERROR IN THIS FUNCTION, THE LENGTH OF THE TITLE BAR IS FOUND USING THE INPUT WITH COMMAND CHARACTERS, THESE WILL BE REMOVED LATER, THEN THE CENTERING WILL BE OFF BY +/- ONE CHAR, YOU NEED TO FIX THAT LATER BY MAKING THE removeAllCmdChar() function in this class;
    titleBarLength = 0;

    bool isTitleBarLenEven = false;
    bool isLineLenEven = false;

    stringstream inputString(originalInputString.str());
    string lineData = "";

    //finding the longest line in the input string
    //the longest line will probably have a command, that will be erased in processing so we substract one form the line length
    while (getline(inputString, lineData))
        if (((int)lineData.length()-1) > titleBarLength)
            titleBarLength = ((int)lineData.length()-1);

    isLineLenEven = checkForEven((int)lineData.length());

    //title 5% > longest line, so:
    titleBarLength = round(titleBarLength + (titleBarLength*0.05));

    isTitleBarLenEven = checkForEven(titleBarLength);

    if (!isTitleBarLenEven && isLineLenEven)
        titleBarLength++;
}

void TextFormat::appendTitleBar()
{
    stringstream titleBar("");

    for (int i = 0; i < titleBarLength; i++)
        outputString << titleBarChar;

    outputString << "\n";

}

void TextFormat::centerText(string& text2Center)
{
    int textLength = (int)text2Center.length();

    //this calculates the space needed to shift the text to center it relative to the titleBar
    int spaceToCenter = round((titleBarLength - textLength) / 2);

    putSpace(textLength, spaceToCenter);

    outputString << text2Center << "\n";
}

void TextFormat::justifyText(string& text2Justify)
{
    //example argument: "this is my left text#this is my right text"

    //-1 because the justifyChar character will be replaced with ""
    int textLength = (int)text2Justify.length() - 1;

    int lenLeftText = 0;

    if (text2Justify[0] != justifyChar)
        //index of the left text = 0
        lenLeftText = text2Justify.find(justifyChar); 
    
    //we will not add one as that character will be replaced with "" later
    int indexRightText = text2Justify.find(justifyChar);
    int lenRightText = textLength - indexRightText;

    removeCmdChar(text2Justify, justifyChar);

    int space2end = (titleBarLength - (lenLeftText + lenRightText));

    //left text
    outputString << text2Justify.substr(0, lenLeftText);

    putSpace(textLength, space2end);

    //right text
    outputString << right << text2Justify.substr(indexRightText, lenRightText) << "\n";
}

void TextFormat::centerTextWrapper(string& text2center)
{
    //this is centerText but with next lines on the top and bottom
    outputString << "\n";
    centerText(text2center);
    outputString << "\n";
}

void TextFormat::removeCmdChar(string& lineData, char commandStr)
{
    int indexOfCommand = lineData.find(commandStr);
    lineData.replace(indexOfCommand, 1, "");
}

void TextFormat::putSpace(int textLength, int space2insert)
{
    //this controle structure checks to prevent negative width
    if (titleBarLength > textLength)
    {    
        for(int i = 0; i < space2insert; i++)
            outputString << " ";
    }
    else
        cout << "titleBarLength < textLength";
}

void TextFormat::display()
{
    cout << outputString.str();
}    

int TextFormat::getTitleBarLen()
{
    return titleBarLength;
}

stringstream& TextFormat::getText()
{
    return outputString;
}