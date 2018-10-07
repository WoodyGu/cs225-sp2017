#include <iostream>
#include <vector>
#include <unordered_map>
#include <utility>
#include <iostream>

using namespace std;


vector<int> orderedGroup(int arr[], int size) {
    // Your Code Here
    std::unordered_map<int,int> dict;
    std::vector<int> retval;
    std::vector<int> order;
    //initialize the dictionary
    for(int i = 0;i<size;i++){
      auto lookup = dict.find(arr[i]);
      if(lookup == dict.end()){
        dict.insert({arr[i],1});
        order.push_back(arr[i]);
      }
      else{
        lookup->second++;
      }
    }
    for(size_t j= 0;j<order.size();j++){
      for(int k = 0;k<dict[order[j]];k++){
        retval.push_back(order[j]);
      }
    }
    return retval;
}


void printVector(vector<int> vec) {
    cout << "Output: <";
    for (size_t i = 0; i < vec.size(); i++)
        cout << "  " << vec[i];
    cout << " >" << endl;
}

int main() {
    // Test1
    int arr1[] = {1, 2, 2, 3, 2, 3, 4};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    printVector(orderedGroup(arr1, n1)); // Output: <1, 2, 2, 2, 3, 3, 4 >
    //cout<<"<1, 2, 2, 2, 3, 3, 4 >"<<endl;
    // Test2
    int arr2[] = {1, 2, 3, 2, 5, 6, 5};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    printVector(orderedGroup(arr2, n2)); // Output: <1, 2, 2, 3, 5, 5, 6 >
    //cout<<"<1, 2, 2, 3, 5, 5, 6 >"<<endl;
    // Test3
    int arr3[] = {2, 4, 1, 3, 3, 2, 4, 1, 1, 2, 4, 3};
    int n3 = sizeof(arr3) / sizeof(arr3[0]);
    printVector(orderedGroup(arr3, n3)); // Output: <2, 2, 2, 4, 4, 4, 1, 1, 1, 3, 3, 3 >
    //cout<<"<2, 2, 2, 4, 4, 4, 1, 1, 1, 3, 3, 3 >"<<endl;
    return 0;
}
