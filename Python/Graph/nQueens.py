#implementation of the N Queens Problem 
class n_Queens:
  def __init__(self, n):
    self.n = n
    self.chess_table = [[0 for i in range(n)] for j in range(n)]

  def print_queens(self):
    for i in range(self.n):
      for j in range(self.n):
        if self.chess_table[i][j] == 1:
          print(" Q ", end = '')
        else:
          print(" - ", end='')
      print("\n")

  def is_place_safe(self, row_index, col_index):
    for i in range(self.n):
      if self.chess_table[row_index][i] == 1:
        return False

    j = col_index
    for i in range(row_index, -1, -1):
      if i < 0:
        break
      if self.chess_table[i][j] == 1:
        return False
      j = j - 1

    j = col_index
    for i in range(row_index, self.n):
      if i < 0:
        break
      if self.chess_table[i][j] == 1:
        return False
      j = j - 1

    return True

  def solve(self, col_index):
    if col_index == self.n:
      return True

    for row_index in range(self.n):
      if self.is_place_safe(row_index, col_index):
        self.chess_table[row_index][col_index] = 1 
        if self.solve(col_index+1):
          return True
        self.chess_table[row_index][col_index] = 0

    return False

  def solve_n_Queens(self):
    if self.solve(0):
      self.print_queens()
    else:
      print("No solution exists for the problem")

queens = n_Queens(8)
queens.solve_n_Queens()