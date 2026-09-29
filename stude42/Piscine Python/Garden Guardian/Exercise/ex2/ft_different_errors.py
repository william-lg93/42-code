if __name__ == "__main__":
    print("=== Garden Error Types Demo ===")
    print("Testing operation 0...")
    try:
        int("abc")
    except ValueError as e:
        print(f"Cought ValueError: {e}")
    print("Testing operation 1...")
    try:
        a = 5 / 0
    except ZeroDivisionError as e:
        print(f"Cought ZeroDivisionError: {e}")
    print("Testing operation 2...")
    try:
        open("trie.txt", "r")
    except FileNotFoundError as e:
        print(f"Cought FileNotFoundError: {e}")
    print("Testing operation 3...")
    try:
        a = "bgreoighfio" + 56
    except TypeError as e:
        print(f"Cought TypeError: {e}")
    print("Testing operation 4...")
    try:
        print("Operation completed successfully")
    except Exception:
        print("Operation fail\n")
    print("\nAll error types tested successfully!")
