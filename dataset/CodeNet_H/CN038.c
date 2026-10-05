    int main(){
        int a[5],s[14],p[14],i,j,c,g,h,d;
        while(scanf("%d,%d,%d,%d,%d",&a[0],&a[1],&a[2],&a[3],&a[4])!=EOF){
            g=0;
            h=0;
            d=0;
            c=0;
            for(i=0;i<14;i++){
                s[i]=i+1;
                p[i]=0;
            }
            s[13]=1;
            for(i=0;i<13;i++)
                for(j=0;j<5;j++)
                if(a[j]==s[i]){
                p[i]++;
                if(a[j]==1)
                    p[13]++;
            }
            for(i=0;i<10;i++)
                if(p[i]==1){
                    for(j=i+1;j<i+5;j++){
                        if(p[j]!=1)
                            break;
                        if(j==i+4){
                            printf("straight\n");
                            c++;
                        }
                    }
            }
            if(c>0)
                continue;
            for(i=0;i<13;i++){
                if(p[i]==4)d++;
                if(p[i]==3)g++;
                if(p[i]==2)h++;
            }
            if(d>0)
                printf("four card\n");
            else if(g>0&&h>0)
                printf("full house\n");
            else if(g>0&&h==0)
                printf("three card\n");
            else if(g==0&&h==1)
                printf("one pair\n");
            else if(g==0&&h==2)
                printf("two pair\n");
            else printf("null\n");
        }
        return 0;
}