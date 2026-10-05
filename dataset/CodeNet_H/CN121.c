int tesuu[40320]; 
char buf[80];
char buf2[9];
int  fact[8]={1,1,2,6,24,120,720,5040};
int used[8];
int limit;
numcnt(int c,int *used)
{
        int i,j,k;
        i=c;j=0;k=0;
        while(1)
        {
                if(0==used[j])
                {    
                        if(i==0)
                                break;
                        k++;
                }
                i--;
                j++;
        }
        used[c]=1;
        return(k);
}
numcnt2(int c,int *used)
{
        int i,j,k;
        i=c;j=0;
        while(1)
        {
                if(0==used[j])
                {    
                        if(i==0)
                                break;
                        if(i>0)
                                i--;
                }
                j++;
        }
        used[j]=1;
        return(j);
}
int jun2num(char * s)
{
        int i,sum;
        for(i=0;i<8;i++)
                used[i]=0;
        sum=0;
        for(i=0;i<8;i++)
                sum += numcnt(s[i]-'0',used)*fact[7-i];
        return(sum);
}
void num2jun(int num,char * s)
{
        int i,c;
        for(i=0;i<8;i++)
                used[i]=0;
        for(i=0;i<8;i++)
        {
                c = num / fact[7-i];
                s[i]=numcnt2(c,used) + '0';
                num = num % fact[7-i];
        }
        s[8]=0;
}
void strexch(char * s,int p1,int p2)
{
        char w;
        w=s[p1];
        s[p1]=s[p2];
        s[p2]=w;
}
int regist(char * s,int tes,int flag)
{
        int num,zeropos,i;
        char s2[9];
        int  find;
        find=0;
        num=jun2num(s);
        if(tesuu[num] == -1 || tesuu[num] >= tes)
        {       
#ifdef DEBUG
                for(i=0;i<8;i++)
                        printf("%c ",s[i]);
                printf("\n");
#endif
                find=1;
                if(flag)
                        tesuu[num]=tes;
                if(flag)return(0);
                if(tes>40320)
                        return(0);
                zeropos=strchr(s,'0')-s;
                if(zeropos % 4 < 3)
                {
                        memcpy(s2,s,8);
                        strexch(s2,zeropos,zeropos+1);
                        regist(s2,tes+1,1);
                }
                if(zeropos % 4 > 0)
                {
                        memcpy(s2,s,8);
                        strexch(s2,zeropos,zeropos-1);
                        regist(s2,tes+1,1);
                }
                if(zeropos > 3)  
                {
                        memcpy(s2,s,8);
                        strexch(s2,zeropos,zeropos-4);
                        regist(s2,tes+1,1);
                }
                if(zeropos < 4)  
                {
                        memcpy(s2,s,8);
                        strexch(s2,zeropos,zeropos+4);
                        regist(s2,tes+1,1);
                }
        }              
        return(find);
}
void init()
{
        int i,j,find;
        char s[9];
        for(i=0;i<40320;i++)
                tesuu[i] =-1;
        tesuu[0]=0;
        for(i=1;i<=40320 && find;i++)
        {
                find=0;
                for(j=0;j<40320;j++)
                        if(tesuu[j]==i-1)
                        {
                                num2jun(j,s);
                                find |= regist(s,i-1,0);
                        }
        }
}
shrink(char *s1,char *s2)
{       
        int i,j;
        i=j=0;
        while(s1[i])
        {
                if(isdigit(s1[i]))
                {
                        s2[j]=s1[i];
                        i++;j++;
                }
                else
                        i++;
        }
        s2[8]='\0';
}
int solve(char * s)
{
        return(tesuu[jun2num(s)]);
}
main()
{
        int ret;
        init();
        while(NULL!=fgets(buf,80,stdin))
        {
                shrink(buf,buf2);
                ret=solve(buf2);
                if(ret==-1)
                        ret=0;
                printf("%d\n",ret);
        }
return(0);
}