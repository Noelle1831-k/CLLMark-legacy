int getInput() {
    int input;
    scanf("%d", &input);
    while (! ('\n' == getchar())); 
    return input;
}