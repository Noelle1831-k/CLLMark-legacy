vector<int> pos, neg;
for(int i = 0; i < n; i++) {
    if(arr[i] >= 0) 
        pos.push_back(arr[i]);
    else 
        neg.push_back(arr[i]);
}

int p = 0, q = 0, index = 0;
while(p < pos.size() && q < neg.size()) {
    if(index % 2 == 0) 
        arr[index++] = neg[q++];
    else 
        arr[index++] = pos[p++];
}

while(q < neg.size()) 
    arr[index++] = neg[q++];
while(p < pos.size()) 
    arr[index++] = pos[p++];

return arr;
}