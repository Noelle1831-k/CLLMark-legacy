import os
import json


def convert_py_folder_to_jsonl(input_folder, output_file, language,EXT):
    """
    Converts all Python files in a folder to a JSONL file.

    Args:
        input_folder (str): Path to the folder containing .py files.
        output_file (str): Path to the output .jsonl file.
        language (str): The programming language for the `language` field in the output.
    """
    with open(output_file, 'w', encoding='utf-8') as outfile:
        # Iterate through all files in the input folder
        for filename in os.listdir(input_folder):
            # Process only .py files
            if filename.endswith(f'.{EXT}'):
                file_path = os.path.join(input_folder, filename)

                # Read the content of the Python file
                with open(file_path, 'r', encoding='utf-8') as py_file:
                    code_content = py_file.read()

                # Create a JSON object for the file
                json_item = {
                    "task_id": os.path.splitext(filename)[0].replace('_','/'),  # Use filename without extension as task_id
                    "completion": code_content,
                    "language": language
                }

                # Write the JSON object as a JSON line
                outfile.write(json.dumps(json_item, ensure_ascii=False) + '\n')

    print(f"Conversion completed! JSONL file saved as {output_file}")



