bool solution(string inputString) {
    for (int i = 0; i < inputString.size() / 2; ++i) {
        if (inputString[i] != inputString[inputString.size() - i - 1]) {
            return false;
        }
    }
    return true;
}
