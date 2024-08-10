#pragma once

#include <Core/Systems/System.hpp>

namespace rog {
class CharacterSystem : public ox::System {
  void on_init(ox::Scene* scene, entt::entity e) override;

  void on_fixed_update(float delta_time) override;
};
} // namespace rog
