#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cassert>
using namespace std;

//Speed up io-based programs
#define cin ios_base::sync_with_stdio(false);cin.tie(NULL); cin
#define add concatenate

template<typename T>
class AddElements {
    T val;
public:
    AddElements(T arg) {
        val = arg;
    }

    T add(T sec_arg) {
        return val + sec_arg;
    }
};



int main () {
  int n,i;
  cin >> n;
  for(i=0;i<n;i++) {
    string type;
    cin >> type;
    if(type=="float") {
        double element1,element2;
        cin >> element1 >> element2;
        AddElements<double> myfloat (element1);
        cout << myfloat.add(element2) << endl;
    }
    else if(type == "int") {
        int element1, element2;
        cin >> element1 >> element2;
        AddElements<int> myint (element1);
        cout << myint.add(element2) << endl;
    }
    else if(type == "string") {
        string element1, element2;
        cin >> element1 >> element2;
        AddElements<string> mystring (element1);
        cout << mystring.concatenate(element2) << endl;
    }
  }
  return 0;
}


/*
	INPUT FORMAT
    3
    string John Doe
    int 1 2
    float 4.0 1.5

	EXPECTED OUTPUT
    JohnDoe
    3
    5.5

*/
