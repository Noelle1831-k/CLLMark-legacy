X;
Y;
Z;
V[4];
E[51];
A[51];
double P0[51][4901];
double P1[51][4901];
main(){
	int i,p,m,u,p1,m1;
	double sum;
	for(;scanf("%d%d%d",&X,&Y,&Z),X;){
		memset(E,0,sizeof(E));
		memset(P0,0,sizeof(P0));
		memset(P1,0,sizeof(P1));
		for(i=0;i<X;i++)
			scanf("%d",V+i);
		for(i=0;i<Z;i++){
			int n,e,a;
			scanf("%d%d%d",&n,&e,&a);
			E[n]=e;
			A[n]=a;
		}
		P0[0][0]=1;
		for(u=1;u;){
			u=0;
			for(p=0;p<=Y;p++){
				for(m=0;m<=p*100;m++){
					if(P0[p][m]){
						u=1;
						for(i=0;i<X;i++){
							p1=p+V[i];
							m1=m;
							if(p1>=Y){
								p1=Y;
							}else{
								switch(E[p1]){
								case 1:
									p1+=A[p1];
									if(p1>=Y)
										p1=Y;
									break;
								case 2:
									m1+=A[p1];
									break;
								case 3:
									m1-=A[p1];
									if(m1<0)
										m1=0;
									break;
								}
							}
							P1[p1][m1]+=P0[p][m]/X;
						}
					}
				}
			}
			memcpy(P0,P1,sizeof(*P0)*Y);
			memset(P1,0,sizeof(*P1)*Y);
		}
		sum=0;
		for(m=0;m<=4900;m++){
			sum+=P1[Y][m]*m;
		}
		printf("%d\n",(int)sum);
	}
	exit(0);
}