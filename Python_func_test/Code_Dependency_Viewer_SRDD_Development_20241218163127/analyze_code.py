def analyze_code(self, file, dependency_graph):
        '''
        Analyzes the source code and identifies dependencies.
        '''
        content = self.read_file(file)
        classes = self.parse_file(content)
        for cls in classes:
            dependency_graph.add_node(cls)
            for dep in classes[cls]:
                dependency_graph.add_edge(cls, dep)