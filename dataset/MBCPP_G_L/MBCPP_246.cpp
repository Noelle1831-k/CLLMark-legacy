double x = number;
double y = 1.0;
double epsilon = 0.000001;

while (x - y > epsilon) {
    x = (x + y) / 2;
    y = number / x;
}

return x;
}