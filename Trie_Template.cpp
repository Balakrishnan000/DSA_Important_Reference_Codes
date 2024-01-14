#include<bits/stdc++.h>
using namespace std;

class Node{
    Node* links[26];
    bool fg;

    public:
    Node(){
        for(int i=0; i<26; i++){
            links[i] = NULL;
        }
        fg = false;
    }

    bool containsKey(char ch){
        return (links[ch - 'a'] != NULL);
    }

    Node* get(char ch){
        return links[ch - 'a'];
    }

    void put(char ch, Node* nd){
        links[ch-'a'] = nd;
    }

    void setEnd(){
        fg = true;
    }

    bool isEnd(){
        return fg;
    }
    
};

class Trie {
private:
    Node* root;
public:
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* nd = root;
        for(int i=0; i<word.size(); i++){
            if(!nd->containsKey(word[i])){
                nd->put(word[i], new Node());
            }
            nd = nd->get(word[i]);
        }
        //string done
        nd->setEnd(); //last ch points last node that is set as TRUE
    }
    
    bool search(string word) {
        Node* nd = root;
        for(int i=0; i<word.size(); i++){
            if(!nd->containsKey(word[i])) return false;
            nd = nd->get(word[i]);
        }

        return nd->isEnd();
    }
    
    bool startsWith(string prefix) {
        Node* nd = root;
        for(int i=0; i<prefix.size(); i++){
            if(!nd->containsKey(prefix[i])) return false;
            nd = nd->get(prefix[i]);
        }

        return true;
    }
};

int main()
{
	int n = 5;
	vector<int>type = {1, 1, 2, 3, 2};
	vector<string>value = {"hello", "help", "help", "hel", "hel"};
	Trie trie;
	for (int i = 0; i < n; i++) {
		if (type[i] == 1) {
			trie.insert(value[i]);
		}
		else if (type[i] == 2) {
			if (trie.search(value[i])) {
				cout << "true" << "\n";
			}
			else {
				cout << "false" << "\n";
			}
		}
		else {
			if (trie.startsWith(value[i])) {
				cout << "true" << "\n";
			}
			else {
				cout << "false" << "\n";
			}
		}
	}
}