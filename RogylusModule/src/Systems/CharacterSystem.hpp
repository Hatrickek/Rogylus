#pragma once

#include <Core/Input.hpp>
#include <Core/Keycodes.hpp>
#include <Core/Systems/System.hpp>
#include <Scene/Scene.hpp>
#include <Utils/Log.hpp>

#include <imgui.h>

#include "Components.hpp"

namespace rog {
class CharacterSystem : public ox::System {
  void on_init(ox::Scene* scene, entt::entity e) override {}

  void on_update(const ox::Timestep& delta_time) override {
    auto& tc = scene->registry.get<ox::TransformComponent>(entity);
    auto& cc = scene->registry.get_or_emplace<CharacterComponent>(entity);

    if (ox::Input::get_key_held(ox::KeyCode::A)) {
      tc.position.x -= cc.speed * delta_time.get_seconds();
    }
    if (ox::Input::get_key_held(ox::KeyCode::D)) {
      tc.position.x += cc.speed * delta_time.get_seconds();
    }
    if (ox::Input::get_key_held(ox::KeyCode::W)) {
      tc.position.y += cc.speed * delta_time.get_seconds();
    }
    if (ox::Input::get_key_held(ox::KeyCode::S)) {
      tc.position.y -= cc.speed * delta_time.get_seconds();
    }
  }
};
} // namespace rog
