def scan_receipt(self, file_path):
        '''
        Scans a receipt from an image file.
        Parameters:
        file_path (str): The path to the image file of the receipt.
        Returns:
        dict: A dictionary containing extracted data from the receipt.
        '''
        try:
            # Load the image from file
            image = cv2.imread(file_path)
            if image is None:
                raise FileNotFoundError(f"Image file '{file_path}' not found.")
            # Convert the image to grayscale
            gray_image = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)
            # Apply GaussianBlur to reduce noise and improve OCR accuracy
            blurred_image = cv2.GaussianBlur(gray_image, (5, 5), 0)
            # Use adaptive thresholding to create a binary image
            binary_image = cv2.adaptiveThreshold(blurred_image, 255, 
                                                 cv2.ADAPTIVE_THRESH_GAUSSIAN_C, 
                                                 cv2.THRESH_BINARY, 11, 2)
            # Save the processed image for debugging purposes
            cv2.imwrite('processed_receipt.jpg', binary_image)
            # Extract text from the processed image using Tesseract OCR
            extracted_text = pytesseract.image_to_string(binary_image)
            # Extract data from the text
            receipt_data = self.extract_data(extracted_text)
            return receipt_data
        except Exception as e:
            print(f"Error scanning receipt: {e}")
            return {}