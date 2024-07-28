#include <Core/EntryPoint.hpp>
#include <Core/App.hpp>

#include "RogylusLayer.hpp"

#include <filesystem>

namespace ox {
class RogylusApp : public ox::App {
public:
  RogylusApp(const ox::AppSpec& spec) : App(spec) { }
};

App* create_application(const AppCommandLineArgs& args) {
  AppSpec spec;
  spec.name = "Rogylus";
  spec.working_directory = std::filesystem::current_path().string();
  spec.command_line_args = args;
  spec.assets_path = "Assets";

  const auto app = new RogylusApp(spec);
  app->push_layer(new rog::RogylusLayer());

  return app;
}
}