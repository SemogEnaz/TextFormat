# TextFormat
This is a console text formatting class, I will update it from time to time. Sugestions are welcome.

doc from header file:

/*  Commands:

    @: will center text
    #: will right justify text
    $: will wrap and center text
    *: will generate a title bar

*/

/*  these are some instructions on how to use this namespace

    this namespace is intended for display() functions that use the stringstream stuff where, we incase the text to be displayed on one set of titleBars (see example below). 

    you can specify what parts need to be formatted with a with the abovementioned commands

    eg:

    *
    @Welcome to this program!
    @written by Zane

    leftJustified#rightJustified 
    $wrapAndCenter
    leftJustified2
    *

    in a string stream input, we would write it lke this:

        stringstream testText(""); //you can input the text here, ill just do it later for this demo

        testText.str(string()) //this is to clear the contents but not reset the eof flag, it is redundent here, but just fyi

        testText << "*\n"
                 << "@Welcome to this program!\n"
                 << "@written by Zane\n"
                 << "\nleftJustified#rightJustified\n"
                 << "$wrapAndCenter\n"
                 << "leftJustified2\n"
                 << "*\n"

        TextFormat myText(testText);

        myText.display(); //or you can return the processed stream using .getText();

    in the above example we need to first calculate the len of the title bar 
    "~" thing and then format the console text accordingly using iomanip functions
    we need to use the namespace functions in the display functions of the classes, 

    so, the output (formated text) would look like this:

    ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ //this is a title bar, you can set the character type in the generateTitleBar()
            Welcome to this program!        //centered text
               written by Zane              //centered text

    leftJustified            rightJustified //right justified
    
                 wrapAndCenter              //"\n" appended to the ends of str, ie text is wrapped in "\n" and centered

    leftJustified2                          //left justified(no need to use namespace)
    ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

*/
