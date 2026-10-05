	unordered_map<int,int> myhash;
	for(int i=0;i<n;i++) {
		myhash[arr1[i]]=myhash[arr1[i]]+1;
	}
	for(int i=0;i<n;i++) {
		myhash[arr2[i]]=myhash[arr2[i]]-1;
	}
	for(int i=0;i<n;i++) {
		if(myhash[arr2[i]]==1)
		return arr2[i];
	}
	return -1;
}
<|endoftext|>