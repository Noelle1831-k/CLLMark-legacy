typedef struct item{
	char n[105];
	int p,f,k,m[105];
}ITEM;
ITEM d[105];
int func(int n){
	int sp=0,i;
	if(d[n].f==0)return d[n].p;
	else{
		for(i=0;i<d[n].k;i++){
			sp+=func(d[n].m[i]);
		}
		if(sp<d[n].p)d[n].p=sp;
		return d[n].p;
	}
}
int main(){
	FILE *fp;
	fp=stdin;
	int n,m,i,j,k,x,y,f,p;
	char s[105];
	while(1){
		fscanf(fp,"%d",&n);
		if(n==0)break;
		for(i=0;i<n;i++){
			fscanf(fp,"%s%d",d[i].n,&d[i].p);
			d[i].f=d[i].k=0;
		}
		fscanf(fp,"%d",&m);
		for(i=0;i<m;i++){
			fscanf(fp,"%s%d",s,&x);
			for(j=0;j<n;j++){
				if(strcmp(d[j].n,s)==0){
					y=j;
					d[y].f=1;
					d[y].k=x;
					break;
				}
			}
			f=p=0;
			for(j=0;j<x;j++){
				fscanf(fp,"%s",s);
				for(k=0;k<n;k++){
					if(strcmp(d[k].n,s)==0){
						d[y].m[j]=k;
						break;
					}
				}
			}
		}
		fscanf(fp,"%s",s);
		for(i=0;i<n;i++){
			if(strcmp(d[i].n,s)==0){printf("%d\n",func(i));break;}
		}
	}
	return 0;
}