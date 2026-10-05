	return ((n%m)+m)%m;
}
"""
def find(n, m):
    return ((n % m) + m) % m
def find2(n, m):
    return (n % m + m) % m
if __name__ == '__main__':
    print("find(3, 3)", find(3, 3))
    print("find(10, 3)", find(10, 3))
    print("find(16, 5)", find(16, 5))
    print("find2(3, 3)", find2(3, 3))
    print("find2(10, 3)", find2(10, 3))
    print("find2(16, 5)", find2(16, 5))
    """
    find(3, 3) 0
    find(10, 3) 1
    find(16, 5) 1
    find2(3, 3) 0
    find2(10, 3) 1
    find2(16, 5) 1
    """
<|endoftext|>