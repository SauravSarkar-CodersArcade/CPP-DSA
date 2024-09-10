#include <iostream>
using namespace std;
class Printer {
public:
    string _name;
    int _availablePaper;
    Printer(string name, int paper){
        _name = name;
        _availablePaper = paper;
    }
    void PrintDocument(string txtDocument){
        int requiredPaper = txtDocument.length() / 10; // 40 / 10 = 4 pages
        if (requiredPaper > _availablePaper){
//            throw 404;
            throw "Printer is out of paper. Add paper..!!";
        }
        cout << "Printing..!! " << txtDocument << endl;
        _availablePaper -= requiredPaper;
    }
};
int main() {
    Printer printer("CANON-5620-Di", 10);
    try {
        printer.PrintDocument
                ("Anvitha is a Software Developer.");
        printer.PrintDocument
                ("Chaithanya is a Software Developer.");
        printer.PrintDocument
                ("Saurav is a Technical Trainer.");
        printer.PrintDocument
                ("Ashank is a Technical Trainer.");
    }catch (int errorCode){
        cout << errorCode << "! Out of Paper. Add more Paper....!!!" << endl;
    }
    catch (const char * textException){
        cout << "Exception: " << textException << endl;
    }
    catch (...){
        cout << "Exception: Something Unexpected Happened...!!!!" << endl;
    }
    cout << printer._availablePaper << endl;
    return 0;
}
