#include "Module.h"

#include <entt/entt.hpp>
#include <sol/sol.hpp>
#include <Scripting/LuaHelpers.h>

#include "Components.h"

namespace ox {
void RogylusModule::register_components(sol::state* state, const entt::locator<entt::meta_ctx>::node_type& ctx) {
  entt::locator<entt::meta_ctx>::reset(ctx); // set local meta context
}

void RogylusModule::unregister_components(sol::state* state, const entt::locator<entt::meta_ctx>::node_type& ctx) {
}
}