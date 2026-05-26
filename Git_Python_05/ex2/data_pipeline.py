from abc import ABC, abstractmethod
from typing import Any, Protocol


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


class ExportPlugin(Protocol):
    def process_output(self, data: list[tuple[int, str]]) -> None: ...


class CSVExportPlugin:

    def process_output(self, data: list[tuple[int, str]]) -> None:

        values: list[str] = []

        for _, value in data:
            values.append(value)

        csv_output = ",".join(values)

        print("CSV Output:")
        print(csv_output)


class JSONExportPlugin:

    def process_output(self, data: list[tuple[int, str]]) -> None:

        json_parts: list[str] = []

        for rank, value in data:

            json_parts.append(f'"item_{rank}": "{value}"')

        json_output = "{"
        json_output += ", ".join(json_parts)
        json_output += "}"

        print("JSON Output:")
        print(json_output)


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
        print("\n== DataStream statistics ==")

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

    def output_pipeline(self, nb: int, plugin: ExportPlugin) -> None:

        for processor in self.processors:

            exported_data: list[tuple[int, str]] = []

            for _ in range(nb):

                if processor.remaining() == 0:
                    break

                exported_data.append(processor.output())

            if exported_data:
                plugin.process_output(exported_data)


def main() -> None:
    print("=== Code Nexus - Data Pipeline ===")

    stream = DataStream()

    print("\nInitialize Data Stream...")

    stream.print_processors_stats()

    print("\nRegistering Processors")

    numeric = NumericProcessor()
    text = TextProcessor()
    log = LogProcessor()

    stream.register_processor(numeric)
    stream.register_processor(text)
    stream.register_processor(log)

    batch1 = [
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

    print(f"\nSend first batch of data on stream: {batch1}")

    stream.process_stream(batch1)

    stream.print_processors_stats()

    csv_plugin = CSVExportPlugin()

    print("\nSend 3 processed data from each " "processor to a CSV plugin:")

    stream.output_pipeline(3, csv_plugin)

    stream.print_processors_stats()

    batch2 = [
        21,
        ["I love AI", "LLMs are wonderful", "Stay healthy"],
        [
            {"log_level": "ERROR",
             "log_message": "500 server crash"},
            {"log_level": "NOTICE",
             "log_message": "Certificate expires in 10 days"},
        ],
        [32, 42, 64, 84, 128, 168],
        "World hello",
    ]

    print(f"\nSend another batch of data: {batch2}")

    stream.process_stream(batch2)

    stream.print_processors_stats()

    json_plugin = JSONExportPlugin()

    print("\nSend 5 processed data from each " "processor to a JSON plugin:")

    stream.output_pipeline(5, json_plugin)

    stream.print_processors_stats()


if __name__ == "__main__":
    main()
