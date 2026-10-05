def upload_footage(self, frame):
        temp_filename = 'temp_frame.jpg'
        try:
            save_frame_to_file(frame, temp_filename)
            self.s3.upload_file(temp_filename, 'bucket_name', 'remote_file.jpg')
        except FileNotFoundError:
            print("The file was not found")
        except NoCredentialsError:
            print("Credentials not available")
        except Exception as e:
            print(f"An error occurred: {e}")
        finally:
            if os.path.exists(temp_filename):
                os.remove(temp_filename)