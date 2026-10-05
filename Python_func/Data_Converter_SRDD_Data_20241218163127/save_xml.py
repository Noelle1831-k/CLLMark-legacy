def save_xml(self, data, file_path):
        root = ET.Element('root')
        self._dict_to_xml(data, root)
        tree = ET.ElementTree(root)
        tree.write(file_path)