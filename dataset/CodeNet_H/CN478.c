int
main()
{
        char search[21] = {0};
        char *itr, *itr2, *itr3;
        char buf;
        char test[20];
        int i, cnt = 0;
        itr = search + 10;
        while (scanf("%c", &buf), buf != '\n')
                *itr++ = buf;
        *itr = '@';
        scanf("%d\n", &i);
        while (i > 0) {
                itr = test;
                itr2 = test + 10;
                while (scanf("%c", &buf), buf != '\n') {
                        *itr++ = buf;
                        *itr2++ = buf;
                }
                itr = search + 10;
                while (itr != search) {
                        buf = 0;
                        itr2 = itr;
                        itr3 = test;
                        while (*itr2 != '@') {
                                buf += (*itr3 - *itr2) * *itr2;
                                itr2++;
                                itr3++;
                        }
                        if (buf == 0) {
                                cnt++;
                                break;
                        }
                        itr--;
                }
                i--;
        }
        printf("%d\n", cnt);
        return 0;
}