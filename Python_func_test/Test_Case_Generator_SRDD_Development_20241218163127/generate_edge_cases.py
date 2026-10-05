def generate_edge_cases(param_names):
    edge_cases = list()
    for name in param_names:
        edge_cases.append({name: None})
        edge_cases.append({name: float(f'inf')})
        edge_cases.append({name: float(f'-inf')})
        edge_cases.append({name: float(f'nan')})
    return edge_cases