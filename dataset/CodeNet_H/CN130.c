int main(void)
{
	int i,j,k;
	int n;
	char junkai[1024],syaryou[30];
	char tmpWord[30],addWord;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%s",junkai);
		syaryou[0]=junkai[0];
		for(j=1;j<1024;j=j+3)
		{
			if(junkai[j]=='-')
				strncat(syaryou,&junkai[j+2],1);
			else if(junkai[j]=='<')
			{
				strncpy(tmpWord,&junkai[j+2],1);	
				tmpWord[1]='\0';					
				strcat(tmpWord,syaryou);			
				strcpy(syaryou,tmpWord);			
			}
			else if(junkai[j]=='\0')
				break;
		}
	printf("%s\n",syaryou);
	}
	return 0;
}