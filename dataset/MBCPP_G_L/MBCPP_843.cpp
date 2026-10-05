priority_queue<long, vector<long>, greater<long>> minHeap;
set<long> seen;
minHeap.push(1);
seen.insert(1);
long currentUgly = 1;
for(int i = 0; i < n; i++) {
    currentUgly = minHeap.top();
    minHeap.pop();
    for(int prime : primes) {
        long newUgly = currentUgly * prime;
        if(seen.insert(newUgly).second) {
            minHeap.push(newUgly);
        }
    }
}
return currentUgly;
}