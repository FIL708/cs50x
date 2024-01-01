from re import match


# TODO
def main():
    str_num = get_input()

    if not luhn_check(str_num):
        return print("INVALID\n")

    print_results(str_num)


def get_input():
    pattern = r"^\d{10,}$"

    while True:
        number = input("Number: ")

        if match(pattern, number):
            return number
        else:
            print("Invalid card number!")


def luhn_check(string):
    sum = 0
    reverse = string[::-1]

    for i in range(len(reverse)):
        if i % 2 != 0:
            num = int(reverse[i]) * 2

            for char in str(num):
                sum += int(char)

        else:
            sum += int(reverse[i])

    return sum % 10 == 0


def print_results(string):
    if len(string) == 15 and string[:2] in ["34", "37"]:
        print("AMEX")

    elif len(string) == 16 and 51 <= int(string[:2]) <= 55:
        print("MASTERCARD")

    elif len(string) in [13, 16] and string[:1] == "4":
        print("VISA")

    else:
        print("INVALID")


main()
