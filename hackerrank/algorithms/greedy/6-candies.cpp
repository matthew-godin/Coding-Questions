long candies(int n, vector<int> arr) {
    vector<int> candies(n, 1);
    for (int i = 0; i < n - 1; ++i) {
        if (arr[i] < arr[i + 1]) {
            candies[i + 1] += candies[i];
        }
    }
    for (int i = n - 2; i >= 0; --i) {
        if (arr[i] > arr[i + 1] && candies[i] <= candies[i + 1]) {
            candies[i] = candies[i + 1] + 1;
        }
    }
    return accumulate(candies.begin(), candies.end(), (long)0);
}