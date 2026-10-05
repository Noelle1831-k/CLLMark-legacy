typedef struct WORDBOOK {
    char word[5000][21];
    int count[5000];
    int wordcount;
} WORDBOOK;
WORDBOOK wordbook[26];
void init_words(WORDBOOK *words);
void sort_dictionary(WORDBOOK *words, int j);
void display_word(WORDBOOK *words, int num);
int main(void)
{
    char sentence[1050];
    char tmp[21];
    char *p;
    char initial[2];
    char temp;
    int line_num;
    int i, j, k, m;
    int num;
    int flag;
    for (i = 0; i < 26; i++) {     
        wordbook[i].wordcount = 0;
    }
    while (1) {
        scanf("%d", &line_num);     
        if (line_num == 0) {
            break;
        }
        scanf("%c", &temp);      
        init_words(wordbook);
        for (i = 0; i < 26; i++) {     
            wordbook[i].wordcount = 0;
        }
        for (i = 0; i < line_num; i++) {
            fgets(sentence, sizeof(sentence), stdin);   
            p = sentence;
            while (*p != '\n') {
                if (*p == ' ') {
                    p++;
                }
                num = *p;
                num -= 97;
                k = 0;
                while ('a' <= *p && *p <= 'z') {
                    tmp[k] = *p;
                    k++;
                    p++;
                }
                tmp[k] = '\0';
                flag = 0;
                for (m = 0; m < wordbook[num].wordcount; m++) {
                    if (strcmp(wordbook[num].word[m], tmp) == 0) {
                        wordbook[num].count[m]++;
                        flag = 1;
                        break;
                    }
                }
                if (flag == 0) {
                    strcpy(wordbook[num].word[wordbook[num].wordcount], tmp);
                    wordbook[num].count[wordbook[num].wordcount] = 1;
                    wordbook[num].wordcount++;
                }
            }
        }
        for (j = 0; j < 26; j++) {
            if (wordbook[j].wordcount > 1) {
                sort_dictionary(wordbook, j);
            }
        }
        scanf("%s", initial);
        num = initial[0];
        num -= 97;
        if (wordbook[num].wordcount == 0) {
            printf("NA\n");
        } else {
            display_word(wordbook, num);
        }
    }
    return (0);
}
void init_words(WORDBOOK *words)
{
    int i, j;
    for (i = 0; i < 26; i++) {
        for (j = 0; j < 5000; j++) {
            words[i].word[j][0] = '\0';
            wordbook[i].count[j] = 0;
        }
    }
}
void sort_dictionary(WORDBOOK *words, int j)
{
    int k, l;
    int flag;
    int temp;
    char tmp[1050];
    for (k = 0; k <= words[j].wordcount - 2; k++) {
    flag = 0;
        for (l = k + 1; l <= words[j].wordcount - 1; l++) {
            if (wordbook[j].count[k] < wordbook[j].count[l]) {
                flag = 1;
                temp = wordbook[j].count[k];
                wordbook[j].count[k] = wordbook[j].count[l];
                wordbook[j].count[l] = temp;
                strcpy(tmp, words[j].word[k]);
                strcpy(words[j].word[k], words[j].word[l]);
                strcpy(words[j].word[l], tmp);
            }
            if (wordbook[j].count[k] == wordbook[j].count[l]) {
                if (strcmp(wordbook[j].word[k], wordbook[j].word[l]) > 0) {
                    flag = 1;
                    strcpy(tmp, words[j].word[k]);
                    strcpy(words[j].word[k], words[j].word[l]);
                    strcpy(words[j].word[l], tmp);
                }
            }
        }
        if (flag == 0) {
        }
    }
}
void display_word(WORDBOOK *words, int num)
{
    int i;
    int count;
    count = 0;
    for (i = 0; i < words[num].wordcount; i++) {
        if (i != 0) {
            printf(" ");
        }
        printf("%s", words[num].word[i]);
        count++;
        if (count == 5) {
            break;
        }
    }
#if 0
    count = 0;
    for (i = 0; i <= words[num].wordcount; i++) {
        if (words[num].word[i][0] != '0') {
            printf("%s", words[num].word[i]);
            if (i == words[num].wordcount - 1) {
                break;
            }
            printf(" ");
            count++;
        }
        if (count == 5) {
            break;
        }
    }
#endif
    printf("\n");
}
