def get_equal(Input, k):
    if all((len(t) == k for t in Input)):
        return 'All tuples have same length'
    else:
        return 'All tuples do not have same length'