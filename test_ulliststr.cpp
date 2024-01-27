#include <string>
#include <vector>
#include <iostream>
#include <sstream>

#include "ulliststr.h"

using namespace std;

//Use this file to test your ulliststr implementation before running the test suite

int main(int argc, char* argv[])
{   
    /*
    // cout<<"Hi"<<endl;
    ULListStr list;
    // cout<<"what's up"<<endl;
    string testvalue = "play";
    // list.push_back("fun");
    list.push_back(testvalue);
    cout<<"push back successful"<<endl;
    cout<<list.get(0)<<endl;
    cout<<"list.get successful"<<endl;
    // list.push_front("fun2");
    // cout<<list.get(0)<<endl;
    
    // {"sup", "er", "cal", "i", "frag", "il", "ist", "ic", "exp", "i", "alo", "doc", "ious"}
    */
//    ULListStr frontPushFront;
//    frontPushFront.push_front("sup");
//    frontPushFront.push_front("er");
//    frontPushFront.push_front("cal");
//    frontPushFront.push_front("i");
//    frontPushFront.push_front("i");
//    frontPushFront.push_front("frag");
//    frontPushFront.push_front("il");
//    frontPushFront.push_front("ist");
//    frontPushFront.push_front("ic");
//    frontPushFront.push_front("exp");
//    frontPushFront.push_front("i");
//    frontPushFront.push_front("alo");
//    frontPushFront.push_front("doc");
//    frontPushFront.push_front("ious");
//    cout<<"The thing at the front is "<<frontPushFront.get(0)<<endl;
//    cout<<"post get message"<<endl;

    ULListStr threeItemsAddFront;
    threeItemsAddFront.push_front("768");
    threeItemsAddFront.push_front("1024");
    threeItemsAddFront.push_front("1536");
    cout<<"the number at 0 is "<<threeItemsAddFront.get(0)<<endl;
    cout<<"the number at 1 is "<<threeItemsAddFront.get(1)<<endl;
    cout<<"the number at 2 is "<<threeItemsAddFront.get(2)<<endl; // this don't work
}
