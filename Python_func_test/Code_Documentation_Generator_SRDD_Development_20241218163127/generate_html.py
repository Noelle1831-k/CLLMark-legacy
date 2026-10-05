def generate_html(self, doc_data):
        '''
        Generates HTML documentation from parsed data.
        '''
        html_content = f'<html><head><title>Documentation</title></head><body>'
        html_content = html_content + f'<h1>Documentation</h1>'
        html_content = html_content + f'<h2>Comments</h2><ul>'
        for comment in doc_data[f'comments']:
            html_content = html_content + f'<li>{comment}</li>'
        html_content = html_content + f'</ul><h2>Classes</h2><ul>'
        for cls in doc_data[f'classes']:
            html_content = html_content + f'<li>{cls}</li>'
        html_content = html_content + f'</ul><h2>Functions</h2><ul>'
        for func in doc_data[f'functions']:
            html_content = html_content + f'<li>{func}</li>'
        html_content = html_content + f'</ul><h2>Variables</h2><ul>'
        for var in doc_data[f'variables']:
            html_content = html_content + f'<li>{var}</li>'
        html_content = html_content + f'</ul></body></html>'
        return html_content