//1.  Finish the truth table found in the Github folder.  4 rows 13 columns.

#include <iostream>
using namespace std;

int main(int argc, char** argv) {
    bool x,y;
    
    cout<<"X Y !X !Y X&&Y X||Y X^Y X^Y^Y X^Y^X !(X&&Y) "<<
            "!X||!Y !(X||Y) !X&&!Y"<<endl;
    
    x=true;
    y=true;
    cout<<(x?'T':'F')<<" "
        <<(y?'T':'F')<<"  "
        <<(!x?'T':'F')<<"  "
        <<(!y?'T':'F')<<"   "
        <<(x&&y?'T':'F')<<"    "
        <<(x||y?'T':'F')<<"   "
        <<(x^y?'T':'F')<<"    "
        <<(x^y^y?'T':'F')<<"     "
        <<(x^y^x?'T':'F')<<"      "
        <<(!(x&&y)?'T':'F')<<"      "
        <<(!x||!y?'T':'F')<<"        "
        <<(!(x||y)?'T':'F')<<"     "
        <<(!x&&!y?'T':'F')<<"        ";
    cout<<endl;
    
    x=true;
    y=false;
    cout<<(x?'T':'F')<<" "
        <<(y?'T':'F')<<"  "
        <<(!x?'T':'F')<<"  "
        <<(!y?'T':'F')<<"   "
        <<(x&&y?'T':'F')<<"    "
        <<(x||y?'T':'F')<<"   "
        <<(x^y?'T':'F')<<"    "
        <<(x^y^y?'T':'F')<<"     "
        <<(x^y^x?'T':'F')<<"      "
        <<(!(x&&y)?'T':'F')<<"      "
        <<(!x||!y?'T':'F')<<"        "
        <<(!(x||y)?'T':'F')<<"     "
        <<(!x&&!y?'T':'F')<<"        ";
    cout<<endl;
    
    x=false;
    y=true;
        cout<<(x?'T':'F')<<" "
        <<(y?'T':'F')<<"  "
        <<(!x?'T':'F')<<"  "
        <<(!y?'T':'F')<<"   "
        <<(x&&y?'T':'F')<<"    "
        <<(x||y?'T':'F')<<"   "
        <<(x^y?'T':'F')<<"    "
        <<(x^y^y?'T':'F')<<"     "
        <<(x^y^x?'T':'F')<<"      "
        <<(!(x&&y)?'T':'F')<<"      "
        <<(!x||!y?'T':'F')<<"        "
        <<(!(x||y)?'T':'F')<<"     "
        <<(!x&&!y?'T':'F')<<"        ";
    cout<<endl;
    
    x=false;
    y=false;
        cout<<(x?'T':'F')<<" "
        <<(y?'T':'F')<<"  "
        <<(!x?'T':'F')<<"  "
        <<(!y?'T':'F')<<"   "
        <<(x&&y?'T':'F')<<"    "
        <<(x||y?'T':'F')<<"   "
        <<(x^y?'T':'F')<<"    "
        <<(x^y^y?'T':'F')<<"     "
        <<(x^y^x?'T':'F')<<"      "
        <<(!(x&&y)?'T':'F')<<"      "
        <<(!x||!y?'T':'F')<<"        "
        <<(!(x||y)?'T':'F')<<"     "
        <<(!x&&!y?'T':'F')<<"        ";
    cout<<endl;
    
    return 0;
}
