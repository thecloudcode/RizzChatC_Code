#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TREE_NODES 256

typedef struct HuffmanNode {
    char data;
    unsigned freq;
    struct HuffmanNode* left;
    struct HuffmanNode* right;
} HuffmanNode;

typedef struct PriorityQueue {
    HuffmanNode** array;
    int size;
    int capacity;
} PriorityQueue;

HuffmanNode* newHuffmanNode(char data, unsigned freq) {
    HuffmanNode* newNode = (HuffmanNode*)malloc(sizeof(HuffmanNode));
    newNode->data = data;
    newNode->freq = freq;
    newNode->left = newNode->right = NULL;
    return newNode;
}

PriorityQueue* createPriorityQueue(int capacity) {
    PriorityQueue* pq = (PriorityQueue*)malloc(sizeof(PriorityQueue));
    pq->size = 0;
    pq->capacity = capacity;
    pq->array = (HuffmanNode**)malloc(capacity * sizeof(HuffmanNode*));
    return pq;
}

void swapNodes(HuffmanNode** a, HuffmanNode** b) {
    HuffmanNode* t = *a;
    *a = *b;
    *b = t;
}

void minHeapify(PriorityQueue* pq, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < pq->size && pq->array[left]->freq < pq->array[smallest]->freq)
        smallest = left;
    
    if (right < pq->size && pq->array[right]->freq < pq->array[smallest]->freq)
        smallest = right;

    if (smallest != i) {
        swapNodes(&pq->array[i], &pq->array[smallest]);
        minHeapify(pq, smallest);
    }
}

HuffmanNode* buildHuffmanTree(char data[], unsigned freq[], int size) {
    PriorityQueue* pq = createPriorityQueue(size);

    for (int i = 0; i < size; ++i)
        pq->array[i] = newHuffmanNode(data[i], freq[i]);

    pq->size = size;
    for (int i = size / 2 - 1; i >= 0; --i)
        minHeapify(pq, i);

    while (pq->size > 1) {
        HuffmanNode* left = pq->array[0];
        pq->array[0] = pq->array[pq->size - 1];
        --pq->size;
        minHeapify(pq, 0);

        HuffmanNode* right = pq->array[0];
        pq->array[0] = newHuffmanNode('$', left->freq + right->freq);
        pq->array[0]->left = left;
        pq->array[0]->right = right;
        minHeapify(pq, 0);
    }

    return pq->array[0];
}

void printHuffmanCodes(HuffmanNode* root, int arr[], int top) {
    if (root->left) {
        arr[top] = 0;
        printHuffmanCodes(root->left, arr, top + 1);
    }

    if (root->right) {
        arr[top] = 1;
        printHuffmanCodes(root->right, arr, top + 1);
    }

    if (!root->left && !root->right) {
        printf("%c: ", root->data);
        for (int i = 0; i < top; ++i)
            printf("%d", arr[i]);
        printf("\n");
    }
}

void compressString(char* input) {
    int n = strlen(input);
    char data[MAX_TREE_NODES];
    unsigned freq[MAX_TREE_NODES];

    for (int i = 0; i < MAX_TREE_NODES; ++i)
        freq[i] = 0;

    for (int i = 0; i < n; ++i)
        freq[input[i]]++;

    int size = 0;
    for (int i = 0; i < MAX_TREE_NODES; ++i) {
        if (freq[i] != 0) {
            data[size] = i;
            size++;
        }
    }

    HuffmanNode* root = buildHuffmanTree(data, freq, size);

    int arr[MAX_TREE_NODES], top = 0;
    printf("Huffman Codes:\n");
    printHuffmanCodes(root, arr, top);

}

int main() {
    char input[] = "Badal";
    compressString(input);
    return 0;
}
