int n = input.size();
if(k > n) k = n;
reverse(input.begin(), input.begin() + k);
return input;
}