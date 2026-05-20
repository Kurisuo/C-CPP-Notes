#include <monitor.h>
#include <stdio.h>

typedef int32_t i32;

monitor mon { 
    i32 foo;
    i32 bar;
    double arr[100];

    void func1(){}
    void func2(){}

    void mon(){}

}