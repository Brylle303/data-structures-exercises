void addNodes()
{
    char input[256];
    printf("Insert values to add (comma-separated): ");
    fflush(stdin);
    fgets(input, sizeof(input), stdin);

    char *token = strtok(input, ", ");
    while (token)
        {
        int val;
        if (sscanf(token, "%d", &val) == 1)
        {
            insertNode(val);
        } else
        {
            printf("Invalid input detected: %s\n", token);
        }
        token = strtok(NULL, ", ");
    }
}
