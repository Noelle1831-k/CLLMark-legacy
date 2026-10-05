def run_interface(self):
        while True:
            command = input("Enter command (add, remove, search, export, preview, execute, exit): ")
            if command == "add":
                content = input("Enter snippet content: ")
                tags = input("Enter tags (comma-separated): ").split(',')
                self.manager.add_snippet(content, tags)
            elif command == "remove":
                snippet_id = input("Enter snippet ID to remove: ")
                self.manager.remove_snippet(snippet_id)
            elif command == "search":
                query = input("Enter search query: ")
                results = self.manager.search_snippets(query)
                for snippet in results:
                    print(f"ID: {snippet.snippet_id}, Content: {snippet.content}, Tags: {snippet.tags}")
            elif command == "export":
                snippet_id = input("Enter snippet ID to export: ")
                format_type = input("Enter format type (text/file): ")
                result = self.manager.export_snippet(snippet_id, format_type)
                print(f"Exported: {result}")
            elif command == "preview":
                snippet_id = input("Enter snippet ID to preview: ")
                preview = self.manager.preview_snippet(snippet_id)
                print(preview)
            elif command == "execute":
                snippet_id = input("Enter snippet ID to execute: ")
                output = self.manager.execute_snippet(snippet_id)
                print(f"Execution Output: {output}")
            elif command == "exit":
                break
            else:
                print("Invalid command.")