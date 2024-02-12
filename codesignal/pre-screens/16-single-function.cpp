int solution(int n) {
    std::string s = std::to_string(n);
    int result = 0;
    for (int i = 0; i < s.size(); ++i) {
        result += s[i] - '0';
    }
    return result;
}
