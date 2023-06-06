#include <iostream>
#include <string>

using namespace std;
void assign_pi_to_dyn_3D(float ***&my_3D_array, int row, int col, int d){
        my_3D_array = new float **[row]();
        for(int i = 0; i < row; i++){
                my_3D_array[i] = new float *[col]();
                for(int j = 0; j < col; j++){
                        my_3D_array[i][j] = 0;
                        my_3D_array[i][j] = new float[d]();
                        for(int k = 0; k < d; k++){
                                my_3D_array[i][j][k] = 3.14;
                        }
                }
        }
}
int main() {

        int row=0, col=0, d=0;
        cout << "Let's creat a 3D array :)" << endl;
        cout << "Type a value for row:  ";
        cin >> row;
        cout << "Type a value for col:  ";
        cin >> col;
        cout << "Type a value for depth:  ";
        cin >> d;

        float ***my_3D_array=NULL;
        assign_pi_to_dyn_3D(my_3D_array, row, col, d);

        for(int i = 0; i < row; i++) {
                for(int j = 0; j < col; j++) {
                        delete[] my_3D_array[i][j];
                }
                delete[] my_3D_array[i];
        }
        delete[] my_3D_array;

        return 0;
}
