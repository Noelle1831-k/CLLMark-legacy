def convert(numbers):
    if isinstance(numbers, (int, float)):
        numbers = complex(numbers, 0)
    magnitude = abs(numbers)
    angle = cmath.phase(numbers)
    return (magnitude, angle)