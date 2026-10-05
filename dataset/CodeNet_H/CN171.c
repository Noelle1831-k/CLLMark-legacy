#define I(x,y,z) x,y,z,y,z,x,z,x,y
R[24][3]={I(0,1,2),I(0,2,4),I(0,3,1),I(0,4,3),I(1,3,5),I(1,5,2),I(2,5,4),I(3,4,5)};
X[2][2],Y[2][2],Z[2][2];
char D[8][7];
S(p,u){
	int x=p&1,y=p/2&1,z=p/4&1,d,r;
	p-8||main(puts("YES"));
	for(r=p?24:1;r--;)
		for(d=8;d--;)
			u&1<<d&&
			(!x?X[y][z]=D[d][*R[r]]:(X[y][z]^D[d][5-*R[r]])==32)&&
			(!y?Y[z][x]=D[d][R[r][1]]:(Y[z][x]^D[d][5-R[r][1]])==32)&&
			(!z?Z[x][y]=D[d][R[r][2]]:(Z[x][y]^D[d][5-R[r][2]])==32)&&
			S(p+1,u^1<<d);
}
main(){
	for(;read(0,D,56)==56;puts("NO"))
		S(0,255);
	puts("");
	exit(0);
}