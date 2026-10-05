def gcd(a, b):
    while b:
        a, b = (b, a % b)
    return a
def lcm(a, b):
    return abs(a * b) // gcd(a, b)
def get_lcm(l):
    current_lcm = l[0]
    for num in l[1:]:
        current_lcm = lcm(current_lcm, num)
    return current_lcm