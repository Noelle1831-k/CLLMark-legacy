def round_and_sum(list1):
    rounded_list = [round(num) for num in list1]
    total_sum = sum(rounded_list)
    result = total_sum * len(list1)
    print(result)