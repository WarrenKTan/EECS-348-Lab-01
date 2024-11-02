#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cmath>
#include <iomanip>

using namespace std;

const int SIZE = 4; // Global variable for matrix size

class Matrix {
    private:
        int data[SIZE][SIZE];  // 2D array for matrix data (using int for simplicity)

    public:
        void readFromStdin(){
            string fileName;
            string s;
            string line;
            int num;
            int rowCount = 0;
            int colCount = 0;

            // get userInput
            cin >> fileName;

            // test input
            // fileName = "matrix1-data.txt";
            // cout << fileName << endl;
            
            // find file by string and store it in 'myFile'
            ifstream myFile(fileName);
            if (!myFile.is_open()) {
                cerr << "Error opening file!" << endl;
                return;
            }

            // split file by line
            while (getline(myFile, line, '\n')) {
                istringstream stream(line);
                // split result by spaces
                while (getline(stream, s, ' ')){
                    if (s != ""){
                        // parse s to integer, then store it in matrix
                        int num = std::stoi(s);
                        data[rowCount][colCount] = num;

                        // re-adjust the position of next value
                        if (colCount < SIZE - 1){
                            colCount++;
                        }else{
                            colCount = 0;
                            rowCount++;
                        }
                    }
                }
            }

            myFile.close();
        }

        // 2. Display a matrix
        void display() const{
            // get max integer in matrix
            int max = data[0][0];
            for (int row = 0; row < SIZE; row++){
                for (int col = 0; col < SIZE; col++){
                    if (max < data[row][col]){
                        max = data[row][col];
                    }
                }
            }
            
            // adjust width based off max integer
            int width = 0;
            while (pow(10, width) < max)
                width++;
            width++;

            // iterate by row and column
            for (int row = 0; row < SIZE; row++){
                for (int col = 0; col < SIZE; col++){
                    cout << left << setw(width) << data[row][col];
                }
                cout << endl;
            }
        }

        // 3. Add two matrices (operator overloading for +)
        Matrix operator+(const Matrix& other) const{
            // iterate by row and column
            Matrix out;
            for (int row = 0; row < SIZE; row++){
                for (int col = 0; col < SIZE; col++){
                    out.data[row][col] = data[row][col] + other.data[row][col];
                }
            }

            return out;
        }

        // 4. Multiply two matrices (operator overloading for *)
        Matrix operator*(const Matrix& other) const{
            Matrix out;
            int multSum;
            
            // iterate through each index of matricies
            for (int row = 0; row < SIZE; row++){
                for (int col = 0; col < SIZE; col++){
                    // sum all of the multiplications
                    multSum = 0;
                    // sum everything in row times col
                    for (int i = 0; i < SIZE; i++){
                        multSum += data[row][i] * other.data[i][col];
                    }

                    // assign multSum to output matrix
                    out.data[row][col] = multSum;
                }
            }
            
            return out;
        }

        // 5. Compute the sum of matrix diagonal elements
        int sumOfDiagonals() const{
            int sum = 0;
            for (int i = 0; i < SIZE; i++){
                // main diagonal
                sum += data[i][i];

                // secondary diagonal
                sum += data[i][SIZE - i - 1];
            }

            return sum;
        }

        // 6. Swap matrix rows
        void swapRows(int row1, int row2){
            // check valid indicies
            if (!(0 <= row1 < SIZE) || !(0 <= row2 < SIZE)){
                cerr << "Invalid indicies!" << endl;
                return;
            }

            // clone data[row1] to data[row2]
            int tempInt;
            for (int i = 0; i < SIZE; i++){
                tempInt = data[row1][i];
                data[row1][i] = data[row2][i];
                data[row2][i] = tempInt;
            }
        }
};

int main() {
    Matrix mat1;
    cout << "Enter values for Matrix 1:" << endl;
    mat1.readFromStdin();
    cout << endl << "Matrix 1:" << endl;
    mat1.display();

    Matrix mat2;
    cout << endl << "Enter values for Matrix 2:" << endl;
    mat2.readFromStdin();
    cout << endl << "Matrix 2:" << endl;
    mat2.display();

    Matrix sum = mat1 + mat2;
    cout << endl << "Sum of matrices:" << endl;
    sum.display();

    Matrix product = mat1 * mat2;
    cout << endl << "Product of matrices:" << endl;
    product.display();

    cout << endl << "Sum of diagonals of Matrix 1: " << mat1.sumOfDiagonals() << endl;

    mat1.swapRows(0, 2);
    cout << endl << "Matrix 1 after swapping rows:" << endl;
    mat1.display();

    return 0;
}
