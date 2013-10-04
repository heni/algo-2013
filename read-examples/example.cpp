#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;

void test_1() {
    ifstream in("none.txt");
    if (!in) {
        cerr << "test1: file not found!" << endl;
    }
}

void test_2() {
    ifstream in("test2.txt");
    string line;
    int lineCount = 0;
    if (!in) {
        cerr << "test2: file not found!" << endl;
        return;
    }
    while (true) {
        getline(in, line);
        if (!in)
            break;
        ++lineCount;
    }
    cout << "test2: lines count = " << lineCount << endl;
}

void test_3() {
    ifstream in("test3.txt");
    if (!in) {
        cerr << "test3: file not found!" << endl;
        return;
    }
    int a = rand(), b = rand(), c = rand();
    cout << "test3: init values: " << &a << ", " << &b << ", " << &c << endl;
    cout << "test3: init values (8-base): " << setbase(8) << a << ", " << b << ", " << c << endl;
    cout << "test3: init values (10-base): " << setbase(10) << a << ", " << b << ", " << c << endl;
    cout << "test3: init values (16-base): " << setbase(16) << a << ", " << b << ", " << c << endl;
    cout << setbase(10);
    in >> a >> b >> c;
    cout << "test3: read values: " << a << ", " << b << ", " << c << endl;
    if (!in) {
        cerr << "test3: incorrect file format" << endl;
    } 
}

void test_4() {
    ifstream in("test4.txt");
    if (!in) {
        cerr << "test4: file not found!" << endl;
        return;
    }
    double x = rand();
    cout << "test4: init value: " << x << endl;
    in >> x;
    cout << "test4: read value: " << setiosflags(ios::fixed) << setprecision(3) << x << " " << (x - 123456789) << endl;
    cout << "test4: read value: " << setiosflags(ios::scientific) << setprecision(3) << x << " " << (x - 123456789) << endl;
    if (!in) {
        cerr << "test4: incorrect file format" << endl;
    }
}

void test_5() {
    ifstream in;
    in.exceptions(ios::failbit);
    in.open("test5.txt", ios::in);
    int c;
    in >> c;
    cout << "read value: " << c << endl;
}

int main() {
    try {
        test_1();
        test_2();
        test_3();
        test_4();
        test_5();
    } catch (const exception& e) {
        cerr << "exception handled for some test: " << e.what() << endl;
    }
    return 0;
}
