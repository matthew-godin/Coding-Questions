string isValid(string s) {
    map<char, int> numOccurrences;
    for (int i = 0; i < s.size(); ++i) {
        if (numOccurrences.find(s[i]) != numOccurrences.end()) {
            ++numOccurrences[s[i]];
        } else {
            numOccurrences[s[i]] = 1;
        }
    }
    auto iter = numOccurrences.begin();
    int commonNumOccurrences;
    bool seenOnceMoreSeen = false;
    bool finalAnswer = true;
    if (iter != numOccurrences.end()) {
        commonNumOccurrences = iter->second;
        ++iter;
    }
    for (; iter != numOccurrences.end(); ++iter) {
        if (commonNumOccurrences != iter->second) {
            if ((commonNumOccurrences + 1 == iter->second || iter->second - 1 == 0) && !seenOnceMoreSeen) {
                seenOnceMoreSeen = true;
            } else {
                finalAnswer = false;
            }
        }
    }
    if (finalAnswer) {
        return "YES";
    }
    finalAnswer = true;
    seenOnceMoreSeen = false;
    iter = numOccurrences.begin();
    ++iter;
    if (iter != numOccurrences.end()) {
        commonNumOccurrences = iter->second;
        --iter;
    }
    for (; iter != numOccurrences.end(); ++iter) {
        if (commonNumOccurrences != iter->second) {
            if ((commonNumOccurrences + 1 == iter->second || iter->second - 1 == 0) && !seenOnceMoreSeen) {
                seenOnceMoreSeen = true;
            } else {
                return "NO";
            }
        }
    }
    return "YES";
}