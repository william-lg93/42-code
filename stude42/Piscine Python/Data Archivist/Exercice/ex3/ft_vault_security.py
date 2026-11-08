def secure_archive(name: str,
                   action: int = 1,
                   new_ft: str | None = None
                   ) -> tuple[bool, str]:
    if action == 1:
        try:
            with open(name, "r") as file:
                new_ft = file.read()
        except (ValueError, OSError) as one:
            return (False, f"{one}")
        return (True, new_ft)
    elif action == 2:
        if new_ft is None:
            return (False, "File can't create")
        else:
            try:
                with open(name, "w") as new:
                    new.write(new_ft)
            except (ValueError, OSError) as two:
                return (False, f"{two}")
        return (True, "Content successfully written to file")
    else:
        return (False, "choose 1 or 2")


if __name__ == "__main__":
    print("=== Cyber Archives Security ===\n")

    print("Using 'secure_archive' to read from a nonexistent file:")
    print(secure_archive("/not/existing/file"))
    print()

    print("Using 'secure_archive' to read from an inaccessible file:")
    print(secure_archive("interdit.txt"))
    print()

    print("Using 'secure_archive' to read from an inaccessible file:")
    print(secure_archive("test.txt"))
    print()

    print("Using 'secure_archive' to read from an inaccessible file:")
    print(secure_archive("test.txt", 2, "new_files"))
    print()
