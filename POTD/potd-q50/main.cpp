#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> zigZag(vector<int> v1, vector<int> v2){

	//write your code here
	std::vector<int> result;
	std::sort(v1.begin(),v1.end());
	std::sort(v2.begin(),v2.end());
	std::reverse(v1.begin(),v1.end());
	std::reverse(v2.begin(),v2.end());
	for(size_t i = 0;i<v1.size();i++){
		result.push_back(v1[i]);
		result.push_back(v2[i]);
	}
	return result;
}


int main(){

vector<int> v1, v2;
v1 = {50,40,20,30,10};
v2 = {1,2,3,4,5};

vector<int>answer = zigZag(v1,v2);

cout << "The zig zag vector is " <<endl;
for (size_t i =0; i < answer.size(); i ++){
	cout << answer[i]<<endl;
}

return 0;

}
