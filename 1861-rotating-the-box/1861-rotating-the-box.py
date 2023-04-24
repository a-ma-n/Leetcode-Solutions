class Solution:
    def rotateTheBox(self, box: List[List[str]]) -> List[List[str]]:
        for row in box:
            move_position = len(row) - 1             # initialize with the last position in row
            for j in range(len(row) - 1, -1, -1):    # iterate from the end of the row
                if row[j] == "*":                    # we cannot move stones behind obstacles,
                    move_position = j - 1            # so update move position to the first before obstacle
                elif row[j] == "#":                  # if stone, move it to the "move_position"
                    row[move_position], row[j] = row[j], row[move_position]
                    move_position -= 1

        return zip(*box[::-1])                       # rotate array