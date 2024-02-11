vector<string> values;

vector<string> solution(vector<vector<string>> queries) {
    vector<string> result(queries.size());
    for (int i = 0; i < queries.size(); ++i) {
        if (queries[i].size() != 2) {
            result[i] = "";
        } else {
            if (queries[i][0] == "ADD") {
                values.push_back(queries[i][1]);
                result[i] = "";
            } else if (queries[i][0] == "EXISTS") {
                if (find(values.begin(), values.end(), queries[i][1]) != values.end()) {
                    result[i] = "true";
                } else {
                    result[i] = "false";
                }
            } else {
                result[i] = "";
            }
        }
    }
    return result;
}