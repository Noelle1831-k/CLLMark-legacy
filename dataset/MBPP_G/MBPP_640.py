def remove_parenthesis(items):
    result = []
    for item in items:
        start = item.find('(')
        end = item.find(')')
        if start != -1 and end != -1:
            result.append(item[0:start].strip())
        else:
            result.append(item.strip())
    return tuple(result)