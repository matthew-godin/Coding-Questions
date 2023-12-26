#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

struct DNA {
    int start;
    int end;
    string d;
};

void populateLPS(vector<int> &lps, const string &pattern) {
    int j = 0;
    lps[0] = 0;
    for (int i = 1; i < pattern.length();) {
        if (pattern[i] == pattern[j]) {
            lps[i] = ++j;
            ++i;
        } else {
            if (j > 0) {
                j = lps[j - 1];
            } else {
                lps[i] = 0;
                ++i;
            }
        }
    }
}

int searchKMP(const string &pattern, const string &text) {
    int numOccurrences = 0;
    int j = 0;
    vector<int> lps(pattern.length());
    populateLPS(lps, pattern);
    for (int i = 0; text.length() - i >= pattern.length() - j;) {
        if (pattern[j] == text[i]) {
            ++j;
            ++i;
        }
        if (j == pattern.length()) {
            // Found pattern
            ++numOccurrences;
            j = lps[j - 1];
        } else if (i < text.length() && pattern[j] != text[i]) {
            if (j > 0) {
                j = lps[j - 1];
            } else {
                ++i;
            }
        }
    }
    return numOccurrences;
}

void determineHealth(vector<string> genes, vector<int> health, vector<DNA> dnaStrands) {
    int minHealth = INT_MAX, maxHealth = 0;
    for (int i = 0; i < dnaStrands.size(); ++i) {
        int currentHealth = 0;
        for (int j = dnaStrands[i].start; j <= dnaStrands[i].end; ++j) {
            currentHealth += searchKMP(genes[j], dnaStrands[i].d) * health[j];
        }
        if (currentHealth > maxHealth) {
            maxHealth = currentHealth;
        }
        if (currentHealth < minHealth) {
            minHealth = currentHealth;
        }
    }   
    cout << minHealth << " " << maxHealth << endl;
}

int main()
{
    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string genes_temp_temp;
    getline(cin, genes_temp_temp);

    vector<string> genes_temp = split(rtrim(genes_temp_temp));

    vector<string> genes(n);

    for (int i = 0; i < n; i++) {
        string genes_item = genes_temp[i];

        genes[i] = genes_item;
    }

    string health_temp_temp;
    getline(cin, health_temp_temp);

    vector<string> health_temp = split(rtrim(health_temp_temp));

    vector<int> health(n);

    for (int i = 0; i < n; i++) {
        int health_item = stoi(health_temp[i]);

        health[i] = health_item;
    }

    string s_temp;
    getline(cin, s_temp);

    int s = stoi(ltrim(rtrim(s_temp)));

    vector<DNA> dnaStrands(s);
    for (int s_itr = 0; s_itr < s; s_itr++) {
        string first_multiple_input_temp;
        getline(cin, first_multiple_input_temp);

        vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

        int first = stoi(first_multiple_input[0]);

        int last = stoi(first_multiple_input[1]);

        string d = first_multiple_input[2];
        
        dnaStrands[s_itr].start = first;
        dnaStrands[s_itr].end = last;
        dnaStrands[s_itr].d = d;
    }
    
    determineHealth(genes, health, dnaStrands);

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
