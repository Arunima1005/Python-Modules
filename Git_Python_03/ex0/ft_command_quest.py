import sys

if __name__ == "__main__":
    print("=== Command Quest ===")

    arg_len = len(sys.argv)

    print(f"Program name: {sys.argv[0]}")

    if arg_len == 1:
        print("No arguments provided!")
    else:
        print(f"Arguments received: {arg_len - 1}")
        for i in range(1, arg_len):
            print(f"Argument {i}: {str(sys.argv[i])}")
    print(f"Total arguments: {arg_len}")
