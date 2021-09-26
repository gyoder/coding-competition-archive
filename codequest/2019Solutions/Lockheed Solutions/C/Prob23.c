#include <stdio.h>
#include <math.h>
#include <string.h>
#include <unistd.h>


struct node {
    char type;
    int height;
    int width;
    int depth;
    struct node *parent;
    struct node *up;
    struct node *left;
    struct node *down;
    struct node *right;
};

int width;
int height;        

void find_exits(struct node tree[height][width], struct node *current) {
    if (current->type == 'X') {
        return;
    }
    if (current->type == ' ' || current->type == 'o') {
        if (current->height > 0 && tree[current->height-1][current->width].depth > current->depth+1) {
            current->up = &(tree[current->height-1][current->width]);
            current->up->parent = current;
            current->up->depth = current->depth + 1;
            find_exits(tree, current->up);
        } else {current->up = NULL;}
        if (current->width > 0 && tree[current->height][current->width-1].depth > current->depth+1) {
            current->left = &(tree[current->height][current->width-1]);
            current->left->parent = current;
            current->left->depth = current->depth + 1;
            find_exits(tree, current->left);
        } else {current->left =  NULL;}
        if (current->height < height && tree[current->height+1][current->width].depth > current->depth+1) {
            current->down = &(tree[current->height+1][current->width]);
            current->down->parent = current;
            current->down->depth = current->depth + 1;
            find_exits(tree, current->down);
        } else {current->down = NULL;}
        if (current->width < width && tree[current->height][current->width+1].depth > current->depth+1) {
            current->right = &(tree[current->height][current->width+1]);
            current->right->parent = current;
            current->right->depth = current->depth + 1;
            find_exits(tree, current->right);
        } else {current->right = NULL;}
    }
}

int main() {

    char input[1024];
    fgets(input, 1024, stdin);
    int num_test_cases;
    sscanf(input, "%d", &num_test_cases);

    int i;
    for (i = 0; i < num_test_cases; i++) {

        fgets(input, 1024, stdin);
        sscanf(input, "%d %d", &width, &height);

        struct node tree[height][width];
        char map[height][width+2];
        int j;
        for (j = 0; j < height; j++) {
            fgets(map[j], 1024, stdin);
            int k;
            for (k = 0; k < width; k++) {
                if (map[j][k] == '\n') {
                    map[j][k] = '\0';
                }
            }
            for (k = 0; k < width; k++) {
                tree[j][k].type = map[j][k];
                tree[j][k].height = j;
                tree[j][k].width = k;
                tree[j][k].depth = height*width;
            }
        } 

        struct node *root;
        for (j = 0; j < height; j++) {
            int k;
            for (k = 0; k < width; k++) {
                if (tree[j][k].type == 'o') {
                    root = &tree[j][k];
                }
            }
        }

        root->depth = 0;
        find_exits(tree, root);

        int least_distance = height*width;
        int least_depth = height*width;
        struct node *nearest_node;
        for (j = 0; j < height; j++) {
            int k;
            for (k = 0; k < width; k++) {
                if (tree[j][k].type == 'X') {
                   if (tree[j][k].depth < least_depth) {
                       nearest_node = &tree[j][k];
                       least_depth = tree[j][k].depth;
                       least_distance = tree[j][k].height + tree[j][k].width;
                    } else if (tree[j][k].depth == least_depth && tree[j][k].height + tree[j][k].width < least_distance) {
                        nearest_node = &tree[j][k];
                        least_distance = tree[j][k].height + tree[j][k].width;
                    }
                }
            }
        }

        struct node *current_node;
        current_node = nearest_node->parent;
        for (j = 0; j < least_depth-1; j++) {
            current_node->type = '.';
            current_node = current_node->parent;
        }

        for (j = 0; j < height; j++) {
            int k;
            for (k = 0; k < width; k++) {
                if (tree[j][k].type == '\0') {
                    break;
                }
                printf("%c", tree[j][k].type);
            }
            printf("\n");
        }
    }
}
