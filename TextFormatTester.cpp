#include "TextFormat.h"

int main(){

    stringstream testStream("*\n"
                            "@this is my test thing so let this be the longest line\n"
                            "@Let this be the second longest loine loine loine\n"
                            "left text#right text\n"
                            "$this can be the wrapped thing\n"
                            "this is just left justified");
/*

    TextFormat testStuff(testStream);

    int titleBarLen = testStuff.getTitleBarLen(); 

    //clearing the string stream
    testStream.str(string());

    testStream << "$this should be in the wrapper\nit is a new object";

    TextFormat test2(testStream, titleBarLen);

    testStream.str(string());

    testStream << "#this should be right justified\n"
               << "*\n";

    TextFormat test3(testStream, titleBarLen);

*/

    testStream.str(string());
    testStream.clear();

/*
    as of sept 27, 2021 this follows an order of precedence, so you cannot do 2 operations per line
    in order to do 2, you need to make it once, edit in your thing and resend to do the 2nd operation
    you can make an immediate change to this by using a loop that checks for all the commands rather then 
    one command per line and move to the next line

    notice the second run has a compounded error to the last line's right justification, this is because
    the sstream used in the all of the classes methods is the one with the commands, which get removed later
    implementation of a remove all cmd would just make the software output more higher quality
*/
    testStream << "*\n"
               << "@this is my test thing so let this be the longest line\n"
               << "@Let this be the second longest loine loine loine\n"
               << "left text---#right text\n"
               << "$this can be the wrapped thing\n"
               << "this is just left justified\n"
               << "$this should be in the wrapper\n"
               << "#this should be right justified\n"
               << "*\n"
               << "\nmanual warped and#right justified\n\n"
               << "#somestuff@otherStuff\n"
               << "*\n";
    
    TextFormat test4(testStream);

    test4.display();

    cout << "\nthis is the second output:\n\n";

    TextFormat test5(test4.getText());

    test5.display();

/*
    testStuff.display();
    test2.display();
    test3.display();

    cout << "\n\n\n\n" ;
*/

}