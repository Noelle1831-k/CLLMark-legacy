def babylonian_squareroot(number):
    guess = number / 2.0
    while abs(guess * guess - number) > 1e-10:
        guess = (guess + number / guess) / 2.0
    return guess