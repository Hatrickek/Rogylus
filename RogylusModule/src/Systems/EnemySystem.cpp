#include "EnemySystem.hpp"
#include "Components.hpp"

#include <Physics/Physics.hpp>
#include <Scene/Components.hpp>

#include <Jolt/Jolt.h>
#include <Jolt/Math/Vec3.h>
#include <Jolt/Physics/Body/Body.h>
#include <Utils/OxMath.hpp>

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

void EnemySystem::on_fixed_update(float delta_time) {
  if (_character == entt::null) {
    _character = get_character(scene);
    return;
  }

  auto& body_interface = ox::Physics::get_body_interface();
  const auto& character_tc = scene->registry.get<ox::TransformComponent>(_character);

  auto e_view = scene->registry.view<ox::TransformComponent, ox::RigidbodyComponent, EnemyComponent>();
  for (const auto& [e, tc, rb, enemy] : e_view.each()) {
    auto direction = ox::math::to_jolt(ox::float3(glm::normalize(ox::float2(character_tc.position) - ox::float2(tc.position)), 0.0f));

    direction *= enemy.speed;

    body_interface.SetLinearVelocity(rb.get_body()->GetID(), direction);
  }
}
} // namespace rog
