#include <iostream>
#include "stackTempleteHeader.h"

using namespace std;

int main()
{
    cout << "Hello world!" << endl;

        int x=9;

    Stack<int> s(30.9);
    Stack<int> s2(100);
    s.push(30);
    s2.push(100);
    s2=s;
   // s2.copy(s).push();
        s.stackDisplay();
            s2.stackDisplay();
   /* s.isStackFull();
    s.isStackEmpty();
    s.stackDisplay();
    s.stackTop();
    s.push(2.8);
    s.isStackFull();
    s.isStackEmpty();
    s.stackDisplay();
     s.stackTop();

         s.push(2.6);
    s.isStackFull();
    s.isStackEmpty();
    s.stackDisplay();
     s.stackTop();

     Stack s2=s;
         s2.push(2.8);
    s2.isStackFull();
    s2.isStackEmpty();
    s2.stackDisplay();
     s2.stackTop();*/
    return 0;
}
