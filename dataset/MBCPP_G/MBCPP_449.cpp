double area = 0.5 * abs(x1*(y2 - y3) + x2*(y3 - y1) + x3*(y1 - y2));
if (area > 0) return "Yes";
else return "No";
}