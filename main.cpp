#include <iostream>
#include "menu.h"
//#include "stack.h"

using namespace std;

#ifdef NORMAL_MODE

int main()
{
    cout << "Verem" << endl;

    Menu test;
    test.run();
    /*Stack st = Stack(100);
    st.push(1);
    st.push(2);
    st.isEmpty();
    cout << st << endl;
    cout << st.pop() << endl;
    cout << st.peek() << endl;*/
    

    return 0;
}

#else

#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "stack.h"

//#define TRUE true
//#define FALSE false

TEST_CASE("ures stack letrehozasa", "[stack]") {
    Stack s1(10);
    CHECK(s1.isEmpty());
}

TEST_CASE("ures stackbe uj elem", "[push]") {
    Stack s1(10);
    s1.push(1);
    CHECK(s1.peek() == 1);
}

TEST_CASE("1-et tartalmazo stack-be 2 rapakolasa", "[push]") {
    Stack s1(10);
    s1.push(1);
    s1.push(2);
    CHECK(s1.peek() == 2);
}

TEST_CASE("felso elem kivevese", "[pop]") {
    Stack s1(10);
    s1.push(1);
    CHECK(s1.pop() == 1);
}

TEST_CASE("teli stackbe nem lehet elemet rakni", "[push]") {
    Stack s1(1);
    s1.push(1);
    CHECK_THROWS(s1.push(2));
}

TEST_CASE("ures stackbol kiveves", "[pop]") {
    Stack s1(1);
    CHECK_THROWS(s1.pop());
}

TEST_CASE("ures stackben lekerdezes", "[peek]") {
    Stack s1(1);
    CHECK_THROWS(s1.peek());
}

TEST_CASE("isEmpty", "[isEmpty]") {
    Stack s1(10);
    CHECK(s1.isEmpty() == true);

    s1.push(1);
    CHECK(s1.isEmpty() == false);
}

TEST_CASE("isFull", "[isFull]") {
    Stack s1(1);
    CHECK(s1.isFull() == false);

    s1.push(1);
    CHECK(s1.isFull() == true);
}

#endif