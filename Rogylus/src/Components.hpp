#pragma once

#include <Core/Types.hpp>

namespace rog {
struct CharacterComponent {
  float speed = 100.0f;
};

struct EnemyComponent {
  float speed = 50.0f;
  ox::int32 damage = 3;
};

struct WeaponComponent {
  enum class Type : ox::uint32 { Melee, Ranged };
  Type type = Type::Melee;
  ox::int32 damage = 5;
  ox::int32 radius = 50;
};
} // namespace rog
