def setup_ui(self):
        self.canvas.bind('<Button-1>', self.on_canvas_click)
        for icon in self.icons:
            button = tk.Button(self.root, text=icon.type, command=lambda i=icon: self.select_tile(i.type))
            button.pack(side=tk.LEFT)