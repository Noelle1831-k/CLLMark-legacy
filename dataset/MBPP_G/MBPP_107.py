def count_Hexadecimal(L, R):
    return sum((1 for i in range(L, R + 1) if any((char in 'ABCDEF' for char in hex(i)[2:].upper()))))