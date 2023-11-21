void countTotal(int &total, vector<int> &fruits, int treePosition, int s, int t) {
     for (int i = 0; i < fruits.size(); ++i) {
        int fruitPosition = treePosition + fruits[i];
        if (fruitPosition >= s && fruitPosition <= t) {
            ++total;
        }
    }
 }

void countApplesAndOranges(int s, int t, int a, int b, vector<int> apples, vector<int> oranges) {
    int totalApples = 0, totalOranges = 0;
    countTotal(totalApples, apples, a, s, t);
    countTotal(totalOranges, oranges, b, s, t);
    cout << totalApples << endl << totalOranges << endl;
}