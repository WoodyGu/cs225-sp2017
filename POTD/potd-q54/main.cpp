#include <iostream>
#include <vector>
using namespace std;
/*
The Problem

There are N students in a class. Some of them are friends, while some are not.
Their friendship is transitive in nature. For example, if A is a direct friend of B, and B is a direct friend of C, then A is an indirect friend of C.
And we defined a friend circle is a group of students who are direct or indirect friends.

Given a N*N matrix M representing the friend relationship between students in the class.
If M[i][j] = 1, then the ith and jth students are direct friends with each other, otherwise not.
And you have to output the total number of friend circles among all the students.

You should use disjoint sets to solve this problem.
Hint: At first, every student belongs to one circle which only contains himself.
Once you find a relationship between two students, "union" the two circles they each belongs to.
Example Input

Student 0 and 1 are friends, student 1 and 2 are friends, student 3 doesn't have any friends. Matrix M = [[1,1,0,0], [1,1,1,0], [0,1,1,0], [0,0,0,1]]
Example Output

Circle 1: student 0 and 1; Circle 2: student 2.

Output: Number of friend circle for class 0 is (correct: 2) is 2.
*/

int find(int elem, vector<int>& parents) {
	// Your codes here.
	if(parents[elem] < 0){
    return elem;
  }
  else{
    parents[elem] = find(parents[elem],parents);
    return find(parents[elem],parents);
  }
}

bool isBigger(int root1, int root2,std::vector<int>& v){
  return abs(v[root1])>=abs(v[root2]);
}

void setunion(int a, int b, std::vector<int>& v){
  int root1 = find(a,v);
  int root2 = find(b,v);
  int newSize = v[root1]+v[root2];
  if(isBigger(root1,root2,v)){
    v[root2] = root1;
    v[root1] = newSize;
  }
  else{
    v[root1] = root2;
    v[root2] = newSize;
  }
}

int findCircleNum(vector<vector<int>>& M) {
        if (M.empty()) return 0;
        int n = M.size();

        vector<int> parents(n);
        for (int i = 0; i < n; i++) { parents[i] = -1; }   // initialize: every student belongs their individual group

        int groups = 0;
        // Your codes here.
				for(size_t stu1 = 0;stu1<M.size();stu1++){
					for(size_t stu2 = 0;stu2<M[0].size();stu2++){
						if(M[stu1][stu2] == 1){//if the two students are friends, set union
							setunion(stu1,stu2,parents);
						}
					}
				}
				for(size_t k = 0;k<parents.size();k++){
					if(parents[k]<0){//find the number of roots
						groups++;
					}
				}
        return groups;
}





int main() {
	vector<vector<int>> M1 = {{1,0,1,0,0}, {0,1,0,1,1}, {1,0,1,0,1}, {0,1,0,1,0}, {0,1,1,0,1}};
	int count1 = findCircleNum(M1);
	cout << "Number of friend circle for class 1 is (correct: 1)"<< count1 << endl;

	vector<vector<int>> M2 = {{1,1,0},{1,1,0},{0,0,1}};
	int count2 = findCircleNum(M2);
	cout << "Number of friend circle for class 2 is (correct: 2)"<< count2 << endl;


	vector<vector<int>> M3 = {{1,1,0,0,0,0},
				{1,1,0,1,0,0},
				{0,0,1,0,1,0},
				{0,1,0,1,0,0},
				{0,0,1,0,1,0},
				{0,0,0,0,0,1}};
	int count3 = findCircleNum(M3);
	cout << "Number of friend circle for class 3 is (correct: 3)"<< count3 << endl;

	return 0;
}
