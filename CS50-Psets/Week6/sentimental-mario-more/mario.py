# TODO
while True:
    # get user input
    try:
        height = int(input("Height: "))
        # limit height
        if height >= 1 and height <= 8:
            # for loop for row
            for i in range(height):
                # for loop for column
                for j in range(height):
                    if i + j < height - 1:
                        print(" ", end="")
                    else:
                        print("#", end="")
                print("  ", end="")

                # left alligned pyramid
                for k in range(i + 1):
                    print("#", end="")
                print("")
            break
    except ValueError:
        print("That's not an interger")