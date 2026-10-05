def extract_even(test_tuple):

    def is_even_element(element):
        if isinstance(element, int):
            return element % 2 == 0
        elif isinstance(element, tuple):
            return True
        return False

    def extract_from_nested_tuple(t):
        result = []
        for elem in t:
            if isinstance(elem, tuple):
                nested_result = extract_from_nested_tuple(elem)
                if nested_result:
                    result.append(nested_result)
            elif is_even_element(elem):
                result.append(elem)
        return tuple(result)
    return extract_from_nested_tuple(test_tuple)