#include "$PROJECT_NAMELayer.hpp"

#include <Modules/ModuleUtil.hpp>

namespace $NAMESPACE {
$PROJECT_NAMELayer* $PROJECT_NAMELayer::_instance = nullptr;

$PROJECT_NAMELayer::$PROJECT_NAMELayer() : Layer("Game Layer") {
  s_instance = this;
}

void $PROJECT_NAMELayer::on_attach(ox::EventDispatcher& dispatcher) {
  ox::ModuleUtil::load_module("${PROJECT_MODULE_TEMPLATE_NAME}", "${PROJECT_MODULE_TEMPLATE_NAME}");

  _scene = ox::create_shared<ox::Scene>();
  _scene->on_runtime_start();
}

void $PROJECT_NAMELayer::on_detach() {
  ox::ModuleUtil::unload_module("${PROJECT_MODULE_TEMPLATE_NAME}");
}

void $PROJECT_NAMELayer::on_update(const ox::Timestep& delta_time) {
  m_scene->on_runtime_update(delta_time);
}

void $PROJECT_NAMELayer::on_imgui_render() {
  m_scene->on_imgui_render(ox::App::get_timestep());
}
}