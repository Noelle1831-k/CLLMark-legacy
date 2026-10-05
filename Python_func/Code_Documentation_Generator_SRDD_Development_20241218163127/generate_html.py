def generate_html(self, doc_data):
        '''
        Generates HTML documentation from parsed data.
        '''
        html_content = "<html><head><title>Documentation</title></head><body>"
        html_content += "<h1>Documentation</h1>"
        html_content += "<h2>Comments</h2><ul>"
        for comment in doc_data['comments']:
            html_content += f"<li>{comment}</li>"
        html_content += "</ul><h2>Classes</h2><ul>"
        for cls in doc_data['classes']:
            html_content += f"<li>{cls}</li>"
        html_content += "</ul><h2>Functions</h2><ul>"
        for func in doc_data['functions']:
            html_content += f"<li>{func}</li>"
        html_content += "</ul><h2>Variables</h2><ul>"
        for var in doc_data['variables']:
            html_content += f"<li>{var}</li>"
        html_content += "</ul></body></html>"
        return html_content