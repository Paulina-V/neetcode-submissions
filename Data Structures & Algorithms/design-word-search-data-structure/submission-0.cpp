class PrefixNode {
public:
    vector<PrefixNode*> children;
    bool word;
    PrefixNode(){
        children = vector<PrefixNode*> (26, nullptr);
        word = false;
    }
};

class WordDictionary {
public:
    PrefixNode* root;
    WordDictionary() {
        root = new PrefixNode();
    }
    
    void addWord(string word) {
        PrefixNode* curr = root;
        for (char c : word) {
            if (curr->children[c - 'a'] == nullptr) {
                curr->children[c - 'a'] = new PrefixNode();
            }
            curr = curr->children[c - 'a'];
        }
        curr->word = true;
    }
    
    bool search(string word) {
        return dfs(word, 0, root);
    }
private:
    bool dfs(string word, int j, PrefixNode* root) {
        PrefixNode* curr = root;
        for (int i = j; i < word.length(); i++) {
            char c = word[i];
            if (c != '.') {
                if (curr->children[c - 'a'] == nullptr) {
                    return false;
                }
                curr = curr->children[c - 'a'];
            } else {
                for (PrefixNode* child : curr->children) {
                    if (child != nullptr && dfs(word, i + 1, child)) {
                        return true;
                    }
                }
                return false;
            }
        }
        return curr->word;
    }
};
