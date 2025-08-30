void insert(int value)
{
    HeapNode *insertedMin = NULL, *insertedMax = NULL;
    minRoot = insertLevelOrder(minRoot, value, &insertedMin);
    maxRoot = insertLevelOrder(maxRoot, value, &insertedMax);
    heapifyUpMin(insertedMin);
    heapifyUpMax(insertedMax);
    nodeCount++;
    printHeaps();
}
