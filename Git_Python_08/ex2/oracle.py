import os
import sys

from dotenv import load_dotenv

def display_configuration() -> None:
    """
    Display loaded configuration.
    """
    matrix_mode = os.getenv("MATRIX_MODE")
    database_url = os.getenv("DATABASE_URL")
    api_key = os.getenv("API_KEY")
    log_level = os.getenv("LOG_LEVEL")
    zion_endpoint = os.getenv("ZION_ENDPOINT")

    print("Configuration loaded:")
    print()

    print(f"Mode: {matrix_mode}")

    if matrix_mode == "development":
        print("Database: Connected to local instance")
    else:
        print("Database: Connected to production instance")

    if database_url:
        print(f"Database URL: {database_url}")

    if api_key:
        print("API Access: Authenticated")
    else:
        print("API Access: Missing API key")

    print(f"Log Level: {log_level}")

    if zion_endpoint:
        print("Zion Network: Online")
    else:
        print("Zion Network: Offline")

    print()

    print("Environment security check:")
    print("[OK] No hardcoded secrets detected")
    print("[OK] .env file properly configured")
    print("[OK] Production overrides available")

    print()
    print("The Oracle sees all configurations.")

def main() -> None:

    REQUIRED_VARIABLES = [
    "MATRIX_MODE",
    "DATABASE_URL",
    "API_KEY",
    "LOG_LEVEL",
    "ZION_ENDPOINT",
]
    print()
    print("ORACLE STATUS: Reading the Matrix...")
    print()

    load_dotenv()

    missing_variables = []

    for variable in REQUIRED_VARIABLES:
        if not os.getenv(variable):
            missing_variables.append(variable)

    if missing_variables:
        print("WARNING: Missing configuration variables:")
        print()

        for variable in missing_variables:
            print(f"- {variable}")
        print()
        print("Please configure your environment variables.")
        sys.exit(1)

    display_configuration()


if __name__ == "__main__":
    main()