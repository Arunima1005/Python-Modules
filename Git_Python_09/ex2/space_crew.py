from pydantic import BaseModel, Field, ValidationError, model_validator
from enum import Enum
from datetime import datetime


class Rank(str, Enum):
    cadet = "cadet"
    officer = "officer"
    lieutenant = "lieutenant"
    captain = "captain"
    commander = "commander"


class CrewMember(BaseModel):
    member_id: str = Field(min_length=3, max_length=10)
    name: str = Field(min_length=2, max_length=50)
    rank: Rank
    age: int = Field(ge=18, le=80)
    specialization: str = Field(min_length=3, max_length=30)
    years_experience: int = Field(ge=0, le=50)
    is_active: bool = True


class SpaceMission(BaseModel):
    mission_id: str = Field(min_length=5, max_length=15)
    mission_name: str = Field(min_length=3, max_length=100)
    destination: str = Field(min_length=3, max_length=50)
    launch_date: datetime
    duration_days: int = Field(ge=1, le=3650)
    crew: list[CrewMember] = Field(min_length=1, max_length=12)
    mission_status: str = "planned"
    budget_millions: float = Field(ge=1.0, le=10000.0)

    @model_validator(mode="after")
    def validation_check(self) -> "SpaceMission":
        errors = []
        if not self.mission_id.startswith("M"):
            errors.append("Mission ID must start with 'M'")

        captain_commander = any(
            crew_member.rank in (Rank.captain, Rank.commander)
            for crew_member in self.crew
        )

        if not captain_commander:
            errors.append(
                "Mission must have at least one Commander or Captain"
                )

        if self.duration_days > 365:
            experienced_crew = [
                crew_member
                for crew_member in self.crew
                if crew_member.years_experience >= 5
            ]
            if len(experienced_crew) < len(self.crew) / 2:
                errors.append("Long missions need 50% experienced crew")

        for member in self.crew:
            if not member.is_active:
                errors.append("All crew members must be active")
                break

        if errors:
            raise ValueError("\n".join(errors))

        return self


def display_mission(mission: SpaceMission) -> None:

    print("Space Mission Crew Validation")
    print("=" * 45)
    print("Valid mission created:")
    print(f"Mission: {mission.mission_name}")
    print(f"ID: {mission.mission_id}")
    print(f"Destination: {mission.destination}")
    print(f"Duration: {mission.duration_days} days")
    print(f"Budget: ${mission.budget_millions}M")
    print(f"Crew size: {len(mission.crew)}")
    print("Crew members:")
    for member in mission.crew:

        print(
            f"- {member.name} "
            f"({member.rank.value}) - "
            f"{member.specialization}"
        )

    print("=" * 45)


def main() -> None:

    try:

        valid_mission = SpaceMission(
            mission_id="M2026_MARS",
            mission_name="Mars Colony Establishment",
            destination="Mars",
            launch_date=datetime.fromisoformat("2026-06-05"),
            duration_days=900,
            budget_millions=2500.0,
            crew=[
                CrewMember(
                    member_id="CM001",
                    name="Sarah Connor",
                    rank=Rank.commander,
                    age=45,
                    specialization="Mission Command",
                    years_experience=15,
                ),
                CrewMember(
                    member_id="CM002",
                    name="John Smith",
                    rank=Rank.lieutenant,
                    age=38,
                    specialization="Navigation",
                    years_experience=8,
                ),
                CrewMember(
                    member_id="CM003",
                    name="Alice Johnson",
                    rank=Rank.officer,
                    age=32,
                    specialization="Engineering",
                    years_experience=6,
                ),
            ],
        )

        display_mission(valid_mission)

    except ValidationError as error:
        print(error)

    print("\nExpected validation error:")

    try:

        invalid_mission = SpaceMission(
            mission_id="MX2026",
            mission_name="Deep Space Probe",
            destination="Jupiter",
            launch_date=datetime.fromisoformat("2026-06-05"),
            duration_days=1000,
            budget_millions=5000.0,
            crew=[
                CrewMember(
                    member_id="CM101",
                    name="Bob",
                    rank=Rank.officer,
                    age=30,
                    specialization="Engineering",
                    years_experience=2,
                    # is_active=True,
                ),
                CrewMember(
                    member_id="CM102",
                    name="Emma",
                    rank=Rank.lieutenant,
                    age=29,
                    specialization="Science",
                    years_experience=6,
                ),
            ],
        )

        display_mission(invalid_mission)

    except ValidationError as error:

        for err in error.errors():
            message = err["msg"]
            if message.startswith("Value error, "):
                message = message.replace("Value error, ", "")
            print(f"{message}")


if __name__ == "__main__":
    main()
