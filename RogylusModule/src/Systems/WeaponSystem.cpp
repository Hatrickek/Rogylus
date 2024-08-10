#include "WeaponSystem.hpp"
#include "Components.hpp"

#include <Physics/Physics.hpp>
#include <Render/RendererConfig.hpp>
#include <Scene/Components.hpp>
#include <Scene/Entity.hpp>
#include <Scene/Scene.hpp>
#include <UI/OxUI.hpp>
#include <Utils/Log.hpp>

#include <Jolt/Jolt.h>
#include <Jolt/Math/Vec3.h>
#include <Jolt/Physics/Body/Body.h>
#include <Jolt/Physics/Collision/CastResult.h>
#include <Jolt/Physics/Collision/Shape/Shape.h>
#include <Jolt/Physics/Collision/Shape/SphereShape.h>
#include <Jolt/Physics/Collision/ShapeCast.h>
#include <imgui.h>

namespace rog {
void WeaponSystem::on_init(ox::Scene* scene, entt::entity e) {}

void WeaponSystem::on_fixed_update(float delta_time) {
  auto* system = ox::Physics::get_physics_system();

  auto w_view = scene->registry.view<ox::TransformComponent, ox::SpriteComponent, WeaponComponent>();
  for (const auto& [e, tc, sc, weapon] : w_view.each()) {
    // Create sphere
    const float radius = weapon.radius;
    const auto position = ox::float3(ox::eutil::get_world_transform(scene, e)[3]);
    JPH::Vec3 point(ox::math::to_jolt(position));

    // Collide sphere
    JPH::AllHitCollisionCollector<JPH::CollideShapeBodyCollector> collector;
    system->GetBroadPhaseQuery().CollideSphere(point, radius, collector);

    if (ox::RendererCVar::cvar_enable_physics_debug_renderer.get()) {
      auto debug_renderer = ox::Physics::get_debug_renderer();
      debug_renderer->DrawWireSphere(JPH::RVec3(point), radius, JPH::Color::sRed);
    }

    if (collector.HadHit()) {
      for (const auto& hit : collector.mHits) {
        JPH::BodyLockRead lock(system->GetBodyLockInterface(), hit);
        if (lock.Succeeded()) {
          const auto& hit_body = lock.GetBody();
          auto body_entity = (entt::entity)hit_body.GetUserData();

          if (scene->registry.all_of<CharacterComponent>(body_entity))
            continue;

          auto& tag = scene->registry.get<ox::TagComponent>(body_entity);
          _collisions.emplace_back(tag.tag);

          // auto& target_tc = scene->registry.get<ox::TransformComponent>(e);
          // auto look_at_mat = glm::lookAt(ox::float3(ox::eutil::get_world_transform(scene, e)[3]), target_tc.position, ox::float3(0, 1, 0));
          // sc.transform *= look_at_mat;
        }
      }
    }
  }
}

void WeaponSystem::on_imgui_render(const ox::Timestep& delta_time) {
  ImGui::SetNextWindowSize({150, 150}, ImGuiCond_Appearing);
  ox::ui::push_frame_style();
  if (ImGui::Begin("Debug")) {
    ImGui::SeparatorText("Weapon Collisions");
    for (auto& c : _collisions) {
      ImGui::Text(c.c_str());
    }
    ImGui::End();
  }
  ox::ui::pop_frame_style();

  _collisions.clear();
}
} // namespace rog
