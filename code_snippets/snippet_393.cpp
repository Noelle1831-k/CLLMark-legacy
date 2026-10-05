	int triangle_area = abs((x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) / 2);
	int triangle_perimeter = abs((x1 - x2) + (x2 - x3) + (x3 - x1));
	if (triangle_area == triangle_perimeter)
		return "Yes";
	else
		return "No";
}
<|endoftext|>