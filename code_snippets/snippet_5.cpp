	if (n <= 0)
		return 0;
	int dp[n + 1];
	dp[0] = 1;
	dp[1] = 1;
	dp[2] = 2;
	for (int i = 3; i <= n; i++)
		dp[i] = dp[i - 1] + dp[i - 2];
	return dp[n];
}
int MaxArea(vector<int>& height) {
	int i = 0, j = height.size() - 1, area = 0;
	while (i < j) {
		area = max(area, min(height[i], height[j]) * (j - i));
		if (height[i] < height[j])
			i++;
		else
			j--;
	}
	return area;
}
int MaxArea(int* height, int heightSize) {
	int i = 0, j = heightSize - 1, area = 0;
	while (i < j) {
		area = max(area, min(height[i], height[j]) * (j - i));
		if (height[i] < height[j])
			i++;
		else
			j--;
	}
	return area;
}
int MaxArea(int* height, int heightSize) {
	int i = 0, j = heightSize - 1, area = 0;
	while (i < j) {
		area = max(area, min(height[i], height[j]) * (j - i));
		if (height[i] < height[j])
			i++;
		else
			j--;
	}
	return area;
}
int MaxArea(int* height, int heightSize) {
	int i = 0, j = heightSize - 1, area = 0;
	while (i < j) {
		area = max(area, min(height[i], height[j]) * (j - i));
		if (height[i] < height[j])
			i++;
		else
			j--;
	}
	return area;
}
int MaxArea(int* height, int heightSize) {
	int i = 0, j = heightSize - 1, area = 0;
	while (i < j) {
		area = max(area, min(height[i], height[j]) * (j - i));
		if (height[i] < height[j])
			i++;
		else
			j--;
	}
	return area;
}
int MaxArea(int* height, int heightSize) {
	int i = 0, j = heightSize - 1, area = 0;
	while (i < j) {
		area = max(area, min(height[i], height[j]) * (j - i));
		if (height[i] < height[j])
			i++;
		else
			j--;
	}
	return area;
}
int MaxArea(int* height, int heightSize) {
	int i = 0, j = heightSize - 1, area = 0;
	while (i < j) {
		area = max(area, min(height[i], height[j]) * (j - i));
		if (height[i] < height[j])
			i++;
		else
			j--;
	}
	return area;
}
int MaxArea(int* height, int heightSize) {
	int i = 0, j = heightSize - 1, area = 0;
	while (i < j) {
		area = max(area, min(height[i], height[j]) * (j - i));
		if (height[i] < height[j])
			i++;
		else
			j--;
	}
	return area;
}
/**
 * @brief Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (