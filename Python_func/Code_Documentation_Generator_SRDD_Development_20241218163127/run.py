def run(self):
        '''
        Executes the main workflow of the application.
        '''
        for root, _, files in os.walk(self.source_dir):
            for file in files:
                if file.endswith('.py'):
                    file_path = os.path.join(root, file)
                    doc_data = self.parser.parse_file(file_path)
                    html_content = self.generator.generate_html(doc_data)
                    pdf_content = self.generator.generate_pdf(doc_data)
                    self.exporter.export_as_html(html_content, os.path.join(self.output_dir, file.replace('.py', '.html')))
                    self.exporter.export_as_pdf(pdf_content, os.path.join(self.output_dir, file.replace('.py', '.pdf')))