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

    testStream << "*\n"
               << "@this is my test thing so let this be the longest line\n"
               << "@Let this be the second longest loine loine loine\n"
               << "left text#right text\n"
               << "$this can be the wrapped thing\n"
               << "this is just left justified\n"
               << "$this should be in the wrapper\n"
               << "#this should be right justified\n"
               << "*\n"
               << "\nmanual warped and#right justified\n\n"
               << "*\n";
    
    TextFormat test4(testStream);

/*
    testStuff.display();
    test2.display();
    test3.display();

    cout << "\n\n\n\n" ;
*/

    test4.display();
}