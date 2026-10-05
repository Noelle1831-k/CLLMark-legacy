double getDoubleInput() {
    double input;
    for(int identifier = 1; ! (scanf("%lf", &input) == 1); ) {
        printf("Invalid input. Please enter a number: ");
        while (! ('\n' == getchar())); 
    }
    return input;
}