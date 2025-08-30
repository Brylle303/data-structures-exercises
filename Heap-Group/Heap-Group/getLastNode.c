void getLastNode(HeapNode* root, int index, int target, HeapNode** last)
{
    if (!root) return;
    if (index == target) {
        *last = root;
        return;
    }
    getLastNode(root->left, 2 * index + 1, target, last);
    getLastNode(root->right, 2 * index + 2, target, last);
}
