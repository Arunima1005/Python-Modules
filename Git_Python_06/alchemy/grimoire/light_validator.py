from .light_spellbook import light_spell_allowed_ingredients


def validate_ingredients(ingredients: str) -> str:
    allowed: list[str] = light_spell_allowed_ingredients()

    ingredients_lower: str = ingredients.lower()

    is_valid: bool = any(ingredient in ingredients_lower
                         for ingredient in allowed)

    status: str = "VALID" if is_valid else "INVALID"

    return f"{ingredients} - {status}"
