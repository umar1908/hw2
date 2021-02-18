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
#include <map>
#include <utility>
#include <forward_list>

class Timer{ //класс таймаре
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


class Tester{ //класс тестировщика
private:
  vector<pair<string,int>> table;
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
  void outside_test(T& container,string name="None"){
    auto start=begin(container);
    auto finish=end(container);
    // assert (container.size()==data.size());
    for(auto elem:data){
      *start=elem;
      start++;
    }
    timer.start();
    sort(begin(container),end(container));
    timer.stop();
    cout<<name+"_sort_outside_result="<<timer.get()<<endl;
    table.push_back(pair<string,int>(name+"(outside)",timer.get()));

  }
  template<typename T>
  void inside_test(T& container,string name="None"){
    auto start=begin(container);
    auto finish=end(container);
    // assert (container.size()==data.size());
    for(auto elem:data){
      *start=elem;
      start++;
    }
    timer.start();
    container.sort();
    timer.stop();
    cout<<name+"_sort_inside_result="<<timer.get()<<endl;
    table.push_back(pair<string,int>(name+"(inside)",timer.get()));
  }


  void get_data()const{
    for(auto elem: data){
      cout<<elem<<" ";
    }
  }

  auto get_table()const{
    return table;
  }

};


bool pair_cmp(pair<string,int> rhs, pair<string,int> lhs){ // компаратор для упорядочивания таблицы резульаттов
  if (lhs.second<rhs.second){
    return true;
  }
  return false;
}


int main(){
  system("chcp 1251"); //для корректного отображения кирилицы
  srand(static_cast<unsigned int>(time(0)));
  cout<<endl;
  const int N=100000;






//outside- сортировка внешней функцией std::sort
//inside- сортировка внутренней функцией sort

  Tester tester1(N);
cout<<"Результат в милисекундах\n";
  {
    vector<int> vec(N);
    tester1.outside_test(vec,"vector");
  }
  {
    deque<int> dec(N);
    tester1.outside_test(dec,"deque");
  }
  {
    std::array<int,N> arr;
    tester1.outside_test(arr,"array");
  }
  {
    list<int> lst(N);
    tester1.inside_test(lst,"list");
  }
  {
    forward_list<int> f_lst(N);
    tester1.inside_test(f_lst,"forward_list");
  }


  cout<<"\n\nОтсортированный результат\n";
  auto table=tester1.get_table();
  sort(table.begin(),table.end(),pair_cmp);
  for(auto elem: table){
    cout<<elem.first<<"="<<elem.second<<endl;
  }





}
