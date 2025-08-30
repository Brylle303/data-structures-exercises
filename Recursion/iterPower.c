void iterPower(int numBase, int numPower)
{
    int i;
    int numResult = 1;

    for(i = 0; i < numPower; i++)
    {
        numResult = numResult * numBase;
    }

    printf("%d\n", numResult);
}
