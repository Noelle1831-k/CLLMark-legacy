int result = 0;
bool negative = false;
if ((x < 0 && y > 0) || (x > 0 && y < 0)) negative = true;
x = abs(x);
y = abs(y);
for (int i = 0; i < y; ++i) {
    result += x;
}
return negative ? -result : result;
}