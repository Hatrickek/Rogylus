#pragma once

#include <Core/Systems/System.hpp>

namespace rog {
class GameManagerSystem : public ox::System {
  void on_init(ox::Scene* scene, entt::entity e) override;
  void on_update(const ox::Timestep& delta_time) override;

private:
  bool _spawned_enemies = false;
};
} // namespace rog
