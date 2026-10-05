def convert_image(self, input_file, output_format):
        image = Image.open(input_file)
        if output_format in ['jpg', 'png']:
            output_file = input_file.rsplit('.', 1)[0] + '.' + output_format
            image.save(output_file)
            print(f"Converting image {input_file} to {output_format}")
        else:
            raise ValueError("Unsupported conversion format for images")