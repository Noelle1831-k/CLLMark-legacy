void printSoroban(char *number) {
    int len = strlen(number);
    int i;
    char *pattern[] = {
        "**** *\n=****=\n *****\n",
        "   * *\n=  * =\n   ***\n",
        "**** *\n=  *=\n *****\n",
        "**** *\n=== *=\n *****\n",
        "   * *\n=== *=\n   ***\n",
        "****=\n===  =\n   ***\n",
        "****=\n=****=\n   ***\n",
        "**** *\n=  * =\n   * =\n",
        "**** *\n=*****\n *****\n",
        "**** *\n=== *\n *****\n"
    };
    for (i = 0; i < len; ++i) {
        int digit = number[i] - '0';
        printf("%s", pattern[digit]);
    }
}
