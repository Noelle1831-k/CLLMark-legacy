int main(void)
{
        int i = 0, j = 0,k = 0;
        int max = 0;
        char text[ 1002 ];
        char word[ 1002 ][ 34 ];
        int count = 0;
        int flag[1002];
        int maxword = 0;
        int maxtango = 0;
        int tangocount[1002];
        char tango[1002][34];
        char longword[1][34];
        int t = 0;
        for(i = 0; i < 1001; i++)
        {
                flag[i] = 0;
                tangocount[i] = 0;
                text[i] = '\0';
        }
        for(i = 0; i < 1001; i++)
        {
                strcpy(word[i],"a");
                strcpy(tango[i],"a");
        }
        i = 0;
        gets(text);
        while(1)
        {
                while(1)
                {
                        if(text[i] == 0x20|| text[i]== 0x00 )
                        {
                                if(maxword < k)
                                {
                                        strcpy(longword[0],word[j]);
                                        maxword = k;
                                }
                                i++;
                                k = 0;
                                break;
                        }
                        word[j][k] = text[i];
                        k++;
                        i++;
                }
                if(text[i] == '\0')
                {
                        break;
                }
                j++;
        }
        count = j;
        for(i = 0; i < count; i++)
        {
                for(j = i+1; j < count; j++)
                {
                        if(strcmp(word[i],word[j]) == 0 && flag[j] == 0 && flag[i] == 0)
                        {
                                strcpy(tango[t],word[i]);
                                tangocount[t]++;
                                flag[j] = 1;
                        }
                }
                t++;
        }
        for(i = 0; i < t; i++)
        {
                if(maxtango < tangocount[i])
                {
                        maxtango = i;
                }
        }
        printf("%s %s\n",tango[maxtango], longword[0]);
        return 0;
}