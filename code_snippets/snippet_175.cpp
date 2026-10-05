	int count = 0;
	while (x1 <= x2 && y1 <= y2) {
		count++;
		x1++;
		y1++;
	}
	return count;
}
int main() {
	countIntgralPoints(1, 1, 4, 4);
	countIntgralPoints(1, 2, 1, 2);
	countIntgralPoints(4, 2, 6, 4);
	return 0;
}
<|endoftext|>