#include <iostream>
#include <cstdio>   
using namespace std;

int main() {
    int integer_value = 42;
    float float_value = 3.14159265f;
    double double_value = 3.14159265;
    char char_value = 'X';
    const char* string_value = "Hello, World!";

    printf("Format Specifier Practice\n");
    printf("------------------------\n\n");

    //Integer formats
    printf("Integer formats:\n");

    printf("Decimal: %d\n", integer_value);
    //print integer in decimal(base 10)

    printf("Hexadecimal: 0x%x\n", integer_value);
    //print integer in hexadecimal(base 16)

    printf("Octal: 0%o\n", integer_value);
    //print integer in octal(base 8)

    printf("With width (5): |%5d|\n", integer_value);
    //print integer in width of 5 characters, right-aligned

    printf("Left-aligned: |%-5d|\n\n", integer_value);
    //print integer in width of 5 characters, left-aligned


    //Float formats
    printf("Float formats:\n");

    printf("Default: %f\n", float_value);
    //print floating-point number(default precision ~6)

    printf("With precision (2): %.2f\n", float_value);
    //print float with 2 digits after decimal point

    printf("Scientific: %e\n", float_value);
    //print scientific notation(exponential form)

    printf("Fixed with precision (4): %.4f\n\n", float_value);
    //print float with 4digits after decimal point

    //Character and String formats
    printf("Character and String formats:\n");

    printf("Character: %c\n", char_value);
    //print single character

    printf("String: %s\n", string_value);
    //print C-style string

    printf("String with width (20): |%20s|\n", string_value);
    //print string right-aligned in a field of width 20

    return 0;
}