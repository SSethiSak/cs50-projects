# TODO
import cs50


def main():
    id = cs50.get_int("number:")
    copy = id
    n = 0
    count = 0
    while copy >= 1:
        copy = copy / 10
        n = n + 1

    for x in range (2, 17, 2):
        card1 = int((id % (10**x)/ 10**(x-1)))*2
        card1 = int((card1 % 100)/10 + (card1 % 10))

        card2 = int((id % (10**(x-1)))/ 10**(x-2))

        count = count + card1 + card2

    if count % 10 != 0:
        print("INVALID\n")
        return 0;

    visa = id
    while visa >= 10:
        visa = int(visa) / 10

    if int(visa) == 4 and (n == 13 or n == 16):
        print("VISA\n")
        return 0;

    MasAme = id;
    while (MasAme >= 100):
        MasAme = int(MasAme) / 10
    MasAme = int(MasAme)
    if (MasAme == 34 or MasAme == 37) and n==15:
        print("AMEX\n")
        return 0;

    if (MasAme == 51 or MasAme == 52 or MasAme == 53 or MasAme == 54 or MasAme == 55) and n == 16:
        print("MASTERCARD\n")
        return 0;
    print("INVALID\n")
    return 0;


if __name__ == "__main__":
    main()