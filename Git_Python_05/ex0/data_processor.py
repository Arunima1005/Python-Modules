from abc import ABC, abstractmethod
from typing import Any

class DataProcessor(ABC):
    def __init__(self) -> None:
        self._storage: list[str] = []
        self._counter: int = 0

    @abstractmethod
    def validate(self, data: Any) -> bool:
        pass

    @abstractmethod
    def ingest(self, data: Any) -> None:
        pass

    def output(self) -> tuple[int, str]:
        if not self._storage:
            raise ValueError("No data available")

        value = self._storage.pop(0)
        rank = self._counter
        self._counter += 1

        return (rank, value)

class NumericProcessor(DataProcessor):
    def validate(self, data: Any) -> bool:
        if isinstance(data, (int, float)):
            return True

        if isinstance(data, list):
            return all(isinstance(x, (int, float)) for x in data)

        return False
    
    def  ingest(self, data: int | float | list[int | float]) -> None:
        if not self.validate(data):
            raise ValueError("Improper numeric data")

        if isinstance(data, list):
            for item in data:
                self._storage.append(str(item))
        else:
            self._storage.append(str(data))

class TextProcessor(DataProcessor):
    def validate(self, data: Any) -> bool:
        if isinstance(data, str):
            return True

        if isinstance(data, list):
            return all(isinstance(x, str) for x in data)

        return False

    def ingest(self, data: str | list[str]) -> None:
        if not self.validate(data):
            raise ValueError("Improper text data")

        if isinstance(data, list):
            for item in data:
                self._storage.append(item)
        else:
            self._storage.append(data)

class LogProcessor(DataProcessor):
    def validate(self, data: Any) -> bool:

        def valid_log(log: Any) -> bool:
            if not isinstance(log, dict):
                return False

            return all(
                isinstance(k, str) and isinstance(v, str)
                for k, v in log.items()
            )

        if valid_log(data):
            return True

        if isinstance(data, list):
            return all(valid_log(item) for item in data)

        return False
    
    def ingest(
        self,
        data: dict[str, str] | list[dict[str, str]]
    ) -> None:

        if not self.validate(data):
            raise ValueError("Improper log data")

        def format_log(log: dict[str, str]) -> str:
            level = log.get("log_level", "UNKNOWN")
            message = log.get("log_message", "")
            return f"{level}: {message}"

        if isinstance(data, list):
            for item in data:
                self._storage.append(format_log(item))
        else:
            self._storage.append(format_log(data))

def main() -> None:

    print("=== Code Nexus - Data Processor ===")

    # ---------------- NUMERIC ----------------

    numeric = NumericProcessor()

    print("\nTesting Numeric Processor...")

    print(f"Trying to validate input '42': {numeric.validate(42)}")
    print(
        f"Trying to validate input 'Hello': "
        f"{numeric.validate('Hello')}"
    )

    print(
        "Test invalid ingestion of string "
        "'foo' without prior validation:"
    )

    try:
        numeric.ingest("foo")  # type: ignore
    except ValueError as e:
        print(f"Got exception: {e}")

    print("Processing data: [1, 2, 3, 4, 5]")

    numeric.ingest([1, 2, 3, 4, 5])

    print("Extracting 3 values...")

    for _ in range(3):
        rank, value = numeric.output()
        print(f"Numeric value {rank}: {value}")

    # ---------------- TEXT ----------------

    text = TextProcessor()

    print("\nTesting Text Processor...")

    print(f"Trying to validate input '42': {text.validate(42)}")

    print("Processing data: ['Hello', 'Nexus', 'World']")

    text.ingest(["Hello", "Nexus", "World"])

    print("Extracting 1 value...")

    rank, value = text.output()

    print(f"Text value {rank}: {value}")

     # ---------------- LOG ----------------

    log = LogProcessor()

    print("\nTesting Log Processor...")

    print(f"Trying to validate input 'Hello': {log.validate('Hello')}")

    logs = [
        {
            "log_level": "NOTICE",
            "log_message": "Connection to server"
        },
        {
            "log_level": "ERROR",
            "log_message": "Unauthorized access!!"
        }
    ]

    print(f"Processing data: {logs}")

    log.ingest(logs)

    print("Extracting 2 values...")

    for _ in range(2):
        rank, value = log.output()
        print(f"Log entry {rank}: {value}")


if __name__ == "__main__":
    main()