int equal(vector<int> arr) {
    int minValue = *min_element(arr.begin(), arr.end());
    int minNumSteps = INT_MAX;
    for (int i = 0; i < 3; ++i) {
        int base = minValue - i;
        int numSteps = 0;
        for (int j = 0; j < arr.size(); ++j) {
            int difference = arr[j] - base;
            numSteps += difference / 5 + difference % 5 / 2 + difference % 5 % 2;
        }
        if (numSteps < minNumSteps) {
            minNumSteps = numSteps;
        }
    }
    return minNumSteps;
}