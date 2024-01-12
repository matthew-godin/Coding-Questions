long getMaximumScore(vector<int> stockPrice) {
	long total = 0;
	unordered_map<int, long> subsequenceTotals;
	for (int i = 0; i < stockPrice.size(); ++i) {
		int indexDifference = stockPrice[i] - i;
		if (subsequenceTotals.find(indexDifference) != subsequenceTotals.end()) {
			subsequenceTotals[indexDifference] += stockPrice[i];
		}
		else {
			subsequenceTotals[indexDifference] = stockPrice[i];
		}
		if (subsequenceTotals[indexDifference] > total) {
			total = subsequenceTotals[indexDifference];
		}
	}
	return total;
}