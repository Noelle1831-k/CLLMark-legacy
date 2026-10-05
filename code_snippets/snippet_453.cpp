	if(num==1)
		return 1;
	else{
		int low=1,high=num/2;
		while(low<=high){
			int mid = low+(high-low)/2;
			if(mid*mid==num){
				return mid;
			}
			else if(mid*mid<num){
				low=mid+1;
			}
			else {
				high=mid-1;
			}
		}
	}
	return 0;
}
<|endoftext|>