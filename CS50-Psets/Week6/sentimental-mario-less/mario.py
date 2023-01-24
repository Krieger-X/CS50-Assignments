# TODO
from cs50 import get_int

while True:
    # getting user input
    height = get_int("Height:")
    # limit the height
    if height > 0 and height < 9:
        for i in range(height):
            for j in range(height):

                # print column
                if (i + j < height - 1):
                    print(" ", end="")
                else:
                    print("#", end="")
            print("")
        # if successful break out of the loop
        break