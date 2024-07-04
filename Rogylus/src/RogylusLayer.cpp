#include "RogylusLayer.hpp"

#include <Modules/ModuleUtil.hpp>

namespace $NAMESPACE {
RogylusLayer* RogylusLayer::_instance = nullptr;

RogylusLayer::RogylusLayer() : Layer("Game Layer") {
  s_instance = this;
}

void RogylusLayer::on_attach(ox::EventDispatcher& dispatcher) {
  ox::ModuleUtil::load_module("${PROJECT_MODULE_TEMPLATE_NAME}", "${PROJECT_MODULE_TEMPLATE_NAME}");

  _scene = ox::create_shared<ox::Scene>();
  _scene->on_runtime_start();
}

void RogylusLayer::on_detach() {
  ox::ModuleUtil::unload_module("${PROJECT_MODULE_TEMPLATE_NAME}");
}

void RogylusLayer::on_update(const ox::Timestep& delta_time) {
  m_scene->on_runtime_update(delta_time);
}

void RogylusLayer::on_imgui_render() {
  m_scene->on_imgui_render(ox::App::get_timestep());
}
}