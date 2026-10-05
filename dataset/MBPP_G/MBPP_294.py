def max_val(listval):
    numeric_values = [item for item in listval if isinstance(item, (int, float))]
    return max(numeric_values) if numeric_values else None