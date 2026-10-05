	int low = 0;
	int high = n-1;
	while(low<=high){
		int mid = low+(high-low)/2;
		if(arr[mid]>arr[high]){
			low = mid+1;
		}
		else if(arr[mid]<arr[high]){
			high = mid-1;
		}
		else{
			high--;
		}
	}
	return n-low;
}
int main(){
	vector<int> arr1 = {3, 2, 1};
	vector<int> arr2 = {4, 5, 1, 2, 3};
	vector<int> arr3 = {7, 8, 9, 1, 2, 3};
	cout<<countRotation(arr1, 3)<<endl;
	cout<<countRotation(arr2, 5)<<endl;
	cout<<countRotation(arr3, 6)<<endl;
	return 0;
}
<|endoftext|>