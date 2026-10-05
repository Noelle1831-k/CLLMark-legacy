int main()
{
	static char prime[1000002];
	int i,j,k,n;
	for(i=1;i<=1000000;i+=2){
		prime[i]=1;
	}
	prime[1]=0;
	prime[2]=1;
	for(i=1;i<=100000;i+=2){
		if(prime[i]==1){
			for(j=3;i*j<=100000;j+=2){
				prime[i*j]=0;
			}
		}
	}
	while(1){k=0;
		scanf("%d",&n);
		if(n==0){
			break;
		}
		for(i=2;i<=n/2;i++){
			if(prime[i]&&prime[n-i]){
				k++;
			}
		}
				printf("%d\n",k);
	}
				return 0;
	}