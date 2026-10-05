def _determine_file_type(self, file_path):
        if file_path.endswith('.docx'):
            return 'document'
        elif file_path.endswith('.xlsx'):
            return 'spreadsheet'
        elif file_path.endswith('.pptx'):
            return 'presentation'
        elif file_path.endswith(('.jpg', '.png')):
            return 'image'
        else:
            raise ValueError("Unsupported file type")