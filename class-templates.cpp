#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cassert>
using namespace std;

#include <utility>
#include <type_traits>

template <typename Type>
static constexpr bool allowed_types // variable tremplate
= std::is_same<Type, double>::value || std::is_same<Type, int>::value;

template <typename Type> class AddElements final {
    static_assert(allowed_types<Type>,
        "This type is not allowed. Only (double and int are allowed)");
    Type _var1;

public:
    explicit constexpr AddElements(const Type var1) noexcept 
           : _var1{ var1 } {}

    constexpr Type add(const Type var2) const noexcept
           { return _var1 + var2; }
};

template <> class AddElements<std::string> final {
    std::string _var1;

public:
    explicit AddElements(const std::string& var1) noexcept
                 : _var1{ std::move(var1) } {}

    std::string concatenate(const std::string& var2) const noexcept
    {
        return _var1 + var2;
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
