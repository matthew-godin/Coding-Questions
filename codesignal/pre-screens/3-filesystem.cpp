#include "container.hpp"

void Container::Add(int value) {
  container.insert(std::lower_bound(container.begin(), container.end(), value), value);
}

bool Container::Delete(int value) {
  auto it = std::find(container.begin(), container.end(), value);
  if (it != container.end()) {
    container.erase(it);
    return true;
  }
  return false;
}

int Container::GetMedian() {
  if (container.size() == 0) {
    throw std::runtime_error("Empty container");
  }
  return container[container.size() / 2 - (container.size() % 2 == 0 ? 1 : 0)];
}
