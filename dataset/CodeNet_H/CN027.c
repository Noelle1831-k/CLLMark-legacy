int main(void){
    int a,b,d,n;
    while(scanf("%d%d",&a,&b), a != 0){
    	d = 0;
        switch (a){
            case 2:
                    d = d + 31;
                    break;
            case 3:
                    d = d + 60;
                    break;
            case 4:
                    d = d + 91;
                    break;
            case 5:
                    d = d + 121;
                    break;
            case 6:
                    d = d + 152;
                    break;
            case 7:
                    d = d + 182;
                    break;
            case 8:
                    d = d + 213;
                    break;
            case 9:
                    d = d + 244;
                    break;
            case 10:
                    d = d + 274;
                    break;
            case 11:
                    d = d + 305;
                    break;
            case 12:
                    d = d + 335;
                    break;
            default:
                    d = d + 0;
                    break;
        }
        d = d + b;
        n = d % 7;
        switch (n){
            case 1:
                    printf("Thursday\n");
                    break;
            case 2:
                    printf("Friday\n");
                    break;
            case 3:
                    printf("Saturday\n");
                    break;
            case 4:
                    printf("Sunday\n");
                    break;
            case 5:
                    printf("Monday\n");
                    break;
            case 6:
                    printf("Tuesday\n");
                    break;
            default:
                    printf("Wednesday\n");
                    break;
        }
    }
    return 0;
}