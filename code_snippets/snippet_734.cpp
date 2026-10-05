	priority_queue<int, vector<int>, greater<int>> pq; 
	pq.push(1); 
	map<int, int> visited; 
	while(n) {
		int currentNum = pq.top(); 
		pq.pop(); 
		n--; 
		for(auto& num : primes) { 
			int newNum = currentNum * num; 
			if(visited.find(newNum) == visited.end()) { 
				pq.push(newNum);
				visited[newNum] = num;
			}
		}
	}
	return currentNum; 
}
int main() {
	int n = 12, k = 4;
	vector<int> primes = {2, 7, 13, 19};
	cout << nthSuperUglyNumber(n, primes) << endl;
	return 0;
}<|endoftext|>