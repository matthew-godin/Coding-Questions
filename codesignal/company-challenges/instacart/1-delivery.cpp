vector<bool> solution(vector<int> order, vector<vector<int>> shoppers) {
    vector<bool> result(shoppers.size());
    int latestTime = order[1] + order[2];
    for (int i = 0; i < shoppers.size(); ++i) {
        float timeArriving = (order[0] + shoppers[i][0]) / (float)shoppers[i][1] + shoppers[i][2];
        result[i] = timeArriving >= order[1] && timeArriving <= latestTime;
    }
    return result;
}