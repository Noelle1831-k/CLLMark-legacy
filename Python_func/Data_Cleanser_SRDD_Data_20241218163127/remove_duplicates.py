def remove_duplicates(data):
    seen = set()
    unique_data = []
    for item in data:
        if item not in seen:
            unique_data.append(item)
            seen.add(item)
    return unique_data