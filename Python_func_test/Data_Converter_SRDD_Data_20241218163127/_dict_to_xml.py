def _dict_to_xml(self, data, root):
        for key, value in data.items():
            child = ET.SubElement(root, key)
            child.text = str(value)