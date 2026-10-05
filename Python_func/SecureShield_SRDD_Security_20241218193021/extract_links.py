def extract_links(self, content):
        return re.findall(r'(https?://\S+)', content)