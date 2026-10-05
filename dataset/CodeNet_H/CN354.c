int main(void)
{
    int X;
    scanf("%d",&X);
    if(X == 1 || X == 8 || X == 15 || X == 22 || X == 29)
    	printf("fri\n");
    else if(X == 2 || X == 9 || X == 16 || X == 23 || X == 30)
    	printf("sat\n");
    else if(X == 3 || X == 10 || X == 17 || X == 24)
    	printf("sun\n");
    else if(X == 4 || X == 11 || X == 18 || X == 25)
    	printf("mon\n");
    else if(X == 5 || X == 12 || X == 19 || X == 26)
    	printf("tue\n");
    else if(X == 6 || X == 13 || X == 20 || X == 27)
    	printf("wed\n");
    else if(X == 7 || X == 14 || X == 21 || X == 28)
    	printf("thu\n");
    return 0;
}
