#include "GameManagerSystem.hpp"
#include "Assets.hpp"
#include "Components.hpp"

#include <Assets/AssetManager.hpp>
#include <Core/App.hpp>
#include <Scene/Components.hpp>
#include <Scene/Scene.hpp>

namespace rog {
void create_enemies(ox::Scene* scene) {
  auto enemy = scene->create_entity("enemy");

  scene->registry.emplace<EnemyComponent>(enemy);

  const auto enemy_sprite = ox::AssetManager::get_texture_asset({.path = assets::enemy_sprite});

  auto& enemy_tc = scene->registry.get<ox::TransformComponent>(enemy);
  enemy_tc.position.x = 48.f;
  enemy_tc.position.y = 32.f;
  enemy_tc.position.z = 1.f;

  enemy_tc.scale.x = enemy_sprite->get_extent().width;
  enemy_tc.scale.y = enemy_sprite->get_extent().height;

  auto& sc = scene->registry.emplace<ox::SpriteComponent>(enemy);
  sc.material->set_albedo_texture(enemy_sprite);

  auto& bc = scene->registry.emplace_or_replace<ox::BoxColliderComponent>(enemy);
  bc.size = {enemy_sprite->get_extent().width / 2.f, enemy_sprite->get_extent().height / 2.f, 0.5f};

  auto& rb = scene->registry.emplace_or_replace<ox::RigidbodyComponent>(enemy);
  rb.type = ox::RigidbodyComponent::BodyType::Kinematic;
  rb.allowed_dofs = ox::RigidbodyComponent::AllowedDOFs::Plane2D;

  auto& tc = scene->registry.get<ox::TransformComponent>(enemy);
  scene->create_rigidbody(enemy, tc, rb);
}

void GameManagerSystem::on_init(ox::Scene* scene, entt::entity e) {}

void GameManagerSystem::on_update(const ox::Timestep& delta_time) {
  if (!_spawned_enemies) {
    create_enemies(scene);

    _spawned_enemies = true;
  }
}
} // namespace rog
