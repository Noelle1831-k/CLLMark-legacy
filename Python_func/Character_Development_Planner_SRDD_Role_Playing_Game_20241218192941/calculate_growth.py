def calculate_growth(attributes):
    total = sum(attributes.values())
    growth = total // len(attributes) if attributes else 0
    return growth