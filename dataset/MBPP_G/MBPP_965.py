def camel_to_snake(text):
    import re
    return re.sub('(?<!^)(?=[A-Z])', '_', text).lower()
print(camel_to_snake('PythonProgram'))
print(camel_to_snake('pythonLanguage'))
print(camel_to_snake('ProgrammingLanguage'))