int main()
{
	char hoshino[8] = "Hoshino";
	char buff[1001];
	char *index;
	int stringCount;
	int i;
	int j;
	int chain;
	scanf("%d",&stringCount);
	scanf("*%s",buff);
	for (i = 0; stringCount > i; ++i) {
		fgets(buff,sizeof(buff),stdin);
		while ('\n' == *buff) {
			fgets(buff,sizeof(buff),stdin);
		}
		chain = 0;
		for (index = buff; '\0' != *index; ++index) {
			if (hoshino[chain] != *index) {
				chain = 0;
			}
			if (hoshino[chain] == *index) {
				++chain;
			}
			if (7 == chain) {
				*index = 'a';
				chain = 0;
			}
		}
		printf("%s",buff);
	}
	return 0;
}