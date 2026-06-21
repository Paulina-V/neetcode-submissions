class PrefixNode {
public:
    bool endWord;
    vector<PrefixNode*> children; 

    PrefixNode() {
        endWord = false;
        children = vector<PrefixNode*> (26, nullptr);
    }
};

class PrefixTree {
private:
    PrefixNode* root;
public:
    PrefixTree() {
        root = new PrefixNode();
    }
    
    void insert(string word) {
        PrefixNode* curr = root;
        char cToAdd;
        int arrayIndx;
        for (int i = 0; i < word.length(); i++) {
            cToAdd = word[i];
            arrayIndx = cToAdd - 'a';
            if (curr->children[arrayIndx] == nullptr) { curr->children[arrayIndx] = new PrefixNode(); }
            curr = curr->children[arrayIndx];
        }
        curr->endWord = true;
    }
    
    bool search(string word) {
        PrefixNode* curr = root;
        for (int i = 0; i < word.length(); i++) {
            int arrayIndx = word[i] - 'a';
            if(curr->children[arrayIndx] == nullptr) { 
                return false; 
            }
            curr = curr->children[arrayIndx];
        }
        return curr->endWord == true;
    }

    bool startsWith(string prefix) {
        PrefixNode* curr = root;
        for (char c : prefix) {
            int indx = c - 'a';
            if (curr->children[indx] == nullptr) {
                return false;
            }
            curr = curr->children[indx];
        }
        return true;
    }
};

// each node contains a array to store refs to child nodes which are characters
// node contains a boolean flag to indivdte if its the end of a valid word
// child nodes hold a unique character of the word