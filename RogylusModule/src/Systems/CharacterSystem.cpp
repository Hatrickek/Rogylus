#include "CharacterSystem.hpp"

#include "Assets.hpp"
#include "Components.hpp"

#include <Core/Input.hpp>
#include <Core/Keycodes.hpp>
#include <Physics/Physics.hpp>
#include <Scene/Components.hpp>
#include <Scene/Entity.hpp>
#include <Scene/Scene.hpp>
#include <Utils/Log.hpp>

#include <Jolt/Jolt.h>
#include <Jolt/Math/Vec3.h>
#include <Jolt/Physics/Body/Body.h>

namespace rog {
void CharacterSystem::on_init(ox::Scene* scene, entt::entity character_entity) {
  scene->registry.emplace<CharacterComponent>(character_entity);

  auto starter_weapon = scene->create_entity("starter_weapon");
  ox::eutil::set_parent(scene, starter_weapon, character_entity);
  scene->registry.emplace<WeaponComponent>(starter_weapon);
 
  const auto weapon_sprite = ox::AssetManager::get_texture_asset({.path = assets::starter_weapon});
  auto& sc = scene->registry.emplace<ox::SpriteComponent>(starter_weapon);
  sc.material->set_albedo_texture(weapon_sprite);

  auto& tc = scene->registry.emplace<ox::TransformComponent>(starter_weapon);
  tc.scale.x = weapon_sprite->get_extent().width;
  tc.scale.y = weapon_sprite->get_extent().height;
}

void CharacterSystem::on_fixed_update(float delta_time) {
  auto& body_interface = ox::Physics::get_body_interface();

  auto& cc = scene->registry.get<CharacterComponent>(entity);
  auto& rb = scene->registry.get<ox::RigidbodyComponent>(entity);
  auto& sc = scene->registry.get<ox::SpriteComponent>(entity);

  JPH::Vec3 velocity = JPH::Vec3::sZero();
  if (ox::Input::get_key_held(ox::KeyCode::A)) {
    velocity.SetX(-1.f);
    sc.flip_x = true;
  }
  if (ox::Input::get_key_held(ox::KeyCode::D)) {
    velocity.SetX(1.f);
    sc.flip_x = false;
  }
  if (ox::Input::get_key_held(ox::KeyCode::W)) {
    velocity.SetY(1.f);
  }
  if (ox::Input::get_key_held(ox::KeyCode::S)) {
    velocity.SetY(-1.f);
  }

  velocity = velocity.NormalizedOr(velocity);
  velocity *= cc.speed;

  body_interface.SetLinearVelocity(rb.get_body()->GetID(), velocity);
}
} // namespace rog
