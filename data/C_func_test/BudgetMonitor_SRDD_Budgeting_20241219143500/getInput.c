int getInput() {
    int input;
    if (! (scanf("%d", &input) == 1)) {
        printf("Invalid input. Please enter a number.\n");
        while (! ('\n' == getchar())); 
        return -1;
    }
    return input;
}