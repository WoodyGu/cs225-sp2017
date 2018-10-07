/* Problem of the Day #2 */

#include <ctime>
#include <iostream>

using namespace std;

int main() {
  time_t sec_since_epoch = time(nullptr);
  int hour = sec_since_epoch/3600;
  int day = hour/24;
  int year = day/365;
  cout<<"Hours: "<<hour<<endl;
  cout<<"Days: "<<day<<endl;
  cout<<"Years: "<<year<<endl;
  return 0;
}
