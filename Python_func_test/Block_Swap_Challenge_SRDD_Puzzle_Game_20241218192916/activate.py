def activate(self, board, x, y):
        if self.type == "bomb":
            self._activate_bomb(board, x, y)
        elif self.type == "color_clear":
            self._activate_color_clear(board, x, y)
        elif self.type == "row_clear":
            self._activate_row_clear(board, x)
        elif self.type == "column_clear":
            self._activate_column_clear(board, y)