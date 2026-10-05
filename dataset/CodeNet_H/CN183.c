char hantei(char * ban)
{
  int lines[][3]={{0,1,2},{3,4,5},{6,7,8},{0,3,6},{1,4,7},{2,5,8},{0,4,8},{2,4,6}};
  char color[2]="bw";
  int i,j,k;
  int result;
  for(i=0;i<2;i++)
    for(j=0;j<8;j++)
      {  result = 1;
        for(k=0;k<3;k++)
          {  
            result &= (color[i]==ban[lines[j][k]])?1:0;
          }
        if(result)
          return(color[i]);
      }
  return('+');
}
main()
{
  char banmen[3][3] = {"+++","+++","+++"};
  char ret;
  while(EOF != scanf("%s",&banmen[0]) && banmen[0][0] != '0')
    { scanf("%3s",&banmen[1]);
      scanf("%3s",&banmen[2]);
      ret = hantei((char *)banmen);
      if(ret == '+')
        printf("NA\n");
      else
        printf("%c\n",ret);
    }
return(0);
}