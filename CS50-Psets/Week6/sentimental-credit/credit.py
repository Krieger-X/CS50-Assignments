from cs50 import get_int
from sys import exit

# get user's card number
while True:
    n = get_int("Number: ")
    if n > 0:
        break

card_type = ""
# check first two digits and the length of the card number
first_digit = int(str(n)[:1])
first_two = int(str(n)[:2])
length = len(str(n))
if (first_two == 34 or first_two == 37) and (length == 15):
    card_type = "AMEX"
elif (first_two >= 51 and first_two <= 55) and (length == 16):
    card_type = "MASTERCARD"
elif (first_digit == 4) and (length == 13 or length == 16):
    card_type = "VISA"
else:
    print("INVALID")
    exit(1)
# checksum by applying Luhn's algorithm
dgt = 0
checksum = 0
even_digits = 0
odd_digits = 0
n = str(n)
n = str(n[::-1])
for i in n:
    # check even digits and get sum
    if dgt % 2 == 0:
        even_digits += int(i)
    else:
        # check odd digits and get sum
        if int(i) > 4:
            odd_digits += (int(i) * 2) - 9
        else:
            odd_digits += (int(i) * 2)
    dgt += 1
# add the products of even, odd digits
checksum = even_digits + odd_digits
checksum %= 10
if checksum == 0:
    print(card_type)
else:
    print("INVALID")
