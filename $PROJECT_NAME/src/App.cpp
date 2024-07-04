#include <Core/EntryPoint.hpp>

#include "$PROJECT_NAMELayer.hpp"

namespace ox {
class $PROJECT_NAMEApp : public ox::Application {
public:
  $PROJECT_NAMEApp(const ox::AppSpec& spec) : Application(spec) { }
};

Application* create_application(ApplicationCommandLineArgs args) {
  AppSpec spec;
  spec.name = "$PROJECT_NAME";
  spec.working_directory = std::filesystem::current_path().string();
  spec.command_line_args = args;
  spec.resources_path = "Assets";

  const auto app = new $PROJECT_NAMEApp(spec);
  app->push_layer(new $NAMESPACE::$PROJECT_NAMELayer());

  return app;
}
}