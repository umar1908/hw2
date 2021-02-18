#include <iostream>
#include <iomanip>
using namespace std;
// #include <functional>
#include <algorithm>
#include <vector>
// #include <string>
// #include <cmath>
// #include <cstdlib>
// #include<utility>
// #include <exception>
// #include <bitset>
#include <chrono>
#include <ctime>
#include <cassert>
#include <deque>
#include <array>
#include <list>

class Timer{
private:
  chrono::time_point<chrono::steady_clock> start_point;
  chrono::time_point<chrono::steady_clock> stop_point;
  chrono::steady_clock::duration result;
public:
  Timer ()=default;
  chrono::time_point<chrono::steady_clock> start () {
    start_point=chrono::steady_clock::now();
    return start_point;
  }
  chrono::time_point<chrono::steady_clock> stop () {
    stop_point=chrono::steady_clock::now();
    result=stop_point-start_point;
    return stop_point;
  }
  auto get() const{
    return chrono::duration_cast<chrono::milliseconds>(result).count();
  }
};


class Tester{
private:
  Timer timer;
  vector<int> data;
  chrono::steady_clock::duration sort_inside_result;
  chrono::steady_clock::duration sort_outside_result;
public:

  Tester(int n){
    for (size_t i = 0; i < n; i++) {
      data.push_back(rand());
    }
  }

  template <typename T>
  void outside_test(T& container){
    auto start=begin(container);
    auto finish=end(container);
    assert (container.size()==data.size());
    for(auto elem:data){
      *start=elem;
      start++;
    }
    timer.start();
    sort(begin(container),end(container));
    timer.stop();
    cout<<"sort_outside_result="<<timer.get()<<endl;

  }
  template<typename T>
  void inside_test(T& container){
    auto start=begin(container);
    auto finish=end(container);
    assert (container.size()==data.size());
    for(auto elem:data){
      *start=elem;
      start++;
    }
    timer.start();
    container.sort();
    timer.stop();
    cout<<"sort_inside_result="<<timer.get()<<endl;
  }


  void get_data()const{
    for(auto elem: data){
      cout<<elem<<" ";
    }
  }

};


int main(){
  system("chcp 1251"); //для корректного отображения кирилицы
  srand(static_cast<unsigned int>(time(0)));
  cout<<endl;
  const int N=100000;








  Tester tester1(N);

  {
    cout<<"vector\n";
  vector<int> vec(N);
  tester1.outside_test(vec);
  // tester1.inside_test(vec);
  }
  {
    cout<<"\ndeque\n";
  deque<int> dec(N);
  tester1.outside_test(dec);
  // tester1.inside_test(dec);
  }
  {
    cout<<"\narray\n";
  std::array<int,N> arr;
  tester1.outside_test(arr);
  // tester1.inside_test(arr);
  }
  {
    cout<<"\nlist\n";
  list<int> lst(N);
  // tester1.outside_test(arr);
  tester1.inside_test(lst);
  }





}
