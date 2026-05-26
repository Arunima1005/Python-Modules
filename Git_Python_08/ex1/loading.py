import importlib
import sys
from typing import Any


def install_instructions() -> None:
    """
    Print installation instructions for pip and Poetry.
    """
    print()
    print("Install dependencies using pip:")
    print("pip install -r requirements.txt")
    print()

    print("Install dependencies using Poetry:")
    print("poetry install")
    print()
    
def check_package(package_name: str, message: str) -> bool:
    """
    Check whether a package is installed and print its version.
    """
    try:
        module: Any = importlib.import_module(package_name)

        version = getattr(module, "__version__", "Unknown version")

        print(f"[OK] {package_name} ({version}) - {message}")

        return True

    except ImportError:
        print(f"[MISSING] {package_name}")
        return False

def analyze_data(data: list[int]) -> None:
    """
    Analyze and visualize Matrix data.
    """
    
    import matplotlib.pyplot as plt
    import pandas as pd
    print()
    print("Analyzing Matrix data...")
    print(f"Processing {len(data)} data points...")

    dataframe = pd.DataFrame(data, columns=["matrix_signal"])

    print()
    print("Data Summary:")
    print(dataframe.describe())

    print()
    print("Generating visualization...")

    plt.figure(figsize=(10, 5))
    plt.plot(dataframe["matrix_signal"])

    plt.title("Matrix Signal Analysis")
    plt.xlabel("Signal Index")
    plt.ylabel("Signal Strength")

    plt.savefig("matrix_analysis.png")

    print()
    print("Analysis complete!")
    print("Results saved to: matrix_analysis.png")


def main() -> None:
    """
    Main program entry point.
    """

    ALL_PACKAGES = {
    "numpy": ("required", "Numerical computation ready"),
    "pandas": ("required", "Data manipulation ready"),
    "matplotlib": ("required", "Visualization ready"),
    # "requests": ("optional", "Network access ready"),
    }
    print()
    print("LOADING STATUS: Loading programs...")
    print()
    print("Checking dependencies:")
    missing_required = False
    for package, (package_type, message) in ALL_PACKAGES.items():
        installed = check_package(package, message)

        if package_type == "required" and not installed:
            missing_required = True

    if missing_required:
        print()
        print("Some required dependencies are missing.")
        install_instructions()
        sys.exit(1)

    import numpy as np

    data = np.random.randint(0, 100, 1000)   

    analyze_data(data.tolist())


if __name__ == "__main__":
    main()


# pip install poetry

# poetry install

# poetry run python loading.py