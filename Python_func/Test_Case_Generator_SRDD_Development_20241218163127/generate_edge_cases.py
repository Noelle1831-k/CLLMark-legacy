def generate_edge_cases(param_names):
    edge_cases = []
    for name in param_names:
        edge_cases.append({name: None})
        edge_cases.append({name: float('inf')})
        edge_cases.append({name: float('-inf')})
        edge_cases.append({name: float('nan')})
    return edge_cases