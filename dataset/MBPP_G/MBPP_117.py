def list_to_float(test_list):
    return [(float(a) if a.replace('.', '', 1).isdigit() else a, float(b) if b.replace('.', '', 1).isdigit() else b) for a, b in test_list]