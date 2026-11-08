import sys


def Archives_Recovery() -> None:
    if len(sys.argv) < 2:
        print(f"Usage : {sys.argv[0]} <file>")
        return
    print("=== Cyber Archives Recovery ===")
    print(f"Accessing file '{sys.argv[1]}'")
    try:
        file = open(sys.argv[1], "r")
    except OSError as one:
        print(f"Error opening file '{sys.argv[1]}': {one}")
        return
    try:
        text = file.read()
    except (ValueError, OSError) as two:
        print(f"Error reading file '{sys.argv[1]}': {two}")
        return
    finally:
        file.close()
    print("---\n")
    print(text)
    print("---")
    print(f"File {sys.argv[1]} closed.")


if __name__ == "__main__":
    Archives_Recovery()
