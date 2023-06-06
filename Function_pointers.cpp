#include <iostream>

using namespace std;

float add(float n1, float n2) {return n1 + n2;}
float subtract(float n1, float n2) {return n1 - n2;}
float divide(float n1, float n2) {return n1 / n2;}
float multiply(float n1, float n2) {return n1*n2; }
float (*FP_array[4])(float n1, float n2);
int main() 
{
        float (*func)(float, float);
        func = add;
        float add_res = add(10, 2);
        cout << "10 + 2 = " << add_res << endl;
        
        FP_array[0] = add;
        FP_array[1] = subtract;
        FP_array[2] = divide;
        FP_array[3] = multiply;
        float res;
        for (unsigned i = 0; i < 4; i++) {
                res = (*FP_array[i])(10, 2);
                cout << res << endl;
        }

        return 0;
}
