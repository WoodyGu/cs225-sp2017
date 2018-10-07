#ifndef TST_H
#define TST_H
#include <vector>
#include <string>
#include <iostream>
using namespace std;

class TST{
  public:
    struct TSTNode;
    TST(){
      root = NULL;
    }
    bool find1(const string& query);
    //bool find2(TSTNode* curr, const string& query, int index);
    bool findHelper(const string& query, TSTNode* curr, string result, vector<string> v);
    void insert(string word);
    TSTNode* put(TSTNode *node, const string &str, size_t index);
    bool find2(const string& query);
    bool find2Helper(TSTNode* curr, const string& query, size_t index);

    struct TSTNode{
      TSTNode* left;
      TSTNode* right;
      TSTNode* mid;
      char c;
      bool is_end;
      TSTNode(char data):left(NULL),right(NULL),mid(NULL),c(data),is_end(false){/*Nothing*/}
    };
    TSTNode* root;
};
#endif
