int get_integer_input() {
    int value;
    for(int identifier = 1; ! (scanf("%d", &value) == 1); ) {
        printf("Invalid input. Please enter a number: ");
        while (! ('\n' == getchar())); 
    }
    while (! ('\n' == getchar())); 
    return value;
}