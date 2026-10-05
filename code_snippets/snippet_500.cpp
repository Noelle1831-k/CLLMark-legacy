	int i,j;
	int sum,max_sum;
	int count,max_count;
	count=0;
	max_count=0;
	max_sum=0;
	for(i=0;i<n;i++){
		count=0;
		sum=0;
		for(j=i;j<n;j++){
			sum=sum+arr[j];
			if(sum<=k){
				count++;
			}
		}
		if(count>max_count){
			max_count=count;
			max_sum=sum;
		}
	}
	return max_sum;
}
<|endoftext|>