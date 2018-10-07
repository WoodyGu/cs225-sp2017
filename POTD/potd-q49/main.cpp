#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <string>
using namespace std;

vector<int> checkSums(vector<int> v){
	//write your code here
	std::vector<int> v2 = v;
	std::vector<int> sums;
	std::sort(v2.begin(),v2.end());
	size_t lastIndex = v2.size()-1;
	sums.push_back(v2[lastIndex]+v2[lastIndex-1]);
	sums.push_back(v2[0]+v2[1]);
	return sums;
}


int main(){

vector<int> v1;

v1 = {20,32,12,65,0,19,76,15,2,39};

vector<int>answer = checkSums(v1);

cout << "The sum of the sum of the largest two elements is " << answer[0] <<endl;
cout << "The sum of the sum of the smallest two elements is " << answer[1] <<endl;

return 0;

}
