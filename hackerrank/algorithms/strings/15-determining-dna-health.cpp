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

struct AhoCorasickNode {
    map<char, AhoCorasickNode*> edges;
    unordered_set<int> patternsMatched;
    AhoCorasickNode* failNode = nullptr;
    bool isRoot;

    AhoCorasickNode(bool root = false) {
        isRoot = root;
    }
};

class AhoCorasickTrie {
    AhoCorasickNode* root;

    void clearRecursion(AhoCorasickNode* currentNode) {
        for (auto iter = currentNode->edges.begin();
            iter != currentNode->edges.end(); ++iter) {
            clearRecursion(currentNode->edges[iter->first]);
        }
        delete currentNode;
    }

public:
    AhoCorasickTrie(const vector<string> &patterns) {
        root = new AhoCorasickNode(true);
        AhoCorasickNode* currentNode;
        for (int i = 0; i < patterns.size(); ++i) {
            currentNode = root;
            for (int j = 0; j < patterns[i].length(); ++j) {
                if (currentNode->edges.find(patterns[i][j]) == currentNode->edges.end()) {
                    currentNode->edges[patterns[i][j]] = new AhoCorasickNode();
                }
                currentNode = currentNode->edges[patterns[i][j]];
            }
            currentNode->patternsMatched.insert(i);
        }
        queue<AhoCorasickNode*> BFSQueue;
        for (auto iter = root->edges.begin(); iter != root->edges.end(); ++iter) {
            BFSQueue.push(root->edges[iter->first]);
            root->edges[iter->first]->failNode = root;
        }
        while (BFSQueue.size() > 0) {
            currentNode = BFSQueue.front();
            BFSQueue.pop();
            for (auto iter = currentNode->edges.begin();
                iter != currentNode->edges.end(); ++iter) {
                AhoCorasickNode* failNode = currentNode->failNode;
                while (failNode->edges.find(iter->first) == failNode->edges.end()) {
                    if (failNode->isRoot) {
                        currentNode->edges[iter->first]->failNode = root;
                        BFSQueue.push(currentNode->edges[iter->first]);
                        goto AhoCorasickTrieL1;
                    }
                    failNode = failNode->failNode;
                }
                failNode = failNode->edges[iter->first];
                currentNode->edges[iter->first]->failNode = failNode;
                currentNode->edges[iter->first]->patternsMatched.insert(
                    failNode->patternsMatched.begin(), failNode->patternsMatched.end());
                BFSQueue.push(currentNode->edges[iter->first]);
                AhoCorasickTrieL1: ;
            }
        }
    }

    int search(const string &text, const vector<int> &health, int start, int end) {
        int totalHealth = 0;
        AhoCorasickNode* currentNode = root;
        for (int i = 0; i < text.length(); ++i) {
            while (currentNode->edges.find(text[i]) == currentNode->edges.end()) {
                if (currentNode->isRoot) {
                    goto searchL1;
                }
                currentNode = currentNode->failNode;
            }
            currentNode = currentNode->edges[text[i]];
            for (auto iter = currentNode->patternsMatched.begin();
                iter != currentNode->patternsMatched.end(); ++iter) {
                if (*iter >= start && *iter <= end) {
                    totalHealth += health[*iter];
                }
            }
            searchL1: ;
        }
        return totalHealth;
    }

    void clear() {
        clearRecursion(root);
    }
};

void determineHealth(const vector<string> &genes, const vector<int> &health, const vector<DNA> &dnaStrands) {
    AhoCorasickTrie ahoCorasickTrie(genes);
    int minHealth = INT_MAX, maxHealth = 0;
    for (int i = 0; i < dnaStrands.size(); ++i) {
        int currentHealth = ahoCorasickTrie.search(dnaStrands[i].d, health, dnaStrands[i].start, dnaStrands[i].end);
        if (currentHealth > maxHealth) {
            maxHealth = currentHealth;
        }
        if (currentHealth < minHealth) {
            minHealth = currentHealth;
        }
    }
    ahoCorasickTrie.clear();
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
