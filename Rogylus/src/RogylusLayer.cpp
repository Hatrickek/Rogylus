#include "RogylusLayer.hpp"

#include <Assets/AssetManager.hpp>
#include <Scene/SceneSerializer.hpp>
#include <Core/App.hpp>
#include <Core/Systems/SystemManager.hpp>
#include <Modules/ModuleUtil.hpp>
#include <Scene/Components.hpp>
#include "Assets.hpp"
#include "Components.hpp"

#include "Systems/GameManagerSystem.hpp"

namespace rog {
RogylusLayer* RogylusLayer::_instance = nullptr;

RogylusLayer::RogylusLayer() : Layer("Game Layer") { _instance = this; }

void RogylusLayer::on_attach(ox::EventDispatcher& dispatcher) {
  ox::ModuleUtil::load_module("RogylusModule", "RogylusModule");

  load_scene();

  // load assets
  ox::AssetManager::get_texture_asset({.path = assets::character_sprite});
  ox::AssetManager::get_texture_asset({.path = assets::enemy_sprite});
}

void RogylusLayer::on_detach() { ox::ModuleUtil::unload_module("RogylusModule"); }

void RogylusLayer::on_update(const ox::Timestep& delta_time) { _scene->on_runtime_update(delta_time); }

void RogylusLayer::on_imgui_render() { _scene->on_imgui_render(ox::App::get_timestep()); }

void RogylusLayer::load_scene() {
  _scene = ox::create_shared<ox::Scene>();
  ox::SceneSerializer serializer(_scene);
  serializer.deserialize("Assets/Scenes/main.oxscene");

  _scene->on_runtime_start();
}
} // namespace rog
