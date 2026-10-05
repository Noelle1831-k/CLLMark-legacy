int count = 0;
for (int i = ceil(sqrt(n)); i <= floor(sqrt(m)); ++i) {
    if (i % 2 != 0) {
        ++count;
    }
}
return count;
}