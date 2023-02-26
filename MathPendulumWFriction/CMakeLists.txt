# CMakeList.txt: проект CMake для MathPendulumWFriction; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#

set(CMAKE_CXX_STANDARD 17)

find_package(Qt6 REQUIRED COMPONENTS Widgets)
find_package(Qt6 REQUIRED COMPONENTS PrintSupport)

# Добавьте источник в исполняемый файл этого проекта.
add_executable (MathPendulumWFriction "MathPendulumWFriction.cpp" "MathPendulumWFriction.h" "MainWindow.h"
 "PendView.cpp"				"PendView.h" "MainWindow.cpp")


target_link_libraries(MathPendulumWFriction PRIVATE Qt6::Widgets)
target_link_libraries(MathPendulumWFriction PRIVATE qcustomplot)
target_link_libraries(MathPendulumWFriction PRIVATE Qt6::PrintSupport)


if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET MathPendulumWFriction PROPERTY CXX_STANDARD 20)
endif()

target_compile_definitions(MathPendulumWFriction PRIVATE QCUSTOMPLOT_USE_LIBRARY)

# TODO: Добавьте тесты и целевые объекты, если это необходимо.
