#include <iostream>
#include <string>
using namespace std;

class TrieNode
{
public:
    char data;
    TrieNode *children[26];
    bool isTerminal;

    // constructor :
    TrieNode(char ch)
    {
        data = ch;
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL; // initially all the children are NULL
        }
        isTerminal = false;
    }
    
};

class Trie
{
public:
    TrieNode *root; // start yahan se hoga trie

    // constructor :
    Trie()
    {
        root = new TrieNode('\0'); // root node ko start krdiya null charavter se
    }

    void insertUtil(TrieNode *root, string word)
    {
        // base case :
        if (word.length() == 0)
        { // hr call me pehle char chodke baaki ki string aage pass krrhe hai
            root->isTerminal = true;
            return;
        }

        // assumption words in CAPS
        int index = word[0] - 'A'; // word ka pehla index dekh rhe hai ki present hai ya nhi
        TrieNode *child;

        // if present
        if (root->children[index] != NULL)
        {
            // just aage bdh jao
            child = root->children[index];
        }
        else
        {
            // insert
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        // recursively calls
        insertUtil(child, word.substr(1)); // oehle word chodke in each function call aage ki subtring pass krdi
    }

    void insertWord(string word)
    {
        // word to be inserted
        insertUtil(root, word);
    }

    bool searchUtil(TrieNode *root, string word)
    {
        // base case :
        if (word.length() == 0)
        { // last letter of the word is terminal or not
            return root->isTerminal;
        }

        int index = word[0] - 'A'; // word ka pehla index dekh rhe hai ki present hai ya nhi
        TrieNode *child;

        // if present
        if (root->children[index] != NULL)
        {
            // just aage bdh jao
            child = root->children[index];
        }
        else
        {
            // not present then just return false
            return false;
        }

        // recursively calls
        return searchUtil(child, word.substr(1)); // oehle word chodke in each function call aage ki subtring pass krdi
    }

    bool searchWord(string word)
    {
        return searchUtil(root, word);
    }

    bool prefixutil(TrieNode *root, string word)
    {
        if (word.length() == 0)
        {
            return true;
        }

        int index = word[0] - 'A';
        TrieNode *child;
        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            return false;
        }
        return prefixutil(child, word.substr(1));
    }
    /** Returns if there is any word in the trie that starts with the given prefix. eg : time is inserted into the dictionary
     check whether there are any word which starts with prefix "ti"*/
    bool startsWith(string prefix)
    {
        return prefixutil(root, prefix);
    }

    /*
        method 1 : to delete the nodes
        void deleteUtil(TrieNode *root, string word)
        {
            // base case :
            if (word.length() == 0)
            {
                root->isTerminal = false; // isTerminal ko false krdiya taki vo word dobara search krne pr na mile
                return;
            }

            int index = word[0] - 'A'; // word ka pehla index dekh rhe hai ki present hai ya nhi

            /*TrieNode *child;

            if (root->children[index] != NULL)
            {
                // just aage bdh jao
                child = root->children[index];
            }  //

            TrieNode* child = root->children[index]; //either use this or above multi line commented block
            deleteUtil(child, word.substr(1));
        }
    */
    /*
        void deleteWord(string word)
        {
            deleteUtil(root, word);
        }*/

// method 2 : since method 1 is not space optimal way to delete , so method 2 is there it will completely delete the node
    bool isEmpty(TrieNode* root){
        bool isBool = true;
        for(int i = 0;i<26;i++){
            if(root->children[i]){
                isBool = false;
                break;
            }
        }
        return isBool;
    }
    void delete2Util(TrieNode *root, string word)
    {
          //base case :
          if(word.length()==0){
            return ;
          }

          int index = word[0]-'A';
          TrieNode* child;
          if(root->children[index]!=NULL){
             child = root->children[index];
          }

          delete2Util(child,word.substr(1));

          if(isEmpty(child)){
            root->children[index]=NULL;
            delete child;
            child = NULL;
          }
    }

    void delete2Word(string word)
    {
       delete2Util(root, word);
    }
};
int main()
{
    Trie *t = new Trie(); // Trie* t = new Trie() ---> both valid here as no parameter is there in the constructor of Trie

    t->insertWord("ABCD");
    t->insertWord("ARM");
    t->insertWord("TIME");
    cout << "Present or Not : " << t->searchWord("ABCD") << endl;
    cout << "Present or Not : " << t->searchWord("TIM") << endl;

/*
    // delete "ABCD"
    t->deleteWord("ABCD");
    cout << "Present or Not : " << t->searchWord("ABCD") << endl;
*/
    cout<<"the given prefix is present or not : "<<t->startsWith("AB")<<endl;

    t->delete2Word("ABCD");
    cout<<"Present or not : "<<t->searchWord("ABCD")<<endl;
    cout<<"prefix present or not : "<<t->startsWith("A")<<endl;
    cout<<"prefix present or not : "<<t->startsWith("AB")<<endl;
    return 0;
}