#pragma once
#include <Core/Layer.hpp>
#include <Scene/Scene.hpp>

namespace rog {
class RogylusLayer : public ox::Layer {
public:
  RogylusLayer();
  ~RogylusLayer() override = default;
  void on_attach(ox::EventDispatcher& dispatcher) override;
  void on_detach() override;
  void on_update(const ox::Timestep& delta_time) override;
  void on_imgui_render() override;

  static RogylusLayer* get() { return _instance; }

private:
  ox::Shared<ox::Scene> _scene;
  static RogylusLayer* _instance;

  void load_scene();
};
} // namespace rog
