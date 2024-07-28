#pragma once

namespace rog {
struct CharacterComponent {
  float speed = 100.0f;
};

struct EnemyComponent {
  float speed = 50.0f;
  int damage = 3;
};
} // namespace rog
