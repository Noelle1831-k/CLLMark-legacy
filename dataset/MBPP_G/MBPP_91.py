def find_substring(str_list, sub_str):
    return any((sub_str in s for s in str_list))