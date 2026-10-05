def even_or_odd(N):
    l = len(N)
    if (N[l - 1] == '0' or N[l - 1] == '2' or
            N[l - 1] == '4' or N[l - 1] == '6' or
            N[l - 1] == '8' or N[l - 1] == 'A' or
            N[l - 1] == 'C' or N[l - 1] == 'E' or
            N[l - 1] == 'a' or N[l - 1] == 'c' or N[l - 1] == 'e'):
        return ("Even")
    else:
        return ("Odd")