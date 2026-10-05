	int count1=0,count0=0;
	int start=-1,end=-1;
	int result=0;
	for(int i=0;i<n;i++){
		if(str[i]=='1'){
			count1++;
		}
		else {
			count0++;
		}
		if(count0-count1>result){
			start=count0;
			end=count1;
		}
	}
	return end-start;
}
<|endoftext|>