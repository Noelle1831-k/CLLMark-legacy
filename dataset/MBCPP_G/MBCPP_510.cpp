int n = arr.size(); 
sort(arr.begin(), arr.end()); 
int count = 0; 
for(int i = 0; i < n; i++) { 
    if(arr[i] >= k) 
        break; 
    int product = arr[i]; 
    for(int j = i + 1; j < n; j++) { 
        product *= arr[j]; 
        if(product < k) 
            count += 1; 
        else 
            break; 
    } 
} 
return count + n;  // Each individual element is also a valid subsequence if less than k.
}