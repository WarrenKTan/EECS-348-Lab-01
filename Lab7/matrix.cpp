#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

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
            string spacing;

            // iterate by row and column
            for (int row = 0; row < SIZE; row++){
                for (int col = 0; col < SIZE; col++){
                    printf("%-3d",data[row][col]);
                }
                cout << endl;
            }
        }

        // 3. Add two matrices (operator overloading for +)
        Matrix operator+(const Matrix& other) const{
            Matrix out;

            // iterate by row and column
            for (int row = 0; row < SIZE; row++){
                for (int col = 0; col < SIZE; col++){
                    out.data[row][col] = data[row][col] + other.data[row][col];
                    // printf("%d + %d\n", this->data[row][col], other.data[row][col]);
                }
                cout << endl;
            }
            cout << "add matrix1 and matrix2" << endl;
            
            return out;
        }

        // 4. Multiply two matrices (operator overloading for *)
        Matrix operator*(const Matrix& other) const{
            Matrix out;
            cout << "multiply matrix1 and matrix2" << endl;
            return out;
        }

        // 5. Compute the sum of matrix diagonal elements
        int sumOfDiagonals() const{
            cout << "add diagonals" << endl;
        }

        // 6. Swap matrix rows
        void swapRows(int row1, int row2){
            if (!(0 <= row1 < SIZE) || !(0 <= row2 < SIZE)){
                cerr << "Invalid indicies!" << endl;
                return;
            }
            cout << "swap row1 and row2" << endl;
        }
};

int main() {
    Matrix mat1;
    cout << "Enter values for Matrix 1:" << endl;
    mat1.readFromStdin();
    cout << "Matrix 1:" << endl;
    mat1.display();

    Matrix mat2;
    cout << "Enter values for Matrix 2:" << endl;
    mat2.readFromStdin();
    cout << "Matrix 2:" << endl;
    mat2.display();

    // Matrix sum = mat1 + mat2;
    // cout << "Sum of matrices:" << endl;
    // sum.display();

    Matrix product = mat1 * mat2;
    cout << "Product of matrices:" << endl;
    product.display();

    cout << "Sum of diagonals of Matrix 1: " << mat1.sumOfDiagonals() << endl;

    mat1.swapRows(0, 2);
    cout << "Matrix 1 after swapping rows:" << endl;
    mat1.display();

    return 0;
}
