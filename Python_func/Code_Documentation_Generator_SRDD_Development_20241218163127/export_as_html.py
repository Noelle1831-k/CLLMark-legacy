def export_as_html(self, html_content, output_path):
        '''
        Exports the documentation as an HTML file.
        '''
        with open(output_path, 'w', encoding='utf-8') as file:
            file.write(html_content)