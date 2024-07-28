#include "EnemySystem.hpp"
#include <Scene/Components.hpp>
#include "Components.hpp"

namespace rog {
entt::entity get_character(ox::Scene* scene) {
  entt::entity e = entt::null;
  auto ch_view = scene->registry.view<ox::TransformComponent, CharacterComponent>();
  for (auto ch_e : ch_view) {
    e = ch_e;
    break;
  }

  return e;
}

void EnemySystem::on_init(ox::Scene* scene, entt::entity e) {}

void EnemySystem::on_update(const ox::Timestep& delta_time) {
  // TODO: maybe call in fixed_update

  if (_character == entt::null) {
    _character = get_character(scene);
  }
  const auto& character_tc = scene->registry.get<ox::TransformComponent>(_character);

  auto e_view = scene->registry.view<ox::TransformComponent, EnemyComponent>();
  for (const auto& [e, tc, enemy] : e_view.each()) {
    auto direction = glm::normalize(ox::float2(character_tc.position) - ox::float2(tc.position));
    tc.position.x += direction.x * delta_time.get_seconds() * enemy.speed;
    tc.position.y += direction.y * delta_time.get_seconds() * enemy.speed;
  }
}
} // namespace rog
