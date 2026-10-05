def delete_shared_file(self, receiver, file_name):
        if receiver.name in self.shared_files:
            self.shared_files[receiver.name] = [
                file for file in self.shared_files[receiver.name] if file[1] != file_name
            ]