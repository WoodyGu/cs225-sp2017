#include <iostream>
#include <vector>
#include <string>
using namespace std;

int hashFunction(string s, int M) {
   // Your Code Here
   //hash function to sum up the ASCII characters of the letters of the string
   int sumOfChar = 0;
   for(size_t i = 0; i< s.size(); i++){
     sumOfChar = (int)s[i] + sumOfChar;
   }
   return (sumOfChar%M);
 }

int countCollisions (int M, vector<string> inputs) {
	int collisions = 0;
	// Your Code Here
  collisions = inputs.size()-2*M;
	return collisions;
}

 int main() {
 	vector<string> inputs {"hi", "i", "richa", "TA", "CS225","fi","hello","weare",
 	"always","there","for","you","valspar","ri","sh","tg","uf","the", "frogurt", "is",
 	"also", "cursed","Whats", "your", "name", "Homer", "Simpson", "What", "is", "favorite",
 	"team", "The", "Isotopes", "I", "like", "too"};

 	for (int i=1; i<=11; i++) {
 		cout<< "performing hash on the inputs with array size " << to_string(i) << " =>\t"<< to_string(countCollisions(i, inputs)) << endl;
 	}
 	return 1;
 }
