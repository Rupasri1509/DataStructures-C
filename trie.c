#include <stdio.h>
#define N 26

struct TrieNode
{
    char data;
    struct TrieNode* children[N];
    int is_leaf;
};

struct TrieNode* make_trienode(char data)
{
    struct TrieNode* node =malloc(sizeof(struct TrieNode));
    for (int i=0; i<N; i++)
        node->children[i] = NULL;
    node->is_leaf = 0;
    node->data = data;
    return node;
}
struct TrieNode* insert_trie(struct TrieNode* root, char* word)
{
    struct TrieNode* temp = root;

    for (int i=0; word[i] != '\0'; i++) {
        // Get the relative position in the alphabet list
        int idx = (int) word[i] - 'a';
        if (temp->children[idx] == NULL) {
            // If the corresponding child doesn't exist,
            // simply create that child!
            temp->children[idx] = make_trienode(word[i]);
        }
        else {
            // Do nothing. The node already exists
        }
        temp = temp->children[idx];
    }
    // At the end of the word, mark this node as the leaf node
    temp->is_leaf = 1;
    return root;
}
void print_trie(struct TrieNode* root) {
    // Prints the nodes of the trie
    if (!root)
        return;
    struct TrieNode* temp = root;
    printf("%c -> ", temp->data);
    for (int i=0; i<N; i++) {
        print_trie(temp->children[i]);
    }
}

int main() {
    // Driver program for the Trie Data Structure Operations
    struct TrieNode* root = make_trienode('\0');
    int n;
    char str[100];
    printf("ENTER THE NO OF STRINGS:");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%s",&str);
        root=insert_trie(root,str);
    }
    print_trie(root);
    //free_trienode(root);
    return 0;
}
