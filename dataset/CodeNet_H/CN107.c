int i,j,k,temp;
int bouble_sort(int area[5]){	
	temp=0;
	for(i=0;i<2;i++){						
		for(j=2;i<j;j--){
			if(area[j-1]>area[j]){
				temp=area[j];
				area[j]=area[j-1];
				area[j-1]=temp;
			}
		}
	}
	return area[2];
}
int main(void){
	int n,height,width,depth,box_area[5],hole[10000]={0},max_area;
	int hantei[10000]={0};
	double hole_area[10000];
	while(1){
		height=0;
		width=0;
		depth=0;
		n=0;
		max_area=0;
		for(i=0;i<10000;i++){
			hole_area[i]=0;
			hole[i]=0;
			hantei[i]=0;
		}
		for(i=0;i<5;i++){
			box_area[i];
		}
		scanf("%d%*c%d%*c%d",&height,&width,&depth);
		if(height==0 && width==0 && depth==0){
			break;
		}
		scanf("%d",&n);
		for(i=0;i<n;i++){
			scanf("%d",&hole[i]);
		}
		for(i=0;i<n;i++){
			hole_area[i]=(double)hole[i]*(double)hole[i]*3.14;
		}
		box_area[0]=height*width;	
		box_area[1]=height*depth;
		box_area[2]=width*depth;
		bouble_sort(box_area);
		max_area=bouble_sort(box_area);
		for(i=0;i<n;i++){
			if(hole_area[i]>max_area){
				hantei[i]=1;
			}
			else{
				hantei[i]=0;
			}
		}
		for(i=0;i<n;i++){
			if(hantei[i]==1){
				printf("OK\n");
				}
			else{
				printf("NA\n");	
			}
		}
	}
	return 0;
}