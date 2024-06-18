#include<stdio.h>
#define N 26
struct trie
{
    char data;
    struct trie child[N];
    int l;
};

