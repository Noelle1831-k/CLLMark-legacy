int size[12][3],pie[12][500][2],sel[12][2000][4],nsel[12],order[12],list[12],q[500],mk[40][40];
int H,W,N,PL,SPACE,SET;
char map[25][25],piece[25][25];
void swap (int* x,int* y){
	int z;
	z=*x;
	*x=*y;
	*y=z;
}
void cover(int n,int x,int y,int dir,int val){
	int i,px,py,ok=1;
	int hei=size[n][0],wid=size[n][1],num=size[n][2];
	for(i=0;i<num;i++){
		px=pie[n][i][0]; py=pie[n][i][1];
		if(dir==0)mk[x+px][y+py]=val;
		if(dir==1)mk[x+py][y+hei-px-1]=val;
		if(dir==2)mk[x+hei-px-1][y+wid-py-1]=val;
		if(dir==3)mk[x+wid-py-1][y+px]=val;
	}
}
void paint(int n,int x,int y,int dir,char cc){
	int i,px,py,ok=1;
	int hei=size[n][0],wid=size[n][1],num=size[n][2];
	for(i=0;i<num;i++){
		px=pie[n][i][0]; py=pie[n][i][1];
		if(dir==0)map[x+px][y+py]=cc;
		if(dir==1)map[x+py][y+hei-px-1]=cc;
		if(dir==2)map[x+hei-px-1][y+wid-py-1]=cc;
		if(dir==3)map[x+wid-py-1][y+px]=cc;
	}
}
int isfit(int n,int x,int y,int dir){
	int i,px,py,ok=1;
	int hei=size[n][0],wid=size[n][1],num=size[n][2];
	for(i=0;i<num;i++){
		px=pie[n][i][0]; py=pie[n][i][1];
		if(dir==0 && map[x+px][y+py]=='#'){ok=0;break;}
		if(dir==1 && map[x+py][y+hei-px-1]=='#'){ok=0;break;}
		if(dir==2 && map[x+hei-px-1][y+wid-py-1]=='#'){ok=0;break;}
		if(dir==3 && map[x+wid-py-1][y+px]=='#'){ok=0;break;}
	}
	return ok;
}
void check(int n,int x,int y,int dir,int* ss){
	if(isfit(n,x,y,dir)){
		sel[n][*ss][0]=x;
		sel[n][*ss][1]=y;
		sel[n][*ss][2]=dir;
		(*ss)++;
	}
}
int search(int look,int num){
	int i,j,k,qua,ok,n=q[look],x,y,dir;
	for(i=nsel[n]-1;i>=0;i--){
		x=sel[n][i][0];
		y=sel[n][i][1];
		dir=sel[n][i][2];
		ok=0;
		if(sel[n][i][3]>=look && isfit(n,x,y,dir)){
			if(look == num-1)return 1;
			paint(n,x,y,dir,'#');
			for(j=look+1;j<num;j++){
				qua=0;
				for(k=nsel[q[j]]-1;k>=0;k--){
					if(sel[q[j]][k][3]>=look){
						if(isfit(q[j],sel[q[j]][k][0],sel[q[j]][k][1],sel[q[j]][k][2])){
							sel[q[j]][k][3]=look+1;
							cover(q[j],sel[q[j]][k][0],sel[q[j]][k][1],sel[q[j]][k][2],look+1);
							qua=1;
						}
						else sel[q[j]][k][3]=look;
					}
				}
				if(qua==0)goto skip;
			}
			for(j=0;j<H;j++){
				for(k=0;k<W;k++){
					if(mk[j][k]<=look && map[j][k]=='.'){goto skip;}
				}
			}
			ok=search(look+1,num);
			skip:paint(n,x,y,dir,'.');
		}
		if(ok==1)return 1;
	}
	return 0;
}
int main(){
    int i,j,k,hh,ww,num,q1,q2;
    while(scanf("%d %d",&H,&W)*(H+W)){
		SET++;
		for(i=0;i<H;i++)scanf("%s",map[i]);
		SPACE=0;
		for(i=0;i<H;i++){
			for(j=0;j<W;j++){
				if(map[i][j]=='.')SPACE++;
			}
		}
		scanf("%d",&N);
		for(i=0;i<N;i++){
			order[i]=i;
			scanf("%d %d",&hh,&ww);
			size[i][0]=hh;size[i][1]=ww;
			for(j=0;j<hh;j++)scanf("%s",piece[j]);
			q1=1;q2=1;num=0;
			if(hh!=ww)q1=0;
			for(j=0;j<hh;j++){
				for(k=0;k<ww;k++){
					if(piece[j][k]!=piece[k][hh-1-j])q1=0;
					if(piece[j][k]!=piece[hh-1-j][ww-1-k])q2=0;
					if(piece[j][k]=='#'){
						pie[i][num][0]=j;
						pie[i][num][1]=k;
						num++;
					}
				}
			}
			size[i][2]=num;
			nsel[i]=0;
			for(j=0;j<H-hh+1;j++){
				for(k=0;k<W-ww+1;k++){
					check(i,j,k,0,&nsel[i]);
					if(!q2)check(i,j,k,2,&nsel[i]);
				}
			}
			if(!q1){
				for(j=0;j<H-ww+1;j++){
					for(k=0;k<W-hh+1;k++){
						check(i,j,k,1,&nsel[i]);
						if(!q2)check(i,j,k,3,&nsel[i]);
					}
				}
			}
		}
		for(i=1;i<N;i++){
			for(j=i;j>0;j--){
				if(nsel[order[j-1]]>nsel[order[j]])swap(&order[j-1],&order[j]);
				else break;
			}
		}
		for(scanf("%d",&PL);PL>0;PL--){
			scanf("%d",&num);
			for(i=0;i<N;i++)list[i]=0;
			for(i=0;i<H;i++){
				for(j=0;j<W;j++){
					mk[i][j]=-1;
				}
			}
			for(i=0,j=0;i<num;i++){
				scanf("%d",&k);
				list[k-1]++;
				j+=size[k-1][2];
			}
			if(SPACE!=j){printf("NO\n");continue;}
			for(i=0,k=0;i<N && k<num;i++){
				for(j=list[order[i]];j>0;j--){
					q[k]=order[i];
					k++;
				}
			}
			for(i=0;i<num;i++){
				for(j=nsel[q[i]]-1;j>=0;j--){
					cover(q[i],sel[q[i]][j][0],sel[q[i]][j][1],sel[q[i]][j][2],0);
				}
			}
			q1=1;
			for(j=0;j<H;j++){
				for(k=0;k<W;k++){
					if(mk[j][k]==-1 && map[j][k]=='.'){q1=0;goto out;}
				}
			}
			out:if(!q1){printf("NO\n");continue;}
			if(search(0,num))printf("YES\n"); else printf("NO\n");
		}
    }
    return 0;
}