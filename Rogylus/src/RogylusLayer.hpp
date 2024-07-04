#pragma once
#include <Core/Layer.hpp>
#include <Scene/Scene.hpp>

namespace $NAMESPACE {
class RogylusLayer : public ox::Layer {
public:
  RogylusLayer();
  ~RogylusLayer() override = default;
  void on_attach(ox::EventDispatcher& dispatcher) override;
  void on_detach() override;
  void on_update(const ox::Timestep& delta_time) override;
  void on_imgui_render() override;

  static RogylusLayer* get() { return _instance; }

  static std::string get_assets_path(const std::string_view path) {
    return ("Assets" / std::filesystem::path(path)).string();
  }
  
private:
  ox::Shared<ox::Scene> _scene;
  static RogylusLayer* _instance;
};
}