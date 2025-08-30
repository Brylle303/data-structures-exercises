#ifndef TREE_H_INCLUDED
#define TREE_H_INCLUDED

// Structure for a tree node
typedef struct Node {
    int value;
    struct Node* left;
    struct Node* right;
} Node;

Node* most_recent_node = NULL;

//Function Prototypes

Node* create_node(int value);
Node* add_node(Node* vertex, int value);
Node* delete_node(Node* vertex, int value, int* success);
Node* edit_node(Node* vertex, int old_value, int new_value, int* success);
int search_node(Node* vertex, int value);
void traverse_breadth_first(Node* vertex);
void display_tree(Node* vertex);
void print_tree(Node* vertex, int level, int space);
void print_spaces(int count) ;
int tree_height(Node* vertex);
void traverse_postorder(Node* vertex) ;
void traverse_preorder(Node* vertex);
void traverse_inorder(Node* vertex);

#endif // TREE_H_INCLUDED
