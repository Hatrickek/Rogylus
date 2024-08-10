#pragma once

#include <Core/Systems/System.hpp>

namespace rog {
class WeaponSystem : public ox::System {
  void on_init(ox::Scene* scene, entt::entity e) override;

  void on_fixed_update(float delta_time) override;
  void on_imgui_render(const ox::Timestep& delta_time) override;

  std::vector<std::string> _collisions = {};
};
} // namespace rog
