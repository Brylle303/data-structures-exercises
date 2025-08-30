void deleteRoot()
{
    if (!minRoot || !maxRoot) {
        printHeaps();
        printf("\n\nBoth heaps are empty! Nothing to delete.");
        return;
    }

    HeapNode* lastMin = NULL;
    HeapNode* lastMax = NULL;
    getLastNode(minRoot, 0, nodeCount - 1, &lastMin);
    getLastNode(maxRoot, 0, nodeCount - 1, &lastMax);

    if (lastMin && minRoot) {
        minRoot->value = lastMin->value;
        if (lastMin->parent) {
            if (lastMin->parent->left == lastMin) lastMin->parent->left = NULL;
            else lastMin->parent->right = NULL;
        } else {
            minRoot = NULL;
        }
        free(lastMin);
    }

    if (lastMax && maxRoot) {
        maxRoot->value = lastMax->value;
        if (lastMax->parent) {
            if (lastMax->parent->left == lastMax) lastMax->parent->left = NULL;
            else lastMax->parent->right = NULL;
        } else {
            maxRoot = NULL;
        }
        free(lastMax);
    }

    nodeCount--;
    heapifyDownMin(minRoot);
    heapifyDownMax(maxRoot);
    printHeaps();
}
