vector<int> solution(vector<int> numbers) {
    vector<int> result(numbers.size() - 2);
    for (int i = 0; i < numbers.size() - 2; ++i) {
        if (numbers[i] < numbers[i + 1]) {
            if (numbers[i + 1] > numbers[i + 2]) {
                result[i] = 1;
            } else {
                result[i] = 0;
            }
        } else if (numbers[i] > numbers[i + 1]) {
            if (numbers[i + 1] < numbers[i + 2]) {
                result[i] = 1;
            } else {
                result[i] = 0;
            }
        } else {
            result[i] = 0;
        }
    }
    return result;
}