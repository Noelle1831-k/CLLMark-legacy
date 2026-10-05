def sum_of_divisors(n):
    divisors_sum = 1
    for i in range(2, int(n ** 0.5) + 1):
        if n % i == 0:
            divisors_sum += i
            if i != n // i:
                divisors_sum += n // i
    return divisors_sum

def amicable_numbers_sum(limit):
    amicable_sum = 0
    for num in range(2, limit):
        partner = sum_of_divisors(num)
        if partner != num and partner < limit and (sum_of_divisors(partner) == num):
            amicable_sum += num
    return amicable_sum