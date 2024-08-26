project(deshovka_frontend)

find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets)
# find_package(pfr REQUIRED)

qt_standard_project_setup()

set(${PROJECT_NAME}_SOURCES
	src/shell/ui_widget.hpp
	src/shell/title_bar.cpp
	src/shell/title_bar.hpp
	src/shell/title_bar_button.cpp
	src/shell/title_bar_button.hpp
	src/shell/content_container.cpp
	src/shell/content_container.hpp
	src/market/page.cpp
	src/market/page.hpp
	src/home/page.cpp
	src/home/page.hpp
	src/main_window.cpp
	src/main_window.hpp
	src/main.cpp
)

set(${PROJECT_NAME}_UI
	ui/main_window.ui
	ui/shell/title_bar.ui
	ui/market/market_page.ui
	ui/home/home_page.ui
)

qt_wrap_ui(SOURCES ${${PROJECT_NAME}_UI})

qt_add_executable(${PROJECT_NAME}
	${${PROJECT_NAME}_SOURCES}
	${${PROJECT_NAME}_UI}
	resources/resources.qrc
)

target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src)
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_BINARY_DIR})

target_link_libraries(${PROJECT_NAME} PRIVATE Qt6::Core Qt6::Gui Qt6::Widgets)
