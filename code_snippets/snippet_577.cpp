	int maxSum=0, temp=0;
	for(int i=0; i<n-2; i++){
		temp=arr[i];
		temp+=arr[i+1];
		temp+=arr[i+2];
		if(temp>maxSum){
			maxSum=temp;
		}
	}
	return maxSum;
}
int main(){
	vector<int> arr={3000, 2000, 1000, 3, 10};
	int n=arr.size();
	cout<<maxSumOfThreeConsecutive(arr, n);
	return 0;
}
<|endoftext|>