# TODO
def main():
    height = get_height()

    for i in range(1, height + 1):
        create_space(height - i)
        create_brick(i)
        create_space(2)
        create_brick(i)
        print()


def get_height():
    while True:
        try:
            n = int(input("Height: "))
            if n > 0 and n < 9:
                return n
            else:
                print("Provide valid integer (1 - 8)")
        except ValueError:
            print("Provide valid integer (1 - 8)")


def create_brick(n=1):
    print("#" * n, end="")


def create_space(n=1):
    print(" " * n, end="")


main()
