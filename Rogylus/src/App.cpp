#include <Core/EntryPoint.hpp>

#include "RogylusLayer.hpp"

namespace ox {
class RogylusApp : public ox::Application {
public:
  RogylusApp(const ox::AppSpec& spec) : Application(spec) { }
};

Application* create_application(ApplicationCommandLineArgs args) {
  AppSpec spec;
  spec.name = "Rogylus";
  spec.working_directory = std::filesystem::current_path().string();
  spec.command_line_args = args;
  spec.resources_path = "Assets";

  const auto app = new RogylusApp(spec);
  app->push_layer(new $NAMESPACE::RogylusLayer());

  return app;
}
}