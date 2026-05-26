from abc import ABC, abstractmethod
from typing import Any


class DataProcessor(ABC):
    def __init__(self) -> None:
        self._storage: list[str] = []
        self._counter: int = 0
        self.total_processed: int = 0

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

    def remaining(self) -> int:
        return len(self._storage)


class NumericProcessor(DataProcessor):
    def validate(self, data: Any) -> bool:
        if isinstance(data, (int, float)):
            return True

        if isinstance(data, list):
            return all(isinstance(x, (int, float)) for x in data)

        return False

    def ingest(self, data: int | float | list[int | float]) -> None:
        if not self.validate(data):
            raise ValueError("Improper numeric data")

        if isinstance(data, list):
            for item in data:
                self._storage.append(str(item))
                self.total_processed += 1
        else:
            self._storage.append(str(data))
            self.total_processed += 1


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
                self.total_processed += 1
        else:
            self._storage.append(data)
            self.total_processed += 1


class LogProcessor(DataProcessor):
    def validate(self, data: Any) -> bool:

        def valid_log(log: Any) -> bool:
            if not isinstance(log, dict):
                return False

            required_keys = {"log_level", "log_message"}

            if set(log.keys()) != required_keys:
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

    def ingest(self, data: dict[str, str] | list[dict[str, str]]) -> None:

        if not self.validate(data):
            raise ValueError("Improper log data")

        def format_log(log: dict[str, str]) -> str:
            level = log["log_level"]
            message = log["log_message"]
            return f"{level}: {message}"

        if isinstance(data, list):
            for item in data:
                self._storage.append(format_log(item))
                self.total_processed += 1
        else:
            self._storage.append(format_log(data))
            self.total_processed += 1


class DataStream:
    def __init__(self) -> None:
        self.processors: list[DataProcessor] = []

    def register_processor(self, proc: DataProcessor) -> None:
        self.processors.append(proc)

    def process_stream(self, stream: list[Any]) -> None:

        for element in stream:
            processed: bool = False

            for processor in self.processors:
                if processor.validate(element):
                    processor.ingest(element)
                    processed = True
                    break

            if not processed:
                print(
                    "DataStream error - "
                    f"Can't process element in stream: {element}"
                )

    def print_processors_stats(self) -> None:
        print("== DataStream statistics ==")

        if not self.processors:
            print("No processor found, no data")
            return

        for processor in self.processors:

            processor_name = processor.__class__.__name__

            print(
                f"{processor_name}: "
                f"total {processor.total_processed} "
                f"items processed, "
                f"remaining {processor.remaining()} "
                f"on processor"
            )


def main() -> None:

    print("=== Code Nexus - Data Stream ===")

    stream = DataStream()

    print("\nInitialize Data Stream...")

    stream.print_processors_stats()

    print("\nRegistering Numeric Processor")

    numeric = NumericProcessor()

    stream.register_processor(numeric)

    batch = [
        "Hello world",
        [3.14, -1, 2.71],
        [
            {"log_level": "WARNING",
             "log_message": "Telnet access! Use ssh instead"},
            {"log_level": "INFO",
             "log_message": "User wil is connected"},
        ],
        42,
        ["Hi", "five"],
    ]

    print(f"Send first batch of data on stream: {batch}")

    stream.process_stream(batch)

    stream.print_processors_stats()

    print("\nRegistering other data processors")

    text = TextProcessor()
    log = LogProcessor()

    stream.register_processor(text)
    stream.register_processor(log)

    print("Send the same batch again")

    stream.process_stream(batch)

    stream.print_processors_stats()

    print(
        "\nConsume some elements from the "
        "data processors: Numeric 3, Text 2, Log 1"
    )

    for _ in range(3):
        numeric.output()

    for _ in range(2):
        text.output()

    for _ in range(1):
        log.output()

    stream.print_processors_stats()


if __name__ == "__main__":
    main()
