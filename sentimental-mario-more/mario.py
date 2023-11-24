# TODO
import cs50


def main():
    f = 0
    while f < 1 or f > 8:
        print("height must be 1 to 8")
        f = cs50.get_int("height of pyramid:")

    for i in range(f):
        for row in range(f - i - 1):
            print(" ", end="")
        for col in range(i + 1):
            print("#", end="")

        for row2 in range(1):
            print(" ", end=" ")
        for col2 in range(i + 1):
            print("#", end="")

        print("")


if __name__ == "__main__":
    main()
