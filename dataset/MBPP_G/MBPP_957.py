def get_First_Set_Bit_Pos(n):
    return (n & -n).bit_length()