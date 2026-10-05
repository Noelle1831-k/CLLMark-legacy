def sample_nam(sample_names):
    return sum((len(name) for name in sample_names if name[0].isupper()))