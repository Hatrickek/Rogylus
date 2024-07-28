#pragma once

#include <Core/Systems/System.hpp>
#include <Scene/Scene.hpp>
#include <Utils/Log.hpp>

#include <entt/entity/entity.hpp>
#include <imgui.h>

namespace rog {
class EnemySystem : public ox::System {
  void on_init(ox::Scene* scene, entt::entity e) override;

  void on_update(const ox::Timestep& delta_time) override;

  entt::entity _character = entt::null;
};
} // namespace rog
