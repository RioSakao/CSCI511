/**
 * A union is a user-defined type in which all members share the same memory location. 
 * This definition means that at any given time, a union can contain no more than one object from its list of members. 
 * It also means that no matter how many members a union has, it always uses only enough memory to store the largest member.
 *
 *
 * Similarities:
 * Both union and casting manipulate data types.
 *
 */




#include <iostream>

using namespace std;


union Union {
        int num1;
        float num2;
        char num3;
        int *num4;
};        

int main() 
{
    int p = 6;
    int *ptr = &p;
    union Union u;
    
    u.num1 = 100;
    u.num2 = 3.14;
    u.num3 = 'a';
    u.num4 = ptr;
    
    cout << "num1: " << u.num1 << endl;
    cout << "num2: " << u.num2 << endl;
    cout << "num3: " << u.num3 << endl;
    cout << "num4: " << *(u.num4) << endl;

    return 0;
}
