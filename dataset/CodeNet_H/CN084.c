int getNextWord(int added, char* src, char* word)
{
	int i;
	for( i = 0; src[i] != ' ' && src[i] != '.' && src[i] != ',' && src[i] != '\0'; i++ )
	{
		word[i] = src[i];
	}
	word[i] = '\0';
	for(; src[i] == ' ' || src[i] == '.' || src[i] == ',' || src[i] == '\0'; i++ )
	{
	}
	return (i + added);
}
int main(void)
{
	char string[2048] = {0};
	char word[2048] = {0};
	int i;
	int len;
	int isFirst = 1;
	fgets( string, 2048, stdin );
	string[ strlen( string ) ] = '\0';
	for( i = 0; i < 2048; )
	{
		i = getNextWord( i, string + i, word );
		len = strlen( word );
		if( len >= 3 && len <= 6 )
		{
			printf("%s%s", isFirst == 1 ? "" : " ", word);
			isFirst = 0;
		}
	}
	puts("");
	return (0);
}