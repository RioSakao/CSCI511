#include <iostream>

using namespace std;

void assign_pi_to_static_3D(float static3D[2][4][3], int row, int col, int k ) {

        for(int row = 0; row < 2; row++){
                for(int col = 0; col < 4; col++) {
                        for(int k = 0; k < 3; k++){
                                static3D[row][col][k] = 3.14;
                        }
                }
        }
}

int main() {

        float static3D[2][4][3];
        assign_pi_to_static_3D(static3D, 2, 4, 3);

        return 0;
}
