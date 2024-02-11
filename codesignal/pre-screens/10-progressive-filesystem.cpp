#ifndef INTEGER_CONTAINER_IMPL_HPP_
#define INTEGER_CONTAINER_IMPL_HPP_

#include "integer_container.hpp"
#include <vector>
#include <algorithm>
using namespace std;

class IntegerContainerImpl : public IntegerContainer {
    vector<int> container;
    
    virtual int Add(int value) {
      container.insert(lower_bound(container.begin(), container.end(), value), value);
      return container.size();
    }
  
    virtual bool Delete(int value) {
      auto it = find(container.begin(), container.end(), value);
      if (it != container.end()) {
        container.erase(it);
        return true;
      }
      return false;
    }
};

#endif  // INTEGER_CONTAINER_IMPL_HPP_
