#include <iostream>
#include "stack.h"

using namespace std;

int main()
{
    Stack st = Stack();

    st.push(5);
    st.push(10);
    //st.pop();
    //cout << st.pop() << endl;
    st.toString();

    return 0;
}
