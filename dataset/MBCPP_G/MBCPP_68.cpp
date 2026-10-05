if(a.empty()) return true;
bool increasing = true, decreasing = true;
for(int i = 1; i < a.size(); ++i) {
    if(a[i] > a[i-1]) decreasing = false;
    if(a[i] < a[i-1]) increasing = false;
}
return increasing || decreasing;
}