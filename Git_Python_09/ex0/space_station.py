from datetime import datetime
from typing import Optional
from pydantic import BaseModel, Field, ValidationError


class SpaceStation(BaseModel):
    station_id: str = Field(min_length=3, max_length=10)
    name: str = Field(min_length=1, max_length=50)
    crew_size: int = Field(ge=1, le=20)
    power_level: float = Field(ge=0.0, le=100.0)
    oxygen_level: float = Field(ge=0.0, le=100.0)
    last_maintenance: datetime
    is_operational: bool = True
    notes: Optional[str] = Field(default=None, max_length=200)


def display_station(station: SpaceStation) -> None:
    print("Space Station Data Validation")
    print("=" * 40)
    print("Valid station created:")
    print(f"ID: {station.station_id}")
    print(f"Name: {station.name}")
    print(f"Crew: {station.crew_size} people")
    print(f"Power: {station.power_level}%")
    print(f"Oxygen: {station.oxygen_level}%")
    status = "Operational" if station.is_operational else "Not Operational"
    print(f"Status: {status}")
    if station.notes:
        print(f"Notes: {station.notes}")
    print()
    print("=" * 40)


def main() -> None:
    try:
        station = SpaceStation(
            station_id="ISS001",
            name="International Space Station",
            crew_size=6,
            power_level=85.5,
            oxygen_level=92.3,
            last_maintenance=datetime.fromisoformat("2026-06-05"),
            # notes="Main orbital research station"
        )
        display_station(station)

    except ValidationError as error:
        print(error)

    print("Expected validation error:")

    try:
        invalid_station = SpaceStation(
            station_id="BAD001",
            name="Broken Station",
            crew_size=25,
            power_level=72.0,
            oxygen_level=50.0,
            last_maintenance=datetime.fromisoformat("2026-06-05"),
        )

        display_station(invalid_station)

    except ValidationError as error:
        for err in error.errors():
            # print(err["msg"])
            field_name = err["loc"][0]
            print(f"{field_name}: {err['msg']}")


if __name__ == "__main__":
    main()
