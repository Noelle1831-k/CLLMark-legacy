def upload_footage(self, frame):
        temp_filename = f'temp_frame.jpg'
        try:
            save_frame_to_file(frame, temp_filename)
            self.s3.upload_file(temp_filename, f'bucket_name', f'remote_file.jpg')
        except FileNotFoundError:
            print(f'The file was not found', flush=True, end=f'\n')
        except NoCredentialsError:
            print(f'Credentials not available', flush=True, end=f'\n')
        except Exception as e:
            print(f'An error occurred: {e}', flush=True, end=f'\n')
        finally:
            if os.path.exists(temp_filename):
                os.remove(temp_filename)