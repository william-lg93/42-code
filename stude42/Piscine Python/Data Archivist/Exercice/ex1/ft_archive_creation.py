import sys


def Archives_Recovery() -> str | None:
    if len(sys.argv) < 2:
        print(f"Usage : {sys.argv[0]} <file>")
        return None
    print("=== Cyber Archives Recovery & Preservation ===")
    print(f"Accessing file '{sys.argv[1]}'")
    try:
        file = open(sys.argv[1], "r")
    except OSError as one:
        print(f"Error opening file '{sys.argv[1]}': {one}")
        return None
    try:
        text = file.read()
    except (ValueError, OSError) as two:
        print(f"Error reading file '{sys.argv[1]}': {two}")
        return None
    finally:
        file.close()
    print("---\n")
    print(text)
    print("---")
    print(f"File {sys.argv[1]} closed.\n")
    return (text)


def change_txt(txt: str | None) -> str | None:
    if txt is None:
        return None
    final = ""
    sep: list[str] = []
    splt = txt.splitlines()
    for ligne in splt:
        sep.append(ligne + "#")
    for little in sep:
        final = final + little + "\n"
    print("Transform data:")
    print("---\n")
    print(final)
    print("---")
    return final


def new_file(txt: str | None) -> None:
    if txt is None:
        return
    name = input("Enter new file name (or empty): ")
    if not name:
        print("Not saving data.")
        return
    print(f"Saving data to {name}")
    try:
        new = open(name, "w")
    except OSError as e:
        print(f"error {e}")
        return
    try:
        new.write(txt)
    except OSError as err:
        print(f"error {err}")
        return
    finally:
        new.close()
    print(f"Data saved in file {name}.")


if __name__ == "__main__":
    text = Archives_Recovery()
    text2 = change_txt(text)
    new_file(text2)
