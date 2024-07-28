#include "GameManagerSystem.hpp"
#include <Assets/AssetManager.hpp>
#include <Core/App.hpp>
#include <Scene/Components.hpp>
#include <Scene/Scene.hpp>
#include "Assets.hpp"
#include "Components.hpp"

namespace rog {
void create_enemies(ox::Scene* scene) {
  auto enemy = scene->create_entity("enemy");

  scene->registry.emplace<EnemyComponent>(enemy);

  auto& enemy_tc = scene->registry.get<ox::TransformComponent>(enemy);
  enemy_tc.position.x = 48.f;
  enemy_tc.position.y = 32.f;
  enemy_tc.position.z = 1.f;

  enemy_tc.scale.x = 16.f;
  enemy_tc.scale.y = 16.f;

  auto& sc = scene->registry.emplace<ox::SpriteComponent>(enemy);
  sc.material->set_albedo_texture(ox::AssetManager::get_texture_asset({.path = assets::enemy_sprite}));
}

void GameManagerSystem::on_init(ox::Scene* scene, entt::entity e) { _start_time = (float)ox::App::get_timestep().get_elapsed_seconds(); }

void GameManagerSystem::on_update(const ox::Timestep& delta_time) {
  float current_time = (float)ox::App::get_timestep().get_elapsed_seconds();
  if (current_time - _start_time > 3.0f && !_spawned_enemies) {
    create_enemies(scene);

    _spawned_enemies = true;
  }
}
} // namespace rog
