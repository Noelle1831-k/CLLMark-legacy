int count = 0;
if (x == y) count++;
if (y == z) count++;
if (x == z) count++;
if (count == 3) return 3;
return count;
}