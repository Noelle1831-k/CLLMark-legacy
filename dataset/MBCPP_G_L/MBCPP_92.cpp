if (n.length() < 3) return false;
char first = n[0], second = n[1];
if (first == second) return false;
for (int i = 2; i < n.length(); i++) {
    if (n[i] != n[i % 2]) {
        return false;
    }
}
return true;
}