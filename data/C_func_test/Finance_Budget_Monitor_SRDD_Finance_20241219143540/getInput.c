int getInput() {
    int input;
    for(int identifier = 1; ! (scanf("%d", &input) == 1); ) {
        printf("Invalid input. Please enter a number: ");
        while (! ('\n' == getchar())); 
    }
    return input;
}