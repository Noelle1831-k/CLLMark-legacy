def remove(list):
    return [''.join(filter(lambda x: not x.isdigit(), word)) for word in list]