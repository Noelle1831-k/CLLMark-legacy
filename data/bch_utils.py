def gf2_add(poly1: int, poly2: int) -> int:
    return poly1 ^ poly2


def gf2_mul(poly1: int, poly2: int) -> int:
    result = 0
    temp = poly2
    while poly1 > 0:
        if (poly1 & 1) == 1:
            result ^= temp
        poly1 >>= 1
        temp <<= 1
    return result


def gf2_div(dividend: int, divisor: int) -> int:
    def degree(poly: int) -> int:
        return poly.bit_length() - 1
    deg_divisor = degree(divisor)
    remainder = dividend

    while degree(remainder) >= deg_divisor and remainder != 0:
        shift = degree(remainder) - deg_divisor
        remainder = gf2_add(remainder, divisor << shift)
    return remainder


G = 0b1011


def encode_bch_7_4(msg_bits: list[int]) -> list[int]:
    M = 0
    for bit in msg_bits:
        M = (M << 1) | (bit & 1)
    M_shifted = M << 3
    remainder = gf2_div(M_shifted, G)
    code_int = M_shifted ^ remainder
    code_bits = []
    for i in range(6, -1, -1):
        code_bits.append((code_int >> i) & 1)
    return code_bits


def build_syndrome_table(generator: int) -> dict[int, int]:
    table = {}
    code = 0
    syndrome = gf2_div(code, generator)
    table[syndrome] = code
    for i in range(7):
        code = 1 << i
        syndrome = gf2_div(code, generator)
        table[syndrome] = code
    return table


def decode_bch_7_4(code_bits: list[int],
                   syndrome_table: dict[int, int]) -> tuple[list[int], int]:

    code_int = 0
    for bit in code_bits:
        code_int = (code_int << 1) | bit
    syn = gf2_div(code_int, G)
    if syn == 0:
        err_pos = -1
        corrected_code_int = code_int
    else:
        if syn in syndrome_table:
            err_pattern = syndrome_table[syn]
            corrected_code_int = code_int ^ err_pattern
            err_pos = (err_pattern.bit_length() - 1) if err_pattern != 0 else -1
        else:
            err_pos = -1
            corrected_code_int = code_int
    decoded_msg_bits = []
    for i in range(6, 2, -1):
        decoded_msg_bits.append((corrected_code_int >> i) & 1)
    return decoded_msg_bits, err_pos



def decode(received):
    syndrome_table = build_syndrome_table(G)
    decoded_msg, err_p = decode_bch_7_4(received, syndrome_table)
    return decoded_msg
