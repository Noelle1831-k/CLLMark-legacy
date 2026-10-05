def decimal_to_Octal(deciNum):
    octalNum = 0
    placeValue = 1
    while deciNum > 0:
        remainder = deciNum % 8
        octalNum += remainder * placeValue
        deciNum //= 8
        placeValue *= 10
    return octalNum