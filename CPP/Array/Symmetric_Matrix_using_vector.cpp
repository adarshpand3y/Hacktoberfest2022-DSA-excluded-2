// Given a square matrix check if it is symmetric or not. Represent a matrix as a vector of vectors. 
// Use vector in STL to represent a matrix.

// Hint: To create a matrix with 'r' rows and 'c' columns

// vector<vector<int>> m1(r,vector<int>(c,0));

// Input Format

// Dimension of matrix, 'n'

// Element in row1 col1

// Element in row1 col2

// ...

// Element in row1 coln

// Element in row2 col1

// Element in row2 col2

// ...

// Element in row2 coln

// ...

// ...

// Element in rown col1

// Element in rown col2

// ...

// Element in rown coln

// Output Format

// Print Symmetric or Not symmetric 

#include<iostream>
#include<vector>
using namespace std;
int main(){
	vector <vector <int>> row;
	int n,ele;
	cin>>n;
	for(int i=0;i<n;i++){
		vector <int> col; 
		for(int j=0;j<n;j++){
			cin>>ele;
			col.push_back(ele);
		}
		row.push_back(col);
	}

	for(int i=0;i<row.size();i++){
		for(int j=0;j<row[i].size();j++){
			if(row[i][j]==row[j][i]) continue;
			else {
				cout<<"Not symmetric";
				return 0;
			}
		}
	}
	cout<<"Symmetric";
	return 0;
}
