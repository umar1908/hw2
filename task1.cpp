#include <iostream>
#include <iomanip>
using namespace std;
// #include <functional>
// #include <algorithm>
#include <vector>
// #include <string>
// #include <cmath>
// #include <cstdlib>
// #include<utility>
// #include <exception>
// #include <bitset>

void info(const vector<int>& v){
  cout<<"##############\n"<<v.size()<<endl<<v.capacity()<<endl<<"##############\n"<<endl;
}


void overflow(vector<int>& v){
  cout<<"flag"<<endl;
  unsigned long long int i=0;
  double capacity=v.capacity();
  // vector<int> v;
  while (true){

    v.push_back(i);
    i++;
    if (capacity!=v.capacity()){
      cout<<"ratio="<<v.capacity()/capacity<<endl;
      capacity=v.capacity();
      cout<<"cap="<<capacity<<endl<<endl<<endl;
    }
  }
}


int main(){
  system("chcp 1251");
  cout<<endl;
  vector<int> v;
  info(v);
  v={1,2,3,4,5,6,7,8,9,10};
  info (v);
  v.push_back(100);
  info(v);
  for (size_t i = 0; i < 100; i++) {
    v.push_back(i);
    cout<<"i="<<i<<endl;
    info(v);
  }

  cout<<"________________________"<<endl;
  vector<int> v2;
  v2.reserve(10);
  info (v2);
  v2.reserve(100);
  info(v2);
  v2.reserve(10);
  info(v2);

  vector<int> v3;
  v3.reserve(13);
  // overflow(v3);
  v3.reserve(4.50104e+008);
  // overflow(v3);
  for (size_t i = 0; i < static_cast<int>(4.50104e+008) ; i++) {
    v3.push_back(1);
  }
  info(v3);
  v3.push_back(1);





}
