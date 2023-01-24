# TODO
from cs50 import get_float


# main function
def main():
    cents = get_cents()

    # calculates total quarters
    quarters = calculate_quarters(cents)
    cents = cents - quarters * 25

    # calculate total dimes
    dimes = calculate_dimes(cents)
    cents = cents - dimes * 10

    # calculate total nickels
    nickels = calculate_nickels(cents)
    cents = cents - nickels * 5

    # calculate total pennies
    pennies = calculate_pennies(cents)
    cents = cents - pennies * 1

    # total amount of coins
    coins = quarters + dimes + nickels + pennies
    coins = int(coins)

    print(f"{coins}")


# get owed change
def get_cents():
    while True:
        cents = get_float("Change owed: ")
        cents = cents * 100
        if cents > 0:
            break
    return cents


# get quarters
def calculate_quarters(cents):
    quarters = 0
    while cents >= 25:
        quarters += 1
        cents -= 25

    return quarters


# get dimes
def calculate_dimes(cents):
    dimes = 0
    while cents >= 10:
        dimes += 1
        cents -= 10

    return dimes


# get nickels
def calculate_nickels(cents):
    nickels = 0
    while cents >= 5:
        nickels += 1
        cents -= 5
    return nickels


# get pennies
def calculate_pennies(cents):
    pennies = 0
    while cents >= 1:
        pennies += 1
        cents -= 1

    return pennies


main()