#include <stdio.h>
#include <stdlib.h>

#include "tree.h"
#include "create_node.c"
#include "add_node.c"
#include "delete_node.c"
#include "search_node.c"
#include "breadth.c"
#include "display_tree.c"
#include "print_tree.c"
#include "print_spaces.c"
#include "tree_height.c"
#include "traverse_postorder.c"
#include "traverse_preorder.c"
#include "traverse_inorder.c"
#include "edit_node.c"


int main() {
    Node* vertex = NULL;
    int choice, value, old_value, new_value, success;

    while (1) {
        printf("\n=== MAIN MENU ===\n");
        printf("[1] Add new node\n");
        printf("[2] Delete a node\n");
        printf("[3] Search a node\n");
        printf("[4] Edit a node\n");
        printf("[5] Traverse all nodes\n");
        printf("[6] Exit\n");
        printf("Choice? ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Insert value to add: ");
                scanf("%d", &value);
                vertex = add_node(vertex, value);
                printf("SUCCESS: node added.\n");
                display_tree(vertex);
                break;

            case 2:
                printf("Input value to delete: ");
                scanf("%d", &value);
                vertex = delete_node(vertex, value, &success);
                if (success) {
                    printf("SUCCESS: node removed.\n");
                } else {
                    printf("FAILED: removing node!!!\n");
                }
                display_tree(vertex);
                break;

            case 3:
                printf("Input value to search: ");
                scanf("%d", &value);
                if (search_node(vertex, value)) {
                    printf("SUCCESS: node found.\n");
                } else {
                    printf("FAILED: node not found!!!\n");
                }
                break;

            case 4:
                printf("Input value to edit: ");
                scanf("%d", &old_value);
                printf("Input new value: ");
                scanf("%d", &new_value);
                vertex = edit_node(vertex, old_value, new_value, &success);
                if (success) {
                    printf("SUCCESS: node edited.\n");
                } else {
                    printf("FAILED: node not found!!!\n");
                }
                display_tree(vertex);
                break;

            case 5:
                printf("Breadth-first: ");
                traverse_breadth_first(vertex);
                printf("\n");

                printf("Depth-first InOrder Traversal: ");
                traverse_inorder(vertex);
                printf("\n");

                printf("Depth-first PreOrder Traversal: ");
                traverse_preorder(vertex);
                printf("\n");

                printf("Depth-first PostOrder Traversal: ");
                traverse_postorder(vertex);
                printf("\n");
                break;

            case 6:
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
