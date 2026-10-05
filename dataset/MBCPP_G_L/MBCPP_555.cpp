int sum_of_cubes = 0, sum_of_numbers = 0;
for (int i = 1; i <= n; i++) {
    sum_of_cubes += i * i * i;
    sum_of_numbers += i;
}
return sum_of_cubes - sum_of_numbers;
}