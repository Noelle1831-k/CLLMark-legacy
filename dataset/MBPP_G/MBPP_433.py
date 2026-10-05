def check_greater(arr, number):
    if all((number > x for x in arr)):
        return 'Yes, the entered number is greater than those in the array'
    else:
        return 'No, entered number is less than those in the array'