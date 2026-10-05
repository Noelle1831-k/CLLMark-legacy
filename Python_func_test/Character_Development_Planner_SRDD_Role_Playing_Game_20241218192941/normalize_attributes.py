def normalize_attributes(attributes):
    max_value = max(attributes.values()) if attributes else 1
    return {k: v / max_value for k, v in attributes.items()}