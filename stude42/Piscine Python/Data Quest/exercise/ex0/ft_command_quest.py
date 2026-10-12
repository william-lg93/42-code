import sys


def argument() -> None:
    argument = 0
    print(f"Program name: {sys.argv[0]}")
    if len(sys.argv) == 1:
        print("No arguments provided!")
    else:
        print(f"Arguments received: {len(sys.argv) - 1}")
        for i in sys.argv[1:]:
            argument += 1
            print("Argument {}: {}" .format(argument, i))
    print(f"Total argument: {len(sys.argv)}")


if __name__ == "__main__":
    print("=== Command Quest ===")
    argument()
