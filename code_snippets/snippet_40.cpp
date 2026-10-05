	map<int,int> mymap;
	int count,ans=0;
	for(int i=0;i<arr.size();i++){
		count=mymap[arr[i]];
		count++;
		mymap[arr[i]]=count;
		if(count>1){
			ans+=arr[i];
		}
	}
	return ans;
}
<|endoftext|>