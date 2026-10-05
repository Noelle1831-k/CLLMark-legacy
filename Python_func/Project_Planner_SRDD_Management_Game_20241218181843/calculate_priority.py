def calculate_priority(priority_level):
    priority_map = {
        'low': 1,
        'medium': 2,
        'high': 3
    }
    return priority_map.get(priority_level.lower(), 0)