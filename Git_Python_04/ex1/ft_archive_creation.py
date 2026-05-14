import sys
from typing import IO


def main() -> None:
    if len(sys.argv) != 2:
        print("Usage: ft_archive_creation.py <file>")
        return

    filename = sys.argv[1]

    print("=== Cyber Archives Recovery & Preservation ===")
    print(f"Accessing file '{filename}'")

    try:
        file: IO[str] = open(filename, "r")
        content = file.read()
        print("---")
        print()
        print(content)
        print()
        print("---")
        file.close()
        print(f"File '{filename}' closed.\n")
        new_content = ""
        for line in content.splitlines():
            new_content += line + "#\n"
        print("Transform data:")
        print("---")
        print()
        print(new_content)
        print("---")

        new_filename = input("Enter new file name (or empty): ")
        if new_filename == "":
            print("Not saving data.")
            return
        print(f"Saving data to '{new_filename}'")
        new_file: IO[str] = open(new_filename, "w")
        new_file.write(new_content)
        new_file.close()
        print(f"Data saved in file '{new_filename}'.\n")

    except Exception as error:
        print(f"Error opening file '{filename}': {error}")


if __name__ == "__main__":
    main()
