long marcsCakewalk(vector<int> calorie) {
    long total = 0;
    sort(calorie.begin(), calorie.end());
    int j = 0;
    for (int i = calorie.size() - 1; i >= 0; --i, ++j) {
        total += pow(2, j) * calorie[i];
    }
    return total;
}