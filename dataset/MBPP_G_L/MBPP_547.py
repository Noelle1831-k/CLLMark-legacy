def Total_Hamming_Distance(n):
    def hamming_distance(x, y):
        return bin(x ^ y).count('1')
    total_distance = 0
    for i in range(n):
        total_distance += hamming_distance(i, i + 1)
    return total_distance
print(Total_Hamming_Distance(4))
print(Total_Hamming_Distance(2))
print(Total_Hamming_Distance(5))