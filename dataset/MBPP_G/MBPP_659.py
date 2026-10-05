def Repeat(x):
    return list({item for item in x if x.count(item) > 1})