if (m < 0 || n < 0 || m >= tri.size() || n > m) return 0;
if (m == 0) return tri[0][0];
int left = maxPathSum(tri, m-1, n-1);
int right = maxPathSum(tri, m-1, n);
return tri[m][n] + max(left, right);
}