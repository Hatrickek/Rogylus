#pragma once

#include <Core/Systems/SystemManager.hpp>
#define OX_BUILD_DLL

#include <entt/locator/locator.hpp>

#include <Modules/Linker.hpp>
#include <Modules/ModuleInterface.hpp>

#include <sol/state.hpp>

namespace ox {
class OX_SHARED RogylusModule : public ModuleInterface {
public:
  ~RogylusModule() override = default;

  void init(App* app_instance, ImGuiContext* imgui_context) override;
  void register_components(sol::state* state, const entt::locator<entt::meta_ctx>::node_type& ctx) override;
  void unregister_components(sol::state* state, const entt::locator<entt::meta_ctx>::node_type& ctx) override;
  void register_cpp_systems(SystemManager* system_manager) override;
  void unregister_cpp_systems(SystemManager* system_manager) override;
};

CREATE_MODULE_FUNC { return new RogylusModule; }
} // namespace ox
