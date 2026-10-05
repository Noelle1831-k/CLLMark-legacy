def _xml_to_dict(self, root):
        result = {}
        for child in root:
            result[child.tag] = child.text
        return result