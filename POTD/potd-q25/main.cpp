#include<string.h>
#include <iostream>
using namespace std;


int main(int argc, char** argv) {
  cout<<argc<<argv<<endl;
  if (argc >= 2) {
    string s(argv[1]);

    if(s.length()%6==0){
        cout<<"fortune1"<<endl;
    }
    if(s.length()%6==1){
        cout<<"fortune2"<<endl;
    }
    if(s.length()%6==2){
        cout<<"fortune3"<<endl;
    }
    if(s.length()%6==3){
        cout<<"fortune4"<<endl;
    }
    if(s.length()%6==4){
        cout<<"fortune5"<<endl;
    }
    if(s.length()%6==5){
        cout<<"fortune6"<<endl;
    }

    return 0;
  } else {
    cout<<"Usage: "<<argv[0]<<" <word>"<<endl;
    return 1;
  }
}
