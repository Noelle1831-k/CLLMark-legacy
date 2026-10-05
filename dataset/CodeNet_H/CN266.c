int main(void){
	clock_t startTime, endTime;
	using namespace std;
	int i,j;
	long long int fact[100000]={0};
	for(i=0; i<100000; i++){
		if(i==0) fact[i] = 1;
		else fact[i] = (fact[i-1]*i)%1000000007;
	}
	long int N,K;
	cin >> N;
	while(N!=0){
		cin >> K;
		long int a,b;
		long int k=0, value=0, index = -1;
		vector <long int> data;
		vector <long int> data2;
		vector <long int>::iterator itr;
		for(i=0; i<N; i++){
			data.push_back(i);
			data2.push_back(i);
		}
		for(i=0; i<K; i++){
		cin >> a >> b;
		swap(data[a-1],data[b-1]);
		}
		for(i=0; i<N; i++){
			itr = find(data2.begin(), data2.end(), data[i]);
			index = itr - data2.begin();
			k = data[i] - index;
			value += (data[i]-k)*fact[N-1-i];
			value = value % 1000000007;
			data2.erase(itr);
		}
		cout << value <<endl;
		cin >> N;
	}
	return 0;
}