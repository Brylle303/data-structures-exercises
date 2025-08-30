int powerSolver(int numBase, int numPower)
{
    if(numPower == 0)
    {
        return 1;
    }
    else
    {
        return numBase * (powerSolver(numBase, numPower - 1));
    }
}
