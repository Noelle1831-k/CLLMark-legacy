def move_num(test_str):
    import re
    alpha_part = ''.join(re.findall('[^\\d]+', test_str))
    num_part = ''.join(re.findall('\\d+', test_str))
    return alpha_part + num_part
print(move_num('I1love143you55three3000thousand'))
print(move_num('Avengers124Assemble'))
print(move_num('Its11our12path13to14see15things16do17things'))