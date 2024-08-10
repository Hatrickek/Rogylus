#include "Module.hpp"

#include <Scripting/LuaHelpers.hpp>
#include <entt/entt.hpp>
#include <imgui.h>
#include <sol/sol.hpp>

#include "Components.hpp"
#include "Systems/CharacterSystem.hpp"
#include "Systems/EnemySystem.hpp"
#include "Systems/GameManagerSystem.hpp"
#include "Systems/WeaponSystem.hpp"

namespace ox {
void RogylusModule::init(App* app_instance, ImGuiContext* imgui_context) {
  App::set_instance(app_instance);
  ImGui::SetCurrentContext(imgui_context);
}

void RogylusModule::register_components(sol::state* state, const entt::locator<entt::meta_ctx>::node_type& ctx) {
  entt::locator<entt::meta_ctx>::reset(ctx); // set local meta context

  // REGISTER_COMPONENT_CTOR(state, rog::CharacterComponent, CTOR(float), CFIELD(rog::CharacterComponent, speed));
}

void RogylusModule::unregister_components(sol::state* state, const entt::locator<entt::meta_ctx>::node_type& ctx) {
  // entt::meta_reset<rog::CharacterComponent>();
}

void RogylusModule::register_cpp_systems(SystemManager* system_manager) {
  system_manager->register_system<rog::CharacterSystem>();
  system_manager->register_system<rog::EnemySystem>();
  system_manager->register_system<rog::GameManagerSystem>();
  system_manager->register_system<rog::WeaponSystem>();
}

void RogylusModule::unregister_cpp_systems(SystemManager* system_manager) {
  system_manager->unregister_system<rog::CharacterSystem>();
  system_manager->unregister_system<rog::EnemySystem>();
  system_manager->unregister_system<rog::GameManagerSystem>();
  system_manager->unregister_system<rog::WeaponSystem>();
}
} // namespace ox
