#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

//global variable
unordered_map<int,int> mymap;

int main() {
  mymap.reserve(7000); // <-- try putting it here
  mymap.insert(std::pair<int,int> (10,100));
  std::unordered_map<int,int>::const_iterator iter = mymap.find(10);
  std::cout<<iter->first<<" "<<iter->second;
  return 0;
}
