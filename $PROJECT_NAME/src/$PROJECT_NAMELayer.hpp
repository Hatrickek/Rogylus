#pragma once
#include <Core/Layer.hpp>
#include <Scene/Scene.hpp>

namespace $NAMESPACE {
class $PROJECT_NAMELayer : public ox::Layer {
public:
  $PROJECT_NAMELayer();
  ~$PROJECT_NAMELayer() override = default;
  void on_attach(ox::EventDispatcher& dispatcher) override;
  void on_detach() override;
  void on_update(const ox::Timestep& delta_time) override;
  void on_imgui_render() override;

  static $PROJECT_NAMELayer* get() { return _instance; }

  static std::string get_assets_path(const std::string_view path) {
    return ("Assets" / std::filesystem::path(path)).string();
  }
  
private:
  ox::Shared<ox::Scene> _scene;
  static $PROJECT_NAMELayer* _instance;
};
}