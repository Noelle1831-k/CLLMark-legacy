def remove_list_range(list1, leftrange, rigthrange):
    return [sublst for sublst in list1 if all((leftrange <= item <= rigthrange for item in sublst))]