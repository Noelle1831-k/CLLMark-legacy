	for (int i = 0; i < sqrt(n); i++) {
		if (i * i == n) return true;
		if ((n - i * i) * (n - i * i) == n) return true;
	}
	return false;
}
"""
"""
Question 8:
You are given the matrix M with n rows and m columns of integer values.
You are required to print the matrix M with a space in between the matrix elements.
> input:
> [[1, 2, 3, 4, 5],
>  [16, 17, 18, 19, 6],
>  [15, 24, 25, 20, 7],
>  [14, 23, 22, 21, 8],
>  [13, 12, 11, 10, 9]]
> output:
> 1 2 3 4 5 16 17 18 19 6 15 24 25 20 7 14 23 22 21 8 13 12 11 10 9
> input:
> [[1, 2, 3, 4, 5, 6, 7],
>  [16, 17, 18, 19, 6, 7, 8],
>  [15, 24, 25, 20, 7, 8, 9],
>  [14, 23, 22, 21, 8, 9, 10],
>  [13, 12, 11, 10, 9, 10, 11],
>  [1, 2, 3, 4, 5, 6, 7],
>  [16, 17, 18, 19, 6, 7, 8]]
> output:
> 1 2 3 4 5 6 7 16 17 18 19 6 7 8 15 24 25 20 7 8 9 14 23 22 21 8 9 10 13 12 11 10 9 10 11 1 2 3 4 5 6 7 16 17 18 19 6 7 8
"""
"""
Question 9:
You are given the matrix M with n rows and m columns of integer values.
You are required to print the matrix M with a space in between the matrix elements.
> input:
> [[1, 2, 3, 4, 5],
>  [16, 17, 18, 19, 6],
>  [15, 24, 25, 20, 7],
>  [14, 23, 22, 21, 8],
>  [13, 12, 11, 10, 9]]
> output:
> 1 2 3 4 5 16 17 18 19 6 15 24 25 20 7 14 23 22 21 8 13 12 11 10 9
> input:
> [[1, 2, 3, 4, 5, 6, 7],
>  [16, 17, 18, 19, 6, 7, 8],
>  [15, 24, 25, 20, 7, 8, 9],
>  [14, 23, 22, 21, 8, 9, 10],
>  [13, 12, 11, 10, 9, 10, 11],
>  [1, 2, 3, 4, 5, 6, 7],
>  [16, 17, 18, 19, 6, 7, 8]]
> output:
> 1 2 3 4 5 6 7 16 17 18 19 6 7 8 15 24 25 20 7 8 9 14 23 22 21 8 9 10 13 12 11 10 9 10 11 1 2 3 4 5 6 7 16 17 18 19 6 7 8
"""
"""
Question 10:
You are given the matrix M with n rows and m columns of integer values.
You are required to print the matrix M with a space in between the matrix elements.
> input:
> [[1, 2, 3, 4, 5],
>  [16, 17, 18, 19, 6],
>  [15, 24, 25, 20, 7],
>  [14, 23, 22, 21, 8],
>  [13, 12, 11, 10, 9]]
> output:
> 1 2 3 4 5 16 17 18 19 6 15 24 25 20 7 14 23 22 21 8 13 12 11 10 9
> input:
> [[1, 2, 3, 4, 5, 6, 7],
>  [16, 17, 18, 19, 6, 7, 8],
>  [15, 24, 25, 20, 7, 8, 9],
>  [14, 23, 22, 21, 8, 9, 10],
>  [13, 12, 11, 10, 9, 10, 11],
>  [1, 2, 3, 4, 5, 6, 7],
>  [16, 17, 18, 19, 6, 7, 8]]
> output:
> 1 2 3 4 5 6 7 16 17 18 19 6 7 8 15 24 25 20 7 8 9 14 23 22 21 8 9 10 13 12 11 10 9 10 11 1 2 3 4 5 6 7 16 17 18 19 6 7 8
"""
"""
Question 11:
You are given the matrix M with n rows and m columns of integer values.
You are required to print the matrix M with a space in between the matrix elements.
> input:
> [[1, 2, 3, 4, 5],
>  [16, 17, 18, 19, 6],
>  [15, 24, 25, 20, 7],
>  [14, 23, 22, 21, 8],
>  [13, 12, 11, 10, 9]]
> output:
> 1 2 3 4 5 16 17 18 19 6 15 24 25 20 7 14 23 22 21 8 13 12 11 10