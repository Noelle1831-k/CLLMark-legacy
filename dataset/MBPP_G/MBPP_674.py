from collections import OrderedDict

def remove_duplicate(string):
    return ' '.join(OrderedDict.fromkeys(string.split()))