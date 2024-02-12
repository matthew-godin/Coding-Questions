bool solution(std::string line) {
  bool atLeastOneDigit = false;
  if (line[line.size() - 1] == '#') {
    int i = 0;
    int base = 0;
    std::string baseStr;
    for (int j = 0;; ++j) {
      if (line[j] != '_') {
        if (line[j] == '#') {
          break;
        }
        baseStr += line[j];
      } else {
        i++;
      }
    }
    if (baseStr.size() == 1 && baseStr[0] >= '2' && baseStr[0] <= '9') {
      base = std::stoi(baseStr);
      i++;
    } else if (baseStr.size() == 2 && baseStr[0] == '1' && baseStr[1] >='0' && baseStr[1] <= '6') {
      base = std::stoi(baseStr);
      i++;
      i++;
    }
    if (base < 2 || base > 16) {
      return false;
    }
    i++;
    while (i < line.size() - 1) {
      if (line[i] != '_') {
        int digit = -1;
        if ('a' <= line[i] && line[i] <= 'f') {
          digit = int(line[i]) - int('a') + 10;
        }
        if ('A' <= line[i] && line[i] <= 'F') {
          digit = int(line[i]) - int('A') + 10;
        }
        if ('0' <= line[i] && line[i] <= '9') {
          digit = int(line[i]) - int('0');
        }
        if (0 <= digit && digit < base) {
          atLeastOneDigit = true;
        }
        else {
          return false;
        }
      }
      i++;
    }
  }
  else {
    for (int i = 0; i < line.size(); i++) {
      if (line[i] != '_') {
        if ('0' <= line[i] && line[i] <= '9') {
          atLeastOneDigit = true;
        }
        else {
          return false;
        }
      }
    }
  }
  return atLeastOneDigit;
}
