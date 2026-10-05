	int i,j;
	for(i=0;i<n;i++){
		for(j=i+1;j<n;j++){
			if(arr[i]<arr[j]){
				int temp=arr[i];
				arr[i]=arr[j];
				arr[j]=temp;
			}
		}
	}
	string ret = "";
	for(int i=0;i<n;i++){
		ret.push_back(arr[i]+'0');
	}
	return stoi(ret);
}
int main()
{
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<int> arr(n);
		for(int i=0;i<n;i++){
			cin>>arr[i];
		}
		cout<<findMaxNum(arr, n)<<endl;
	}
	return 0;
}<|endoftext|>