#include <bits/stdc++.h>
#include <iostream>
#include <assert.h>
#include <math.h>

using namespace std;


    /*
    
        ENUMERATING THE PRODUCTS:
        1. P1 = (A00 + A11)*(B00 + B11);
        2. P2 = (A10 + A11)*B00; 
        3. P3 = (A00)*(B01 - B11);
        4. P4 = A11*(B10 - B00);
        5. P5 = (A00 + A01)*B11;
        6. P6 = (A10  - A00)*(B00 + B01);
        7. P7 = (A01 - A11)*(B10 + B11);

        C00 = P1 + P4 - P5 + P7;
        C01 = P3 + P5;
        C10 = P2 + P4;
        C11 = P1 - P2 + P3 + P6;

        // lets hope this works

    */



vector <vector<int>> matrixAddBasic(vector <vector<int>> a, vector<vector<int>> b, int sign){
    int m = a.size();
    int n = a[0].size();
    vector <vector<int>> c(m, vector <int> (n));
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(!sign) c[i][j] = a[i][j] + b[i][j];
            else c[i][j] = a[i][j] - b[i][j];
        }
    }
    return c;
}


vector <vector<int>> generateSlice(vector <vector<int>> a, int x1, int x2, int y1, int y2){
    int m = x2 - x1 + 1;
    int n = y2 - y1 + 1;
    vector <vector<int>> response(m, vector<int> (n));
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            response[i][j] = a[x1 + i][y1 + j];
        }
    }
    return response;
}

vector <vector<int>> matrixMultiply(vector <vector<int>> m1, vector <vector<int>> m2){
    int m = m1.size();
    int n = m1[0].size();
    int o = m2[0].size();
    assert(m2.size() == n);
    if(m == 1 && n == 1 && o == 1){
        return {{m1[0][0]*m2[0][0]}};
    }
    int div1 = m/2;
    int div2 = n/2;
    vector <vector<int>> a00 = generateSlice(m1, 0, div1-1, 0, div2-1);
    vector <vector<int>> a01 = generateSlice(m1, 0, div1-1, div2, n-1);
    vector <vector<int>> a10 = generateSlice(m1, div1, m-1, 0, div2-1);
    vector <vector<int>> a11 = generateSlice(m1, div1, m-1, div2, n-1);
    vector <vector<int>> b00 = generateSlice(m2, 0, div1-1, 0, div2-1);
    vector <vector<int>> b01 = generateSlice(m2, 0, div1-1, div2, n-1);
    vector <vector<int>> b10 = generateSlice(m2, div1, m-1, 0, div2-1);
    vector <vector<int>> b11 = generateSlice(m2, div1, m-1, div2, n-1);

    //////////////////// ACTUAL ALGORITHM /////////////////////////////
    vector <vector<int>> p1 = matrixMultiply(matrixAddBasic(a00, a11, 0), matrixAddBasic(b00, b11, 0));
    vector <vector<int>> p2 = matrixMultiply(matrixAddBasic(a10, a11, 0), b00);
    vector <vector<int>> p3 = matrixMultiply(a00, matrixAddBasic(b01, b11, 1));
    vector <vector<int>> p4 = matrixMultiply(a11, matrixAddBasic(b10, b00, 1));
    vector <vector<int>> p5 = matrixMultiply(matrixAddBasic(a00, a01, 0), b11);
    vector <vector<int>> p6 = matrixMultiply(matrixAddBasic(a10, a00, 1), matrixAddBasic(b00, b01, 0));
    vector <vector<int>> p7 = matrixMultiply(matrixAddBasic(a01, a11, 1), matrixAddBasic(b10, b11, 0));

    vector <vector<int>> c00 = matrixAddBasic(p1, matrixAddBasic(p4, matrixAddBasic(p7, p5, 1), 0), 0);
    vector <vector<int>> c01 = matrixAddBasic(p3, p5, 0);
    vector <vector<int>> c10 = matrixAddBasic(p2, p4, 0);
    vector <vector<int>> c11 = matrixAddBasic(p1, matrixAddBasic(p3, matrixAddBasic(p6, p2, 1), 0), 0);

    vector <vector<int>> response(m, vector<int> (o));
    for(int i = 0; i < div1; i++){
        for(int j = 0; j < div2; j++){
            response[i][j] = c00[i][j];
            response[i][div2 + j] = c01[i][j];
            response[div1 + i][j] = c10[i][j];
            response[div1 + i][div2 + j] = c11[i][j];
        }
    }
    return response;
}


int main(){
    int m1, n1, m2, n2; // size of matrices 
    std::cin>>m1>>n1>>m2>>n2;
    int n = max(m1, max(m2, max(n1, n2))); // calculate max dimensions
    int nearestPower = ceil(log2(n));
    n = pow(2, nearestPower);
    cout<<"Nearest Square Size: "<<n<<endl;
    vector <vector<int>> matrix1(n, vector <int> (n, 0));
    vector <vector<int>> matrix2(n, vector<int> (n, 0));
    for(int i = 0; i < m1; i++){
        for(int j = 0; j < n1; j++){
            cin>>matrix1[i][j];
        }
    }    
    for(int i = 0; i < m2; i++){
        for(int j = 0; j < n2; j++) cin>>matrix2[i][j];
    }

    vector <vector<int>> ultra = matrixMultiply(matrix1, matrix2);
    for(int i = 0; i < m1; i++){
        for(int j = 0; j < n2; j++) cout<<ultra[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}

/// In the current state, this algorithm is effective(guaranteed) only for cases where n >= 16408
// Since there are no practical usecases for such an algorithm, we sacrifice on optimality, but using a combination of Strassen
// and standard O(n^3) divide and conquer;