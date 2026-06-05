from pydantic import BaseModel, Field, model_validator, ValidationError
from datetime import datetime
from enum import Enum
from typing import Optional


class ContactType(str, Enum):
    radio = "radio"
    visual = "visual"
    physical = "physical"
    telepathic = "telepathic"


class AlienContact(BaseModel):
    contact_id: str = Field(min_length=5, max_length=15)
    timestamp: datetime
    location: str = Field(min_length=3, max_length=100)
    contact_type: ContactType
    signal_strength: float = Field(ge=0.0, le=10.0)
    duration_minutes: int = Field(ge=1, le=1440)
    witness_count: int = Field(ge=1, le=100)
    message_received: Optional[str] = Field(default=None, max_length=500)
    is_verified: bool = False

    @model_validator(mode="after")
    def validation_check(self):
        errors = []
        if not self.contact_id.startswith("AC"):
            errors.append("Contact ID must start with 'AC'")
        if self.contact_type == ContactType.physical and not self.is_verified:
            errors.append("Physical contact reports must be verified")
        if (self.contact_type == ContactType.telepathic
                and self.witness_count < 3):
            errors.append("Telepathic contact requires at least 3 witnesses")
        if self.signal_strength > 7.0 and not self.message_received:
            errors.append("Strong signals must include messages")

        if errors:
            raise ValueError("\n".join(errors))
        return self


def display_contact(contact: AlienContact) -> None:
    print("Alien Contact Log Validation")
    print("=" * 40)
    print("Valid contact report:")
    print(f"ID: {contact.contact_id}")
    print(f"Type: {contact.contact_type.value}")
    print(f"Location: {contact.location}")
    print(f"Signal: {contact.signal_strength}/10")
    print(f"Duration: {contact.duration_minutes} minutes")
    print(f"Witnesses: {contact.witness_count}")
    if contact.message_received:
        print(f"Message: '{contact.message_received}'")
    print()
    print("=" * 40)


def main() -> None:
    try:
        valid_contact = AlienContact(
            contact_id="AC_2024_001",
            timestamp=datetime.fromisoformat("2026-06-05 10:30:00"),
            location="Area 51, Nevada",
            contact_type=ContactType.radio,
            signal_strength=8.5,
            duration_minutes=45,
            witness_count=5,
            message_received="Greetings from Zeta Reticuli",
            is_verified=True,
        )
        display_contact(valid_contact)
    except ValidationError as error:
        print(error)
    print("Expected validation error:")
    try:
        invalid_contact = AlienContact(
            contact_id="AC_2024_002",
            timestamp=datetime.fromisoformat("2026-06-05 10:30:00"),
            location="Mars Base",
            contact_type=ContactType.telepathic,
            signal_strength=5.0,
            duration_minutes=20,
            witness_count=1,
            is_verified=False,
        )
        display_contact(invalid_contact)
    except ValidationError as error:
        # print(error.errors()[0]["msg"].split(',')[1])
        for err in error.errors():
            message = err["msg"]
            if message.startswith("Value error, "):
                message = message.replace("Value error, ", "")
            print(f"{message}")


if __name__ == "__main__":
    main()
