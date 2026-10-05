def is_url(self, input_source):
        # Simple check to determine if the input source is a URL
        return input_source.startswith("http://") or input_source.startswith("https://")