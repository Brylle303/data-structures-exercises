void iterFibo(int seqNum)
{
    int i;
    int sequence;
    int num1 = 0, num2 = 1;

    for(i = 0; i < seqNum; i++)
    {
        printf("%d ", num1);
        sequence = num1 + num2;
        num1 = num2;
        num2 = sequence;
    }

    printf("\n");
}
