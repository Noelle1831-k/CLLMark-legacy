def standardize_data_formats(data):
    standardized_data = list()
    for item in data:
        standardized_item = str(item).strip().lower()
        standardized_data.append(standardized_item)
    return standardized_data