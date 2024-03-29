#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define COUNT 10

struct Node {
	int key;
    struct Node* left;
    struct Node* right;
};

struct BinarySearchTree {
	struct Node* root;
};

// Function prototypes
struct Node* getSuccessor(struct Node* node);

void initBST(struct BinarySearchTree* bst) {
    bst->root = NULL;
}

struct Node* getRoot(struct BinarySearchTree* bst) {
    return bst->root;
}

struct Node* search(struct BinarySearchTree* bst, int desiredKey) {
	printf("\nSearching for node %d", desiredKey);
    struct Node* currentNode = bst->root;
	printf("\nStarting at root node %d", currentNode->key);
    while (currentNode != NULL) {
        if (currentNode->key == desiredKey) {
            return currentNode;
        } else if (desiredKey < currentNode->key) {
			printf("\nDid not find node, navigating to node %d's left child", currentNode->key); 
            currentNode = currentNode->left;
        } else {
			printf("\nDid not find node, navigating to node %d's right child", currentNode->key); 
            currentNode = currentNode->right;
        }
    }
    return NULL;
}

void insert(struct BinarySearchTree* bst, struct Node* node) {
	printf("\nInserting node %d", node->key);
    if (bst->root == NULL) {
        bst->root = node;
		printf("\nInserted node %d as the root node.\n", node->key);
    } else {
        struct Node* currentNode = bst->root;
        while (currentNode != NULL) {
            if (node->key < currentNode->key) {
				printf("\nChecking node %d for left child." , currentNode->key);
                if (currentNode->left == NULL) {
					printf("\nInserting node %d as left child of node %d.\n", node->key, currentNode->key);
                    currentNode->left = node;
                    currentNode = NULL;
                } else {
                    currentNode = currentNode->left;
					printf("\nTraversed to left child node %d.", currentNode->key);
                }
            } else {
				printf("\nChecking node %d for right child." , currentNode->key);
                if (currentNode->right == NULL) {
					printf("\nInserting node %d as right child of node %d.\n", node->key, currentNode->key);
                    currentNode->right = node;
                    currentNode = NULL;
                } else {
                    currentNode = currentNode->right;
					printf("\nTraversed to right child node %d.", currentNode->key);
                }
            }
        }
    }
}

bool removeNode(struct BinarySearchTree* bst, int key) {
    struct Node* parent = NULL;
    struct Node* current = bst->root;
    bool isLeftChild = false;

    // Searching for the node with the given key
    while (current != NULL && current->key != key) {
        parent = current;
        if (key < current->key) {
            current = current->left;
            isLeftChild = true;
        } else {
            current = current->right;
            isLeftChild = false;
        }
    }

    if (current == NULL) {
        return false;  // Node not found
    }

    // Case 1: Node to be deleted has no children
    if (current->left == NULL && current->right == NULL) {
        if (current == bst->root) {
            bst->root = NULL;
        } else {
            if (isLeftChild) {
                parent->left = NULL;
            } else {
                parent->right = NULL;
            }
        }
        printf("\nLeaf node %d was removed.\n", current->key);
    }
    // Case 2: Node to be deleted has two children
    else if (current->left != NULL && current->right != NULL) {
        struct Node* successor = getSuccessor(current);
        if (current == bst->root) {
            bst->root = successor;
        } else {
            if (isLeftChild) {
                parent->left = successor;
            } else {
                parent->right = successor;
            }
        }
        successor->left = current->left;
    }
    // Case 3: Node to be deleted has only one child
    else {
        struct Node* child = (current->left != NULL) ? current->left : current->right;
        if (current == bst->root) {
            bst->root = child;
        } else {
            if (isLeftChild) {
                parent->left = child;
            } else {
                parent->right = child;
            }
        }
    }

    free(current);
    return true;
}

struct Node* getSuccessor(struct Node* node) {
    struct Node* current = node->right;
    struct Node* parent = node;
    struct Node* successor = node;

    while (current != NULL) {
        parent = successor;
        successor = current;
        current = current->left;
    }

    if (successor != node->right) {
        parent->left = successor->right;
        successor->right = node->right;
    }

    return successor;
}

// Function to print binary tree in 2D
// It does reverse inorder traversal
void print2DUtil(struct Node* root, int space)
{
    // Base case
    if (root == NULL) {
        return;
	}
	
    // Increase distance between levels
    space += COUNT;
 
    // Process right child first
    print2DUtil(root->right, space);
 
    // Print current node after space
    // count
    printf("\n");
    for (int i = COUNT; i < space; i++) {
		printf(" ");
	}
    printf("%d\n", root->key);
 
    // Process left child
    print2DUtil(root->left, space);
}
 
// Wrapper over print2DUtil()
void print2D(struct Node* root)
{
    // Pass initial space count as 0
    print2DUtil(root, 0);
}

int main() {
    struct BinarySearchTree bst;
    initBST(&bst);

    // Insert the nodes 20,35,13,6,24,18,48,1,27 in the order listed
    int keys[] = {20,35,13,6,24,18,48,1,27};
    for (int i = 0; i < sizeof(keys)/sizeof(keys[0]); i++) {
        struct Node* node = (struct Node*)malloc(sizeof(struct Node));
        node->key = keys[i];
        node->left = NULL;
        node->right = NULL;
        insert(&bst, node);
    }

    // Call the print2D method/function
    printf("\nInitial Binary Search Tree:\n");
    print2D(getRoot(&bst));

    // Remove nodes 18 and 48
    removeNode(&bst, 18);
    removeNode(&bst, 48);

    // Call the print2D method/function
    printf("\nBinary Search Tree after removing nodes 18 and 48:\n");
    print2D(getRoot(&bst));

    // Insert nodes 16 and 45
    struct Node* node16 = (struct Node*)malloc(sizeof(struct Node));
    node16->key = 16;
    node16->left = NULL;
    node16->right = NULL;
    insert(&bst, node16);

    struct Node* node45 = (struct Node*)malloc(sizeof(struct Node));
    node45->key = 45;
    node45->left = NULL;
    node45->right = NULL;
    insert(&bst, node45);

    // Call the print2D method/function
    printf("\nBinary Search Tree after inserting nodes 16 and 45:\n");
    print2D(getRoot(&bst));

    // Remove nodes 6 and 24
    removeNode(&bst, 6);
    removeNode(&bst, 24);

    // Call the print2D method/function
    printf("\nBinary Search Tree after removing nodes 6 and 24:\n");
    print2D(getRoot(&bst));

    // Remove node 20 and attempt to remove node 38 (not in tree)
    removeNode(&bst, 20);
    removeNode(&bst, 38);

    // Call the print2D method/function
    printf("\nBinary Search Tree after removing nodes 20 and 38:\n");
    print2D(getRoot(&bst));

    return 0;
}
