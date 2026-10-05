def load_xml(self, file_path):
        tree = ET.parse(file_path)
        root = tree.getroot()
        return self._xml_to_dict(root)