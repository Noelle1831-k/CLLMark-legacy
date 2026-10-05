def parse_file(self, content):
        '''
        Parses a single file to identify classes and their dependencies.
        '''
        classes = {}
        class_pattern = re.compile(r'class (\w+)')
        dependency_pattern = re.compile(r'(\w+)\(')
        lines = content.split('\n')
        current_class = None
        for line in lines:
            class_match = class_pattern.search(line)
            if class_match:
                current_class = class_match.group(1)
                classes[current_class] = []
            elif current_class:
                dependency_match = dependency_pattern.findall(line)
                for dep in dependency_match:
                    classes[current_class].append(dep)
        return classes